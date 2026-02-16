# Wild Pool System Documentation

## Overview

The Legends Awaken wild pool system provides dynamic, map-specific wild Pokémon encounters with comprehensive biodiversity across all regions. This system replaces static encounter data with intelligent pool selection based on geography, environment, and progression.

## System Architecture

### Core Components

1. **Pool Types** - Thematic encounter categories
2. **Evolution Lines** - Progressive species evolution with level/badge gating
3. **Map-Specific Overrides** - Geographic pool assignment
4. **Weighted Selection** - Rarity-based spawn chances
5. **Time Bias** - Day/night encounter variations

### File Structure

```
include/constants/
├── wild_pools.h          # Pool definitions and structures
├── map_pools.h           # Map-specific pool configurations
└── species.h             # Species constants

src/data/
└── wild_pools.c          # Pool arrays and species data

src/
└── wild_encounter.c      # Pool selection and encounter logic
```

## Pool Types

### 🌿 POOL_GRASS - Open Fields / Plains
**Theme:** Normal/early mix grasslands and open fields

**Typical Locations:**
- Early game routes (101-104, 113)
- Town outskirts and plains
- Open grassy areas

**Featured Species:**
- **Normal Types:** Rattata, Pidgey, Meowth, Eevee
- **Bird Types:** Spearow, Fearow, Farfetch'd (including Galar form)
- **Early Evolutions:** Caterpie, Weedle, Pichu (including Spiky-eared)
- **Regional Forms:** Alolan Rattata/Raticate, Galar Farfetch'd
- **Special Forms:** All Pikachu variants (Cosplay, Rock Star, etc.)

**Progression:** Low-level species (2-10) with 0-2 badge requirements

---

### 🌲 POOL_FOREST - Bug / Forest Heavy
**Theme:** Dense canopy, bugs, poison, forest predators

**Typical Locations:**
- Forest areas (Petalburg Woods, Eterna Forest)
- Wooded routes (Route 118)
- Jungle and swamp edges

**Featured Species:**
- **Bug Types:** Caterpie → Butterfree, Weedle → Beedrill, Scyther, Heracross
- **Forest Variants:** All Vivillon patterns (20 forms), Burmy forms
- **Poison Types:** Venonat → Venomoth, Spinarak → Ariados
- **Special Forms:** Furfrou trims (10 forms), Flabébé colors (4 forms)

**Progression:** Medium-level species (4-20) with 2-4 badge requirements

---

### 🌋 POOL_VOLCANO - Fire / Rock / Ground
**Theme:** Volcanic areas, lava fields, rocky fire zones

**Typical Locations:**
- Mt. Chimney and Fiery Path
- Lavaridge Town outskirts
- Volcanic caves and mountains

**Featured Species:**
- **Fire Types:** Growlithe → Arcanine (including Hisui), Vulpix → Ninetales (including Alola)
- **Rock Types:** Geodude → Golem (including Alola), Onix → Steelix
- **Ground Types:** Sandshrew → Sandslash (including Alola), Diglett → Dugtrio
- **Regional Variants:** Hisui Growlithe/Arcanine, Alolan Vulpix/Ninetales

**Progression:** Medium-high level species (8-40) with 3-6 badge requirements

---

### 🌾 POOL_WETLAND - Poison / Water / Bug
**Theme:** Swamps, marshes, river edges, bug/water-heavy

**Typical Locations:**
- Safari Zone areas
- Lake of Rage marshes
- Routes 12-13, 19-20, 32-37
- Wetland forest edges

**Featured Species:**
- **Poison Types:** Grimer → Muk (including Alola), Koffing → Weezing (including Galar)
- **Water Types:** Poliwag → Poliwrath, Tentacool → Tentacruel
- **Bug Types:** Venonat → Venomoth, Paras → Parasect
- **Hybrid Types:** Lotad → Ludicolo, Surskit → Masquerain

**Progression:** Variable levels (5-30) with 2-5 badge requirements

---

### 🏔️ POOL_MOUNTAIN - Rock / Fighting / Ground
**Theme:** Rocky highlands, cliffs, alpine open zones

**Typical Locations:**
- Mountain routes (114, 116, 111)
- Victory Road cliffs
- Sky Pillar exterior
- Alpine rocky patches (214-215)

**Featured Species:**
- **Rock Types:** Geodude → Golem, Roggenrola → Gigalith
- **Fighting Types:** Mankey → Primeape, Machop → Machamp, Tyrogue → Hitmontop
- **Ground Types:** Larvitar → Tyranitar, Gible → Garchomp
- **Postgame Pseudo-legendaries:** Bagon → Salamence, Larvitar → Tyranitar, Gible → Garchomp

**Progression:** High-level species (10-50) with 4-8 badge requirements

---

### 🕳️ POOL_CAVE - Bats / Rock / Subterranean
**Theme:** Subterranean zones, caves, nocturnal species

**Typical Locations:**
- All cave interiors (Mt. Moon, Cerulean Cave, Union Cave)
- Underground areas
- Rock encounter areas

**Featured Species:**
- **Bat Types:** Zubat → Golbat → Crobat, Woobat → Swoobat, Noibat → Noivern
- **Rock Types:** Geodude → Golem, Roggenrola → Gigalith
- **Ghost/Dark Types:** Sableye, Misdreavus → Mismagius, Duskull → Dusknoir
- **Psychic Types:** Abra → Alakazam, Natu → Xatu

**Progression:** Variable levels (5-40) with 2-6 badge requirements

---

### 🌊 POOL_WATER - Surf / Water Encounters
**Theme:** Oceans, lakes, rivers

**Typical Locations:**
- All surfable routes (105-134)
- Lakes and rivers
- Underwater areas

**Featured Species:**
- **Water Types:** Magikarp → Gyarados, Tentacool → Tentacruel, Goldeen → Seaking
- **Psychic Water:** Staryu → Starmie, Slowpoke → Slowbro/Slowking
- **Grass Water:** Lotad → Ludicolo, Horsea → Kingdra
- **Regional Variants:** Wooper Paldea, Basculin forms

**Progression:** Variable levels (5-40) with 2-6 badge requirements

---

### ⚡ POOL_POWERPLANT - Electric / Steel / Industrial
**Theme:** Factories, power plants, tech-heavy zones

**Typical Locations:**
- Power Plant (near Cerulean)
- Mauville City industrial zones
- Valley Windworks
- Routes with electrical pylons (110-111)

**Featured Species:**
- **Electric Types:** Magnemite → Magnezone, Electrike → Manectric, Shinx → Luxray
- **Steel Types:** Aron → Aggron, Bronzor → Bronzong, Klink → Klinklang
- **Industrial Types:** Grimer → Muk, Trubbish → Garbodor, Porygon → Porygon-Z
- **Postgame Pseudo-legendaries:** Metagross line

**Progression:** Medium-high level species (10-40) with 3-6 badge requirements

---

### ❄️ POOL_SNOW - Ice / Snow / Alpine
**Theme:** Tundra, glaciers, snow-covered areas

**Typical Locations:**
- Ice Path (Johto)
- Sinnoh snowy routes (216-221)
- Snowpoint City
- Alpine mountain passes

**Featured Species:**
- **Ice Types:** Swinub → Mamoswine, Snorunt → Froslass, Snover → Abomasnow
- **Regional Forms:** Alolan Vulpix → Ninetales, Alolan Sandshrew → Sandslash
- **Alpine Types:** Cryogonal, Glaceon, Bergmite → Avalugg
- **Postgame Pseudo-legendaries:** Frigibax → Baxcalibur

**Progression:** High-level species (10-50) with 4-8 badge requirements

---

### ☠️ POOL_GRAVEYARD - Ghost / Dark / Cryptic
**Theme:** Haunted cemeteries, ruins, crypts, spectral zones

**Typical Locations:**
- Lavender Town and haunted areas
- Mt. Pyre (all floors)
- Abandoned Ship (ghost-infested rooms)
- Eterna Forest (Old Chateau)

**Featured Species:**
- **Ghost Core:** Gastly → Gengar, Misdreavus → Mismagius, Duskull → Dusknoir
- **Dark Types:** Murkrow → Honchkrow, Zorua → Zoroark, Pawniard → Bisharp
- **Cryptic Species:** Yamask → Cofagrigus, Golett → Golurk, Spiritomb, Mimikyu
- **Regional Variants:** Yamask Galar, Zorua Hisui → Zoroark Hisui

**Progression:** Variable levels (5-50) with 2-8 badge requirements

---

## Rod Pool System

### 🎣 POOL_OLD_ROD - Early Game Fishing
**Locations:** Routes 101-104, early towns
**Species:** Magikarp, low-level water Pokémon
**Level Range:** 2-15

### 🎣 POOL_GOOD_ROD - Mid-Game Fishing  
**Locations:** Routes 105-108, mid-game cities
**Species:** Goldeen, Poliwag, Tentacool
**Level Range:** 10-30

### 🎣 POOL_SUPER_ROD - Late-Game Fishing
**Locations:** Routes 124-134, late-game areas
**Species:** Gyarados, Feebas, Dratini, high-level fish
**Level Range:** 20-50

## Evolution Line Structure

Each pool uses `EvolutionLine` structs with:

```c
struct EvolutionLine {
    u16 species[MAX_EVO_STAGES];    // Species in evolution chain
    u8 min_level[MAX_EVO_STAGES];     // Minimum level for each stage
    u8 min_badges[MAX_EVO_STAGES];    // Minimum badges for each stage
    u32 weight;                       // Spawn weight (rarity)
    u8 time_bias;                     // Day/night bias (0=none, 1=day, 2=night)
};
```

### Progression System

- **Level Gating:** Each evolution stage requires minimum player level
- **Badge Gating:** Each evolution stage requires minimum badge count
- **Weight Selection:** Higher weights = more common encounters
- **Time Bias:** Some species prefer day or night encounters

## Map-Specific Configuration

### Override System

Maps can override the default area-based selection:

```c
static const struct MapPoolConfig sMapPoolOverrides[] = {
    {MAP_ROUTE101, POOL_GRASS},        // Route 101 uses grass pool
    {MAP_MT_MOON_1F, POOL_CAVE},       // Mt. Moon uses cave pool
    {MAP_POWER_PLANT, POOL_POWERPLANT}, // Power Plant uses industrial pool
};
```

### Priority System

1. **Map-Specific Override** (highest priority)
2. **Area-Based Selection** (fallback)
3. **Default POOL_GRASS** (final fallback)

## Encounter Selection Logic

### Weighted Random Selection

1. Calculate total weight of all species in pool
2. Roll random number between 0 and total weight
3. Select species based on cumulative weight ranges
4. Choose highest evolution stage allowed by level/badge count

### Example Selection

```c
// In POOL_GRASS with total weight 1000:
// Pidgey line: weight 180 (0-179)
// Rattata line: weight 160 (180-339)  
// Pikachu: weight 70 (340-409)
// ... other species
```

## Regional Forms Support

The system supports all regional forms:

- **Alolan Forms:** Vulpix, Ninetales, Sandshrew, Sandslash, etc.
- **Galar Forms:** Farfetch'd, Weezing, Ponyta, Rapidash, etc.
- **Hisui Forms:** Growlithe, Arcanine, Sneasel, Samurott, etc.
- **Special Forms:** All Pikachu variants, Vivillon patterns, etc.

## Postgame Pseudo-Legendaries

Rare encounters in high-level areas:

- **POOL_MOUNTAIN:** Bagon → Salamence, Larvitar → Tyranitar, Gible → Garchomp
- **POOL_CAVE:** Deino → Hydreigon
- **POOL_POWERPLANT:** Metagross line
- **POOL_SNOW:** Frigibax → Baxcalibur
- **POOL_GRAVEYARD:** All pseudo-legendaries (very low weight)

## Configuration Examples

### Adding New Map Override

```c
{MAP_YOUR_ROUTE, POOL_DESIRED_POOL}, // Your comment
```

### Adding New Evolution Line

```c
{{SPECIES_BASIC, SPECIES_EVOLVED, SPECIES_FINAL, SPECIES_NONE},
 {  5,                   25,                  45,                    0 },
 {  0,                    3,                   6,                    0 },
 150,  0}, // weight 150, no time bias
```

## Troubleshooting

### Common Issues

1. **Compilation Errors:** Check species constants in `species.h`
2. **Pool Not Working:** Verify map ID in `map_groups.h`
3. **Wrong Species:** Ensure correct evolution progression
4. **Level Issues:** Adjust `min_level` and `min_badges` arrays

### Debug Commands

```bash
make                    # Build to check for errors
grep SPECIES_X include/constants/species.h  # Find species constant
```

## Future Enhancements

### Planned Features

- **Weather-Based Pools:** Different encounters for rain/sun/snow
- **Seasonal Variations:** Seasonal species availability
- **Time-of-Day Pools:** Day/night specific encounters
- **Rare Event Pools:** Special event encounters

### Expansion Guidelines

1. **Maintain Balance:** Keep spawn weights reasonable
2. **Progressive Difficulty:** Higher areas should have stronger species
3. **Thematic Consistency:** Species should match environment
4. **Regional Diversity:** Include appropriate regional forms

---

*Last Updated: February 2026*
*System Version: 1.0*
*Game: Legends Awaken*
