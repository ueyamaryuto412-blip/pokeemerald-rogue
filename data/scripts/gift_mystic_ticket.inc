MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。\p{PLAYER}さん ですね。\nあなたに チケットが とどいて います。$"

sText_MysticTicketUseAtPort:
	.string "{JPN}ミナモシティの みなとで\nつかう もののようです。\pいちど ためして みては\nいかがでしょうか?$"

sText_MysticTicketThankYou:
	.string "{JPN}ふしぎなおくりものシステムを\nごりよう ありがとう ございます。$"

sText_MysticTicketBagFull:
	.string "{JPN}もうしわけ ありません {PLAYER}さん。\nバッグの だいじなものポケットが いっぱいです。\pパソコンに なにか あずけてから\nまた おこし ください。$"
