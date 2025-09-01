#include "global.h"
#include "class_profiles.h"
#include "constants/trainers.h"

#if B_GLOBAL_PRESET_TEAMS

const struct ClassProfile gClassProfiles[TRAINER_CLASS_COUNT] = {
    [TRAINER_CLASS_BUG_CATCHER] = { .doubles=FALSE, .roles={ ROLE_LEAD, ROLE_BREAKER, ROLE_ACE, ROLE_LEAD, ROLE_BREAKER, ROLE_ACE } },
    [TRAINER_CLASS_HIKER]       = { .doubles=FALSE, .roles={ ROLE_LEAD, ROLE_WALL, ROLE_BREAKER, ROLE_PIVOT, ROLE_BREAKER, ROLE_ACE } },
    [TRAINER_CLASS_COOLTRAINER] = { .doubles=FALSE, .roles={ ROLE_LEAD, ROLE_BREAKER, ROLE_PIVOT, ROLE_BREAKER, ROLE_SPEED_CTRL, ROLE_ACE } },
    [TRAINER_CLASS_EXPERT]      = { .doubles=FALSE, .roles={ ROLE_LEAD, ROLE_WALL, ROLE_PIVOT, ROLE_BREAKER, ROLE_SETUP, ROLE_ACE } },
};

#endif // B_GLOBAL_PRESET_TEAMS
