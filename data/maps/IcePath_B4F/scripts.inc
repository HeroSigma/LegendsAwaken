@ === IcePath_B4F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ IcePath_B4F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_B4F_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ IcePath_B4F_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@
@ IcePath_B4F_EventScript_Item_NeverMeltIce::
@ 	finditem ITEM_NEVER_MELT_ICE
@ 	end
@ --- End original content ---

IcePath_B4F_MapScripts::
	.byte 0

IcePath_B4F_EventScript_Item_NeverMeltIce::
	end
