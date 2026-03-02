@ === IcePath_B2F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ IcePath_B2F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_B2F_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ IcePath_B2F_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@
@ IcePath_B2F_EventScript_Item_FullHeal::
@ 	finditem ITEM_FULL_HEAL
@ 	end
@
@ IcePath_B2F_EventScript_Item_MaxPotion::
@ 	finditem ITEM_MAX_POTION
@ 	end
@
@ IcePath_B2F_EventScript_Item_Carbos::
@ 	finditem ITEM_CARBOS
@ 	end
@ --- End original content ---

IcePath_B2F_MapScripts::
	.byte 0

IcePath_B2F_EventScript_Item_FullHeal::
	end

IcePath_B2F_EventScript_Item_MaxPotion::
	end

IcePath_B2F_EventScript_Item_Carbos::
	end
