#ifndef GUARD_CONSTANTS_MAP_POOLS_H
#define GUARD_CONSTANTS_MAP_POOLS_H

#include "wild_pools.h"
#include "map_groups.h"

// Map-specific pool configurations
// Each map can have a specific pool type override
// If a map is not listed here, it will use the default area-based pool selection

struct MapPoolConfig {
    u16 mapId;
    enum WildPoolType poolType;
};

// Map-specific pool configurations for grass areas (LAND encounters)
static const struct MapPoolConfig sMapPoolOverrides[] = {
    // Hoenn Routes - Grass/Plains areas
    {MAP_ROUTE101, POOL_GRASS},        // Littleroot → Oldale Town
    {MAP_ROUTE102, POOL_GRASS},        // Oldale → Petalburg
    {MAP_ROUTE103, POOL_GRASS},        // Petalburg → Rustboro outskirts
    {MAP_ROUTE104, POOL_GRASS},        // Rustboro → Petalburg
    {MAP_ROUTE113, POOL_GRASS},        // Route 112 → Lavaridge outskirts
    
    // Forest areas
    {MAP_PETALBURG_WOODS, POOL_FOREST},
    {MAP_RUSTURF_TUNNEL, POOL_FOREST},     // Forested areas near Rusturf
    
    // Note: Eterna Forest moved to POOL_GRAVEYARD for ghost-specific encounters
    // Note: Abandoned Ship moved to POOL_GRAVEYARD for ghost-specific encounters
    
    // Routes with wooded patches/jungles (non-wetland)
    {MAP_ROUTE118, POOL_FOREST},           // Jungles near wetlands (non-swamp areas)
    
    // Wetland areas - Poison/Water/Bug
    // Kanto wetland routes
    {MAP_ROUTE12, POOL_WETLAND},            // Near water/marsh edges
    {MAP_ROUTE13, POOL_WETLAND},            // Near water/marsh edges
    {MAP_ROUTE19, POOL_WETLAND},            // Water-adjacent grassy patches
    {MAP_ROUTE20, POOL_WETLAND},            // Water-adjacent grassy patches
    
    // Safari Zone - boggy/wetland sections
    {MAP_SAFARI_ZONE_NORTHWEST, POOL_WETLAND},
    {MAP_SAFARI_ZONE_NORTH, POOL_WETLAND},
    {MAP_SAFARI_ZONE_SOUTHWEST, POOL_WETLAND},
    {MAP_SAFARI_ZONE_SOUTH, POOL_WETLAND},
    {MAP_SAFARI_ZONE_NORTHEAST, POOL_WETLAND},
    {MAP_SAFARI_ZONE_SOUTHEAST, POOL_WETLAND},
    {MAP_SAFARI_ZONE_REST_HOUSE, POOL_WETLAND},
    
    // Johto wetland routes
    {MAP_ROUTE32, POOL_WETLAND},            // Forest edge wetlands
    {MAP_ROUTE33, POOL_WETLAND},            // Forest edge wetlands
    {MAP_ROUTE34, POOL_WETLAND},            // Forest edge wetlands
    {MAP_ROUTE36, POOL_WETLAND},            // Marshy farmland edges
    {MAP_ROUTE37, POOL_WETLAND},            // Marshy farmland edges
    
    // Lake of Rage - marsh edges
    {MAP_LAKE_OF_RAGE, POOL_WETLAND},
    {MAP_LAKE_OF_RAGE_HOUSE1, POOL_WETLAND},
    {MAP_LAKE_OF_RAGE_HOUSE2, POOL_WETLAND},
    
    // Hoenn wetland routes
    {MAP_ROUTE119, POOL_WETLAND},           // Permanent rain + ponds
    {MAP_ROUTE120, POOL_WETLAND},           // Lakeside and swampy forest edges
    {MAP_ROUTE121, POOL_WETLAND},           // Lakeside and swampy forest edges
    
    // Abandoned Ship wetland areas
    {MAP_ABANDONED_SHIP_UNDERWATER1, POOL_WETLAND},  // Small bogs
    {MAP_ABANDONED_SHIP_UNDERWATER2, POOL_WETLAND},  // Small bogs
    
    // Sinnoh wetland routes
    {MAP_ROUTE212_NORTH, POOL_WETLAND},     // Lake/pond marsh edges
    {MAP_ROUTE212_SOUTH, POOL_WETLAND},     // Lake/pond marsh edges
    {MAP_ROUTE213, POOL_WETLAND},           // Lake/pond marsh edges
    
    // Volcanic areas
    {MAP_ROUTE112, POOL_VOLCANO},      // Route to Lavaridge (volcanic path)
    {MAP_MT_CHIMNEY, POOL_VOLCANO},    // Mt. Chimney main area
    {MAP_MT_CHIMNEY_CABLE_CAR_STATION, POOL_VOLCANO}, // Mt. Chimney cable car
    {MAP_FIERY_PATH, POOL_VOLCANO},    // Lava tunnels
    {MAP_LAVARIDGE_TOWN, POOL_VOLCANO}, // Lavaridge Town outskirts (ash plains)
    {MAP_LAVARIDGE_TOWN_GYM_1F, POOL_VOLCANO}, // Fire gym
    {MAP_LAVARIDGE_TOWN_GYM_B1F, POOL_VOLCANO},
    
    // Mt. Pyre (volcanic/spiritual mountain)
    // Note: Moved to POOL_GRAVEYARD for ghost/dark encounters
    
    // Mt. Ember (volcanic area)
    {MAP_MT_EMBER_EXTERIOR, POOL_VOLCANO},
    {MAP_MT_EMBER_SUMMIT_PATH_1F, POOL_VOLCANO},
    {MAP_MT_EMBER_SUMMIT_PATH_2F, POOL_VOLCANO},
    {MAP_MT_EMBER_SUMMIT_PATH_3F, POOL_VOLCANO},
    {MAP_MT_EMBER_SUMMIT, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_1F, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_B1F, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_B2F, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_B3F, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_B4F, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_B5F, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_B1F_STAIRS, POOL_VOLCANO},
    {MAP_MT_EMBER_RUBY_PATH_B2F_STAIRS, POOL_VOLCANO},
    
    // Victory Road (lava-like rock patches)
    // Note: Moved to POOL_MOUNTAIN for better thematic consistency
    
    // Cinnabar Island (volcano/island lava zones)
    {MAP_CINNABAR_ISLAND, POOL_VOLCANO},
    {MAP_CINNABAR_ISLAND_GYM, POOL_VOLCANO}, // Fire gym
    
    // Note: Mt. Mortar and Mt. Silver moved to POOL_MOUNTAIN for better thematic consistency
    
    // Mountain/Rock areas
    {MAP_ROUTE114, POOL_MOUNTAIN},     // Rock areas with fossil maniac
    {MAP_ROUTE116, POOL_MOUNTAIN},     // Tunnel areas
    
    // Kanto mountain areas (non-cave)
    // Note: Mt. Moon moved to POOL_CAVE for cave-specific encounters
    
    // Victory Road - mountain cliffs / open rocky paths
    {MAP_VICTORY_ROAD_1F, POOL_MOUNTAIN},
    {MAP_VICTORY_ROAD_B1F, POOL_MOUNTAIN},
    {MAP_VICTORY_ROAD_B2F, POOL_MOUNTAIN},
    
    // Johto mountain areas (non-cave)
    // Note: Union Cave moved to POOL_CAVE for cave-specific encounters
    
    {MAP_TIN_TOWER_1F, POOL_MOUNTAIN},        // Cliffs / surrounding mountain edges
    {MAP_TIN_TOWER_2F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_3F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_4F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_5F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_6F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_7F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_8F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_9F, POOL_MOUNTAIN},
    {MAP_TIN_TOWER_10F, POOL_MOUNTAIN},
    
    // Mt. Silver - high-altitude slopes / postgame
    {MAP_MT_SILVER_ENTRANCE, POOL_MOUNTAIN},
    {MAP_MT_SILVER_MAIN_ROOM, POOL_MOUNTAIN},
    {MAP_MT_SILVER_SOUTH_ROOM, POOL_MOUNTAIN},
    {MAP_MT_SILVER_NORTH_ROOM, POOL_MOUNTAIN},
    {MAP_MT_SILVER_BOSS_ROOM, POOL_MOUNTAIN},
    
    // Hoenn mountain areas (non-cave)
    // Note: Granite Cave and Meteor Falls moved to POOL_CAVE for cave-specific encounters
    // Note: Fiery Path moved to POOL_CAVE for cave-specific encounters
    
    {MAP_ROUTE111, POOL_MOUNTAIN},            // Highlands / desert rock patches
    
    // Sky Pillar - high cliffs / postgame pseudo-legendaries
    {MAP_SKY_PILLAR_ENTRANCE, POOL_MOUNTAIN},
    {MAP_SKY_PILLAR_OUTSIDE, POOL_MOUNTAIN},
    {MAP_SKY_PILLAR_1F, POOL_MOUNTAIN},
    {MAP_SKY_PILLAR_2F, POOL_MOUNTAIN},
    {MAP_SKY_PILLAR_3F, POOL_MOUNTAIN},
    {MAP_SKY_PILLAR_4F, POOL_MOUNTAIN},
    {MAP_SKY_PILLAR_5F, POOL_MOUNTAIN},
    {MAP_SKY_PILLAR_TOP, POOL_MOUNTAIN},
    
    // Sinnoh mountain areas (non-cave)
    // Note: Mt. Coronet moved to POOL_CAVE for cave-specific encounters
    
    // Alpine rocky patches
    {MAP_ROUTE214, POOL_MOUNTAIN},             // Alpine rocky patches
    {MAP_ROUTE215, POOL_MOUNTAIN},             // Alpine rocky patches
    {MAP_ROUTE214_ACCESS, POOL_MOUNTAIN},
    {MAP_ROUTE215_ACCESS, POOL_MOUNTAIN},
    
    // Cave areas - Bats/Rock/Subterranean
    // Kanto cave areas
    {MAP_MT_MOON_1F, POOL_CAVE},               // Cave interiors
    {MAP_MT_MOON_B1F, POOL_CAVE},              // Cave interiors
    {MAP_MT_MOON_B2F, POOL_CAVE},              // Cave interiors
    
    {MAP_CERULEAN_CAVE_1F, POOL_CAVE},         // Interior floors (postgame pseudo-legendaries)
    {MAP_CERULEAN_CAVE_2F, POOL_CAVE},         // Interior floors (postgame pseudo-legendaries)
    {MAP_CERULEAN_CAVE_B1F, POOL_CAVE},        // Interior floors (postgame pseudo-legendaries)
    
    // Johto cave areas
    {MAP_UNION_CAVE_1F, POOL_CAVE},            // Interior
    {MAP_UNION_CAVE_B1F, POOL_CAVE},           // Interior
    {MAP_UNION_CAVE_B2F, POOL_CAVE},           // Interior
    
    {MAP_DARK_CAVE_VIOLET, POOL_CAVE},         // Floors / passageways
    {MAP_DARK_CAVE_BLACKTHORN, POOL_CAVE},     // Floors / passageways
    
    // Note: Ice Path moved to POOL_SNOW for ice-specific encounters
    
    // Hoenn cave areas
    {MAP_GRANITE_CAVE_1F, POOL_CAVE},          // Interior
    {MAP_GRANITE_CAVE_B1F, POOL_CAVE},         // Interior
    {MAP_GRANITE_CAVE_B2F, POOL_CAVE},         // Interior
    {MAP_GRANITE_CAVE_STEVENS_ROOM, POOL_CAVE}, // Interior
    
    {MAP_METEOR_FALLS_1F_1R, POOL_CAVE},       // Cave interiors
    {MAP_METEOR_FALLS_1F_2R, POOL_CAVE},       // Cave interiors
    {MAP_METEOR_FALLS_B1F_1R, POOL_CAVE},      // Cave interiors
    {MAP_METEOR_FALLS_B1F_2R, POOL_CAVE},      // Cave interiors
    {MAP_METEOR_FALLS_STEVENS_CAVE, POOL_CAVE}, // Cave interiors
    
    {MAP_FIERY_PATH, POOL_CAVE},               // Lava-adjacent tunnels (non-volcano sections)
    
    // Cave of Origin
    {MAP_CAVE_OF_ORIGIN_ENTRANCE, POOL_CAVE},
    {MAP_CAVE_OF_ORIGIN_1F, POOL_CAVE},
    {MAP_CAVE_OF_ORIGIN_B1F, POOL_CAVE},
    
    // Sinnoh cave areas
    {MAP_OREBURGH_MINE_B1F, POOL_CAVE},         // Interior floors
    {MAP_OREBURGH_MINE_B2F, POOL_CAVE},         // Interior floors
    
    {MAP_MT_CORONET_B1F, POOL_CAVE},           // Cave interiors
    {MAP_MT_CORONET_1F_SOUTH, POOL_CAVE},      // Cave interiors
    {MAP_MT_CORONET_1F_NORTH_ROOM1, POOL_CAVE}, // Cave interiors
    {MAP_MT_CORONET_1F_NORTH_ROOM2, POOL_CAVE}, // Cave interiors
    
    // Note: Victory Road cave sections already covered in POOL_MOUNTAIN
    // Note: Stark Mountain and Iron Island would need to be added if they exist in this gamebase
    
    // Water/Ocean areas - Surf/Water encounters
    // Kanto water routes
    {MAP_ROUTE19, POOL_WATER},              // Sea routes / coastlines
    {MAP_ROUTE20, POOL_WATER},              // Sea routes / coastlines

    // Sevii Islands surf routes between islands
    // Note: These would be the water areas between the existing Sevii Island routes

    // Johto water areas
    {MAP_ROUTE32, POOL_WATER},              // Lakeside areas
    {MAP_ROUTE33, POOL_WATER},              // Lakeside areas
    {MAP_ROUTE34, POOL_WATER},              // Lakeside areas
    {MAP_ROUTE35, POOL_WATER},              // Lakeside areas
    {MAP_ROUTE36, POOL_WATER},              // Lakeside areas

    {MAP_LAKE_OF_RAGE, POOL_WATER},         // Open water

    // Whirl Islands - interior waters
    {MAP_WHIRL_ISLANDS_NORTH_WEST_ENTRANCE, POOL_WATER},
    {MAP_WHIRL_ISLANDS_NORTH_EAST_ENTRANCE, POOL_WATER},
    {MAP_WHIRL_ISLANDS_SOUTH_WEST_ENTRANCE, POOL_WATER},
    {MAP_WHIRL_ISLANDS_SOUTH_EAST_ENTRANCE, POOL_WATER},
    {MAP_WHIRL_ISLANDS_B2F, POOL_WATER},
    {MAP_WHIRL_ISLANDS_B3F, POOL_WATER},
    {MAP_WHIRL_ISLANDS_B4F, POOL_WATER},
    {MAP_WHIRL_ISLANDS_B5F, POOL_WATER},
    {MAP_WHIRL_ISLANDS_B6F, POOL_WATER},
    {MAP_WHIRL_ISLANDS_B7F, POOL_WATER},

    // Hoenn water routes
    {MAP_ROUTE105, POOL_WATER},             // Coastal surf
    {MAP_ROUTE106, POOL_WATER},             // Coastal surf
    {MAP_ROUTE107, POOL_WATER},             // Coastal surf
    {MAP_ROUTE108, POOL_WATER},             // Coastal surf
    {MAP_ROUTE118, POOL_WATER},             // Ocean routes
    {MAP_ROUTE119, POOL_WATER},             // Ocean routes
    {MAP_ROUTE120, POOL_WATER},             // Ocean routes
    {MAP_ROUTE124, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE125, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE126, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE127, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE128, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE129, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE130, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE131, POOL_WATER},             // Surfable coastal waters
    {MAP_ROUTE132, POOL_WATER},             // Surfable coastal waters

    // Shoal Cave - tide pools
    {MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM, POOL_WATER},
    {MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM, POOL_WATER},
    {MAP_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM, POOL_WATER},
    {MAP_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM, POOL_WATER},
    {MAP_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM, POOL_WATER},
    {MAP_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM, POOL_WATER},
    {MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM, POOL_WATER},

    // Sinnoh water areas
    {MAP_ROUTE205_NORTH, POOL_WATER},       // Rivers, lakes, coastal zones
    {MAP_ROUTE205_SOUTH, POOL_WATER},       // Rivers, lakes, coastal zones
    {MAP_ROUTE206_NORTH, POOL_WATER},       // Rivers, lakes, coastal zones
    {MAP_ROUTE206_SOUTH, POOL_WATER},       // Rivers, lakes, coastal zones
    {MAP_ROUTE208_ACCESS, POOL_WATER},      // Rivers, lakes, coastal zones
    {MAP_ROUTE209_ACCESS, POOL_WATER},      // Rivers, lakes, coastal zones
    {MAP_ROUTE212_ACCESS, POOL_WATER},      // Rivers, lakes, coastal zones
    {MAP_ROUTE213_ACCESS, POOL_WATER},      // Rivers, lakes, coastal zones

    // Lake Verity, Lake Valor, Lake Acuity - open water
    {MAP_LAKE_VERITY, POOL_WATER},
    {MAP_LAKE_VALOR, POOL_WATER},
    {MAP_LAKE_ACUITY, POOL_WATER},
    {MAP_LAKE_VERITY_CAVE, POOL_WATER},
    {MAP_LAKE_VALOR_CAVE, POOL_WATER},
    {MAP_LAKE_ACUITY_CAVE, POOL_WATER},

    {MAP_ROUTE218, POOL_WATER},             // River/marsh intersections
    {MAP_ROUTE219, POOL_WATER},             // River/marsh intersections
    {MAP_ROUTE218_EAST, POOL_WATER},        // River/marsh intersections
    {MAP_ROUTE218_WEST, POOL_WATER},        // River/marsh intersections
    {MAP_ROUTE220, POOL_WATER},             // River/marsh intersections
    {MAP_ROUTE221, POOL_WATER},             // River/marsh intersections
    {MAP_ROUTE222, POOL_WATER},             // River/marsh intersections
    {MAP_ROUTE222_ACCESS, POOL_WATER},      // River/marsh intersections
    {MAP_ROUTE225_ACCESS, POOL_WATER},      // River/marsh intersections
    {MAP_ROUTE226_ACCESS, POOL_WATER},      // River/marsh intersections

    // Underwater routes
    {MAP_UNDERWATER_ROUTE124, POOL_WATER},
    {MAP_UNDERWATER_ROUTE126, POOL_WATER},
    {MAP_UNDERWATER_ROUTE127, POOL_WATER},
    {MAP_UNDERWATER_ROUTE128, POOL_WATER},
    {MAP_UNDERWATER_ROUTE129, POOL_WATER},
    {MAP_UNDERWATER_ROUTE105, POOL_WATER},
    {MAP_UNDERWATER_ROUTE125, POOL_WATER},

    // Special areas
    {MAP_TOURNAMENT_ISLAND, POOL_WATER},
    {MAP_ROUTE213B, POOL_WATER},
    
    // Cave areas (these would use ROCKS encounter areas)
    // Maps with ROCKS areas will automatically use POOL_CAVE
    
    // Power Plant / Industrial areas - Electric/Steel/Industrial
    // Kanto Power Plant areas
    {MAP_POWER_PLANT, POOL_POWERPLANT},          // Near Cerulean - primary high-level Electric/Steel spawns
    
    // Johto industrial areas
    {MAP_VALLEY_WINDWORKS, POOL_POWERPLANT},     // High-tech wind/industrial area
    {MAP_GOLDENROD_CITY_UNDERGROUND, POOL_POWERPLANT}, // Underground Electric/Steel spawns
    {MAP_GOLDENROD_CITY_UNDERGROUND_NORTH_ENTRANCE, POOL_POWERPLANT},
    {MAP_GOLDENROD_CITY_UNDERGROUND_SOUTH_ENTRANCE, POOL_POWERPLANT},
    {MAP_GOLDENROD_CITY_UNDERGROUND_B1F, POOL_POWERPLANT},
    {MAP_GOLDENROD_CITY_UNDERGROUND_WAREHOUSE, POOL_POWERPLANT},
    {MAP_GOLDENROD_CITY_MAGNET_TRAIN_STATION, POOL_POWERPLANT}, // Electric/Steel spawns
    
    // Hoenn industrial areas
    {MAP_MAUVILLE_CITY, POOL_POWERPLANT},        // Power Plant, industrial zones
    {MAP_ROUTE110, POOL_POWERPLANT},            // Electrical pylons and high-tech installations
    {MAP_ROUTE111, POOL_POWERPLANT},            // Electrical pylons and high-tech installations
    
    // Sinnoh industrial areas
    {MAP_CANALAVE_CITY, POOL_POWERPLANT},       // Industrial / Electric zones
    {MAP_VALLEY_WINDWORKS, POOL_POWERPLANT},    // Main factory
    {MAP_SUNYSHORE_CITY, POOL_POWERPLANT},      // High-level Electric/Steel spawns
    {MAP_ROUTE218, POOL_POWERPLANT},            // Industrial areas / pylons
    {MAP_ROUTE219, POOL_POWERPLANT},            // Industrial areas / pylons
    {MAP_ROUTE218_EAST, POOL_POWERPLANT},       // Industrial areas / pylons
    {MAP_ROUTE218_WEST, POOL_POWERPLANT},       // Industrial areas / pylons
    
    // Snow / Ice / Alpine areas
    // Kanto snow areas (if applicable)
    // Note: Ice Path and Mt. Silver moved to appropriate sections
    
    // Johto snow areas
    {MAP_ICE_PATH, POOL_SNOW},                 // Main ice cave and tunnels
    {MAP_ICE_PATH_B1F, POOL_SNOW},             // Ice cave and tunnels
    {MAP_ICE_PATH_B1F_2, POOL_SNOW},           // Ice cave and tunnels
    {MAP_ICE_PATH_B2F, POOL_SNOW},             // Ice cave and tunnels
    {MAP_ICE_PATH_B2F_2, POOL_SNOW},           // Ice cave and tunnels
    {MAP_ICE_PATH_B3F, POOL_SNOW},             // Ice cave and tunnels
    
    // Sinnoh snow areas
    {MAP_ROUTE216, POOL_SNOW},                // Snowy mountain passes
    {MAP_ROUTE217, POOL_SNOW},                // Snowy mountain passes
    {MAP_ROUTE218, POOL_SNOW},                // Tundra/ice plains (moved from industrial)
    {MAP_ROUTE219, POOL_SNOW},                // Tundra/ice plains (moved from industrial)
    {MAP_ROUTE220, POOL_SNOW},                // Tundra/ice plains
    {MAP_ROUTE221, POOL_SNOW},                // Tundra/ice plains
    {MAP_SNOWPOINT_CITY, POOL_SNOW},           // Surrounding snow routes
    
    // Note: Mt. Coronet northern snowy peaks would be added if they exist as separate maps
    // Note: Stark Mountain snow-covered upper slopes would be added if they exist
    
    // Graveyard / Ghost / Dark areas - Haunted / Ghost / Dark
    // Kanto graveyard areas
    {MAP_LAVENDER_TOWN, POOL_GRAVEYARD},           // Main haunted town
    {MAP_LAVENDER_TOWN_POKEMON_CENTER_1F, POOL_GRAVEYARD}, // Haunted areas
    {MAP_LAVENDER_TOWN_POKEMON_CENTER_2F, POOL_GRAVEYARD}, // Haunted areas
    {MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE, POOL_GRAVEYARD}, // Haunted house
    {MAP_LAVENDER_TOWN_HOUSE1, POOL_GRAVEYARD},    // Haunted house
    {MAP_LAVENDER_TOWN_HOUSE2, POOL_GRAVEYARD},    // Haunted house
    
    // Johto graveyard areas
    // Note: Pokémon Tower would be added if it exists in this gamebase
    // Note: Ruins of Alph would be added if it exists in this gamebase
    
    // Hoenn graveyard areas
    {MAP_MT_PYRE_1F, POOL_GRAVEYARD},            // Main area + surrounding cemetery paths
    {MAP_MT_PYRE_2F, POOL_GRAVEYARD},            // Main area + surrounding cemetery paths
    {MAP_MT_PYRE_3F, POOL_GRAVEYARD},            // Main area + surrounding cemetery paths
    {MAP_MT_PYRE_4F, POOL_GRAVEYARD},            // Main area + surrounding cemetery paths
    {MAP_MT_PYRE_5F, POOL_GRAVEYARD},            // Main area + surrounding cemetery paths
    {MAP_MT_PYRE_6F, POOL_GRAVEYARD},            // Main area + surrounding cemetery paths
    {MAP_MT_PYRE_EXTERIOR, POOL_GRAVEYARD},      // Surrounding cemetery paths
    {MAP_MT_PYRE_SUMMIT, POOL_GRAVEYARD},        // Summit cemetery area
    
    // Abandoned Ship - ghost-infested rooms
    {MAP_ABANDONED_SHIP_CORRIDORS_1F, POOL_GRAVEYARD}, // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_ROOMS_1F, POOL_GRAVEYARD},     // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_CORRIDORS_B1F, POOL_GRAVEYARD}, // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_ROOMS_B1F, POOL_GRAVEYARD},     // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_ROOMS2_B1F, POOL_GRAVEYARD},    // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_ROOM_B1F, POOL_GRAVEYARD},      // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_ROOMS2_1F, POOL_GRAVEYARD},     // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, POOL_GRAVEYARD}, // Ghost-infested rooms
    {MAP_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS, POOL_GRAVEYARD}, // Ghost-infested rooms
    
    // Sinnoh graveyard areas
    {MAP_ETERNA_FOREST, POOL_GRAVEYARD},          // Old Chateau - Eterna Forest
    {MAP_ETERNA_FOREST_A, POOL_GRAVEYARD},        // Old Chateau - Eterna Forest
    
    // Note: Lost Tower / Mt. Coronet haunted patches would be added if they exist
    // Note: Manor Ruins would be added if they exist
};

// Rod Pool configurations - Fishing encounters
// Maps that use OLD_ROD (Magikarp, low-level water Pokémon)
static const struct MapPoolConfig sOldRodPoolOverrides[] = {
    // Early game fishing spots
    {MAP_ROUTE101, POOL_OLD_ROD},         // Littleroot → Oldale Town
    {MAP_ROUTE102, POOL_OLD_ROD},         // Oldale → Petalburg
    {MAP_ROUTE103, POOL_OLD_ROD},         // Petalburg → Rustboro outskirts
    {MAP_ROUTE104, POOL_OLD_ROD},         // Rustboro → Petalburg
    {MAP_LITTLEROOT_TOWN, POOL_OLD_ROD},  // Early game fishing
    {MAP_OLDALE_TOWN, POOL_OLD_ROD},      // Early game fishing
    {MAP_DEWFORD_TOWN, POOL_OLD_ROD},     // Early game fishing
    {MAP_PETALBURG_CITY, POOL_OLD_ROD},   // Early game fishing
    {MAP_RUSTBORO_CITY, POOL_OLD_ROD},    // Early game fishing
    {MAP_SLATEPORT_CITY, POOL_OLD_ROD},   // Early game fishing
};

// Maps that use GOOD_ROD (Goldeen, Poliwag, Tentacool)
static const struct MapPoolConfig sGoodRodPoolOverrides[] = {
    // Mid-game fishing spots
    {MAP_ROUTE105, POOL_GOOD_ROD},        // Coastal surf areas
    {MAP_ROUTE106, POOL_GOOD_ROD},        // Coastal surf areas
    {MAP_ROUTE107, POOL_GOOD_ROD},        // Coastal surf areas
    {MAP_ROUTE108, POOL_GOOD_ROD},        // Coastal surf areas
    {MAP_ROUTE110, POOL_GOOD_ROD},        // Mauville → Verdanturf
    {MAP_ROUTE118, POOL_GOOD_ROD},        // Route 117 → Fallarbor
    {MAP_ROUTE119, POOL_GOOD_ROD},        // Route 120 section
    {MAP_LAKE_OF_RAGE, POOL_GOOD_ROD},    // Lake of Rage
    {MAP_MAUVILLE_CITY, POOL_GOOD_ROD},   // Mid-game fishing
    {MAP_VERDANTURF_TOWN, POOL_GOOD_ROD}, // Mid-game fishing
    {MAP_FALLARBOR_TOWN, POOL_GOOD_ROD},  // Mid-game fishing
    {MAP_FORTREE_CITY, POOL_GOOD_ROD},    // Mid-game fishing
    {MAP_LILYCOVE_CITY, POOL_GOOD_ROD},    // Mid-game fishing
    {MAP_MOSSDEEP_CITY, POOL_GOOD_ROD},   // Mid-game fishing
    {MAP_SOOTOPOLIS_CITY, POOL_GOOD_ROD}, // Mid-game fishing
};

// Maps that use SUPER_ROD (Gyarados, Feebas, Luvdisc, Dratini, high-level fish)
static const struct MapPoolConfig sSuperRodPoolOverrides[] = {
    // Late-game and special fishing spots
    {MAP_ROUTE119, POOL_SUPER_ROD},       // Weather Institute area (Feebas)
    {MAP_ROUTE120, POOL_SUPER_ROD},       // Lakeside and swampy forest edges
    {MAP_ROUTE121, POOL_SUPER_ROD},       // Lakeside and swampy forest edges
    {MAP_ROUTE124, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE125, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE126, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE127, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE128, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE129, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE130, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE131, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE132, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE133, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_ROUTE134, POOL_SUPER_ROD},       // Surfable coastal waters
    {MAP_EVER_GRANDE_CITY, POOL_SUPER_ROD}, // Late-game fishing
    {MAP_PACIFIDLOG_TOWN, POOL_SUPER_ROD}, // Late-game fishing
    {MAP_SAFARI_ZONE_NORTHWEST, POOL_SUPER_ROD}, // Safari Zone fishing
    {MAP_SAFARI_ZONE_NORTH, POOL_SUPER_ROD},     // Safari Zone fishing
    {MAP_SAFARI_ZONE_SOUTHWEST, POOL_SUPER_ROD}, // Safari Zone fishing
    {MAP_SAFARI_ZONE_SOUTH, POOL_SUPER_ROD},     // Safari Zone fishing
    {MAP_SAFARI_ZONE_NORTHEAST, POOL_SUPER_ROD}, // Safari Zone fishing
    {MAP_SAFARI_ZONE_SOUTHEAST, POOL_SUPER_ROD}, // Safari Zone fishing
    {MAP_LAKE_VERITY, POOL_SUPER_ROD},    // Lake Verity (high-level)
    {MAP_LAKE_VALOR, POOL_SUPER_ROD},     // Lake Valor (high-level)
    {MAP_LAKE_ACUITY, POOL_SUPER_ROD},    // Lake Acuity (high-level)
    {MAP_WHIRL_ISLANDS_B2F, POOL_SUPER_ROD},     // Whirl Islands (Dratini)
    {MAP_WHIRL_ISLANDS_B3F, POOL_SUPER_ROD},     // Whirl Islands (Dratini)
    {MAP_WHIRL_ISLANDS_B4F, POOL_SUPER_ROD},     // Whirl Islands (Dratini)
    {MAP_WHIRL_ISLANDS_B5F, POOL_SUPER_ROD},     // Whirl Islands (Dratini)
    {MAP_WHIRL_ISLANDS_B6F, POOL_SUPER_ROD},     // Whirl Islands (Dratini)
    {MAP_WHIRL_ISLANDS_B7F, POOL_SUPER_ROD},     // Whirl Islands (Dratini)
};

// Function to get pool type for a specific map
enum WildPoolType GetPoolTypeForMap(u16 mapId, enum WildPokemonArea area);

#endif // GUARD_CONSTANTS_MAP_POOLS_H
