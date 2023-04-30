// Chernobog (4/7/23)
// Updated after Animate Dead Rework

#include <std.h>

inherit "/cmds/spells/a/_animate_dead";

void create(){
    ::create();
    set_spell_name("dance of the dead");
    set_spell_level(([ "bard" : 4 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS dance of the dead [on TYPE]");
    set_damage_desc("raises up to clevel/5 lesser minions");
    set_description("With this spell, the bard plays or sings a dirge to the deceased, their voice enriched with magic and causing carrion and stray bones to rise up and join in the dance. These minions are weak, but can be shaped quickly and serve the will of the bard. Many faiths and cultures condemn this spell and similar powers as it serves the caster's selfish, often evil, motives. Frequent users of the spell are believed to be inherently evil. This spell can be directed to create skeletons or zombies, but will produce a mix of both by default."+("/cmds/spells/a/_animate_dead"->extra_help()));
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    set_helpful_spell(1);
    evil_spell(1);
    set_arg_needed(1);
    set_property("undead spell", 1);
}

string query_cast_string(){
    return "%^C243%^"+caster->query_cap_name()+"%^C243%^ begins to play a %^C099%^l%^C105%^o%^C099%^w%^C243%^, %^C098%^r%^C104%^e%^C110%^s%^C116%^on%^C110%^a%^C104%^t%^C098%^e %^C116%^tone%^C243%^.%^CRST%^";
}

void fail(){
    tell_object(caster, "%^C160%^Your dance is already full!%^CRST%^");
    return;
}

void succeed(){
    tell_object(caster, "%^C243%^You play a %^C099%^d%^C105%^i%^C111%^s%^C117%^c%^C111%^o%^C105%^r%^C099%^dant%^C243%^, %^C098%^h%^C104%^a%^C110%^u%^C116%^n%^C110%^t%^C104%^i%^C098%^ng%^C243%^ %^C116%^melody%^C243%^ and the corpses begin to stir!%^CRST%^");
    tell_room(place, "%^C243%^"+caster->query_cap_name()+" plays a %^C099%^d%^C105%^i%^C111%^s%^C117%^c%^C111%^o%^C105%^r%^C099%^dant%^C243%^, %^C098%^h%^C104%^a%^C110%^u%^C116%^n%^C110%^t%^C104%^i%^C098%^ng%^C243%^ %^C116%^melody%^C243%^ and the corpses begin to stir!%^CRST%^", caster);
    return;
}

