#ifndef GUARD_TRAINER_MECHANIC_POOLS_H
#define GUARD_TRAINER_MECHANIC_POOLS_H

#include "constants/items.h"
#include "constants/pokemon.h"

// One entry per class for each mechanic
typedef struct {
    u16 item;           // Mega Stone or Z-Crystal
    u8  weight;
} MechanicItemLine;

typedef struct {
    u8  teraType;       // TYPE_xxx
    u8  weight;
} TeraTypeLine;

// Per-class pools
extern const MechanicItemLine gMegaStonePools[TRAINER_CLASS_COUNT][8];   // up to 8 options per class
extern const MechanicItemLine gZCrystalPools[TRAINER_CLASS_COUNT][8];
extern const TeraTypeLine     gTeraTypePools[TRAINER_CLASS_COUNT][8];

// Functions
u16 GetRandomMegaStone(u8 trainerClass);
u16 GetRandomZCrystal(u8 trainerClass);
u8  GetRandomTeraType(u8 trainerClass);
bool8 CanDynamaxThisTrainer(u8 trainerClass);   // simple flag pool

#endif // GUARD_TRAINER_MECHANIC_POOLS_H
