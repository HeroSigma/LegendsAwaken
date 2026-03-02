@ === MtSilver_2F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ MtSilver_2F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_2F_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ MtSilver_2F_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@ --- End original content ---

MtSilver_2F_MapScripts::
	.byte 0
