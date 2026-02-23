LittlerootTown_PlayersHouse_1F_MapScripts::
# 2 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_minimal.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_PlayersHouse_1F_OnLoad
# 3 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_minimal.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PlayersHouse_1F_OnTransition
	.byte 0


LittlerootTown_PlayersHouse_1F_OnLoad::
# 7 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_minimal.pory"
	callif_lt VAR_INTRO_STATE, 6, LittlerootTown_PlayersHouse_1F_EventScript_SetMovingBoxes
	return


LittlerootTown_PlayersHouse_1F_OnTransition::
# 12 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_minimal.pory"
	callif_eq VAR_INTRO_STATE, 3, LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToDoor
# 13 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_minimal.pory"
	callif_eq VAR_INTRO_STATE, 5, LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToStairs
# 14 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_minimal.pory"
	callif_eq VAR_INTRO_STATE, 6, LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToTV
	return

