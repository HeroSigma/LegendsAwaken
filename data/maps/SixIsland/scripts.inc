@ === SixIsland scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ SixIsland_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
@ 	.byte 0
@
@ SixIsland_OnTransition:
@ 	setflag FLAG_VISITED_SIX_ISLAND
@ 	end
@
@ SixIsland_EventScript_IslandSign::
@ 	msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
@ 	end
@
@ SixIsland_Text_IslandSign::
@     .string "SIX ISLAND\n"
@     .string "Fortune Island of Aged Wisdom$"
@ --- End original content ---

SixIsland_MapScripts::
	.byte 0

SixIsland_EventScript_IslandSign::
	end

SixIsland_Text_IslandSign::
	end
