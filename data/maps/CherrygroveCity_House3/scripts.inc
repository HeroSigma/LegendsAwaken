@ === CherrygroveCity_House3 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ CherrygroveCity_House3_MapScripts::
@ 	.byte 0
@
@ CherrygroveCity_House3_EventScript_Boy::
@ 	lock
@ 	faceplayer
@ 	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ CherrygroveCity_House3_EventScript_Girl::
@ 	lock
@ 	faceplayer
@ 	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ CherrygroveCity_EvolutionHouse_Text_Youngster:
@ 	.string "POKéMON gain experience in\n"
@ 	.string "battle and change their form.$"
@
@ CherrygroveCity_EvolutionHouse_Text_Lass:
@ 	.string "POKéMON change?\p"
@ 	.string "I would be shocked if one did\n"
@ 	.string "that!$"
@ --- End original content ---

CherrygroveCity_House3_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	end

CherrygroveCity_House3_EventScript_Girl::
	end
