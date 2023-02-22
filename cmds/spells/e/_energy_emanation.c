#include <std.h>
#include <priest.h>

inherit SPELL;
int counter, element, random_element, flag;
string myenergy, mycolor;

#define MYELEMENT ({ "cold", "electricity", "fire", "sonic" })
#define MYENERGY ({ "%^C039%^f%^C045%^r%^C051%^ig%^C045%^i%^C039%^d%^C033%^", "%^C228%^e%^C231%^l%^C226%^e%^C228%^ctr%^C231%^i%^C228%^ca%^C226%^l%^C100%^", "%^C208%^f%^C214%^i%^C208%^e%^C202%^r%^C208%^y%^C124%^", "%^C218%^s%^C212%^o%^C206%^n%^C212%^i%^C218%^c%^C090%^" })
#define MYCOLOR ({ "an %^C045%^i%^C051%^c%^C045%^y %^C039%^b%^C045%^l%^C051%^u%^C045%^e%^C033%^", "a %^C228%^go%^C231%^l%^C226%^d%^C228%^en y%^C226%^e%^C228%^l%^C231%^l%^C228%^o%^C226%^w%^C100%^", "a %^C124%^sm%^C160%^ol%^C196%^d%^C160%^er%^C124%^in%^C160%^g %^C196%^re%^C160%^d%^C124%^", "an %^C099%^i%^C105%^r%^C033%^i%^C027%^d%^C026%^e%^C032%^s%^C037%^c%^C043%^e%^C044%^n%^C038%^t%^C090%^" })

void create(){
    ::create();
    set_spell_name("energy emanation");
    set_spell_level( ([ "psywarrior" : 2, "psion" : 2 ]) );
    set_spell_sphere("psychokinesis");
    set_discipline("kineticist");
    set_syntax("cast CLASS energy emanation [on cold|electricity|fire|sonic|random]");
    set_description("This power surrounds the psionic character in a glowing halo of energy that lashes out at all those nearby. The amount of damage grows with the manifester, and she can learn to control it better through feats like Perfect Caster. Upon manifesting the power, the psionic character chooses the energy type - cold, electricity, fire, sonic, or random. If no type is designated, it will default to a random selection of energies.");
    set_verbal_comp();
    set_arg_needed();
    traveling_aoe_spell(1);
}

string query_cast_string(){
   return "%^RESET%^%^CRST%^%^C255%^The air around "+caster->query_cap_name()+" %^RESET%^%^CRST%^%^C255%^begins to %^C220%^g%^C226%^l%^C220%^o%^C214%^w %^C255%^faintly.%^CRST%^";

}

int preSpell(){
    if (caster->query_property("energy_emanated")){
      tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already under the effects of this power!%^CRST%^");
        return 0;
    }
    return 1;
}


void spell_effect(int prof){
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    random_element = 0;
    if(!arg){
        arg = "random";
        random_element = 1;
    }
    switch(arg){
        case "cold":        element = 0; break;
        case "electricity": element = 1; break;
        case "fire":        element = 2; break;
        case "sonic":       element = 3; break;
        default:            element = random(4); random_element = 1;
    }
    
    tell_room(place, "%^RESET%^%^CRST%^%^C255%^The aura surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^ brightens and takes on "+MYCOLOR[element]+" hue %^C255%^as it emanates "+MYENERGY[element]+" energy%^C255%^!%^CRST%^", caster);
    tell_object(caster, "%^RESET%^%^CRST%^%^C255%^The aura surrounding you brightens and takes on "+MYCOLOR[element]+" hue %^C255%^as it emanates "+MYENERGY[element]+" energy%^C255%^!%^CRST%^");
    caster->set_property("energy_emanated", 1);
    caster->set_property("spelled", ({this_object()}) );
    addSpellToCaster();
    spell_successful();
    execute_attack();
    call_out("room_check",ROUND_LENGTH);
}

void room_check(){
    if(!objectp(caster) || !objectp(environment(caster))){
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(environment(caster));

    call_out("room_check", ROUND_LENGTH*2);
    return;
}

void execute_attack(){
    int i, done;
    object *ppl = ({}), *enemies = ({});
    if(!flag){
        ::execute_attack();
        flag = 1;
        return;
    }
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    
    ppl = caster->query_attackers();
    ppl = filter_array(ppl, "is_non_immortal", FILTERS_D);
    if(member_array(caster,ppl) != -1){
        ppl -= ({caster});
    }
    ppl = target_filter(ppl);

    ppl = distinct_array(ppl);
    enemies += caster->query_attackers();
    enemies = distinct_array(enemies);
    if(sizeof(ppl)){
        done = 0;
        define_base_damage(0);

        tell_object(caster, "%^RESET%^%^CRST%^%^C255%^The halo of "+MYENERGY[element]+" energy %^C255%^surrounding you lashes out at your enemies!%^CRST%^");
        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C255%^The halo of "+MYENERGY[element]+" energy %^C255%^surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^ lashes out at "+caster->query_possessive()+" enemies!%^CRST%^", ({caster, ppl[i]}));

        for(i=0;i<sizeof(ppl);i++){
            if(!objectp(ppl[i])) continue;
            tell_object(ppl[i], "%^RESET%^%^CRST%^%^C255%^The halo of "+MYENERGY[element]+" energy %^C255%^surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^ lashes out at you!%^CRST%^");
            do_spell_damage(ppl[i],ppl[i]->return_target_limb(), sdamage, MYELEMENT[element]);
            if(member_array(ppl[i], enemies) == -1){
                spell_kill(ppl[i], caster);
            }
            done++;
        }
    }
    
    if(random_element) element = random(4);
    counter++;
    if(counter > (clevel * 6)){
        dest_effect();
        return;
    }
    else environment(caster)->addObjectToCombatCycle(this_object(), 1);
}

void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C100%^You feel the energy drain from you.%^CRST%^");
        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C100%^The field of energy surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ fades away.%^CRST%^", caster);
        caster->remove_property("energy_emanated");
    }
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

