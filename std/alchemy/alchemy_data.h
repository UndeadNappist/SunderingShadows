// Authothed by Spade, 16 March 2023

// Provides:
// Standard difficulties for alchemy
// Critical ingredients for alchemical formulas
// Data about the yield of an alchemical mixture

// IN DEVELOPMENT, NOT IN ACTIVE USE, SUBJECT TO CHANGE //

// Standard Difficulties //
#define TIER_0_DIFFICULTY   0    // Newbie Healing Kit
#define TIER_1_DIFFICULTY  10    // Blue Healing Kit
#define TIER_2_DIFFICULTY  30    // White Healing Kit
#define TIER_3_DIFFICULTY  50    // Pink Healing Kit
#define TIER_4_DIFFICULTY  70    // Gold Healing Kit
#define TIER_5_DIFFICULTY  90    // Red Healing Kit (Feat required)
#define TIER_6_DIFFICULTY 110    // Unobtainable without bonuses

// Critical Reagents for Reactions //
#define FULL_HEAL_CRITICAL_REAGENTS ([ "ashes of a dead star": 1, "heart of an ancient wyrm": 2 ])

#define CURSE_REMOVAL_CRITICAL_REAGENTS ([ "dream fragment": 4 ])
#define     FLAME_OIL_CRITICAL_REAGENTS ([ "tendril of flame": 5, "eye of newt": 4 ])
#define     FROST_OIL_CRITICAL_REAGENTS ([ "breath of winter": 5, "corrupted fey lifeblood": 4 ])
#define    WIZARD_OIL_CRITICAL_REAGENTS ([ "tendril of flame": 5, "lich dust": 1, "nycissa orchid": 1 ])

#define YOUTH_POTION_CRITICAL_REAGENTS ([ "heart of an ancient wyrm": 1, "divine essence": 1 ])

#define  BLINDING_POWDER_CRITICAL_REAGENTS ([ "bone dust": 2, "nutshells": 1 ])
#define NIGHTMARE_POWDER_CRITICAL_REAGENTS ([ "dream fragment": 2, "corrupted fey lifeblood": 1 ])
#define       REZ_POWDER_CRITICAL_REAGENTS ([ "corrupted fey lifeblood": 1 ])

// Our table of recipes
mapping REACTIONS =
([
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                               HEALING POTIONS                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

    // Blue Healing Potion -- Heals 2d6 + 4 HP (4/10/16) after 8 seconds.
    // Max of 5 ingested in a round.
    0: ([ "object"           : "/d/common/obj/potion/healing.c",
          "difficulty"       : TIER_1_DIFFICULTY,
          "critical_reagents": 0 ]),

    // White Healing Potion -- Heals 3d10 + 5 HP (8/20/35) after 8 seconds.
    // Max of 5 ingested in a round.
    0: ([ "object"           : "/d/common/obj/potion/extra_heal.c",
          "difficulty"       : TIER_2_DIFFICULTY,
          "critical_reagents": 0 ]),

    // Pink Healing Potion -- Heals 4d12 + 6 HP (10/30/54) after 8 seconds.
    // Max of 5 ingested in a round.
    0: ([ "object"           : "/d/common/obj/potion/advanced_heal.c",
          "difficulty"       : TIER_3_DIFFICULTY,
          "critical_reagents": 0 ]),

    // Gold Healing Potion -- Heals 6d20 + 20 HP (26/50/80) after 8 seconds.
    // Max of 5 ingested in a round.
    0: ([ "object"           : "/d/common/obj/potion/legendary_heal.c",
          "difficulty"       : TIER_4_DIFFICULTY,
          "critical_reagents": 0 ]),

    // Red Healing Potion -- Heals 8d20 + 20 HP (28/60/100) after 8 seconds.
    // Max of 5 ingested in a round.
    0: ([ "object"           : "/d/common/obj/potion/resplendent_heal.c",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": 0 ]),

    // Full Healing Potion -- Heals all damage after 8 seconds.
    // Weighs 20 units. Made of the dust of a neutron star. Onobtainable, definitely being removed.
    // Lmao.
    0: ([ "object"           : "/d/common/obj/potion/full_heal.c",
          "difficulty"       : TIER_6_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                             TRADITIONAL POTIONS                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

    // Antidote -- Removes poisons
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_3_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Potion of Detect Invisibility -- Legacy potion, don't actually know mechanical specs.
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_4_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Potion of Clear Sight -- Removes blindness status
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_4_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Potion of Optic Transmogrification -- Changes eye color
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_4_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Potion of Hirsute Transmogrification
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_4_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Potion of Gender Inversion
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_4_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Potion of Youth
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_6_DIFFICULTY,
          "critical_reagents": YOUTH_POTION_CRITICAL_REAGENTS ]),


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                                    ELIXRS                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

    // Elixr of Beat's Endurance
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Bull's Strength
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Cat's Grace
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Eagle's Splendor
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Fox's Cunning
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Owl's Wisdom
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Barkskin
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Bless
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Darkvision
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Displacement
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Energy Resistance
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Grace
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Haste
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Heroism
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Insight
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Levitation
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Misdirection
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Rejuvenation
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Spider Climb
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Sticky Fingerd
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Stoneskin
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Tenacity
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Pass Without Trace
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),

    // Elixr of Water Breathing
    0: ([ "object"           : "/d/common/obj/potion/",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FULL_HEAL_CRITICAL_REAGENTS ]),


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                               WEAPON COATINGS                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

    // Oil of Curse Removal -- Strips curses from gear.
    0: ([ "object"           : "/d/common/obj/brewing/oils/oil_of_curse_removal.c",
          "difficulty"       : TIER_3_DIFFICULTY,
          "critical_reagents": CURSE_REMOVAL_CRITICAL_REAGENTS ]),

    // Oil of Fire -- Augments a weapon with +5 fire damage per hit.
    0: ([ "object"           : "/d/common/obj/brewing/oils/fire_oil.c",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FLAME_OIL_CRITICAL_REAGENTS ]),

    // Oil of Frost -- Augments a weapon with +5 cold damage per hit.
    0: ([ "object"           : "/d/common/obj/brewing/oils/frost_oil.c",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FROST_OIL_CRITICAL_REAGENTS ]),

    // Oil of Lightning -- Augments a weapon with +5 electricity damage per hit.
    0: ([ "object"           : "/d/common/obj/brewing/oils/lightning_oil.c",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FROST_OIL_CRITICAL_REAGENTS ]),

    // Oil of Causticity -- Augments a weapon with +5 acid damage per hit.
    0: ([ "object"           : "/d/common/obj/brewing/oils/caustic_oil.c",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FROST_OIL_CRITICAL_REAGENTS ]),

    // Oil of Reverberation -- Augments a weapon with +5 sonic damage per hit.
    0: ([ "object"           : "/d/common/obj/brewing/oils/vibration_oil.c",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FROST_OIL_CRITICAL_REAGENTS ]),

    // Oil of Casting -- Allows a caster to invoke a spell whilst holding an oiled weapon.
    0: ([ "object"           : "/d/common/obj/brewing/oils/wizard_oil.c",
          "difficulty"       : TIER_3_DIFFICULTY,
          "critical_reagents": WIZARD_OIL_CRITICAL_REAGENTS ]),


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                                   POWDERS                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

    // Blinding Powder -- Blind thy target.
    0: ([ "object"           : "/d/common/obj/brewing/powders/blinding_powder.c",
          "difficulty"       : TIER_2_DIFFICULTY,
          "critical_reagents": BLINDING_POWDER_CRITICAL_REAGENTS ]),

    // Nightmare Powder -- Inflict one of several debuffs.
    0: ([ "object"           : "/d/underdark/ud_ruins/obj/illusion_powder.c",
          "difficulty"       : TIER_3_DIFFICULTY,
          "critical_reagents": REZ_POWDER_CRITICAL_REAGENTS ]),

    // Power of Life -- Ressurect a target corpse to near-death status.
    0: ([ "object"           : "/d/common/obj/brewing/powders/powder_of_life.c",
          "difficulty"       : TIER_5_DIFFICULTY,
          "critical_reagents": FROST_OIL_CRITICAL_REAGENTS ]),


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                                    DRUGS                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

    // Dwarf's Pride Tobacco
    0: ([ "object"           : "/d/common/obj/",
          "difficulty"       : TIER_1_DIFFICULTY,
          "critical_reagents": BLINDING_POWDER_CRITICAL_REAGENTS ]),

    // Halfling's Homeblend Tobacco
    0: ([ "object"           : "/d/common/obj/",
          "difficulty"       : TIER_1_DIFFICULTY,
          "critical_reagents": BLINDING_POWDER_CRITICAL_REAGENTS ]),

    // Luxury of Tharis Tobacco
    0: ([ "object"           : "/d/common/obj/",
          "difficulty"       : TIER_1_DIFFICULTY,
          "critical_reagents": BLINDING_POWDER_CRITICAL_REAGENTS ]),

    // Pirate's Booty Tobacco (lol)
    0: ([ "object"           : "/d/common/obj/",
          "difficulty"       : TIER_1_DIFFICULTY,
          "critical_reagents": BLINDING_POWDER_CRITICAL_REAGENTS ]),

    // Tsarven Tobacco
    0: ([ "object"           : "/d/common/obj/",
          "difficulty"       : TIER_1_DIFFICULTY,
          "critical_reagents": BLINDING_POWDER_CRITICAL_REAGENTS ]),

    // White Dragon Tobacco
    0: ([ "object"           : "/d/common/obj/",
          "difficulty"       : TIER_1_DIFFICULTY,
          "critical_reagents": BLINDING_POWDER_CRITICAL_REAGENTS ]),

]);
