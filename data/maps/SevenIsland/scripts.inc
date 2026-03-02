@ === SevenIsland scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ SevenIsland_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
@ 	.byte 0
@
@ SevenIsland_OnTransition:
@ 	setflag FLAG_VISITED_SEVEN_ISLAND
@ 	end
@
@ SevenIsland_EventScript_IslandSign::
@ 	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
@ 	end
@
@ SevenIsland_Text_IslandSign::
@     .string "SEVEN ISLAND\n"
@     .string "Quest Island of Infinity$"
@ --- End original content ---

SevenIsland_MapScripts::
	.byte 0

SevenIsland_EventScript_IslandSign::
	end

SevenIsland_Text_IslandSign::
	end
