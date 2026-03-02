@ === FiveIsland scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ FiveIsland_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_OnTransition
@ 	.byte 0
@
@ FiveIsland_OnTransition:
@ 	setflag FLAG_VISITED_FIVE_ISLAND
@ 	end
@
@ FiveIsland_EventScript_IslandSign::
@ 	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
@ 	end
@
@ FiveIsland_Text_IslandSign::
@     .string "FIVE ISLAND\n"
@     .string "Chrono Island: Where Time Goes$"
@ --- End original content ---

FiveIsland_MapScripts::
	.byte 0

FiveIsland_EventScript_IslandSign::
	end

FiveIsland_Text_IslandSign::
	end
