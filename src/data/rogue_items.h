#include "graphics.h"

extern const u8 gItemDesc_EvolutionItem[];
extern const u8 gItemDesc_QuestLog[];
extern const u8 gItemDesc_BattleChecker[];
extern const u8 gItemDesc_HealingFlask[];
extern const u8 gItemDesc_RidingWhistle[];
extern const u8 gItemDesc_GoldRidingWhistle[];
extern const u8 gItemDesc_CGear[];
extern const u8 gItemDesc_DaycarePhone[];
extern const u8 gItemDesc_BuildingSupplies[];
extern const u8 gItemDesc_SmallCoinCase[];
extern const u8 gItemDesc_LargeCoinCase[];
extern const u8 gItemDesc_GoldenSeed[];

extern const u8 gItemDesc_NormalPokeblock[];
extern const u8 gItemDesc_FightingPokeblock[];
extern const u8 gItemDesc_FlyingPokeblock[];
extern const u8 gItemDesc_PoisonPokeblock[];
extern const u8 gItemDesc_GroundPokeblock[];
extern const u8 gItemDesc_RockPokeblock[];
extern const u8 gItemDesc_BugPokeblock[];
extern const u8 gItemDesc_GhostPokeblock[];
extern const u8 gItemDesc_SteelPokeblock[];
extern const u8 gItemDesc_FirePokeblock[];
extern const u8 gItemDesc_WaterPokeblock[];
extern const u8 gItemDesc_GrassPokeblock[];
extern const u8 gItemDesc_ElectricPokeblock[];
extern const u8 gItemDesc_PsychicPokeblock[];
extern const u8 gItemDesc_IcePokeblock[];
extern const u8 gItemDesc_DragonPokeblock[];
extern const u8 gItemDesc_DarkPokeblock[];
extern const u8 gItemDesc_FairyPokeblock[];
extern const u8 gItemDesc_ShinyPokeblock[];
extern const u8 gItemDesc_StatPokeblock[];

extern const u8 gItemDesc_ShopPriceCharm[];
extern const u8 gItemDesc_ShopPriceCurse[];
extern const u8 gItemDesc_FlinchCharm[];
extern const u8 gItemDesc_FlinchCurse[];
extern const u8 gItemDesc_CritCharm[];
extern const u8 gItemDesc_CritCurse[];
extern const u8 gItemDesc_ShedSkinCharm[];
extern const u8 gItemDesc_ShedSkinCurse[];
extern const u8 gItemDesc_WildIVCharm[];
extern const u8 gItemDesc_WildIVCurse[];
extern const u8 gItemDesc_CatchingCharm[];
extern const u8 gItemDesc_CatchingCurse[];
extern const u8 gItemDesc_GraceCharm[];
extern const u8 gItemDesc_GraceCurse[];
extern const u8 gItemDesc_WildCharm[];
extern const u8 gItemDesc_WildCurse[];
extern const u8 gItemDesc_PriorityCharm[];
extern const u8 gItemDesc_PriorityCurse[];
extern const u8 gItemDesc_EndureCharm[];
extern const u8 gItemDesc_EndureCurse[];
extern const u8 gItemDesc_TormentCharm[];
extern const u8 gItemDesc_TormentCurse[];
extern const u8 gItemDesc_PressureCharm[];
extern const u8 gItemDesc_PressureCurse[];
extern const u8 gItemDesc_UnawareCharm[];
extern const u8 gItemDesc_UnawareCurse[];
extern const u8 gItemDesc_AdaptabilityCharm[];
extern const u8 gItemDesc_AdaptabilityCurse[];
extern const u8 gItemDesc_ExtraLifeCharm[];
extern const u8 gItemDesc_AllowSaveScumCharm[];
extern const u8 gItemDesc_PartyCurse[];
extern const u8 gItemDesc_EverstoneCurse[];
extern const u8 gItemDesc_BattleItemCurse[];
extern const u8 gItemDesc_SpeciesClauseCurse[];
extern const u8 gItemDesc_ItemShuffleCurse[];
extern const u8 gItemDesc_SnowballCurse[];
extern const u8 gItemDesc_RandomanRouteSpawnCurse[];
extern const u8 gItemDesc_RandomanAlwaysSpawnCurse[];
extern const u8 gItemDesc_AutoMoveSelectCurse[];
extern const u8 gItemDesc_OneHitCurse[];
extern const u8 gItemDesc_SnagCurse[];
extern const u8 gItemDesc_WildEggSpeciesCurse[];

const struct RogueItem gRogueItems[ITEM_ROGUE_ITEM_COUNT] =
{
    [ITEM_LINK_CABLE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}つうしんケーブル"),
#else
        .name = _("{JPN}つうしんケーブル"),
#endif
        .itemId = ITEM_LINK_CABLE,
        .price = 2100,
        .description = gItemDesc_EvolutionItem,
        .pocket = POCKET_HELD_ITEMS,
        .iconImage = gItemIcon_ExpShare,
        .iconPalette = gItemIconPalette_ExpShare,
    },

    [ITEM_QUEST_LOG - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}クエストブック"),
#else
        .name = _("{JPN}クエストブック"),
#endif
        .itemId = ITEM_QUEST_LOG,
        .price = 0,
        .description = gItemDesc_QuestLog,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .registrability = FALSE,
        .fieldUseFunc = ItemUseOutOfBattle_QuestLog,
        .iconImage = gItemIcon_QuestBook,
        .iconPalette = gItemIconPalette_QuestBook,
    },

    [ITEM_BATTLE_CHECKER - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}バトルチェッカー"),
#else
        .name = _("{JPN}バトルチェッカー"),
#endif
        .itemId = ITEM_BATTLE_CHECKER,
        .price = 0,
        .description = gItemDesc_BattleChecker,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .registrability = FALSE,
        .fieldUseFunc = ItemUseOutOfBattle_BattleChecker,
        .iconImage = gItemIcon_FameChecker,
        .iconPalette = gItemIconPalette_FameChecker,
    },

    [ITEM_HEALING_FLASK - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}かいふくの ビン"),
#else
        .name = _("{JPN}かいふくの ビン"),
#endif
        .itemId = ITEM_HEALING_FLASK,
        .price = 0,
        .description = gItemDesc_HealingFlask,
        .pocket = POCKET_KEY_ITEMS,
        .registrability = TRUE,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_HealingFlask,
        .iconImage = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_HealingFlask,
    },

    [ITEM_BASIC_RIDING_WHISTLE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ポケのふえ"),
#else
        .name = _("{JPN}ポケのふえ"),
#endif
        .itemId = ITEM_BASIC_RIDING_WHISTLE, 
        .price = 0,
        .description = gItemDesc_RidingWhistle,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_RideMon,
        .secondaryId = RIDE_WHISTLE_BASIC,
        .registrability = TRUE,
        .iconImage = gItemIcon_PokeWhistle,
        .iconPalette = gItemIconPalette_PokeWhistleBasic,
    },

    [ITEM_GOLD_RIDING_WHISTLE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}きんのふえ"),
#else
        .name = _("{JPN}きんのふえ"),
#endif
        .itemId = ITEM_GOLD_RIDING_WHISTLE,
        .price = 0,
        .description = gItemDesc_GoldRidingWhistle,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_RideMon,
        .secondaryId = RIDE_WHISTLE_GOLD,
        .registrability = TRUE,
        .iconImage = gItemIcon_PokeWhistle,
        .iconPalette = gItemIconPalette_PokeWhistleGold,
    },

    [ITEM_C_GEAR - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}Cギア"),
#else
        .name = _("{JPN}Cギア"),
#endif
        .itemId = ITEM_C_GEAR,
        .price = 0,
        .description = gItemDesc_CGear,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CGear,
        .secondaryId = 0,
        .registrability = TRUE,
        .iconImage = gItemIcon_CGear,
        .iconPalette = gItemIconPalette_CGear,
    },

    [ITEM_DAYCARE_PHONE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ポケギア"),
#else
        .name = _("{JPN}ポケギア"),
#endif
        .itemId = ITEM_DAYCARE_PHONE,
        .price = 0,
        .description = gItemDesc_DaycarePhone,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DayCarePhone,
        .secondaryId = 0,
        .registrability = TRUE,
        .iconImage = gItemIcon_PokeGear,
        .iconPalette = gItemIconPalette_PokeGear,
    },
    
    [ITEM_BUILDING_SUPPLIES - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}けんちくざい"),
#else
        .name = _("{JPN}けんちくざい"),
#endif
        .itemId = ITEM_BUILDING_SUPPLIES,
        .price = 0,
        .description = gItemDesc_BuildingSupplies,
        .pocket = POCKET_KEY_ITEMS,
        .registrability = FALSE,
        .iconImage = gItemIcon_BuildResources,
        .iconPalette = gItemIconPalette_BuildResources,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.iconImage = gItemIcon_OaksParcel,
        //.iconPalette = gItemIconPalette_OaksParcel,
    },

#ifdef ROGUE_EXPANSION
    [ITEM_ALOLA_STONE - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("{JPN}アローラのいせき"),
        .itemId = ITEM_ALOLA_STONE,
        .price = 2100,
        .description = gItemDesc_EvolutionItem,
        .pocket = POCKET_ITEMS,
        .iconImage = gItemIcon_AlolaStone,
        .iconPalette = gItemIconPalette_AlolaStone,
    },
    [ITEM_GALAR_STONE - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("{JPN}ガラルのいせき"),
        .itemId = ITEM_GALAR_STONE,
        .price = 2100,
        .description = gItemDesc_EvolutionItem,
        .pocket = POCKET_ITEMS,
        .iconImage = gItemIcon_GalarStone,
        .iconPalette = gItemIconPalette_GalarStone,
    },
    [ITEM_HISUI_STONE - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("{JPN}ヒスイのいせき"),
        .itemId = ITEM_HISUI_STONE,
        .price = 2100,
        .description = gItemDesc_EvolutionItem,
        .pocket = POCKET_ITEMS,
        .iconImage = gItemIcon_HisuiStone,
        .iconPalette = gItemIconPalette_HisuiStone,
    },
#endif
    [ITEM_SMALL_COIN_CASE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ちいさなコインケース"),
#else
        .name = _("{JPN}ちいさなコインケース"),
#endif
        .itemId = ITEM_SMALL_COIN_CASE,
        .price = 1300,
        .description = gItemDesc_SmallCoinCase,
        .pocket = POCKET_ITEMS,
        .iconImage = gItemIcon_CoinCase,
        .iconPalette = gItemIconPalette_CoinCase,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },
    [ITEM_LARGE_COIN_CASE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}おおきなコインケース"),
#else
        .name = _("{JPN}おおきなコインケース"),
#endif
        .itemId = ITEM_LARGE_COIN_CASE,
        .price = 12500,
        .description = gItemDesc_LargeCoinCase,
        .pocket = POCKET_ITEMS,
        .iconImage = gItemIcon_CoinCase,
        .iconPalette = gItemIconPalette_CoinCase,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLDEN_SEED - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}きんのタネ"),
#else
        .name = _("{JPN}きんのタネ"),
#endif
        .itemId = ITEM_GOLDEN_SEED,
        .price = 0,
        .description = gItemDesc_GoldenSeed,
        .pocket = POCKET_KEY_ITEMS,
        .iconImage = gItemIcon_GoldenSeed,
        .iconPalette = gItemIconPalette_GoldenSeed,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_GoldenSeed,
    },

    // Pokeblock
    //
    [ITEM_POKEBLOCK_NORMAL - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ノーマル{POKEBLOCK}"),
#else
        .name = _("{JPN}ノーマル{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_NORMAL,
        .secondaryId = TYPE_NORMAL,
        .price = 0,
        .description = gItemDesc_NormalPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockNormal,
    },
    [ITEM_POKEBLOCK_FIGHTING - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}かくとう{POKEBLOCK}"),
#else
        .name = _("{JPN}かくとう{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_FIGHTING,
        .secondaryId = TYPE_FIGHTING,
        .price = 0,
        .description = gItemDesc_FightingPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockFighting,
    },
    [ITEM_POKEBLOCK_FLYING - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ひこう{POKEBLOCK}"),
#else
        .name = _("{JPN}ひこう{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_FLYING,
        .secondaryId = TYPE_FLYING,
        .price = 0,
        .description = gItemDesc_FlyingPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockFlying,
    },
    [ITEM_POKEBLOCK_POISON - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}どく{POKEBLOCK}"),
#else
        .name = _("{JPN}どく{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_POISON,
        .secondaryId = TYPE_POISON,
        .price = 0,
        .description = gItemDesc_PoisonPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockPoison,
    },
    [ITEM_POKEBLOCK_GROUND - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}じめん{POKEBLOCK}"),
#else
        .name = _("{JPN}じめん{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_GROUND,
        .secondaryId = TYPE_GROUND,
        .price = 0,
        .description = gItemDesc_GroundPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockGround,
    },
    [ITEM_POKEBLOCK_ROCK - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}いわ{POKEBLOCK}"),
#else
        .name = _("{JPN}いわ{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_ROCK,
        .secondaryId = TYPE_ROCK,
        .price = 0,
        .description = gItemDesc_RockPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockRock,
    },
    [ITEM_POKEBLOCK_BUG - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}むし{POKEBLOCK}"),
#else
        .name = _("{JPN}むし{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_BUG,
        .secondaryId = TYPE_BUG,
        .price = 0,
        .description = gItemDesc_BugPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockBug,
    },
    [ITEM_POKEBLOCK_GHOST - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ゴースト{POKEBLOCK}"),
#else
        .name = _("{JPN}ゴースト{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_GHOST,
        .secondaryId = TYPE_GHOST,
        .price = 0,
        .description = gItemDesc_GhostPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockGhost,
    },
    [ITEM_POKEBLOCK_STEEL - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}はがね{POKEBLOCK}"),
#else
        .name = _("{JPN}はがね{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_STEEL,
        .secondaryId = TYPE_STEEL,
        .price = 0,
        .description = gItemDesc_SteelPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockSteel,
    },
    [ITEM_POKEBLOCK_FIRE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ほのお{POKEBLOCK}"),
#else
        .name = _("{JPN}ほのお{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_FIRE,
        .secondaryId = TYPE_FIRE,
        .price = 0,
        .description = gItemDesc_FirePokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockFire,
    },
    [ITEM_POKEBLOCK_WATER - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}みず{POKEBLOCK}"),
#else
        .name = _("{JPN}みず{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_WATER,
        .secondaryId = TYPE_WATER,
        .price = 0,
        .description = gItemDesc_WaterPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockWater,
    },
    [ITEM_POKEBLOCK_GRASS - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}くさ{POKEBLOCK}"),
#else
        .name = _("{JPN}くさ{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_GRASS,
        .secondaryId = TYPE_GRASS,
        .price = 0,
        .description = gItemDesc_GrassPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockGrass,
    },
    [ITEM_POKEBLOCK_ELECTRIC - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}でんき{POKEBLOCK}"),
#else
        .name = _("{JPN}でんき{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_ELECTRIC,
        .secondaryId = TYPE_ELECTRIC,
        .price = 0,
        .description = gItemDesc_ElectricPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockElectric,
    },
    [ITEM_POKEBLOCK_PSYCHIC - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}エスパー{POKEBLOCK}"),
#else
        .name = _("{JPN}エスパー{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_PSYCHIC,
        .secondaryId = TYPE_PSYCHIC,
        .price = 0,
        .description = gItemDesc_PsychicPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockPsychic,
    },
    [ITEM_POKEBLOCK_ICE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}こおり{POKEBLOCK}"),
#else
        .name = _("{JPN}こおり{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_ICE,
        .secondaryId = TYPE_ICE,
        .price = 0,
        .description = gItemDesc_IcePokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockIce,
    },
    [ITEM_POKEBLOCK_DRAGON - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ドラゴン{POKEBLOCK}"),
#else
        .name = _("{JPN}ドラゴン{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_DRAGON,
        .secondaryId = TYPE_DRAGON,
        .price = 0,
        .description = gItemDesc_DragonPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockDragon,
    },
    [ITEM_POKEBLOCK_DARK - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}あく{POKEBLOCK}"),
#else
        .name = _("{JPN}あく{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_DARK,
        .secondaryId = TYPE_DARK,
        .price = 0,
        .description = gItemDesc_DarkPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockDark,
    },
#ifdef ROGUE_EXPANSION
    [ITEM_POKEBLOCK_FAIRY - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("{JPN}フェアリー{POKEBLOCK}"),
        .itemId = ITEM_POKEBLOCK_FAIRY,
        .secondaryId = TYPE_FAIRY,
        .price = 0,
        .description = gItemDesc_FairyPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockFairy,
    },
#endif
    [ITEM_POKEBLOCK_SHINY - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}キラキラ{POKEBLOCK}"),
#else
        .name = _("{JPN}キラキラ{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_SHINY,
        .secondaryId = TYPE_MYSTERY, // just fill in with a placeholder
        .price = 0,
        .description = gItemDesc_ShinyPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_PokeblockShiny,
        .iconPalette = gItemIconPalette_PokeblockShiny,
    },
    [ITEM_POKEBLOCK_HP - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("{JPN}HP{POKEBLOCK}"),
        .itemId = ITEM_POKEBLOCK_HP,
        .secondaryId = TYPE_NONE,
        .price = 0,
        .description = gItemDesc_StatPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockStat,
    },
    [ITEM_POKEBLOCK_ATK - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}こうげき{POKEBLOCK}"),
#else
        .name = _("{JPN}こうげき{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_ATK,
        .secondaryId = TYPE_NONE,
        .price = 0,
        .description = gItemDesc_StatPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockStat,
    },
    [ITEM_POKEBLOCK_DEF - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ぼうぎょ{POKEBLOCK}"),
#else
        .name = _("{JPN}ぼうぎょ{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_DEF,
        .secondaryId = TYPE_NONE,
        .price = 0,
        .description = gItemDesc_StatPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockStatAlt,
    },
    [ITEM_POKEBLOCK_SPEED - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}すばやさ{POKEBLOCK}"),
#else
        .name = _("{JPN}すばやさ{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_SPEED,
        .secondaryId = TYPE_NONE,
        .price = 0,
        .description = gItemDesc_StatPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockStatAlt,
    },
    [ITEM_POKEBLOCK_SPATK - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}とくこう{POKEBLOCK}"),
#else
        .name = _("{JPN}とくこう{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_SPATK,
        .secondaryId = TYPE_NONE,
        .price = 0,
        .description = gItemDesc_StatPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockStat,
    },
    [ITEM_POKEBLOCK_SPDEF - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}とくぼう{POKEBLOCK}"),
#else
        .name = _("{JPN}とくぼう{POKEBLOCK}"),
#endif
        .itemId = ITEM_POKEBLOCK_SPDEF,
        .secondaryId = TYPE_NONE,
        .price = 0,
        .description = gItemDesc_StatPokeblock,
        .pocket = POCKET_POKEBLOCK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pokeblock,
        .registrability = FALSE,
        .iconImage = gItemIcon_Pokeblock,
        .iconPalette = gItemIconPalette_PokeblockStatAlt,
    },


    // Charms
    //
    [ITEM_SHOP_PRICE_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}わりびきの おふだ"),
#else
        .name = _("{JPN}わりびきの おふだ"),
#endif
        .itemId = ITEM_SHOP_PRICE_CHARM,
        .price = 0,
        .description = gItemDesc_ShopPriceCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_FLINCH_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ひるみの おふだ"),
#else
        .name = _("{JPN}ひるみの おふだ"),
#endif
        .itemId = ITEM_FLINCH_CHARM,
        .price = 0,
        .description = gItemDesc_FlinchCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_CRIT_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}きゅうしょの おふだ"),
#else
        .name = _("{JPN}きゅうしょの おふだ"),
#endif
        .itemId = ITEM_CRIT_CHARM,
        .price = 0,
        .description = gItemDesc_CritCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_SHED_SKIN_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}だっぴの おふだ"),
#else
        .name = _("{JPN}だっぴの おふだ"),
#endif
        .itemId = ITEM_SHED_SKIN_CHARM,
        .price = 0,
        .description = gItemDesc_ShedSkinCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_WILD_IV_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ちからの おふだ"),
#else
        .name = _("{JPN}ちからの おふだ"),
#endif
        .itemId = ITEM_WILD_IV_CHARM,
        .price = 0,
        .description = gItemDesc_WildIVCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_CATCHING_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ほかくの おふだ"),
#else
        .name = _("{JPN}ほかくの おふだ"),
#endif
        .itemId = ITEM_CATCHING_CHARM,
        .price = 0,
        .description = gItemDesc_CatchingCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_GRACE_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}めぐみの おふだ"),
#else
        .name = _("{JPN}めぐみの おふだ"),
#endif
        .itemId = ITEM_GRACE_CHARM,
        .price = 0,
        .description = gItemDesc_GraceCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_WILD_ENCOUNTER_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}やせいの おふだ"),
#else
        .name = _("{JPN}やせいの おふだ"),
#endif
        .itemId = ITEM_WILD_ENCOUNTER_CHARM,
        .price = 0,
        .description = gItemDesc_WildCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_MOVE_PRIORITY_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}せんせいの おふだ"),
#else
        .name = _("{JPN}せんせいの おふだ"),
#endif
        .itemId = ITEM_MOVE_PRIORITY_CHARM,
        .price = 0,
        .description = gItemDesc_PriorityCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_ENDURE_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}こらえるの おふだ"),
#else
        .name = _("{JPN}こらえるの おふだ"),
#endif
        .itemId = ITEM_ENDURE_CHARM,
        .price = 0,
        .description = gItemDesc_EndureCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_TORMENT_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}いちゃもんの おふだ"),
#else
        .name = _("{JPN}いちゃもんの おふだ"),
#endif
        .itemId = ITEM_TORMENT_CHARM,
        .price = 0,
        .description = gItemDesc_TormentCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_PRESSURE_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}プレッシャーおふだ"),
#else
        .name = _("{JPN}プレッシャーおふだ"),
#endif
        .itemId = ITEM_PRESSURE_CHARM,
        .price = 0,
        .description = gItemDesc_PressureCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_UNAWARE_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}てんねんの おふだ"),
#else
        .name = _("{JPN}てんねんの おふだ"),
#endif
        .itemId = ITEM_UNAWARE_CHARM,
        .price = 0,
        .description = gItemDesc_UnawareCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_ADAPTABILITY_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}てきおうの おふだ"),
#else
        .name = _("{JPN}てきおうの おふだ"),
#endif
        .itemId = ITEM_ADAPTABILITY_CHARM,
        .price = 0,
        .description = gItemDesc_AdaptabilityCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_INFINITE_EXTRA_LIFE_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}やりなおしおふだ"),
#else
        .name = _("{JPN}やりなおしおふだ"),
#endif
        .itemId = ITEM_INFINITE_EXTRA_LIFE_CHARM,
        .price = 0,
        .description = gItemDesc_ExtraLifeCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_ALLOW_SAVE_SCUM_CHARM - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}セーブの おふだ"),
#else
        .name = _("{JPN}セーブの おふだ"),
#endif
        .itemId = ITEM_ALLOW_SAVE_SCUM_CHARM,
        .price = 0,
        .description = gItemDesc_AllowSaveScumCharm,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCharm,
        .iconPalette = gItemIconPalette_RogueCharm,
    },

    [ITEM_SHOP_PRICE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}わりびきの のろい"),
#else
        .name = _("{JPN}わりびきの のろい"),
#endif
        .itemId = ITEM_SHOP_PRICE_CURSE,
        .price = 0,
        .description = gItemDesc_ShopPriceCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_FLINCH_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ひるみの のろい"),
#else
        .name = _("{JPN}ひるみの のろい"),
#endif
        .itemId = ITEM_FLINCH_CURSE,
        .price = 0,
        .description = gItemDesc_FlinchCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_CRIT_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}きゅうしょの のろい"),
#else
        .name = _("{JPN}きゅうしょの のろい"),
#endif
        .itemId = ITEM_CRIT_CURSE,
        .price = 0,
        .description = gItemDesc_CritCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_SHED_SKIN_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}だっぴの のろい"),
#else
        .name = _("{JPN}だっぴの のろい"),
#endif
        .itemId = ITEM_SHED_SKIN_CURSE,
        .price = 0,
        .description = gItemDesc_ShedSkinCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_WILD_IV_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ちからの のろい"),
#else
        .name = _("{JPN}ちからの のろい"),
#endif
        .itemId = ITEM_WILD_IV_CURSE,
        .price = 0,
        .description = gItemDesc_WildIVCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_CATCHING_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ほかくの のろい"),
#else
        .name = _("{JPN}ほかくの のろい"),
#endif
        .itemId = ITEM_CATCHING_CURSE,
        .price = 0,
        .description = gItemDesc_CatchingCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_GRACE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}めぐみの のろい"),
#else
        .name = _("{JPN}めぐみの のろい"),
#endif
        .itemId = ITEM_GRACE_CURSE,
        .price = 0,
        .description = gItemDesc_GraceCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_WILD_ENCOUNTER_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}やせいの のろい"),
#else
        .name = _("{JPN}やせいの のろい"),
#endif
        .itemId = ITEM_WILD_ENCOUNTER_CURSE,
        .price = 0,
        .description = gItemDesc_WildCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_PARTY_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ようりょうの のろい"),
#else
        .name = _("{JPN}ようりょうの のろい"),
#endif
        .itemId = ITEM_PARTY_CURSE,
        .price = 0,
        .description = gItemDesc_PartyCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_EVERSTONE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}かわらずの のろい"),
#else
        .name = _("{JPN}かわらずの のろい"),
#endif
        .itemId = ITEM_EVERSTONE_CURSE,
        .price = 0,
        .description = gItemDesc_EverstoneCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_BATTLE_ITEM_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}さしおさえの のろい"),
#else
        .name = _("{JPN}さしおさえの のろい"),
#endif
        .itemId = ITEM_BATTLE_ITEM_CURSE,
        .price = 0,
        .description = gItemDesc_BattleItemCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_SPECIES_CLAUSE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}すがたの のろい"),
#else
        .name = _("{JPN}すがたの のろい"),
#endif
        .itemId = ITEM_SPECIES_CLAUSE_CURSE,
        .price = 0,
        .description = gItemDesc_SpeciesClauseCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_SHUFFLE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}シャッフルの のろい"),
#else
        .name = _("{JPN}シャッフルの のろい"),
#endif
        .itemId = ITEM_SHUFFLE_CURSE,
        .price = 0,
        .description = gItemDesc_ItemShuffleCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_SNOWBALL_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ゆきだるまのろい"),
#else
        .name = _("{JPN}ゆきだるまのろい"),
#endif
        .itemId = ITEM_SNOWBALL_CURSE,
        .price = 0,
        .description = gItemDesc_SnowballCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_RANDOMAN_ROUTE_SPAWN_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ワーイの のろい"),
#else
        .name = _("{JPN}ワーイの のろい"),
#endif
        .itemId = ITEM_RANDOMAN_ROUTE_SPAWN_CURSE,
        .price = 0,
        .description = gItemDesc_RandomanRouteSpawnCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_RANDOMAN_ALWAYS_SPAWN_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ワーイ{PLUS}の のろい"),
#else
        .name = _("{JPN}ワーイ{PLUS}の のろい"),
#endif
        .itemId = ITEM_RANDOMAN_ALWAYS_SPAWN_CURSE,
        .price = 0,
        .description = gItemDesc_RandomanAlwaysSpawnCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_AUTO_MOVE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}じどうわざの のろい"),
#else
        .name = _("{JPN}じどうわざの のろい"),
#endif
        .itemId = ITEM_AUTO_MOVE_CURSE,
        .price = 0,
        .description = gItemDesc_AutoMoveSelectCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_ONE_HIT_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}いちげきの のろい"),
#else
        .name = _("{JPN}いちげきの のろい"),
#endif
        .itemId = ITEM_ONE_HIT_CURSE,
        .price = 0,
        .description = gItemDesc_OneHitCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_SNAG_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}スナッチの のろい"),
#else
        .name = _("{JPN}スナッチの のろい"),
#endif
        .itemId = ITEM_SNAG_CURSE,
        .price = 0,
        .description = gItemDesc_SnagCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_WILD_EGG_SPECIES_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}ベイビィの のろい"),
#else
        .name = _("{JPN}ベイビィの のろい"),
#endif
        .itemId = ITEM_WILD_EGG_SPECIES_CURSE,
        .price = 0,
        .description = gItemDesc_WildEggSpeciesCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_MOVE_PRIORITY_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}せんせいの のろい"),
#else
        .name = _("{JPN}せんせいの のろい"),
#endif
        .itemId = ITEM_MOVE_PRIORITY_CURSE,
        .price = 0,
        .description = gItemDesc_PriorityCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_ENDURE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}こらえるの のろい"),
#else
        .name = _("{JPN}こらえるの のろい"),
#endif
        .itemId = ITEM_ENDURE_CURSE,
        .price = 0,
        .description = gItemDesc_EndureCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_TORMENT_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}いちゃもんの のろい"),
#else
        .name = _("{JPN}いちゃもんの のろい"),
#endif
        .itemId = ITEM_TORMENT_CURSE,
        .price = 0,
        .description = gItemDesc_TormentCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_PRESSURE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}プレッシャーのろい"),
#else
        .name = _("{JPN}プレッシャーのろい"),
#endif
        .itemId = ITEM_PRESSURE_CURSE,
        .price = 0,
        .description = gItemDesc_PressureCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_UNAWARE_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}てんねんの のろい"),
#else
        .name = _("{JPN}てんねんの のろい"),
#endif
        .itemId = ITEM_UNAWARE_CURSE,
        .price = 0,
        .description = gItemDesc_UnawareCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },

    [ITEM_ADAPTABILITY_CURSE - ITEM_ROGUE_ITEM_FIRST] =
    {
#ifdef ROGUE_EXPANSION
        .name = _("{JPN}てきおうの のろい"),
#else
        .name = _("{JPN}てきおうの のろい"),
#endif
        .itemId = ITEM_ADAPTABILITY_CURSE,
        .price = 0,
        .description = gItemDesc_AdaptabilityCurse,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .registrability = FALSE,
        .iconImage = gItemIcon_RogueCurse,
        .iconPalette = gItemIconPalette_RogueCurse,
    },
    
    [ITEM_TR01 - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("{JPN}わざレコード"),
        .itemId = ITEM_TR01,
        .price = 1000,
        .description = gText_DexEmptyString,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .registrability = FALSE,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .iconImage = gItemIcon_TM,
        .iconPalette = gItemIconPalette_FightingTMHM,
    },
    [ITEM_TR50 - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("{JPN}わざレコード"),
        .itemId = ITEM_TR50,
        .price = 1000,
        .description = gText_DexEmptyString,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .registrability = FALSE,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .iconImage = gItemIcon_TM,
        .iconPalette = gItemIconPalette_FightingTMHM,
    },

#ifdef ROGUE_DEBUG
    [ITEM_DEBUG_MINT_HARDY - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("DEBUG H MINT"),
        .itemId = ITEM_DEBUG_MINT_HARDY,
        .price = 0,
        .description = gText_DexEmptyString,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .registrability = FALSE,
        .fieldUseFunc = ItemUseOutOfBattle_NatureMint,
        .iconImage = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },
    [ITEM_DEBUG_MINT_ADAMANT - ITEM_ROGUE_ITEM_FIRST] =
    {
        .name = _("DEBUG A MINT"),
        .itemId = ITEM_DEBUG_MINT_ADAMANT,
        .price = 0,
        .description = gText_DexEmptyString,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .registrability = FALSE,
        .fieldUseFunc = ItemUseOutOfBattle_NatureMint,
        .iconImage = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },
#endif
};
