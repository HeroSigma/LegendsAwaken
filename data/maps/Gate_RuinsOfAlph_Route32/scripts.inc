@ === Gate_RuinsOfAlph_Route32 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ Gate_RuinsOfAlph_Route32_MapScripts::
@ 	.byte 0
@
@
@ Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
@ 	lock
@ 	faceplayer
@ 	msgbox Gate_RuinsOfAlph_Route32_Text_PokefanM, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ Gate_RuinsOfAlph_Route32_EventScript_Youngster::
@ 	lock
@ 	faceplayer
@ 	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ Gate_RuinsOfAlph_Route32_Text_PokefanM:
@ 	.string "You're studying the RUINS?\n"
@ 	.string "I see a scientist in the making.$"
@
@ Gate_RuinsOfAlph_Route32_Text_Youngster:
@ 	.string "There are drawings on stone\n"
@ 	.string "panels.\p"
@ 	.string "I tried moving them.\n"
@ 	.string "I wonder what they are.$"
@ --- End original content ---

Gate_RuinsOfAlph_Route32_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
	end

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	end
