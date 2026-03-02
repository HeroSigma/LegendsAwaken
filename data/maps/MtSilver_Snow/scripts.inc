@ === MtSilver_Snow scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ MtSilver_Snow_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_Snow_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ MtSilver_Snow_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@
@ MtSilver_Snow_EventScript_RareCandy::
@ 	finditem ITEM_RARE_CANDY
@ 	end
@ MtSilver_Snow_EventScript_NevermeltIce::	
@ 	finditem ITEM_NEVER_MELT_ICE
@ 	end
@ --- End original content ---

MtSilver_Snow_MapScripts::
	.byte 0

MtSilver_Snow_EventScript_RareCandy::
	end

MtSilver_Snow_EventScript_NevermeltIce::
	end
