@ === FourIsland scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ FourIsland_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_OnTransition
@ 	.byte 0
@
@ FourIsland_OnTransition:
@ 	setflag FLAG_VISITED_FOUR_ISLAND
@ 	end
@
@ FourIsland_EventScript_IslandSign::
@ 	msgbox FourIsland_Text_IslandSign, MSGBOX_SIGN
@ 	end
@
@ FourIsland_EventScript_LoreleisHouseSign::
@ 	msgbox FourIsland_Text_LoreleisHouse, MSGBOX_SIGN
@ 	end
@
@ FourIsland_Text_IslandSign::
@     .string "FOUR ISLAND\n"
@     .string "The Warm, Blue, Floe Island$"
@
@ FourIsland_Text_LoreleisHouse::
@     .string "LORELEI'S HOUSE$"
@ --- End original content ---

FourIsland_MapScripts::
	.byte 0

FourIsland_EventScript_IslandSign::
	end

FourIsland_EventScript_LoreleisHouseSign::
	end

FourIsland_Text_IslandSign::
	end

FourIsland_Text_LoreleisHouse::
	end
