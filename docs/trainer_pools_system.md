# Trainer Pools System - Comprehensive Documentation

## Overview

The Trainer Pools System is a dynamic encounter system that replaces static trainer parties with procedurally generated teams based on trainer class pools. This creates unprecedented variety and challenge in every trainer battle.

## Features

### 🎯 Core Features
- **Dynamic Team Generation** - Every trainer battle has a unique team composition
- **Pool-Based Selection** - Trainers draw from class-specific Pokemon pools
- **Intelligent AI Scaling** - All trainers use elite-level AI intelligence
- **Progressive Difficulty** - Teams scale with player's badge progress

### 💀 Brutal Mode Features
- **Maximum AI Intelligence** - Every trainer gets elite AI (omniscient, predictive, smart switching)
- **Level 100 Cap** - All trainers use maximum level Pokemon
- **Perfect Stats** - 31 IVs, competitive EV spreads, optimal natures
- **Strategic Items** - Held items (Sitrus Berries, Leftovers) for enhanced survivability
- **Shiny Ace Pokemon** - Psychological intimidation factor

## Level Cap System

### Hoenn Badge-Based Scaling
The level cap scales based on the number of badges obtained:

| Badges | Level Cap | Description |
|---------|-----------|-------------|
| 0 (Before 1st Gym) | 20 | Early game encounters |
| 1 (Before 2nd Gym) | 30 | Rusturf encounters |
| 2 (Before 3rd Gym) | 40 | Dewford encounters |
| 3 (Before 5th Gym) | 50 | Mauville encounters |
| 4 (Before 6th Gym) | 70 | Lavaridge encounters |
| 5 (Before 7th Gym) | 80 | Fortree encounters |
| 6 (Before 8th Gym) | 90 | Mossdeep encounters |
| 7 (Before 8th Gym) | 90 | Sootopolis encounters |
| 8 (After 8th Gym) | 100 | Victory Road & Elite Four |

### Region-Specific Implementation
Currently only Hoenn region scaling is implemented. Other regions (Kanto, Johto, etc.) are commented out for future implementation.

## AI System

### Brutal AI Flags
Every trainer receives the maximum AI intelligence package:

```c
// Core Intelligence
AI_FLAG_SMART_TRAINER | AI_FLAG_PREDICTION | AI_FLAG_OMNISCIENT
AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_SMART_TERA

// Tactical Excellence  
AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY
AI_FLAG_PP_STALL_PREVENTION

// Prediction Capabilities
AI_FLAG_PREDICT_SWITCH | AI_FLAG_PREDICT_INCOMING_MON | AI_FLAG_PREDICT_MOVE

// Strategic Assumptions
AI_FLAG_ASSUME_STAB | AI_FLAG_ASSUME_STATUS_MOVES | AI_FLAG_WEIGH_ABILITY_PREDICTION
```

### AI Behavior
- **Omniscient Awareness** - Knows player's entire team composition, moves, items, and abilities
- **Perfect Prediction** - Predicts player switches and move selections
- **Smart Switching** - Always makes optimal switch decisions
- **Strategic Item Usage** - Uses held items at perfect moments
- **Move Optimization** - Never uses suboptimal moves

## Pokemon Generation

### Team Composition
- **6 Pokemon Teams** - 5 from pool + 1 shiny ace
- **Perfect IVs** - 31 across all stats
- **Competitive EVs** - 252/252/4 distribution
- **Optimal Natures** - Class-specific preferred natures
- **Held Items** - Sitrus Berries for regular Pokemon, Leftovers for ace

### Ace Pokemon System
- **Always Shiny** - Visual intimidation factor
- **Level Cap** - Always at current level cap
- **Signature Item** - Leftovers for enhanced survivability
- **Aggressive Nature** - Adamant for maximum damage output

## Pool Categories

### Generic Pools
- **Hiker** - Rock/Ground type specialists
- **Youngster** - Basic Pokemon variety
- **Lass** - Balanced type distribution
- **Cooltrainer** - Advanced Pokemon selection
- **Beauty** - Elegant Pokemon choices

### Specialized Pools
- **Gym Leaders** - Type-specific elite pools
- **Elite Four** - Champion-level Pokemon
- **Villain Teams** - Themed criminal organization pools

## Technical Implementation

### Core Functions
- `GenerateSpecialTrainerParty()` - Main generation function
- `ApplyDynamicAIToTrainer()` - AI enhancement system
- `GetPoolForTrainerClass()` - Pool retrieval system
- `TrainerClassUsesPool()` - Pool eligibility check

### Integration Points
- **Battle System** - `CreateNPCTrainerPartyFromTrainer()` in battle_main.c
- **Level Cap System** - Badge-based scaling in pool generation
- **AI System** - Dynamic AI flag assignment

## Configuration

### Enable/Disable System
```c
// include/config/general.h
#define USE_DYNAMIC_TRAINER_POOLS 1  // Enable pool system
```

### Level Cap Configuration
Level caps are automatically calculated based on badge count using the `GetCurrentLevelCap()` function.

## Debug Information

The system includes comprehensive debug logging:
- Pool generation process
- AI flag assignment
- Level cap calculations
- Team composition details

Enable debug output by compiling with debug flags enabled.

## Future Enhancements

### Planned Features
- **Region-Specific Pools** - Kanto, Johto, Sinnoh implementations
- **Type-Aware AI** - AI adapts strategy based on team composition
- **Weather Integration** - Weather-affected pool selection
- **Time-Based Variations** - Day/night pool differences

### Balance Considerations
- **Difficulty Scaling** - Fine-tune badge-based level caps
- **Pool Composition** - Adjust pool sizes and variety
- **AI Behavior** - Balance intelligence vs. fairness

## Troubleshooting

### Common Issues
- **Empty Teams** - Check pool definitions and trainer class mappings
- **Compilation Errors** - Verify AI flag definitions and includes
- **AI Not Working** - Confirm dynamic AI function integration

### Debug Commands
```bash
# Check pool generation
make -j4 && ./LegendsAwakening.gba

# Monitor debug output
# Look for "Applied BRUTAL AI flags" messages
```

## Credits

This system was developed for Legends Awaken to provide:
- **Enhanced Replayability** - Every battle is unique
- **Strategic Depth** - AI adapts to any team composition  
- **Progressive Challenge** - Difficulty scales with player progress
- **Brutal Difficulty** - No "easy" trainer battles

---

*Last Updated: 2025-02-18*
*Version: 1.0 - Brutal Mode Implementation*
