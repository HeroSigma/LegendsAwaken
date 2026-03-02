@ === NewBarkTown_House1 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ NewBarkTown_House1_MapScripts::
@ 	.byte 0
@
@ NewBarkTown_House1_EventScript_Mother::
@ 	lock
@ 	faceplayer
@ 	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ NewBarkTown_House1_EventScript_Daughter::
@ 	lock
@ 	faceplayer
@ 	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ NewBarkTown_House1_Text_NeighborsDaughter:
@ 	.string "PIKACHU is an evolved POKéMON.\p"
@ 	.string "I was amazed by PROF.ELM's\n"
@ 	.string "findings.\p"
@ 	.string "He's so famous for his research\n"
@ 	.string "on POKéMON evolution.\p"
@ 	.string "…sigh…\p"
@ 	.string "I wish I could be a researcher\n"
@ 	.string "like him…$"
@
@
@ NewBarkTown_House1_Text_Neighbor:
@ 	.string "My daughter is adamant about\n"
@ 	.string "becoming PROF.ELM's assistant.\p"
@ 	.string "She really loves POKéMON!\p"
@ 	.string "But then, so do I!$"
@ --- End original content ---

NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	end

NewBarkTown_House1_EventScript_Daughter::
	end
