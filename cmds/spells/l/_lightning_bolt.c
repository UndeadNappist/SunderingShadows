// help updated to reflect damage isn't maxed at level 10, last change 5/2001 *Styx* 8/2003
// Lightning Bolt
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

string element;
void dest_effect();

void create(){
    ::create();
    set_spell_name("lightning bolt");
    set_spell_level(([ "mage" : 3, "magus" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS lightning bolt on TARGET");
    set_description("This spell, when cast, will allow you to hurl a lightning bolt at your target. The blazing electricity will inflict half damage against targets that make their save.");
    set_verbal_comp();
    set_somatic_comp();
    versatile();
    set_target_required(1);
    set_components(([
      "mage" : ([ "firefly" : 1, ]),
    ]));
    set_immunities(({"electricity"}));
    set_save("reflex");
}

string query_cast_string(){
    return "%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ clenches "+caster->query_possessive()+" hands into fists while muttering %^C058%^harsh %^C101%^words.%^CRST%^";
}

spell_effect(int prof) {
    int num;
    string target_limb;
    spell_successful();

    if(environment(caster) != environment(target)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Your target has left your range.%^CRST%^\n");
        dest_effect();
        return;
    }
    target_limb = target->return_target_limb();
    spell_kill(target, caster);

    element = (string)caster->query("elementalist");
    switch(element){
        case "acid":
            tell_object(caster, "%^RESET%^%^CRST%^%^C065%^You hurl your fist forth and a %^C077%^b%^C071%^o%^C070%^l%^C076%^t %^C070%^o%^C071%^f %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^RESET%^%^C065%^streaks forth towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C065%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^ hurls "+caster->query_possessive()+" fist forth and a %^C077%^b%^C071%^o%^C070%^l%^C076%^t %^C070%^o%^C071%^f %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^RESET%^%^C065%^streaks towards you!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C065%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^ hurls "+caster->QP+" fist forth and a %^C077%^b%^C071%^o%^C070%^l%^C076%^t %^C070%^o%^C071%^f %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^RESET%^%^C065%^acid streaks out towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^", ({caster, target}));
            break;
        case "cold":
            tell_object(caster, "%^RESET%^%^CRST%^%^C039%^You hurl your fist forth and a %^C069%^b%^C075%^o%^C081%^l%^C087%^t %^C123%^o%^C087%^f %^C081%^i%^C075%^c%^C069%^e %^RESET%^%^C039%^is cast out towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^!%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C039%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^ hurls "+caster->query_possessive()+" forth and a %^C069%^b%^C075%^o%^C081%^l%^C087%^t %^C123%^o%^C087%^f %^C081%^i%^C075%^c%^C069%^e %^RESET%^%^C039%^is cast out towards you!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C039%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^ hurls "+caster->query_possessive()+" fist forth and a %^C069%^b%^C075%^o%^C081%^l%^C087%^t %^C123%^o%^C087%^f %^C081%^i%^C075%^c%^C069%^e %^RESET%^%^C039%^is cast out towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^!%^CRST%^", ({caster, target}));
            break;
        case "fire":
            tell_object(caster, "%^RESET%^%^CRST%^%^C160%^You hurl your fist forth and a %^C208%^b%^C214%^o%^C208%^l%^C202%^t %^C208%^o%^C214%^f %^C208%^f%^C202%^l%^C208%^a%^C214%^m%^C208%^e %^RESET%^%^C160%^races towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C160%^!%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C160%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C160%^ hurls "+caster->query_possessive()+" fist forth and a %^C208%^b%^C214%^o%^C208%^l%^C202%^t %^C208%^o%^C214%^f %^C208%^f%^C202%^l%^C208%^a%^C214%^m%^C208%^e %^RESET%^%^C160%^races towards you!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C160%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C160%^ hurls "+caster->query_possessive()+" fist forth and a %^C208%^b%^C214%^o%^C208%^l%^C202%^t %^C208%^o%^C214%^f %^C208%^f%^C202%^l%^C208%^a%^C214%^m%^C208%^e %^RESET%^%^C160%^races out towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C160%^!%^CRST%^", ({caster, target}));
            break;
        case "sonic":
            tell_object(caster, "%^RESET%^%^CRST%^%^C090%^You hurl your fist forth and a %^C218%^c%^C212%^a%^C206%^copho%^C212%^n%^C218%^y of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^crashes into "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C090%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^ hurls "+caster->query_possessive()+" fist forth and a %^C218%^c%^C212%^a%^C206%^copho%^C212%^n%^C218%^y of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^crashes into you!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^ hurls "+caster->query_possessive()+" fist forth and a %^C218%^c%^C212%^a%^C206%^copho%^C212%^n%^C218%^y of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^crashes into "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^", ({caster, target}));
            break;
        default:
            element = "electricity";
            tell_object(caster, "%^RESET%^%^CRST%^%^C100%^You hurl your fist forth and a %^C228%^bo%^C231%^l%^C228%^t %^C226%^o%^C228%^f l%^C231%^i%^C228%^gh%^C231%^t%^C226%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^charges towards towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C100%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ hurls "+caster->query_possessive()+" fist forth and a %^C228%^bo%^C231%^l%^C228%^t %^C226%^o%^C228%^f l%^C231%^i%^C228%^gh%^C231%^t%^C226%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^charges towards towards you!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ hurls "+caster->query_possessive()+" fist forth and a %^C228%^bo%^C231%^l%^C228%^t %^C226%^o%^C228%^f l%^C231%^i%^C228%^gh%^C231%^t%^C226%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^charges out towards "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^", ({caster, target}));
            break;
    }
    
    if(do_save(target,0)){
        if(evade_splash(target)){
            dest_effect();
            return;
        }
        switch(element){
            case "acid":
                tell_object(target, "%^RESET%^%^CRST%^%^C065%^The acidic bolt grazes your "+target_limb+".%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C065%^The acidic bolt grazes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^'s "+target_limb+".%^CRST%^", target);
                break;
            case "cold":
                tell_object(target, "%^RESET%^%^CRST%^%^C039%^The frozen bolt grazes your "+target_limb+".%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^The frozen bolt grazes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^'s "+target_limb+".%^CRST%^", target);
                break;
            case "fire":
                tell_object(target, "%^RESET%^%^CRST%^%^C160%^The blazing bolt scorches your "+target_limb+".%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C160%^The blazing bolt scorches "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C160%^'s "+target_limb+".%^CRST%^", target);
                break;
            case "sonic":
                tell_object(target, "%^RESET%^%^CRST%^%^C090%^The sonic bolt grazes your "+target_limb+".%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^The sonic bolt grazes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^'s "+target_limb+".%^CRST%^",  target);
                break;
            default:
                tell_object(target, "%^RESET%^%^CRST%^%^C100%^The lightning bolt scorches your "+target_limb+".%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^The lightning bolt scorches "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^'s "+target_limb+".%^CRST%^", target);
                break;
        }
        damage_targ(target, target_limb, to_int(sdamage / 2), element);
    }
    else{
        switch(element){
            case "acid":
                tell_object(target, "%^RESET%^%^CRST%^%^C065%^The acidic bolt strikes you, %^C077%^b%^C071%^u%^C070%^r%^C076%^n%^C070%^i%^C071%^n%^C077%^g %^RESET%^%^C065%^your "+target_limb+"!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C065%^The acidic bolt strikes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^, %^C077%^b%^C071%^u%^C070%^r%^C076%^n%^C070%^i%^C071%^n%^C077%^g %^RESET%^%^C065%^"+target->QP+" "+target_limb+"!%^CRST%^", target);
                break;
            case "cold":
                tell_object(target, "%^RESET%^%^CRST%^%^C039%^The frozen bolt strikes you, %^C069%^c%^C075%^h%^C081%^i%^C087%^l%^C123%^l%^C087%^i%^C081%^n%^C075%^g %^RESET%^%^C039%^your "+target_limb+"!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^The frozen bolt strikes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^%^, %^C069%^c%^C075%^h%^C081%^i%^C087%^l%^C123%^l%^C087%^i%^C081%^n%^C075%^g %^RESET%^%^C039%^"+target->QP+" "+target_limb+"!%^CRST%^", target);
                break;
            case "fire":
                tell_object(target, "%^RESET%^%^CRST%^%^C160%^The blazing bolt strikes you, %^C208%^s%^C214%^e%^C208%^a%^C202%^r%^C208%^i%^C214%^n%^C208%^g %^RESET%^%^C160%^your "+target_limb+"!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C160%^The blazing bolt strikes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C160%^, %^C208%^s%^C214%^e%^C208%^a%^C202%^r%^C208%^i%^C214%^n%^C208%^g %^RESET%^%^C160%^"+target->QP+" "+target_limb+"!%^CRST%^", target);
                break;
            case "sonic":
                tell_object(target, "%^RESET%^%^CRST%^%^C090%^The sonic bolt strikes you, %^C218%^b%^C212%^l%^C206%^asti%^C212%^n%^C218%^g %^RESET%^%^C090%^your "+target_limb+"!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^The sonic bolt strikes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^, %^C218%^b%^C212%^l%^C206%^asti%^C212%^n%^C218%^g %^RESET%^%^C090%^"+target->QP+" "+target_limb+"!%^CRST%^", target);
                break;
            default:
                tell_object(target, "%^RESET%^%^CRST%^%^C100%^The lightning bolt strikes you, %^C228%^e%^C231%^l%^C228%^ect%^C226%^r%^C231%^i%^C228%^fy%^C231%^i%^C228%^n%^C226%^g %^RESET%^%^C100%^your "+target_limb+"!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^The lightning bolt strikes "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^, %^C228%^e%^C231%^l%^C228%^ect%^C226%^r%^C231%^i%^C228%^fy%^C231%^i%^C228%^n%^C226%^g %^RESET%^%^C100%^"+target->QP+" "+target_limb+"!%^CRST%^", target);
                break;
        }
        damage_targ(target, target_limb, sdamage, element);
    }
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

