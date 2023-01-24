#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;

void create(){
    ::create();
    set_spell_name("sleet storm");
    set_spell_level(([ "druid" : 3, "mage" : 3, "magus" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS sleet storm");
    set_description("The spell sleet storm only works outdoors. When it is cast, the skies will open up and begin pouring freezing rain on the area. Within a few moments, howling winds and freezing rain will turn the ground into ice. Movement through the area is difficult and sometimes visibility is obstructed to the point of virtual blindness.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_immunities( ({"cold"}) );
    //set_components((["mage":(["pinch of special dust":1,"water":1])]));
    aoe_spell(1);
    set_aoe_message("%^RESET%^%^CRST%^%^C051%^(%^C024%^besieged by %^C250%^w%^C255%^in%^C250%^d%^C255%^s %^RESET%^%^C024%^and %^C069%^s%^C075%^l%^C081%^e%^C075%^e%^C069%^t%^C051%^)%^CRST%^");
}

void spell_effect(int prof){
    tell_object(caster, "%^RESET%^%^CRST%^%^C024%^You raise your hand to the air and clench your fist. A peal of %^C059%^t%^C244%^h%^C059%^un%^C244%^d%^C059%^e%^C244%^r %^RESET%^%^C024%^sounds as you open your hand and the skies open, drenching the area with %^C069%^f%^C075%^r%^C081%^eezi%^C075%^n%^C069%^g %^C075%^r%^C081%^a%^C075%^i%^C069%^n%^RESET%^%^C024%^!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C024%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C024%^ raises "+caster->query_possessive()+" hand into the air and clenches "+caster->query_possessive()+" fist. A peal of %^C059%^t%^C244%^h%^C059%^un%^C244%^d%^C059%^e%^C244%^r %^RESET%^%^C024%^sounds as "+caster->query_subjective()+" opens "+caster->query_possessive()+" hand and the skies open, drenching the area with %^C069%^f%^C075%^r%^C081%^eezi%^C075%^n%^C069%^g %^C075%^r%^C081%^a%^C075%^i%^C069%^n%^RESET%^%^C024%^!%^CRST%^", caster);
    counter = clevel / 10 + 1;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}


void execute_attack(){
    object *foes=({}),targ;
    int i;
    string limb;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster) || !objectp(place) || !present(caster,place)|| counter<0)
    {
        dest_effect();
        return;
    }

    message("info", "%^RESET%^%^CRST%^%^C255%^Ho%^C250%^w%^C255%^l%^C250%^i%^C255%^ng %^C250%^w%^C255%^in%^C250%^d%^C255%^s %^RESET%^%^C024%^and the pelting of %^C069%^h%^C075%^e%^C081%^a%^C075%^v%^C069%^y %^C075%^r%^C081%^a%^C075%^i%^C069%^n %^RESET%^%^C024%^threaten to drown out all other sounds!%^CRST%^", nearbyRoom(place, 2));

    foes = target_selector();
    foes -= ({ caster });

    for(i=0;i<sizeof(foes);i++){
        if(!objectp(targ = foes[i])) continue;

        limb = targ->return_target_limb();
        if(do_save(targ,0)){
            tell_object(targ, "%^RESET%^%^CRST%^%^C024%^You avoid the worst of the %^C069%^s%^C075%^l%^C081%^e%^C075%^e%^C069%^t%^RESET%^%^C024%^, but some of the %^C051%^cold %^RESET%^%^C024%^still bites at your skin!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C024%^"+targ->query_cap_name()+"%^RESET%^%^CRST%^%^C024%^ manages to hold "+targ->query_possessive()+" footing on the ice!%^CRST%^",({targ}));
            damage_targ(targ, limb, sdamage / 2, "cold");
        }
        else{
            tell_object(targ, "%^RESET%^%^CRST%^%^C039%^Unable to hold your balance, you slip on the %^C045%^i%^C051%^c%^C045%^e%^RESET%^%^C039%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C039%^Unable to hold "+targ->query_possessive()+" balance, "+targ->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^ slips on the %^C045%^i%^C051%^c%^C045%^e%^RESET%^%^C039%^!%^CRST%^", ({targ}));
            targ->set_temporary_blinded(1);
            targ->set_tripped(1, "%^RESET%^%^CRST%^%^C045%^You are struggling to regain your footing on the ice!%^CRST%^", 4);
            damage_targ(targ, limb, sdamage, "cold");
        }
    }

    counter--;
    place->addObjectToCombatCycle(this_object(), 1);
}


void dest_effect(){
    if(objectp(place)) tell_object(place, "%^RESET%^%^CRST%^%^C024%^The %^C069%^f%^C075%^r%^C081%^eezi%^C075%^n%^C069%^g %^C075%^r%^C081%^a%^C075%^i%^C069%^n %^RESET%^%^C024%^and %^C255%^wi%^C250%^n%^C255%^d %^RESET%^%^C024%^die down and then fade away as the storm clears from the area.%^CRST%^");
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

