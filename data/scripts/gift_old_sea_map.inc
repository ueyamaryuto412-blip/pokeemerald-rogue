MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。\pかくにん します あなたは {PLAYER}さん?\pあなたあての ふるいかいずを\nおあずかり して います。$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "{JPN}ミナモシティの みなとで\nつかう もののようです。\pいちど ためして みては\nいかがでしょうか?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "{JPN}もうしわけ ありません {PLAYER}さん。\nバッグの だいじなものポケットが いっぱいです。\pパソコンに なにか あずけてから\nまた おこし ください。$"
