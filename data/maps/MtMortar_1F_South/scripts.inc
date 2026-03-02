@ === MtMortar_1F_South scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ MtMortar_1F_South_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_South_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ MtMortar_1F_South_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	end
@
@
@
@ MtMortar_1F_South_EventScript_Item_Revive::
@     finditem ITEM_REVIVE
@     end
@
@ MtMortar_1F_South_EventScript_Item_Elixir::
@     finditem ITEM_ELIXIR
@     end
@ --- End original content ---

MtMortar_1F_South_MapScripts::
	.byte 0

MtMortar_1F_South_EventScript_Item_Revive::
	end

MtMortar_1F_South_EventScript_Item_Elixir::
	end
