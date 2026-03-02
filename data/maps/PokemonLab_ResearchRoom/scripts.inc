@ === PokemonLab_ResearchRoom scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ PokemonLab_ResearchRoom_MapScripts::
@ 	.byte 0
@
@ CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
@ 	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
@ 	end
@
@ CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
@ 	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
@ 	end
@
@ CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
@     .string "There's an e-mail message.\p"
@     .string "… … …\p"
@     .string "There are three legendary bird\n"
@     .string "POKéMON.\p"
@     .string "They are ARTICUNO, ZAPDOS, and\n"
@     .string "MOLTRES.\p"
@     .string "Their whereabouts are unknown.\p"
@     .string "We plan to explore the cavern\n"
@     .string "close to CERULEAN.\p"
@     .string "From: POKéMON RESEARCH TEAM…$"
@
@ CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
@     .string "An amber pipe!$"
@ --- End original content ---

PokemonLab_ResearchRoom_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
	end
