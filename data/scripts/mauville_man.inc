MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "{JPN}やあ わたしは こうかんやです。\nかざりを こうかん しませんか?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "{JPN}ああ…\nさびしい きもちに なりますね…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "{JPN}でも あなたとは もう\nかざりを こうかん しましたよ。$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "{JPN}わたしの かざりで ほしい ものが\nあれば いって ください。$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "{JPN}なにも いりませんか?\nさびしい ものですね…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "{JPN}その かざりは むかし {STR_VAR_1}が\nもって いた ものです。\pほしいですか?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "{JPN}おっと まって ください。 かざりを\n1つも もって いないでは ないですか!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "{JPN}では わたしに ゆずって くれる\nかざりを えらんで ください。$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "{JPN}こうかん して くれないのですか?\nさびしい ものですね…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "{JPN}{STR_VAR_2}は もう しまえるだけ\nもって います。 いれる ばしょが ありません。$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "{JPN}では わたしの {STR_VAR_3}と\nあなたの {STR_VAR_2}を こうかん しますか?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "{JPN}その かざりは つかって いますね。\nこうかん できません。$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "{JPN}では こうかん しましょう!\nかざりは パソコンに おくりますね。$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "{JPN}おっと しつれい! それは とても\nめずらしい かざりでして。\lそれだけは こうかん できません!\pほかの ものでは いかがですか?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "{JPN}わしは ものがたりの かたりべ。\nでんせつの トレーナーの はなしを\lきかせて やろう。\pきいて いくかね?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "{JPN}ああ…\nさびしい きもちに なりますね…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "{JPN}わしが しって おる でんせつじゃ。\nどの はなしを きかせようか?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "{JPN}だが でんせつの トレーナーを しらぬゆえ\nきかせる はなしも ないのじゃ。\pどこへ いけば はなしに ふさわしい\nトレーナーに あえるのかのう?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "{JPN}なんと?!\nおまえさん… おまえさんは…\p{STR_VAR_2}\n{STR_VAR_1}かい?!\pそれは みごとじゃ!\nあらたな でんせつの たんじょうじゃ!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "{JPN}かんがえて みると もっと すごい\nでんせつを もつ トレーナーが\lまだ どこかに いるのかも しれんな。$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "{JPN}おまえさんは トレーナーかね?\pでは でんせつと よべそうな はなしを\nなにか もって おらんかね?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "{JPN}ところで…\nもう ひとつ でんせつを きいて いくかね?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "{JPN}うーむ…\nもの たりんのう…\pでんせつと よべる ような はなしを\nもって きて ほしいものじゃ。$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "{JPN}でんせつの トレーナーの ものがたりに\nもっと おおくの ひとが きょうみを\lもって くれると よいのじゃがのう。$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "{JPN}セーブずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "{JPN}ゲームを ほぞん した かいすう$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ゲームを\n{STR_VAR_1}かいも ほぞん した!\p{STR_VAR_3}ほど ようじんぶかい\nトレーナーは そう いない!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "{JPN}りゅうこうを つくる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "{JPN}りゅうこうを うんだ かいすう$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは あたらしい りゅうこうを\n{STR_VAR_1}かいも うみだした!\p{STR_VAR_3}は ホウエンじゅうの\nりゅうこうを つくって いる!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "{JPN}きのみを うえる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "{JPN}きのみを うえた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは きのみを\n{STR_VAR_1}かいも うえた!\p{STR_VAR_3}は でんせつの\nきのみずきだ!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "{JPN}じてんしゃずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "{JPN}じてんしゃを こうかん した かいすう$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは じてんしゃを\n{STR_VAR_1}かいも こうかん した!\p{STR_VAR_3}は よほど じてんしゃを\nあいして いるに ちがいない!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "{JPN}しゅざいされた トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "{JPN}しゅざいされた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは\n{STR_VAR_1}かいも しゅざいされた!\p{STR_VAR_3}は よほど ちゅうもくを\nあつめて いる トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "{JPN}しょうぶずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "{JPN}しょうぶを した かいすう$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "{JPN}これは {STR_VAR_3}と いう トレーナーの\nものがたり。\pこの トレーナーは {STR_VAR_1}かいも しょうぶを した!\p{STR_VAR_3}は しょうぶの さそいを けっして ことわらない\nトレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "{JPN}ポケモンを つかまえる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "{JPN}つかまえた ポケモンの かず$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ポケモンを\n{STR_VAR_1}ひきも つかまえた!\p{STR_VAR_3}は でんせつの\nポケモンとりの めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "{JPN}つりずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "{JPN}つりざおで つかまえた かず$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは つりで ポケモンを\n{STR_VAR_1}ひきも つかまえた!\p{STR_VAR_3}は でんせつの\nつりの めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "{JPN}タマゴを あたためる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "{JPN}タマゴを かえした かず$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは タマゴから\n{STR_VAR_1}ひきも かえした!\p{STR_VAR_3}は でんせつの\nタマゴあたための めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "{JPN}しんかさせる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "{JPN}しんかさせた ポケモンの かず$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ポケモンを\n{STR_VAR_1}ひきも しんかさせた!\p{STR_VAR_3}は しんかの\nきわみの トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "{JPN}ポケモンセンターずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "{JPN}ポケモンセンターを つかった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ポケモンセンターで\n{STR_VAR_1}かいも ポケモンを かいふく した!\p{STR_VAR_3}ほどの ポケモンセンター\nずきは ほかに いない!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "{JPN}いえずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "{JPN}いえで ポケモンを やすませた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは いえで\n{STR_VAR_1}かいも ポケモンを かいふく した!\p{STR_VAR_3}ほどの いえずきは\nほかに いない!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "{JPN}サファリずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "{JPN}サファリゾーンに はいった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは サファリゾーンに\n{STR_VAR_1}かいも はいった!\p{STR_VAR_3}は サファリゾーンで\nやせいの こころが めざめる トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "{JPN}いあいぎりの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "{JPN}いあいぎりを つかった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは いあいぎりを\n{STR_VAR_1}かいも つかった!\p{STR_VAR_3}は きるのが\nすきで たまらない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "{JPN}いわくだきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "{JPN}いわを くだいた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは いわくだきを\n{STR_VAR_1}かいも つかった!\p{STR_VAR_3}は いわを みると\nくだかずに いられない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "{JPN}ひっこしずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "{JPN}ひみつきちを うつした かいすう$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ひみつきちを\n{STR_VAR_1}かいも うつした!\p{STR_VAR_3}は ひっこしが\nすきで たまらない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "{JPN}はねるずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "{JPN}はねるを つかった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは はねるを\n{STR_VAR_1}かいも つかった!\p{STR_VAR_3}は はねるのが\nすきで たまらない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "{JPN}ねばりづよい トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "{JPN}わるあがきに たよった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは わるあがきに\n{STR_VAR_1}かいも たよった!\p{STR_VAR_3}は どんな ぎゃっきょうにも\nくじけない ねばりづよい トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "{JPN}スロットの おうじゃ$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "{JPN}スロットで おおあたりを だした かいすう$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは スロットで\n{STR_VAR_1}かいも おおあたりを だした。\p{STR_VAR_3}は スロットで\nうんの よい トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "{JPN}ルーレットの おうじゃ$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "{JPN}ルーレットの れんしょう かいすう$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ルーレットで\n{STR_VAR_1}かい れんぞくで かった。\p{STR_VAR_3}は ルーレットの たまに\nみはなされない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "{JPN}バトルタワーへの ちょうせんしゃ$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "{JPN}バトルタワーに いどんだ かいすう$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは バトルタワーに\n{STR_VAR_1}かいも いどんだ!\p{STR_VAR_3}は バトルタワーで\nたかみを めざす トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "{JPN}ブレンドずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "{JPN}{POKEBLOCK}を つくった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは {POKEBLOCK}を\n{STR_VAR_1}かいも つくった!\p{STR_VAR_3}ほど きのみブレンダーを\nつかいこなす ものは いない!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "{JPN}コンテストずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "{JPN}コンテストに でた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは コンテストに\n{STR_VAR_1}かいも でた!\p{STR_VAR_3}は ポケモンを ひとに\nみせるのが すきに ちがいない!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "{JPN}コンテストの めいじん$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "{JPN}コンテストで かった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは コンテストで\n{STR_VAR_1}かいも ゆうしょう した!\p{STR_VAR_3}は とんでもない\nコンテストの めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "{JPN}かいものずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "{JPN}かいものを した かいすう$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは みせで\n{STR_VAR_1}かいも かいものを した!\p{STR_VAR_3}は かいものの ために\nうまれて きたような ひとだ。$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "{JPN}どうぐを さがす トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "{JPN}ダウジングマシンを つかった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ダウジングマシンを\n{STR_VAR_1}かいも つかった!\p{STR_VAR_3}は かくれた どうぐを\nさがすのが すきに ちがいない!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "{JPN}あめに ぬれる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "{JPN}あめに ふられた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは あめに\n{STR_VAR_1}かいも ぬれた!\p{STR_VAR_3}の みりょくは\nあめまで ひきよせるらしい!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "{JPN}ずかんを よみこむ トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "{JPN}ずかんを みた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ずかんを\n{STR_VAR_1}かいも みた!\p{STR_VAR_3}は ずかんで ポケモンを\nしらべるのが すきに ちがいない!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "{JPN}リボンあつめの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "{JPN}リボンを もらった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは リボンを\n{STR_VAR_1}かいも もらった!\p{STR_VAR_3}は リボンあつめが\nすきな トレーナーに ちがいない!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "{JPN}だんさを とびおりる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "{JPN}だんさを とびおりた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは だんさを\n{STR_VAR_1}かいも とびおりた!\pだんさが あれば {STR_VAR_3}は\nみすごせないのだ!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "{JPN}でんせつの テレビずき$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "{JPN}テレビを みた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "{JPN}これは {STR_VAR_3}と いう トレーナーの\nものがたり。\pこの トレーナーは テレビを {STR_VAR_1}かいも\nみた!\p{STR_VAR_3}は テレビを みるのが すきに ちがいない!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "{JPN}じかんに きびしい トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "{JPN}じかんを たしかめた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは じかんを\n{STR_VAR_1}かいも たしかめた!\p{STR_VAR_3}は じかんに きびしい\nきちょうめんな トレーナーだ。$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "{JPN}ポケモンくじの めいじん$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "{JPN}ポケモンくじに あたった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ポケモンくじに\n{STR_VAR_1}かいも あたった!\p{STR_VAR_3}には こうかんできる\nともだちが たくさん いるのだろう!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "{JPN}あずかりやを つかう トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "{JPN}あずかりやに あずけた かいすう$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは あずかりやに\n{STR_VAR_1}かいも あずけた!\p{STR_VAR_3}は ポケモンを どんどん\nそだてる はたらきものだ!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "{JPN}ロープウェイずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "{JPN}ロープウェイに のった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは ロープウェイに\n{STR_VAR_1}かいも のった!\p{STR_VAR_3}は のぼったり おりたり\nいそがしい トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "{JPN}おんせんずきの トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "{JPN}おんせんに はいった かいすう$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "{JPN}これは {STR_VAR_3}と いう\nトレーナーの ものがたり。\pこの トレーナーは おんせんに\n{STR_VAR_1}かいも はいった!\p{STR_VAR_3}は はだが すべすべの\nトレーナーに ちがいない!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "{JPN}わたしは おしゃべりずき!\nおもしろい はなしが あるのよ!\pきいて いく?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "{JPN}ああ…\nさびしい きもちに なりますね…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "{JPN}それから おもったんだけど…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "{JPN}だいたい そんな ところかしら…\pまた おしゃべり しましょうね!\nバイバイ!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "{JPN}やあ わたしは うたうたい。\nうたを きいて いくかい?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "{JPN}ああ…\nさびしい きもちに なりますね…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "{JPN}ああ こころに ひびく うた…\nほかの ひとにも きかせたいものだ…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "{JPN}どうだった? わたしの\nうたは。\pでも かしが どうも きに\nいらなくてね。\pよければ あたらしい かしを かんがえて\nくれないか?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "{JPN}ああ…\nさびしい きもちに なりますね…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "{JPN}ありがとう!\nでは うたって みよう。$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "{JPN}きみの おもった とおりの うたに\nなったかな?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "{JPN}よし きまりだ。\nしばらく この うたを うたうよ。$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "{JPN}よお! おれは ながれものさ。\nいま はやりの ことばを おしえて やるよ。$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "{JPN}だが はやりの ことばは もう おしえて\nやったぜ。\pほかの やつにも\nひろめたいからな。$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "{JPN}だが おまえは もう はやりの ことばを\nよく しって いるな。\pあたらしく おしえる ことは ないぜ!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "{JPN}なあ「{STR_VAR_1}」って\nきいた ことが あるかい?\pどういう いみかって?\nパパか ママに きいて みな?$"
