@ === RockTunnel_B1F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ RockTunnel_B1F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_B1F_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ RockTunnel_B1F_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@
@ RockTunnel_B1F_EventScript_ItemFacade::
@ 	finditem ITEM_TM_FACADE
@ 	end
@
@ RockTunnel_B1F_EventScript_Elixir::
@ 	finditem ITEM_ELIXIR
@ 	end
@ --- End original content ---

RockTunnel_B1F_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_ItemFacade::
	end

RockTunnel_B1F_EventScript_Elixir::
	end
