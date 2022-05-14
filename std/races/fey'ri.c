// Bonuses in lib: all subraces; +2 vs charm spells and sleep immunity, see /std/magic/spell.
// added Szarkai for specialty character support - all modifiers per drow race. -N, 03/11.
// Fey'ri new subrace. N, 1/14.
// note - /d/shadowgate/colors/elf has manual subrace select so that szarkai don't appear. Wild elves are manually restricted
// also; the only case of a HM-restricted non-LA subrace in the game, so I didn't bother installing massive lib for it. N, 8/15.
// Made a copy of this into a separate fey'ri file since their appearance overall is so different. Previously, a fey'ri could disguise themselves purely through describes, not needing their alter self innate at all.

#include <std.h>
#include <objects.h>
inherit DAEMON;

void create()
{
    ::create();
}

// age at which each age cat starts: normal, middle, old, venerable
int* age_brackets()
{
    return ({ 102, 175, 233, 350 });
}

int* restricted_alignments(string subrace)
{
    return ({ 1, 2, 4, 5, 7, 8 });
}

string* restricted_classes(string subrace)
{
    return ({ "psion", "psywarrior", "monk", "druid" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string* restricted_deities(string subrace)
{
    return ({ "jarmila", "edea", "callamir", "kreysneothosies", "seija" });
}

int* stat_mods(string subrace)   // stats in order: str, dex, con, int, wis, cha
{
    return ({ 0, 2, -2, 2, 0, 0 }); break;
}

mapping skill_mods(string subrace)
{
    return ([ "perception" : 2]); break;
}

int natural_AC(string subrace)
{
    return 0;
}

int sight_bonus(string subrace)
{
    return 3;
}

mapping daily_uses(string subrace)
{
    return (["alter self" : -1 ]);
}

mapping query_racial_innate(string subrace)
{
    return (["alter self" : (["type" : "spell", "casting level" : 0.5, "daily uses" : -1, "delay" : 1, "uses left" : -1,"refresh time" : -1, "level required" : 0, "class specific" : 0]), ]);
}

int misc_bonuses(string subrace, string bonus)
{
    return 0;
}

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int* min_stats()
{
    return ({ 3, 7, 6, 8, 3, 8 });
}

int* max_stats()
{
    return ({ 18, 19, 17, 18, 18, 18 });
}

int* stat_adj()
{
    return ({ 0, 1, -1, 0, 0, 0 });
}

int is_restricted()
{
    return 0;
}                                 // restricted races by approval

int is_rollable() { return 0; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name()
{
    return "fey'ri";
}

// gets used in a forumla based on con to determine actual weight
int weight()
{
    return 8000;
}

int fingers()
{
    return 5;
}

string* wielding_limbs()
{
    return ({ "right hand", "left hand" });
}

mapping monster_stat_rolls()
{
    return ([ "str" : 0, "con" : 0, "int" : 5, "wis" : 8, "dex" : 3, "cha" : 1 ]);
}

int size()
{
    return 2;
}

string* limbs()
{
    return ({ "head",
              "right arm",
              "right hand",
              "left arm",
              "left hand",
              "left leg",
              "left foot",
              "right leg",
              "right foot",
              "waist",
              "neck" });
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender)
{
    if (gender == "male") {
        return 53;
    }
    return 53;
}

int height_mod(string gender)
{
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender)
{
    if (gender == "male") {
        return 85;
    }
    return 80;
}

int weight_mod(string gender)
{
    return 6;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map = ([]);

    map["num"] = 3;

    switch (gender) {
    case "male":
        map["base"] = 90;
        switch (height) {
        case 55..57: map["adjust"] = -10; map["die"] = 15; break;

        case 58..62: map["adjust"] = 0;   map["die"] = 10; break;

        case 63..65: map["adjust"] = 0;   map["die"] = 15; break;

        case 66..68: map["adjust"] = 15;  map["die"] = 15; break;

        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }

    default:
        map["base"] = 70;
        switch (height) {
        case 50..52: map["adjust"] = -15; map["die"] = 15; break;

        case 53..57: map["adjust"] = 0;   map["die"] = 10; break;

        case 58..60: map["adjust"] = 0;   map["die"] = 15; break;

        case 61..63: map["adjust"] = 5;   map["die"] = 15; break;

        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string* query_hair_colors(string subrace)
{
    string* choices = ({});

    choices += ({ "golden", "crimson", "scarlet", "auburn", "ebony" });
    choices += ({ "red" });
    choices += ({ "blonde", "black" });

    return choices;
}

string* query_eye_colors(string subrace, int cha)
{
    string* choices = ({});

    choices += ({ "emerald", "golden" });
    choices += ({ "amber" });
    choices += ({ "green" });

    return choices;
}

string* query_subraces(object who)
{
    return ({  });
}

int is_pk_race(string subrace)
{
    return 1;
}

string* query_languages(string subrace)
{
    return (["required" : ({ "abyssal", "common" }), "optional" : ({ "drow", "undercommon", "orcish", "elven", "infernal", "draconic" })]);
}
