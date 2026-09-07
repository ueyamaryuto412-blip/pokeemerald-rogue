static const u8 sDummyDesc[] = _(
    "?????");

// Poké Balls
static const u8 sPokeBallDesc[] = _("{JPN}やせいの ポケモンに\nなげて つかまえる ための\nボール。");

static const u8 sGreatBallDesc[] = _("{JPN}モンスターボールより\nつかまえやすい\nすこし いい ボール。");

static const u8 sUltraBallDesc[] = _("{JPN}スーパーボールより\nつかまえやすい\nさらに いい ボール。");

static const u8 sMasterBallDesc[] = _("{JPN}かならず つかまえる\nことが できる\nさいこうの ボール。");

static const u8 sPremierBallDesc[] = _("{JPN}なにかの きねんに\nつくられた\nめずらしい ボール。");

static const u8 sHealBallDesc[] = _("{JPN}つかまえた ポケモンを\nかいふくさせる\nボール。");

static const u8 sNetBallDesc[] = _("{JPN}みずタイプと\nむしタイプに\nつかまえやすい ボール。");

static const u8 sNestBallDesc[] = _("{JPN}よわい ポケモンほど\nつかまえやすく\nなる ボール。");

static const u8 sDiveBallDesc[] = _("{JPN}かいていの ポケモンを\nつかまえやすく\nする ボール。");

static const u8 sDuskBallDesc[] = _("{JPN}くらい ばしょで\nつかうと よく\nつかまえられる。");

static const u8 sTimerBallDesc[] = _("{JPN}ターンが かかるほど\nつかまえやすく\nなる ボール。");

static const u8 sQuickBallDesc[] = _("{JPN}さいしょの ターンに\nつかうと よく\nつかまえられる。");

static const u8 sRepeatBallDesc[] = _("{JPN}つかまえた ことの\nある ポケモンほど\nつかまえやすい ボール。");

static const u8 sLuxuryBallDesc[] = _("{JPN}つかまえた ポケモンが\nなつきやすく なる\nやさしい ボール。");

static const u8 sLevelBallDesc[] = _("{JPN}レベルの ひくい\nポケモンを つかまえ\nやすく する ボール。");

static const u8 sLureBallDesc[] = _("{JPN}つりで つかまえる\nポケモンに つよい\nボール。");

static const u8 sMoonBallDesc[] = _("{JPN}つきのいしで しんかする\nポケモンを つかまえ\nやすく する ボール。");

static const u8 sFriendBallDesc[] = _("{JPN}つかまえた ポケモンが\nなついた じょうたいに\nなる ボール。");

static const u8 sLoveBallDesc[] = _("{JPN}せいべつが ちがう\nポケモンを つかまえ\nやすく する ボール。");

static const u8 sFastBallDesc[] = _("{JPN}すばやい ポケモンを\nつかまえやすく\nする ボール。");

static const u8 sHeavyBallDesc[] = _("{JPN}おもい ポケモンを\nつかまえやすく\nする ボール。");

static const u8 sDreamBallDesc[] = _(
#if B_DREAM_BALL_MODIFIER >= GEN_8
    "A Ball that works\n"
    "well on sleeping\n"
    "Pokémon.");
#else
    "A Poké Ball used in\n"
    "the Entree Forest.");
#endif

static const u8 sSafariBallDesc[] = _("{JPN}サファリゾーンでのみ\nつかえる とくべつな\nボール。");

static const u8 sSportBallDesc[] = _("{JPN}むしとり たいかいで\nつかう とくべつな\nボール。");

static const u8 sParkBallDesc[] = _("{JPN}パルパークで つかう\nとくべつな ボール。");

static const u8 sBeastBallDesc[] = _("{JPN}ウルトラビーストを\nつかまえる ボール。");

static const u8 sCherishBallDesc[] = _("{JPN}なにかの きねんに\nつくられた\nめずらしい ボール。");

// Medicine
static const u8 sPotionDesc[] = _("{JPN}ポケモン 1ひきの\nHPを 20だけ\lかいふくする。");

static const u8 sSuperPotionDesc[] = _(
    "Restores the HP of\n"
    "a Pokémon by\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "60 points.");
#else
    "50 points.");
#endif

static const u8 sHyperPotionDesc[] = _(
    "Restores the HP of\n"
    "a Pokémon by\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "120 points.");
#else
    "200 points.");
#endif

static const u8 sMaxPotionDesc[] = _("{JPN}ポケモン 1ひきの HPを\nすべて かいふくする。");

static const u8 sFullRestoreDesc[] = _("{JPN}ポケモン 1ひきの HPと\nじょうたい いじょうを\nすべて かいふくする。");

static const u8 sReviveDesc[] = _("{JPN}ひんしの ポケモンを\nHPの はんぶんで\nいきかえらせる。");

static const u8 sMaxReviveDesc[] = _("{JPN}ひんしの ポケモンを\nHPまんたんで\nいきかえらせる。");

static const u8 sFreshWaterDesc[] = _(
    "A mineral water\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 30 points.");
#else
    "by 50 points.");
#endif

static const u8 sSodaPopDesc[] = _(
    "A fizzy soda drink\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 50 points.");
#else
    "by 60 points.");
#endif

static const u8 sLemonadeDesc[] = _(
    "A very sweet drink\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 70 points.");
#else
    "by 80 points.");
#endif

static const u8 sMoomooMilkDesc[] = _("{JPN}ポケモン 1ひきの\nHPを 100だけ\lかいふくする。");

static const u8 sEnergyPowderDesc[] = _(
    "A bitter powder\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 60 points.");
#else
    "by 50 points.");
#endif

static const u8 sEnergyRootDesc[] = _(
    "A bitter root\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 120 points.");
#else
    "by 200 points.");
#endif

static const u8 sHealPowderDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sRevivalHerbDesc[] = _("{JPN}ひんしの ポケモン\n1ひきの HPを すべて\nかいふくする。");

static const u8 sAntidoteDesc[] = _("{JPN}ポケモン 1ひきの どくを\nなおす。");

static const u8 sParalyzeHealDesc[] = _("{JPN}ポケモン 1ひきの まひを\nなおす。");

static const u8 sBurnHealDesc[] = _("{JPN}ポケモン 1ひきの\nやけどを なおす。");

static const u8 sIceHealDesc[] = _("{JPN}ポケモン 1ひきの\nこおりを なおす。");

static const u8 sAwakeningDesc[] = _("{JPN}ポケモン 1ひきの\nねむりを なおす。");

static const u8 sFullHealDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sEtherDesc[] = _("{JPN}ポケモンが おぼえている\nわざのうち 1つの PPを\n10だけ かいふくする。");

static const u8 sMaxEtherDesc[] = _("{JPN}ポケモンが おぼえている\nわざのうち 1つの PPを\nすべて かいふくする。");

static const u8 sElixirDesc[] = _("{JPN}4つの わざの PPを\n10ずつ かいふく。");

static const u8 sMaxElixirDesc[] = _("{JPN}ポケモンが おぼえている\n4つの わざの PPを\nすべて かいふくする。");

static const u8 sBerryJuiceDesc[] = _("{JPN}ポケモン 1ひきの\nHPを 20だけ\lかいふくする。");

static const u8 sSacredAshDesc[] = _("{JPN}ひんしの ポケモンを\nすべて まんたんで\nいきかえらせる。");

static const u8 sSweetHeartDesc[] = _("{JPN}あまい チョコレート。\nHPを 20だけ\nかいふくする。");

static const u8 sMaxHoneyDesc[] = _("{JPN}ひんしの ポケモンを\nHPまんたんで\nいきかえらせる。");

static const u8 sPewterCrunchiesDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sRageCandyBarDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sLavaCookieDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sOldGateauDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sCasteliaconeDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sLumioseGaletteDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sShalourSableDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sBigMalasadaDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

// Vitamins
static const u8 sHPUpDesc[] = _("{JPN}ポケモン 1ひきの HPの\nきそポイントを あげる。");

static const u8 sProteinDesc[] = _("{JPN}ポケモン 1ひきの\nこうげきの きそポイントを\nあげる。");

static const u8 sIronDesc[] = _("{JPN}ポケモン 1ひきの\nぼうぎょの きそポイントを\nあげる。");

static const u8 sCalciumDesc[] = _("{JPN}ポケモン 1ひきの\nとくこうの きそポイントを\nあげる。");

static const u8 sZincDesc[] = _("{JPN}ポケモン 1ひきの\nとくぼうの きそポイントを\nあげる。");

static const u8 sCarbosDesc[] = _("{JPN}ポケモン 1ひきの\nすばやさの きそポイントを\nあげる。");

static const u8 sPPUpDesc[] = _("{JPN}えらんだ わざの\nPPの さいだいちを\nすこし あげる。");

static const u8 sPPMaxDesc[] = _("{JPN}わざの PPの\nさいだいちを\nいちどに あげる。");

// EV Feathers
static const u8 sHealthFeatherDesc[] = _("{JPN}ポケモンの きほんの\nHPを あげる\nどうぐ。");

static const u8 sMuscleFeatherDesc[] = _("{JPN}ポケモンの きほんの\nこうげきを あげる\nどうぐ。");

static const u8 sResistFeatherDesc[] = _("{JPN}ポケモンの きほんの\nぼうぎょを あげる\nどうぐ。");

static const u8 sGeniusFeatherDesc[] = _("{JPN}ポケモンの きほんの\nとくこうを あげる\nどうぐ。");

static const u8 sCleverFeatherDesc[] = _("{JPN}ポケモンの きほんの\nとくぼうを あげる\nどうぐ。");

static const u8 sSwiftFeatherDesc[] = _("{JPN}ポケモンの きほんの\nすばやさを あげる\nどうぐ。");

// Ability Modifiers
static const u8 sAbilityCapsuleDesc[] = _("{JPN}ポケモンの とくせいを\nきりかえる。");

static const u8 sAbilityPatchDesc[] = _("{JPN}ポケモンの とくせいを\nめずらしい ものに\nかえる。");

// Mints
static const u8 sLonelyMintDesc[] = _("{JPN}かいだ ポケモンの\nこうげきが あがり\nぼうぎょが さがる。");

static const u8 sAdamantMintDesc[] = _("{JPN}かいだ ポケモンの\nこうげきが あがり\nとくこうが さがる。");

static const u8 sNaughtyMintDesc[] = _("{JPN}かいだ ポケモンの\nこうげきが あがり\nとくぼうが さがる。");

static const u8 sBraveMintDesc[] = _("{JPN}かいだ ポケモンの\nこうげきが あがり\nすばやさが さがる。");

static const u8 sBoldMintDesc[] = _("{JPN}かいだ ポケモンの\nぼうぎょが あがり\nこうげきが さがる。");

static const u8 sImpishMintDesc[] = _("{JPN}かいだ ポケモンの\nぼうぎょが あがり\nとくこうが さがる。");

static const u8 sLaxMintDesc[] = _("{JPN}かいだ ポケモンの\nぼうぎょが あがり\nとくぼうが さがる。");

static const u8 sRelaxedMintDesc[] = _("{JPN}かいだ ポケモンの\nぼうぎょが あがり\nすばやさが さがる。");

static const u8 sModestMintDesc[] = _("{JPN}かいだ ポケモンの\nとくこうが あがり\nこうげきが さがる。");

static const u8 sMildMintDesc[] = _("{JPN}かいだ ポケモンの\nとくこうが あがり\nぼうぎょが さがる。");

static const u8 sRashMintDesc[] = _("{JPN}かいだ ポケモンの\nとくこうが あがり\nとくぼうが さがる。");

static const u8 sQuietMintDesc[] = _("{JPN}かいだ ポケモンの\nとくこうが あがり\nすばやさが さがる。");

static const u8 sCalmMintDesc[] = _("{JPN}かいだ ポケモンの\nとくぼうが あがり\nこうげきが さがる。");

static const u8 sGentleMintDesc[] = _("{JPN}かいだ ポケモンの\nとくぼうが あがり\nぼうぎょが さがる。");

static const u8 sCarefulMintDesc[] = _("{JPN}かいだ ポケモンの\nとくぼうが あがり\nとくこうが さがる。");

static const u8 sSassyMintDesc[] = _("{JPN}かいだ ポケモンの\nとくぼうが あがり\nすばやさが さがる。");

static const u8 sTimidMintDesc[] = _("{JPN}かいだ ポケモンの\nすばやさが あがり\nこうげきが さがる。");

static const u8 sHastyMintDesc[] = _("{JPN}かいだ ポケモンの\nすばやさが あがり\nぼうぎょが さがる。");

static const u8 sJollyMintDesc[] = _("{JPN}かいだ ポケモンの\nすばやさが あがり\nとくこうが さがる。");

static const u8 sNaiveMintDesc[] = _("{JPN}かいだ ポケモンの\nすばやさが あがり\nとくぼうが さがる。");

static const u8 sSeriousMintDesc[] = _("{JPN}かいだ ポケモンの\nのうりょくが すべて\nおなじだけ のびる。");

// Candy
static const u8 sRareCandyDesc[] = _("{JPN}あたえると ポケモン\n1ひきの レベルが 1だけ\nあがる。");

static const u8 sExpCandyXSDesc[] = _("{JPN}ポケモン 1ぴきに\nごく すこしの\nけいけんちを あげる。");

static const u8 sExpCandySDesc[] = _("{JPN}ポケモン 1ぴきに\nすこしの けいけんちを\nあげる。");

static const u8 sExpCandyMDesc[] = _("{JPN}ポケモン 1ぴきに\nそこそこの けいけんちを\nあげる。");

static const u8 sExpCandyLDesc[] = _("{JPN}ポケモン 1ぴきに\nおおくの けいけんちを\nあげる。");

static const u8 sExpCandyXLDesc[] = _("{JPN}ポケモン 1ぴきに\nとても おおくの\nけいけんちを あげる。");

static const u8 sDynamaxCandyDesc[] = _("{JPN}ポケモン 1ぴきの\nダイマックスレベルを\n1つ あげる。");

// Medicinal Flutes
static const u8 sBlueFluteDesc[] = _("{JPN}ねむり\nじょうたいを\lかいふくする。");

static const u8 sYellowFluteDesc[] = _("{JPN}こんらん\nじょうたいを\lかいふくする。");

static const u8 sRedFluteDesc[] = _("{JPN}メロメロ\nじょうたいを\lかいふくする。");

// Encounter-modifying Flutes
static const u8 sBlackFluteDesc[] = _("{JPN}つかった ばしょで\nつよいポケモンと そうぐう\nしやすくなる。");

static const u8 sWhiteFluteDesc[] = _("{JPN}よわい ポケモンと\nであいやすく なる。");

// Encounter Modifiers
static const u8 sRepelDesc[] = _("{JPN}100ぽの あいだ\nよわい やせいポケモンを\nよせつけない。");

static const u8 sSuperRepelDesc[] = _("{JPN}よわい やせいの\nポケモンが まったく でて\nこなくなる。");

static const u8 sMaxRepelDesc[] = _("{JPN}よわい やせいの\nポケモンが まったく でて\nこなくなる。");

static const u8 sLureDesc[] = _("{JPN}100ぽの あいだ\nポケモンが でやすく\nなる。");

static const u8 sSuperLureDesc[] = _("{JPN}200ぽの あいだ\nポケモンが でやすく\nなる。");

static const u8 sMaxLureDesc[] = _("{JPN}250ぽの あいだ\nポケモンが でやすく\nなる。");

static const u8 sEscapeRopeDesc[] = _("{JPN}どうくつや ダンジョンから\nぬけだすことが できる。\nなんどでも つかえる。");

// Battle items
static const u8 sXAttackDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Attack during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Attack during one\n"
    "battle.");
#endif

static const u8 sXDefenseDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Defense during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Defense during one\n"
    "battle.");
#endif

static const u8 sXSpAtkDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Sp. Atk during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Sp. Atk during one\n"
    "battle.");
#endif

static const u8 sXSpDefDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Sp. Def during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Sp. Def during one\n"
    "battle.");
#endif

static const u8 sXSpeedDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Speed during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Speed during one\n"
    "battle.");
#endif

static const u8 sXAccuracyDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises move\n"
    "accuracy during\n"
    "one battle.");
#else
    "Raises accuracy\n"
    "of attack moves\n"
    "during one battle.");
#endif

static const u8 sDireHitDesc[] = _("{JPN}きゅうしょりつが おおきく\nあがる。 いちどしか\nつかうことが できない。");

static const u8 sGuardSpecDesc[] = _("{JPN}バトルで つかうと\nのうりょくが さがるのを\nふせぐ。");

// Escape Items
static const u8 sPokeDollDesc[] = _("{JPN}やせいポケモンとの\nせんとうから ぜったいに\nにげられる。");

static const u8 sFluffyTailDesc[] = _("{JPN}やせいポケモンとの\nせんとうから ぜったいに\nにげられる。");

static const u8 sPokeToyDesc[] = _("{JPN}やせいポケモンとの\nせんとうから ぜったいに\nにげられる。");

static const u8 sMaxMushroomsDesc[] = _("{JPN}1かいの バトルで\nすべての のうりょくを\n1だんかい あげる。");

// Treasures
static const u8 sBottleCapDesc[] = _("{JPN}ぎんいろに かがやく\nうつくしい\nおうかん。");

static const u8 sGoldBottleCapDesc[] = _("{JPN}きんいろに かがやく\nうつくしい\nおうかん。");

static const u8 sNuggetDesc[] = _("{JPN}キラキラと きんいろに\nひかる じゅんきん せいの\nたま。");

static const u8 sBigNuggetDesc[] = _("{JPN}きんの おおきな\nかたまり。たかく\nうれる。");

static const u8 sTinyMushroomDesc[] = _("{JPN}いちぶの マニアの\nあいだでは けっこう\nにんきが たかい。");

static const u8 sBigMushroomDesc[] = _("{JPN}いちぶの マニアの\nあいだでは とても\nにんきが たかい。");

static const u8 sBalmMushroomDesc[] = _("{JPN}いちぶの マニアの\nあいだでは とても\nにんきが たかい。");

static const u8 sPearlDesc[] = _("{JPN}きれいな ぎんいろに\nひかる すこし ちいさめの\nしんじゅ。");

static const u8 sBigPearlDesc[] = _("{JPN}きれいな ぎんいろに\nひかる かなり おおつぶの\nしんじゅ。");

static const u8 sPearlStringDesc[] = _("{JPN}とても おおきな\nしんじゅ。たかく\nうれる。");

static const u8 sStardustDesc[] = _("{JPN}てざわりが サラサラの\nあかくて きれいな\lすな。");

static const u8 sStarPieceDesc[] = _("{JPN}キラキラと あかく ひかる\nきれいな ほうせきの\nかけら。");

static const u8 sCometShardDesc[] = _("{JPN}すいせいの\nかけら。 たかく\lうれる。");

static const u8 sShoalSaltDesc[] = _("{JPN}あさせのほらあなで\nみつけた しお。");

static const u8 sShoalShellDesc[] = _("{JPN}あさせのほらあなで\nみつけた\lかいがら。");

static const u8 sRedShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sBlueShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sYellowShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sGreenShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sHeartScaleDesc[] = _("{JPN}きれいな ハートの\nかたちの とても\nめずらしい ウロコ。");

static const u8 sHoneyDesc[] = _("{JPN}つかうと やせいの\nポケモンを よびよせる\nあまい ミツ。");

static const u8 sRareBoneDesc[] = _("{JPN}とても めずらしい\nほね。たかく\lうれる。");

static const u8 sOddKeystoneDesc[] = _("{JPN}ときどき こえが\nきこえる ふしぎな\nいし。");

static const u8 sPrettyFeatherDesc[] = _("{JPN}うつくしいが なんの\nこうかも ない\nはね。");

static const u8 sRelicCopperDesc[] = _("{JPN}むかし つかわれた\nどうかへい。たかく\nうれる。");

static const u8 sRelicSilverDesc[] = _("{JPN}むかし つかわれた\nぎんかへい。たかく\nうれる。");

static const u8 sRelicGoldDesc[] = _("{JPN}むかし つかわれた\nきんかへい。たかく\nうれる。");

static const u8 sRelicVaseDesc[] = _("{JPN}むかし つくられた\nつぼ。たかく\lうれる。");

static const u8 sRelicBandDesc[] = _("{JPN}ふるい うでわ。\nたかく うれる。");

static const u8 sRelicStatueDesc[] = _("{JPN}ふるい ぞう。\nたかく\lうれる。");

static const u8 sRelicCrownDesc[] = _("{JPN}ふるい\nおうかん。\lたかく うれる。");

static const u8 sStrangeSouvenirDesc[] = _("{JPN}アローラの ポケモンを\nかたどった\nかざり。");

// Fossils
static const u8 sHelixFossilDesc[] = _("{JPN}おおむかし うみに\nすんでいた こだい\nポケモンの カセキ。");

static const u8 sDomeFossilDesc[] = _("{JPN}おおむかし うみに\nすんでいた こだい\nポケモンの カセキ。");

static const u8 sOldAmberDesc[] = _("{JPN}あかみを\nおびて\lすけている。");

static const u8 sRootFossilDesc[] = _("{JPN}むかし かいていに\nすんでいた ポケモンの\nカセキ。");

static const u8 sClawFossilDesc[] = _("{JPN}むかし かいていに\nすんでいた ポケモンの\nカセキ。");

static const u8 sArmorFossilDesc[] = _("{JPN}おおむかしの\nポケモンの あたまの\lかけら。");

static const u8 sSkullFossilDesc[] = _("{JPN}おおむかしの\nポケモンの あたまの\lかけら。");

static const u8 sCoverFossilDesc[] = _("{JPN}おおむかしの\nポケモンの せなかの\lかけら。");

static const u8 sPlumeFossilDesc[] = _("{JPN}おおむかしの\nポケモンの つばさの\lかけら。");

static const u8 sJawFossilDesc[] = _("{JPN}おおむかしの ポケモンの\nおおきな あごの\nかけら。");

static const u8 sSailFossilDesc[] = _("{JPN}おおむかしの\nポケモンの せびれの\lかけら。");

static const u8 sFossilizedBirdDesc[] = _("{JPN}むかし そらを\nとんでいた ポケモンの\lカセキ。");

static const u8 sFossilizedFishDesc[] = _("{JPN}むかし うみに\nすんでいた ポケモンの\lカセキ。");

static const u8 sFossilizedDrakeDesc[] = _("{JPN}むかし りくに\nすんでいた ポケモンの\lカセキ。");

static const u8 sFossilizedDinoDesc[] = _("{JPN}むかし うみに\nすんでいた ポケモンの\lカセキ。");

// Mulch
static const u8 sGrowthMulchDesc[] = _("{JPN}きのみの\nせいちょうを\lはやめる ひりょう。");

static const u8 sDampMulchDesc[] = _("{JPN}きのみの せいちょうを\nおそくする ひりょう。");

static const u8 sStableMulchDesc[] = _("{JPN}きのみの きの\nじゅみょうを のばす\nひりょう。");

static const u8 sGooeyMulchDesc[] = _("{JPN}おちたあとに きのみが\nおおく はえなおる\nひりょう。");

static const u8 sRichMulchDesc[] = _("{JPN}とれる きのみの\nかずが ふえる\nひりょう。");

static const u8 sSurpriseMulchDesc[] = _("{JPN}きのみが へんいする\nかくりつが あがる\nひりょう。");

static const u8 sBoostMulchDesc[] = _("{JPN}やわらかい つちが\nかわく はやさを\nあげる ひりょう。");

static const u8 sAmazeMulchDesc[] = _("{JPN}ゆたかで おどろきが\nあって そだちも よい\nひりょう。");

// Apricorns
static const u8 sRedApricornDesc[] = _("{JPN}あかい ぼんぐり。\nつーんと はなにくる\nにおいがする。");

static const u8 sBlueApricornDesc[] = _("{JPN}あおい ぼんぐり。\nすこし あおくさい\lかおりがする。");

static const u8 sYellowApricornDesc[] = _("{JPN}きいろの ぼんぐり。\nさわやかな かおりが\nする。");

static const u8 sGreenApricornDesc[] = _("{JPN}みどりの ぼんぐり。\nふしぎな かおりが\nする。");

static const u8 sPinkApricornDesc[] = _("{JPN}ももいろの ぼんぐり。\nあまそうな いい\nにおいがする。");

static const u8 sWhiteApricornDesc[] = _("{JPN}しろい ぼんぐり。\nなんの においも\lしない。");

static const u8 sBlackApricornDesc[] = _("{JPN}くろい ぼんぐり。\nなんともいえない\nにおいがする。");

static const u8 sWishingPieceDesc[] = _("{JPN}{PKMN}の すあなに\nなげて ダイマックスの\nポケモンを よびよせる。");

static const u8 sGalaricaTwigDesc[] = _("{JPN}ガラルの\nガラナツと いう\lきの えだ。");

static const u8 sArmoriteOreDesc[] = _("{JPN}めずらしい こうせき。\nガラルの ヨロイじまで\nみつかる。");

static const u8 sDyniteOreDesc[] = _("{JPN}ふしぎな こうせき。\nガラルの マックスラボで\nみつかる。");

// Mail
static const u8 sOrangeMailDesc[] = _("{JPN}ポケモンに もたせる\nジグザグマの もようの\nてがみ。");

static const u8 sHarborMailDesc[] = _("{JPN}ポケモンに もたせる\nキャモメの もようの\nてがみ。");

static const u8 sGlitterMailDesc[] = _("{JPN}ポケモンに もたせる\nピカチュウの もようの\nてがみ。");

static const u8 sMechMailDesc[] = _("{JPN}ポケモンに もたせる\nコイルの もようの\nてがみ。");

static const u8 sWoodMailDesc[] = _("{JPN}ポケモンに もたせる\nナマケロの もようの\nてがみ。");

static const u8 sWaveMailDesc[] = _("{JPN}ポケモンに もたせる\nホエルコの もようの\nてがみ。");

static const u8 sBeadMailDesc[] = _("{JPN}もっている ポケモンの\nえが かかれた\nてがみ。");

static const u8 sShadowMailDesc[] = _("{JPN}ポケモンに もたせる\nヨマワルの もようの\nてがみ。");

static const u8 sTropicMailDesc[] = _("{JPN}ポケモンに もたせる\nキレイハナの もようの\nてがみ。");

static const u8 sDreamMailDesc[] = _("{JPN}もっている ポケモンの\nえが かかれた\nてがみ。");

static const u8 sFabMailDesc[] = _("{JPN}ポケモンに もたせる\nごうかな もようの\nてがみ。");

static const u8 sRetroMailDesc[] = _("{JPN}3びきの ポケモンの\nえが かかれた\nてがみ。");

// Evolution Items
static const u8 sFireStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sWaterStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sThunderStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sLeafStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sIceStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sSunStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sMoonStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sShinyStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sDuskStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sDawnStoneDesc[] = _("{JPN}とくていの\nポケモンを\lしんかさせる。");

static const u8 sSweetAppleDesc[] = _("{JPN}とても あまい りんご。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sTartAppleDesc[] = _("{JPN}とても すっぱい りんご。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sCrackedPotDesc[] = _("{JPN}われた きゅうす。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sChippedPotDesc[] = _("{JPN}かけた きゅうす。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sGalaricaCuffDesc[] = _("{JPN}ガラルの うでわ。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sGalaricaWreathDesc[] = _("{JPN}ガラルの はなわ。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sDragonScaleDesc[] = _("{JPN}ドラゴンタイプの\nポケモンが\nもっていることが ある。");

static const u8 sUpgradeDesc[] = _("{JPN}いろんな じょうほうが\nつまった きかい。");

static const u8 sProtectorDesc[] = _("{JPN}とくていの ポケモンが\nこのむ かたくて\nおもい もの。");

static const u8 sElectirizerDesc[] = _("{JPN}とくていの ポケモンが\nこのむ でんきの\nエネルギーの かたまり。");

static const u8 sMagmarizerDesc[] = _("{JPN}とくていの ポケモンが\nこのむ マグマの\nエネルギーの かたまり。");

static const u8 sDubiousDiscDesc[] = _("{JPN}あやしい データが\nあふれた とうめいな\nそうち。");

static const u8 sReaperClothDesc[] = _("{JPN}とくていの ポケモンが\nこのむ れいてきな\nちからの こもった もの。");

static const u8 sPrismScaleDesc[] = _("{JPN}かがやく ふしぎな\nウロコ。とくていの\nポケモンを しんかさせる。");

static const u8 sWhippedDreamDesc[] = _("{JPN}とくていの ポケモンが\nこのむ やわらかくて\nあまい おかし。");

static const u8 sSachetDesc[] = _("{JPN}とくていの ポケモンが\nこのむ かおりの\nつまった ふくろ。");

static const u8 sOvalStoneDesc[] = _("{JPN}タマゴのような かたち。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sStrawberrySweetDesc[] = _("{JPN}マホミルが このむ\nイチゴのかたちの\nおかし。");

static const u8 sLoveSweetDesc[] = _("{JPN}マホミルが このむ\nハートのかたちの\nおかし。");

static const u8 sBerrySweetDesc[] = _("{JPN}マホミルが すきな\nきのみの かたちの\lあめ。");

static const u8 sCloverSweetDesc[] = _("{JPN}マホミルが すきな\nクローバーの\lあめ。");

static const u8 sFlowerSweetDesc[] = _("{JPN}マホミルが すきな\nはなの かたちの\lあめ。");

static const u8 sStarSweetDesc[] = _("{JPN}マホミルが すきな\nほしの かたちの\lあめ。");

static const u8 sRibbonSweetDesc[] = _("{JPN}マホミルが\nすきな リボンの\lあめ。");

static const u8 sEverstoneDesc[] = _("{JPN}しんかを とめる\nふしぎな\lもちもの。");

static const u8 sBlackAuguriteDesc[] = _("{JPN}ある ポケモンを\nしんか させる くろい\lいし。");;

static const u8 sLinkingCordDesc[] = _("{JPN}ある ポケモンを\nしんか させる\lふしぎな ひも。");

static const u8 sPeatBlockDesc[] = _("{JPN}ある ポケモンを\nしんか させる\lかたまり。");

// Nectars
static const u8 sRedNectarDesc[] = _("{JPN}ある ポケモンの\nすがたを かえる はなの\lみつ。");

static const u8 sYellowNectarDesc[] = _("{JPN}ある ポケモンの\nすがたを かえる はなの\lみつ。");

static const u8 sPinkNectarDesc[] = _("{JPN}ある ポケモンの\nすがたを かえる はなの\lみつ。");

static const u8 sPurpleNectarDesc[] = _("{JPN}ある ポケモンの\nすがたを かえる はなの\lみつ。");

// Plates
static const u8 sFlamePlateDesc[] = _("{JPN}ほのおタイプの\nわざを つよくする\lばん。");

static const u8 sSplashPlateDesc[] = _("{JPN}みずタイプの\nわざを つよくする\lばん。");

static const u8 sZapPlateDesc[] = _("{JPN}でんきタイプの\nわざを つよくする\lばん。");

static const u8 sMeadowPlateDesc[] = _("{JPN}くさタイプの\nわざを つよくする\lばん。");

static const u8 sIciclePlateDesc[] = _("{JPN}こおりタイプの\nわざを つよくする\lばん。");

static const u8 sFistPlateDesc[] = _("{JPN}かくとうタイプの\nわざを つよくする\lばん。");

static const u8 sToxicPlateDesc[] = _("{JPN}どくタイプの\nわざを つよくする\lばん。");

static const u8 sEarthPlateDesc[] = _("{JPN}じめんタイプの\nわざを つよくする\lばん。");

static const u8 sSkyPlateDesc[] = _("{JPN}ひこうタイプの\nわざを つよくする\lばん。");

static const u8 sMindPlateDesc[] = _("{JPN}エスパータイプの\nわざを つよくする\lばん。");

static const u8 sInsectPlateDesc[] = _("{JPN}むしタイプの\nわざを つよくする\lばん。");

static const u8 sStonePlateDesc[] = _("{JPN}いわタイプの\nわざを つよくする\lばん。");

static const u8 sSpookyPlateDesc[] = _("{JPN}ゴーストタイプの\nわざを つよくする\lばん。");

static const u8 sDracoPlateDesc[] = _("{JPN}ドラゴンタイプの\nわざを つよくする\lばん。");

static const u8 sDreadPlateDesc[] = _("{JPN}あくタイプの\nわざを つよくする\lばん。");

static const u8 sIronPlateDesc[] = _("{JPN}はがねタイプの\nわざを つよくする\lばん。");

static const u8 sPixiePlateDesc[] = _("{JPN}フェアリータイプの\nわざを つよくする\lばん。");

// Drives
static const u8 sDouseDriveDesc[] = _("{JPN}ゲノセクトの わざを\nみずタイプに\lかえる。");

static const u8 sShockDriveDesc[] = _("{JPN}ゲノセクトの わざを\nでんきタイプに\lかえる。");

static const u8 sBurnDriveDesc[] = _("{JPN}ゲノセクトの わざを\nほのおタイプに\lかえる。");

static const u8 sChillDriveDesc[] = _("{JPN}ゲノセクトの わざを\nこおりタイプに\lかえる。");

// Memories
static const u8 sFireMemoryDesc[] = _("{JPN}ほのおタイプの\nデータが はいった\lディスク。");

static const u8 sWaterMemoryDesc[] = _("{JPN}みずタイプの\nデータが はいった\lディスク。");

static const u8 sElectricMemoryDesc[] = _("{JPN}でんきタイプの\nデータが はいった\lディスク。");

static const u8 sGrassMemoryDesc[] = _("{JPN}くさタイプの\nデータが はいった\lディスク。");

static const u8 sIceMemoryDesc[] = _("{JPN}こおりタイプの\nデータが はいった\lディスク。");

static const u8 sFightingMemoryDesc[] = _("{JPN}かくとうタイプの\nデータが はいった\lディスク。");

static const u8 sPoisonMemoryDesc[] = _("{JPN}どくタイプの\nデータが はいった\lディスク。");

static const u8 sGroundMemoryDesc[] = _("{JPN}じめんタイプの\nデータが はいった\lディスク。");

static const u8 sFlyingMemoryDesc[] = _("{JPN}ひこうタイプの\nデータが はいった\lディスク。");

static const u8 sPsychicMemoryDesc[] = _("{JPN}エスパータイプの\nデータが はいった\lディスク。");

static const u8 sBugMemoryDesc[] = _("{JPN}むしタイプの\nデータが はいった\lディスク。");

static const u8 sRockMemoryDesc[] = _("{JPN}いわタイプの\nデータが はいった\lディスク。");

static const u8 sGhostMemoryDesc[] = _("{JPN}ゴーストタイプの\nデータが はいった\lディスク。");

static const u8 sDragonMemoryDesc[] = _("{JPN}ドラゴンタイプの\nデータが はいった\lディスク。");

static const u8 sDarkMemoryDesc[] = _("{JPN}あくタイプの\nデータが はいった\lディスク。");

static const u8 sSteelMemoryDesc[] = _("{JPN}はがねタイプの\nデータが はいった\lディスク。");

static const u8 sFairyMemoryDesc[] = _("{JPN}フェアリータイプの\nデータが はいった\nディスク。");

static const u8 sRustedSwordDesc[] = _("{JPN}さびた つるぎ。\nえいゆうが わざわいを\nとめた。");

static const u8 sRustedShieldDesc[] = _("{JPN}さびた たて。\nえいゆうが わざわいを\lとめた。");

// Colored Orbs
static const u8 sRedOrbDesc[] = _("{JPN}いにしえの ちからを\nひめた あかい\lたま。");

static const u8 sBlueOrbDesc[] = _("{JPN}いにしえの ちからを\nひめた あおい\lたま。");

// Mega Stones
static const u8 sVenusauriteDesc[] = _("{JPN}フシギバナが メガシンカ\nできる ように なる\nいし。");

static const u8 sCharizarditeDesc[] = _("{JPN}リザードンが メガシンカ\nできる ように なる\nいし。");

static const u8 sBlastoisiniteDesc[] = _("{JPN}カメックスが メガシンカ\nできる ように なる\nいし。");

static const u8 sBeedrilliteDesc[] = _("{JPN}スピアーが メガシンカ\nできる ように なる\nいし。");

static const u8 sPidgeotiteDesc[] = _("{JPN}ピジョットが メガシンカ\nできる ように なる\nいし。");

static const u8 sAlakaziteDesc[] = _("{JPN}フーディンが メガシンカ\nできる ように なる\nいし。");

static const u8 sSlowbroniteDesc[] = _("{JPN}ヤドランが メガシンカ\nできる ように なる\nいし。");

static const u8 sGengariteDesc[] = _("{JPN}ゲンガーが メガシンカ\nできる ように なる\nいし。");

static const u8 sKangaskhaniteDesc[] = _("{JPN}ガルーラが メガシンカ\nできる ように なる\nいし。");

static const u8 sPinsiriteDesc[] = _("{JPN}カイロスが メガシンカ\nできる ように なる\nいし。");

static const u8 sGyaradositeDesc[] = _("{JPN}ギャラドスが メガシンカ\nできる ように なる\nいし。");

static const u8 sAerodactyliteDesc[] = _("{JPN}プテラが メガシンカ\nできる ように なる\nいし。");

static const u8 sMewtwoniteDesc[] = _("{JPN}ミュウツーが メガシンカ\nできる ように なる\nいし。");

static const u8 sRaichuniteDesc[] = _("{JPN}ライチュウが メガシンカ\nできる ように なる\nいし。");

static const u8 sAmpharositeDesc[] = _("{JPN}デンリュウが メガシンカ\nできる ように なる\nいし。");

static const u8 sSteelixiteDesc[] = _("{JPN}ハガネールが メガシンカ\nできる ように なる\nいし。");

static const u8 sScizoriteDesc[] = _("{JPN}ハッサムが メガシンカ\nできる ように なる\nいし。");

static const u8 sHeracroniteDesc[] = _("{JPN}ヘラクロスが メガシンカ\nできる ように なる\nいし。");

static const u8 sHoundoominiteDesc[] = _("{JPN}ヘルガーが メガシンカ\nできる ように なる\nいし。");

static const u8 sTyranitariteDesc[] = _("{JPN}バンギラスが メガシンカ\nできる ように なる\nいし。");

static const u8 sSceptiliteDesc[] = _("{JPN}ジュカインが メガシンカ\nできる ように なる\nいし。");

static const u8 sBlazikeniteDesc[] = _("{JPN}バシャーモが メガシンカ\nできる ように なる\nいし。");

static const u8 sSwampertiteDesc[] = _("{JPN}ラグラージが メガシンカ\nできる ように なる\nいし。");

static const u8 sGardevoiriteDesc[] = _("{JPN}サーナイトが メガシンカ\nできる ように なる\nいし。");

static const u8 sSableniteDesc[] = _("{JPN}ヤミラミが メガシンカ\nできる ように なる\nいし。");

static const u8 sMawiliteDesc[] = _("{JPN}クチートが メガシンカ\nできる ように なる\nいし。");

static const u8 sAggroniteDesc[] = _("{JPN}ボスゴドラが メガシンカ\nできる ように なる\nいし。");

static const u8 sMedichamiteDesc[] = _("{JPN}チャーレムが メガシンカ\nできる ように なる\nいし。");

static const u8 sManectiteDesc[] = _("{JPN}ライボルトが メガシンカ\nできる ように なる\nいし。");

static const u8 sSharpedoniteDesc[] = _("{JPN}サメハダーが メガシンカ\nできる ように なる\nいし。");

static const u8 sCameruptiteDesc[] = _("{JPN}バクーダが メガシンカ\nできる ように なる\nいし。");

static const u8 sAltarianiteDesc[] = _("{JPN}チルタリスが メガシンカ\nできる ように なる\nいし。");

static const u8 sBanettiteDesc[] = _("{JPN}ジュペッタが メガシンカ\nできる ように なる\nいし。");

static const u8 sAbsoliteDesc[] = _("{JPN}アブソルが メガシンカ\nできる ように なる\nいし。");

static const u8 sGlalititeDesc[] = _("{JPN}オニゴーリが メガシンカ\nできる ように なる\nいし。");

static const u8 sSalamenciteDesc[] = _("{JPN}ボーマンダが メガシンカ\nできる ように なる\nいし。");

static const u8 sMetagrossiteDesc[] = _("{JPN}メタグロスが メガシンカ\nできる ように なる\nいし。");

static const u8 sLatiasiteDesc[] = _("{JPN}ラティアスが メガシンカ\nできる ように なる\nいし。");

static const u8 sLatiositeDesc[] = _("{JPN}ラティオスが メガシンカ\nできる ように なる\nいし。");

static const u8 sLopunniteDesc[] = _("{JPN}ミミロップが メガシンカ\nできる ように なる\nいし。");

static const u8 sGarchompiteDesc[] = _("{JPN}ガブリアスが メガシンカ\nできる ように なる\nいし。");

static const u8 sLucarioniteDesc[] = _("{JPN}ルカリオが メガシンカ\nできる ように なる\nいし。");

static const u8 sAbomasiteDesc[] = _("{JPN}ユキノオーが メガシンカ\nできる ように なる\nいし。");

static const u8 sGalladiteDesc[] = _("{JPN}エルレイドが メガシンカ\nできる ように なる\nいし。");

static const u8 sAudiniteDesc[] = _("{JPN}タブンネが メガシンカ\nできる ように なる\nいし。");

static const u8 sDianciteDesc[] = _("{JPN}ディアンシーが メガシンカ\nできる ように なる\nいし。");

// Gems
static const u8 sNormalGemDesc[] = _("{JPN}ノーマルタイプの\nわざの いりょくを\lあげる。");

static const u8 sFireGemDesc[] = _("{JPN}ほのおタイプの\nわざの いりょくを\lあげる。");

static const u8 sWaterGemDesc[] = _("{JPN}みずタイプの\nわざの いりょくを\lあげる。");

static const u8 sElectricGemDesc[] = _("{JPN}でんきタイプの\nわざの いりょくを\lあげる。");

static const u8 sGrassGemDesc[] = _("{JPN}くさタイプの\nわざの いりょくを\lあげる。");

static const u8 sIceGemDesc[] = _("{JPN}こおりタイプの\nわざの いりょくを\lあげる。");

static const u8 sFightingGemDesc[] = _("{JPN}かくとうタイプの\nわざの いりょくを\lあげる。");

static const u8 sPoisonGemDesc[] = _("{JPN}どくタイプの\nわざの いりょくを\lあげる。");

static const u8 sGroundGemDesc[] = _("{JPN}じめんタイプの\nわざの いりょくを\lあげる。");

static const u8 sFlyingGemDesc[] = _("{JPN}ひこうタイプの\nわざの いりょくを\lあげる。");

static const u8 sPsychicGemDesc[] = _("{JPN}エスパータイプの\nわざの いりょくを\lあげる。");

static const u8 sBugGemDesc[] = _("{JPN}むしタイプの\nわざの いりょくを\lあげる。");

static const u8 sRockGemDesc[] = _("{JPN}いわタイプの\nわざの いりょくを\lあげる。");

static const u8 sGhostGemDesc[] = _("{JPN}ゴーストタイプの\nわざの いりょくを\lあげる。");

static const u8 sDragonGemDesc[] = _("{JPN}ドラゴンタイプの\nわざの いりょくを\lあげる。");

static const u8 sDarkGemDesc[] = _("{JPN}あくタイプの\nわざの いりょくを\lあげる。");

static const u8 sSteelGemDesc[] = _("{JPN}はがねタイプの\nわざの いりょくを\lあげる。");

static const u8 sFairyGemDesc[] = _("{JPN}フェアリータイプの\nわざの いりょくを\lあげる。");

// Z-Crystals
static const u8 sNormaliumZDesc[] = _("{JPN}ノーマルタイプの\nわざを Zわざに\lする。");

static const u8 sFiriumZDesc[] = _("{JPN}ほのおタイプの\nわざを Zわざに\lする。");

static const u8 sWateriumZDesc[] = _("{JPN}みずタイプの\nわざを Zわざに\lする。");

static const u8 sElectriumZDesc[] = _("{JPN}でんきタイプの\nわざを Zわざに\lする。");

static const u8 sGrassiumZDesc[] = _("{JPN}くさタイプの\nわざを Zわざに\lする。");

static const u8 sIciumZDesc[] = _("{JPN}こおりタイプの\nわざを Zわざに\lする。");

static const u8 sFightiniumZDesc[] = _("{JPN}かくとうタイプの\nわざを Zわざに\lする。");

static const u8 sPoisoniumZDesc[] = _("{JPN}どくタイプの\nわざを Zわざに\lする。");

static const u8 sGroundiumZDesc[] = _("{JPN}じめんタイプの\nわざを Zわざに\lする。");

static const u8 sFlyiniumZDesc[] = _("{JPN}ひこうタイプの\nわざを Zわざに\lする。");

static const u8 sPsychiumZDesc[] = _("{JPN}エスパータイプの\nわざを Zわざに\lする。");

static const u8 sBuginiumZDesc[] = _("{JPN}むしタイプの\nわざを Zわざに\lする。");

static const u8 sRockiumZDesc[] = _("{JPN}いわタイプの\nわざを Zわざに\lする。");

static const u8 sGhostiumZDesc[] = _("{JPN}ゴーストタイプの\nわざを Zわざに\lする。");

static const u8 sDragoniumZDesc[] = _("{JPN}ドラゴンタイプの\nわざを Zわざに\lする。");

static const u8 sDarkiniumZDesc[] = _("{JPN}あくタイプの\nわざを Zわざに\lする。");

static const u8 sSteeliumZDesc[] = _("{JPN}はがねタイプの\nわざを Zわざに\lする。");

static const u8 sFairiumZDesc[] = _("{JPN}フェアリータイプの\nわざを Zわざに\lする。");

static const u8 sPikaniumZDesc[] = _("{JPN}ピカチュウの\nボルテッカーを Zわざに\nする。");

static const u8 sEeviumZDesc[] = _("{JPN}イーブイの\nとっておきを Zわざに\lする。");

static const u8 sSnorliumZDesc[] = _("{JPN}カビゴンの\nギガインパクトを Zわざに\nする。");

static const u8 sMewniumZDesc[] = _("{JPN}ミュウの\nサイコキネシスを\lZわざに する。");

static const u8 sDecidiumZDesc[] = _("{JPN}ジュナイパーの\nかげぬいを Zわざに\lする。");

static const u8 sInciniumZDesc[] = _("{JPN}ガオガエンの\nDDラリアットを Zわざに\nする。");

static const u8 sPrimariumZDesc[] = _("{JPN}アシレーヌの うたかたの\nアリアを Zわざに\lする。");

static const u8 sLycaniumZDesc[] = _("{JPN}ルガルガンの\nストーンエッジを Zわざに\nする。");

static const u8 sMimikiumZDesc[] = _("{JPN}ミミッキュの\nじゃれつくを Zわざに\lする。");

static const u8 sKommoniumZDesc[] = _("{JPN}ジャラランガの\nスケイルノイズを Zわざに\nする。");

static const u8 sTapuniumZDesc[] = _("{JPN}カプたちの しぜんの\nいかりを Zわざに\lする。");

static const u8 sSolganiumZDesc[] = _("{JPN}ソルガレオの\nメテオドライブを Zわざに\nする。");

static const u8 sLunaliumZDesc[] = _("{JPN}ルナアーラの\nシャドーレイを Zわざに\nする。");

static const u8 sMarshadiumZDesc[] = _("{JPN}マーシャドーの\nシャドースチールを\nZわざに する。");

static const u8 sAloraichiumZDesc[] = _("{JPN}アローラライチュウの\n10まんボルトを Zわざに\nする。");

static const u8 sPikashuniumZDesc[] = _("{JPN}ぼうしの ピカチュウの\n10まんボルトを Zわざに\nする。");

static const u8 sUltranecroziumZDesc[] = _("{JPN}ネクロズマを あたらしい\nすがたに する\nけっしょう。");

// Species-specific Held Items
static const u8 sLightBallDesc[] = _("{JPN}ピカチュウの こうげきと\nとくこうを あげる\nもちもの。");

static const u8 sLeekDesc[] = _("{JPN}カモネギに もたせると\nわざが きゅうしょに\nあたりやすくなる。");

static const u8 sThickClubDesc[] = _("{JPN}カラカラ または\nガラガラに もたせると\nこうげきが あがる。");

static const u8 sLuckyPunchDesc[] = _("{JPN}ラッキーに もたせると\nわざが きゅうしょに\nあたりやすくなる。");

static const u8 sMetalPowderDesc[] = _("{JPN}メタモンに もたせると\nぼうぎょが あがる\nふしぎなこな。");

static const u8 sQuickPowderDesc[] = _("{JPN}メタモンに もたせると\nすばやさが あがる\lこな。");

static const u8 sDeepSeaScaleDesc[] = _("{JPN}パールルに もたせると\nとくぼうが あがる\nウロコ。");

static const u8 sDeepSeaToothDesc[] = _("{JPN}パールルに もたせると\nとくこうが あがる\lキバ。");

static const u8 sSoulDewDesc[] = _(
#if B_SOUL_DEW_BOOST >= GEN_7
    "Powers up Latios' &\n"
    "Latias' Psychic and\n"
    "Dragon-type moves.");
#else
    "Hold item: raises\n"
    "Sp. Atk & Sp. Def of\n"
    "Latios & Latias.");
#endif

static const u8 sAdamantOrbDesc[] = _("{JPN}ディアルガの ドラゴンと\nはがねの わざを\nつよくする。");

static const u8 sLustrousOrbDesc[] = _("{JPN}パルキアの ドラゴンと\nみずの わざを\nつよくする。");

static const u8 sGriseousOrbDesc[] = _("{JPN}ギラティナの ドラゴンと\nゴーストの わざを\nつよくする。");

// Incenses
static const u8 sSeaIncenseDesc[] = _("{JPN}もたせると みずタイプの\nわざの いりょくが\nあがる。");

static const u8 sLaxIncenseDesc[] = _("{JPN}あいての\nめいちゅうりつを すこし\lさげる もちもの。");

static const u8 sOddIncenseDesc[] = _("{JPN}もたせると\nエスパータイプの わざの\nいりょくが あがる。");

static const u8 sRockIncenseDesc[] = _("{JPN}もたせると いわタイプの\nわざの いりょくが\nあがる。");

static const u8 sFullIncenseDesc[] = _("{JPN}もつと すばやさが\nおそく なる\lもちもの。");

static const u8 sWaveIncenseDesc[] = _("{JPN}もたせると みずタイプの\nわざの いりょくが\nあがる。");

static const u8 sRoseIncenseDesc[] = _("{JPN}もたせると くさタイプの\nわざの いりょくが\nあがる。");

static const u8 sLuckIncenseDesc[] = _("{JPN}もつ ポケモンが\nたたかうと おかねが\n2ばいに なる。");

static const u8 sPureIncenseDesc[] = _("{JPN}やせいの ポケモンを\nよせつけにくく する\nもちもの。");

// Contest Scarves
static const u8 sRedScarfDesc[] = _("{JPN}コンテストの\nかっこよさが あがる\lもちもの。");

static const u8 sBlueScarfDesc[] = _("{JPN}コンテストの\nうつくしさが あがる\lもちもの。");

static const u8 sPinkScarfDesc[] = _("{JPN}コンテストの\nかわいさが あがる\lもちもの。");

static const u8 sGreenScarfDesc[] = _("{JPN}コンテストの\nかしこさが あがる\lもちもの。");

static const u8 sYellowScarfDesc[] = _("{JPN}コンテストの\nたくましさが あがる\lもちもの。");

// EV Gain Modifiers
static const u8 sMachoBraceDesc[] = _("{JPN}もたせると すばやさは\nさがるが ふつうより\nつよく そだちやすい。");

static const u8 sPowerWeightDesc[] = _("{JPN}HPが あがりやすく\nなるが すばやさが\nさがる。");

static const u8 sPowerBracerDesc[] = _("{JPN}こうげきが あがりやすく\nなるが すばやさが\nさがる。");

static const u8 sPowerBeltDesc[] = _("{JPN}ぼうぎょが あがりやすく\nなるが すばやさが\nさがる。");

static const u8 sPowerLensDesc[] = _("{JPN}とくこうが あがりやすく\nなるが すばやさが\nさがる。");

static const u8 sPowerBandDesc[] = _("{JPN}とくぼうが あがりやすく\nなるが すばやさが\nさがる。");

static const u8 sPowerAnkletDesc[] = _("{JPN}すばやさが あがりやすく\nなるが すばやさが\nさがる。");

// Type-boosting Held Items
static const u8 sSilkScarfDesc[] = _("{JPN}もたせると\nノーマルタイプの わざの\nいりょくが あがる。");

static const u8 sCharcoalDesc[] = _("{JPN}もたせると ほのおタイプの\nわざの いりょくが\nあがる。");

static const u8 sMysticWaterDesc[] = _("{JPN}もたせると みずタイプの\nわざの いりょくが\nあがる。");

static const u8 sMagnetDesc[] = _("{JPN}もたせると でんきタイプの\nわざの いりょくが\nあがる。");

static const u8 sMiracleSeedDesc[] = _("{JPN}もたせると くさタイプの\nわざの いりょくが\nあがる。");

static const u8 sNeverMeltIceDesc[] = _("{JPN}もたせると こおりタイプの\nわざの いりょくが\nあがる。");

static const u8 sBlackBeltDesc[] = _("{JPN}もたせると\nかくとうタイプの わざの\nいりょくが あがる。");

static const u8 sPoisonBarbDesc[] = _("{JPN}もたせると どくタイプの\nわざの いりょくが\nあがる。");

static const u8 sSoftSandDesc[] = _("{JPN}もたせると じめんタイプの\nわざの いりょくが\nあがる。");

static const u8 sSharpBeakDesc[] = _("{JPN}もたせると ひこうタイプの\nわざの いりょくが\nあがる。");

static const u8 sTwistedSpoonDesc[] = _("{JPN}もたせると\nエスパータイプの わざの\nいりょくが あがる。");

static const u8 sSilverPowderDesc[] = _("{JPN}もたせると むしタイプの\nわざの いりょくが\nあがる。");

static const u8 sHardStoneDesc[] = _("{JPN}もたせると いわタイプの\nわざの いりょくが\nあがる。");

static const u8 sSpellTagDesc[] = _("{JPN}もたせると\nゴーストタイプの わざの\nいりょくが あがる。");

static const u8 sDragonFangDesc[] = _("{JPN}もたせると\nドラゴンタイプの わざの\nいりょくが あがる。");

static const u8 sBlackGlassesDesc[] = _("{JPN}もたせると あくタイプの\nわざの いりょくが\nあがる。");

static const u8 sMetalCoatDesc[] = _("{JPN}もたせると はがねタイプの\nわざの いりょくが\nあがる。");

// Choice Items
static const u8 sChoiceBandDesc[] = _("{JPN}もたせると こうげきは\nあがるが おなじ わざしか\nだせなくなる。");

static const u8 sChoiceSpecsDesc[] = _("{JPN}とくこうが あがるが\nわざが 1つしか だせなく\nなる。");

static const u8 sChoiceScarfDesc[] = _("{JPN}すばやさが あがるが\nわざが 1つしか だせなく\nなる。");

// Status Orbs
static const u8 sFlameOrbDesc[] = _("{JPN}もつと しょうぶちゅうに\nやけどに なる ふしぎな\nたま。");

static const u8 sToxicOrbDesc[] = _("{JPN}もつと しょうぶちゅうに\nもうどくに なる ふしぎな\nたま。");

// Weather Rocks
static const u8 sDampRockDesc[] = _("{JPN}もつ ポケモンの\nあまごいが ながく\nつづく。");

static const u8 sHeatRockDesc[] = _("{JPN}もつ ポケモンの\nにほんばれが ながく\nつづく。");

static const u8 sSmoothRockDesc[] = _("{JPN}もつ ポケモンの\nすなあらしが ながく\nつづく。");

static const u8 sIcyRockDesc[] = _("{JPN}もつ ポケモンの\nあられが ながく\lつづく。");

// Terrain Seeds
static const u8 sElectricSeedDesc[] = _("{JPN}エレキフィールドで\n1かいだけ ぼうぎょが\nあがる。");

static const u8 sPsychicSeedDesc[] = _("{JPN}サイコフィールドで\n1かいだけ とくぼうが\nあがる。");

static const u8 sMistySeedDesc[] = _("{JPN}ミストフィールドで\n1かいだけ とくぼうが\nあがる。");

static const u8 sGrassySeedDesc[] = _("{JPN}グラスフィールドで\n1かいだけ ぼうぎょが\nあがる。");

// Type-activated Stat Modifiers
static const u8 sAbsorbBulbDesc[] = _("{JPN}みずの わざを\nうけると とくこうが\lあがる。");

static const u8 sCellBatteryDesc[] = _("{JPN}でんきの わざを\nうけると こうげきが\lあがる。");

static const u8 sLuminousMossDesc[] = _("{JPN}みずの わざを\nうけると とくぼうが\lあがる。");

static const u8 sSnowballDesc[] = _("{JPN}こおりの わざを\nうけると こうげきが\lあがる。");

// Misc. Held Items
static const u8 sBrightPowderDesc[] = _("{JPN}キラキラ ひかるこな。");

static const u8 sWhiteHerbDesc[] = _("{JPN}さがった のうりょくを\nもとに もどす\lもちもの。");

static const u8 sExpShareDesc[] = _(
#if I_EXP_SHARE_ITEM >= GEN_6
    "This device gives\n"
    "exp. to other\n"
    "party members.");
#else
    "A hold item that\n"
    "gets Exp. points\n"
    "from battles.");
#endif

static const u8 sQuickClawDesc[] = _("{JPN}もたせると あいてより\nさきに こうどう\nできることが ある。");

static const u8 sSootheBellDesc[] = _("{JPN}もたせた ポケモンは\nこころが やすらぎ\nなかよく なりやすくなる。");

#if B_MENTAL_HERB >= GEN_5
static const u8 sMentalHerbDesc[] = _("{JPN}わざの しばりから\nぬけだせる\lもちもの。");
#else
static const u8 sMentalHerbDesc[] = _("{JPN}メロメロから\nぬけだせる\lもちもの。");
#endif

static const u8 sKingsRockDesc[] = _("{JPN}こうげきが あたると\nあいてが ひるむ ことが\nある。");

static const u8 sAmuletCoinDesc[] = _("{JPN}もつ ポケモンが\nたたかうと おかねが\n2ばいに なる。");

static const u8 sCleanseTagDesc[] = _("{JPN}やせいの ポケモンを\nよせつけにくく する\nもちもの。");

static const u8 sSmokeBallDesc[] = _("{JPN}やせいの ポケモンから\nかならず にげられる\nもちもの。");

static const u8 sFocusBandDesc[] = _("{JPN}ときどき ひんしに\nならずに たえる\nもちもの。");

static const u8 sLuckyEggDesc[] = _("{JPN}もたせた ポケモンは\nもらえる けいけんちが\nすこし ふえる。");

static const u8 sScopeLensDesc[] = _("{JPN}もたせた ポケモンの\nわざが きゅうしょに\nあたりやすくなる。");

static const u8 sLeftoversDesc[] = _("{JPN}もたせると ポケモンの\nHPが せんとうの あいだ\nすこしずつ かいふくする。");

static const u8 sShellBellDesc[] = _("{JPN}こうげきが あたると\nHPが かいふく する\nもちもの。");

static const u8 sWideLensDesc[] = _("{JPN}わざの\nめいちゅうりつが\lあがる レンズ。");

static const u8 sMuscleBandDesc[] = _("{JPN}ぶつりの わざを\nつよくする\lハチマキ。");

static const u8 sWiseGlassesDesc[] = _("{JPN}とくしゅの わざを\nつよくする\lめがね。");

static const u8 sExpertBeltDesc[] = _("{JPN}こうかばつぐんの\nわざを つよくする\lベルト。");

static const u8 sLightClayDesc[] = _("{JPN}かべの わざの\nこうかが ながく\lつづく。");

static const u8 sLifeOrbDesc[] = _("{JPN}まいターン HPを\nへらして わざを\nつよくする。");

static const u8 sPowerHerbDesc[] = _("{JPN}ためる わざを\nすぐに だせるように\lなる。");

static const u8 sFocusSashDesc[] = _("{JPN}HPまんたんなら\nいちげきに HPを 1\nのこして たえる。");

static const u8 sZoomLensDesc[] = _("{JPN}あとから うごくと\nめいちゅうりつが\lあがる。");

static const u8 sMetronomeDesc[] = _("{JPN}おなじ わざを\nつづけて つかうと\lつよくなる。");

static const u8 sIronBallDesc[] = _("{JPN}すばやさが さがり\nひこうにも じめんが\nあたる。");

static const u8 sLaggingTailDesc[] = _("{JPN}もつと すばやさが\nおそく なる\lもちもの。");

static const u8 sDestinyKnotDesc[] = _("{JPN}じぶんが メロメロに\nなると あいても\nメロメロに なる。");

static const u8 sBlackSludgeDesc[] = _("{JPN}どくタイプは HPが\nかいふく。 ほかは\nダメージ。");

static const u8 sGripClawDesc[] = _("{JPN}しめつける わざが\n7ターン つづくように\nなる。");

static const u8 sStickyBarbDesc[] = _("{JPN}まいターン ダメージ。\nあいてに うつることも\nある。");

static const u8 sShedShellDesc[] = _("{JPN}かならず せんとうから\nいれかわれる\lもちもの。");

static const u8 sBigRootDesc[] = _("{JPN}HPを すいとる\nわざを つよくする\lもちもの。");

static const u8 sRazorClawDesc[] = _("{JPN}きゅうしょに\nあたりやすく なる\lかぎづめ。");

static const u8 sRazorFangDesc[] = _("{JPN}こうげきが あたると\nあいてが ひるむ ことが\nある。");

static const u8 sEvioliteDesc[] = _("{JPN}しんかできる ポケモンの\nぼうぎょと とくぼうを\nあげる。");

static const u8 sFloatStoneDesc[] = _("{JPN}とても かるく もつと\nおもさが はんぶんに\nなる。");

static const u8 sRockyHelmetDesc[] = _("{JPN}ふれた あいてを\nきずつける\lもちもの。");

static const u8 sAirBalloonDesc[] = _("{JPN}そらに うかぶ。\nこうげきを うけると\nわれる。");

static const u8 sRedCardDesc[] = _("{JPN}こうげきを うけると\nあいてを\lいれかわらせる。");

static const u8 sRingTargetDesc[] = _("{JPN}こうかの ない\nわざも あたるように\lなる。");

static const u8 sBindingBandDesc[] = _("{JPN}しめつける わざを\nつよくする\lもちもの。");

static const u8 sEjectButtonDesc[] = _("{JPN}こうげきを うけると\nじぶんが\lいれかわる。");

static const u8 sWeaknessPolicyDesc[] = _("{JPN}こうかばつぐんを うけると\nこうげきと とくこうが\nあがる。");

static const u8 sAssaultVestDesc[] = _("{JPN}とくぼうが あがるが\nへんかわざが つかえなく\nなる。");

static const u8 sSafetyGogglesDesc[] = _("{JPN}てんきの ダメージと\nこなの わざを\lふせぐ。");

static const u8 sAdrenalineOrbDesc[] = _("{JPN}いかくを うけると\n1かいだけ すばやさが\nあがる。");

static const u8 sTerrainExtenderDesc[] = _("{JPN}フィールドの\nこうかが ながく\lつづく。");

static const u8 sProtectivePadsDesc[] = _("{JPN}ふれる わざの\nついかこうかから\lまもる。");

static const u8 sThroatSprayDesc[] = _("{JPN}おとの わざを\nつかうと とくこうが\lあがる。");

static const u8 sEjectPackDesc[] = _("{JPN}のうりょくが\nさがると じぶんが\lいれかわる。");

static const u8 sHeavyDutyBootsDesc[] = _("{JPN}じめんに しかけた わなの\nこうかを うけない\nブーツ。");

static const u8 sBlunderPolicyDesc[] = _("{JPN}わざが はずれると\nすばやさが\lあがる。");

static const u8 sRoomServiceDesc[] = _("{JPN}トリックルームの\nあいだ すばやさが\lさがる。");

static const u8 sUtilityUmbrellaDesc[] = _("{JPN}てんきの\nこうかから まもる\lかさ。");

// Berries
static const u8 sCheriBerryDesc[] = _("{JPN}ポケモンに\nもたせると まひを\lかいふくする。");

static const u8 sChestoBerryDesc[] = _("{JPN}ポケモンに もたせると\nねむりを\lかいふくする。");

static const u8 sPechaBerryDesc[] = _("{JPN}ポケモンに\nもたせると どくを\lかいふくする。");

static const u8 sRawstBerryDesc[] = _("{JPN}ポケモンに もたせると\nやけどを\lかいふくする。");

static const u8 sAspearBerryDesc[] = _("{JPN}ポケモンに もたせると\nこおりを\lかいふくする。");

static const u8 sLeppaBerryDesc[] = _("{JPN}ポケモンに もたせると\nPPを 10だけ\nかいふくする。");

static const u8 sOranBerryDesc[] = _("{JPN}ポケモンに もたせると\nHPを 10だけ\nかいふくする。");

static const u8 sPersimBerryDesc[] = _("{JPN}ポケモンに もたせると\nこんらんを\lかいふくする。");

static const u8 sLumBerryDesc[] = _("{JPN}ポケモンに もたせると\nすべての じょうたい\nいじょうを かいふくする。");

static const u8 sSitrusBerryDesc[] = _(
#if I_SITRUS_BERRY_HEAL >= GEN_4
    "A hold item that\n"
    "restores the user's\n"
    "HP a little.");
#else
    "A hold item that\n"
    "restores 30 HP in\n"
    "battle.");
#endif

static const u8 sFigyBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき HPを\nかいふくする。");

static const u8 sWikiBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき HPを\nかいふくする。");

static const u8 sMagoBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき HPを\nかいふくする。");

static const u8 sAguavBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき HPを\nかいふくする。");

static const u8 sIapapaBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき HPを\nかいふくする。");

static const u8 sRazzBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nズリのみが そだつ。");

static const u8 sBlukBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nブリーのみが そだつ。");

static const u8 sNanabBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nナナのみが そだつ。");

static const u8 sWepearBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nセシナのみが そだつ。");

static const u8 sPinapBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nパイルのみが そだつ。");

static const u8 sPomegBerryDesc[] = _("{JPN}なつきやすく なるが\nきそポイントの HPが\nさがる。");

static const u8 sKelpsyBerryDesc[] = _("{JPN}なつきやすく なるが\nきそポイントの こうげきが\nさがる。");

static const u8 sQualotBerryDesc[] = _("{JPN}なつきやすく なるが\nきそポイントの ぼうぎょが\nさがる。");

static const u8 sHondewBerryDesc[] = _("{JPN}なつきやすく なるが\nきそポイントの とくこうが\nさがる。");

static const u8 sGrepaBerryDesc[] = _("{JPN}なつきやすく なるが\nきそポイントの とくぼうが\nさがる。");

static const u8 sTamatoBerryDesc[] = _("{JPN}なつきやすく なるが\nきそポイントの すばやさが\nさがる。");

static const u8 sCornnBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nコーンのみが そだつ。");

static const u8 sMagostBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nマゴスのみが そだつ。");

static const u8 sRabutaBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nラブタのみが そだつ。");

static const u8 sNomelBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nノメルのみが そだつ。");

static const u8 sSpelonBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nノワキのみが そだつ。");

static const u8 sPamtreBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nシーヤのみが そだつ。");

static const u8 sWatmelBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nカイスのみが そだつ。");

static const u8 sDurinBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nドリのみが そだつ。");

static const u8 sBelueBerryDesc[] = _("{JPN}{POKEBLOCK}の ざいりょう。\nつちに うえると\nベリブのみが そだつ。");

static const u8 sChilanBerryDesc[] = _("{JPN}ノーマルの わざを\nよわめる\lもちもの。");

static const u8 sOccaBerryDesc[] = _("{JPN}よわてんの ほのおの\nわざを よわめる\nもちもの。");

static const u8 sPasshoBerryDesc[] = _("{JPN}よわてんの みずの\nわざを よわめる\lもちもの。");

static const u8 sWacanBerryDesc[] = _("{JPN}よわてんの でんきの\nわざを よわめる\nもちもの。");

static const u8 sRindoBerryDesc[] = _("{JPN}よわてんの くさの\nわざを よわめる\lもちもの。");

static const u8 sYacheBerryDesc[] = _("{JPN}よわてんの こおりの\nわざを よわめる\nもちもの。");

static const u8 sChopleBerryDesc[] = _("{JPN}よわてんの かくとうの\nわざを よわめる\nもちもの。");

static const u8 sKebiaBerryDesc[] = _("{JPN}よわてんの どくの\nわざを よわめる\lもちもの。");

static const u8 sShucaBerryDesc[] = _("{JPN}よわてんの じめんの\nわざを よわめる\nもちもの。");

static const u8 sCobaBerryDesc[] = _("{JPN}よわてんの ひこうの\nわざを よわめる\nもちもの。");

static const u8 sPayapaBerryDesc[] = _("{JPN}よわてんの エスパーの\nわざを よわめる\nもちもの。");

static const u8 sTangaBerryDesc[] = _("{JPN}よわてんの むしの\nわざを よわめる\lもちもの。");

static const u8 sChartiBerryDesc[] = _("{JPN}よわてんの いわの\nわざを よわめる\lもちもの。");

static const u8 sKasibBerryDesc[] = _("{JPN}よわてんの ゴーストの\nわざを よわめる\nもちもの。");

static const u8 sHabanBerryDesc[] = _("{JPN}よわてんの ドラゴンの\nわざを よわめる\nもちもの。");

static const u8 sColburBerryDesc[] = _("{JPN}よわてんの あくの\nわざを よわめる\lもちもの。");

static const u8 sBabiriBerryDesc[] = _("{JPN}よわてんの はがねの\nわざを よわめる\nもちもの。");

static const u8 sRoseliBerryDesc[] = _("{JPN}よわてんの フェアリーの\nわざを よわめる\nもちもの。");

static const u8 sLiechiBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nこうげきが あがる。");

static const u8 sGanlonBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nぼうぎょが あがる。");

static const u8 sSalacBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nすばやさが あがる。");

static const u8 sPetayaBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nとくこうが あがる。");

static const u8 sApicotBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nとくぼうが あがる。");

static const u8 sLansatBerryDesc[] = _("{JPN}ピンチの ときに\nきゅうしょに あたりやすく\nなる。");

static const u8 sStarfBerryDesc[] = _("{JPN}ピンチの ときに\nのうりょくが ぐーんと\nあがる。");

static const u8 sEnigmaBerryDesc[] = _("{JPN}こうかばつぐんの わざを\nうけると かいふく\lする。");

static const u8 sMicleBerryDesc[] = _("{JPN}ピンチの ときに\nめいちゅうりつが\lあがる。");

static const u8 sCustapBerryDesc[] = _("{JPN}ピンチの ときに\n1かいだけ さきに\nうごける。");

static const u8 sJabocaBerryDesc[] = _("{JPN}ぶつりの わざを うけると\nあいてを すこし\nきずつける。");

static const u8 sRowapBerryDesc[] = _("{JPN}とくしゅの わざを\nうけると あいてを すこし\nきずつける。");

static const u8 sKeeBerryDesc[] = _("{JPN}ぶつりの わざを うけると\nぼうぎょが すこし\nあがる。");

static const u8 sMarangaBerryDesc[] = _("{JPN}とくしゅの わざを\nうけると とくぼうが\nすこし あがる。");

static const u8 sEnigmaBerryEReaderDesc[] = _("{JPN}{POKEBLOCK}の\nざいりょう。 なにが\nそだつか わからない。");

// TMs/HMs
static const u8 sTM01Desc[] = _("{JPN}ものすごい ちからを\nこめた キックで あいてを\nけとばして こうげきする。");

static const u8 sTM02Desc[] = _("{JPN}あいての からだに\nこばんを なげつけて\nこうげきする。");

static const u8 sTM03Desc[] = _("{JPN}ほのおを こめた\nパンチで あいてを\lこうげきする。");

static const u8 sTM04Desc[] = _("{JPN}れいきを こめた\nパンチで あいてを\lこうげきする。");

static const u8 sTM05Desc[] = _("{JPN}でんげきを こめた\nパンチで あいてを\nこうげきする。");

static const u8 sTM06Desc[] = _("{JPN}1ターンめで そらへ とび\n2ターンめに あいてを\nこうげきする。");

static const u8 sTM07Desc[] = _("{JPN}するどい ハリを あいてに\nはっしゃして\nこうげきする。");

static const u8 sTM08Desc[] = _("{JPN}つよい こうせんを\nあいてに はっしゃして\nこうげきする。");

static const u8 sTM09Desc[] = _("{JPN}もてる ちからを すべて\nつかって あいてに\nとつげきする。");

static const u8 sTM10Desc[] = _("{JPN}あいてを ついせきする\nふしぎな はっぱを\nまきちらす。");

static const u8 sTM11Desc[] = _("{JPN}5ターン\nほのおタイプの わざを\lつよくする。");

static const u8 sTM12Desc[] = _("{JPN}あいてを おこらせて\nこうげきわざしか だせなく\nする。");

static const u8 sTM13Desc[] = _("{JPN}つめたい こうせん。\nこおりに することが\nある。");

static const u8 sTM14Desc[] = _("{JPN}よわい でんげきを\nあびせる ことで あいてを\nまひ じょうたいに する。");

static const u8 sTM15Desc[] = _("{JPN}1ターンめに もぐり\n2ターンめで あいてを\nこうげきする。");

static const u8 sTM16Desc[] = _("{JPN}ひかりの かべで\nとくしゅの ダメージを\nよわめる。");

static const u8 sTM17Desc[] = _("{JPN}ダメージを ふせぐ。\nつづけると しっぱい\nしやすい。");

static const u8 sTM18Desc[] = _("{JPN}5ターン\nみずタイプの わざを\lつよくする。");

static const u8 sTM19Desc[] = _("{JPN}あたえた ダメージの\nはんぶん HPを かいふく\nする。");

static const u8 sTM20Desc[] = _("{JPN}ばくはつを おこして\nじぶんの まわりに\nいるものを こうげきする。");

static const u8 sTM21Desc[] = _("{JPN}じぶんの HPと\nじょうたいいじょうを\nすべて かいふく する。");

static const u8 sTM22Desc[] = _("{JPN}おおきな いわを\nはげしく ぶつけて\lこうげきする。");

static const u8 sTM23Desc[] = _("{JPN}じぶんが どうぐを\nもっている ばあいは\nぬすめない。");

static const u8 sTM24Desc[] = _("{JPN}じぶんが ねている ときに\nざつおんを だして\nこうげきする。");

static const u8 sTM25Desc[] = _("{JPN}あいての こうげきを\nまったく うけない。");

static const u8 sTM26Desc[] = _("{JPN}じしんを おこす。 そらに\nいる あいてには\nあたらない。");

static const u8 sTM27Desc[] = _("{JPN}つめたい れいきを\nあいてに ふきつけて\nこうげきする。");

static const u8 sTM28Desc[] = _("{JPN}あたえた ダメージの\nはんぶんの HPを\nかいふく できる。");

static const u8 sTM29Desc[] = _("{JPN}つよい ねんりき。\nとくぼうを さげることが\nある。");

static const u8 sTM30Desc[] = _("{JPN}かたい つばさを あいてに\nたたきつけて\nこうげきする。");

static const u8 sTM31Desc[] = _("{JPN}♂なら♀を ♀なら♂を\nゆうわくして メロメロに\nする。");

static const u8 sTM32Desc[] = _("{JPN}いわタイプの\nとくぼうが\lあがる。");

static const u8 sTM33Desc[] = _("{JPN}5ターンの あいだ あめを\nふらせて みずタイプの\nいりょくを あげる。");

static const u8 sTM34Desc[] = _("{JPN}みずタイプの\nいりょくは\lさがる。");

static const u8 sTM35Desc[] = _("{JPN}ほのおを はく。\nやけどに することが\lある。");

static const u8 sTM36Desc[] = _("{JPN}ヘドロを なげつける。\nどくに することが\lある。");

static const u8 sTM37Desc[] = _("{JPN}みかた\nぜんいんで\lこうげきする。");

static const u8 sTM38Desc[] = _("{JPN}つよい ほのお。\nやけどに することが\lある。");

static const u8 sTM39Desc[] = _("{JPN}いわで うごきを\nとめる。 すばやさを\lさげる。");

static const u8 sTM40Desc[] = _("{JPN}ほしがたの ひかりを\nはっしゃして あいてを\nこうげきする。");

static const u8 sTM41Desc[] = _("{JPN}なかまを たすける。");

static const u8 sTM42Desc[] = _("{JPN}どく やけど まひの\nとき こうげきが\lあがる。");

static const u8 sTM43Desc[] = _("{JPN}しゅとうを いきおいよく\nふりおろして あいてを\nこうげきする。");

static const u8 sTM44Desc[] = _("{JPN}2ターン ねむって HPと\nじょうたいを かいふく\nする。");

static const u8 sTM45Desc[] = _("{JPN}1ターンめで もぐり\n2ターンめに うきあがって\nこうげきする。");

static const u8 sTM46Desc[] = _("{JPN}つかった ときの てんきに\nよって わざの タイプと\nいりょくが かわる。");

static const u8 sTM47Desc[] = _("{JPN}こまらせる ことで\nあいての とくぼうを\nがくっと さげる。");

static const u8 sTM48Desc[] = _("{JPN}あいての うごきを\nふうじることで すばやさを\nさげる。");

static const u8 sTM49Desc[] = _("{JPN}あいてが だそうと\nしている わざを よこどり\nする。");

static const u8 sTM50Desc[] = _("{JPN}タネを いきおいよく\nあいてに はっしゃして\nこうげきする。");

static const u8 sTM51Desc[] = _( // Todo
    "?????");

static const u8 sTM52Desc[] = _( // Todo
    "?????");

static const u8 sTM53Desc[] = _( // Todo
    "?????");

static const u8 sTM54Desc[] = _( // Todo
    "?????");

static const u8 sTM55Desc[] = _( // Todo
    "?????");

static const u8 sTM56Desc[] = _( // Todo
    "?????");

static const u8 sTM57Desc[] = _( // Todo
    "?????");

static const u8 sTM58Desc[] = _( // Todo
    "?????");

static const u8 sTM59Desc[] = _( // Todo
    "?????");

static const u8 sTM60Desc[] = _( // Todo
    "?????");

static const u8 sTM61Desc[] = _( // Todo
    "?????");

static const u8 sTM62Desc[] = _( // Todo
    "?????");

static const u8 sTM63Desc[] = _( // Todo
    "?????");

static const u8 sTM64Desc[] = _( // Todo
    "?????");

static const u8 sTM65Desc[] = _( // Todo
    "?????");

static const u8 sTM66Desc[] = _( // Todo
    "?????");

static const u8 sTM67Desc[] = _( // Todo
    "?????");

static const u8 sTM68Desc[] = _( // Todo
    "?????");

static const u8 sTM69Desc[] = _( // Todo
    "?????");

static const u8 sTM70Desc[] = _( // Todo
    "?????");

static const u8 sTM71Desc[] = _( // Todo
    "?????");

static const u8 sTM72Desc[] = _( // Todo
    "?????");

static const u8 sTM73Desc[] = _( // Todo
    "?????");

static const u8 sTM74Desc[] = _( // Todo
    "?????");

static const u8 sTM75Desc[] = _( // Todo
    "?????");

static const u8 sTM76Desc[] = _( // Todo
    "?????");

static const u8 sTM77Desc[] = _( // Todo
    "?????");

static const u8 sTM78Desc[] = _( // Todo
    "?????");

static const u8 sTM79Desc[] = _( // Todo
    "?????");

static const u8 sTM80Desc[] = _( // Todo
    "?????");

static const u8 sTM81Desc[] = _( // Todo
    "?????");

static const u8 sTM82Desc[] = _( // Todo
    "?????");

static const u8 sTM83Desc[] = _( // Todo
    "?????");

static const u8 sTM84Desc[] = _( // Todo
    "?????");

static const u8 sTM85Desc[] = _( // Todo
    "?????");

static const u8 sTM86Desc[] = _( // Todo
    "?????");

static const u8 sTM87Desc[] = _( // Todo
    "?????");

static const u8 sTM88Desc[] = _( // Todo
    "?????");

static const u8 sTM89Desc[] = _( // Todo
    "?????");

static const u8 sTM90Desc[] = _( // Todo
    "?????");

static const u8 sTM91Desc[] = _( // Todo
    "?????");

static const u8 sTM92Desc[] = _( // Todo
    "?????");

static const u8 sTM93Desc[] = _( // Todo
    "?????");

static const u8 sTM94Desc[] = _( // Todo
    "?????");

static const u8 sTM95Desc[] = _( // Todo
    "?????");

static const u8 sTM96Desc[] = _( // Todo
    "?????");

static const u8 sTM97Desc[] = _( // Todo
    "?????");

static const u8 sTM98Desc[] = _( // Todo
    "?????");

static const u8 sTM99Desc[] = _( // Todo
    "?????");

static const u8 sTM100Desc[] = _( // Todo
    "?????");

static const u8 sHM01Desc[] = _("{JPN}ー\nー\lー。");

static const u8 sHM02Desc[] = _("{JPN}ー\nー\lー。");

static const u8 sHM03Desc[] = _("{JPN}ー\nー\lー。");

static const u8 sHM04Desc[] = _("{JPN}ー\nー\lー。");

static const u8 sHM05Desc[] = _("{JPN}ー\nー\lー。");

static const u8 sHM06Desc[] = _("{JPN}ー\nー\lー。");

static const u8 sHM07Desc[] = _("{JPN}1ターンめで もぐり\n2ターンめに うきあがって\nこうげきする。");

static const u8 sHM08Desc[] = _("{JPN}1ターンめに もぐり\n2ターンめに\nこうげきする。");

// Charms
static const u8 sOvalCharmDesc[] = _("{JPN}あずかりやで タマゴが\nみつかりやすく なる。");

static const u8 sShinyCharmDesc[] = _("{JPN}いろちがいの ポケモンが\nあらわれやすく なる\nおまもり。");

static const u8 sCatchingCharmDesc[] = _("{JPN}クリティカルほかくが\nおきやすく なる\nおまもり。");

static const u8 sExpCharmDesc[] = _("{JPN}しょうぶで もらえる\nけいけんちが ふえる\nおまもり。");

// Form-changing Key Items
static const u8 sRotomCatalogDesc[] = _("{JPN}ロトムの すきな\nきかいが のっている\lカタログ。");

static const u8 sGracideaDesc[] = _("{JPN}かんしゃの しるしとして\nおくる はなたばに\nつかう。");

static const u8 sRevealGlassDesc[] = _("{JPN}ポケモンを もとの\nすがたに もどす\lガラス。");

static const u8 sDNASplicersDesc[] = _("{JPN}キュレムと ある\nポケモンを あわせる\nどうぐ。");

static const u8 sZygardeCubeDesc[] = _("{JPN}ジガルデの コアと\nセルを しまう\lどうぐ。");

static const u8 sPrisonBottleDesc[] = _("{JPN}むかし ある\nポケモンを ふうじた\lビン。");

static const u8 sNSolarizerDesc[] = _("{JPN}ソルガレオで ネクロズマを\nあわせたり わけたり\nする。");

static const u8 sNLunarizerDesc[] = _("{JPN}ルナアーラで ネクロズマを\nあわせたり わけたり\nする。");

static const u8 sReinsOfUnityDesc[] = _("{JPN}バドレックスと\nあいぼうを むすぶ\lたづな。");

// Battle Mechanic Key Items
static const u8 sMegaRingDesc[] = _("{JPN}メガストーンを もつ\n{PKMN}が メガシンカ\nできる。");

static const u8 sZPowerRingDesc[] = _("{JPN}Zわざが\nつかえるように なる\lふしぎな リング。");

static const u8 sDynamaxBandDesc[] = _("{JPN}ダイマックスできる\nねがいぼしの ついた\nバンド。");

// Misc. Key Items
static const u8 sBicycleDesc[] = _("{JPN}ランニングシューズより\nはやい おりたたみ\nじてんしゃ。");

static const u8 sMachBikeDesc[] = _("{JPN}2ばい いじょうの\nはやさで いどう できる\nおりたたみの じてんしゃ。");

static const u8 sAcroBikeDesc[] = _("{JPN}ジャンプや ウィリーの\nアクションが できる\nおりたたみの じてんしゃ。");

static const u8 sOldRodDesc[] = _("{JPN}みずの ある ばしょで\nつかうと ポケモンが\nつれる。");

static const u8 sGoodRodDesc[] = _("{JPN}みずの ある ばしょで\nつかうと ポケモンが\nつれる。");

static const u8 sSuperRodDesc[] = _("{JPN}みずの ある ばしょで\nつかうと ポケモンが\nつれる。");

static const u8 sDowsingMachineDesc[] = _("{JPN}あたまに\nつけて\lつかう。");

static const u8 sTownMapDesc[] = _("{JPN}いつでも てがるに\nみることが できる\nべんりな ちず。");

static const u8 sVsSeekerDesc[] = _("{JPN}たたかいたい\nトレーナーを\lおしえてくれる きかい。");

static const u8 sTMCaseDesc[] = _("{JPN}ー\nー\lー。");

static const u8 sBerryPouchDesc[] = _("{JPN}きのみを しまって\nおける べんりな\lいれもの。");

static const u8 sPokemonBoxLinkDesc[] = _("{JPN}{PKMN}を あずける\nシステムを つかえる\nどうぐ。");

static const u8 sCoinCaseDesc[] = _("{JPN}コインを 9999まいまで\nしまえる ケース。");

static const u8 sPowderJarDesc[] = _("{JPN}きのみクラッシャーで\nつくった きのみパウダーを\nしまう。");

static const u8 sWailmerPailDesc[] = _("{JPN}みずを かける どうぐ。\nつちに うめた きのみを\nすくすく そだてる。");

static const u8 sPokeRadarDesc[] = _("{JPN}くさむらに かくれた\nポケモンを さがす\nどうぐ。");

static const u8 sPokeblockCaseDesc[] = _("{JPN}きのみブレンダーの\n{POKEBLOCK}を\nしまう ケース。");

static const u8 sSootSackDesc[] = _("{JPN}つもった かざんばいを\nあつめるための\lふくろ。");

static const u8 sPokeFluteDesc[] = _("{JPN}ポケモンの めを\nさます あまい\lねいろの ふえ。");

static const u8 sFameCheckerDesc[] = _("{JPN}ゆうめいな ひとの\nじょうほうを すぐに\nよびだせる。");

static const u8 sTeachyTVDesc[] = _("{JPN}トレーナーむけの\nばんぐみが うつる\nテレビ。");

// Story Key Items
static const u8 sSSTicketDesc[] = _("{JPN}こうそくせん アクアごうに\nのるとき ひつような\nふねの チケット。");

static const u8 sEonTicketDesc[] = _("{JPN}トウカジムの ジムリーダー\nセンリが ひみつを\nしっている!?。");

static const u8 sMysticTicketDesc[] = _("{JPN}ハジツゲの いわに いく\nふねに のる ための\nきっぷ。");

static const u8 sAuroraTicketDesc[] = _("{JPN}ミナモの しまに いく\nふねに のる ための\nきっぷ。");

static const u8 sOldSeaMapDesc[] = _("{JPN}ある しまへの みちを\nしめす あせた\lかいず。");

static const u8 sLetterDesc[] = _("{JPN}デボンしゃちょうから\nあずかった てがみ。");

static const u8 sDevonPartsDesc[] = _("{JPN}デボンの きかいの\nぶひんが はいった\nにもつ。");

static const u8 sGoGogglesDesc[] = _("{JPN}さばくの すなあらしから\nめを まもって くれる\nすてきな ゴーグル。");

static const u8 sDevonScopeDesc[] = _("{JPN}みえない ポケモンに\nはんのうして おとをだす\nデボンの とくせいひん。");

static const u8 sBasementKeyDesc[] = _("{JPN}コガネちかどうに ある\nとびらを あける\lカギ。");

static const u8 sScannerDesc[] = _("{JPN}シーキンセツの\nなかで みつけた\lどうぐ。");

static const u8 sStorageKeyDesc[] = _("{JPN}すてられ ぶねの そうこの\nかぎ。");

static const u8 sKeyToRoom1Desc[] = _("{JPN}すてられ ぶねの\nとびらを あける\lかぎ。");

static const u8 sKeyToRoom2Desc[] = _("{JPN}すてられ ぶねの\nとびらを あける\lかぎ。");

static const u8 sKeyToRoom4Desc[] = _("{JPN}すてられ ぶねの\nとびらを あける\lかぎ。");

static const u8 sKeyToRoom6Desc[] = _("{JPN}すてられ ぶねの\nとびらを あける\lかぎ。");

static const u8 sMeteoriteDesc[] = _("{JPN}りゅうせいのたきに\nおちていた いんせき。");

static const u8 sMagmaEmblemDesc[] = _("{JPN}マグマだんの マークと\nおなじ かたちの\lメダル。");

static const u8 sContestPassDesc[] = _("{JPN}きねんリボンが\nかかれている。");

static const u8 sParcelDesc[] = _("{JPN}ショップの てんいんから\nオーキドはかせへの\nにもつ。");

static const u8 sSecretKeyDesc[] = _("{JPN}グレンじまの\nジムの いりぐちの\lかぎ。");

static const u8 sBikeVoucherDesc[] = _("{JPN}じてんしゃやで\nじてんしゃを もらえる\nひきかえけん。");

static const u8 sGoldTeethDesc[] = _("{JPN}サファリゾーンの\nえんちょうが おとした\nきんいろの いれば。");

static const u8 sCardKeyDesc[] = _("{JPN}ラジオきょくの\nシャッターを あける\nカードしきの カギ。");

static const u8 sLiftKeyDesc[] = _("{JPN}ロケットだん アジトに\nある エレベータを\nうごかす カギ。");

static const u8 sSilphScopeDesc[] = _("{JPN}ひとの めに みえない\nものを みることが できる\nスコープ。");

static const u8 sTriPassDesc[] = _("{JPN}1ばん 2ばん\n3ばんじまを むすぶ\nふねの じょうしゃけん。");

static const u8 sRainbowPassDesc[] = _("{JPN}クチバと\nセブンアイランドを むすぶ\nふねに つかう。");

static const u8 sTeaDesc[] = _("{JPN}すこし にがくて\nこうばしい かおりの\nおちゃ。");

static const u8 sRubyDesc[] = _("{JPN}じょうねつを あらわす\nあかく かがやく\nほうせき。");

static const u8 sSapphireDesc[] = _("{JPN}せいじつさを あらわす\nあおく かがやく\nほうせき。");

static const u8 sAbilityShieldDesc[] = _("{JPN}もつ ポケモンの\nとくせいが かわらなく\nなる。");

static const u8 sClearAmuletDesc[] = _("{JPN}もつ ポケモンの\nのうりょくが さがらなく\nなる。");

static const u8 sPunchingGloveDesc[] = _("{JPN}パンチの わざを\nつよくし ふれない\lように する。");

static const u8 sCovertCloakDesc[] = _("{JPN}わざの ついかこうかから\nもつ ポケモンを\lまもる。");

static const u8 sLoadedDiceDesc[] = _("{JPN}おおきな めが でる。\nれんぞくわざの かいすうが\nふえる。");

static const u8 sAuspiciousArmorDesc[] = _("{JPN}えんぎの よい ねがいの\nこもった よろい。\nしんかする。");

static const u8 sBoosterEnergyDesc[] = _("{JPN}つめられた エネルギー。\nある とくせいを\nつよくする。");

static const u8 sBigBambooShootDesc[] = _("{JPN}おおきくて めずらしい\nたけのこ。 うると\nたかい。");

static const u8 sGimmighoulCoinDesc[] = _("{JPN}コレクレーが\nあつめる ふしぎな\lコイン。");

static const u8 sLeadersCrestDesc[] = _("{JPN}ふるい やいばの\nかけら。 キリキザンが\lもつ。");

static const u8 sMaliciousArmorDesc[] = _("{JPN}わるい ねんの\nこもった よろい。\lしんかする。");

static const u8 sMirrorHerbDesc[] = _("{JPN}あいての\nのうりょくアップを\n1かいだけ まねる。");

static const u8 sScrollOfDarknessDesc[] = _("{JPN}あくの みちの ひでんが\nかかれた ふしぎな\nまきもの。");

static const u8 sScrollOfWatersDesc[] = _("{JPN}みずの みちの ひでんが\nかかれた ふしぎな\nまきもの。");

static const u8 sTeraOrbDesc[] = _("{JPN}ためた エネルギーで\nテラスタル できるように\nなる。");

static const u8 sTinyBambooShootDesc[] = _("{JPN}ちいさくて めずらしい\nたけのこ。 うると\nたかい。");

static const u8 sTeraShardDesc[] = _("{JPN}{PKMN}の\nテラスタイプを かえる\nことが ある かけら。");

static const u8 sAdamantCrystalDesc[] = _("{JPN}ディアルガの すがたを\nかえる おおきな\nほうせき。");

static const u8 sGriseousCoreDesc[] = _("{JPN}ギラティナの すがたを\nかえる おおきな\nほうせき。");

static const u8 sLustrousGlobeDesc[] = _("{JPN}パルキアの すがたを\nかえる おおきな\nほうせき。");

static const u8 sBerserkGene[] = _("{JPN}こうげきが ぐーんと\nあがるが こんらん\nしつづける。");

static const u8 sFairyFeatherDesc[] = _("{JPN}フェアリータイプの\nわざを つよくする\lもちもの。");

static const u8 sSyrupyAppleDesc[] = _("{JPN}みつの おおい リンゴ。\nある ポケモンが しんか\nする。");

static const u8 sUnremarkableTeacupDesc[] = _("{JPN}われた ちゃわん。 ある\nポケモンが しんか\lする。");

static const u8 sMasterpieceTeacupDesc[] = _("{JPN}かけた ちゃわん。 ある\nポケモンが しんか\lする。");

static const u8 sCornerstoneMaskDesc[] = _("{JPN}オーガポンが\nいわタイプで たたかえる\lように なる。");

static const u8 sWellspringMaskDesc[] = _("{JPN}オーガポンが\nみずタイプで たたかえる\lように なる。");

static const u8 sHearthflameMaskDesc[] = _("{JPN}オーガポンが\nほのおタイプで たたかえる\nように なる。");

static const u8 sHealthMochiDesc[] = _("{JPN}ポケモンの きほんの\nHPを あげる\nどうぐ。");

static const u8 sMuscleMochiDesc[] = _("{JPN}ポケモンの きほんの\nこうげきを あげる\nどうぐ。");

static const u8 sResistMochiDesc[] = _("{JPN}ポケモンの きほんの\nぼうぎょを あげる\nどうぐ。");

static const u8 sGeniusMochiDesc[] = _("{JPN}ポケモンの きほんの\nとくこうを あげる\nどうぐ。");

static const u8 sCleverMochiDesc[] = _("{JPN}ポケモンの きほんの\nとくぼうを あげる\nどうぐ。");

static const u8 sSwiftMochiDesc[] = _("{JPN}ポケモンの きほんの\nすばやさを あげる\nどうぐ。");

static const u8 sFreshStartMochiDesc[] = _("{JPN}ポケモンの きそポイントを\nぜんぶ 0に する\nどうぐ。");

static const u8 sGlimmeringCharmDesc[] = _("{JPN}テラレイドで もらえる\nかけらが ふえる\nおまもり。");

static const u8 sMetalAlloyDesc[] = _("{JPN}ふしぎな きんぞく。\nある ポケモンが しんか\lする。");
