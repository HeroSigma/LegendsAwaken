@ === PalletTown_PlayersHouse_2F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ PalletTown_PlayersHouse_2F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
@ 	.byte 0
@
@ PalletTown_PlayersHouse_2F_OnTransition:
@ 	call_if_eq VAR_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
@ 	end
@ --- End original content ---

PalletTown_PlayersHouse_2F_MapScripts::
	.byte 0
