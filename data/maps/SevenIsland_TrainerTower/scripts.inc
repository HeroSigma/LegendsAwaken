@ === SevenIsland_TrainerTower scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ SevenIsland_TrainerTower_MapScripts::
@ 	.byte 0
@
@ SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
@ 	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
@ 	end
@
@ SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
@ 	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
@ 	end
@
@ SevenIsland_TrainerTower_Text_TrainerTowerSign::
@     .string "TRAINER TOWER ENTRANCE\n"
@     .string "Rise to the Challenge, TRAINERS!$"
@
@ SevenIsland_TrainerTower_Text_TrainerTowerAhead::
@     .string "TRAINER TOWER AHEAD$"
@ --- End original content ---

SevenIsland_TrainerTower_MapScripts::
	.byte 0

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	end

SevenIsland_TrainerTower_Text_TrainerTowerSign::
	end

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
	end
