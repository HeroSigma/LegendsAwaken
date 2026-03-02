@ === MtSilver_3F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ MtSilver_3F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_3F_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ MtSilver_3F_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	setescapewarp MAP_MT_SILVER_OUTSIDE, 17, 8
@ 	end
@ --- End original content ---

MtSilver_3F_MapScripts::
	.byte 0
