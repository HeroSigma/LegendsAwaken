@ === Route16 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ Route16_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ Route16_OnTransition:
@ 	callnative SetTimeBasedEncounters
@ 	end
@
@ Route16_EventScript_Sign::
@ 	msgbox Route16_Text_Sign, MSGBOX_SIGN
@ 	end
@
@ Route16_Text_Sign:
@ 	.string "CYCLING ROAD\n"
@ 	.string "DOWNHILL COASING\l"
@ 	.string "ALL THE WAY DOWN!$"
@ --- End original content ---

Route16_MapScripts::
	.byte 0

Route16_EventScript_Sign::
	end
