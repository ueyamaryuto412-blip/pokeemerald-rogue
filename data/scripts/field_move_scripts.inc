@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "{JPN}この きは いあいぎりで\nきれそうだ!\pいあいぎりを つかいますか?$"

Text_MonUsedFieldMove:
	.string "{JPN}{STR_VAR_1}は {STR_VAR_2}を つかった!$"

Text_CantCut:
	.string "{JPN}この きは いあいぎりで\nきれそうだ!$"

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "{JPN}この いわは こわせそうだ。\nいわくだきを つかいますか?$"

Text_CantSmash:
	.string "{JPN}ごつごつした いわだ。ポケモンなら\nこわせるかも しれない。$"

EventScript_StrengthBoulder::
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "{JPN}おおきな いわだ。ポケモンなら\nおせるかも しれない。\pかいりきを つかいますか?$"

Text_MonUsedStrength:
	.string "{JPN}{STR_VAR_1}は かいりきを つかった!\p{STR_VAR_1}の かいりきで いわを\nおせる ように なった!$"

Text_CantStrength:
	.string "{JPN}おおきな いわだ。ポケモンなら\nおせるかも しれない。$"

Text_StrengthActivated:
	.string "{JPN}かいりきで いわを おせる ように\nなった。$"

EventScript_UseWaterfall::
	lockall
	checkpartymove MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	setfieldeffectargument 0, VAR_RESULT
	call FollowerIntoPlayerScript
	callnative HideFollower
	dofieldeffect FLDEFF_USE_WATERFALL
	callnative FollowMe_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "{JPN}みずの かべが ものすごい おとを\nたてて おちて いる。$"

Text_WantToWaterfall:
	.string "{JPN}おおきな たきだ。\nたきのぼりを つかいますか?$"

Text_MonUsedWaterfall:
	.string "{JPN}{STR_VAR_1}は たきのぼりを つかった。$"

EventScript_UseDive::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	copyvar 0x8004 VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	call FollowerIntoPlayerScript
	callnative HideFollower
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

Text_CantDive:
	.string "{JPN}うみが ふかい。ポケモンなら\nもぐれるかも しれない。$"

Text_WantToDive:
	.string "{JPN}うみが ふかい。\nダイビングを つかいますか?$"

Text_MonUsedDive:
	.string "{JPN}{STR_VAR_1}は ダイビングを つかった。$"

Text_CantSurface:
	.string "{JPN}うえから ひかりが さして いる。\nポケモンなら うかべるかも しれない。$"

Text_WantToSurface:
	.string "{JPN}うえから ひかりが さして いる。\nダイビングを つかいますか?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "{JPN}なにも ないようだ…$"
	
FollowerPositionFixScript::
	setvar 0x8000 0x0
	callnative FollowerTrainerSightingPositionFix
	compare VAR_RESULT 0xFFFF
	goto_if_eq FollowerPositionFixScriptReturn
	call WalkCall
	setvar 0x8000 0x1
	callnative FollowerTrainerSightingPositionFix
FollowerPositionFixScriptReturn:
	return
	
FollowerIntoPlayerScript::
	setvar 0x8000 0x0
	callnative FollowerIntoPlayer
	compare VAR_RESULT 0xFFFF
	goto_if_eq FollowerPositionFixScriptReturn
	setvar 0x8005 0xFE  @ follower
	call WalkCall
	setvar 0x8000 0x1
	callnative FollowerIntoPlayer
	return
	
WalkCall:
	compare VAR_RESULT 0x0
	call_if_eq WalkDownCall
	compare VAR_RESULT 0x1
	call_if_eq WalkUpCall
	compare VAR_RESULT 0x2
	call_if_eq WalkLeftCall
	compare VAR_RESULT 0x3
	call_if_eq WalkRightCall
	waitmovement 0x8005
	return
	
WalkDownCall:
	applymovement 0x8005 WalkDown
	return

WalkUpCall:
	applymovement 0x8005 WalkUp
	return

WalkLeftCall:
	applymovement 0x8005 WalkLeft
	return

WalkRightCall:
	applymovement 0x8005 WalkRight
	return
	
WalkDown:
	walk_down
	step_end 

WalkUp:
	walk_up
	step_end

WalkLeft:
	walk_left
	step_end

WalkRight:
	walk_right
	step_end
