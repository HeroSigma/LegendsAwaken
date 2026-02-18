#include "constants/opponents.h"

LittlerootTown_EventScript_Youngster::
	trainerbattle_single TRAINER_LITTLEROOT_YOUNGSTER, 0, 0
	gotopostbattlescript

LittlerootTown_EventScript_Twin::
	lockall
	faceplayer
	applymovement MOVEMENT_TYPE_FACE_DOWN
	msgbox MSG_LITTLEROOT_TWIN_INTRO
	waitbutton
	closemsg
	releaseall
	end

LittlerootTown_EventScript_FatMan::
	lockall
	faceplayer
	applymovement MOVEMENT_TYPE_FACE_DOWN
	msgbox MSG_LITTLEROOT_FAT_MAN_INTRO
	waitbutton
	closemsg
	releaseall
	end

LittlerootTown_EventScript_Boy::
	lockall
	faceplayer
	applymovement MOVEMENT_TYPE_FACE_DOWN
	msgbox MSG_LITTLEROOT_BOY_INTRO
	waitbutton
	closemsg
	releaseall
	end

LittlerootTown_EventScript_Mom::
	lockall
	faceplayer
	applymovement MOVEMENT_TYPE_FACE_UP
	msgbox MSG_LITTLEROOT_MOM_INTRO
	waitbutton
	closemsg
	releaseall
	end
