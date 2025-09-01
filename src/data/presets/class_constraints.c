#include "global.h"
#include "class_constraints.h"
#include "constants/trainers.h"

#if B_GLOBAL_PRESET_TEAMS

static const u16 sEmptyBanList[] = { };

const struct ClassConstraint gClassConstraints[TRAINER_CLASS_COUNT] = {
    [TRAINER_CLASS_BUG_CATCHER] = { .doubles=FALSE, .teamSize=3, .allowedTypesMask={0x80,0}, .bannedSpeciesCount=0, .bannedSpecies=sEmptyBanList, .speciesClause=TRUE, .formsAsSame=TRUE, .itemClause=FALSE },
    [TRAINER_CLASS_HIKER]       = { .doubles=FALSE, .teamSize=4, .allowedTypesMask={0x60,0x01}, .bannedSpeciesCount=0, .bannedSpecies=sEmptyBanList, .speciesClause=TRUE, .formsAsSame=TRUE, .itemClause=TRUE },
    [TRAINER_CLASS_COOLTRAINER] = { .doubles=FALSE, .teamSize=6, .allowedTypesMask={0xFF,0xFF}, .bannedSpeciesCount=0, .bannedSpecies=sEmptyBanList, .speciesClause=TRUE, .formsAsSame=FALSE, .itemClause=TRUE },
    [TRAINER_CLASS_EXPERT] = { .doubles=FALSE, .teamSize=4, .allowedTypesMask={0xFF,0xFF}, .bannedSpeciesCount=0, .bannedSpecies=sEmptyBanList, .speciesClause=TRUE, .formsAsSame=FALSE, .itemClause=FALSE },
};

#endif // B_GLOBAL_PRESET_TEAMS
