#include <std.h>
#include <clock.h>
#include <magic.h>

#define WTROB "/d/magic/obj/breathob.c"

inherit SPELL;
object breathob;

void create(){
    ::create();
    set_spell_name("water breathing");
    set_spell_level(([ "mage" : 3, "cleric" : 3, "druid" : 3, "psywarrior" : 1, "psion" : 1, "magus" : 3 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS water breathing [on TARGET]");
    set_description("This spell allows the target to breathe water for a limited period of time.");
    set_verbal_comp();
    set_somatic_comp();
    //set_target_required(1);
	set_helpful_spell(1);
}

int preSpell(){
    if(!target || !objectp(target)) target = caster;
    
    if(present("underwtr_breath_ob", target)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^"+target->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ can already breathe water.%^CRST%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    if (environment(target)!=place){
        tell_object(caster,"%^RESET%^%^CRST%^%^C059%^Your target has left the area!%^CRST%^");
        this_object()->remove();
        return;
    }

    spell_successful();
    tell_room(environment(caster), "%^RESET%^%^CRST%^%^C255%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C033%^ touches "+target->possessive()+" nose and mouth lightly.%^CRST%^", ({caster, target}) );
    if(caster == target){
        tell_object(caster, "%^RESET%^%^CRST%^%^C255%^You touch your nose and mouth lightly, granting yourself the ability to breathe %^C033%^w%^C039%^a%^C045%^t%^C033%^e%^C039%^r%^RESET%^%^C255%^.%^CRST%^");
    }
    else{
        tell_object(caster, "%^RESET%^%^CRST%^%^C255%^You touch "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^'s nose and mouth lightly, granting "+target->query_objective()+" the ability to breathe %^C033%^w%^C039%^a%^C045%^t%^C033%^e%^C039%^r%^RESET%^%^C255%^.%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C255%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^ touches your nose and mouth lightly, granting you the power to breathe %^C033%^w%^C039%^a%^C045%^t%^C033%^e%^C039%^r%^RESET%^%^C255%^.%^CRST%^");
    }

    breathob = new(WTROB);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    breathob->set_maxtime(spell_duration);
    breathob->set_property("spell", this_object());
    breathob->set_property("spelled", ({this_object()}));
    addSpellToCaster();
    breathob->move(target);
}

void dest_effect(){
    tell_object(target, "%^RESET%^%^CRST%^%^C059%^You feel the power to breathe %^C033%^w%^C039%^a%^C045%^t%^C033%^e%^C039%^r %^RESET%^%^C059%^leave you.%^CRST%^");
    if(objectp(breathob))
      breathob->remove();
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();

}

void reverse_spell(){
    spell_effect(-100);
}

