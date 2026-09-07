#include "global.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_anim.h"
#include "battle_terastal.h"
#include "battle_util.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "decompress.h"
#include "fpmath.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

#include "battle_controllers.h"
#include "event_data.h"
#include "item_menu.h"
#include "constants/items.h"
#include "constants/species.h"

#include "rogue_typechart_ui.h"

// タイプ相性の早見画面。
//
//   タブ1 じゃくてん … てもち6匹が どの タイプに 弱いか
//   タブ2 こうげき   … てもちの わざが どの タイプに とおるか
//   タブ3 そうせい   … えらんだ タイプの 攻守の相性
//
// 18タイプを 9行 × 2列 に並べると 144px。上の見出し 16px と合わせて
// ちょうど 画面（160px）に収まる。

enum
{
    TAB_PARTY_WEAKNESS,
    TAB_PARTY_COVERAGE,
    TAB_TYPE_MATCHUP,
    TAB_COUNT,
};

enum
{
    WIN_HEADER,
    WIN_MAIN,
    WIN_COUNT,
};

// 倍率を 6段階に まるめたもの。アイコンの並び順でもある。
enum
{
    EFF_ZERO,
    EFF_QUARTER,
    EFF_HALF,
    EFF_NEUTRAL,
    EFF_DOUBLE,
    EFF_QUAD,
    EFF_LEVEL_COUNT,
};

#define DISPLAY_TYPE_COUNT 18
#define TYPE_PICK_NONE     0xFF
#define ROWS_PER_COLUMN    (DISPLAY_TYPE_COUNT / 2)
#define ROW_HEIGHT         16

// 左右2列ぶんの x 位置（ウィンドウ内の px）
#define COLUMN_X(col)      ((col) ? 116 : 0)
#define CELL_X(col, i)     (COLUMN_X(col) + 36 + (i) * 9)
#define SUMMARY_X(col)     (COLUMN_X(col) + 36 + 6 * 9 + 2)
// そうせいタブは 1行に 2つだけなので ゆったり置く
#define MATCHUP_ATK_X(col) (COLUMN_X(col) + 36)
#define MATCHUP_DEF_X(col) (COLUMN_X(col) + 60)

struct RogueTypeChartUi
{
    MainCallback returnCallback;
    u8 tab;
    u8 pickedType;                 // タブ3で えらんでいる タイプ（表示順）
    u8 pickedType2;                // TYPE_PICK_NONE で「なし」
    u8 partyCount;
    u8 monTypes[PARTY_SIZE][3];                   // TYPE_NONE で うめる
    u8 monPartyIndex[PARTY_SIZE];
    u8 monMoveTypes[PARTY_SIZE][MAX_MON_MOVES];   // TYPE_NONE で 攻撃わざ でない
    u8 monLabel[PARTY_SIZE][3];

    bool8 fromBattle;
    u8 opponentCount;
    u8 opponentTypes[2][3];
};

static EWRAM_DATA struct RogueTypeChartUi *sUi = NULL;

static void MainCB2(void);
static void VBlankCB(void);
static void CB2_InitTypeChart(void);
static void Task_FadeIn(u8 taskId);
static void Task_HandleInput(u8 taskId);
static void Task_FadeOut(u8 taskId);
static void DrawScreen(void);

// かなは 4文字まで（1列 32px に収めるため）
static const u8 sTypeName_Normal[]   = _("{JPN}ノーマル");
static const u8 sTypeName_Fighting[] = _("{JPN}かくとう");
static const u8 sTypeName_Flying[]   = _("{JPN}ひこう");
static const u8 sTypeName_Poison[]   = _("{JPN}どく");
static const u8 sTypeName_Ground[]   = _("{JPN}じめん");
static const u8 sTypeName_Rock[]     = _("{JPN}いわ");
static const u8 sTypeName_Bug[]      = _("{JPN}むし");
static const u8 sTypeName_Ghost[]    = _("{JPN}ゴースト");
static const u8 sTypeName_Steel[]    = _("{JPN}はがね");
static const u8 sTypeName_Fire[]     = _("{JPN}ほのお");
static const u8 sTypeName_Water[]    = _("{JPN}みず");
static const u8 sTypeName_Grass[]    = _("{JPN}くさ");
static const u8 sTypeName_Electric[] = _("{JPN}でんき");
static const u8 sTypeName_Psychic[]  = _("{JPN}エスパー");
static const u8 sTypeName_Ice[]      = _("{JPN}こおり");
static const u8 sTypeName_Dragon[]   = _("{JPN}ドラゴン");
static const u8 sTypeName_Dark[]     = _("{JPN}あく");
static const u8 sTypeName_Fairy[]    = _("{JPN}フェアリ");

static const u8 sDisplayTypes[DISPLAY_TYPE_COUNT] =
{
    TYPE_NORMAL, TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON, TYPE_GROUND,
    TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL,
    TYPE_FIRE, TYPE_WATER, TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC,
    TYPE_ICE, TYPE_DRAGON, TYPE_DARK, TYPE_FAIRY,
};

static const u8 *const sTypeNames[DISPLAY_TYPE_COUNT] =
{
    sTypeName_Normal, sTypeName_Fighting, sTypeName_Flying, sTypeName_Poison, sTypeName_Ground,
    sTypeName_Rock, sTypeName_Bug, sTypeName_Ghost, sTypeName_Steel,
    sTypeName_Fire, sTypeName_Water, sTypeName_Grass, sTypeName_Electric, sTypeName_Psychic,
    sTypeName_Ice, sTypeName_Dragon, sTypeName_Dark, sTypeName_Fairy,
};

static const u8 sTabTitle_Weakness[] = _("{JPN}じゃくてん");
static const u8 sTabTitle_Coverage[] = _("{JPN}こうげき");
static const u8 sTabTitle_Matchup[]  = _("{JPN}そうせい");

static const u8 *const sTabTitles[TAB_COUNT] =
{
    sTabTitle_Weakness, sTabTitle_Coverage, sTabTitle_Matchup,
};

static const u8 sText_Attack[]  = _("{JPN}こう");
static const u8 sText_Defence[] = _("{JPN}ぼう");
static const u8 sText_TypeNone[]    = _("{JPN}なし");
static const u8 sText_Slash[]       = _("{JPN}・");

// 0=とうめい 1=しろ 2=もじ 3=かげ 4=あか 5=こいあか 6=みずいろ 7=あお 8=はいいろ 9=みどり
static const u16 sPalette[16] =
{
    RGB(6, 8, 14),      RGB(31, 31, 31),   RGB(4, 4, 6),      RGB(21, 21, 22),
    RGB(31, 10, 8),     RGB(21, 2, 2),     RGB(12, 20, 31),   RGB(3, 6, 24),
    RGB(17, 17, 17),    RGB(6, 24, 8),     RGB(0, 0, 0),      RGB(0, 0, 0),
    RGB(0, 0, 0),       RGB(0, 0, 0),      RGB(0, 0, 0),      RGB(0, 0, 0),
};

static const u8 sTextColor[3]          = { 1, 2, 3 };
static const u8 sTextColorHighlight[3] = { 1, 9, 3 };

// 8x8 の 4bpp タイル。EFF_* の順。
static const u8 sCellIconGfx[] =
{
    // こうかなし（×じるし）
    0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00,
    0x00, 0x80, 0x80, 0x00, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // 4ぶんの1
    0x00, 0x00, 0x00, 0x00, 0x77, 0x77, 0x77, 0x07,
    0x77, 0x77, 0x77, 0x07, 0x70, 0x77, 0x77, 0x00,
    0x70, 0x77, 0x77, 0x00, 0x00, 0x77, 0x07, 0x00,
    0x00, 0x77, 0x07, 0x00, 0x00, 0x70, 0x00, 0x00,
    // はんぶん
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x60, 0x66, 0x66, 0x00, 0x60, 0x66, 0x66, 0x00,
    0x00, 0x66, 0x06, 0x00, 0x00, 0x66, 0x06, 0x00,
    0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // とうばい（なにも かかない）
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // 2ばい
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
    0x00, 0x44, 0x04, 0x00, 0x00, 0x44, 0x04, 0x00,
    0x40, 0x44, 0x44, 0x00, 0x40, 0x44, 0x44, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // 4ばい
    0x00, 0x50, 0x00, 0x00, 0x00, 0x55, 0x05, 0x00,
    0x00, 0x55, 0x05, 0x00, 0x50, 0x55, 0x55, 0x00,
    0x50, 0x55, 0x55, 0x00, 0x55, 0x55, 0x55, 0x05,
    0x55, 0x55, 0x55, 0x05, 0x00, 0x00, 0x00, 0x00,
};

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

// 1つの charblock は 512タイル までなので、見出しと本体で BG を分けている。
static const struct WindowTemplate sWinTemplates[] =
{
    [WIN_HEADER] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 28,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 1,
    },
    [WIN_MAIN] =
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 28,
        .height = 18,
        .paletteNum = 1,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static u8 EffLevelFromMultiplier(uq4_12_t mul)
{
    if (mul == UQ_4_12(0.0))
        return EFF_ZERO;
    if (mul <= UQ_4_12(0.25))
        return EFF_QUARTER;
    if (mul < UQ_4_12(1.0))
        return EFF_HALF;
    if (mul == UQ_4_12(1.0))
        return EFF_NEUTRAL;
    if (mul < UQ_4_12(4.0))
        return EFF_DOUBLE;
    return EFF_QUAD;
}

// 攻撃タイプ atk が、types[] を持つ相手に どれだけ とおるか。
// おなじタイプを 二重に かけないよう、出てきたものは 覚えておく。
static uq4_12_t DefenceMultiplier(u8 atkType, const u8 *types)
{
    uq4_12_t mul = UQ_4_12(1.0);
    u8 i, j;

    for (i = 0; i < 3; ++i)
    {
        if (types[i] >= NUMBER_OF_MON_TYPES)
            continue;

        for (j = 0; j < i; ++j)
        {
            if (types[j] == types[i])
                break;
        }

        if (j != i)
            continue;

        mul = uq4_12_multiply(mul, GetTypeModifier(atkType, types[i]));
    }

    return mul;
}

// 表に出す 18タイプの なかの 何番目か
static u8 DisplayIndexOfType(u8 type)
{
    u8 i;

    for (i = 0; i < DISPLAY_TYPE_COUNT; ++i)
    {
        if (sDisplayTypes[i] == type)
            return i;
    }

    return 0;
}

// バトル中に あいての タイプと 合っている 行か（見出しの色を 変えるため）
static bool8 IsOpponentType(u8 type)
{
    u8 i, j;

    if (!sUi->fromBattle)
        return FALSE;

    for (i = 0; i < sUi->opponentCount; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            if (sUi->opponentTypes[i][j] == type)
                return TRUE;
        }
    }

    return FALSE;
}

static void CacheParty(void)
{
    u8 i, j;

    sUi->partyCount = 0;

    for (i = 0; i < PARTY_SIZE; ++i)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE || species == SPECIES_EGG || GetMonData(mon, MON_DATA_IS_EGG))
            continue;

        sUi->monTypes[sUi->partyCount][0] = gSpeciesInfo[species].types[0];
        sUi->monTypes[sUi->partyCount][1] = gSpeciesInfo[species].types[1];
        sUi->monTypes[sUi->partyCount][2] = TYPE_NONE;
        sUi->monPartyIndex[sUi->partyCount] = i;

        for (j = 0; j < MAX_MON_MOVES; ++j)
        {
            u16 move = GetMonData(mon, MON_DATA_MOVE1 + j);

            if (move != MOVE_NONE && gBattleMoves[move].power != 0)
                sUi->monMoveTypes[sUi->partyCount][j] = gBattleMoves[move].type;
            else
                sUi->monMoveTypes[sUi->partyCount][j] = TYPE_NONE;
        }

        // 見出しに出す 2文字ぶんの ニックネーム
        // GetMonData は 名前ぜんぶを 書きこむので、いったん 別の器で受ける
        {
            u8 nickname[POKEMON_NAME_LENGTH + 1];

            GetMonData(mon, MON_DATA_NICKNAME, nickname);
            sUi->monLabel[sUi->partyCount][0] = nickname[0];
            sUi->monLabel[sUi->partyCount][1] = (nickname[0] == EOS) ? EOS : nickname[1];
            sUi->monLabel[sUi->partyCount][2] = EOS;
        }

        sUi->partyCount++;
    }
}


// バトル中に 開いたとき。あいての タイプと、場に出ている 味方のタイプを
// バトル側から とる（テラスタルや タイプ変化を そのまま うつすため）。
static void ReadBattlerTypes(u32 battler, u8 *dst)
{
    if (IsTerastallized(battler))
    {
        dst[0] = GetBattlerTeraType(battler);
        dst[1] = TYPE_NONE;
        dst[2] = TYPE_NONE;
        return;
    }

    dst[0] = gBattleMons[battler].type1;
    dst[1] = gBattleMons[battler].type2;
    dst[2] = gBattleMons[battler].type3;
}

static void CacheBattle(void)
{
    static const u8 sOpponentPositions[2] = { B_POSITION_OPPONENT_LEFT, B_POSITION_OPPONENT_RIGHT };
    u8 i, j;

    sUi->opponentCount = 0;

    for (i = 0; i < ARRAY_COUNT(sOpponentPositions); ++i)
    {
        u32 battler = GetBattlerAtPosition(sOpponentPositions[i]);

        if (battler >= gBattlersCount)
            continue;
        if (gBattleMons[battler].species == SPECIES_NONE || !IsBattlerAlive(battler))
            continue;

        ReadBattlerTypes(battler, sUi->opponentTypes[sUi->opponentCount]);
        sUi->opponentCount++;
    }

    // 場に出ている 味方は バトル側のタイプで 上書きする
    for (i = 0; i < gBattlersCount; ++i)
    {
        if (GetBattlerSide(i) != B_SIDE_PLAYER || !IsBattlerAlive(i))
            continue;

        for (j = 0; j < sUi->partyCount; ++j)
        {
            if (sUi->monPartyIndex[j] == gBattlerPartyIndexes[i])
            {
                ReadBattlerTypes(i, sUi->monTypes[j]);
                break;
            }
        }
    }
}

static void BlitCellIcon(u8 level, u16 x, u16 y)
{
    if (level == EFF_NEUTRAL)
        return;

    BlitBitmapRectToWindow(WIN_MAIN, &sCellIconGfx[level * 32], 0, 0, 8, 8, x, y, 8, 8);
}

static void PrintOnMain(const u8 *str, u16 x, u16 y, bool8 highlight)
{
    AddTextPrinterParameterized4(WIN_MAIN, FONT_NORMAL, x, y, 0, 0,
                                 highlight ? sTextColorHighlight : sTextColor, TEXT_SKIP_DRAW, str);
}

static void PrintNumberOnMain(u8 value, u16 x, u16 y)
{
    u8 buffer[4];

    ConvertIntToDecimalStringN(buffer, value, STR_CONV_MODE_LEFT_ALIGN, 1);
    AddTextPrinterParameterized4(WIN_MAIN, FONT_NORMAL, x, y, 0, 0, sTextColor, TEXT_SKIP_DRAW, buffer);
}

static void DrawHeader(void)
{
    u8 i;
    u8 buffer[32];

    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));

    AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, 0, 0, 0, 0, sTextColorHighlight,
                                 TEXT_SKIP_DRAW, sTabTitles[sUi->tab]);

    if (sUi->tab == TAB_TYPE_MATCHUP)
    {
        u8 *ptr;

        // どちらの列が なにか わかるように 見出しを 出す
        for (i = 0; i < 2; ++i)
        {
            AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, MATCHUP_ATK_X(i), 0, 0, 0,
                                         sTextColor, TEXT_SKIP_DRAW, sText_Attack);
            AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, MATCHUP_DEF_X(i), 0, 0, 0,
                                         sTextColor, TEXT_SKIP_DRAW, sText_Defence);
        }

        ptr = StringCopy(buffer, sTypeNames[sUi->pickedType]);

        if (sUi->pickedType2 != TYPE_PICK_NONE)
        {
            ptr = StringAppend(buffer, sText_Slash);
            StringAppend(buffer, sTypeNames[sUi->pickedType2]);
        }

        AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, 80, 0, 0, 0, sTextColorHighlight,
                                     TEXT_SKIP_DRAW, buffer);
    }
    else
    {
        // てもちの ならびを 見出しに 出す（1ピカ 2ヒト …）
        for (i = 0; i < sUi->partyCount; ++i)
        {
            u8 *ptr = buffer;

            ptr = ConvertIntToDecimalStringN(ptr, i + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
            StringCopy(ptr, sUi->monLabel[i]);

            AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, 72 + i * 24, 0, 0, 0, sTextColor,
                                         TEXT_SKIP_DRAW, buffer);
        }
    }

    CopyWindowToVram(WIN_HEADER, COPYWIN_GFX);
}

// てもちの じゃくてん / こうげき はんい は 同じ かたちの表
static void DrawPartyGrid(bool8 coverage)
{
    u8 row, col, mon, i;

    for (col = 0; col < 2; ++col)
    {
        for (row = 0; row < ROWS_PER_COLUMN; ++row)
        {
            u8 index = col * ROWS_PER_COLUMN + row;
            u8 type = sDisplayTypes[index];
            u16 y = row * ROW_HEIGHT;
            u8 count = 0;

            PrintOnMain(sTypeNames[index], COLUMN_X(col), y, IsOpponentType(type));

            for (mon = 0; mon < sUi->partyCount; ++mon)
            {
                uq4_12_t mul;
                u8 level;

                if (coverage)
                {
                    // この タイプの 相手に いちばん とおる わざ
                    mul = UQ_4_12(0.0);

                    for (i = 0; i < MAX_MON_MOVES; ++i)
                    {
                        uq4_12_t moveMul;

                        if (sUi->monMoveTypes[mon][i] == TYPE_NONE)
                            continue;

                        moveMul = GetTypeModifier(sUi->monMoveTypes[mon][i], type);

                        if (moveMul > mul)
                            mul = moveMul;
                    }

                    level = EffLevelFromMultiplier(mul);

                    if (level >= EFF_DOUBLE)
                        count++;
                }
                else
                {
                    mul = DefenceMultiplier(type, sUi->monTypes[mon]);
                    level = EffLevelFromMultiplier(mul);

                    if (level >= EFF_DOUBLE)
                        count++;
                }

                BlitCellIcon(level, CELL_X(col, mon), y + 4);
            }

            PrintNumberOnMain(count, SUMMARY_X(col), y);
        }
    }
}

// えらんだ タイプの 攻守を 1画面で
static void DrawMatchup(void)
{
    u8 row, col;
    u8 picked = sDisplayTypes[sUi->pickedType];
    u8 picked2 = (sUi->pickedType2 == TYPE_PICK_NONE) ? TYPE_NONE : sDisplayTypes[sUi->pickedType2];

    for (col = 0; col < 2; ++col)
    {
        for (row = 0; row < ROWS_PER_COLUMN; ++row)
        {
            u8 index = col * ROWS_PER_COLUMN + row;
            u8 type = sDisplayTypes[index];
            u16 y = row * ROW_HEIGHT;
            uq4_12_t atkMul, defMul;

            PrintOnMain(sTypeNames[index], COLUMN_X(col), y, FALSE);

            // こうげき: えらんだ タイプで この タイプを 殴ったとき
            atkMul = GetTypeModifier(picked, type);

            if (picked2 != TYPE_NONE)
            {
                uq4_12_t other = GetTypeModifier(picked2, type);

                if (other > atkMul)
                    atkMul = other;
            }

            // ぼうぎょ: この タイプで えらんだ タイプを 殴られたとき
            {
                u8 pickedTypes[3];

                pickedTypes[0] = picked;
                pickedTypes[1] = picked2;
                pickedTypes[2] = TYPE_NONE;
                defMul = DefenceMultiplier(type, pickedTypes);
            }

            BlitCellIcon(EffLevelFromMultiplier(atkMul), MATCHUP_ATK_X(col) + 4, y + 4);
            BlitCellIcon(EffLevelFromMultiplier(defMul), MATCHUP_DEF_X(col) + 4, y + 4);
        }
    }
}

static void DrawScreen(void)
{
    DrawHeader();

    FillWindowPixelBuffer(WIN_MAIN, PIXEL_FILL(1));

    switch (sUi->tab)
    {
    case TAB_PARTY_WEAKNESS:
        DrawPartyGrid(FALSE);
        break;
    case TAB_PARTY_COVERAGE:
        DrawPartyGrid(TRUE);
        break;
    case TAB_TYPE_MATCHUP:
        DrawMatchup();
        break;
    }

    CopyWindowToVram(WIN_MAIN, COPYWIN_GFX);
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void SetupUi(MainCallback returnCallback)
{
    sUi = AllocZeroed(sizeof(struct RogueTypeChartUi));
    sUi->returnCallback = returnCallback;
    sUi->tab = TAB_PARTY_WEAKNESS;
    sUi->pickedType = 0;
    sUi->pickedType2 = TYPE_PICK_NONE;
    CacheParty();
}

void Rogue_OpenTypeChartFromField(void)
{
    SetupUi(CB2_ReturnToField);
    SetMainCallback2(CB2_InitTypeChart);
}

void Rogue_OpenTypeChartFromBattle(void)
{
    SetupUi(NULL);
    sUi->fromBattle = TRUE;
    CacheBattle();

    // バトル中は 知りたいのが「あいての 弱点」なので、
    // そうせいタブを あいての タイプで 開いた 状態にしておく。
    if (sUi->opponentCount != 0)
    {
        u8 *types = sUi->opponentTypes[0];

        sUi->tab = TAB_TYPE_MATCHUP;
        sUi->pickedType = DisplayIndexOfType(types[0]);

        if (types[1] < NUMBER_OF_MON_TYPES && types[1] != types[0])
            sUi->pickedType2 = DisplayIndexOfType(types[1]);
    }

    SetMainCallback2(CB2_InitTypeChart);
}

bool8 Rogue_IsViewingTypeChart(void)
{
    return sUi != NULL;
}

static void CB2_InitTypeChart(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        InitWindows(sWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadPalette(sPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        LoadPalette(&sPalette[0], BG_PLTT_ID(0), PLTT_SIZEOF(1));
        gMain.state++;
        break;
    case 4:
        PutWindowTilemap(WIN_HEADER);
        PutWindowTilemap(WIN_MAIN);
        FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
        FillWindowPixelBuffer(WIN_MAIN, PIXEL_FILL(1));
        CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
        CopyWindowToVram(WIN_MAIN, COPYWIN_FULL);
        gMain.state++;
        break;
    case 5:
        DrawScreen();
        CreateTask(Task_FadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        gMain.state = 0;
        return;
    }
}

static void Task_FadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_HandleInput;
}

static void Task_HandleInput(u8 taskId)
{
    bool8 redraw = FALSE;

    if (JOY_NEW(B_BUTTON) || JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_FadeOut;
        return;
    }

    if (JOY_NEW(L_BUTTON))
    {
        sUi->tab = (sUi->tab + TAB_COUNT - 1) % TAB_COUNT;
        redraw = TRUE;
    }
    else if (JOY_NEW(START_BUTTON) || JOY_NEW(A_BUTTON))
    {
        sUi->tab = (sUi->tab + 1) % TAB_COUNT;
        redraw = TRUE;
    }

    if (sUi->tab == TAB_TYPE_MATCHUP)
    {
        if (JOY_NEW(DPAD_LEFT))
        {
            sUi->pickedType = (sUi->pickedType + DISPLAY_TYPE_COUNT - 1) % DISPLAY_TYPE_COUNT;
            redraw = TRUE;
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            sUi->pickedType = (sUi->pickedType + 1) % DISPLAY_TYPE_COUNT;
            redraw = TRUE;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (sUi->pickedType2 == TYPE_PICK_NONE)
                sUi->pickedType2 = DISPLAY_TYPE_COUNT - 1;
            else if (sUi->pickedType2 == 0)
                sUi->pickedType2 = TYPE_PICK_NONE;
            else
                sUi->pickedType2--;
            redraw = TRUE;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (sUi->pickedType2 == TYPE_PICK_NONE)
                sUi->pickedType2 = 0;
            else if (sUi->pickedType2 == DISPLAY_TYPE_COUNT - 1)
                sUi->pickedType2 = TYPE_PICK_NONE;
            else
                sUi->pickedType2++;
            redraw = TRUE;
        }
    }

    if (redraw)
    {
        PlaySE(SE_SELECT);
        DrawScreen();
    }
}

static void Task_FadeOut(u8 taskId)
{
    MainCallback returnCallback;

    if (gPaletteFade.active)
        return;

    returnCallback = sUi->returnCallback;

    Free(sUi);
    sUi = NULL;

    FreeAllWindowBuffers();
    DestroyTask(taskId);

    if (returnCallback != NULL)
    {
        SetMainCallback2(returnCallback);
    }
    else
    {
        // バトルから開いたとき。どうぐを つかわなかった ことにして 戻す
        gSpecialVar_ItemId = ITEM_NONE;
        SetMainCallback2(CB2_SetUpReshowBattleScreenAfterMenu2);
    }
}
