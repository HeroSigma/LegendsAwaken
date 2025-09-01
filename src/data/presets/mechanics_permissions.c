#include "global.h"
#include "mechanics_permissions.h"
#include "constants/trainers.h"

#if B_GLOBAL_PRESET_TEAMS

const struct ClassMechanicRule gClassMechanics[TRAINER_CLASS_COUNT] = {
    [TRAINER_CLASS_LEADER] = { .allowedMask = MECH_MEGA | MECH_ZMOVE | MECH_DMAX, .policy = POLICY_ALL_ALLOWED },
};

#endif // B_GLOBAL_PRESET_TEAMS
