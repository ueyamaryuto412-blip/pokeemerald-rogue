

// When changing this, make sure to:
// -bump ROGUE_SAVE_VERSION in rogue_save.h
// -update SAVE_VER_ID_X_Y_Z enum in rogue_save.h
const u8 gText_RogueVersion[] = _("v2.2.0");

#ifdef ROGUE_EXPANSION
const u8 gText_RogueVersionPrefix[] = _("EX");
#else
const u8 gText_RogueVersionPrefix[] = _("{JPN}バニラ");
#endif

#if defined(ROGUE_FEATURE_AUTOMATION)
const u8 gText_RogueVersionSuffix[] = _("(AUTOMATION)");
#elif defined(ROGUE_DEBUG)
const u8 gText_RogueVersionSpacer[] = _(" - ");
const u8 gText_RogueVersionSuffix[] = _("(DEBUG)");
#else
const u8 gText_RogueVersionSpacer[] = _(" - ");
const u8 gText_RogueVersionSuffix[] = _("Revised Mode + Z-A pt.2");
#endif

// UI String
//
const u8 gText_StatusRoute[] = _("{JPN}ルート {STR_VAR_1}\n");
const u8 gText_StatusBadges[] = _("{JPN}バッジ {STR_VAR_1}\n");
const u8 gText_StatusScore[] = _("{JPN}スコア {STR_VAR_1}\n");
const u8 gText_StatusTimer[] = _("{JPN}タイマー {STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusClock[] = _("{STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusSeasonSpring[] = _("{JPN}·はる·");
const u8 gText_StatusSeasonSummer[] = _("{JPN}·なつ·");
const u8 gText_StatusSeasonAutumn[] = _("{JPN}·あき·");
const u8 gText_StatusSeasonWinter[] = _("{JPN}·ふゆ·");

// Colours aren't exact as they'll be used in battle UI
const u8 gText_MoveEffective[] = _("{JPN}{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}ふつう");
const u8 gText_MoveNoEffect[] = _("{JPN}{COLOR TRANSPARENT}{SHADOW BLUE}こうかなし…");
const u8 gText_MoveSuperEffective[] = _("{JPN}{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}ばつぐん!");
const u8 gText_MoveNotVeryEffective[] = _("{JPN}{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}いまひとつ");
const u8 gText_MoveSlash[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}·");
const u8 gText_MoveShortEffective[] = _("{JPN}{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}ふつう");
const u8 gText_MoveShortNoEffect[] = _("{JPN}{COLOR TRANSPARENT}{SHADOW BLUE}なし");
const u8 gText_MoveShortSuperEffective[] = _("{JPN}{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}ばつぐん");
const u8 gText_MoveShortNotVeryEffective[] = _("{JPN}{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}いまひとつ");


// Trainers
//
const u8 gText_TrainerName_Default[] = _("{JPN}バルキー");

const u8 gText_TrainerName_Brendan[] = _("{JPN}ユウキ");
const u8 gText_TrainerName_May[] = _("{JPN}ハルカ");
const u8 gText_TrainerName_Red[] = _("{JPN}レッド");
const u8 gText_TrainerName_Leaf[] = _("{JPN}リーフ");
const u8 gText_TrainerName_Ethan[] = _("{JPN}ヒビキ");
const u8 gText_TrainerName_Lyra[] = _("{JPN}コトネ");

// Items
//
const u8 gText_EscapeRopeDesc[] = _("{JPN}つかうと たいていの\nであいから すぐに\nにげられる。");

// Difficulty/Config lab settings
//

//{COLOR DARK_GRAY}{SHADOW DARK_GRAY} <default> orange tint
//{COLOR GREEN}{SHADOW LIGHT_GREEN} no tint
//{COLOR RED}{SHADOW LIGHT_RED} red tint
//{COLOR LIGHT_BLUE}{SHADOW BLUE} green tint
const u8 gText_16Spaces[] = _("                ");
const u8 gText_32Spaces[] = _("                                ");

const u8 gText_DifficultySettings[] = _("{JPN}なんいどの せってい");
const u8 gText_DifficultyArrowLeft[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{LEFT_ARROW}");
const u8 gText_DifficultyArrowRight[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{RIGHT_ARROW}");

const u8 gText_DifficultyDoesntAffectReward[] = _("{JPN}{COLOR GREEN}{SHADOW LIGHT_GREEN}ごほうびは かわりません");
const u8 gText_DifficultyRewardLevel[] = _("{JPN}{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}ごほうびの レベル ");

const u8 gText_DifficultyPreset[] = _("{JPN}なんいど");

// Colours on the Settings Screen are out of order and wild
//LIGHT_BLUE = green
//BLUE = light green
//LIGHT_RED = red
//RED = light red
//DARK_GRAY = light yellow
//LIGHT_GRAY = dark yellow
//LIGHT_GREEN = light grey
const u8 gText_DifficultyPresetEasy[] = _("{JPN}{COLOR LIGHT_BLUE}{SHADOW BLUE}やさしい");
const u8 gText_DifficultyPresetMedium[] = _("{JPN}{COLOR LIGHT_BLUE}{SHADOW LIGHT_GREEN}ふつう");
const u8 gText_DifficultyPresetHard[] = _("{JPN}{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}むずかしい");
const u8 gText_DifficultyPresetBrutal[] = _("{JPN}{COLOR LIGHT_RED}{SHADOW RED}ようしゃなし");
const u8 gText_DifficultyPresetCustom[] = _("{JPN}{COLOR DARK_GRAY}{SHADOW LIGHT_GREEN}じぶんで");

const u8 gText_DifficultyEnabled[] = _("{JPN}{COLOR LIGHT_BLUE}{SHADOW BLUE}オン  ");
const u8 gText_DifficultyDisabled[] = _("{JPN}{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}つかわない");
const u8 gText_DifficultyModeActive[] = _("{JPN}{COLOR LIGHT_BLUE}{SHADOW BLUE}はつどうちゅう!");

const u8 gText_DifficultyExpAll[] = _("{JPN}がくしゅうそうち");
const u8 gText_DifficultyOverLvl[] = _("{JPN}レベルの うわげん");
const u8 gText_DifficultyEVGain[] = _("{JPN}どりょくち");
const u8 gText_DifficultyOverworldMons[] = _("{JPN}みえる やせいの {PKMN}");
const u8 gText_DifficultyBagWipe[] = _("{JPN}やりなおし");
const u8 gText_DifficultySwitchMode[] = _("{JPN}いれかえの ルール");

const u8 gText_DifficultyTrainers[] = _("{JPN}トレーナー");
const u8 gText_DifficultyItems[] = _("{JPN}どうぐ");
const u8 gText_DifficultyLegendaries[] = _("{JPN}でんせつの ポケモン");

const u8 gText_DifficultyCustomDesc[] = _("{JPN}{COLOR GREEN}{SHADOW LIGHT_GREEN}ひとつずつ いじって なんいどを\nこのみに あわせられます。");

const u8 gText_AdventureCustomDesc[] = _("{JPN}{COLOR GREEN}{SHADOW LIGHT_GREEN}ひとつずつ いじって ぼうけんを\nこのみに あわせられます。");

const u8 gText_DifficultyTrainersDesc[] = _("{JPN}{COLOR GREEN}{SHADOW LIGHT_GREEN}トレーナーの {PKMN}の しつ かず つよさを\nまとめて かえます。");

const u8 gText_DifficultyItemsDesc[] = _("{JPN}{COLOR GREEN}{SHADOW LIGHT_GREEN}これから なおす ところです…");

const u8 gText_DifficultyLegendariesDesc[] = _("{JPN}{COLOR GREEN}{SHADOW LIGHT_GREEN}でんせつの {PKMN}の しつと かずを\nへらします。");

// Campaigns
//
const u8 gText_CampaignHofTitle[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{STR_VAR_1}");

const u8 gText_Campaign_None[] = _("???");
const u8 gText_Campaign_LowBST[] = _("{JPN}しゅぞくちカップ");
const u8 gText_Campaign_Classic[] = _("{JPN}クラシックモード");
const u8 gText_Campaign_MiniBossBattler[] = _("{JPN}しょうぶ ちゅうどく");
const u8 gText_Campaign_AutoBattler[] = _("{JPN}じどう しょうぶ");
const u8 gText_Campaign_LaterManner[] = _("{JPN}あとまわし モード");
const u8 gText_Campaign_PokeballLimit[] = _("{JPN}ほかく せいげん");
const u8 gText_Campaign_OneHp[] = _("{JPN}いちげき モード");

// Debug
//
#ifdef ROGUE_DEBUG
const u8 gText_RogueDebug_Header[] = _("ROGUE DEBUG");
const u8 gText_RogueDebug_Save[] = _("\nSave: ");
const u8 gText_RogueDebug_Room[] = _("\nRoom: ");
const u8 gText_RogueDebug_BossRoom[] = _("\nBossRoom: ");
const u8 gText_RogueDebug_Difficulty[] = _("\nDfcy: ");
const u8 gText_RogueDebug_PlayerLvl[] = _("\nPly lvl: ");
const u8 gText_RogueDebug_WildLvl[] = _("\nWld lvl: ");
const u8 gText_RogueDebug_WildCount[] = _("\nWld Opt: ");
const u8 gText_RogueDebug_ItemCount[] = _("\nItm Opt: ");
const u8 gText_RogueDebug_TrainerCount[] = _("\nTrn Opt: ");
const u8 gText_RogueDebug_Seed[] = _("\nSeed: ");

const u8 gText_RogueDebug_AdvHeader[] = _("ROGUE ADVPATH");
const u8 gText_RogueDebug_AdvCount[] = _("\nCount: ");
const u8 gText_RogueDebug_X[] = _("\nX: ");
const u8 gText_RogueDebug_Y[] = _("\nY: ");
#endif