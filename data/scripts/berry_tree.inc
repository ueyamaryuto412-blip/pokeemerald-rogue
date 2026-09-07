BerryTreeScript::
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, Rogue_BerryTree_CheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_Sparkling::
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil::
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, TRUE, Rogue_BerryTree_WantToPlant
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_WantToPlant::
	msgbox BerryTree_Text_WantToPlant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_ChooseBerryToPlant
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPlanting
	end

BerryTree_EventScript_ChooseBerryToPlant::
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseBerry
	waitstate
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call Rogue_BerryTree_PlantBerry

BerryTree_EventScript_CancelPlanting::
	release
	end

BerryTree_EventScript_CheckBerryStage1::
	lockall
	special ObjectEventInteractionGetBerryCountString
	message BerryTree_Text_BerryGrowthStage1
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage2::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage2
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage3::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage3
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage4::
	call BerryTree_EventScript_GetCareAdverb
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage4
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb::
	goto_if_eq VAR_0x8005, 0, BerryTree_EventScript_SetAdverbPoor
	goto_if_eq VAR_0x8005, 4, BerryTree_EventScript_SetAdverbGreat
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	goto BerryTree_EventScript_PickBerry

BerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	@ msgbox BerryTree_Text_PickedTheBerry, MSGBOX_DEFAULT
	@ playfanfare MUS_OBTAIN_BERRY
	@ waitmessage
	@ call Rogue_BerryTree_PickedUpBerry
	@ waitbuttonpress
	@ message BerryTree_Text_PutAwayBerry
	@ waitmessage
	@ waitbuttonpress
	release
	end

BerryTree_EventScript_BerryPocketFull::
	release
	end

BerryTree_EventScript_CancelPickingBerry::
	message BerryTree_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry::
	lockall
	special ObjectEventInteractionGetBerryTreeData
	call Rogue_BerryTree_PlantBerry
	releaseall
	end

BerryTree_EventScript_WantToWater::
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_WantToWater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater

BerryTree_EventScript_DontWater::
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail::
	special ObjectEventInteractionGetBerryTreeData
	lockall
BerryTree_EventScript_WaterBerry::
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_WateredTheBerry
	waitmessage
	special ObjectEventInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
	message BerryTree_Text_PlantIsDelighted
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_PlantBerry::
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	special ObjectEventInteractionGetBerryCountString
	message BerryTree_Text_PlantedOneBerry
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_ItsSoftLoamySoil:
	.string "{JPN}やわらかい つちだ。$"

BerryTree_Text_WantToPlant:
	.string "{JPN}やわらかい つちだ。\nきのみを うえますか?$"

BerryTree_Text_PlantedOneBerry:
	.string "{JPN}{PLAYER}は やわらかい つちに\n{STR_VAR_1}を うえた。$"

BerryTree_Text_BerryGrowthStage1:
	.string "{JPN}{STR_VAR_1}を うえた ところだ。$"

BerryTree_Text_BerryGrowthStage2:
	.string "{JPN}{STR_VAR_1}の めが でた。$"

BerryTree_Text_BerryGrowthStage3:
	.string "{JPN}{STR_VAR_1}の めが おおきく なった。$"

BerryTree_Text_BerryGrowthStage4:
	.string "{JPN}{STR_VAR_1}の はなが\n{STR_VAR_2} さいて いる。$"

BerryTree_Text_CareAdverbGreat:
	.string "{JPN}とても きれいに$"

BerryTree_Text_CareAdverbPoor:
	.string "{JPN}かわいく$"

BerryTree_Text_CareAdverbGood:
	.string "{JPN}きれいに$"

BerryTree_Text_WantToPick:
	.string "{JPN}{STR_VAR_2}この {STR_VAR_1}が みのって いる!\p{STR_VAR_1}を とりますか?$"

BerryTree_Text_PickedTheBerry:
	.string "{JPN}{PLAYER}は {STR_VAR_1}を\n{STR_VAR_2}こ てにいれた。$"

BerryTree_Text_PutAwayBerry:
	.string "{JPN}{PLAYER}は {STR_VAR_1}を\nバッグの きのみポケットに しまった。$"

BerryTree_Text_BerryPocketFull:
	.string "{JPN}バッグが いっぱいで {STR_VAR_1}を\nうけとれない。$"

BerryTree_Text_BerryLeftUnpicked:
	.string "{JPN}{PLAYER}は {STR_VAR_1}を\nとらずに おいた。$"

BerryTree_Text_WantToWater:
	.string "{JPN}ジョウロで {STR_VAR_1}に\nみずを あげますか?$"

BerryTree_Text_WateredTheBerry:
	.string "{JPN}{PLAYER}は {STR_VAR_1}に\nみずを あげた。$"

BerryTree_Text_PlantIsDelighted:
	.string "{JPN}うれしそうに して いる。$"

BerryTree_Text_ExclamationPoint:
	.string "!$"
