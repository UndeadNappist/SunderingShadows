// Chernobog (4/7/23)
// Updated after Animate Dead Rework

#include <std.h>

inherit "/cmds/spells/a/_animate_dead";

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("the dead walk");
    set_spell_level(([ "warlock" : 2 ]));
    set_mystery(({}));
    set_syntax("cast CLASS the dead walk [on TYPE]");
    set_damage_desc("raises up to clevel/5 lesser minions");
    set_description("This invocation infuses the area with negative energy to reanimate decayed matter and spare bones into weak, though serviceable, minions. They will follow you and defend you from your enemies. They are undead, so they can be turned, and so forth, but they cannot be dispelled. Many faiths and cultures condemn this spell and similar powers as it serves the caster's selfish, often evil, motives. Frequent users of the spell are believed to be inherently evil. This spell can be directed to create skeletons or zombies, but will produce a mix of both by default."+("/cmds/spells/a/_animate_dead"->extra_help()));
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    set_helpful_spell(1);
    evil_spell(1);
    set_arg_needed(1);
    set_property("undead spell", 1);
}

string query_cast_string(){
    tell_object(caster, "%^C059%^A %^C244%^stillness %^C059%^falls upon the area as you sway gently, tainting your surroundings with %^C030%^n%^C036%^e%^C041%^c%^C036%^r%^C030%^o%^C036%^t%^C041%^i%^C036%^c %^C030%^e%^C036%^n%^C041%^e%^C036%^r%^C030%^g%^C036%^y%^C059%^.%^CRST%^");
    tell_room(place, "%^C059%^A %^C244%^stillness %^C059%^falls upon the area as "+caster->query_cap_name()+"%^C059%^ sways gently.%^CRST%^", caster);
    return "display";
}

