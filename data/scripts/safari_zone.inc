SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "{JPN}サファリゾーンから\nでますか?$"

SafariZone_Text_TimesUp:
	.string "{JPN}ピンポンパンポン! じかんです!\nサファリゲームは しゅうりょうです。$"

SafariZone_Text_OutOfBalls:
	.string "{JPN}サファリボールが なくなりました。\nサファリゲームは しゅうりょうです。$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "{JPN}{POKEBLOCK}を {POKEBLOCK}エサばこに\nおきますか?$"

SafariZone_Text_PokeblockStillHere:
	.string "{JPN}まえに おいた {STR_VAR_1}が\nまだ のこって いる。$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{JPN}{STR_VAR_1}を {POKEBLOCK}エサばこに\nおいた。$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "{JPN}サファリゾーンへ ようこそ!\pここでは ホウエンでは めったに みられない\nポケモンに たくさん であえます。\pしかも しぜんの すがたの まま\nくらして いる ところを みられるのです。\pさらに ポケモントレーナーの みなさまに\nもんを ひらいて おります。\pぜひ ポケモンを つかまえて\nもちかえって ください!\pさあ サファリゾーンを おたのしみ ください!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "{JPN}サファリゾーンへ ようこそ!\nこちらは はじめてですか?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "{JPN}さあ サファリゾーンを おたのしみ ください!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "{JPN}サファリゾーンに はいると ポケモンを\nつかまえるための サファリボールを\l30こ おわたし します。\pサファリボールが なくなるか\n500ぽ あるくと サファリゲームは\lしゅうりょうです。\pさあ サファリゾーンを おたのしみ ください!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "{JPN}サファリゾーンへ ようこそ!\pにゅうじょうりょうは 1000¥です!\nおはいりに なりますか?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "{JPN}わかりました。\nまた の おこしを おまち して います!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "{JPN}おかねが たりません。\nもうしわけ ありません。$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "{JPN}1000¥ いただきます。$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "{JPN}サファリボールを どうぞ。$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{JPN}{PLAYER}は サファリボールを 3こ うけとった。$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "{JPN}しゅうりょうの ときは おしらせ\nします。\pそれまで どうぞ ごゆっくり!\nいってらっしゃいませ!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "{JPN}おきゃくさま!\nパソコンの ボックスが いっぱいです。$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "{JPN}おきゃくさま!\n{POKEBLOCK}ケースを おもちで ないようです。\p{POKEBLOCK}を つかうと サファリゲームが\nずっと たのしく なりますよ。\p{POKEBLOCK}ケースを もって また おこし ください。\p{POKEBLOCK}ケースは ミナモの コンテストかいじょうで\nいただけます。$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "{JPN}まだ じかんが のこって います。\nサファリゾーンから でますか?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "{JPN}のこりの ぼうけんも おたのしみ\nください!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "{JPN}かしこまりました。\pのこりの サファリボールは\nおあずかり します。\pごりよう ありがとう ございました。\nまた の おこしを おまち して います。$"

SafariZone_South_Text_GoodLuck:
	.string "{JPN}がんばって ください!\pこまった ことが あれば えんりょなく\nおっしゃって ください!$"

SafariZone_South_Text_Boy:
	.string "{JPN}しって いますか?\pあの しかくい はこに {POKEBLOCK}を いれると\nポケモンが あつまって くるんですよ。$"

SafariZone_South_Text_Man:
	.string "{JPN}もっと おくへ いきたいけど\nじてんしゃを わすれて きちゃった。\pおくの ほうには めずらしい ポケモンが\nいそうな きが するんだ。$"

SafariZone_Southwest_Text_Woman:
	.string "{JPN}ときどき {POKEBLOCK}を なげても ポケモンに\nむしされるんだ。\pポケモンにも すききらいが\nあるのかな?$"

SafariZone_Northwest_Text_Man:
	.string "{JPN}はあ はあ…\nここまで きたけど…\pへとへとだ… ポケモンを つかまえる\nちからが のこって いないよ…$"

SafariZone_North_Text_Fisherman:
	.string "{JPN}ホウエンでは みられない みずポケモンを\nさがして いるんだ。\pみずうみが どこか しらないかい?$"

SafariZone_North_Text_Man:
	.string "{JPN}ここで めずらしい ポケモンを たくさん\nつかまえて ともだちと こうかんするんだ!$"

SafariZone_South_Text_Youngster:
	.string "{JPN}{POKEBLOCK}エサばこに {POKEBLOCK}を おいたのに\nなくなって いるみたい。\pしらないうちに ポケモンが\nたべて しまったのかな。$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "{JPN}サファリゾーン トレーナーへの ヒント!\pやせいの ポケモンに {POKEBLOCK}を なげると\nにげにくく なります。$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "{JPN}「つかれた あしを やすめよう」\nきゅうけいじょ$"

SafariZone_RestHouse_Text_Youngster:
	.string "{JPN}{POKEBLOCK}は もって いないけど\nポケモンは そこそこ つかまえたよ。\pサファリボールを なげる まえに\nちかづくと つかまえやすく\lなるんだ。$"

SafariZone_RestHouse_Text_PsychicM:
	.string "{JPN}{POKEBLOCK}を つかうと やせいの ポケモンは\nすぐには にげなく なるよ。\pもともと にげにくい ポケモンに\n{POKEBLOCK}を あげても あまり いみは ないけどね。$"

SafariZone_RestHouse_Text_FatMan:
	.string "{JPN}エサばこに {POKEBLOCK}を おくと\nポケモンが よって くるの。\pおなじような せいかくの ポケモンが\nとくていの {POKEBLOCK}に ひかれると おもうわ。$"

SafariZone_South_Text_AreaOffLimits1:
	.string "{JPN}ここは まだ こうじちゅうです。\nたちいり きんしです ごめんなさい!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "{JPN}サファリゾーンの かくちょうこうじが\nおわりました。\pあたらしい エリアも おたのしみ ください。$"

SafariZone_South_Text_AreaOffLimits2:
	.string "{JPN}ここは まだ こうじちゅうです。\nたちいり きんしです ごめんなさい!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "{JPN}わあ! やった! はじめて みる\nポケモンばかり!$"

SafariZone_Southeast_Text_FatMan:
	.string "{JPN}この エリアの ポケモンは ぜんぶ\nはじめて みる こばかり。\pこんな めずらしい ポケモンを\nつかまえられるなんて さいこう!$"

SafariZone_Southeast_Text_RichBoy:
	.string "{JPN}この あたりの ポケモンは ホウエン いがいの\nちほうから きて いるみたい。$"

SafariZone_Northeast_Text_Boy:
	.string "{JPN}サファリボールが あと すこししか ない。\pなにを つかまえるか まよって\nしまうな。$"

SafariZone_Northeast_Text_Woman:
	.string "{JPN}ここで ピカチュウに あえると きいたの。\nどこに いるのかしら?$"

SafariZone_Northeast_Text_Girl:
	.string "{JPN}ああ もう!\nぜんぜん つかまえられない!\pなにか つかまえないと にゅうじょうりょうが\nむだに なって しまう!$"
