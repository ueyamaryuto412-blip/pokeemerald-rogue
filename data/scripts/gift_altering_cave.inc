MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。\pめずらしい ポケモンを みたという\nうわさが あるようです。\p103ばんどうろの へんげのどうくつで\nみかけたと いう はなしです。\pいちど しらべて みると\nいいかも しれません。$"
