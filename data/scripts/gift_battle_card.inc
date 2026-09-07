MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。\pバトルカウントカードは おなじ カードを\nもつ トレーナーとの せんせきを\lきろく して くれます。\pおなじ カードを もつ トレーナーを\nさがして たたかって みましょう。\pぜんたいの じゅんいは ニュースで\nかくにん できます。\pぜひ ためして みて ください!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。\pおめでとう ございます!\p3かい かった ごほうびの\nプレゼントです!\pこれからも たくさん\nたたかって くださいね。$"
