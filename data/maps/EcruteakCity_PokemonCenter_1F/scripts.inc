@ === EcruteakCity_PokemonCenter_1F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ .set LOCALID_NURSE, 1
@
@ EcruteakCity_PokemonCenter_1F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_1F_OnTransition
@ 	.byte 0
@
@ EcruteakCity_PokemonCenter_1F_OnTransition:
@ 	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
@ 	end
@
@ EcruteakCity_PokemonCenter_1F_EventScript_Nurse::
@ 	setvar VAR_0x800B, LOCALID_NURSE
@ 	call Common_EventScript_PkmnCenterNurse
@ 	waitmessage
@ 	waitbuttonpress
@ 	release
@ 	end
@ --- End original content ---

EcruteakCity_PokemonCenter_1F_MapScripts::
	.byte 0

EcruteakCity_PokemonCenter_1F_EventScript_Nurse::
	end
