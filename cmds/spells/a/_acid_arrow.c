// Acid Arrow
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

string target_limb, element, coloring;
int num;

void create(){
    ::create();
    set_spell_name("acid arrow");
    set_spell_level(([ "mage" : 2, "magus" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS acid arrow [on TARGET]");
    set_damage_desc("acid");
    set_description("When throwing a dart at a victim and casting the acid arrow spell, the dart will turn into an acidic arrow with the aim and speed as if fired by a fighter of the caster's spell level. Damage will be inflicted immediately upon hitting the target, then the acid will seep through the victim's veins, doing more damage per combat round until the acid wears off or the target is dead.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    versatile();
    //set_components(([ "mage" : ([ "dart" : 1, ]), ]));
    set_immunities( ({ "acid"}) );
}


string query_cast_string(){
    element = (string)caster->query("elementalist");
    if(element){
        set_immunities(({ element }));
        define_clevel();
        define_base_damage(0);
    }
    switch(element){
        case "cold":
            coloring = "%^C039%^";
            break;
        case "electricity":
            coloring = "%^C100%^";
            break;
        case "fire":
            coloring = "%^C124%^";
            break;
        case "sonic":
            coloring = "%^C090%^";
            break;
        default:
            element = "acid";
            coloring = "%^C064%^";
            break;
    }
    tell_object(caster, ""+coloring+"You shout out %^C093%^m%^C099%^a%^C105%^gic%^C099%^a%^C093%^l w%^C099%^o%^C105%^r%^C099%^d%^C093%^s "+coloring+"in a powerful voice, holding a %^C144%^d%^C101%^a%^C100%^rt "+coloring+"aloft.%^CRST%^");
    tell_room(place, ""+coloring+caster->query_cap_name()+coloring+" shouts out %^C093%^m%^C099%^a%^C105%^gic%^C099%^a%^C093%^l w%^C099%^o%^C105%^r%^C099%^d%^C093%^s "+coloring+"in a powerful voice, holding a %^C144%^d%^C101%^a%^C100%^rt "+coloring+"aloft.%^CRST%^", caster);
    return "display";
}

void spell_effect(int prof){
    string arrowtype, shortmsg;
    int need, roll;

    if(!objectp(caster) || !objectp(place)){
        dest_effect();
        return;
    }
    if(!target || !objectp(target)){
        target = caster->query_current_attacker();
    }
    if(!objectp(target) || !present(target,place)){
        tell_object(caster, "%^C059%^Your target is not in this area.\n%^CRST%^");
        dest_effect();
        return;
    }
    if(!caster->ok_to_kill(target)){
        dest_effect();
        return 1;
    }

    target_limb = target->return_target_limb();
    need = "/daemon/bonus_d.c"->thaco(clevel,"fighter") - ((int)target->query_ac());
    roll = random(20) + 1;

    switch(element){
        case "cold":
            arrowtype = "an %^C045%^i%^C051%^c%^C045%^y";
            shortmsg = "%^C045%^I%^C051%^c%^C045%^e %^C039%^sears";
            break;
        case "electricity":
            arrowtype = "a %^C228%^c%^C231%^h%^C226%^a%^C228%^rg%^C226%^e%^C228%^d";
            shortmsg = "%^C228%^S%^C231%^t%^C226%^a%^C228%^ti%^C231%^c %^C100%^jolts";
            break;
        case "fire":
            arrowtype = "a %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^i%^C214%^n%^C208%^g";
            shortmsg = "%^C208%^F%^C214%^l%^C208%^a%^C202%^m%^C208%^e %^C124%^sears";
            break;
        case "sonic":
            arrowtype = "a %^C218%^b%^C212%^u%^C206%^zzi%^C212%^n%^C218%^g";
            shortmsg = "%^C218%^R%^C212%^e%^C206%^ve%^C212%^r%^C218%^b%^C212%^e%^C206%^r%^C212%^a%^C218%^t%^C212%^i%^C206%^o%^C212%^n%^C218%^s %^C090%^echo";
            break;
        default:
            arrowtype = "an %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^C070%^i%^C071%^c";    
            shortmsg = "%^C077%^A%^C071%^c%^C070%^i%^C076%^d %^C064%^burns";
            break;
    }

    if(interactive(caster)){
        tell_object(caster, ""+coloring+"You launch a dart out of your hand, aiming it at "+target->query_cap_name()+coloring+"!%^CRST%^");
        tell_object(target, ""+coloring+""+caster->query_cap_name()+coloring+" launches a dart out of "+caster->query_possessive()+" hand, aiming it at you!%^CRST%^");
        tell_room(place, ""+coloring+caster->query_cap_name()+coloring+" launches a dart out of "+caster->query_possessive()+" hand, aiming it at "+target->query_cap_name()+coloring+"!%^CRST%^", ({ caster, target}) );

        if(roll < need && roll != 20){
            tell_object(caster, "%^C059%^Your dart explodes into "+arrowtype+"%^C059%^ arrow and zips past "+target->query_possessive()+" "+target_limb+".%^CRST%^");
            tell_object(target, "%^C059%^"+caster->query_cap_name()+"%^C059%^'s dart explodes into "+arrowtype+"%^C059%^ arrow and zips past you.%^CRST%^");
            tell_room(place, "%^C059%^"+caster->query_cap_name()+"%^C059%^'s dart explodes into "+arrowtype+"%^C059%^ arrow and zips past "+target->query_cap_name()+"%^C059%^.%^CRST%^", ({ caster, target}) );
            dest_effect();
            return 1;
        }

        tell_object(caster, ""+coloring+"Your dart explodes into "+arrowtype+coloring+" arrow and pierces "+target->query_possessive()+" "+target_limb+"!%^CRST%^");
        tell_object(target, ""+coloring+caster->query_cap_name()+coloring+"'s dart explodes into "+arrowtype+coloring+" arrow and pierces your "+target_limb+"!\n"+coloring+shortmsg+" through your veins.%^CRST%^");
        tell_room(place, ""+coloring+caster->query_cap_name()+coloring+"'s dart explodes into "+arrowtype+coloring+" arrow and pierces "+target->query_cap_name()+coloring+"'s "+target_limb+"!%^CRST%^", ({ caster, target}) );
        spell_successful();
    }
    else{
        tell_object(target, ""+coloring+"A dart flies from "+caster->query_cap_name()+coloring+", aiming directly at you!%^CRST%^");
        tell_room(place, ""+coloring+"A dart flies from "+caster->query_cap_name()+coloring+", aiming directly at "+target->query_cap_name()+coloring+"!%^CRST%^", target);

        if(roll < need && roll != 20){
            tell_object(target, "%^C059%^The dart explodes into "+arrowtype+"%^C059%^ arrow and zips past you.%^CRST%^");
            tell_room(place, "%^C059%^The dart explodes into "+arrowtype+"%^C059%^ arrow and zips past "+target->query_cap_name()+"%^C059%^.%^CRST%^", target);
            dest_effect();
            return 1;
        }

        tell_object(target, ""+coloring+"The dart explodes into "+arrowtype+coloring+" arrow and pierces your "+target_limb+"!\n"+coloring+shortmsg+" through your veins.%^CRST%^");
        tell_room(place, ""+coloring+"The dart explodes into "+arrowtype+coloring+" arrow and pierces "+target->query_cap_name()+coloring+"'s "+target_limb+"!%^CRST%^", target);
        spell_successful();
    }

    damage_targ(target, target_limb, sdamage, element);
    spell_kill(target,caster);

    if(!objectp(target)){
        dest_effect();
    }

    num = (clevel / 3);
    if(num){ call_out("more_acid", ROUND_LENGTH); }
    else{ dest_effect(); }
}


void more_acid(){
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    if(!objectp(target)){
        dest_effect();
        return;
    }

    death_check(target);

    if(target->query_hp()<0){
        dest_effect();
        return;
    }

    switch(element){
        case "cold":
            tell_object(target, ""+coloring+"Pain floods through your "+target_limb+" as the icy chill continues to burn.%^CRST%^");
            break;
        case "electricity":
            tell_object(target, ""+coloring+"Pain floods through your "+target_limb+" as the charged dart jolts you again.%^CRST%^");
            break;
        case "fire":
            tell_object(target, ""+coloring+"Pain floods through your "+target_limb+" as the searing flame continues to burn.%^CRST%^");
            break;
        case "sonic":
            tell_object(target, ""+coloring+"Pain floods through your "+target_limb+" as the resonations thrum back and forth.%^CRST%^");
            break;
        default:
            tell_object(target, ""+coloring+"Pain floods through your "+target_limb+" as the acid continues to burn.%^CRST%^");
            break;
    }
    define_base_damage(0);//lazy re-roll
    damage_targ(target, target_limb, sdamage/6, element);

    if (!target && objectp(this_object())){
        dest_effect();
        return;
    }

    if (num-- > 0) { call_out("more_acid", ROUND_LENGTH); }
    else{
        dest_effect();
        return;
    }
    if(target->query_hp()<0){
        dest_effect();
        return;
    }
}


void dest_effect(){
    if (find_call_out("more_acid") != -1) remove_call_out("more_acid");

    if(objectp(target)){
        switch(element){
            case "cold":
                tell_object(target, ""+coloring+"The icy chill finally recedes.%^CRST%^");
                break;
            case "electricity":
                tell_object(target, ""+coloring+"The static jolts finally recede.%^CRST%^");
                break;
            case "fire":
                tell_object(target, ""+coloring+"The searing pain finally recedes.%^CRST%^");
                break;
            case "sonic":
                tell_object(target, ""+coloring+"The echo of the resonations finally recedes.%^CRST%^");
                break;
            default:
                tell_object(target, ""+coloring+"The burning of the acid finally recedes.%^CRST%^");
                break;
        }
    }

    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }

}
