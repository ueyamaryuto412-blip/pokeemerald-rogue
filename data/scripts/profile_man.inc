ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "{JPN}やあ トレーナー!\nすてきな えがおを して いるね。\pぼくの しゅみは ポケモントレーナーの\nじこしょうかいを あつめる ことなんだ。$"

ProfileMan_Text_MayISeeYourProfile:
	.string "{JPN}どうかな?\nきみの じこしょうかいを みせて くれる?$"

ProfileMan_Text_EasyChatExplanation:
	.string "{JPN}じこしょうかいは 4つの ことばを\nくみあわせて つくるんだ。\pまずは 4つの ことばを つかった\nれいを みせて あげよう。\pその 4つは すきな ことばと\nどんどん いれかえて じぶんだけの\lじこしょうかいに できるんだ。\pつかえる ことばは\nたくさん あるよ。\pポケモン くらし しゅみ などの\nグループに わけて あるから\lさがしやすい はずだ。\pまずは ことばの グループを えらんで\nいちらんを だすんだ。\pつぎに すきな ことばを えらぶ。\pのこりも おなじように えらべば\nきみだけの じこしょうかいの できあがりさ。$"

ProfileMan_Text_LetsSeeItThen:
	.string "{JPN}やった! ありがとう!\nさっそく みせて もらおうか。$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "{JPN}ええっ ほんとうに?\pきみなら すてきな じこしょうかいが\nできそうなのに…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "{JPN}おや? いまは きぶんじゃ ないのかな?\pいつでも いいから またね!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "{JPN}やあ トレーナー!\nすてきな えがおだね。$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "{JPN}あたらしい じこしょうかいを みせて くれる?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "{JPN}やった! ありがとう!\pまえに みせて もらった ものより\nもっと すてきだと いいな。$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "{JPN}おや いまの じこしょうかいが きに いってるんだね。\pむりも ないよ いまのままでも\nじゅうぶん すてきだもの。$"

ProfileMan_Text_FantasticProfile:
	.string "{JPN}す すごい!\pきみの じこしょうかい さいこうだ!\nきみらしさが よく でて いるよ。\pこれを きいたら だれだって\nきみに ひきつけられる はずさ!\pありがとう!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "{JPN}おや?\nひみつの あいことばを しって いるね!\pきみも きょうから ふしぎイベントクラブの\nなかまだ!$"
