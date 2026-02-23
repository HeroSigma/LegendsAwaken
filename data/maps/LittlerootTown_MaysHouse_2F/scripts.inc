LittlerootTown_MaysHouse_2F_MapScripts::
	.byte 0


MaysHouse_2F_EventScript_Rival::
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox MaysHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 8 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox MaysHouse_2F_Text_ItsMaysPokeBall, MSGBOX_DEFAULT
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_MaysHouse_2F_EventScript_ZRingBall::
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox MaysHouse_2F_Text_ZRingBall, MSGBOX_DEFAULT
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_MaysHouse_2F_EventScript_PC::
# 30 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 31 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 32 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return


MaysHouse_2F_Text_MayWhoAreYou::
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: Who are you?\p"
	.string "Oh, it's you, {PLAYER}!\p"
	.string "What brings you here?\p"
	.string "$"

MaysHouse_2F_Text_ItsMaysPokeBall::
# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "This is MAY's POKé BALL.\p"
	.string "Better not touch it!\p"
	.string "$"

MaysHouse_2F_Text_ZRingBall::
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There's something sparkly here!\p"
	.string "It's a Z-RING!\p"
	.string "$"
