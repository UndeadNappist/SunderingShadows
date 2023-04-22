// repose sphere, summons a spectral mount. Nienne, 04/07
//Moved to level 3 after conversations with Nienne
//in rebalancing the domains ~Circe~ 4/24/08

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define HORSE "/d/magic/mon/mounts/spectral"
inherit SPELL;

object ob;

void create(){
    ::create();
    set_spell_name("phantom steed");
    set_spell_level(([ "bard" : 3, "mage" : 3, "oracle" : 3, "psion" : 2, "magus" : 3 ]));
    set_mystery("whimsy");
    set_discipline("nomad");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS phantom steed");
    set_description("By means of this spell, the caster summons forth a ghostly horse to serve as his faithful mount and to help defend them. This spell will not work if you are already mounted.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string(){
    tell_object(caster, "%^C101%^You bring both hands forward, and then beckon them together towards yourself%^CRST%^.");
    tell_room(place, "%^C101%^"+caster->query_cap_name()+"%^C101%^ brings both hands forward, and then beckons them together towards "+caster->query_objective()+"self%^CRST%^.", caster);
    return "display";
}

int preSpell(){
    if(caster->query_in_vehicle()){
        tell_object(caster, "%^C059%^A mount will not come if you are already mounted.%^CRST%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){

    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);

    tell_object(caster, "%^C101%^A faint, translucent %^C051%^m%^C045%^i%^C039%^s%^C033%^t %^C101%^becomes apparent in the air before you, forming the outline of a %^C144%^ghostly creature%^C101%^!%^CRST%^");
    tell_room(place, "%^C101%^A faint, translucent %^C051%^m%^C045%^i%^C039%^s%^C033%^t %^C101%^becomes apparent in the air before "+caster->query_cap_name()+"%^C101%^, forming the outline of a %^C144%^ghostly creature%^C101%^!%^CRST%^", caster);
    caster->set_paralyzed(7, "%^C031%^You are still exhausted from summoning a mount!%^CRST%^");
    call_out("mount", 5);
}

void mount(){
    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);

    tell_object(caster, "%^C101%^The ghostly creature slowly becomes clear enough to discern as the outline of a %^C051%^s%^C045%^pe%^C039%^ct%^C033%^ral %^C051%^h%^C045%^o%^C039%^r%^C033%^se%^C101%^, standing before you. It paws the ground with perfectly %^C059%^silent %^C101%^hooves.%^RESET%^");
    tell_room(place, "%^C101%^The ghostly creature slowly becomes clear enough to discern as the outline of a %^C051%^s%^C045%^pe%^C039%^ct%^C033%^ral %^C051%^h%^C045%^o%^C039%^r%^C033%^se%^C101%^, standing before "+caster->query_cap_name()+"%^C101%^. It paws the ground with perfectly %^C059%^silent %^C101%^hooves.%^RESET%^");
    ob = new(HORSE);
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_owner(caster);
    ob->move(place);
    caster->force_me("mount spectral steed");
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

