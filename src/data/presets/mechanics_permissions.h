#pragma once
#include "global.h"
#include "constants/trainers.h"

#if B_GLOBAL_PRESET_TEAMS

#define MECH_NONE   0
#define MECH_MEGA   (1 << 0)
#define MECH_ZMOVE  (1 << 1)
#define MECH_DMAX   (1 << 2)

enum MechanicPolicy { POLICY_ONE_OF, POLICY_ALL_ALLOWED };

struct ClassMechanicRule { u8 allowedMask; u8 policy; };
extern const struct ClassMechanicRule gClassMechanics[TRAINER_CLASS_COUNT];

u8  ChooseMechanicForBattle(u16 trainerId, u8 allowedMask);
// void ApplyMechanicsToTeam(u8 mechanicMask, struct TrainerMon *party, u8 count);

#endif // B_GLOBAL_PRESET_TEAMS
