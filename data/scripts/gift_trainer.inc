MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。\pこの ふしぎなカードを もって いると\nフレンドリィショップの アンケートに\lさんか できます。\pアンケートで ルネシティに\nトレーナーを よべます。\p…アンケートの あいことばを\nおしえましょう。\p{ENG}“GIVE ME\nAWESOME TRAINER”{JPN}\pアンケートに かいて ワイヤレス\nつうしんシステムに おくって\lください。$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。\pルネシティに あなたを さがす\nトレーナーが やってきました。\pぜひ その トレーナーとの バトルを\nたのしんで ください。\pほかの あいことばを いれれば\nべつの トレーナーも よべます。\pいろいろな あいことばを\nさがして みて ください。$"
