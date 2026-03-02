@ === OlivineCity_House2 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ OlivineCity_House2_MapScripts::
@ 	.byte 0
@
@ OlivineCity_EventScript_Punisher::
@ 	lock
@ 	faceplayer
@ 	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ OlivineCity_EventScript_PunisherBoy::
@ 	lock
@ 	faceplayer
@ 	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ OlivineCity_Text_PunishmentBro:
@ 	.string "Along the way to CIANWOOD,\n"
@ 	.string "there are four deserted islands.\p"
@ 	.string "Bad kids are taken to those\n"
@ 	.string "islands as punishment!$"
@
@ OlivineCity_Text_PunishmentBoy:
@ 	.string "Whenever I get in trouble,\n"
@ 	.string "big bro always scares me.$"
@ --- End original content ---

OlivineCity_House2_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	end

OlivineCity_EventScript_PunisherBoy::
	end
