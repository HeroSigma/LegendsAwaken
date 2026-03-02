@ === ThreeIsland scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ ThreeIsland_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_OnTransition
@ 	.byte 0
@
@ ThreeIsland_OnTransition:
@ 	setflag FLAG_VISITED_THREE_ISLAND
@ 	end
@
@ ThreeIsland_EventScript_IslandSign::
@ 	msgbox ThreeIsland_Text_IslandSign, MSGBOX_SIGN
@ 	end
@
@ ThreeIsland_Text_IslandSign::
@     .string "THREE ISLAND\n"
@     .string "Kin Island of Family Bonding$"
@ --- End original content ---

ThreeIsland_MapScripts::
	.byte 0

ThreeIsland_EventScript_IslandSign::
	end

ThreeIsland_Text_IslandSign::
	end
