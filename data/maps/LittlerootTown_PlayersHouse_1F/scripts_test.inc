LittlerootTown_PlayersHouse_1F_MapScripts::
# 2 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_test.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_PlayersHouse_1F_OnLoad
# 3 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_test.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PlayersHouse_1F_OnTransition
# 4 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_test.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/LittlerootTown_PlayersHouse_1F/scripts_test.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

