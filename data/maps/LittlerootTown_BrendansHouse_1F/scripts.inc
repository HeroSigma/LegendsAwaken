LittlerootTown_BrendansHouse_1F_MapScripts::
	.byte 0


RivalsHouse_1F_EventScript_RivalMom::
# 6 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_RivalMom, MSGBOX_DEFAULT
	return


RivalsHouse_1F_EventScript_RivalSibling::
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_RivalSibling, MSGBOX_DEFAULT
	return


LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 18 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_1F_Text_GoSeeRoom, MSGBOX_DEFAULT
# 19 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	return


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
# 24 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 25 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_1F_Text_MeetRival0, MSGBOX_DEFAULT
# 26 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	return


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
# 31 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 32 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_1F_Text_MeetRival1, MSGBOX_DEFAULT
# 33 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	return


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
# 38 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 39 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_1F_Text_MeetRival2, MSGBOX_DEFAULT
# 40 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	return


RivalsHouse_1F_Text_RivalMom::
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh, you must be {PLAYER}!\p"
	.string "BRENDAN has been waiting for you!\p"
	.string "He's upstairs in his room.\p"
	.string "$"

RivalsHouse_1F_Text_RivalSibling::
# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "SIBLING: Hi, {PLAYER}!\p"
	.string "BRENDAN's been looking for you.\p"
	.string "He's upstairs.\p"
	.string "$"

LittlerootTown_BrendansHouse_1F_Text_GoSeeRoom::
# 59 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Why don't you go see\n"
	.string "BRENDAN's room?\p"
	.string "$"

LittlerootTown_BrendansHouse_1F_Text_MeetRival0::
# 65 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "BRENDAN: {PLAYER}! You're here!\p"
	.string "I was just about to go look for you.\p"
	.string "$"

LittlerootTown_BrendansHouse_1F_Text_MeetRival1::
# 71 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}!\p"
	.string "Ready to start our adventure?\p"
	.string "$"

LittlerootTown_BrendansHouse_1F_Text_MeetRival2::
# 77 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "BRENDAN: There you are, {PLAYER}!\p"
	.string "I've been waiting.\p"
	.string "$"
