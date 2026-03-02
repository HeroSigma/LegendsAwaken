@ === MtSilver_MountainSide scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ MtSilver_MountainSide_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_MountainSide_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ MtSilver_MountainSide_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@ --- End original content ---

MtSilver_MountainSide_MapScripts::
	.byte 0
