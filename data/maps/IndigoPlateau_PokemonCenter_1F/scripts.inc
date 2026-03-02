@ === IndigoPlateau_PokemonCenter_1F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ .set LOCALID_NURSE, 1
@
@ IndigoPlateau_PokemonCenter_1F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
@ 	.byte 0
@
@ IndigoPlateau_PokemonCenter_1F_OnTransition:
@ 	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
@ 	end
@
@ IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
@ 	setvar VAR_0x800B, LOCALID_NURSE
@ 	call Common_EventScript_KantoPkmnCenterNurse
@ 	waitmessage
@ 	waitbuttonpress
@ 	release
@ 	end
@ --- End original content ---

IndigoPlateau_PokemonCenter_1F_MapScripts::
	.byte 0

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	end
