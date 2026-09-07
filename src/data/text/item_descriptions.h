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

static const u8 sBeastBallDesc[] = _("{JPN}ウルトラビーストを\nつかまえる ための\nボール。");

static const u8 sCherishBallDesc[] = _("{JPN}なにかの きねんに\nつくられた\nめずらしい ボール。");

// Medicine
static const u8 sPotionDesc[] = _("{JPN}ポケモン 1ひきの HPを\n20だけ かいふくする。");

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

static const u8 sMoomooMilkDesc[] = _("{JPN}ポケモン 1ひきの HPを\n100だけ かいふくする。");

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

static const u8 sAntidoteDesc[] = _("{JPN}ポケモン 1ひきの どくの\nじょうたいを\nかいふくする。");

static const u8 sParalyzeHealDesc[] = _("{JPN}ポケモン 1ひきの まひの\nじょうたいを\nかいふくする。");

static const u8 sBurnHealDesc[] = _("{JPN}ポケモン 1ひきの\nやけどの じょうたいを\nかいふくする。");

static const u8 sIceHealDesc[] = _("{JPN}ポケモン 1ひきの\nこおりの じょうたいを\nかいふくする。");

static const u8 sAwakeningDesc[] = _("{JPN}ポケモン 1ひきの\nねむりの じょうたいを\nかいふくする。");

static const u8 sFullHealDesc[] = _("{JPN}ポケモン 1ひきの\nじょうたいの いじょうを\nすべて かいふくする。");

static const u8 sEtherDesc[] = _("{JPN}ポケモンが おぼえている\nわざのうち 1つの PPを\n10だけ かいふくする。");

static const u8 sMaxEtherDesc[] = _("{JPN}ポケモンが おぼえている\nわざのうち 1つの PPを\nすべて かいふくする。");

static const u8 sElixirDesc[] = _("{JPN}ポケモンが おぼえている\n4つの わざの PPを\n10ずつ かいふくする。");

static const u8 sMaxElixirDesc[] = _("{JPN}ポケモンが おぼえている\n4つの わざの PPを\nすべて かいふくする。");

static const u8 sBerryJuiceDesc[] = _("{JPN}ポケモン 1ひきの HPを\n20だけ かいふくする。");

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
static const u8 sBlueFluteDesc[] = _("{JPN}ねむり じょうたいを\nかいふくする。");

static const u8 sYellowFluteDesc[] = _("{JPN}こんらん じょうたいを\nかいふくする。");

static const u8 sRedFluteDesc[] = _("{JPN}メロメロ じょうたいを\nかいふくする。");

// Encounter-modifying Flutes
static const u8 sBlackFluteDesc[] = _("{JPN}つかった ばしょで\nつよいポケモンと そうぐう\nしやすくなる。");

static const u8 sWhiteFluteDesc[] = _("{JPN}つかった ばしょで\nよわいポケモンと そうぐう\nしやすくなる。");

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

static const u8 sStardustDesc[] = _("{JPN}てざわりが サラサラの\nあかくて きれいな すな。");

static const u8 sStarPieceDesc[] = _("{JPN}キラキラと あかく ひかる\nきれいな ほうせきの\nかけら。");

static const u8 sCometShardDesc[] = _("{JPN}すいせいの かけら。\nたかく うれる。");

static const u8 sShoalSaltDesc[] = _("{JPN}あさせのほらあなで\nみつけた しお。");

static const u8 sShoalShellDesc[] = _("{JPN}あさせのほらあなで\nみつけた かいがら。");

static const u8 sRedShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sBlueShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sYellowShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sGreenShardDesc[] = _("{JPN}むかしの どうぐの\nかけら。やすく\nうれる。");

static const u8 sHeartScaleDesc[] = _("{JPN}きれいな ハートの\nかたちの とても\nめずらしい ウロコ。");

static const u8 sHoneyDesc[] = _("{JPN}つかうと やせいの\nポケモンを よびよせる\nあまい ミツ。");

static const u8 sRareBoneDesc[] = _("{JPN}とても めずらしい\nほね。たかく うれる。");

static const u8 sOddKeystoneDesc[] = _("{JPN}ときどき こえが\nきこえる ふしぎな\nいし。");

static const u8 sPrettyFeatherDesc[] = _("{JPN}うつくしいが なんの\nこうかも ない\nはね。");

static const u8 sRelicCopperDesc[] = _("{JPN}むかし つかわれた\nどうかへい。たかく\nうれる。");

static const u8 sRelicSilverDesc[] = _("{JPN}むかし つかわれた\nぎんかへい。たかく\nうれる。");

static const u8 sRelicGoldDesc[] = _("{JPN}むかし つかわれた\nきんかへい。たかく\nうれる。");

static const u8 sRelicVaseDesc[] = _("{JPN}むかし つくられた\nつぼ。たかく うれる。");

static const u8 sRelicBandDesc[] = _("{JPN}ふるい うでわ。\nたかく うれる。");

static const u8 sRelicStatueDesc[] = _("{JPN}ふるい ぞう。\nたかく うれる。");

static const u8 sRelicCrownDesc[] = _("{JPN}ふるい おうかん。\nたかく うれる。");

static const u8 sStrangeSouvenirDesc[] = _("{JPN}アローラの ポケモンを\nかたどった\nかざり。");

// Fossils
static const u8 sHelixFossilDesc[] = _("{JPN}おおむかし うみに\nすんでいた こだい\nポケモンの カセキ。");

static const u8 sDomeFossilDesc[] = _("{JPN}おおむかし うみに\nすんでいた こだい\nポケモンの カセキ。");

static const u8 sOldAmberDesc[] = _("{JPN}あかみを おびて\nすけている。");

static const u8 sRootFossilDesc[] = _("{JPN}むかし かいていに\nすんでいた ポケモンの\nカセキ。");

static const u8 sClawFossilDesc[] = _("{JPN}むかし かいていに\nすんでいた ポケモンの\nカセキ。");

static const u8 sArmorFossilDesc[] = _("{JPN}おおむかしの ポケモンの\nあたまの かけら。");

static const u8 sSkullFossilDesc[] = _("{JPN}おおむかしの ポケモンの\nあたまの かけら。");

static const u8 sCoverFossilDesc[] = _("{JPN}おおむかしの ポケモンの\nせなかの かけら。");

static const u8 sPlumeFossilDesc[] = _("{JPN}おおむかしの ポケモンの\nつばさの かけら。");

static const u8 sJawFossilDesc[] = _("{JPN}おおむかしの ポケモンの\nおおきな あごの\nかけら。");

static const u8 sSailFossilDesc[] = _("{JPN}おおむかしの ポケモンの\nせびれの かけら。");

static const u8 sFossilizedBirdDesc[] = _("{JPN}むかし そらを とんでいた\nポケモンの カセキ。");

static const u8 sFossilizedFishDesc[] = _("{JPN}むかし うみに すんでいた\nポケモンの カセキ。");

static const u8 sFossilizedDrakeDesc[] = _("{JPN}むかし りくに すんでいた\nポケモンの カセキ。");

static const u8 sFossilizedDinoDesc[] = _("{JPN}むかし うみに すんでいた\nポケモンの カセキ。");

// Mulch
static const u8 sGrowthMulchDesc[] = _("{JPN}きのみの せいちょうを\nはやめる ひりょう。");

static const u8 sDampMulchDesc[] = _("{JPN}きのみの せいちょうを\nおそくする ひりょう。");

static const u8 sStableMulchDesc[] = _("{JPN}きのみの きの\nじゅみょうを のばす\nひりょう。");

static const u8 sGooeyMulchDesc[] = _("{JPN}おちたあとに きのみが\nおおく はえなおる\nひりょう。");

static const u8 sRichMulchDesc[] = _("{JPN}とれる きのみの\nかずが ふえる\nひりょう。");

static const u8 sSurpriseMulchDesc[] = _("{JPN}きのみが へんいする\nかくりつが あがる\nひりょう。");

static const u8 sBoostMulchDesc[] = _("{JPN}やわらかい つちが\nかわく はやさを\nあげる ひりょう。");

static const u8 sAmazeMulchDesc[] = _("{JPN}ゆたかで おどろきが\nあって そだちも よい\nひりょう。");

// Apricorns
static const u8 sRedApricornDesc[] = _("{JPN}あかい ぼんぐり。\nつーんと はなにくる\nにおいがする。");

static const u8 sBlueApricornDesc[] = _("{JPN}あおい ぼんぐり。 すこし\nあおくさい かおりがする。");

static const u8 sYellowApricornDesc[] = _("{JPN}きいろの ぼんぐり。\nさわやかな かおりが\nする。");

static const u8 sGreenApricornDesc[] = _("{JPN}みどりの ぼんぐり。\nふしぎな かおりが\nする。");

static const u8 sPinkApricornDesc[] = _("{JPN}ももいろの ぼんぐり。\nあまそうな いい\nにおいがする。");

static const u8 sWhiteApricornDesc[] = _("{JPN}しろい ぼんぐり。 なんの\nにおいも しない。");

static const u8 sBlackApricornDesc[] = _("{JPN}くろい ぼんぐり。\nなんともいえない\nにおいがする。");

static const u8 sWishingPieceDesc[] = _("{JPN}{PKMN}の すあなに\nなげて ダイマックスの\nポケモンを よびよせる。");

static const u8 sGalaricaTwigDesc[] = _("{JPN}ガラルの ガラナツと\nいう きの えだ。");

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
static const u8 sFireStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sWaterStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sThunderStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sLeafStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sIceStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sSunStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sMoonStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sShinyStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sDuskStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sDawnStoneDesc[] = _("{JPN}とくていの ポケモンを\nしんかさせる。");

static const u8 sSweetAppleDesc[] = _("{JPN}とても あまい りんご。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sTartAppleDesc[] = _("{JPN}とても すっぱい りんご。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sCrackedPotDesc[] = _("{JPN}われた きゅうす。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sChippedPotDesc[] = _("{JPN}かけた きゅうす。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sGalaricaCuffDesc[] = _("{JPN}ガラルの うでわ。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sGalaricaWreathDesc[] = _("{JPN}ガラルの はなわ。\nとくていの ポケモンを\nしんかさせる。");

static const u8 sDragonScaleDesc[] = _("{JPN}ドラゴンタイプの\nポケモンが\nもっていることが ある。");

static const u8 sUpgradeDesc[] = _("{JPN}なかに いろんな\nじょうほうが つまった\nとうめいな きかい。");

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

static const u8 sBerrySweetDesc[] = _(
    "A berry-shaped\n"
    "sweet loved by\n"
    "Milcery.");

static const u8 sCloverSweetDesc[] = _(
    "A clover-shaped\n"
    "sweet loved by\n"
    "Milcery.");

static const u8 sFlowerSweetDesc[] = _(
    "A flower-shaped\n"
    "sweet loved by\n"
    "Milcery.");

static const u8 sStarSweetDesc[] = _(
    "A star-shaped\n"
    "sweet loved by\n"
    "Milcery.");

static const u8 sRibbonSweetDesc[] = _(
    "A ribbon-shaped\n"
    "sweet loved by\n"
    "Milcery.");

static const u8 sEverstoneDesc[] = _(
    "A wondrous hold\n"
    "item that prevents\n"
    "evolution.");

static const u8 sBlackAuguriteDesc[] = _(
    "A black stone that\n"
    "makes some Pokémon\n"
    "evolve.");;

static const u8 sLinkingCordDesc[] = _(
    "A mysterious string\n"
    "that makes some\n"
    "Pokémon evolve.");

static const u8 sPeatBlockDesc[] = _(
    "A block of material\n"
    "that makes some\n"
    "Pokémon evolve.");

// Nectars
static const u8 sRedNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

static const u8 sYellowNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

static const u8 sPinkNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

static const u8 sPurpleNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

// Plates
static const u8 sFlamePlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Fire-type moves.");

static const u8 sSplashPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Water-type moves.");

static const u8 sZapPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of Elec-\n"
    "tric-type moves.");

static const u8 sMeadowPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Grass-type moves.");

static const u8 sIciclePlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Ice-type moves.");

static const u8 sFistPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of Fight-\n"
    "ing-type moves.");

static const u8 sToxicPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Poison-type moves.");

static const u8 sEarthPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Ground-type moves.");

static const u8 sSkyPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Flying-type moves.");

static const u8 sMindPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of Psy\n"
    "chic-type moves.");

static const u8 sInsectPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Bug-type moves.");

static const u8 sStonePlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Rock-type moves.");

static const u8 sSpookyPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Ghost-type moves.");

static const u8 sDracoPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Dragon-type moves.");

static const u8 sDreadPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Dark-type moves.");

static const u8 sIronPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Steel-type moves.");

static const u8 sPixiePlateDesc[] = _(
    "A stone tablet that\n"
    "boosts the power of\n"
    "Fairy-type moves.");

// Drives
static const u8 sDouseDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Water-type.");

static const u8 sShockDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Electric-type.");

static const u8 sBurnDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Fire-type.");

static const u8 sChillDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Ice-type.");

// Memories
static const u8 sFireMemoryDesc[] = _(
    "A disc with Fire\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sWaterMemoryDesc[] = _(
    "A disc with Water\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sElectricMemoryDesc[] = _(
    "A disc with Electric\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sGrassMemoryDesc[] = _(
    "A disc with Grass\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sIceMemoryDesc[] = _(
    "A disc with Ice\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFightingMemoryDesc[] = _(
    "A disc with Fighting\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sPoisonMemoryDesc[] = _(
    "A disc with Poison\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sGroundMemoryDesc[] = _(
    "A disc with Ground\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFlyingMemoryDesc[] = _(
    "A disc with Flying\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sPsychicMemoryDesc[] = _(
    "A disc with Psychic\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sBugMemoryDesc[] = _(
    "A disc with Bug\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sRockMemoryDesc[] = _(
    "A disc with Rock\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sGhostMemoryDesc[] = _(
    "A disc with Ghost\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sDragonMemoryDesc[] = _(
    "A disc with Dragon\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sDarkMemoryDesc[] = _(
    "A disc with Dark\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sSteelMemoryDesc[] = _(
    "A disc with Steel\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFairyMemoryDesc[] = _(
    "A disc with Fairy\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sRustedSwordDesc[] = _(
    "A rusty sword. A\n"
    "hero used it to\n"
    "halt a disaster.");

static const u8 sRustedShieldDesc[] = _(
    "A rusty shield. A\n"
    "hero used it to\n"
    "halt a disaster.");

// Colored Orbs
static const u8 sRedOrbDesc[] = _(
    "A red, glowing orb\n"
    "said to contain an\n"
    "ancient power.");

static const u8 sBlueOrbDesc[] = _(
    "A blue, glowing orb\n"
    "said to contain an\n"
    "ancient power.");

// Mega Stones
static const u8 sVenusauriteDesc[] = _(
    "This stone enables\n"
    "Venusaur to Mega\n"
    "Evolve in battle.");

static const u8 sCharizarditeDesc[] = _(
    "This stone enables\n"
    "Charizard to Mega\n"
    "Evolve in battle.");

static const u8 sBlastoisiniteDesc[] = _(
    "This stone enables\n"
    "Blastoise to Mega\n"
    "Evolve in battle.");

static const u8 sBeedrilliteDesc[] = _(
    "This stone enables\n"
    "Beedrill to Mega\n"
    "Evolve in battle.");

static const u8 sPidgeotiteDesc[] = _(
    "This stone enables\n"
    "Pidgeot to Mega\n"
    "Evolve in battle.");

static const u8 sAlakaziteDesc[] = _(
    "This stone enables\n"
    "Alakazam to Mega\n"
    "Evolve in battle.");

static const u8 sSlowbroniteDesc[] = _(
    "This stone enables\n"
    "Slowbro to Mega\n"
    "Evolve in battle.");

static const u8 sGengariteDesc[] = _(
    "This stone enables\n"
    "Gengar to Mega\n"
    "Evolve in battle.");

static const u8 sKangaskhaniteDesc[] = _(
    "This stone enables\n"
    "Kangaskhan to Mega\n"
    "Evolve in battle.");

static const u8 sPinsiriteDesc[] = _(
    "This stone enables\n"
    "Pinsir to Mega\n"
    "Evolve in battle.");

static const u8 sGyaradositeDesc[] = _(
    "This stone enables\n"
    "Gyarados to Mega\n"
    "Evolve in battle.");

static const u8 sAerodactyliteDesc[] = _(
    "This stone enables\n"
    "Aerodactyl to Mega\n"
    "Evolve in battle.");

static const u8 sMewtwoniteDesc[] = _(
    "This stone enables\n"
    "Mewtwo to Mega\n"
    "Evolve in battle.");

static const u8 sRaichuniteDesc[] = _(
    "This stone enables\n"
    "Raichu to Mega\n"
    "Evolve in battle.");

static const u8 sAmpharositeDesc[] = _(
    "This stone enables\n"
    "Ampharos to Mega\n"
    "Evolve in battle.");

static const u8 sSteelixiteDesc[] = _(
    "This stone enables\n"
    "Steelix to Mega\n"
    "Evolve in battle.");

static const u8 sScizoriteDesc[] = _(
    "This stone enables\n"
    "Scizor to Mega\n"
    "Evolve in battle.");

static const u8 sHeracroniteDesc[] = _(
    "This stone enables\n"
    "Heracross to Mega\n"
    "Evolve in battle.");

static const u8 sHoundoominiteDesc[] = _(
    "This stone enables\n"
    "Houndoom to Mega\n"
    "Evolve in battle.");

static const u8 sTyranitariteDesc[] = _(
    "This stone enables\n"
    "Tyranitar to Mega\n"
    "Evolve in battle.");

static const u8 sSceptiliteDesc[] = _(
    "This stone enables\n"
    "Sceptile to Mega\n"
    "Evolve in battle.");

static const u8 sBlazikeniteDesc[] = _(
    "This stone enables\n"
    "Blaziken to Mega\n"
    "Evolve in battle.");

static const u8 sSwampertiteDesc[] = _(
    "This stone enables\n"
    "Swampert to Mega\n"
    "Evolve in battle.");

static const u8 sGardevoiriteDesc[] = _(
    "This stone enables\n"
    "Gardevoir to Mega\n"
    "Evolve in battle.");

static const u8 sSableniteDesc[] = _(
    "This stone enables\n"
    "Sableye to Mega\n"
    "Evolve in battle.");

static const u8 sMawiliteDesc[] = _(
    "This stone enables\n"
    "Mawile to Mega\n"
    "Evolve in battle.");

static const u8 sAggroniteDesc[] = _(
    "This stone enables\n"
    "Aggron to Mega\n"
    "Evolve in battle.");

static const u8 sMedichamiteDesc[] = _(
    "This stone enables\n"
    "Medicham to Mega\n"
    "Evolve in battle.");

static const u8 sManectiteDesc[] = _(
    "This stone enables\n"
    "Manectric to Mega\n"
    "Evolve in battle.");

static const u8 sSharpedoniteDesc[] = _(
    "This stone enables\n"
    "Sharpedo to Mega\n"
    "Evolve in battle.");

static const u8 sCameruptiteDesc[] = _(
    "This stone enables\n"
    "Camerupt to Mega\n"
    "Evolve in battle.");

static const u8 sAltarianiteDesc[] = _(
    "This stone enables\n"
    "Altaria to Mega\n"
    "Evolve in battle.");

static const u8 sBanettiteDesc[] = _(
    "This stone enables\n"
    "Banette to Mega\n"
    "Evolve in battle.");

static const u8 sAbsoliteDesc[] = _(
    "This stone enables\n"
    "Absol to Mega\n"
    "Evolve in battle.");

static const u8 sGlalititeDesc[] = _(
    "This stone enables\n"
    "Glalie to Mega\n"
    "Evolve in battle.");

static const u8 sSalamenciteDesc[] = _(
    "This stone enables\n"
    "Salamence to Mega\n"
    "Evolve in battle.");

static const u8 sMetagrossiteDesc[] = _(
    "This stone enables\n"
    "Metagross to Mega\n"
    "Evolve in battle.");

static const u8 sLatiasiteDesc[] = _(
    "This stone enables\n"
    "Latias to Mega\n"
    "Evolve in battle.");

static const u8 sLatiositeDesc[] = _(
    "This stone enables\n"
    "Latios to Mega\n"
    "Evolve in battle.");

static const u8 sLopunniteDesc[] = _(
    "This stone enables\n"
    "Lopunny to Mega\n"
    "Evolve in battle.");

static const u8 sGarchompiteDesc[] = _(
    "This stone enables\n"
    "Garchomp to Mega\n"
    "Evolve in battle.");

static const u8 sLucarioniteDesc[] = _(
    "This stone enables\n"
    "Lucario to Mega\n"
    "Evolve in battle.");

static const u8 sAbomasiteDesc[] = _(
    "This stone enables\n"
    "Abomasnow to Mega\n"
    "Evolve in battle.");

static const u8 sGalladiteDesc[] = _(
    "This stone enables\n"
    "Gallade to Mega\n"
    "Evolve in battle.");

static const u8 sAudiniteDesc[] = _(
    "This stone enables\n"
    "Audino to Mega\n"
    "Evolve in battle.");

static const u8 sDianciteDesc[] = _(
    "This stone enables\n"
    "Diancie to Mega\n"
    "Evolve in battle.");

// Gems
static const u8 sNormalGemDesc[] = _(
    "Increases the\n"
    "power of Normal\n"
    "Type moves.");

static const u8 sFireGemDesc[] = _(
    "Increases the\n"
    "power of Fire\n"
    "Type moves.");

static const u8 sWaterGemDesc[] = _(
    "Increases the\n"
    "power of Water\n"
    "Type moves.");

static const u8 sElectricGemDesc[] = _(
    "Increases the\n"
    "power of Electric\n"
    "Type moves.");

static const u8 sGrassGemDesc[] = _(
    "Increases the\n"
    "power of Grass\n"
    "Type moves.");

static const u8 sIceGemDesc[] = _(
    "Increases the\n"
    "power of Ice\n"
    "Type moves.");

static const u8 sFightingGemDesc[] = _(
    "Increases the\n"
    "power of Fighting\n"
    "Type moves.");

static const u8 sPoisonGemDesc[] = _(
    "Increases the\n"
    "power of Poison\n"
    "Type moves.");

static const u8 sGroundGemDesc[] = _(
    "Increases the\n"
    "power of Ground\n"
    "Type moves.");

static const u8 sFlyingGemDesc[] = _(
    "Increases the\n"
    "power of Flying\n"
    "Type moves.");

static const u8 sPsychicGemDesc[] = _(
    "Increases the\n"
    "power of Psychic\n"
    "Type moves.");

static const u8 sBugGemDesc[] = _(
    "Increases the\n"
    "power of Bug\n"
    "Type moves.");

static const u8 sRockGemDesc[] = _(
    "Increases the\n"
    "power of Rock\n"
    "Type moves.");

static const u8 sGhostGemDesc[] = _(
    "Increases the\n"
    "power of Ghost\n"
    "Type moves.");

static const u8 sDragonGemDesc[] = _(
    "Increases the\n"
    "power of Dragon\n"
    "Type moves.");

static const u8 sDarkGemDesc[] = _(
    "Increases the\n"
    "power of Dark\n"
    "Type moves.");

static const u8 sSteelGemDesc[] = _(
    "Increases the\n"
    "power of Steel\n"
    "Type moves.");

static const u8 sFairyGemDesc[] = _(
    "Increases the\n"
    "power of Fairy\n"
    "Type moves.");

// Z-Crystals
static const u8 sNormaliumZDesc[] = _(
    "Upgrade Normal-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sFiriumZDesc[] = _(
    "Upgrade Fire-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sWateriumZDesc[] = _(
    "Upgrade Water-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sElectriumZDesc[] = _(
    "Upgrade Electric-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sGrassiumZDesc[] = _(
    "Upgrade Grass-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sIciumZDesc[] = _(
    "Upgrade Ice-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sFightiniumZDesc[] = _(
    "Upgrade Fighting-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sPoisoniumZDesc[] = _(
    "Upgrade Poison-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sGroundiumZDesc[] = _(
    "Upgrade Ground-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sFlyiniumZDesc[] = _(
    "Upgrade Flying-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sPsychiumZDesc[] = _(
    "Upgrade Psychic-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sBuginiumZDesc[] = _(
    "Upgrade Bug-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sRockiumZDesc[] = _(
    "Upgrade Rock-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sGhostiumZDesc[] = _(
    "Upgrade Ghost-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sDragoniumZDesc[] = _(
    "Upgrade Dragon-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sDarkiniumZDesc[] = _(
    "Upgrade Dark-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sSteeliumZDesc[] = _(
    "Upgrade Steel-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sFairiumZDesc[] = _(
    "Upgrade Fairy-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sPikaniumZDesc[] = _(
    "Upgrade Pikachu's\n"
    "Volt Tackle\n"
    "into a Z-Move.");

static const u8 sEeviumZDesc[] = _(
    "Upgrade Eevee's\n"
    "Last Resort\n"
    "into a Z-Move.");

static const u8 sSnorliumZDesc[] = _(
    "Upgrade Snorlax's\n"
    "Giga Impact\n"
    "into a Z-Move.");

static const u8 sMewniumZDesc[] = _(
    "Upgrade Mew's\n"
    "Psychic into\n"
    "a Z-Move.");

static const u8 sDecidiumZDesc[] = _(
    "Upgrade Decidu-\n"
    "eye's Spirit Sha-\n"
    "ckle into a Z-Move.");

static const u8 sInciniumZDesc[] = _(
    "Upgrade Incine-\n"
    "roar's Darkest La-\n"
    "riat into a Z-Move.");

static const u8 sPrimariumZDesc[] = _(
    "Upgrade Primarina's\n"
    "Sparkling Aria\n"
    "into a Z-Move.");

static const u8 sLycaniumZDesc[] = _(
    "Upgrade Lycanroc's\n"
    "Stone Edge\n"
    "into a Z-Move.");

static const u8 sMimikiumZDesc[] = _(
    "Upgrade Mimikyu's\n"
    "Play Rough\n"
    "into a Z-Move.");

static const u8 sKommoniumZDesc[] = _(
    "Upgrade Kommo-o's\n"
    "Clanging Scales\n"
    "into a Z-Move.");

static const u8 sTapuniumZDesc[] = _(
    "Upgrade the tapu's\n"
    "Nature's Madness\n"
    "into a Z-Move.");

static const u8 sSolganiumZDesc[] = _(
    "Upgrade Solgaleo's\n"
    "Sunsteel Strike\n"
    "into a Z-Move.");

static const u8 sLunaliumZDesc[] = _(
    "Upgrade Lunala's\n"
    "Moongeist Beam\n"
    "into a Z-Move.");

static const u8 sMarshadiumZDesc[] = _(
    "Upgrade Marsha-\n"
    "dow's Spectral Thi-\n"
    "ef into a Z-Move.");

static const u8 sAloraichiumZDesc[] = _(
    "Upgrade Alolan\n"
    "Raichu's Thunder-\n"
    "bolt into a Z-Move.");

static const u8 sPikashuniumZDesc[] = _(
    "Upgrade Pikachu w/\n"
    "a cap's Thunderbolt\n"
    "into a Z-Move.");

static const u8 sUltranecroziumZDesc[] = _(
    "A crystal to turn\n"
    "fused Necrozma\n"
    "into a new form.");

// Species-specific Held Items
static const u8 sLightBallDesc[] = _(
    "A hold item that\n"
    "raises the Atk and\n"
    "Sp. Atk of Pikachu.");

static const u8 sLeekDesc[] = _("{JPN}カモネギに もたせると\nわざが きゅうしょに\nあたりやすくなる。");

static const u8 sThickClubDesc[] = _("{JPN}カラカラ または\nガラガラに もたせると\nこうげきが あがる。");

static const u8 sLuckyPunchDesc[] = _("{JPN}ラッキーに もたせると\nわざが きゅうしょに\nあたりやすくなる。");

static const u8 sMetalPowderDesc[] = _("{JPN}メタモンに もたせると\nぼうぎょが あがる\nふしぎなこな。");

static const u8 sQuickPowderDesc[] = _(
    "An item to be held\n"
    "by Ditto. This odd\n"
    "powder boosts Speed.");

static const u8 sDeepSeaScaleDesc[] = _("{JPN}パールルに もたせると\nとくぼうが あがる\nウロコ。");

static const u8 sDeepSeaToothDesc[] = _("{JPN}パールルに もたせると\nとくこうが あがる キバ。");

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

static const u8 sAdamantOrbDesc[] = _(
    "Boosts the power of\n"
    "Dialga's Dragon and\n"
    "Steel-type moves.");

static const u8 sLustrousOrbDesc[] = _(
    "Boosts the power of\n"
    "Palkia's Dragon and\n"
    "Water-type moves.");

static const u8 sGriseousOrbDesc[] = _(
    "Powers up Giratina's\n"
    "Dragon and Ghost-\n"
    "type moves.");

// Incenses
static const u8 sSeaIncenseDesc[] = _("{JPN}もたせると みずタイプの\nわざの いりょくが\nあがる。");

static const u8 sLaxIncenseDesc[] = _(
    "A hold item that\n"
    "slightly lowers the\n"
    "foe's accuracy.");

static const u8 sOddIncenseDesc[] = _("{JPN}もたせると\nエスパータイプの わざの\nいりょくが あがる。");

static const u8 sRockIncenseDesc[] = _("{JPN}もたせると いわタイプの\nわざの いりょくが\nあがる。");

static const u8 sFullIncenseDesc[] = _(
    "A held item that\n"
    "makes the holder\n"
    "move slower.");

static const u8 sWaveIncenseDesc[] = _("{JPN}もたせると みずタイプの\nわざの いりょくが\nあがる。");

static const u8 sRoseIncenseDesc[] = _("{JPN}もたせると くさタイプの\nわざの いりょくが\nあがる。");

static const u8 sLuckIncenseDesc[] = _(
    "Doubles money in\n"
    "battle if the\n"
    "holder takes part.");

static const u8 sPureIncenseDesc[] = _(
    "A hold item that\n"
    "helps repel wild\n"
    "Pokémon.");

// Contest Scarves
static const u8 sRedScarfDesc[] = _(
    "A hold item that\n"
    "raises Cool in\n"
    "Contests.");

static const u8 sBlueScarfDesc[] = _(
    "A hold item that\n"
    "raises Beauty in\n"
    "Contests.");

static const u8 sPinkScarfDesc[] = _(
    "A hold item that\n"
    "raises Cute in\n"
    "Contests.");

static const u8 sGreenScarfDesc[] = _(
    "A hold item that\n"
    "raises Smart in\n"
    "Contests.");

static const u8 sYellowScarfDesc[] = _(
    "A hold item that\n"
    "raises Tough in\n"
    "Contests.");

// EV Gain Modifiers
static const u8 sMachoBraceDesc[] = _("{JPN}もたせると すばやさは\nさがるが ふつうより\nつよく そだちやすい。");

static const u8 sPowerWeightDesc[] = _(
    "A hold item that\n"
    "promotes HP gain,\n"
    "but reduces Speed.");

static const u8 sPowerBracerDesc[] = _(
    "A hold item that\n"
    "promotes Atk gain,\n"
    "but reduces Speed.");

static const u8 sPowerBeltDesc[] = _(
    "A hold item that\n"
    "promotes Def gain,\n"
    "but reduces Speed.");

static const u8 sPowerLensDesc[] = _(
    "Hold item that pro-\n"
    "motes Sp. Atk gain,\n"
    "but reduces Speed.");

static const u8 sPowerBandDesc[] = _(
    "Hold item that pro-\n"
    "motes Sp. Def gain,\n"
    "but reduces Speed.");

static const u8 sPowerAnkletDesc[] = _(
    "A hold item that\n"
    "promotes Spd gain,\n"
    "but reduces Speed.");

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

static const u8 sChoiceSpecsDesc[] = _(
    "Boosts Sp. Atk, but\n"
    "allows the use of\n"
    "only one move.");

static const u8 sChoiceScarfDesc[] = _(
    "Boosts Speed, but\n"
    "allows the use of\n"
    "only one move.");

// Status Orbs
static const u8 sFlameOrbDesc[] = _(
    "A bizarre orb that\n"
    "inflicts a burn on\n"
    "holder in battle.");

static const u8 sToxicOrbDesc[] = _(
    "A bizarre orb that\n"
    "badly poisons the\n"
    "holder in battle.");

// Weather Rocks
static const u8 sDampRockDesc[] = _(
    "Extends the length\n"
    "of Rain Dance if\n"
    "used by the holder.");

static const u8 sHeatRockDesc[] = _(
    "Extends the length\n"
    "of Sunny Day if\n"
    "used by the holder.");

static const u8 sSmoothRockDesc[] = _(
    "Extends the length\n"
    "of Sandstorm if\n"
    "used by the holder.");

static const u8 sIcyRockDesc[] = _(
    "Extends the length\n"
    "of the move Hail\n"
    "used by the holder.");

// Terrain Seeds
static const u8 sElectricSeedDesc[] = _(
    "Boosts Defense on\n"
    "Electric Terrain,\n"
    "but only one time.");

static const u8 sPsychicSeedDesc[] = _(
    "Boosts Sp. Def. on\n"
    "Psychic Terrain,\n"
    "but only one time.");

static const u8 sMistySeedDesc[] = _(
    "Boosts Sp. Def. on\n"
    "Misty Terrain,\n"
    "but only one time.");

static const u8 sGrassySeedDesc[] = _(
    "Boosts Defense on\n"
    "Grassy Terrain,\n"
    "but only one time.");

// Type-activated Stat Modifiers
static const u8 sAbsorbBulbDesc[] = _(
    "Raises Sp. Atk if\n"
    "the holder is hit by\n"
    "a Water-type move.");

static const u8 sCellBatteryDesc[] = _(
    "Raises Atk if the\n"
    "holder is hit by an\n"
    "Electric-type move.");

static const u8 sLuminousMossDesc[] = _(
    "Raises Sp. Def if\n"
    "the holder is hit by\n"
    "a Water-type move.");

static const u8 sSnowballDesc[] = _(
    "Raises Atk if its\n"
    "holder is hit by an\n"
    "Ice-type move.");

// Misc. Held Items
static const u8 sBrightPowderDesc[] = _("{JPN}キラキラ ひかるこな。");

static const u8 sWhiteHerbDesc[] = _(
    "A hold item that\n"
    "restores any\n"
    "lowered stat.");

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
static const u8 sMentalHerbDesc[] = _(
    "Snaps Pokémon out\n"
    "of move-binding\n"
    "effects.");
#else
static const u8 sMentalHerbDesc[] = _(
    "A hold item that\n"
    "snaps Pokémon out\n"
    "of infatuation.");
#endif

static const u8 sKingsRockDesc[] = _(
    "A hold item that\n"
    "may cause flinching\n"
    "when the foe is hit.");

static const u8 sAmuletCoinDesc[] = _(
    "Doubles money in\n"
    "battle if the\n"
    "holder takes part.");

static const u8 sCleanseTagDesc[] = _(
    "A hold item that\n"
    "helps repel wild\n"
    "Pokémon.");

static const u8 sSmokeBallDesc[] = _(
    "A hold item that\n"
    "assures fleeing\n"
    "from wild Pokémon.");

static const u8 sFocusBandDesc[] = _(
    "A hold item that\n"
    "occasionally\n"
    "prevents fainting.");

static const u8 sLuckyEggDesc[] = _("{JPN}もたせた ポケモンは\nもらえる けいけんちが\nすこし ふえる。");

static const u8 sScopeLensDesc[] = _("{JPN}もたせた ポケモンの\nわざが きゅうしょに\nあたりやすくなる。");

static const u8 sLeftoversDesc[] = _("{JPN}もたせると ポケモンの\nHPが せんとうの あいだ\nすこしずつ かいふくする。");

static const u8 sShellBellDesc[] = _(
    "A hold item that\n"
    "restores HP upon\n"
    "striking the foe.");

static const u8 sWideLensDesc[] = _(
    "A magnifying lens\n"
    "that boosts the\n"
    "accuracy of moves.");

static const u8 sMuscleBandDesc[] = _(
    "A headband that\n"
    "boosts the power of\n"
    "physical moves.");

static const u8 sWiseGlassesDesc[] = _(
    "A pair of glasses\n"
    "that ups the power\n"
    "of special moves.");

static const u8 sExpertBeltDesc[] = _(
    "A belt that boosts\n"
    "the power of super\n"
    "effective moves.");

static const u8 sLightClayDesc[] = _(
    "Extends the length\n"
    "of barrier moves\n"
    "used by the holder.");

static const u8 sLifeOrbDesc[] = _(
    "Boosts the power of\n"
    "moves at the cost\n"
    "of some HP per turn.");

static const u8 sPowerHerbDesc[] = _(
    "Allows immediate\n"
    "use of a move that\n"
    "charges first.");

static const u8 sFocusSashDesc[] = _(
    "If the holder has\n"
    "full HP, it endures\n"
    "KO hits with 1 HP.");

static const u8 sZoomLensDesc[] = _(
    "If the holder moves\n"
    "after the foe, it'll\n"
    "boost accuracy.");

static const u8 sMetronomeDesc[] = _(
    "A held item that\n"
    "boosts a move used\n"
    "consecutively.");

static const u8 sIronBallDesc[] = _(
    "Cuts Speed and lets\n"
    "Flying-types be hit\n"
    "by Ground moves.");

static const u8 sLaggingTailDesc[] = _(
    "A held item that\n"
    "makes the holder\n"
    "move slower.");

static const u8 sDestinyKnotDesc[] = _(
    "If the holder falls\n"
    "in love, the foe\n"
    "does too.");

static const u8 sBlackSludgeDesc[] = _(
    "Gradually restores\n"
    "HP of Poison-types.\n"
    "Damages others.");

static const u8 sGripClawDesc[] = _(
    "Makes binding moves\n"
    "used by the holder\n"
    "go on for 7 turns.");

static const u8 sStickyBarbDesc[] = _(
    "Damages the holder\n"
    "each turn. May latch\n"
    "on to foes.");

static const u8 sShedShellDesc[] = _(
    "Enables the holder\n"
    "to switch out of\n"
    "battle without fail.");

static const u8 sBigRootDesc[] = _(
    "A held item that\n"
    "boosts the power of\n"
    "HP-stealing moves.");

static const u8 sRazorClawDesc[] = _(
    "A hooked claw that\n"
    "ups the holder's\n"
    "critical-hit ratio.");

static const u8 sRazorFangDesc[] = _(
    "A hold item that\n"
    "may cause flinching\n"
    "when the foe is hit.");

static const u8 sEvioliteDesc[] = _(
    "Raises the Def and\n"
    "Sp. Def of Pokémon\n"
    "that can evolve.");

static const u8 sFloatStoneDesc[] = _(
    "It's so light that\n"
    "when held, it halves\n"
    "a Pokémon's weight.");

static const u8 sRockyHelmetDesc[] = _(
    "Hurts the foe if\n"
    "they touch its\n"
    "holder.");

static const u8 sAirBalloonDesc[] = _(
    "Elevates the holder\n"
    "in the air. If hit,\n"
    "this item will burst.");

static const u8 sRedCardDesc[] = _(
    "Switches out the\n"
    "foe if they hit the\n"
    "holder.");

static const u8 sRingTargetDesc[] = _(
    "Moves that wouldn't\n"
    "have effect will\n"
    "land on its holder.");

static const u8 sBindingBandDesc[] = _(
    "Increases the\n"
    "power of binding\n"
    "moves when held.");

static const u8 sEjectButtonDesc[] = _(
    "Switches out the\n"
    "user if they're hit\n"
    "by the foe.");

static const u8 sWeaknessPolicyDesc[] = _(
    "If hit by a Super\n"
    "Effective move, ups\n"
    "Atk and Sp. Atk.");

static const u8 sAssaultVestDesc[] = _(
    "Raises Sp. Def but\n"
    "prevents the use\n"
    "of status moves.");

static const u8 sSafetyGogglesDesc[] = _(
    "Protect from\n"
    "weather damage and\n"
    "powder moves.");

static const u8 sAdrenalineOrbDesc[] = _(
    "Boosts Speed if the\n"
    "user is intimidated,\n"
    "but only one time.");

static const u8 sTerrainExtenderDesc[] = _(
    "Extends the length\n"
    "of the active\n"
    "battle terrain.");

static const u8 sProtectivePadsDesc[] = _(
    "Guard the holder\n"
    "from contact move\n"
    "effects.");

static const u8 sThroatSprayDesc[] = _(
    "Raises Sp. Atk. if\n"
    "the holder uses a\n"
    "sound-based move.");

static const u8 sEjectPackDesc[] = _(
    "Forces the user to\n"
    "switch if its stats\n"
    "are lowered.");

static const u8 sHeavyDutyBootsDesc[] = _(
    "Boots that prevent\n"
    "effects of traps\n"
    "set in the field.");

static const u8 sBlunderPolicyDesc[] = _(
    "Raises Speed if\n"
    "the user misses\n"
    "due to Accuracy.");

static const u8 sRoomServiceDesc[] = _(
    "Lowers Speed if\n"
    "Trick Room is\n"
    "active.");

static const u8 sUtilityUmbrellaDesc[] = _(
    "An umbrella that\n"
    "protects from\n"
    "weather effects.");

// Berries
static const u8 sCheriBerryDesc[] = _("{JPN}ポケモンに もたせると\nまひを かいふくする。");

static const u8 sChestoBerryDesc[] = _("{JPN}ポケモンに もたせると\nねむりを かいふくする。");

static const u8 sPechaBerryDesc[] = _("{JPN}ポケモンに もたせると\nどくを かいふくする。");

static const u8 sRawstBerryDesc[] = _("{JPN}ポケモンに もたせると\nやけどを かいふくする。");

static const u8 sAspearBerryDesc[] = _("{JPN}ポケモンに もたせると\nこおりを かいふくする。");

static const u8 sLeppaBerryDesc[] = _("{JPN}ポケモンに もたせると\nPPを 10だけ\nかいふくする。");

static const u8 sOranBerryDesc[] = _("{JPN}ポケモンに もたせると\nHPを 10だけ\nかいふくする。");

static const u8 sPersimBerryDesc[] = _("{JPN}ポケモンに もたせると\nこんらんを かいふくする。");

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

static const u8 sRazzBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Razz.");

static const u8 sBlukBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Bluk.");

static const u8 sNanabBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Nanab.");

static const u8 sWepearBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Wepear.");

static const u8 sPinapBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Pinap.");

static const u8 sPomegBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base HP.");

static const u8 sKelpsyBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Attack.");

static const u8 sQualotBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Defense.");

static const u8 sHondewBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Sp. Atk.");

static const u8 sGrepaBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Sp. Def.");

static const u8 sTamatoBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Speed.");

static const u8 sCornnBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Cornn.");

static const u8 sMagostBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Magost.");

static const u8 sRabutaBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Rabuta.");

static const u8 sNomelBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Nomel.");

static const u8 sSpelonBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Spelon.");

static const u8 sPamtreBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Pamtre.");

static const u8 sWatmelBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Watmel.");

static const u8 sDurinBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Durin.");

static const u8 sBelueBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Belue.");

static const u8 sChilanBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Normal\n"
    "move.");

static const u8 sOccaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Fire\n"
    "move if weak to it.");

static const u8 sPasshoBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Water\n"
    "move if weak to it.");

static const u8 sWacanBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Electric\n"
    "move if weak to it.");

static const u8 sRindoBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Grass\n"
    "move if weak to it.");

static const u8 sYacheBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Ice\n"
    "move if weak to it.");

static const u8 sChopleBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Fighting\n"
    "move if weak to it.");

static const u8 sKebiaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Poison\n"
    "move if weak to it.");

static const u8 sShucaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Ground\n"
    "move if weak to it.");

static const u8 sCobaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Flying\n"
    "move if weak to it.");

static const u8 sPayapaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Psychic\n"
    "move if weak to it.");

static const u8 sTangaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Bug\n"
    "move if weak to it.");

static const u8 sChartiBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Rock\n"
    "move if weak to it.");

static const u8 sKasibBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Ghost\n"
    "move if weak to it.");

static const u8 sHabanBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Dragon\n"
    "move if weak to it.");

static const u8 sColburBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Dark\n"
    "move if weak to it.");

static const u8 sBabiriBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Steel\n"
    "move if weak to it.");

static const u8 sRoseliBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Fairy\n"
    "move if weak to it.");

static const u8 sLiechiBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nこうげきが あがる。");

static const u8 sGanlonBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nぼうぎょが あがる。");

static const u8 sSalacBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nすばやさが あがる。");

static const u8 sPetayaBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nとくこうが あがる。");

static const u8 sApicotBerryDesc[] = _("{JPN}ポケモンに もたせると\nピンチのとき じぶんの\nとくぼうが あがる。");

static const u8 sLansatBerryDesc[] = _(
    "A hold item that\n"
    "ups the critical-\n"
    "hit rate in a pinch.");

static const u8 sStarfBerryDesc[] = _(
    "A hold item that\n"
    "sharply boosts a\n"
    "stat in a pinch.");

static const u8 sEnigmaBerryDesc[] = _(
    "A hold item that\n"
    "heals from super\n"
    "effective moves.");

static const u8 sMicleBerryDesc[] = _(
    "When held, it ups\n"
    "the Accuracy of a\n"
    "move in a pinch.");

static const u8 sCustapBerryDesc[] = _(
    "It allows a Pokémon\n"
    "in a pinch to move\n"
    "first just once.");

static const u8 sJabocaBerryDesc[] = _(
    "If hit by a physical\n"
    "move, it will hurt\n"
    "the attacker a bit.");

static const u8 sRowapBerryDesc[] = _(
    "If hit by a special\n"
    "move, it will hurt\n"
    "the attacker a bit.");

static const u8 sKeeBerryDesc[] = _(
    "If hit by a physical\n"
    "move, it raises the\n"
    "Defense a bit.");

static const u8 sMarangaBerryDesc[] = _(
    "If hit by a special\n"
    "move, it raises the\n"
    "Sp. Def. a bit.");

static const u8 sEnigmaBerryEReaderDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow a mystery.");

// TMs/HMs
static const u8 sTM01Desc[] = _("{JPN}ものすごい ちからを\nこめた キックで あいてを\nけとばして こうげきする。");

static const u8 sTM02Desc[] = _("{JPN}あいての からだに\nこばんを なげつけて\nこうげきする。");

static const u8 sTM03Desc[] = _("{JPN}ほのおを こめた パンチで\nあいてを こうげきする。");

static const u8 sTM04Desc[] = _("{JPN}れいきを こめた パンチで\nあいてを こうげきする。");

static const u8 sTM05Desc[] = _("{JPN}でんげきを こめた\nパンチで あいてを\nこうげきする。");

static const u8 sTM06Desc[] = _("{JPN}1ターンめで そらへ とび\n2ターンめに あいてを\nこうげきする。");

static const u8 sTM07Desc[] = _("{JPN}するどい ハリを あいてに\nはっしゃして\nこうげきする。");

static const u8 sTM08Desc[] = _("{JPN}つよい こうせんを\nあいてに はっしゃして\nこうげきする。");

static const u8 sTM09Desc[] = _("{JPN}もてる ちからを すべて\nつかって あいてに\nとつげきする。");

static const u8 sTM10Desc[] = _("{JPN}あいてを ついせきする\nふしぎな はっぱを\nまきちらす。");

static const u8 sTM11Desc[] = _(
    "Raises the power of\n"
    "Fire-type moves\n"
    "for 5 turns.");

static const u8 sTM12Desc[] = _(
    "Enrages the foe so\n"
    "it can only use\n"
    "attack moves.");

static const u8 sTM13Desc[] = _(
    "Fires an icy cold\n"
    "beam that may\n"
    "freeze the foe.");

static const u8 sTM14Desc[] = _("{JPN}よわい でんげきを\nあびせる ことで あいてを\nまひ じょうたいに する。");

static const u8 sTM15Desc[] = _("{JPN}1ターンめに もぐり\n2ターンめで あいてを\nこうげきする。");

static const u8 sTM16Desc[] = _(
    "Creates a wall of\n"
    "light that lowers\n"
    "Sp. Atk damage.");

static const u8 sTM17Desc[] = _(
    "Negates all damage,\n"
    "but may fail if used\n"
    "in succession.");

static const u8 sTM18Desc[] = _(
    "Raises the power of\n"
    "Water-type moves\n"
    "for 5 turns.");

static const u8 sTM19Desc[] = _(
    "Recovers half the\n"
    "HP of the damage \n"
    "this move inflicts.");

static const u8 sTM20Desc[] = _("{JPN}ばくはつを おこして\nじぶんの まわりに\nいるものを こうげきする。");

static const u8 sTM21Desc[] = _("{JPN}じぶんの HPと\nじょうたいいじょうを\nすべて かいふく する。");

static const u8 sTM22Desc[] = _("{JPN}おおきな いわを はげしく\nぶつけて こうげきする。");

static const u8 sTM23Desc[] = _("{JPN}じぶんが どうぐを\nもっている ばあいは\nぬすめない。");

static const u8 sTM24Desc[] = _("{JPN}じぶんが ねている ときに\nざつおんを だして\nこうげきする。");

static const u8 sTM25Desc[] = _("{JPN}あいての こうげきを\nまったく うけない。");

static const u8 sTM26Desc[] = _(
    "Causes a quake\n"
    "that has no effect\n"
    "on flying foes.");

static const u8 sTM27Desc[] = _("{JPN}つめたい れいきを\nあいてに ふきつけて\nこうげきする。");

static const u8 sTM28Desc[] = _("{JPN}あたえた ダメージの\nはんぶんの HPを\nかいふく できる。");

static const u8 sTM29Desc[] = _(
    "A powerful psychic\n"
    "attack that may\n"
    "lower Sp. Def.");

static const u8 sTM30Desc[] = _("{JPN}かたい つばさを あいてに\nたたきつけて\nこうげきする。");

static const u8 sTM31Desc[] = _("{JPN}♂なら♀を ♀なら♂を\nゆうわくして メロメロに\nする。");

static const u8 sTM32Desc[] = _("{JPN}いわタイプの とくぼうが\nあがる。");

static const u8 sTM33Desc[] = _("{JPN}5ターンの あいだ あめを\nふらせて みずタイプの\nいりょくを あげる。");

static const u8 sTM34Desc[] = _("{JPN}みずタイプの いりょくは\nさがる。");

static const u8 sTM35Desc[] = _(
    "Looses a stream of\n"
    "fire that may burn\n"
    "the foe.");

static const u8 sTM36Desc[] = _(
    "Hurls sludge at the\n"
    "foe. It may poison\n"
    "the foe.");

static const u8 sTM37Desc[] = _("{JPN}みかた ぜんいんで\nこうげきする。");

static const u8 sTM38Desc[] = _(
    "A powerful fire\n"
    "attack that may\n"
    "burn the foe.");

static const u8 sTM39Desc[] = _(
    "Stops the foe from\n"
    "moving with rocks.\n"
    "May lower Speed.");

static const u8 sTM40Desc[] = _("{JPN}ほしがたの ひかりを\nはっしゃして あいてを\nこうげきする。");

static const u8 sTM41Desc[] = _("{JPN}なかまを たすける。");

static const u8 sTM42Desc[] = _(
    "Raises Attack when\n"
    "poisoned, burned,\n"
    "or paralyzed.");

static const u8 sTM43Desc[] = _("{JPN}しゅとうを いきおいよく\nふりおろして あいてを\nこうげきする。");

static const u8 sTM44Desc[] = _(
    "The user sleeps for\n"
    "2 turns to restore\n"
    "health and status.");

static const u8 sTM45Desc[] = _("{JPN}1ターンめで もぐり\n2ターンめに うきあがって\nこうげきする。");

static const u8 sTM46Desc[] = _("{JPN}つかった ときの てんきに\nよって わざの タイプと\nいりょくが かわる。");

static const u8 sTM47Desc[] = _("{JPN}こまらせる ことで\nあいての とくぼうを\nがくっと さげる。");

static const u8 sTM48Desc[] = _("{JPN}あいての うごきを\nふうじることで すばやさを\nさげる。");

static const u8 sTM49Desc[] = _(
    "Steals the effects\n"
    "of the move the foe\n"
    "is trying to use.");

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

static const u8 sHM01Desc[] = _("{JPN}ー ー ー。");

static const u8 sHM02Desc[] = _("{JPN}ー ー ー。");

static const u8 sHM03Desc[] = _("{JPN}ー ー ー。");

static const u8 sHM04Desc[] = _("{JPN}ー ー ー。");

static const u8 sHM05Desc[] = _("{JPN}ー ー ー。");

static const u8 sHM06Desc[] = _("{JPN}ー ー ー。");

static const u8 sHM07Desc[] = _("{JPN}1ターンめで もぐり\n2ターンめに うきあがって\nこうげきする。");

static const u8 sHM08Desc[] = _(
    "Dives underwater\n"
    "the 1st turn, then\n"
    "attacks next turn.");

// Charms
static const u8 sOvalCharmDesc[] = _(
    "Raises the chance\n"
    "of finding eggs\n"
    "at the daycare.");

static const u8 sShinyCharmDesc[] = _(
    "A charm that will\n"
    "raise the chance\n"
    "of Shiny Pokémon.");

static const u8 sCatchingCharmDesc[] = _(
    "A charm that raises\n"
    "the chance of\n"
    "Critical Captures.");

static const u8 sExpCharmDesc[] = _(
    "A charm that raises\n"
    "the amount of Exp.\n"
    "earned in battle.");

// Form-changing Key Items
static const u8 sRotomCatalogDesc[] = _(
    "A catalog full of\n"
    "deviced liked by\n"
    "Rotom.");

static const u8 sGracideaDesc[] = _(
    "Bouquets made with\n"
    "it are offered as a\n"
    "token of gratitude.");

static const u8 sRevealGlassDesc[] = _(
    "This glass returns\n"
    "a Pokémon back to\n"
    "its original form.");

static const u8 sDNASplicersDesc[] = _(
    "Splicer that fuses\n"
    "Kyurem and a\n"
    "certain Pokémon.");

static const u8 sZygardeCubeDesc[] = _(
    "An item to store\n"
    "Zygarde Cores and\n"
    "Cells.");

static const u8 sPrisonBottleDesc[] = _(
    "A bottle used to\n"
    "seal a certain\n"
    "Pokémon long ago.");

static const u8 sNSolarizerDesc[] = _(
    "A device to fuse\n"
    "and split Necrozma\n"
    "using a Solgaleo.");

static const u8 sNLunarizerDesc[] = _(
    "A device to fuse\n"
    "and split Necrozma\n"
    "using a Lunala.");

static const u8 sReinsOfUnityDesc[] = _(
    "Reins that unite\n"
    "Calyrex with its\n"
    "beloved steed.");

// Battle Mechanic Key Items
static const u8 sMegaRingDesc[] = _(
    "Enables {PKMN} holding\n"
    "their Mega Stone to\n"
    "Mega Evolve.");

static const u8 sZPowerRingDesc[] = _(
    "A strange ring\n"
    "that enables\n"
    "Z-Move usage.");

static const u8 sDynamaxBandDesc[] = _(
    "A band carrying a\n"
    "Wishing Star that\n"
    "allows Dynamaxing.");

// Misc. Key Items
static const u8 sBicycleDesc[] = _(
    "A folding bicycle\n"
    "that is faster than\n"
    "the Running Shoes.");

static const u8 sMachBikeDesc[] = _("{JPN}2ばい いじょうの\nはやさで いどう できる\nおりたたみの じてんしゃ。");

static const u8 sAcroBikeDesc[] = _("{JPN}ジャンプや ウィリーの\nアクションが できる\nおりたたみの じてんしゃ。");

static const u8 sOldRodDesc[] = _("{JPN}みずの ある ばしょで\nつかうと ポケモンが\nつれる。");

static const u8 sGoodRodDesc[] = _("{JPN}みずの ある ばしょで\nつかうと ポケモンが\nつれる。");

static const u8 sSuperRodDesc[] = _("{JPN}みずの ある ばしょで\nつかうと ポケモンが\nつれる。");

static const u8 sDowsingMachineDesc[] = _("{JPN}あたまに つけて つかう。");

static const u8 sTownMapDesc[] = _("{JPN}いつでも てがるに\nみることが できる\nべんりな ちず。");

static const u8 sVsSeekerDesc[] = _("{JPN}たたかいたい トレーナーを\nおしえてくれる きかい。");

static const u8 sTMCaseDesc[] = _("{JPN}ー ー ー。");

static const u8 sBerryPouchDesc[] = _(
    "A convenient\n"
    "container that\n"
    "holds Berries.");

static const u8 sPokemonBoxLinkDesc[] = _(
    "This device grants\n"
    "access to the {PKMN}\n"
    "Storage System.");

static const u8 sCoinCaseDesc[] = _(
    "A case that holds\n"
    "up to 9,999 Coins.");

static const u8 sPowderJarDesc[] = _(
    "Stores Berry\n"
    "Powder made using\n"
    "a Berry Crusher.");

static const u8 sWailmerPailDesc[] = _("{JPN}みずを かける どうぐ。\nつちに うめた きのみを\nすくすく そだてる。");

static const u8 sPokeRadarDesc[] = _(
    "A tool used to\n"
    "search out Pokémon\n"
    "hiding in grass.");

static const u8 sPokeblockCaseDesc[] = _(
    "A case for holding\n"
    "{POKEBLOCK}s made with\n"
    "a Berry Blender.");

static const u8 sSootSackDesc[] = _("{JPN}つもった かざんばいを\nあつめるための ふくろ。");

static const u8 sPokeFluteDesc[] = _(
    "A sweet-sounding\n"
    "flute that awakens\n"
    "Pokémon.");

static const u8 sFameCheckerDesc[] = _(
    "Stores information\n"
    "on famous people\n"
    "for instant recall.");

static const u8 sTeachyTVDesc[] = _(
    "A TV set tuned to\n"
    "an advice program\n"
    "for Trainers.");

// Story Key Items
static const u8 sSSTicketDesc[] = _("{JPN}こうそくせん アクアごうに\nのるとき ひつような\nふねの チケット。");

static const u8 sEonTicketDesc[] = _("{JPN}トウカジムの ジムリーダー\nセンリが ひみつを\nしっている!?。");

static const u8 sMysticTicketDesc[] = _(
    "A ticket required\n"
    "to board the ship\n"
    "to Navel Rock.");

static const u8 sAuroraTicketDesc[] = _(
    "A ticket required\n"
    "to board the ship\n"
    "to Birth Island.");

static const u8 sOldSeaMapDesc[] = _(
    "A faded sea chart\n"
    "that shows the way\n"
    "to a certain island.");

static const u8 sLetterDesc[] = _("{JPN}デボンしゃちょうから\nあずかった てがみ。");

static const u8 sDevonPartsDesc[] = _(
    "A package that\n"
    "contains Devon's\n"
    "machine parts.");

static const u8 sGoGogglesDesc[] = _("{JPN}さばくの すなあらしから\nめを まもって くれる\nすてきな ゴーグル。");

static const u8 sDevonScopeDesc[] = _("{JPN}みえない ポケモンに\nはんのうして おとをだす\nデボンの とくせいひん。");

static const u8 sBasementKeyDesc[] = _("{JPN}コガネちかどうに ある\nとびらを あける カギ。");

static const u8 sScannerDesc[] = _("{JPN}シーキンセツの なかで\nみつけた どうぐ。");

static const u8 sStorageKeyDesc[] = _(
    "The key to the\n"
    "storage inside the\n"
    "Abandoned Ship.");

static const u8 sKeyToRoom1Desc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sKeyToRoom2Desc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sKeyToRoom4Desc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sKeyToRoom6Desc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sMeteoriteDesc[] = _("{JPN}もともとは\nりゅうせいのたきに\nおちていた いんせき。");

static const u8 sMagmaEmblemDesc[] = _(
    "A medal-like item in\n"
    "the same shape as\n"
    "Team Magma's mark.");

static const u8 sContestPassDesc[] = _("{JPN}きねんリボンが\nかかれている。");

static const u8 sParcelDesc[] = _(
    "A parcel for Prof.\n"
    "Oak from a Pokémon\n"
    "Mart's clerk.");

static const u8 sSecretKeyDesc[] = _(
    "The key to the\n"
    "Cinnabar Island\n"
    "Gym's entrance.");

static const u8 sBikeVoucherDesc[] = _(
    "A voucher for\n"
    "obtaining a bicycle\n"
    "from the Bike Shop.");

static const u8 sGoldTeethDesc[] = _("{JPN}サファリゾーンの\nえんちょうが おとした\nきんいろの いれば。");

static const u8 sCardKeyDesc[] = _("{JPN}ラジオきょくの\nシャッターを あける\nカードしきの カギ。");

static const u8 sLiftKeyDesc[] = _("{JPN}ロケットだん アジトに\nある エレベータを\nうごかす カギ。");

static const u8 sSilphScopeDesc[] = _("{JPN}ひとの めに みえない\nものを みることが できる\nスコープ。");

static const u8 sTriPassDesc[] = _(
    "A pass for ferries\n"
    "between One, Two,\n"
    "and Three Island.");

static const u8 sRainbowPassDesc[] = _(
    "For ferries serving\n"
    "Vermilion and the\n"
    "Sevii Islands.");

static const u8 sTeaDesc[] = _("{JPN}すこし にがくて\nこうばしい かおりの\nおちゃ。");

static const u8 sRubyDesc[] = _(
    "An exquisite, red-\n"
    "glowing gem that\n"
    "symbolizes passion.");

static const u8 sSapphireDesc[] = _(
    "A brilliant blue gem\n"
    "that symbolizes\n"
    "honesty.");

static const u8 sAbilityShieldDesc[] = _(
    "Ability changes are\n"
    "prevented for this\n"
    "items's holder.");

static const u8 sClearAmuletDesc[] = _(
    "Stat lowering is\n"
    "prevented for this\n"
    "items's holder.");

static const u8 sPunchingGloveDesc[] = _(
    "Powers up punching\n"
    "moves and removes\n"
    "their contact.");

static const u8 sCovertCloakDesc[] = _(
    "Protects the holder\n"
    "from secondary\n"
    "move effects.");

static const u8 sLoadedDiceDesc[] = _(
    "Rolls high numbers.\n"
    "Multihit strikes\n"
    "hit more times.");

static const u8 sAuspiciousArmorDesc[] = _(
    "Armor inhabited by\n"
    "auspicious wishes.\n"
    "Causes evolution.");

static const u8 sBoosterEnergyDesc[] = _(
    "Encapsuled energy\n"
    "ups Pokémon with\n"
    "certain Abilities.");

static const u8 sBigBambooShootDesc[] = _(
    "A large and rare\n"
    "bamboo shoot. Best\n"
    "sold to gourmands.");

static const u8 sGimmighoulCoinDesc[] = _(
    "Gimmighoul hoard\n"
    "and treasure these\n"
    "curious coins.");

static const u8 sLeadersCrestDesc[] = _(
    "A shard of an old\n"
    "blade of some sort.\n"
    "Held by Bisharp.");

static const u8 sMaliciousArmorDesc[] = _(
    "Armor inhabited by\n"
    "malicious will.\n"
    "Causes evolution.");

static const u8 sMirrorHerbDesc[] = _(
    "Mirrors an enemy's\n"
    "stat increases\n"
    "but only once.");

static const u8 sScrollOfDarknessDesc[] = _(
    "A peculiar scroll\n"
    "with secrets of\n"
    "the dark path.");

static const u8 sScrollOfWatersDesc[] = _(
    "A peculiar scroll\n"
    "with secrets of\n"
    "the water path.");

static const u8 sTeraOrbDesc[] = _(
    "Energy charges can\n"
    "be used to cause\n"
    "Terastallization.");

static const u8 sTinyBambooShootDesc[] = _(
    "A small and rare\n"
    "bamboo shoot. Best\n"
    "sold to gourmands.");

static const u8 sTeraShardDesc[] = _(
    "A shard that may\n"
    "change the Tera\n"
    "Type of a {PKMN}.");

static const u8 sAdamantCrystalDesc[] = _(
    "A large, glowing gem\n"
    "that lets Dialga\n"
    "change form.");

static const u8 sGriseousCoreDesc[] = _(
    "A large, glowing gem\n"
    "that lets Giratina\n"
    "change form.");

static const u8 sLustrousGlobeDesc[] = _(
    "A large, glowing gem\n"
    "that lets Palkia\n"
    "change form.");

static const u8 sBerserkGene[] = _(
    "Sharply boosts\n"
    "Attack, but causes\n"
    "lasting confusion.");

static const u8 sFairyFeatherDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Fairy-type moves.");

static const u8 sSyrupyAppleDesc[] = _(
    "A very syrupy apple\n"
    "that makes certain\n"
    "Pokémon evolve.");

static const u8 sUnremarkableTeacupDesc[] = _(
    "A cracked teacup\n"
    "that makes certain\n"
    "Pokémon evolve.");

static const u8 sMasterpieceTeacupDesc[] = _(
    "A chipped teacup\n"
    "that makes certain\n"
    "Pokémon evolve.");

static const u8 sCornerstoneMaskDesc[] = _(
    "Allows Ogerpon to\n"
    "wield the Rock-\n"
    "type in battle.");

static const u8 sWellspringMaskDesc[] = _(
    "Allows Ogerpon to\n"
    "wield the Water-\n"
    "type in battle.");

static const u8 sHearthflameMaskDesc[] = _(
    "Allows Ogerpon to\n"
    "wield the Fire-\n"
    "type in battle.");

static const u8 sHealthMochiDesc[] = _("{JPN}ポケモンの きほんの\nHPを あげる\nどうぐ。");

static const u8 sMuscleMochiDesc[] = _("{JPN}ポケモンの きほんの\nこうげきを あげる\nどうぐ。");

static const u8 sResistMochiDesc[] = _("{JPN}ポケモンの きほんの\nぼうぎょを あげる\nどうぐ。");

static const u8 sGeniusMochiDesc[] = _("{JPN}ポケモンの きほんの\nとくこうを あげる\nどうぐ。");

static const u8 sCleverMochiDesc[] = _("{JPN}ポケモンの きほんの\nとくぼうを あげる\nどうぐ。");

static const u8 sSwiftMochiDesc[] = _("{JPN}ポケモンの きほんの\nすばやさを あげる\nどうぐ。");

static const u8 sFreshStartMochiDesc[] = _(
    "An item that resets\n"
    "all base points of\n"
    "a Pokémon.");

static const u8 sGlimmeringCharmDesc[] = _(
    "A charm that will\n"
    "raise the shards\n"
    "from Tera Raids.");

static const u8 sMetalAlloyDesc[] = _(
    "A peculiar metal\n"
    "that makes certain\n"
    "Pokémon evolve.");
