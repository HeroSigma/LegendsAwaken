@ === Route28 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ Route28_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, Route28_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ Route28_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@
@ Route28_EventScript_Sign::
@ 	msgbox Route28_Text_Sign, MSGBOX_SIGN
@ 	end
@
@ Route28_Text_Sign:
@ 	.string "ROUTE 28$"
@ --- End original content ---

Route28_MapScripts::
	.byte 0

Route28_EventScript_Sign::
	end
