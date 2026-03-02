@ === IndigoPlateau_Exterior scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ IndigoPlateau_Exterior_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Exterior_OnTransition
@ 	.byte 0
@
@ IndigoPlateau_Exterior_OnTransition:
@ 	setflag FLAG_VISITED_INDIGO_PLATEAU
@ 	end
@ --- End original content ---

IndigoPlateau_Exterior_MapScripts::
	.byte 0
