@ === OneIsland scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ OneIsland_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_OnTransition
@ 	.byte 0
@
@ OneIsland_OnTransition:
@ 	setflag FLAG_VISITED_ONE_ISLAND
@ 	end
@
@ OneIsland_EventScript_IslandSign::
@ 	msgbox OneIsland_Text_IslandSign, MSGBOX_SIGN
@ 	end
@
@ OneIsland_EventScript_PokemonNetCenterSign::
@ 	msgbox OneIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
@ 	end
@
@ OneIsland_Text_IslandSign::
@     .string "ONE ISLAND\n"
@     .string "Friends Gather at Knot Island$"
@
@ OneIsland_Text_PokemonNetCenterSign::
@     .string "Expanding the POKéMON World!\n"
@     .string "POKéMON NET CENTER$"
@ --- End original content ---

OneIsland_MapScripts::
	.byte 0

OneIsland_EventScript_IslandSign::
	end

OneIsland_EventScript_PokemonNetCenterSign::
	end

OneIsland_Text_IslandSign::
	end

OneIsland_Text_PokemonNetCenterSign::
	end
