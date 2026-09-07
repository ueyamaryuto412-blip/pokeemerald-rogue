Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "{JPN}なにを して いるかって?\nきに なる?\pポケモンの わざで じぶんの へやを\nつくろうと おもって いるんだ。\pそうだ! この わざマシンを あげる。\nきみも じぶんの へやを つくって みない?$"

Route111_Text_ExplainSecretPower:
	.string "{JPN}つるが たれさがりそうな おおきな\nきを さがすんだ。\pその きの まえで ひみつのちからを\nつかうと つるが ほどけて\lおりて きて きに のぼれるんだ。\pなかには すきな ものを おける\nひろい ばしょが あるよ。\pそこは きみだけの ひみつの へや…\nひみつきちさ!\pきみも つくって みると いい。\pそれと ひみつきちは きに かぎらず\nつくれるんだ。\pちいさな くぼみの ある いわかべでも\nひみつのちからを つかって みて。\pぼくは ほかの ばしょを さがすよ。\nそれじゃ またね!$"

Route111_Text_DontWantThis:
	.string "{JPN}あれ いらないの?\nきが かわったら いって ね?$"

Route111_Text_DontHaveAnyRoom:
	.string "{JPN}おや もつ ところが ないみたいだね。\pあずかって おくから また こんど\nとりに おいで ね?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
