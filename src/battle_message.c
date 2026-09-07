#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

#include "rogue_controller.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);

static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
//static const u8 sText_PkmnGainedEXP[] = _("Team gained EXP. Points!\p");
//static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1} gained{B_BUFF2}\n{B_BUFF3} EXP. Points!\p");
static const u8 sText_PkmnGainedEXP[] = _("{JPN}{B_BUFF1}は{B_BUFF2}\nけいけんちを もらった!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _("{JPN} たくさんの");
static const u8 sText_PkmnGrewToLv[] = _("{JPN}{B_BUFF1}は レベル{B_BUFF2}に\nあがった!\p");
static const u8 sText_TeamGrewToLv[] = _("{JPN}みんなは {LV}{B_BUFF2}に\nあがった!\p");
static const u8 sText_PkmnLearnedMove[] = _("{JPN}{B_BUFF1}は {B_BUFF2}を\nおぼえた!\p");
static const u8 sText_TryToLearnMove1[] = _("{JPN}{B_BUFF1}は {B_BUFF2}を\nおぼえようと している。\p");
static const u8 sText_TryToLearnMove2[] = _("{JPN}しかし {B_BUFF1}は わざを\n4つしか おぼえられない。\p");
static const u8 sText_TryToLearnMove3[] = _("{JPN}{B_BUFF2}を おぼえるために\nわざを わすれさせますか?");
static const u8 sText_PkmnForgotMove[] = _("{JPN}{B_BUFF1}は {B_BUFF2}を\nわすれた。\p");
static const u8 sText_StopLearningMove[] = _("{JPN}{PAUSE 32}{B_BUFF2}を おぼえるのを\nやめますか?");
static const u8 sText_DidNotLearnMove[] = _("{JPN}{B_BUFF1}は {B_BUFF2}を\nおぼえなかった。\p");
static const u8 sText_UseNextPkmn[] = _("{JPN}つぎの ポケモンを だしますか?");
static const u8 sText_AttackMissed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の\nこうげきは はずれた!");
static const u8 sText_PkmnProtectedItself[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nみを まもっている!");
static const u8 sText_AvoidedDamage[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nダメージを うけなかった!");
static const u8 sText_PkmnMakesGroundMiss[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で じめんタイプの\nわざを うけない!");
static const u8 sText_PkmnAvoidedAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nこうげきを かわした!");
static const u8 sText_ItDoesntAffect[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}には\nこうかが ないようだ…");
static const u8 sText_AttackerFainted[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nたおれた!\p");
static const u8 sText_TargetFainted[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nたおれた!\p");
static const u8 sText_PlayerGotMoney[] = _("{JPN}{B_PLAYER_NAME}は しょうきんとして\n{B_BUFF1}¥を てに いれた!\p");
static const u8 sText_PlayerLostToEnemyTrainer[] = _("{JPN}{B_PLAYER_NAME}には たたかえる ポケモンが\nいなくなった!\p{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}に\nまけて しまった!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerPaidPrizeMoney[] = _("{JPN}… … … …\p{B_PLAYER_NAME}は めのまえが まっくらに なった!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerWhiteout[] = _("{JPN}{B_PLAYER_NAME}には たたかえる ポケモンが\nいなくなった!\p");
#if B_WHITEOUT_MONEY >= GEN_4
static const u8 sText_PlayerWhiteout2[] = _("{JPN}{B_PLAYER_NAME}は あわてて {B_BUFF1}¥を おとした…\p… … … …\p{B_PLAYER_NAME}は めのまえが まっくらに なった!{PAUSE_UNTIL_PRESS}");
#else
static const u8 sText_PlayerWhiteout2[] = _("{JPN}{B_PLAYER_NAME}は めのまえが まっくらに なった!{PAUSE_UNTIL_PRESS}");
#endif
static const u8 sText_PreventsEscape[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nにげられない!\p");
static const u8 sText_CantEscape2[] = _("{JPN}にげられない!\p");
static const u8 sText_AttackerCantEscape[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は にげられない!");
static const u8 sText_HitXTimes[] = _("{JPN}{B_BUFF1}かい あたった!");
static const u8 sText_PkmnFellAsleep[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nねむってしまった!");
static const u8 sText_PkmnMadeSleep[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\n{B_EFF_NAME_WITH_PREFIX}を ねむらせた!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nもう ねむっている!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nもう ねむっている!");
static const u8 sText_PkmnWasntAffected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}には\nきかなかった!");
static const u8 sText_PkmnWasPoisoned[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nどくを あびた!");
static const u8 sText_PkmnPoisonedBy[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は {B_SCR_ACTIVE_NAME_WITH_PREFIX}の\n{B_BUFF1}で どくを あびた!");
static const u8 sText_PkmnHurtByPoison[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nどくで ダメージを うけた!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nもう どく じょうたいだ。");
static const u8 sText_PkmnBadlyPoisoned[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nもうどくを あびた!");
static const u8 sText_PkmnEnergyDrained[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の\nたいりょくを すいとった!");
static const u8 sText_PkmnWasBurned[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は やけどを おった!");
static const u8 sText_PkmnGotFrostbite[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は しもやけに なった!");
static const u8 sText_PkmnBurnedBy[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\n{B_EFF_NAME_WITH_PREFIX}を やけどに した!");
static const u8 sText_PkmnHurtByBurn[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は やけどの\nダメージを うけた!");
static const u8 sText_PkmnHurtByFrostbite[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は しもやけの\nダメージを うけた!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は すでに\nやけどを おっている。");
static const u8 sText_PkmnWasFrozen[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nこおりついた!");
static const u8 sText_PkmnFrozenBy[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\n{B_EFF_NAME_WITH_PREFIX}を こおらせた!");
static const u8 sText_PkmnIsFrozen[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は こおって しまって\nうごけない!");
static const u8 sText_PkmnWasDefrosted[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の こおりが\nとけた!");
static const u8 sText_PkmnWasDefrosted2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の こおりが\nとけた!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_CURRENT_MOVE}で\nこおりが とけた!");
static const u8 sText_PkmnFrostbiteHealed[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の しもやけが\nなおった!");
static const u8 sText_PkmnFrostbiteHealed2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の しもやけが\nなおった!");
static const u8 sText_PkmnFrostbiteHealedBy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_CURRENT_MOVE}で\nしもやけが なおった!");
static const u8 sText_PkmnWasParalyzed[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は まひして しまって\nわざが でにくく なった!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\n{B_EFF_NAME_WITH_PREFIX}を まひさせた!\lわざが でにくく なった!");
static const u8 sText_PkmnIsParalyzed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は からだが しびれて\nうごけない!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は すでに\nまひして いる!");
static const u8 sText_PkmnHealedParalysis[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の まひが\nなおった!");
static const u8 sText_PkmnDreamEaten[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の ゆめを\nたべた!");
static const u8 sText_StatsWontIncrease[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}は\nもう あがらない!");
static const u8 sText_StatsWontDecrease[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}は\nもう さがらない!");
static const u8 sText_TeamStoppedWorking[] = _("{JPN}みかたの {B_BUFF1}の\nこうかが なくなった!");
static const u8 sText_FoeStoppedWorking[] = _("{JPN}あいての {B_BUFF1}の\nこうかが なくなった!");
static const u8 sText_PkmnIsConfused[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は こんらんして\nいる!");
static const u8 sText_PkmnHealedConfusion[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の こんらんが\nとけた!");
static const u8 sText_PkmnWasConfused[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nこんらんした!");
static const u8 sText_PkmnAlreadyConfused[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は すでに\nこんらんして いる!");
static const u8 sText_PkmnFellInLove[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は メロメロに\nなった!");
static const u8 sText_PkmnInLove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_SCR_ACTIVE_NAME_WITH_PREFIX}に\nメロメロだ!");
static const u8 sText_PkmnImmobilizedByLove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は メロメロで\nわざが だせない!");
static const u8 sText_PkmnBlownAway[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nふきとばされた!");
static const u8 sText_PkmnChangedType[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}タイプに\nなった!");
static const u8 sText_PkmnFlinched[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ひるんで わざが だせない!");
static const u8 sText_PkmnRegainedHealth[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は たいりょくを\nかいふくした!");
static const u8 sText_PkmnHPFull[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の HPは\nまんたんだ!");
static const u8 sText_PkmnRaisedSpDef[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nとくぼうが あがった!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nとくぼうが すこし あがった!");
static const u8 sText_PkmnRaisedDef[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nぼうぎょが あがった!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nぼうぎょが すこし あがった!");
static const u8 sText_PkmnCoveredByVeil[] = _("{JPN}{B_ATK_PREFIX2}の てもちは\nベールに つつまれた!");
static const u8 sText_PkmnUsedSafeguard[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の てもちは しんぴのまもりに\nまもられている!");
static const u8 sText_PkmnSafeguardExpired[] = _("{JPN}{B_ATK_PREFIX3}の てもちの しんぴのまもりが\nきれた!");
static const u8 sText_PkmnWentToSleep[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nねむりはじめた!");
static const u8 sText_PkmnSleptHealthy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ねむって げんきに\nなった!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は たつまきを\nおこした!");
static const u8 sText_PkmnTookSunlight[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は こうごうせいの\nじゅんびを した!");
static const u8 sText_PkmnLoweredHead[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あたまを\nさげた!");
static const u8 sText_PkmnIsGlowing[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ひかり かがやいた!");
static const u8 sText_PkmnFlewHigh[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は そらたかく\nとびあがった!");
static const u8 sText_PkmnDugHole[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あなを ほって もぐった!");
static const u8 sText_PkmnHidUnderwater[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は みずに\nもぐった!");
static const u8 sText_PkmnSprangUp[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は とびはねた!");
static const u8 sText_PkmnSqueezedByBind[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_ATK_NAME_WITH_PREFIX}の\nしめつけるに つかまった!");
static const u8 sText_PkmnInSnapTrap[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は トラップに\nかかった!");
static const u8 sText_PkmnTrappedInVortex[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は うずしおに\nつかまった!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は すなじごくに\nつかまった!");
static const u8 sText_PkmnWrappedBy[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_ATK_NAME_WITH_PREFIX}に\nまきつかれた!");
static const u8 sText_PkmnClamped[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nはさみこんだ!");
static const u8 sText_PkmnHurtBy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}の\nダメージを うけた!");
static const u8 sText_PkmnFreedFrom[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}から\nぬけだした!");
static const u8 sText_PkmnCrashed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は いきおいあまって\nじめんに ぶつかった!");
const u8 gText_PkmnShroudedInMist[] = _("{JPN}{B_ATK_PREFIX2}は しろいきりに\nつつまれた!");
static const u8 sText_PkmnProtectedByMist[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は しろいきりに\nまもられている!");
const u8 gText_PkmnGettingPumped[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nはりきっている!");
static const u8 sText_PkmnHitWithRecoil[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は はんどうで ダメージを\nうけた!");
static const u8 sText_PkmnProtectedItself2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は みを\nまもっている!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は すなあらしの\nダメージを うけた!");
static const u8 sText_PkmnPeltedByHail[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あられの\nダメージを うけた!");
static const u8 sText_PkmnsXWoreOff[] = _("{JPN}{B_ATK_PREFIX1}の {B_BUFF1}の\nこうかが きれた!");
static const u8 sText_PkmnSeeded[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}に やどりぎを うえつけた!");
static const u8 sText_PkmnEvadedAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は こうげきを\nかわした!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は やどりぎに\nたいりょくを すいとられた!");
static const u8 sText_PkmnFastAsleep[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ぐうぐう\nねむっている。");
static const u8 sText_PkmnWokeUp[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は めを さました!");
static const u8 sText_PkmnUproarKeptAwake[] = _("{JPN}しかし {B_SCR_ACTIVE_NAME_WITH_PREFIX}の さわぐで\nねむれない!");
static const u8 sText_PkmnWokeUpInUproar[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は さわぎで めを\nさました!");
static const u8 sText_PkmnCausedUproar[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nさわぎはじめた!");
static const u8 sText_PkmnMakingUproar[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nさわいでいる!");
static const u8 sText_PkmnCalmedDown[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は しずかに なった。");
static const u8 sText_PkmnCantSleepInUproar[] = _("{JPN}しかし さわがしくて\n{B_DEF_NAME_WITH_PREFIX}は ねむれない!");
static const u8 sText_PkmnStockpiled[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}つ\nたくわえた!");
static const u8 sText_PkmnCantStockpile[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は これいじょう\nたくわえられない!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("{JPN}しかし さわがしくて\n{B_DEF_NAME_WITH_PREFIX}は ねむれない!");
static const u8 sText_UproarKeptPkmnAwake[] = _("{JPN}さわぎで {B_DEF_NAME_WITH_PREFIX}は\nねむれない!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nねむらなかった!");
static const u8 sText_PkmnStoringEnergy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ちからを\nためている!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ためた ちからを\nはなった!");
static const u8 sText_PkmnFatigueConfusion[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は つかれで\nこんらんした!");
static const u8 sText_PlayerPickedUpMoney[] = _("{JPN}{B_PLAYER_NAME}は {B_BUFF1}¥を\nひろった!\p");
static const u8 sText_PkmnUnaffected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}には こうかが\nない!");
static const u8 sText_PkmnTransformedInto[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}に\nへんしんした!");
static const u8 sText_PkmnMadeSubstitute[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は みがわりを\nだした!");
static const u8 sText_PkmnHasSubstitute[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は すでに みがわりを\nだして いる!");
static const u8 sText_SubstituteDamaged[] = _("{JPN}みがわりが {B_DEF_NAME_WITH_PREFIX}の\nかわりに ダメージを うけた!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の みがわりは\nきえた!\p");
static const u8 sText_PkmnMustRecharge[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nうごけない!");
static const u8 sText_PkmnRageBuilding[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の いかりの ゲージが\nあがっている!");
static const u8 sText_PkmnMoveWasDisabled[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}を\nふうじこめた!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の かなしばりが\nとけた!");
static const u8 sText_PkmnGotEncore[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は アンコールを\nうけた!");
static const u8 sText_PkmnEncoreEnded[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の アンコールが\nおわった!");
static const u8 sText_PkmnTookAim[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}に\nねらいを さだめた!");
static const u8 sText_PkmnSketchedMove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}を\nスケッチした!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてを みちづれに\nしようと している!");
static const u8 sText_PkmnTookFoe[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_ATK_NAME_WITH_PREFIX}を\nみちづれに した!");
static const u8 sText_PkmnReducedPP[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}を\n{B_BUFF2} へらした!");
static const u8 sText_PkmnStoleItem[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_LAST_ITEM}を うばった!");
static const u8 sText_TargetCantEscapeNow[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は もう\nにげられない!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は あくむを\nみはじめた!");
static const u8 sText_PkmnLockedInNightmare[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あくむに\nうなされている!");
static const u8 sText_PkmnLaidCurse[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は じぶんの HPを けずって\n{B_DEF_NAME_WITH_PREFIX}に のろいを かけた!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は のろいの\nダメージを うけた!");
static const u8 sText_SpikesScattered[] = _("{JPN}{B_DEF_TEAM2}の あしもとに\nまきびしが ちらばった!");
static const u8 sText_PkmnHurtBySpikes[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は まきびしの\nダメージを うけた!");
static const u8 sText_PkmnIdentified[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nみやぶった!");
static const u8 sText_PkmnPerishCountFell[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の ほろびの カウントが\n{B_BUFF1}に なった!");
static const u8 sText_PkmnBracedItself[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は こうげきに\nそなえた!");
static const u8 sText_PkmnEnduredHit[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は こうげきを\nもちこたえた!");
static const u8 sText_MagnitudeStrength[] = _("{JPN}マグニチュード {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は じぶんの HPを けずって\nこうげきを さいだいに した!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の のうりょくへんかを\nコピーした!");
static const u8 sText_PkmnGotFree[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}から\nぬけだした!");
static const u8 sText_PkmnShedLeechSeed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は やどりぎを\nふりはらった!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は まきびしを\nふきとばした!");
static const u8 sText_PkmnFledFromBattle[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は バトルから\nにげだした!");
static const u8 sText_PkmnForesawAttack[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は みらいに こうげきを\nよちした!");
static const u8 sText_PkmnTookAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_BUFF1}の\nこうげきを うけた!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_CURRENT_MOVE}を\nうんめいに えらんだ!");
static const u8 sText_PkmnAttack[] = _("{JPN}{B_BUFF1}の こうげき!");
static const u8 sText_PkmnCenterAttention[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}に ちゅうもくが\nあつまった!");
static const u8 sText_PkmnChargingPower[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ちからを\nためはじめた!");
static const u8 sText_NaturePowerTurnedInto[] = _("{JPN}しぜんのちからは {B_CURRENT_MOVE}に\nなった!");
static const u8 sText_PkmnStatusNormal[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の のうりょくへんかが\nもとに もどった!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は いちゃもんを\nつけられた!");
static const u8 sText_PkmnTighteningFocus[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は しゅうちゅうを\nたかめている!");
static const u8 sText_PkmnFellForTaunt[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は ちょうはつに\nのった!");
static const u8 sText_PkmnReadyToHelp[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nてだすけする じゅんびを した!");
static const u8 sText_PkmnSwitchedItems[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと どうぐを\nいれかえた!");
static const u8 sText_PkmnObtainedX[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}を てに\nいれた。");
static const u8 sText_PkmnObtainedX2[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_BUFF2}を てに\nいれた。");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}を てに\nいれた。\p{B_DEF_NAME_WITH_PREFIX}は {B_BUFF2}を てに\nいれた。");
static const u8 sText_PkmnCopiedFoe[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_DEF_ABILITY}を コピーした!");
static const u8 sText_PkmnMadeWish[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ねがいごとを した!");
static const u8 sText_PkmnWishCameTrue[] = _("{JPN}{B_BUFF1}の ねがいごとが\nかなった!");
static const u8 sText_PkmnPlantedRoots[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ねを はった!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ねから えいようを\nすいとった!");
static const u8 sText_PkmnAnchoredItself[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は ねを はって\nふんばっている!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nねむけに さそった!");
static const u8 sText_PkmnKnockedOff[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_LAST_ITEM}を たたきおとした!");
static const u8 sText_PkmnSwappedAbilities[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと とくせいを\nいれかえた!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいての わざを\nふうじた!");
static const u8 sText_PkmnWantsGrudge[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてに おんねんを\nのこそうと している!");
static const u8 sText_PkmnLostPPGrudge[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}は おんねんで\nPPが なくなった!");
static const u8 sText_PkmnShroudedItself[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_CURRENT_MOVE}に\nつつまれた!");
static const u8 sText_PkmnMoveBounced[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_CURRENT_MOVE}は\nマジックコートで はねかえされた!");
static const u8 sText_PkmnWaitsForTarget[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてが うごくのを\nまっている!");
static const u8 sText_PkmnSnatchedMove[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_SCR_ACTIVE_NAME_WITH_PREFIX}の わざを\nよこどりした!");
static const u8 sText_ElectricityWeakened[] = _("{JPN}でんきの いりょくが\nよわまった!");
static const u8 sText_FireWeakened[] = _("{JPN}ほのおの いりょくが\nよわまった!");
static const u8 sText_XFoundOneY[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ITEM}を\nひろった!");
static const u8 sText_SoothingAroma[] = _("{JPN}こころちよい かおりが\nただよった!");
static const u8 sText_ItemsCantBeUsedNow[] = _("{JPN}いまは どうぐを つかえない。{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}には\n{B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nはりきりだした!");
static const u8 sText_PkmnLostFocus[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は しゅうちゅうが きれて\nわざが だせなかった!");
static const u8 sText_PkmnWasDraggedOut[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nひきずりだされた!\p");
static const u8 sText_TheWallShattered[] = _("{JPN}かべが くだけちった!");
static const u8 sText_ButNoEffect[] = _("{JPN}しかし こうかが なかった!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は つかえる わざが\nなくなった!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は かなしばりで\n{B_CURRENT_MOVE}が だせない!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は いちゃもんで おなじ わざを\nつづけて だせない!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ちょうはつで\n{B_CURRENT_MOVE}が だせない!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ふうじられた\n{B_CURRENT_MOVE}が だせない!\p");
static const u8 sText_PkmnCantUseMoveThroatChop[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は じごくづきで\n{B_CURRENT_MOVE}が だせない!\p");
static const u8 sText_PkmnMadeItRain[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nあめが ふりはじめた!");
static const u8 sText_PkmnRaisedSpeed[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nすばやさが あがった!");
static const u8 sText_PkmnProtectedBy[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nまもられた!");
static const u8 sText_PkmnPreventsUsage[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_ATK_NAME_WITH_PREFIX}は\l{B_CURRENT_MOVE}が だせない!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nHPを かいふくした!");
static const u8 sText_PkmnsXMadeYUseless[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_CURRENT_MOVE}は きかなかった!");
static const u8 sText_PkmnChangedTypeWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_BUFF1}タイプに なった!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}は\nまひを ふせいだ!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}は\nメロメロを ふせいだ!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}は\nどくを ふせいだ!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}は\nこんらんを ふせいだ!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\nほのおの いりょくが あがった!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nふんばっている!");
static const u8 sText_PkmnCutsAttackWith[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\n{B_DEF_NAME_WITH_PREFIX}の こうげきを さげた!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}は\nのうりょくが さがるのを ふせいだ!");
static const u8 sText_PkmnHurtsWith[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_BUFF1}で ダメージを うけた!");
static const u8 sText_PkmnTraced[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_BUFF1}の\n{B_BUFF2}を トレースした!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_EFF_ABILITY}は\nやけどを ふせいだ!");
static const u8 sText_PkmnsXBlocksY[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}が\n{B_CURRENT_MOVE}を ふせいだ!");
static const u8 sText_PkmnsXBlocksY2[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\n{B_CURRENT_MOVE}を ふせいだ!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_ABILITY}で\nHPを すこし かいふくした!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nすなあらしが おきた!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nひざしが つよく なった!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}は\n{B_BUFF1}が さがるのを ふせいだ!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}が\n{B_ATK_NAME_WITH_PREFIX}を メロメロに した!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_CURRENT_MOVE}は きかなかった!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_BUFF1}が なおった!");
static const u8 sText_ItSuckedLiquidOoze[] = _("{JPN}ヘドロえきを\nすいこんだ!");
static const u8 sText_PkmnTransformed[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は へんしんした!");
static const u8 sText_PkmnsXTookAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}が\nこうげきを うけとめた!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{JPN}{B_BUFF1}の {B_LAST_ABILITY}で\nいれかえられない!\p");
static const u8 sText_PreventedFromWorking[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}が\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}の\l{B_BUFF1}を むこうに した!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nきかなかった!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_EFF_ABILITY}は\nひるみを ふせいだ!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_ATK_ABILITY}が\n{B_DEF_NAME_WITH_PREFIX}の\l{B_DEF_ABILITY}を むこうに した!");
static const u8 sText_PkmnsAbilityPreventsAbility[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\n{B_DEF_NAME_WITH_PREFIX}の\l{B_DEF_ABILITY}を むこうに した!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_BUFF1}が なおった!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}は\n{B_EFF_NAME_WITH_PREFIX}に きかなかった!");
const u8 gText_StatSharply[] = _("{JPN}ぐーんと ");
const u8 gText_StatRose[] = _("{JPN}あがった!");
static const u8 sText_StatHarshly[] = _("{JPN}がくっと ");
static const u8 sText_StatFell[] = _("{JPN}さがった!");
static const u8 sText_AttackersStatRose[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("{JPN}{B_LAST_ITEM}で {B_SCR_ACTIVE_NAME_WITH_PREFIX}の\n{B_BUFF1}が {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の のうりょくは\nもう あがらない!");
static const u8 sText_StatsWontDecrease2[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の のうりょくは\nもう さがらない!");
static const u8 sText_CriticalHit[] = _("{JPN}きゅうしょに あたった!");
static const u8 sText_OneHitKO[] = _("{JPN}いちげき ひっさつ!");
static const u8 sText_123Poof[] = _("{JPN}{PLAY_SE SE_BALL_BOUNCE_1}ポカン!\p");
static const u8 sText_AndEllipsis[] = _("{JPN}そして…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("{JPN}ひでんわざは いま\nわすれさせられない。\p");
static const u8 sText_NotVeryEffective[] = _("{JPN}こうかは いまひとつの ようだ…");
static const u8 sText_SuperEffective[] = _("{JPN}こうかは ばつぐんだ!");
static const u8 sText_GotAwaySafely[] = _("{JPN}{PLAY_SE SE_FLEE}うまく にげきれた!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{JPN}{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nにげだした!\p");
static const u8 sText_PkmnFledUsing[] = _("{JPN}{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_ABILITY}で\nにげだした!\p");
static const u8 sText_WildPkmnFled[] = _("{JPN}{PLAY_SE SE_FLEE}やせいの {B_BUFF1}は にげだした!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("{JPN}{B_LINK_OPPONENT1_NAME}に\nかった!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と\n{B_LINK_OPPONENT2_NAME}に かった!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("{JPN}{B_LINK_OPPONENT1_NAME}に\nまけた!");
static const u8 sText_PlayerLostToTwo[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と\n{B_LINK_OPPONENT2_NAME}に まけた!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と\nひきわけた!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と {B_LINK_OPPONENT2_NAME}と\nひきわけた!");
static const u8 sText_WildFled[] = _("{JPN}{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}は にげだした!");
static const u8 sText_TwoWildFled[] = _("{JPN}{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}と\n{B_LINK_OPPONENT2_NAME}は にげだした!");
static const u8 sText_NoRunningFromTrainers[] = _("{JPN}だめだ! トレーナーとの\nバトルからは にげられない!\p");
static const u8 sText_CantEscape[] = _("{JPN}にげられない!\p");
static const u8 sText_DontLeaveBirch[] = _("{JPN}オダマキはかせ: たすけて おいていかないで!\p");
static const u8 sText_ButNothingHappened[] = _("{JPN}しかし なにも おこらなかった!");
static const u8 sText_ButItFailed[] = _("{JPN}しかし うまく きまらなかった!");
static const u8 sText_ItHurtConfusion[] = _("{JPN}わけも わからず じぶんを\nこうげきした!");
static const u8 sText_MirrorMoveFailed[] = _("{JPN}オウムがえしは しっぱいした!");
static const u8 sText_StartedToRain[] = _("{JPN}あめが ふりはじめた!");
static const u8 sText_DownpourStarted[] = _("{JPN}はげしい あめが ふりはじめた!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
static const u8 sText_RainContinues[] = _("{JPN}あめが ふりつづいている。");
static const u8 sText_DownpourContinues[] = _("{JPN}はげしい あめが つづいている。"); // unused
static const u8 sText_RainStopped[] = _("{JPN}あめが あがった。");
static const u8 sText_SandstormBrewed[] = _("{JPN}すなあらしが ふきはじめた!");
static const u8 sText_SandstormRages[] = _("{JPN}すなあらしが ふきあれる。");
static const u8 sText_SandstormSubsided[] = _("{JPN}すなあらしが おさまった。");
static const u8 sText_SunlightGotBright[] = _("{JPN}ひざしが つよく なった!");
static const u8 sText_SunlightStrong[] = _("{JPN}ひざしが つよい。");
static const u8 sText_SunlightFaded[] = _("{JPN}ひざしが よわまった。");
static const u8 sText_StartedHail[] = _("{JPN}あられが ふりはじめた!");
static const u8 sText_HailContinues[] = _("{JPN}あられが ふりつづいている。");
static const u8 sText_HailStopped[] = _("{JPN}あられが やんだ。");
static const u8 sText_StartedSnow[] = _("{JPN}ゆきが ふりはじめた!");
static const u8 sText_SnowContinues[] = _("{JPN}ゆきが ふりつづいている。");
static const u8 sText_SnowStopped[] = _("{JPN}ゆきが やんだ。");
static const u8 sText_FailedToSpitUp[] = _("{JPN}しかし なにも\nはきださなかった!");
static const u8 sText_FailedToSwallow[] = _("{JPN}しかし なにも\nのみこめなかった!");
static const u8 sText_WindBecameHeatWave[] = _("{JPN}かぜは ねっぷうに\nかわった!");
static const u8 sText_StatChangesGone[] = _("{JPN}すべての のうりょくへんかが\nもとに もどった!");
static const u8 sText_CoinsScattered[] = _("{JPN}コインが あたりに ちらばった!");
static const u8 sText_TooWeakForSubstitute[] = _("{JPN}HPが たりなくて みがわりを\nだせなかった!");
static const u8 sText_SharedPain[] = _("{JPN}おたがいの いたみを\nわけあった!");
static const u8 sText_BellChimed[] = _("{JPN}すずの ねいろが ひびいた!");
static const u8 sText_FaintInThree[] = _("{JPN}うたを きいた ポケモンは\n3ターンごに たおれて しまう!");
static const u8 sText_NoPPLeft[] = _("{JPN}この わざは PPが\nのこっていない!\p");
static const u8 sText_ButNoPPLeft[] = _("{JPN}しかし わざの PPが\nのこっていなかった!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ねむったまま\nめいれいを きかない!");
static const u8 sText_PkmnIgnoredOrders[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は めいれいを\nきかない!");
static const u8 sText_PkmnBeganToNap[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は いねむりを はじめた!");
static const u8 sText_PkmnLoafing[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nなまけている!");
static const u8 sText_PkmnWontObey[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は いうことを\nきかない!");
static const u8 sText_PkmnTurnedAway[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は そっぽを むいた!");
static const u8 sText_PkmnPretendNotNotice[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は きづかない ふりを\nした!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}は\n{B_BUFF2}を くりだそうと している。\p{B_PLAYER_NAME}は ポケモンを\nいれかえますか?");
static const u8 sText_PkmnLearnedMove2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}を\nおぼえた!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}に\nかった!\p");
static const u8 sText_CreptCloser[] = _("{JPN}{B_PLAYER_NAME}は {B_OPPONENT_MON1_NAME}に\nそっと ちかづいた!");
static const u8 sText_CantGetCloser[] = _("{JPN}{B_PLAYER_NAME}は これいじょう ちかづけない!");
static const u8 sText_PkmnWatchingCarefully[] = _("{JPN}{B_OPPONENT_MON1_NAME}は じっと\nようすを みている!");
static const u8 sText_PkmnCuriousAboutX[] = _("{JPN}{B_OPPONENT_MON1_NAME}は {B_BUFF1}に\nきょうみを もっている!");
static const u8 sText_PkmnEnthralledByX[] = _("{JPN}{B_OPPONENT_MON1_NAME}は {B_BUFF1}に\nむちゅうだ!");
static const u8 sText_PkmnIgnoredX[] = _("{JPN}{B_OPPONENT_MON1_NAME}は {B_BUFF1}を\nまったく きにしなかった!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{JPN}{B_PLAYER_NAME}は {POKEBLOCK}を\n{B_OPPONENT_MON1_NAME}に なげた!");
static const u8 sText_OutOfSafariBalls[] = _("{JPN}{PLAY_SE SE_DING_DONG}アナウンス: サファリボールが\nなくなりました! しゅうりょうです!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{JPN}{B_OPPONENT_MON1_NAME}が あらわれた!\p");
static const u8 sText_WildPkmnAppeared[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が とびだしてきた!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が とびだしてきた!\p");
static const u8 sText_UniquePkmnAppeared[] = _("{JPN}とくべつな {B_OPPONENT_MON1_NAME}が とびだしてきた!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が とびだしてきた!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}と\n{B_OPPONENT_MON2_NAME}が とびだしてきた!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}が\nしょうぶを しかけてきた!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("{JPN}{B_LINK_OPPONENT1_NAME}が\nしょうぶを しかけてきた!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と {B_LINK_OPPONENT2_NAME}が\nしょうぶを しかけてきた!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}は\n{B_OPPONENT_MON1_NAME}を くりだした!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}は\n{B_OPPONENT_MON1_NAME}と {B_OPPONENT_MON2_NAME}を くりだした!");
const u8 sText_Trainer1SentOutPkmn2[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}は\n{B_BUFF1}を くりだした!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は {B_OPPONENT_MON1_NAME}を\nくりだした!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は {B_OPPONENT_MON1_NAME}と\n{B_OPPONENT_MON2_NAME}を くりだした!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は {B_LINK_OPPONENT_MON1_NAME}を!\n{B_LINK_OPPONENT2_NAME}は {B_LINK_OPPONENT_MON2_NAME}を くりだした!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は {B_BUFF1}を\nくりだした!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{JPN}{B_LINK_SCR_TRAINER_NAME}は {B_BUFF1}を\nくりだした!");
static const u8 sText_GoPkmn[] = _("{JPN}ゆけっ! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("{JPN}ゆけっ! {B_PLAYER_MON1_NAME}と\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("{JPN}ゆけっ! {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("{JPN}それいけ! {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("{JPN}たのむぞ {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("{JPN}あいては よわっている!\nいまだ {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{JPN}{B_LINK_PARTNER_NAME}は {B_LINK_PLAYER_MON2_NAME}を!\nゆけっ! {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("{JPN}{B_BUFF1} もう じゅうぶんだ!\nもどれ!");
static const u8 sText_PkmnComeBack[] = _("{JPN}{B_BUFF1} もどれ!");
static const u8 sText_PkmnOkComeBack[] = _("{JPN}{B_BUFF1} よし!\nもどれ!");
static const u8 sText_PkmnGoodComeBack[] = _("{JPN}{B_BUFF1} よくやった!\nもどれ!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}は\n{B_BUFF1}を もどした!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は {B_BUFF1}を\nもどした!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{JPN}{B_LINK_SCR_TRAINER_NAME}は {B_BUFF1}を\nもどした!");
static const u8 sText_PkmnIsAngry[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は いかっている!");
static const u8 sText_PkmnIsCalm[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の いかりが\nおさまった");
static const u8 sText_PoisonPuppeteer[] = _("{JPN}{B_PLAYER_MON1_NAME}の どくくぐつで\n{B_OPPONENT_MON1_NAME}は こんらんした!");
static const u8 sText_CommanderActivates[] = _("{JPN}{B_BUFF1}は {B_BUFF2}に のみこまれ\n{B_BUFF2}の しれいとうに なった!");
static const u8 sText_WildPkmnPrefix[] = _("{JPN}やせいの ");
static const u8 sText_FoePkmnPrefix[] = _("{JPN}あいての ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("{JPN}あいて");
static const u8 sText_AllyPkmnPrefix[] = _("{JPN}みかた");
static const u8 sText_FoePkmnPrefix3[] = _("{JPN}あいて");
static const u8 sText_AllyPkmnPrefix2[] = _("{JPN}みかた");
static const u8 sText_FoePkmnPrefix4[] = _("{JPN}あいて");
static const u8 sText_AllyPkmnPrefix3[] = _("{JPN}みかた");
static const u8 sText_AttackerUsedX[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の\n{B_BUFF3}!");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP[] = _("{JPN}HP");
static const u8 sText_Attack[] = _("{JPN}こうげき");
static const u8 sText_Defense[] = _("{JPN}ぼうぎょ");
static const u8 sText_Speed[] = _("{JPN}すばやさ");
static const u8 sText_SpAttack[] = _("{JPN}とくこう");
static const u8 sText_SpDefense[] = _("{JPN}とくぼう");
static const u8 sText_Accuracy[] = _("{JPN}めいちゅうりつ");
static const u8 sText_Evasiveness[] = _("{JPN}かいひりつ");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    sText_HP, sText_Attack, sText_Defense,
    sText_Speed, sText_SpAttack, sText_SpDefense,
    sText_Accuracy, sText_Evasiveness
};

static const u8 sText_PokeblockWasTooSpicy[] = _("{JPN}からすぎた!");
static const u8 sText_PokeblockWasTooDry[] = _("{JPN}しぶすぎた!");
static const u8 sText_PokeblockWasTooSweet[] = _("{JPN}あますぎた!");
static const u8 sText_PokeblockWasTooBitter[] = _("{JPN}にがすぎた!");
static const u8 sText_PokeblockWasTooSour[] = _("{JPN}すっぱすぎた!");

const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = _("{JPN}きみは {B_LAST_ITEM}を\nつかった!");
static const u8 sText_WallyUsedItem[] = _("{JPN}ミツルは {B_LAST_ITEM}を\nつかった!");
static const u8 sText_Trainer1UsedItem[] = _("{JPN}{B_ATK_TRAINER_CLASS}の {B_ATK_TRAINER_NAME}は\n{B_LAST_ITEM}を つかった!");
static const u8 sText_TrainerBlockedBall[] = _("{JPN}トレーナーに ボールを はじかれた!");
static const u8 sText_DontBeAThief[] = _("{JPN}ひとの ポケモンを とったら どろぼう!");
static const u8 sText_ItDodgedBall[] = _("{JPN}なげた ボールを かわされた!\nこの ポケモンは つかまえられない!");
static const u8 sText_YouMissedPkmn[] = _("{JPN}ポケモンに あたらなかった!");
static const u8 sText_PkmnBrokeFree[] = _("{JPN}ああ!\nポケモンが でて しまった!");
static const u8 sText_ItAppearedCaught[] = _("{JPN}ああ!\nつかまえたと おもったのに!");
static const u8 sText_AarghAlmostHadIt[] = _("{JPN}ううん!\nもう ちょっとだったのに!");
static const u8 sText_ShootSoClose[] = _("{JPN}ちくしょう!\nおしかったのに!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("{JPN}やった!\n{B_DEF_NAME}を つかまえたぞ!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("{JPN}やった!\n{B_DEF_NAME}を つかまえたぞ!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("{JPN}つかまえた {B_DEF_NAME}に\nニックネームを つけますか?");
static const u8 sText_PkmnSentToPC[] = _("{JPN}{B_DEF_NAME}は\n{B_PC_CREATOR_NAME}パソコンに おくられた。");
static const u8 sText_Someones[] = _("{JPN}だれかの");
static const u8 sText_Lanettes[] = _("{JPN}ラネットの");
static const u8 sText_PkmnDataAddedToDex[] = _("{JPN}{B_DEF_NAME}の データが\nポケモンずかんに とうろくされた。\p");
static const u8 sText_ItIsRaining[] = _("{JPN}あめが ふっている。");
static const u8 sText_SandstormIsRaging[] = _("{JPN}すなあらしが ふきあれている。");
static const u8 sText_BoxIsFull[] = _("{JPN}ボックスが いっぱいだ!\nこれいじょう つかまえられない!\p");
static const u8 sText_EnigmaBerry[] = _("ENIGMA BERRY");
static const u8 sText_BerrySuffix[] = _("{JPN}のみ");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nまひが なおった!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nどくが なおった!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nやけどが なおった!");
static const u8 sText_PkmnsItemHealedFrostbite[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nしもやけが なおった!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nこおりが とけた!");
static const u8 sText_PkmnsItemWokeIt[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nめを さました!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nこんらんが とけた!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\n{B_BUFF1}が なおった!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nじょうたいが もとに もどった!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nたいりょくを かいふくした!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\n{B_BUFF1}の PPを かいふくした!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nじょうたいを かいふくした!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nHPを すこし かいふくした!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{JPN}{B_LAST_ITEM}で {B_CURRENT_MOVE}しか\nつかえない!\p");
static const u8 sText_PkmnHungOnWithX[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nもちこたえた!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("{JPN}いま ボールを なげるんですね?\nぼ ぼく がんばります!");

// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

// New battle strings.
static const u8 sText_EnduredViaSturdy[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nこうげきを もちこたえた!");
static const u8 sText_PowerHerbActivation[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nじゅうでんが かんりょうした!");
static const u8 sText_HurtByItem[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nダメージを うけた!");
static const u8 sText_BadlyPoisonedByItem[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nもうどくを あびた!");
static const u8 sText_BurnedByItem[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nやけどを おった!");
static const u8 sText_TargetAbilityActivates[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}が はつどうした!");
static const u8 sText_GravityIntensified[] = _("{JPN}じゅうりょくが つよく なった!");
static const u8 sText_TargetIdentified[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nみやぶられた!");
static const u8 sText_TargetWokeUp[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は めを さました!");
static const u8 sText_PkmnStoleAndAteItem[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_LAST_ITEM}を うばって たべた!");
static const u8 sText_TailWindBlew[] = _("{JPN}{B_ATK_TEAM2}の うしろから\nおいかぜが ふきはじめた!");
static const u8 sText_PkmnWentBack[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_TRAINER_CLASS}の\n{B_ATK_TRAINER_NAME}の もとへ もどった");
static const u8 sText_PkmnCantUseItemsAnymore[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は もう どうぐを\nつかえない!");
static const u8 sText_PkmnFlung[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ITEM}を\nなげつけた!");
static const u8 sText_PkmnPreventedFromHealing[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は かいふくを\nふうじられた!");
static const u8 sText_PkmnSwitchedAtkAndDef[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は こうげきと ぼうぎょを\nいれかえた!");
static const u8 sText_PkmnsAbilitySuppressed[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の とくせいが\nきかなく なった!");
static const u8 sText_ShieldedFromCriticalHits[] = _("{JPN}{B_CURRENT_MOVE}が {B_ATK_TEAM2}を\nきゅうしょから まもった!");
static const u8 sText_SwitchedAtkAndSpAtk[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は こうげきと とくこうの\nのうりょくへんかを\pあいてと いれかえた!");
static const u8 sText_SwitchedDefAndSpDef[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ぼうぎょと とくぼうの\nのうりょくへんかを\pあいてと いれかえた!");
static const u8 sText_PkmnAcquiredAbility[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}を てに\nいれた!");
static const u8 sText_PoisonSpikesScattered[] = _("{JPN}{B_DEF_TEAM2}の あしもとに\nどくびしが ちらばった!");
static const u8 sText_PkmnSwitchedStatChanges[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと のうりょくへんかを\nいれかえた!");
static const u8 sText_PkmnSurroundedWithVeilOfWater[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は みずの ベールに\nつつまれた!");
static const u8 sText_PkmnLevitatedOnElectromagnetism[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は じりょくで\nうきあがった!");
static const u8 sText_PkmnTwistedDimensions[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は じくうを\nゆがめた!");
static const u8 sText_PointedStonesFloat[] =_("{JPN}{B_DEF_TEAM2}の まわりに\nとがった いわが うかんだ!");
static const u8 sText_CloakedInMysticalMoonlight[] =_("{JPN}しんぴてきな つきのひかりに\nつつまれた!");
static const u8 sText_TrappedBySwirlingMagma[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は うずまく マグマに\nとらわれた!");
static const u8 sText_VanishedInstantly[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}は しゅんじに すがたを\nけした!");
static const u8 sText_ProtectedTeam[] =_("{JPN}{B_CURRENT_MOVE}が {B_ATK_TEAM2}を\nまもった!");
static const u8 sText_SharedItsGuard[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと ぼうぎょを\nわけあった!");
static const u8 sText_SharedItsPower[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと ちからを\nわけあった!");
static const u8 sText_SwapsDefAndSpDefOfAllPkmn[] =_("{JPN}ぼうぎょと とくぼうが いれかわる\nふしぎな くうかんが できた!");
static const u8 sText_BecameNimble[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}は みがるに なった!");
static const u8 sText_HurledIntoTheAir[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は そらへ\nほうりだされた!");
static const u8 sText_HeldItemsLoseEffects[] =_("{JPN}もちものの こうかが なくなる\nふしぎな くうかんが できた!");
static const u8 sText_FellStraightDown[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は まっすぐ\nおちてきた!");
static const u8 sText_TargetChangedType[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_BUFF1}タイプに\nなった!");
static const u8 sText_PkmnAcquiredSimple[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は たんじゅんを てに\nいれた!");
static const u8 sText_KindOffer[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は しんせつを\nうけとった!");
static const u8 sText_ResetsTargetsStatLevels[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}の のうりょくへんかが\nもとに もどった!");
static const u8 sText_AllySwitchPosition[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}と {B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nばしょを いれかえた!");
static const u8 sText_RestoreTargetsHealth[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}の HPが かいふくした!");
static const u8 sText_TookPkmnIntoTheSky[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nそらへ つれさった!");
static const u8 sText_FreedFromSkyDrop[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は フリーフォールから\nかいほうされた!");
static const u8 sText_PostponeTargetMove[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}の わざは あとまわしに\nされた!");
static const u8 sText_ReflectTargetsType[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}の タイプが {B_DEF_NAME_WITH_PREFIX}と\nおなじに なった!");
static const u8 sText_TransferHeldItem[] =_("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_ATK_NAME_WITH_PREFIX}から\n{B_LAST_ITEM}を うけとった");
static const u8 sText_EmbargoEnds[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は また どうぐを\nつかえるように なった!");
static const u8 sText_Electromagnetism[] = _("{JPN}じりょく");
static const u8 sText_BufferEnds[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}の\nこうかが きれた!");
static const u8 sText_ThroatChopEnds[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は また おとの わざを\nつかえるように なった!");
static const u8 sText_TelekinesisEnds[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は テレキネシスから\nかいほうされた!");
static const u8 sText_TailwindEnds[] = _("{JPN}{B_ATK_TEAM1}の おいかぜが\nやんだ!");
static const u8 sText_LuckyChantEnds[] = _("{JPN}{B_ATK_TEAM1}の おまじないの\nこうかが きれた!");
static const u8 sText_TrickRoomEnds[] = _("{JPN}ゆがんだ じくうが もとに\nもどった!");
static const u8 sText_WonderRoomEnds[] = _("{JPN}ワンダールームが きれて ぼうぎょと\nとくぼうが もとに もどった!");
static const u8 sText_MagicRoomEnds[] = _("{JPN}マジックルームが きれて もちものの\nこうかが もとに もどった!");
static const u8 sText_MudSportEnds[] = _("{JPN}どろあそびの こうかが きれた。");
static const u8 sText_WaterSportEnds[] = _("{JPN}みずあそびの こうかが きれた。");
static const u8 sText_GravityEnds[] = _("{JPN}じゅうりょくが もとに もどった!");
static const u8 sText_AquaRingHeal[] = _("{JPN}アクアリングが {B_ATK_NAME_WITH_PREFIX}の\nHPを かいふくした!");
static const u8 sText_TargetAbilityRaisedStat[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_BUFF1}が あがった!");
static const u8 sText_TargetAbilityLoweredStat[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_BUFF1}が さがった!");
static const u8 sText_AttackerAbilityRaisedStat[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_ATK_ABILITY}で\n{B_BUFF1}が あがった!");
static const u8 sText_ScriptingAbilityRaisedStat[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_BUFF1}が あがった!");
static const u8 sText_AuroraVeilEnds[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}の\nこうかが きれた!");
static const u8 sText_ElectricTerrainEnds[] = _("{JPN}でんきが せんじょうから\nきえた。");
static const u8 sText_MistyTerrainEnds[] = _("{JPN}きりが せんじょうから\nきえた。");
static const u8 sText_PsychicTerrainEnds[] = _("{JPN}ふしぎな かんじが せんじょうから\nきえた。");
static const u8 sText_GrassyTerrainEnds[] = _("{JPN}くさが せんじょうから\nきえた。");
static const u8 sText_TargetsStatWasMaxedOut[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_BUFF1}が さいだいに なった!");
static const u8 sText_PoisonHealHpUp[] = _("{JPN}どくで {B_ATK_NAME_WITH_PREFIX}は\nすこし かいふくした!");
static const u8 sText_BadDreamsDmg[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は いちゃもんを つけられている!");
static const u8 sText_MoldBreakerEnters[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は かたやぶりだ!");
static const u8 sText_TeravoltEnters[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は はじける オーラを\nはなっている!");
static const u8 sText_TurboblazeEnters[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は もえたつ オーラを\nはなっている!");
static const u8 sText_SlowStartEnters[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は やるきが でない!");
static const u8 sText_SlowStartEnd[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ようやく やるきを\nだした!");
static const u8 sText_SolarPowerHpDrop[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_ATK_ABILITY}が\nダメージを あたえた!");
static const u8 sText_AftermathDmg[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ダメージを うけた!");
static const u8 sText_AnticipationActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nみぶるいした!");
static const u8 sText_ForewarnActivates[] = _("{JPN}{B_SCR_ACTIVE_ABILITY}が {B_SCR_ACTIVE_NAME_WITH_PREFIX}に\n{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}を おしえた!");
static const u8 sText_IceBodyHpGain[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_ABILITY}で\nすこし かいふくした!");
static const u8 sText_SnowWarningHail[] = _("{JPN}あられが ふりはじめた!");
static const u8 sText_SnowWarningSnow[] = _("{JPN}ゆきが ふりはじめた!");
static const u8 sText_FriskActivates[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_LAST_ITEM}を みやぶった!");
static const u8 sText_UnnerveEnters[] = _("{JPN}あいては きんちょうして\nきのみを たべられない!");
static const u8 sText_HarvestBerry[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ITEM}を\nしゅうかくした!");
static const u8 sText_LastAbilityRaisedBuff1[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_LAST_ABILITY}で\n{B_BUFF1}が あがった!");
static const u8 sText_MagicBounceActivates[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_ATK_NAME_WITH_PREFIX}を\nはねかえした!");
static const u8 sText_ProteanTypeChange[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_ABILITY}で\n{B_BUFF1}タイプに なった!");
static const u8 sText_SymbiosisItemPass[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ABILITY}で {B_LAST_ITEM}を\n{B_ATK_NAME_WITH_PREFIX}に わたした!");
static const u8 sText_StealthRockDmg[] = _("{JPN}とがった いわが {B_SCR_ACTIVE_NAME_WITH_PREFIX}に\nつきささった!");
static const u8 sText_ToxicSpikesAbsorbed[] = _("{JPN}{B_DEF_TEAM2}の あしもとの\nどくびしが きえた!");
static const u8 sText_ToxicSpikesPoisoned[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は どくを あびた!");
static const u8 sText_StickyWebSwitchIn[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は ねばねばネットに\nつかまった!");
static const u8 sText_HealingWishCameTrue[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}に いやしのねがいが\nかなった!");
static const u8 sText_HealingWishHealed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は たいりょくを かいふくした!");
static const u8 sText_LunarDanceCameTrue[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は しんぴてきな つきのひかりに\nつつまれた!");
static const u8 sText_CursedBodyDisabled[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}が ふうじられた!");
static const u8 sText_AttackerAquiredAbility[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_ABILITY}を てに\nいれた!");
static const u8 sText_TargetStatWontGoHigher[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}は\nもう あがらない!");
static const u8 sText_PkmnMoveBouncedViaAbility[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_CURRENT_MOVE}は\n{B_DEF_NAME_WITH_PREFIX}の\l{B_DEF_ABILITY}で はねかえされた!");
static const u8 sText_ImposterTransform[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ABILITY}で\n{B_DEF_NAME_WITH_PREFIX}に へんしんした!");
static const u8 sText_NotDoneYet[] = _("{JPN}この わざの こうかは まだ みじっそうだ!\p");
static const u8 sText_PkmnBlewAwayToxicSpikes[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は どくびしを\nふきとばした!");
static const u8 sText_PkmnBlewAwayStickyWeb[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ねばねばネットを\nふきとばした!");
static const u8 sText_PkmnBlewAwayStealthRock[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ステルスロックを\nふきとばした!");
static const u8 sText_SpikesDisappearedFromTeam[] = _("{JPN}{B_ATK_TEAM2}の あしもとの\nまきびしが きえた!");
static const u8 sText_ToxicSpikesDisappearedFromTeam[] = _("{JPN}{B_ATK_TEAM2}の あしもとの\nどくびしが きえた!");
static const u8 sText_StealthRockDisappearedFromTeam[] = _("{JPN}{B_ATK_TEAM2}の まわりの\nとがった いわが きえた!");
static const u8 sText_StickyWebDisappearedFromTeam[] = _("{JPN}{B_ATK_TEAM2}の あしもとの\nねばねばネットが きえた!");
static const u8 sText_StickyWebUsed[] = _("{JPN}{B_DEF_TEAM2}の あしもとに\nねばねばネットが ひろがった!");
static const u8 sText_QuashSuccess[] = _("{JPN}あいての {B_DEF_NAME_WITH_PREFIX}の わざは\nあとまわしに された!");
static const u8 sText_IonDelugeOn[] = _("{JPN}イオンの あめが せんじょうに\nふりそそぐ!");
static const u8 sText_TopsyTurvySwitchedStats[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の のうりょくへんかが\nすべて ぎゃくに なった!");
static const u8 sText_TerrainBecomesMisty[] = _("{JPN}せんじょうに きりが\nたちこめた!");
static const u8 sText_TerrainBecomesGrassy[] = _("{JPN}せんじょうに くさが\nしげった!");
static const u8 sText_TerrainBecomesElectric[] = _("{JPN}せんじょうに でんきが\nながれた!");
static const u8 sText_TerrainBecomesPsychic[] = _("{JPN}せんじょうが ふしぎな かんじに なった!");
static const u8 sText_TargetElectrified[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の わざが でんきを\nおびた!");
static const u8 sText_AssaultVestDoesntAllow[] = _("{JPN}{B_LAST_ITEM}の こうかで へんかわざが\nつかえない!\p");
static const u8 sText_GravityPreventsUsage[] = _("{JPN}じゅうりょくで {B_ATK_NAME_WITH_PREFIX}は\n{B_CURRENT_MOVE}が つかえない!\p");
static const u8 sText_HealBlockPreventsUsage[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は かいふくを\nふうじられた!\p");
static const u8 sText_MegaEvoReacting[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_LAST_ITEM}が\n{B_ATK_TRAINER_NAME}の メガリングに はんのうした!");
static const u8 sText_FerventWishReached[] = _("{JPN}{B_ATK_TRAINER_NAME}の つよい おもいが\n{B_ATK_NAME_WITH_PREFIX}に とどいた!");
static const u8 sText_MegaEvoEvolved[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は メガシンカして\nメガ{B_BUFF1}に なった!");
static const u8 sText_drastically[] = _("{JPN}ぐぐーんと ");
static const u8 sText_severely[] = _("{JPN}がくーんと ");
static const u8 sText_Infestation[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}に よって {B_DEF_NAME_WITH_PREFIX}は\nまとわりつかれた!");
static const u8 sText_NoEffectOnTarget[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}には こうかが\nなかった!");
static const u8 sText_BurstingFlames[] = _("{JPN}はじける ほのおが {B_SCR_ACTIVE_NAME_WITH_PREFIX}に\nおそいかかった!");
static const u8 sText_BestowItemGiving[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_ATK_NAME_WITH_PREFIX}から\n{B_LAST_ITEM}を うけとった!");
static const u8 sText_ThirdTypeAdded[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}に {B_BUFF1}タイプが\nくわわった!");
static const u8 sText_FellForFeint[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は フェイントに\nひっかかった!");
static const u8 sText_PokemonCannotUseMove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_CURRENT_MOVE}を\nつかえない!");
static const u8 sText_CoveredInPowder[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は こなに つつまれた!");
static const u8 sText_PowderExplodes[] = _("{JPN}ほのおが こなに ふれて\nばくはつした!");
static const u8 sText_BelchCantUse[] = _("{JPN}ゲップは つかえない!\p");
static const u8 sText_SpectralThiefSteal[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいての あがった\nのうりょくを うばった!");
static const u8 sText_GravityGrounding[] = _("{JPN}じゅうりょくで {B_DEF_NAME_WITH_PREFIX}は\nそらに いられない!");
static const u8 sText_MistyTerrainPreventsStatus[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は まもりの きりに\nつつまれた!");
static const u8 sText_GrassyTerrainHeals[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は グラスフィールドで\nかいふくした!");
static const u8 sText_ElectricTerrainPreventsSleep[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は エレキフィールドに\nつつまれた!");
static const u8 sText_PsychicTerrainPreventsPriority[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は サイコフィールドに\nつつまれた!");
static const u8 sText_SafetyGogglesProtected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_LAST_ITEM}の おかげで\nえいきょうを うけない!");
static const u8 sText_FlowerVeilProtected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は はなびらの ベールに\nつつまれた!");
static const u8 sText_SweetVeilProtected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は あまい ベールに\nつつまれた!");
static const u8 sText_AromaVeilProtected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は アロマベールに\nまもられている!");
static const u8 sText_CelebrateMessage[] = _("{JPN}おめでとう {B_PLAYER_NAME}!");
static const u8 sText_UsedInstructedMove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}に\nしじされた わざを つかった!");
static const u8 sText_LaserFocusMessage[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nしゅうちゅうしている!");
static const u8 sText_GemActivates[] = _("{JPN}{B_LAST_ITEM}が {B_ATK_NAME_WITH_PREFIX}の\nいりょくを たかめた!");
static const u8 sText_BerryDmgReducing[] = _("{JPN}{B_LAST_ITEM}が {B_DEF_NAME_WITH_PREFIX}への\nダメージを よわめた!");
static const u8 sText_TargetAteItem[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_LAST_ITEM}を たべた!");
static const u8 sText_AirBalloonFloat[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nそらに うかんでいる!");
static const u8 sText_AirBalloonPop[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_LAST_ITEM}が はじけた!");
static const u8 sText_IncinerateBurn[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_LAST_ITEM}が\nやけて しまった!");
static const u8 sText_BugBite[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_EFF_NAME_WITH_PREFIX}の\n{B_LAST_ITEM}を うばって たべた!");
static const u8 sText_IllusionWoreOff[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の イリュージョンが とけた!");
static const u8 sText_AttackerCuredTargetStatus[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\nじょうたいを なおした!");
static const u8 sText_AttackerLostFireType[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は もえつきた!");
static const u8 sText_HealerCure[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_LAST_ABILITY}が\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}の じょうたいを なおした!");
static const u8 sText_ReceiverAbilityTakeOver[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}が\nうばわれた!");
static const u8 sText_PkmnAbsorbingPower[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ちからを すいとっている!");
static const u8 sText_NoOneWillBeAbleToRun[] = _("{JPN}つぎの ターンは だれも\nにげられなく なった!");
static const u8 sText_DestinyKnotActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nメロメロに なった!");
static const u8 sText_CloakedInAFreezingLight[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は こおりつく ひかりに\nつつまれた!");
static const u8 sText_ClearAmuletWontLowerStats[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_LAST_ITEM}が のうりょくが\nさがるのを ふせいだ!");
static const u8 sText_AuraFlaredToLife[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の オーラが もえあがった!");
static const u8 sText_AirLockActivates[] = _("{JPN}てんきの こうかが\nきえた。");
static const u8 sText_PressureActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は プレッシャーを\nだしている!");
static const u8 sText_DarkAuraActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は あくの オーラを\nはなっている!");
static const u8 sText_FairyAuraActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は フェアリーの オーラを\nはなっている!");
static const u8 sText_AuraBreakActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は ほかの ポケモンの\nオーラを ぎゃくてんさせた!");
static const u8 sText_ComatoseActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は うとうと している!");
static const u8 sText_ScreenCleanerActivates[] = _("{JPN}せんじょうの かべが すべて\nきえた!");
static const u8 sText_FetchedPokeBall[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}を\nみつけた!");
static const u8 sText_BattlerAbilityRaisedStat[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_BUFF1}が あがった!");
static const u8 sText_ASandstormKickedUp[] = _("{JPN}すなあらしが ふきはじめた!");
static const u8 sText_PkmnsWillPerishIn3Turns[] = _("{JPN}どちらの ポケモンも 3ターンごに\nたおれて しまう!");
static const u8 sText_AbilityRaisedStatDrastically[] = _("{JPN}{B_DEF_ABILITY}で {B_DEF_NAME_WITH_PREFIX}の\n{B_BUFF1}が ぐぐーんと あがった!");
static const u8 sText_AsOneEnters[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は とくせいを ふたつ もっている!");
static const u8 sText_PkmnMadeShellGleam[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の からが かがやいた!\nタイプの あいしょうが ゆがむ!");
static const u8 sText_CuriousMedicineEnters[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の のうりょくへんかが\nもとに もどった!");
static const u8 sText_CanActFaster[] = _("{JPN}{B_BUFF1}の おかげで {B_ATK_NAME_WITH_PREFIX}は\nはやく うごける!");
static const u8 sText_MicleBerryActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で つぎの わざの\nめいちゅうを たかめた!");
static const u8 sText_PkmnShookOffTheTaunt[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は ちょうはつから\nたちなおった!");
static const u8 sText_PkmnGotOverItsInfatuation[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の メロメロが\nなおった!");
static const u8 sText_ZPowerSurrounds[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は Zパワーに\nつつまれた!");
static const u8 sText_ZPowerUnleashed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ぜんりょくの Zワザを\nはなった!");
static const u8 sText_ZMoveResetsStats[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は Zパワーで\nさがった のうりょくを\lもとに もどした!");
static const u8 sText_ZMoveAllStatsUp[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は Zパワーで すべての\nのうりょくを あげた!");
static const u8 sText_ZMoveBoostCrit[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は Zパワーで きゅうしょに\nあたりやすく なった!");
static const u8 sText_ZMoveRestoreHp[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は Zパワーで HPを\nかいふくした!");
static const u8 sText_ZMoveStatUp[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は Zパワーで のうりょくを\nあげた!");
static const u8 sText_ZMoveHpSwitchInTrap[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の HPが Zパワーで かいふくした!");
static const u8 sText_TerrainReturnedToNormal[] = _("{JPN}フィールドが もとに\nもどった!");
static const u8 sText_ItemCannotBeRemoved[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の どうぐは はずせない!");
static const u8 sText_StickyBarbTransfer[] = _("{JPN}{B_LAST_ITEM}が {B_ATK_NAME_WITH_PREFIX}に\nくっついた!");
static const u8 sText_PkmnBurnHealed[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の やけどが\nなおった。");
static const u8 sText_RedCardActivate[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_ATK_NAME_WITH_PREFIX}に むけて\n{B_LAST_ITEM}を かかげた!");
static const u8 sText_EjectButtonActivate[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nこうたいした!");
static const u8 sText_AttackerGotOverInfatuation[] =_("{JPN}{B_ATK_NAME_WITH_PREFIX}の メロメロが\nなおった!");
static const u8 sText_TormentedNoMore[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の いちゃもんが\nとけた!");
static const u8 sText_HealBlockedNoMore[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の かいふくふうじが\nとけた!");
static const u8 sText_AttackerBecameFullyCharged[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は トレーナーとの きずなで\nじゅうでんが かんりょうした!\p");
static const u8 sText_AttackerBecameAshSpecies[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は サトシ{B_BUFF1}に なった!\p");
static const u8 sText_ExtremelyHarshSunlight[] = _("{JPN}ひざしが とても つよく\nなった!");
static const u8 sText_ExtremeSunlightFaded[] = _("{JPN}つよい ひざしが おさまった。{PAUSE 64}");
static const u8 sText_MoveEvaporatedInTheHarshSunlight[] = _("{JPN}みずタイプの こうげきは つよい\nひざしで じょうはつした!");
static const u8 sText_ExtremelyHarshSunlightWasNotLessened[] = _("{JPN}つよい ひざしは まったく\nよわまらなかった!");
static const u8 sText_HeavyRain[] = _("{JPN}つよい あめが ふりはじめた!");
static const u8 sText_HeavyRainLifted[] = _("{JPN}つよい あめが あがった!{PAUSE 64}");
static const u8 sText_MoveFizzledOutInTheHeavyRain[] = _("{JPN}ほのおタイプの こうげきは つよい\nあめで きえて しまった!");
static const u8 sText_NoReliefFromHeavyRain[] = _("{JPN}つよい あめは\nやみそうにない!");
static const u8 sText_MysteriousAirCurrent[] = _("{JPN}ふしぎな きりゅうが ひこうタイプの\nポケモンを まもっている!");
static const u8 sText_StrongWindsDissipated[] = _("{JPN}ふしぎな つよい かぜが\nやんだ!{PAUSE 64}");
static const u8 sText_MysteriousAirCurrentBlowsOn[] = _("{JPN}ふしぎな きりゅうは\nふきつづけている!");
static const u8 sText_AttackWeakenedByStrongWinds[] = _("{JPN}ふしぎな つよい かぜが\nこうげきを よわめた!");
static const u8 sText_StuffCheeksCantSelect[] = _("{JPN}きのみが ないと ほおばるは\nえらべない!\p");
static const u8 sText_PkmnRevertedToPrimal[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の げんしかいき!\nげんしの すがたに もどった!");
static const u8 sText_ButPokemonCantUseTheMove[] = _("{JPN}しかし {B_ATK_NAME_WITH_PREFIX}は\nその わざを つかえない!");
static const u8 sText_ButHoopaCantUseIt[] = _("{JPN}しかし フーパは いまの すがたでは\nつかえない!");
static const u8 sText_BrokeThroughProtection[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の まもりを\nつきやぶった!");
static const u8 sText_AbilityAllowsOnlyMove[] = _("{JPN}{B_ATK_ABILITY}で {B_CURRENT_MOVE}しか\nつかえない!\p");
static const u8 sText_SwappedAbilities[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は あいてと とくせいを\nいれかえた!");
static const u8 sText_PastelVeilProtected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は パステルベールに\nまもられている!");
static const u8 sText_PastelVeilEnters[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の どくが\nなおった!");
static const u8 sText_BattlerTypeChangedTo[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の タイプが {B_BUFF1}に\nなった!");
static const u8 sText_BothCanNoLongerEscape[] = _("{JPN}どちらの ポケモンも にげられない!");
static const u8 sText_CantEscapeDueToUsedMove[] = _("{JPN}{B_CURRENT_MOVE}を つかったので\n{B_ATK_NAME_WITH_PREFIX}は もう にげられない!");
static const u8 sText_PkmnBecameWeakerToFire[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は ほのおに よわく\nなった!");
static const u8 sText_PkmnAboutToBeAttackedByItsItem[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_BUFF1}に\nおそわれようと している!");
static const u8 sText_CantEscapeBecauseOfCurrentMove[] = _("{JPN}{B_CURRENT_MOVE}の せいで\n{B_DEF_NAME_WITH_PREFIX}は もう にげられない!");
static const u8 sText_NeutralizingGasEnters[] = _("{JPN}かがくへんかガスが あたりに みちた!");
static const u8 sText_NeutralizingGasOver[] = _("{JPN}かがくへんかガスの こうかが\nきれた!");
static const u8 sText_PkmnTookTargetHigh[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nそらへ つれさった!");
static const u8 sText_TargetTooHeavy[] = _("{JPN}しかし あいてが\nおもすぎた!");
static const u8 sText_MeteorBeamCharging[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は うちゅうの エネルギーで\nあふれている!");
static const u8 sText_HeatingUpBeak[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は くちばしを\nあたためはじめた!");
static const u8 sText_CourtChange[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は りょうがわの こうかを\nいれかえた!");
static const u8 sText_AttackerExpelledThePoison[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は どくを\nはきだした!");
static const u8 sText_AttackerShookItselfAwake[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は みぶるいして めを さました!");
static const u8 sText_AttackerBrokeThroughParalysis[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ちからを ふりしぼって\nまひを のりこえた!");
static const u8 sText_AttackerHealedItsBurn[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は きあいで やけどを\nなおした!");
static const u8 sText_AttackerHealedItsFrostbite[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は きあいで しもやけを\nなおした!");
static const u8 sText_AttackerMeltedTheIce[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は もえる きあいで\nこおりを とかした!");
static const u8 sText_TargetToughedItOut[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は いいところを みせようと\nふんばった!");
static const u8 sText_AttackerLostElectricType[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は でんきを\nつかいきった!");
static const u8 sText_AttackerSwitchedStatWithTarget[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと {B_BUFF1}を\nいれかえた!");
static const u8 sText_BeingHitChargedPkmnWithPower[] = _("{JPN}{B_CURRENT_MOVE}を うけて {B_DEF_NAME_WITH_PREFIX}に\nちからが たまった!");
static const u8 sText_SunlightActivatedAbility[] = _("{JPN}つよい ひざしで {B_SCR_ACTIVE_NAME_WITH_PREFIX}の\n{B_LAST_ABILITY}が はつどうした!");
static const u8 sText_StatWasHeightened[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_BUFF1}が たかまった!");
static const u8 sText_BoosterEnergyActivates[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の ブーストエナジーで\n{B_SCR_ACTIVE_ABILITY}が はつどうした!");
static const u8 sText_ElectricTerrainActivatedAbility[] = _("{JPN}エレキフィールドで {B_SCR_ACTIVE_NAME_WITH_PREFIX}の\n{B_LAST_ABILITY}が はつどうした!");
static const u8 sText_AbilityWeakenedSurroundingMonsStat[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_ATK_ABILITY}が まわりの\nポケモンの {B_BUFF1}を\lよわめた!\p");
static const u8 sText_AttackerGainedStrengthFromTheFallen[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は たおれた なかまから\nちからを もらった!");
static const u8 sText_PrepareShellTrap[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は カラのわなを しかけた!");
static const u8 sText_ShellTrapDidntWork[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の カラのわなは しっぱいした!");
static const u8 sText_SharpSteelFloats[] = _("{JPN}{B_DEF_TEAM2}の まわりに\nとがった はがねが うかんだ!");
static const u8 sText_SharpSteelDmg[] = _("{JPN}とがった はがねが {B_DEF_NAME_WITH_PREFIX}に つきささった!");
static const u8 sText_PkmnBlewAwaySharpSteel[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は とがった はがねを\nふきとばした!");
static const u8 sText_SharpSteelDisappearedFromTeam[] = _("{JPN}{B_ATK_TEAM2}の あしもとの\nとがった はがねが きえた!");
static const u8 sText_TeamTrappedWithVines[] = _("{JPN}{B_DEF_TEAM1}は つるに\nとらわれた!");
static const u8 sText_PkmnHurtByVines[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は キョダイコウジンの\nダメージを うけた!");
static const u8 sText_TeamCaughtInVortex[] = _("{JPN}{B_DEF_TEAM1}は みずの うずに\nとらわれた!");
static const u8 sText_PkmnHurtByVortex[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は キョダイホウゲキの\nダメージを うけた!");
static const u8 sText_TeamSurroundedByFire[] = _("{JPN}{B_DEF_TEAM1}は ほのおに\nつつまれた!");
static const u8 sText_PkmnBurningUp[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は キョダイゴクエンの\nダメージを うけた!");
static const u8 sText_TeamSurroundedByRocks[] = _("{JPN}{B_DEF_TEAM1}は いわに\nかこまれた!");
static const u8 sText_PkmnHurtByRocksThrown[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は キョダイフンセキの\nダメージを うけた!");
static const u8 sText_CouldntFullyProtect[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は まもりきれずに\nダメージを うけた!");
static const u8 sText_StockpiledEffectWoreOff[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の たくわえるの こうかが\nきれた!");
static const u8 sText_MoveBlockedByDynamax[] = _("{JPN}ダイマックスの ちからで\nわざが ふせがれた!");
static const u8 sText_PkmnRevivedReadyToFight[] = _("{JPN}{B_BUFF1}は いきかえって\nまた たたかえるように なった!");
static const u8 sText_ItemRestoredSpeciesHealth[] = _("{JPN}{B_BUFF1}の HPが\nかいふくした!");
static const u8 sText_ItemCuredSpeciesStatus[] = _("{JPN}{B_BUFF1}の じょうたいが\nなおった!");
static const u8 sText_ItemRestoredSpeciesPP[] = _("{JPN}{B_BUFF1}の PPが\nかいふくした!");
static const u8 sText_AtkTrappedDef[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nとらえた!");
static const u8 sText_MirrorHerbCopied[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で あいての\nのうりょくへんかを うつしとった!");
static const u8 sText_PkmnItemMelted[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_LAST_ITEM}を とかした!");
static const u8 sText_UltraBurstReacting[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}から まばゆい ひかりが\nあふれだそうと している!");
static const u8 sText_UltraBurstCompleted[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ウルトラバーストで\nほんとうの ちからを とりもどした!");
static const u8 sText_TeamGainedEXP[] = _("{JPN}{B_LAST_ITEM}の おかげで ほかの てもちも\nけいけんちを もらった!\p");
static const u8 sText_CurrentMoveCantSelect[] = _("{JPN}{B_BUFF1}は つかえない!\p");
static const u8 sText_TargetIsBeingSaltCured[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は しおづけに されている!");
static const u8 sText_TargetIsHurtBySaltCure[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_BUFF1}の ダメージを うけた!");
static const u8 sText_OpportunistCopied[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は あいての のうりょくへんかを\nコピーした!");
static const u8 sText_TargetCoveredInStickyCandySyrup[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は ねばつく シロップに\nつつまれた!");
static const u8 sText_PkmnTellChillingReceptionJoke[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は さむい ジョークの\nじゅんびを している!");
static const u8 sText_ZeroToHeroTransformation[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は えいゆうの すがたに\nなった!");
static const u8 sText_TheTwoMovesBecomeOne[] = _("{JPN}ふたつの わざが ひとつに!\nあわせわざだ!{PAUSE 16}");
static const u8 sText_ARainbowAppearedOnSide[] = _("{JPN}{B_ATK_TEAM2}の そらに\nにじが かかった!");
static const u8 sText_TheRainbowDisappeared[] = _("{JPN}{B_ATK_TEAM2}がわの にじが\nきえた!");
static const u8 sText_WaitingForPartnersMove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_PARTNER_NAME}の\nわざを まっている…{PAUSE 16}");
static const u8 sText_SeaOfFireEnvelopedSide[] = _("{JPN}{B_DEF_TEAM2}は ひのうみに\nつつまれた!");
static const u8 sText_HurtByTheSeaOfFire[] = _("{JPN}{B_ATK_TEAM1}の {B_ATK_NAME_WITH_PREFIX}は\nひのうみの ダメージを うけた!");
static const u8 sText_TheSeaOfFireDisappeared[] = _("{JPN}{B_ATK_TEAM2}の ひのうみが\nきえた!");
static const u8 sText_SwampEnvelopedSide[] = _("{JPN}{B_DEF_TEAM2}は ぬまに\nつつまれた!");
static const u8 sText_TheSwampDisappeared[] = _("{JPN}{B_ATK_TEAM2}の ぬまが\nきえた!");
static const u8 sText_ShedItsTail[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は しっぽを きりはなして\nおとりを つくった!");
static const u8 sText_TidyingUpComplete[] = _("{JPN}おかたづけ かんりょう!");
static const u8 sText_HospitalityRestoration[] = _("{JPN}{B_ATK_PARTNER_NAME}は {B_ATK_NAME_WITH_PREFIX}の\nつくった まっちゃを のみほした!");
static const u8 sText_SupersweetAromaWafts[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}を つつむ シロップから\nあまい かおりが ただよう!");
static const u8 sText_PkmnTerastallizedInto[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}タイプに\nテラスタルした!");
static const u8 sText_ElectroShotCharging[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は でんきを\nきゅうしゅうした!");

const u8 *const gBattleStringsTable[BATTLESTRINGS_COUNT] =
{
    [STRINGID_PKMNTERASTALLIZEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTerastallizedInto,
    [STRINGID_SUPERSWEETAROMAWAFTS - BATTLESTRINGS_TABLE_START] = sText_SupersweetAromaWafts,
    [STRINGID_HOSPITALITYRESTORATION - BATTLESTRINGS_TABLE_START] = sText_HospitalityRestoration,
    [STRINGID_TIDYINGUPCOMPLETE - BATTLESTRINGS_TABLE_START] = sText_TidyingUpComplete,
    [STRINGID_SHEDITSTAIL - BATTLESTRINGS_TABLE_START] = sText_ShedItsTail,
    [STRINGID_THESWAMPDISAPPEARED - BATTLESTRINGS_TABLE_START] = sText_TheSwampDisappeared,
    [STRINGID_SWAMPENVELOPEDSIDE - BATTLESTRINGS_TABLE_START] = sText_SwampEnvelopedSide,
    [STRINGID_THESEAOFFIREDISAPPEARED - BATTLESTRINGS_TABLE_START] = sText_TheSeaOfFireDisappeared,
    [STRINGID_HURTBYTHESEAOFFIRE - BATTLESTRINGS_TABLE_START] = sText_HurtByTheSeaOfFire,
    [STRINGID_SEAOFFIREENVELOPEDSIDE - BATTLESTRINGS_TABLE_START] = sText_SeaOfFireEnvelopedSide,
    [STRINGID_WAITINGFORPARTNERSMOVE - BATTLESTRINGS_TABLE_START] = sText_WaitingForPartnersMove,
    [STRINGID_THERAINBOWDISAPPEARED - BATTLESTRINGS_TABLE_START] = sText_TheRainbowDisappeared,
    [STRINGID_ARAINBOWAPPEAREDONSIDE - BATTLESTRINGS_TABLE_START] = sText_ARainbowAppearedOnSide,
    [STRINGID_THETWOMOVESBECOMEONE - BATTLESTRINGS_TABLE_START] = sText_TheTwoMovesBecomeOne,
    [STRINGID_ZEROTOHEROTRANSFORMATION - BATTLESTRINGS_TABLE_START] = sText_ZeroToHeroTransformation,
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE - BATTLESTRINGS_TABLE_START] = sText_PkmnTellChillingReceptionJoke,
    [STRINGID_MOVEBLOCKEDBYDYNAMAX - BATTLESTRINGS_TABLE_START] = sText_MoveBlockedByDynamax,
    [STRINGID_OPPORTUNISTCOPIED - BATTLESTRINGS_TABLE_START] = sText_OpportunistCopied,
    [STRINGID_TARGETISHURTBYSALTCURE - BATTLESTRINGS_TABLE_START] = sText_TargetIsHurtBySaltCure,
    [STRINGID_TARGETISBEINGSALTCURED - BATTLESTRINGS_TABLE_START] = sText_TargetIsBeingSaltCured,
    [STRINGID_CURRENTMOVECANTSELECT - BATTLESTRINGS_TABLE_START] = sText_CurrentMoveCantSelect,
    [STRINGID_PKMNITEMMELTED - BATTLESTRINGS_TABLE_START] = sText_PkmnItemMelted,
    [STRINGID_MIRRORHERBCOPIED - BATTLESTRINGS_TABLE_START] = sText_MirrorHerbCopied,
    [STRINGID_THUNDERCAGETRAPPED - BATTLESTRINGS_TABLE_START] = sText_AtkTrappedDef,
    [STRINGID_ITEMRESTOREDSPECIESHEALTH - BATTLESTRINGS_TABLE_START] = sText_ItemRestoredSpeciesHealth,
    [STRINGID_ITEMCUREDSPECIESSTATUS - BATTLESTRINGS_TABLE_START] = sText_ItemCuredSpeciesStatus,
    [STRINGID_ITEMRESTOREDSPECIESPP - BATTLESTRINGS_TABLE_START] = sText_ItemRestoredSpeciesPP,
    [STRINGID_PKMNREVIVEDREADYTOFIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnRevivedReadyToFight,
    [STRINGID_STOCKPILEDEFFECTWOREOFF - BATTLESTRINGS_TABLE_START] = sText_StockpiledEffectWoreOff,
    [STRINGID_COULDNTFULLYPROTECT - BATTLESTRINGS_TABLE_START] = sText_CouldntFullyProtect,
    [STRINGID_PKMNHURTBYROCKSTHROWN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByRocksThrown,
    [STRINGID_TEAMSURROUNDEDBYROCKS - BATTLESTRINGS_TABLE_START] = sText_TeamSurroundedByRocks,
    [STRINGID_PKMNBURNINGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnBurningUp,
    [STRINGID_TEAMSURROUNDEDBYFIRE - BATTLESTRINGS_TABLE_START] = sText_TeamSurroundedByFire,
    [STRINGID_PKMNHURTBYVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByVortex,
    [STRINGID_TEAMCAUGHTINVORTEX - BATTLESTRINGS_TABLE_START] = sText_TeamCaughtInVortex,
    [STRINGID_PKMNHURTBYVINES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByVines,
    [STRINGID_TEAMTRAPPEDWITHVINES - BATTLESTRINGS_TABLE_START] = sText_TeamTrappedWithVines,
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySharpSteel,
    [STRINGID_SHARPSTEELDMG - BATTLESTRINGS_TABLE_START] = sText_SharpSteelDmg,
    [STRINGID_SHARPSTEELFLOATS - BATTLESTRINGS_TABLE_START] = sText_SharpSteelFloats,
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN - BATTLESTRINGS_TABLE_START] = sText_AttackerGainedStrengthFromTheFallen,
    [STRINGID_ABILITYWEAKENEDFSURROUNDINGMONSSTAT - BATTLESTRINGS_TABLE_START] = sText_AbilityWeakenedSurroundingMonsStat,
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainActivatedAbility,
    [STRINGID_STATWASHEIGHTENED - BATTLESTRINGS_TABLE_START] = sText_StatWasHeightened,
    [STRINGID_SUNLIGHTACTIVATEDABILITY - BATTLESTRINGS_TABLE_START] = sText_SunlightActivatedAbility,
    [STRINGID_POISONPUPPETEER - BATTLESTRINGS_TABLE_START] = sText_PoisonPuppeteer,
    [STRINGID_BOOSTERENERGYACTIVATES - BATTLESTRINGS_TABLE_START] = sText_BoosterEnergyActivates,
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER - BATTLESTRINGS_TABLE_START] = sText_BeingHitChargedPkmnWithPower,
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET - BATTLESTRINGS_TABLE_START] = sText_AttackerSwitchedStatWithTarget,
    [STRINGID_TARGETTOUGHEDITOUT - BATTLESTRINGS_TABLE_START] = sText_TargetToughedItOut,
    [STRINGID_ATTACKERMELTEDTHEICE - BATTLESTRINGS_TABLE_START] = sText_AttackerMeltedTheIce,
    [STRINGID_ATTACKERHEALEDITSBURN - BATTLESTRINGS_TABLE_START] = sText_AttackerHealedItsBurn,
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_AttackerBrokeThroughParalysis,
    [STRINGID_ATTACKERSHOOKITSELFAWAKE - BATTLESTRINGS_TABLE_START] = sText_AttackerShookItselfAwake,
    [STRINGID_ATTACKEREXPELLEDTHEPOISON - BATTLESTRINGS_TABLE_START] = sText_AttackerExpelledThePoison,
    [STRINGID_ZPOWERSURROUNDS - BATTLESTRINGS_TABLE_START] = sText_ZPowerSurrounds,
    [STRINGID_ZMOVEUNLEASHED - BATTLESTRINGS_TABLE_START] = sText_ZPowerUnleashed,
    [STRINGID_ZMOVERESETSSTATS - BATTLESTRINGS_TABLE_START] = sText_ZMoveResetsStats,
    [STRINGID_ZMOVEALLSTATSUP - BATTLESTRINGS_TABLE_START] = sText_ZMoveAllStatsUp,
    [STRINGID_ZMOVEZBOOSTCRIT - BATTLESTRINGS_TABLE_START] = sText_ZMoveBoostCrit,
    [STRINGID_ZMOVERESTOREHP - BATTLESTRINGS_TABLE_START] = sText_ZMoveRestoreHp,
    [STRINGID_ZMOVESTATUP - BATTLESTRINGS_TABLE_START] = sText_ZMoveStatUp,
    [STRINGID_ZMOVEHPTRAP - BATTLESTRINGS_TABLE_START] = sText_ZMoveHpSwitchInTrap,
    [STRINGID_PLAYERLOSTTOENEMYTRAINER - BATTLESTRINGS_TABLE_START] = sText_PlayerLostToEnemyTrainer,
    [STRINGID_PLAYERPAIDPRIZEMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPaidPrizeMoney,
    [STRINGID_SHELLTRAPDIDNTWORK - BATTLESTRINGS_TABLE_START] = sText_ShellTrapDidntWork,
    [STRINGID_PREPARESHELLTRAP - BATTLESTRINGS_TABLE_START] = sText_PrepareShellTrap,
    [STRINGID_COURTCHANGE - BATTLESTRINGS_TABLE_START] = sText_CourtChange,
    [STRINGID_HEATUPBEAK - BATTLESTRINGS_TABLE_START] = sText_HeatingUpBeak,
    [STRINGID_METEORBEAMCHARGING - BATTLESTRINGS_TABLE_START] = sText_MeteorBeamCharging,
    [STRINGID_ELECTROSHOTCHARGING - BATTLESTRINGS_TABLE_START] = sText_ElectroShotCharging,
    [STRINGID_PKMNINSNAPTRAP - BATTLESTRINGS_TABLE_START] = sText_PkmnInSnapTrap,
    [STRINGID_NEUTRALIZINGGASOVER - BATTLESTRINGS_TABLE_START] = sText_NeutralizingGasOver,
    [STRINGID_NEUTRALIZINGGASENTERS - BATTLESTRINGS_TABLE_START] = sText_NeutralizingGasEnters,
    [STRINGID_BATTLERTYPECHANGEDTO - BATTLESTRINGS_TABLE_START] = sText_BattlerTypeChangedTo,
    [STRINGID_PASTELVEILENTERS - BATTLESTRINGS_TABLE_START] = sText_PastelVeilEnters,
    [STRINGID_PASTELVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_PastelVeilProtected,
    [STRINGID_SWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_SwappedAbilities,
    [STRINGID_ABILITYALLOWSONLYMOVE - BATTLESTRINGS_TABLE_START] = sText_AbilityAllowsOnlyMove,
    [STRINGID_BROKETHROUGHPROTECTION - BATTLESTRINGS_TABLE_START] = sText_BrokeThroughProtection,
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE - BATTLESTRINGS_TABLE_START] = sText_ButPokemonCantUseTheMove,
    [STRINGID_BUTHOOPACANTUSEIT - BATTLESTRINGS_TABLE_START] = sText_ButHoopaCantUseIt,
    [STRINGID_PKMNREVERTEDTOPRIMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnRevertedToPrimal,
    [STRINGID_STUFFCHEEKSCANTSELECT - BATTLESTRINGS_TABLE_START] = sText_StuffCheeksCantSelect,
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS - BATTLESTRINGS_TABLE_START] = sText_AttackWeakenedByStrongWinds,
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON - BATTLESTRINGS_TABLE_START] = sText_MysteriousAirCurrentBlowsOn,
    [STRINGID_STRONGWINDSDISSIPATED - BATTLESTRINGS_TABLE_START] = sText_StrongWindsDissipated,
    [STRINGID_MYSTERIOUSAIRCURRENT - BATTLESTRINGS_TABLE_START] = sText_MysteriousAirCurrent,
    [STRINGID_NORELIEFROMHEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_NoReliefFromHeavyRain,
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_MoveFizzledOutInTheHeavyRain,
    [STRINGID_HEAVYRAINLIFTED - BATTLESTRINGS_TABLE_START] = sText_HeavyRainLifted,
    [STRINGID_HEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_HeavyRain,
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED - BATTLESTRINGS_TABLE_START] = sText_ExtremelyHarshSunlightWasNotLessened,
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_MoveEvaporatedInTheHarshSunlight,
    [STRINGID_EXTREMESUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_ExtremeSunlightFaded,
    [STRINGID_EXTREMELYHARSHSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_ExtremelyHarshSunlight,
    [STRINGID_ATTACKERBECAMEASHSPECIES - BATTLESTRINGS_TABLE_START] = sText_AttackerBecameAshSpecies,
    [STRINGID_ATTACKERBECAMEFULLYCHARGED - BATTLESTRINGS_TABLE_START] = sText_AttackerBecameFullyCharged,
    [STRINGID_HEALBLOCKEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_HealBlockedNoMore,
    [STRINGID_TORMENTEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_TormentedNoMore,
    [STRINGID_ATKGOTOVERINFATUATION - BATTLESTRINGS_TABLE_START] = sText_AttackerGotOverInfatuation,
    [STRINGID_EJECTBUTTONACTIVATE - BATTLESTRINGS_TABLE_START] = sText_EjectButtonActivate,
    [STRINGID_REDCARDACTIVATE - BATTLESTRINGS_TABLE_START] = sText_RedCardActivate,
    [STRINGID_PKMNBURNHEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnHealed,
    [STRINGID_STICKYBARBTRANSFER - BATTLESTRINGS_TABLE_START] = sText_StickyBarbTransfer,
    [STRINGID_ITEMCANNOTBEREMOVED - BATTLESTRINGS_TABLE_START] = sText_ItemCannotBeRemoved,
    [STRINGID_PKMNGOTOVERITSINFATUATION - BATTLESTRINGS_TABLE_START] = sText_PkmnGotOverItsInfatuation,
    [STRINGID_PKMNSHOOKOFFTHETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnShookOffTheTaunt,
    [STRINGID_MICLEBERRYACTIVATES - BATTLESTRINGS_TABLE_START] = sText_MicleBerryActivates,
    [STRINGID_CANACTFASTERTHANKSTO - BATTLESTRINGS_TABLE_START] = sText_CanActFaster,
    [STRINGID_CURIOUSMEDICINEENTERS - BATTLESTRINGS_TABLE_START] = sText_CuriousMedicineEnters,
    [STRINGID_ASONEENTERS - BATTLESTRINGS_TABLE_START] = sText_AsOneEnters,
    [STRINGID_PKMNMADESHELLGLEAM - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeShellGleam,
    [STRINGID_ABILITYRAISEDSTATDRASTICALLY - BATTLESTRINGS_TABLE_START] = sText_AbilityRaisedStatDrastically,
    [STRINGID_PKMNSWILLPERISHIN3TURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsWillPerishIn3Turns,
    [STRINGID_ASANDSTORMKICKEDUP - BATTLESTRINGS_TABLE_START] = sText_ASandstormKickedUp,
    [STRINGID_BATTLERABILITYRAISEDSTAT - BATTLESTRINGS_TABLE_START] = sText_BattlerAbilityRaisedStat,
    [STRINGID_FETCHEDPOKEBALL - BATTLESTRINGS_TABLE_START] = sText_FetchedPokeBall,
    [STRINGID_CLEARAMULETWONTLOWERSTATS - BATTLESTRINGS_TABLE_START] = sText_ClearAmuletWontLowerStats,
    [STRINGID_CLOAKEDINAFREEZINGLIGHT - BATTLESTRINGS_TABLE_START] = sText_CloakedInAFreezingLight,
    [STRINGID_DESTINYKNOTACTIVATES - BATTLESTRINGS_TABLE_START] = sText_DestinyKnotActivates,
    [STRINGID_NOONEWILLBEABLETORUNAWAY - BATTLESTRINGS_TABLE_START] = sText_NoOneWillBeAbleToRun,
    [STRINGID_PKNMABSORBINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbingPower,
    [STRINGID_RECEIVERABILITYTAKEOVER - BATTLESTRINGS_TABLE_START] = sText_ReceiverAbilityTakeOver,
    [STRINGID_SCRIPTINGABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_ScriptingAbilityRaisedStat,
    [STRINGID_HEALERCURE - BATTLESTRINGS_TABLE_START] = sText_HealerCure,
    [STRINGID_ATTACKERLOSTFIRETYPE - BATTLESTRINGS_TABLE_START] = sText_AttackerLostFireType,
    [STRINGID_ATTACKERCUREDTARGETSTATUS - BATTLESTRINGS_TABLE_START] = sText_AttackerCuredTargetStatus,
    [STRINGID_ILLUSIONWOREOFF - BATTLESTRINGS_TABLE_START] = sText_IllusionWoreOff,
    [STRINGID_BUGBITE - BATTLESTRINGS_TABLE_START] = sText_BugBite,
    [STRINGID_INCINERATEBURN - BATTLESTRINGS_TABLE_START] = sText_IncinerateBurn,
    [STRINGID_AIRBALLOONPOP - BATTLESTRINGS_TABLE_START] = sText_AirBalloonPop,
    [STRINGID_AIRBALLOONFLOAT - BATTLESTRINGS_TABLE_START] = sText_AirBalloonFloat,
    [STRINGID_TARGETATEITEM - BATTLESTRINGS_TABLE_START] = sText_TargetAteItem,
    [STRINGID_BERRYDMGREDUCES - BATTLESTRINGS_TABLE_START] = sText_BerryDmgReducing,
    [STRINGID_GEMACTIVATES - BATTLESTRINGS_TABLE_START] = sText_GemActivates,
    [STRINGID_LASERFOCUS - BATTLESTRINGS_TABLE_START] = sText_LaserFocusMessage,
    [STRINGID_THROATCHOPENDS - BATTLESTRINGS_TABLE_START] = sText_ThroatChopEnds,
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveThroatChop,
    [STRINGID_USEDINSTRUCTEDMOVE - BATTLESTRINGS_TABLE_START] = sText_UsedInstructedMove,
    [STRINGID_CELEBRATEMESSAGE - BATTLESTRINGS_TABLE_START] = sText_CelebrateMessage,
    [STRINGID_AROMAVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_AromaVeilProtected,
    [STRINGID_SWEETVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_SweetVeilProtected,
    [STRINGID_FLOWERVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_FlowerVeilProtected,
    [STRINGID_SAFETYGOGGLESPROTECTED - BATTLESTRINGS_TABLE_START] = sText_SafetyGogglesProtected,
    [STRINGID_SPECTRALTHIEFSTEAL - BATTLESTRINGS_TABLE_START] = sText_SpectralThiefSteal,
    [STRINGID_BELCHCANTSELECT - BATTLESTRINGS_TABLE_START] = sText_BelchCantUse,
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_TEAMGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_TeamGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = gText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_STARTEDSNOW - BATTLESTRINGS_TABLE_START] = sText_StartedSnow,
    [STRINGID_SNOWCONTINUES -BATTLESTRINGS_TABLE_START] = sText_SnowContinues,
    [STRINGID_SNOWSTOPPED - BATTLESTRINGS_TABLE_START] = sText_SnowStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtPlayer,
    [STRINGID_GOTCHAPKMNCAUGHTWALLY - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtWally,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2WinText,
    [STRINGID_ENDUREDSTURDY - BATTLESTRINGS_TABLE_START] = sText_EnduredViaSturdy,
    [STRINGID_POWERHERB - BATTLESTRINGS_TABLE_START] = sText_PowerHerbActivation,
    [STRINGID_HURTBYITEM - BATTLESTRINGS_TABLE_START] = sText_HurtByItem,
    [STRINGID_PSNBYITEM - BATTLESTRINGS_TABLE_START] = sText_BadlyPoisonedByItem,
    [STRINGID_BRNBYITEM - BATTLESTRINGS_TABLE_START] = sText_BurnedByItem,
    [STRINGID_DEFABILITYIN - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityActivates,
    [STRINGID_GRAVITYINTENSIFIED - BATTLESTRINGS_TABLE_START] = sText_GravityIntensified,
    [STRINGID_TARGETIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_TargetIdentified,
    [STRINGID_TARGETWOKEUP - BATTLESTRINGS_TABLE_START] = sText_TargetWokeUp,
    [STRINGID_PKMNSTOLEANDATEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleAndAteItem,
    [STRINGID_TAILWINDBLEW - BATTLESTRINGS_TABLE_START] = sText_TailWindBlew,
    [STRINGID_PKMNWENTBACK - BATTLESTRINGS_TABLE_START] = sText_PkmnWentBack,
    [STRINGID_PKMNCANTUSEITEMSANYMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseItemsAnymore,
    [STRINGID_PKMNFLUNG - BATTLESTRINGS_TABLE_START] = sText_PkmnFlung,
    [STRINGID_PKMNPREVENTEDFROMHEALING - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventedFromHealing,
    [STRINGID_PKMNSWITCHEDATKANDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedAtkAndDef,
    [STRINGID_PKMNSABILITYSUPPRESSED - BATTLESTRINGS_TABLE_START] = sText_PkmnsAbilitySuppressed,
    [STRINGID_SHIELDEDFROMCRITICALHITS - BATTLESTRINGS_TABLE_START] = sText_ShieldedFromCriticalHits,
    [STRINGID_SWITCHEDATKANDSPATK - BATTLESTRINGS_TABLE_START] = sText_SwitchedAtkAndSpAtk,
    [STRINGID_SWITCHEDDEFANDSPDEF - BATTLESTRINGS_TABLE_START] = sText_SwitchedDefAndSpDef,
    [STRINGID_PKMNACQUIREDABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnAcquiredAbility,
    [STRINGID_POISONSPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_PoisonSpikesScattered,
    [STRINGID_PKMNSWITCHEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedStatChanges,
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnSurroundedWithVeilOfWater,
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM - BATTLESTRINGS_TABLE_START] = sText_PkmnLevitatedOnElectromagnetism,
    [STRINGID_PKMNTWISTEDDIMENSIONS - BATTLESTRINGS_TABLE_START] = sText_PkmnTwistedDimensions,
    [STRINGID_POINTEDSTONESFLOAT - BATTLESTRINGS_TABLE_START] = sText_PointedStonesFloat,
    [STRINGID_CLOAKEDINMYSTICALMOONLIGHT - BATTLESTRINGS_TABLE_START] = sText_CloakedInMysticalMoonlight,
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA - BATTLESTRINGS_TABLE_START] = sText_TrappedBySwirlingMagma,
    [STRINGID_VANISHEDINSTANTLY - BATTLESTRINGS_TABLE_START] = sText_VanishedInstantly,
    [STRINGID_PROTECTEDTEAM - BATTLESTRINGS_TABLE_START] = sText_ProtectedTeam,
    [STRINGID_SHAREDITSGUARD - BATTLESTRINGS_TABLE_START] = sText_SharedItsGuard,
    [STRINGID_SHAREDITSPOWER - BATTLESTRINGS_TABLE_START] = sText_SharedItsPower,
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON - BATTLESTRINGS_TABLE_START] = sText_SwapsDefAndSpDefOfAllPkmn,
    [STRINGID_BECAMENIMBLE - BATTLESTRINGS_TABLE_START] = sText_BecameNimble,
    [STRINGID_HURLEDINTOTHEAIR - BATTLESTRINGS_TABLE_START] = sText_HurledIntoTheAir,
    [STRINGID_HELDITEMSLOSEEFFECTS - BATTLESTRINGS_TABLE_START] = sText_HeldItemsLoseEffects,
    [STRINGID_FELLSTRAIGHTDOWN - BATTLESTRINGS_TABLE_START] = sText_FellStraightDown,
    [STRINGID_TARGETCHANGEDTYPE  - BATTLESTRINGS_TABLE_START] = sText_TargetChangedType,
    [STRINGID_PKMNACQUIREDSIMPLE - BATTLESTRINGS_TABLE_START] = sText_PkmnAcquiredSimple,
    [STRINGID_EMPTYSTRING5 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_KINDOFFER - BATTLESTRINGS_TABLE_START] = sText_KindOffer,
    [STRINGID_RESETSTARGETSSTATLEVELS - BATTLESTRINGS_TABLE_START] = sText_ResetsTargetsStatLevels,
    [STRINGID_EMPTYSTRING6 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ALLYSWITCHPOSITION - BATTLESTRINGS_TABLE_START] = sText_AllySwitchPosition,
    [STRINGID_RESTORETARGETSHEALTH - BATTLESTRINGS_TABLE_START] = sText_RestoreTargetsHealth,
    [STRINGID_TOOKPJMNINTOTHESKY - BATTLESTRINGS_TABLE_START] = sText_TookPkmnIntoTheSky,
    [STRINGID_FREEDFROMSKYDROP - BATTLESTRINGS_TABLE_START] = sText_FreedFromSkyDrop,
    [STRINGID_POSTPONETARGETMOVE - BATTLESTRINGS_TABLE_START] = sText_PostponeTargetMove,
    [STRINGID_REFLECTTARGETSTYPE - BATTLESTRINGS_TABLE_START] = sText_ReflectTargetsType,
    [STRINGID_TRANSFERHELDITEM - BATTLESTRINGS_TABLE_START] = sText_TransferHeldItem,
    [STRINGID_EMBARGOENDS - BATTLESTRINGS_TABLE_START] = sText_EmbargoEnds,
    [STRINGID_ELECTROMAGNETISM - BATTLESTRINGS_TABLE_START] = sText_Electromagnetism,
    [STRINGID_BUFFERENDS - BATTLESTRINGS_TABLE_START] = sText_BufferEnds,
    [STRINGID_TELEKINESISENDS - BATTLESTRINGS_TABLE_START] = sText_TelekinesisEnds,
    [STRINGID_TAILWINDENDS - BATTLESTRINGS_TABLE_START] = sText_TailwindEnds,
    [STRINGID_LUCKYCHANTENDS - BATTLESTRINGS_TABLE_START] = sText_LuckyChantEnds,
    [STRINGID_TRICKROOMENDS - BATTLESTRINGS_TABLE_START] = sText_TrickRoomEnds,
    [STRINGID_WONDERROOMENDS - BATTLESTRINGS_TABLE_START] = sText_WonderRoomEnds,
    [STRINGID_MAGICROOMENDS - BATTLESTRINGS_TABLE_START] = sText_MagicRoomEnds,
    [STRINGID_MUDSPORTENDS - BATTLESTRINGS_TABLE_START] = sText_MudSportEnds,
    [STRINGID_WATERSPORTENDS - BATTLESTRINGS_TABLE_START] = sText_WaterSportEnds,
    [STRINGID_GRAVITYENDS - BATTLESTRINGS_TABLE_START] = sText_GravityEnds,
    [STRINGID_AQUARINGHEAL - BATTLESTRINGS_TABLE_START] = sText_AquaRingHeal,
    [STRINGID_AURORAVEILENDS - BATTLESTRINGS_TABLE_START] = sText_AuroraVeilEnds,
    [STRINGID_ELECTRICTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainEnds,
    [STRINGID_MISTYTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_MistyTerrainEnds,
    [STRINGID_PSYCHICTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_PsychicTerrainEnds,
    [STRINGID_GRASSYTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_GrassyTerrainEnds,
    [STRINGID_TARGETABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityRaisedStat,
    [STRINGID_TARGETSSTATWASMAXEDOUT - BATTLESTRINGS_TABLE_START] = sText_TargetsStatWasMaxedOut,
    [STRINGID_ATTACKERABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_AttackerAbilityRaisedStat,
    [STRINGID_POISONHEALHPUP - BATTLESTRINGS_TABLE_START] = sText_PoisonHealHpUp,
    [STRINGID_BADDREAMSDMG - BATTLESTRINGS_TABLE_START] = sText_BadDreamsDmg,
    [STRINGID_MOLDBREAKERENTERS - BATTLESTRINGS_TABLE_START] = sText_MoldBreakerEnters,
    [STRINGID_TERAVOLTENTERS - BATTLESTRINGS_TABLE_START] = sText_TeravoltEnters,
    [STRINGID_TURBOBLAZEENTERS - BATTLESTRINGS_TABLE_START] = sText_TurboblazeEnters,
    [STRINGID_SLOWSTARTENTERS - BATTLESTRINGS_TABLE_START] = sText_SlowStartEnters,
    [STRINGID_SLOWSTARTEND - BATTLESTRINGS_TABLE_START] = sText_SlowStartEnd,
    [STRINGID_SOLARPOWERHPDROP - BATTLESTRINGS_TABLE_START] = sText_SolarPowerHpDrop,
    [STRINGID_AFTERMATHDMG - BATTLESTRINGS_TABLE_START] = sText_AftermathDmg,
    [STRINGID_ANTICIPATIONACTIVATES - BATTLESTRINGS_TABLE_START] = sText_AnticipationActivates,
    [STRINGID_FOREWARNACTIVATES - BATTLESTRINGS_TABLE_START] = sText_ForewarnActivates,
    [STRINGID_ICEBODYHPGAIN - BATTLESTRINGS_TABLE_START] = sText_IceBodyHpGain,
    [STRINGID_SNOWWARNINGHAIL - BATTLESTRINGS_TABLE_START] = sText_SnowWarningHail,
    [STRINGID_SNOWWARNINGSNOW - BATTLESTRINGS_TABLE_START] = sText_SnowWarningSnow,
    [STRINGID_FRISKACTIVATES - BATTLESTRINGS_TABLE_START] = sText_FriskActivates,
    [STRINGID_UNNERVEENTERS - BATTLESTRINGS_TABLE_START] = sText_UnnerveEnters,
    [STRINGID_HARVESTBERRY - BATTLESTRINGS_TABLE_START] = sText_HarvestBerry,
    [STRINGID_LASTABILITYRAISEDSTAT - BATTLESTRINGS_TABLE_START] = sText_LastAbilityRaisedBuff1,
    [STRINGID_MAGICBOUNCEACTIVATES - BATTLESTRINGS_TABLE_START] = sText_MagicBounceActivates,
    [STRINGID_PROTEANTYPECHANGE - BATTLESTRINGS_TABLE_START] = sText_ProteanTypeChange,
    [STRINGID_SYMBIOSISITEMPASS - BATTLESTRINGS_TABLE_START] = sText_SymbiosisItemPass,
    [STRINGID_STEALTHROCKDMG - BATTLESTRINGS_TABLE_START] = sText_StealthRockDmg,
    [STRINGID_TOXICSPIKESABSORBED - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesAbsorbed,
    [STRINGID_TOXICSPIKESPOISONED - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesPoisoned,
    [STRINGID_STICKYWEBSWITCHIN - BATTLESTRINGS_TABLE_START] = sText_StickyWebSwitchIn,
    [STRINGID_HEALINGWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_HealingWishCameTrue,
    [STRINGID_HEALINGWISHHEALED - BATTLESTRINGS_TABLE_START] = sText_HealingWishHealed,
    [STRINGID_LUNARDANCECAMETRUE - BATTLESTRINGS_TABLE_START] = sText_LunarDanceCameTrue,
    [STRINGID_CUSEDBODYDISABLED - BATTLESTRINGS_TABLE_START] = sText_CursedBodyDisabled,
    [STRINGID_ATTACKERACQUIREDABILITY - BATTLESTRINGS_TABLE_START] = sText_AttackerAquiredAbility,
    [STRINGID_TARGETABILITYSTATLOWER - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityLoweredStat,
    [STRINGID_TARGETSTATWONTGOHIGHER - BATTLESTRINGS_TABLE_START] = sText_TargetStatWontGoHigher,
    [STRINGID_PKMNMOVEBOUNCEDABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBouncedViaAbility,
    [STRINGID_IMPOSTERTRANSFORM - BATTLESTRINGS_TABLE_START] = sText_ImposterTransform,
    [STRINGID_ASSAULTVESTDOESNTALLOW - BATTLESTRINGS_TABLE_START] = sText_AssaultVestDoesntAllow,
    [STRINGID_GRAVITYPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_GravityPreventsUsage,
    [STRINGID_HEALBLOCKPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_HealBlockPreventsUsage,
    [STRINGID_NOTDONEYET - BATTLESTRINGS_TABLE_START] = sText_NotDoneYet,
    [STRINGID_STICKYWEBUSED - BATTLESTRINGS_TABLE_START] = sText_StickyWebUsed,
    [STRINGID_QUASHSUCCESS - BATTLESTRINGS_TABLE_START] = sText_QuashSuccess,
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayToxicSpikes,
    [STRINGID_PKMNBLEWAWAYSTICKYWEB - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayStickyWeb,
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayStealthRock,
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_SpikesDisappearedFromTeam,
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesDisappearedFromTeam,
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_StealthRockDisappearedFromTeam,
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_StickyWebDisappearedFromTeam,
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_SharpSteelDisappearedFromTeam,
    [STRINGID_IONDELUGEON - BATTLESTRINGS_TABLE_START] = sText_IonDelugeOn,
    [STRINGID_TOPSYTURVYSWITCHEDSTATS - BATTLESTRINGS_TABLE_START] = sText_TopsyTurvySwitchedStats,
    [STRINGID_TERRAINBECOMESMISTY - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesMisty,
    [STRINGID_TERRAINBECOMESGRASSY - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesGrassy,
    [STRINGID_TERRAINBECOMESELECTRIC - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesElectric,
    [STRINGID_TERRAINBECOMESPSYCHIC - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesPsychic,
    [STRINGID_TARGETELECTRIFIED - BATTLESTRINGS_TABLE_START] = sText_TargetElectrified,
    [STRINGID_MEGAEVOREACTING - BATTLESTRINGS_TABLE_START] = sText_MegaEvoReacting,
    [STRINGID_FERVENTWISHREACHED - BATTLESTRINGS_TABLE_START] = sText_FerventWishReached,
    [STRINGID_MEGAEVOEVOLVED - BATTLESTRINGS_TABLE_START] = sText_MegaEvoEvolved,
    [STRINGID_DRASTICALLY - BATTLESTRINGS_TABLE_START] = sText_drastically,
    [STRINGID_SEVERELY - BATTLESTRINGS_TABLE_START] = sText_severely,
    [STRINGID_INFESTATION - BATTLESTRINGS_TABLE_START] = sText_Infestation,
    [STRINGID_NOEFFECTONTARGET - BATTLESTRINGS_TABLE_START] = sText_NoEffectOnTarget,
    [STRINGID_BURSTINGFLAMESHIT - BATTLESTRINGS_TABLE_START] = sText_BurstingFlames,
    [STRINGID_BESTOWITEMGIVING - BATTLESTRINGS_TABLE_START] = sText_BestowItemGiving,
    [STRINGID_THIRDTYPEADDED - BATTLESTRINGS_TABLE_START] = sText_ThirdTypeAdded,
    [STRINGID_FELLFORFEINT - BATTLESTRINGS_TABLE_START] = sText_FellForFeint,
    [STRINGID_POKEMONCANNOTUSEMOVE - BATTLESTRINGS_TABLE_START] = sText_PokemonCannotUseMove,
    [STRINGID_COVEREDINPOWDER - BATTLESTRINGS_TABLE_START] = sText_CoveredInPowder,
    [STRINGID_POWDEREXPLODES - BATTLESTRINGS_TABLE_START] = sText_PowderExplodes,
    [STRINGID_GRAVITYGROUNDING - BATTLESTRINGS_TABLE_START] = sText_GravityGrounding,
    [STRINGID_MISTYTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_MistyTerrainPreventsStatus,
    [STRINGID_GRASSYTERRAINHEALS - BATTLESTRINGS_TABLE_START] = sText_GrassyTerrainHeals,
    [STRINGID_ELECTRICTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainPreventsSleep,
    [STRINGID_PSYCHICTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_PsychicTerrainPreventsPriority,
    [STRINGID_AURAFLAREDTOLIFE - BATTLESTRINGS_TABLE_START] = sText_AuraFlaredToLife,
    [STRINGID_AIRLOCKACTIVATES - BATTLESTRINGS_TABLE_START] = sText_AirLockActivates,
    [STRINGID_PRESSUREENTERS - BATTLESTRINGS_TABLE_START] = sText_PressureActivates,
    [STRINGID_DARKAURAENTERS - BATTLESTRINGS_TABLE_START] = sText_DarkAuraActivates,
    [STRINGID_FAIRYAURAENTERS - BATTLESTRINGS_TABLE_START] = sText_FairyAuraActivates,
    [STRINGID_AURABREAKENTERS - BATTLESTRINGS_TABLE_START] = sText_AuraBreakActivates,
    [STRINGID_COMATOSEENTERS - BATTLESTRINGS_TABLE_START] = sText_ComatoseActivates,
    [STRINGID_SCREENCLEANERENTERS - BATTLESTRINGS_TABLE_START] = sText_ScreenCleanerActivates,
    [STRINGID_BOTHCANNOLONGERESCAPE - BATTLESTRINGS_TABLE_START] = sText_BothCanNoLongerEscape,
    [STRINGID_CANTESCAPEDUETOUSEDMOVE - BATTLESTRINGS_TABLE_START] = sText_CantEscapeDueToUsedMove,
    [STRINGID_PKMNBECAMEWEAKERTOFIRE - BATTLESTRINGS_TABLE_START] = sText_PkmnBecameWeakerToFire,
    [STRINGID_ABOUTTOUSEPOLTERGEIST - BATTLESTRINGS_TABLE_START] = sText_PkmnAboutToBeAttackedByItsItem,
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE - BATTLESTRINGS_TABLE_START] = sText_CantEscapeBecauseOfCurrentMove,
    [STRINGID_PKMNTOOKTARGETHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnTookTargetHigh,
    [STRINGID_TARGETTOOHEAVY - BATTLESTRINGS_TABLE_START] = sText_TargetTooHeavy,
    [STRINGID_ATTACKERLOSTELECTRICTYPE - BATTLESTRINGS_TABLE_START] = sText_AttackerLostElectricType,
    [STRINGID_PKMNSABILITYPREVENTSABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnsAbilityPreventsAbility,
    [STRINGID_PKMNHURTBYFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByFrostbite,
    [STRINGID_PKMNGOTFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFrostbite,
    [STRINGID_PKMNSITEMHEALEDFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedFrostbite,
    [STRINGID_ATTACKERHEALEDITSFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_AttackerHealedItsFrostbite,
    [STRINGID_PKMNFROSTBITEHEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnFrostbiteHealed,
    [STRINGID_PKMNFROSTBITEHEALED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnFrostbiteHealed2,
    [STRINGID_PKMNFROSTBITEHEALEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrostbiteHealedBy,
    [STRINGID_ULTRABURSTREACTING - BATTLESTRINGS_TABLE_START] = sText_UltraBurstReacting,
    [STRINGID_ULTRABURSTCOMPLETED - BATTLESTRINGS_TABLE_START] = sText_UltraBurstCompleted,
    [STRINGID_TEAMGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_TeamGainedEXP,
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP - BATTLESTRINGS_TABLE_START] = sText_TargetCoveredInStickyCandySyrup,
    [STRINGID_PKMNISANGRY - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAngry,
    [STRINGID_PKMNISCALM - BATTLESTRINGS_TABLE_START] = sText_PkmnIsCalm,
    [STRINGID_COMMANDERACTIVATES - BATTLESTRINGS_TABLE_START] = sText_CommanderActivates,
    
};

const u16 gTrainerUsedItemStringIds[] =
{
    STRINGID_PLAYERUSEDITEM, STRINGID_TRAINER1USEDITEM
};

const u16 gZEffectStringIds[] =
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_BUFFERENDS,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
};

const u16 gTerrainStringIds[B_MSG_TERRAIN_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY] = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC] = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY] = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_TERRAIN_END_MISTY] = STRINGID_MISTYTERRAINENDS,
    [B_MSG_TERRAIN_END_ELECTRIC] = STRINGID_ELECTRICTERRAINENDS,
    [B_MSG_TERRAIN_END_PSYCHIC] = STRINGID_PSYCHICTERRAINENDS,
    [B_MSG_TERRAIN_END_GRASSY] = STRINGID_GRASSYTERRAINENDS,
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gMagicCoatBounceStringIds[] =
{
    STRINGID_PKMNMOVEBOUNCED, STRINGID_PKMNMOVEBOUNCEDABILITY
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE, STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PASTELVEILENTERS,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
};

const u16 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN] = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_SUN] = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_HAIL] = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_STRONG_WINDS] = STRINGID_STRONGWINDSDISSIPATED,
    [B_MSG_WEATHER_END_SNOW] = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG] = STRINGID_SNOWSTOPPED,
};

const u16 gSandStormHailSnowContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES,
    [B_MSG_SNOW]      = STRINGID_SNOWCONTINUES,
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailSnowEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED,
    [B_MSG_SNOW]      = STRINGID_SNOWSTOPPED,
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND]    = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM]    = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH]    = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK]    = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]           = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]           = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]          = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]        = STRINGID_PKMNSPRANGUP,
    [B_MSG_TURN1_PHANTOM_FORCE] = STRINGID_VANISHEDINSTANTLY,
    [B_MSG_TURN1_GEOMANCY]      = STRINGID_PKNMABSORBINGPOWER,
    [B_MSG_TURN1_FREEZE_SHOCK]  = STRINGID_CLOAKEDINAFREEZINGLIGHT,
    [B_MSG_TURN1_SKY_DROP]      = STRINGID_PKMNTOOKTARGETHIGH,
    [B_MSG_TURN1_METEOR_BEAM]   = STRINGID_METEORBEAMCHARGING,
    [B_MSG_TURN1_ELECTRO_SHOT]  = STRINGID_ELECTROSHOTCHARGING,
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,     // MOVE_THUNDER_CAGE
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE
};

const u16 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED2,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_STARTEDSNOW,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING,
    [WEATHER_LEAVES]             = STRINGID_ITISRAINING
};

const u16 gPrimalWeatherBlocksStringIds[] =
{
    [B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN]      = STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN,
    [B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN]    = STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT,
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]  = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL] = STRINGID_PKMNBOXLANETTESPCFULL,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u16 gStatus2StringIds[] =
{
    STRINGID_PKMNWASCONFUSED, STRINGID_PKMNFELLINLOVE, STRINGID_TARGETCANTESCAPENOW, STRINGID_PKMNSUBJECTEDTOTORMENT
};

const u16 gDamageNonTypesStartStringIds[] =
{
    [B_MSG_TRAPPED_WITH_VINES]  = STRINGID_TEAMTRAPPEDWITHVINES,
    [B_MSG_CAUGHT_IN_VORTEX]    = STRINGID_TEAMCAUGHTINVORTEX,
    [B_MSG_SURROUNDED_BY_FIRE]  = STRINGID_TEAMSURROUNDEDBYFIRE,
    [B_MSG_SURROUNDED_BY_ROCKS] = STRINGID_TEAMSURROUNDEDBYROCKS,
};

const u16 gDamageNonTypesDmgStringIds[] =
{
    [B_MSG_HURT_BY_VINES]        = STRINGID_PKMNHURTBYVINES,
    [B_MSG_HURT_BY_VORTEX]       = STRINGID_PKMNHURTBYVORTEX,
    [B_MSG_BURNING_UP]           = STRINGID_PKMNBURNINGUP,
    [B_MSG_HURT_BY_ROCKS_THROWN] = STRINGID_PKMNHURTBYROCKSTHROWN,
};

const u8 gText_PkmnIsEvolving[] = _("{JPN}おや?\n{STR_VAR_1}の ようすが…!");
const u8 gText_CongratsPkmnEvolved[] = _("{JPN}おめでとう! {STR_VAR_1}は\n{STR_VAR_2}に しんかした!\p");
const u8 gText_PkmnStoppedEvolving[] = _("{JPN}あれ? {STR_VAR_1}の\nしんかが とまった!\p");
const u8 gText_EllipsisQuestionMark[] = _("{JPN}……?\p");
const u8 gText_WhatWillPkmnDo[] = _("{JPN}{FONT_NARROW}{B_BUFF1}は どうする?\n{FONT_SMALL_NARROW}{SELECT_BUTTON} {PKMN}じょうほう");
const u8 gText_WhatWillPkmnDo2[] = _("{JPN}{B_PLAYER_NAME}は\nどうする?");
const u8 gText_WhatWillWallyDo[] = _("{JPN}ミツルは\nどうする?");
const u8 gText_LinkStandby[] = _("{JPN}{PAUSE 16}つうしん まちうけ…");
const u8 gText_BattleMenu[] = _("{JPN}たたかう{CLEAR_TO 56}バッグ\nポケモン{CLEAR_TO 56}にげる {B_BUTTON}");
const u8 gText_TrainerBattleMenu[] = _("{JPN}たたかう{CLEAR_TO 56}バッグ\nポケモン{CLEAR_TO 56}ぼうきゃく");
const u8 gText_SafariZoneMenu[] = _("{JPN}つかまえる{CLEAR_TO 56}{FONT_SMALL_NARROW}ボールこうかん\n{CLEAR_TO 56}{FONT_NORMAL}にげる {B_BUTTON}");
const u8 gText_SafariZoneMenuNoBallSwap[] = _("{JPN}つかまえる{CLEAR_TO 56}{FONT_SMALL_NARROW}{COLOR DYNAMIC_COLOR6}{SHADOW DYNAMIC_COLOR5}ボールこうかん\n{CLEAR_TO 56}{FONT_NORMAL}{COLOR DYNAMIC_COLOR4}{SHADOW DYNAMIC_COLOR6}にげる {B_BUTTON}");
const u8 gText_MoveInterfacePP[] = _("{JPN}PP ");
const u8 gText_MoveInterfaceType[] = _("{JPN}タイプ/");
const u8 gText_MoveInterfacePpType[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nタイプ/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}どの わざを\nわすれさせますか?");
const u8 gText_BattleYesNoChoice[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}はい\nいいえ");
const u8 gText_BattleSwitchWhich[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}どれと\nいれかえる?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

// Unused
static const u8 *const sStatNamesTable2[] =
{
    gText_HP3, gText_SpAtk, gText_Attack,
    gText_SpDef, gText_Defense, gText_Speed
};

const u8 gText_SafariBalls[] = _("{HIGHLIGHT LIGHT_RED}");
const u8 gText_SafariBallLeft[] = _("{JPN}{HIGHLIGHT LIGHT_RED}のこり: ${HIGHLIGHT LIGHT_RED}");
const u8 gText_Sleep[] = _("{JPN}ねむり");
const u8 gText_Poison[] = _("{JPN}どく");
const u8 gText_Burn[] = _("{JPN}やけど");
const u8 gText_Paralysis[] = _("{JPN}まひ");
const u8 gText_Ice[] = _("{JPN}こおり");
const u8 gText_Confusion[] = _("{JPN}こんらん");
const u8 gText_Love[] = _("{JPN}メロメロ");
const u8 gText_SpaceAndSpace[] = _("{JPN}と ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("{JPN}は");
const u8 gText_Are2[] = _("{JPN}は");
const u8 gText_BadEgg[] = _("{JPN}だめな タマゴ");
const u8 gText_BattleWallyName[] = _("{JPN}ミツル");
const u8 gText_Win[] = _("{JPN}{HIGHLIGHT TRANSPARENT}かち");
const u8 gText_Loss[] = _("{JPN}{HIGHLIGHT TRANSPARENT}まけ");
const u8 gText_Draw[] = _("{JPN}{HIGHLIGHT TRANSPARENT}ひきわけ");
static const u8 sText_SpaceIs[] = _("{JPN}は");
static const u8 sText_ApostropheS[] = _("'s");

// For displaying names of invalid moves.
// This is large enough that the text for TYPE_ELECTRIC will exceed TEXT_BUFF_ARRAY_COUNT.
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL]   = _("{JPN}ノーマルタイプの わざ"),
    [TYPE_FIGHTING] = _("{JPN}かくとうタイプの わざ"),
    [TYPE_FLYING]   = _("{JPN}ひこうタイプの わざ"),
    [TYPE_POISON]   = _("{JPN}どくタイプの わざ"),
    [TYPE_GROUND]   = _("{JPN}じめんタイプの わざ"),
    [TYPE_ROCK]     = _("{JPN}いわタイプの わざ"),
    [TYPE_BUG]      = _("{JPN}むしタイプの わざ"),
    [TYPE_GHOST]    = _("{JPN}ゴーストタイプの わざ"),
    [TYPE_STEEL]    = _("{JPN}はがねタイプの わざ"),
    [TYPE_MYSTERY]  = _("{JPN}???タイプの わざ"),
    [TYPE_FIRE]     = _("{JPN}ほのおタイプの わざ"),
    [TYPE_WATER]    = _("{JPN}みずタイプの わざ"),
    [TYPE_GRASS]    = _("{JPN}くさタイプの わざ"),
    [TYPE_ELECTRIC] = _("{JPN}でんきタイプの わざ"),
    [TYPE_PSYCHIC]  = _("{JPN}エスパータイプの わざ"),
    [TYPE_ICE]      = _("{JPN}こおりタイプの わざ"),
    [TYPE_DRAGON]   = _("{JPN}ドラゴンタイプの わざ"),
    [TYPE_DARK]     = _("{JPN}あくタイプの わざ"),
    [TYPE_FAIRY]    = _("{JPN}フェアリータイプの わざ"),
};

const u8 gText_BattleTourney[] = _("{JPN}バトル トーナメント");
static const u8 sText_Round1[] = _("{JPN}1かいせん");
static const u8 sText_Round2[] = _("{JPN}2かいせん");
static const u8 sText_Semifinal[] = _("{JPN}じゅんけっしょう");
static const u8 sText_Final[] = _("{JPN}けっしょう");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = _("{JPN}きたいの しんじん!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("{JPN}ゆうしょうの ゆめは かなうのか!?\p");
const u8 gText_AFormerChampion[] = _("{JPN}もとチャンピオン!\p");
const u8 gText_ThePreviousChampion[] = _("{JPN}ぜんチャンピオン!\p");
const u8 gText_TheUnbeatenChampion[] = _("{JPN}むはいの チャンピオン!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("{JPN}VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("{JPN}こころ");
const u8 gText_Skill[] = _("{JPN}わざ");
const u8 gText_Body[] = _("{JPN}からだ");
const u8 gText_Judgment[] = _("{JPN}{B_BUFF1}{CLEAR 13}はんてい{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}は\n{B_OPPONENT_MON1_NAME}を くりだした!\p{B_TRAINER2_CLASS}の {B_TRAINER2_NAME}は\n{B_OPPONENT_MON2_NAME}を くりだした!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{JPN}{B_TRAINER2_CLASS}の {B_TRAINER2_NAME}は\n{B_BUFF1}を くりだした!");
static const u8 sText_TwoTrainersWantToBattle[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}と\n{B_TRAINER2_CLASS}の {B_TRAINER2_NAME}が\lしょうぶを しかけてきた!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{JPN}{B_PARTNER_CLASS}の {B_PARTNER_NAME}は\n{B_PLAYER_MON2_NAME}を くりだした!\lゆけっ {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}と\n{B_TRAINER2_CLASS}の {B_TRAINER2_NAME}に\lかった!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ちからを だせない\nようだ!");
static const u8 sText_GlintAppearsInEye[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の めが\nひかった!");
static const u8 sText_PkmnGettingIntoPosition[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は かまえを\nとった!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は ひくく うなりはじめた!");
static const u8 sText_PkmnEagerForMore[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は もっと やりたそうだ!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = _("{JPN}しんぱん: 3ターンで きまらなければ\nはんていに うつります!");
static const u8 sText_RefThatsIt[] = _("{JPN}しんぱん: そこまで! これより はんていで\nしょうしゃを きめます!");
static const u8 sText_RefJudgeMind[] = _("{JPN}しんぱん: はんてい その1 こころ!\nいちばん こんじょうを みせた ポケモン!\p");
static const u8 sText_RefJudgeSkill[] = _("{JPN}しんぱん: はんてい その2 わざ!\nいちばん わざを うまく つかった ポケモン!\p");
static const u8 sText_RefJudgeBody[] = _("{JPN}しんぱん: はんてい その3 からだ!\nいちばん たいりょくの ある ポケモン!\p");
static const u8 sText_RefPlayerWon[] = _("{JPN}しんぱん: はんてい {B_BUFF1}たい{B_BUFF2}!\nかちは {B_PLAYER_NAME}の {B_PLAYER_MON1_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("{JPN}しんぱん: はんてい {B_BUFF1}たい{B_BUFF2}!\nかちは {B_TRAINER1_NAME}の {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_RefDraw[] = _("{JPN}しんぱん: はんてい 3たい3!\nひきわけです!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("{JPN}{B_PLAYER_MON1_NAME}は はんていで あいての\n{B_OPPONENT_MON1_NAME}に かった!");
static const u8 sText_LostToOpponentByReferee[] = _("{JPN}{B_PLAYER_MON1_NAME}は はんていで あいての\n{B_OPPONENT_MON1_NAME}に まけた!");
static const u8 sText_TiedOpponentByReferee[] = _("{JPN}{B_PLAYER_MON1_NAME}は はんていで あいての\n{B_OPPONENT_MON1_NAME}と ひきわけた!");
static const u8 sText_RefCommenceBattle[] = _("{JPN}しんぱん: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nしょうぶ はじめ!");

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};

static const u8 sText_QuestionForfeitMatch[] = _("{JPN}バトルを ぼうきゃくして\nぼうけんを やめますか?");
static const u8 sText_ForfeitedMatch[] = _("{JPN}{B_PLAYER_NAME}は バトルを ぼうきゃくした!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{JPN}{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}は にげだした!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}に\nまけた!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("{JPN}{B_TRAINER1_CLASS}の {B_TRAINER1_NAME}と\nひきわけた!");
const u8 gText_RecordBattleToPass[] = _("{JPN}バトルの けっかを フロンティアパスに\nきろく しますか?");
const u8 gText_BattleRecordedOnPass[] = _("{JPN}{B_PLAYER_NAME}の バトルの けっかが\nフロンティアパスに きろくされた。");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("{JPN}{B_LINK_OPPONENT1_NAME}が\nしょうぶを しかけてきた!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と {B_LINK_OPPONENT2_NAME}が\nしょうぶを しかけてきた!{PAUSE 49}");
static const u8 sText_Your1[] = _("{JPN}みかたの");
static const u8 sText_Opposing1[] = _("{JPN}あいての");
static const u8 sText_Your2[] = _("{JPN}みかたの");
static const u8 sText_Opposing2[] = _("{JPN}あいての");

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VISE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(u16 stringID, u32 battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)]]))
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else if (gBattleTypeFlags & BATTLE_TYPE_ALPHA_MON) // not legend but alpha means this is a unique mon
                stringPtr = sText_UniquePkmnAppeared;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]]))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]]))
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // pokemon used a move msg
        if (gBattleStruct->zmove.active && gBattleStruct->zmove.activeSplit != SPLIT_STATUS)
            StringCopy(gBattleTextBuff3, GetZMoveName(gBattleMsgDataPtr->currentMove));
        else if (IsMaxMove(gBattleMsgDataPtr->currentMove))
            StringCopy(gBattleTextBuff3, GetMaxMoveName(gBattleMsgDataPtr->currentMove));
        else if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff3, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff3, gMoveNames[gBattleMsgDataPtr->currentMove]);

        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(battler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(battler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                case B_OUTCOME_FORFEITED:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                case B_OUTCOME_FORFEITED:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_TABLE_START];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    return BattleStringExpandPlaceholders(Rogue_ModifyBattleMessage(src), gDisplayedStringBattle);
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(u32 battler, u8 *dst)
{
    struct Pokemon *mon, *illusionMon;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        mon = &gPlayerParty[gBattlerPartyIndexes[battler]];
    else
        mon = &gEnemyParty[gBattlerPartyIndexes[battler]];

    illusionMon = GetIllusionMonPtr(battler);
    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                          \
    if (GetBattlerSide(battler) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                    \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, u8 battler)
{
    const u8 *toCpy = NULL;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        toCpy = Rogue_GetTrainerName(trainerId);
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, u8 battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battler);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, battler);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battler);
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, u8 battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)))
            || gTestRunnerEnabled)
        {
            toCpy = gLinkPlayers[0].name;
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, u8 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        return BattleStringGetPlayerName(text, battler);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;
    struct Trainer trainer;

    Rogue_ModifyTrainer(trainerId, &trainer);

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClassNames[GetSecretBaseTrainerClass()];
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClassNames[GetUnionRoomTrainerClass()];
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClassNames[GetFrontierBrainTrainerClass()];
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClassNames[GetFrontierOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClassNames[GetEreaderTrainerClassId()];
    else
        toCpy = gTrainerClassNames[trainer.trainerClass];

    return toCpy;
}

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    // This buffer may hold either the name of a trainer, pokemon, or item.
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 multiplayerId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        toCpy = NULL;
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 1, text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 2, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 3, text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleStruct->zmove.active)
                    toCpy = GetZMoveName(gBattleMsgDataPtr->currentMove);
                else if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleStruct->zmove.active)
                    toCpy = GetZMoveName(gBattleMsgDataPtr->originallyUsedMove);
                else if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY_E_READER)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                                toCpy = sText_EnigmaBerry;
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                if (GetBattlerSide(gBattleScripting.battler) != B_SIDE_PLAYER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                    GetMonData(&gEnemyParty[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                }
                else
                {
                    GetMonData(&gPlayerParty[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                }
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void IllusionNickHack(u32 battler, u32 partyId, u8 *dst)
{
    s32 id, i;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battler)))
            partnerMon = &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]];
        else
            partnerMon = mon;

        // Find last alive non-egg pokemon.
        for (i = PARTY_SIZE - 1; i >= 0; i--)
        {
            id = i;
            if (GetMonData(&gEnemyParty[id], MON_DATA_SANITY_HAS_SPECIES)
                && GetMonData(&gEnemyParty[id], MON_DATA_HP)
                && &gEnemyParty[id] != mon
                && &gEnemyParty[id] != partnerMon)
            {
                GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
                return;
            }
        }
    }

    GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_TABLE_START]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY_E_READER)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "?" or "?") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void UNUSED ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "? ????!". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "??!". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "? ??!" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " ????!" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void UNUSED ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    BattlePutTextOnWindowWithSpeed(text, windowId, TEXT_SKIP_DRAW);
}

void BattlePutTextOnWindowWithSpeed(const u8* text, u8 windowId, u8 textSpeed)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)) || gTestRunnerEnabled)
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    if(textSpeed != TEXT_SKIP_DRAW)
    {
        speed = textSpeed;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(u32 battler)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var;

    if (!gBattleStruct->zmove.viewing)
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[battler]]);
    else
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]], gBattleMoves[gMoveSelectionCursor[battler]].pp);

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}

struct TrainerSlide
{
    u16 trainerId;
    bool8 isFrontierTrainer;
    const u8 *msgLastSwitchIn;
    const u8 *msgLastLowHp;
    const u8 *msgFirstDown;
    const u8 *msgLastHalfHp;
    const u8 *msgFirstCriticalHit;
    const u8 *msgFirstSuperEffectiveHit;
    const u8 *msgFirstSTABMove;
    const u8 *msgPlayerMonUnaffected;
    const u8 *msgMegaEvolution;
    const u8 *msgZMove;
    const u8 *msgBeforeFirstTurn;
    const u8 *msgDynamax;
};

static const struct TrainerSlide sTrainerSlides[] =
{
    /* Put any trainer slide-in messages inside this array.
    Example:
    {
        .trainerId = TRAINER_WALLY_VR_2,
        .isFrontierTrainer = FALSE,
        .msgLastSwitchIn = sText_AarghAlmostHadIt,
        .msgLastLowHp = sText_BoxIsFull,
        .msgFirstDown = sText_123Poof,
        .msgLastHalfHp = sText_ShootSoClose,
        .msgFirstCriticalHit = sText_CriticalHit,
        .msgFirstSuperEffectiveHit = sText_SuperEffective,
        .msgFirstSTABMove = sText_ABoosted,
        .msgPlayerMonUnaffected = sText_ButNoEffect,
        .msgMegaEvolution = sText_PowderExplodes,
        .msgZMove = sText_Electromagnetism,
        .msgBeforeFirstTurn = sText_GravityIntensified,
        .msgDynamax = sText_TargetWokeUp,
    },
    */
};

static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = firstId; i < lastId; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG, NULL);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

enum
{
    LESS_THAN,
    EQUAL,
    GREATER_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    NOT_EQUAL,
};

u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold)
{
    switch (operation)
    {
    case LESS_THAN:
        return gBattleMons[battler].hp < (gBattleMons[battler].maxHP / threshold);
    case EQUAL:
        return gBattleMons[battler].hp == (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN:
        return gBattleMons[battler].hp > (gBattleMons[battler].maxHP / threshold);
    case LESS_THAN_OR_EQUAL:
        return gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN_OR_EQUAL:
        return gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / threshold);
    case NOT_EQUAL:
    default:
        return gBattleMons[battler].hp != (gBattleMons[battler].maxHP / threshold);
    }
}

u32 ShouldDoTrainerSlide(u32 battler, u32 which)
{
    u32 i, firstId, lastId, trainerId, retValue = 1;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GetBattlerSide(battler) != B_SIDE_OPPONENT)
        return 0;

    // Two opponents support.
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        if (gBattlerPartyIndexes[battler] >= 3)
        {
            firstId = 3, lastId = PARTY_SIZE;
            trainerId = gTrainerBattleOpponent_B;
            retValue = 2;
        }
        else
        {
            firstId = 0, lastId = 3;
            trainerId = gTrainerBattleOpponent_A;
        }
    }
    else
    {
        firstId = 0, lastId = PARTY_SIZE;
        trainerId = gTrainerBattleOpponent_A;
    }

    for (i = 0; i < ARRAY_COUNT(sTrainerSlides); i++)
    {
        if (trainerId == sTrainerSlides[i].trainerId
            && (((gBattleTypeFlags & BATTLE_TYPE_FRONTIER) && sTrainerSlides[i].isFrontierTrainer)
                || (!(gBattleTypeFlags & BATTLE_TYPE_FRONTIER) && !sTrainerSlides[i].isFrontierTrainer)))
        {
            gBattleScripting.battler = battler;
            switch (which)
            {
            case TRAINER_SLIDE_LAST_SWITCHIN:
                if (sTrainerSlides[i].msgLastSwitchIn != NULL && !CanBattlerSwitch(battler))
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastSwitchIn;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_LOW_HP:
                if (sTrainerSlides[i].msgLastLowHp != NULL
                    && GetEnemyMonCount(firstId, lastId, TRUE) == 1
                    && BattlerHPPercentage(battler, GREATER_THAN_OR_EQUAL, 4)
                    && !gBattleStruct->trainerSlideLowHpMsgDone)
                {
                    gBattleStruct->trainerSlideLowHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastLowHp;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_FIRST_DOWN:
                if (sTrainerSlides[i].msgFirstDown != NULL && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1)
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstDown;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_HALF_HP:
                if (sTrainerSlides[i].msgLastHalfHp != NULL
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1
                 && BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 2) && BattlerHPPercentage(battler, GREATER_THAN, 4)
                 && !gBattleStruct->trainerSlideHalfHpMsgDone)
                {
                    gBattleStruct->trainerSlideHalfHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastHalfHp;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_CRITICAL_HIT:
                if (sTrainerSlides[i].msgFirstCriticalHit != NULL && gBattleStruct->trainerSlideFirstCriticalHitMsgState == 1)
                {
                    gBattleStruct->trainerSlideFirstCriticalHitMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstCriticalHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_SUPER_EFFECTIVE_HIT:
                if (sTrainerSlides[i].msgFirstSuperEffectiveHit != NULL
                    && gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState == 1
                    && gBattleMons[battler].hp)
                {
                    gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstSuperEffectiveHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_STAB_MOVE:
                if (sTrainerSlides[i].msgFirstSTABMove != NULL
                 && gBattleStruct->trainerSlideFirstSTABMoveMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gBattleStruct->trainerSlideFirstSTABMoveMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstSTABMove;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_PLAYER_MON_UNAFFECTED:
                if (sTrainerSlides[i].msgPlayerMonUnaffected != NULL
                 && gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgPlayerMonUnaffected;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_MEGA_EVOLUTION:
                if (sTrainerSlides[i].msgMegaEvolution != NULL && !gBattleStruct->trainerSlideMegaEvolutionMsgDone)
                {
                    gBattleStruct->trainerSlideMegaEvolutionMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgMegaEvolution;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_Z_MOVE:
                if (sTrainerSlides[i].msgZMove != NULL && !gBattleStruct->trainerSlideZMoveMsgDone)
                {
                    gBattleStruct->trainerSlideZMoveMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgZMove;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_BEFORE_FIRST_TURN:
                if (sTrainerSlides[i].msgBeforeFirstTurn != NULL && !gBattleStruct->trainerSlideBeforeFirstTurnMsgDone)
                {
                    gBattleStruct->trainerSlideBeforeFirstTurnMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgBeforeFirstTurn;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_DYNAMAX:
                if (sTrainerSlides[i].msgDynamax != NULL && !gBattleStruct->trainerSlideDynamaxMsgDone)
                {
                    gBattleStruct->trainerSlideDynamaxMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgDynamax;
                    return TRUE;
                }
                break;
            }
            break;
        }
    }

    return 0;
}
