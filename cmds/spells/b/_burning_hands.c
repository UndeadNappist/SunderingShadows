//      Burning Hands
//      Thorn@Shadowgate
//      10/16/94
//      Totally modified and updated by Vashkar
//      11/1/95

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

void dest_effect();
void damage(object mytarg, int bonus);
string element;

void create(){
    ::create();
    set_spell_name("burning hands");
    set_spell_level(([ "mage" : 1, "monk" : 3, "magus" : 1, "druid" : 1 ]));
    set_spell_sphere("alteration");
    set_circle("wildfire");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS burning hands [on TARGET]");
    set_description("This spell begins by the caster fanning out his hands while chanting the spell. Flames will flare out and do a small amount of damage to the target and those near him.");
    set_verbal_comp();
    set_somatic_comp();
    //set_target_required(1);
    set_save("reflex");
    versatile();
    splash_spell(1);
    set_immunities(({"fire"}));
}

string query_cast_string(){
    return "%^RESET%^%^CRST%^%^C178%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C178%^ fans out "+caster->query_possessive()+" hands and begins to chant.%^CRST%^";
}

void spell_effect(int prof){
    int counter;
    int bonus = prof/10 - 10;
    int x;
    string targetname, castername;
    object * allies;
    object * targets;
    
    if(!target || !objectp(target))
        target = caster->query_current_attacker();

    if(!target || !objectp(target))
        return;

    if(!present(target,environment(caster))){
        tell_object(caster,"%^RESET%^%^CRST%^%^C059%^Your target is not in this area.%^CRST%^\n");
        dest_effect();
        return;
    }
    
    element = (string)caster->query("elementalist");
    if(element){
        set_immunities(({ element }));
        define_clevel();
        define_base_damage(0);
    }
    
    if(spell_type == "monk") MAGIC_D->elemental_opportunist(caster, target);
    targets = target_selector();

    targets -= ({target});
    //lets remove caster because that would mean the fire bonces straight back (assume the player is smart enough to move
    targets -= ({caster});

    if(target->query_party())
        allies = PARTY_D->query_party_members(target->query_party());
    else{
        allies = ({caster});
    }

    if(sizeof(caster->query_classes()) == 1){
        targets -= allies;
        if(caster->query_followers()) targets -= caster->query_followers();
    }
    
    targetname = target->query_cap_name();
    castername = caster->query_cap_name();
    switch(element){
        case "acid":
            tell_object(target, "%^RESET%^%^CRST%^%^C064%^"+castername+"%^RESET%^%^CRST%^%^C064%^ aims a %^C046%^spray %^RESET%^%^C064%^of %^C190%^corrosive %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^RESET%^%^C064%^at you!%^CRST%^");
            tell_object(caster, "%^RESET%^%^CRST%^%^C064%^You aim a %^C046%^spray %^RESET%^%^C064%^of %^C190%^corrosive %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^RESET%^%^C064%^at "+targetname+"%^RESET%^%^CRST%^%^C064%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C064%^"+castername+"%^RESET%^%^CRST%^%^C064%^ aims a %^C046%^spray %^RESET%^%^C064%^of %^C190%^corrosive %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^RESET%^%^C064%^at "+targetname+"%^RESET%^%^CRST%^%^C064%^!%^CRST%^", ({ caster, target}) );
            break;
        case "cold":
            tell_object(target, "%^RESET%^%^CRST%^%^C039%^"+castername+"%^RESET%^%^CRST%^%^C039%^ sends a burst of %^C051%^frigid air %^C039%^filled with %^C075%^s%^C081%^h%^C087%^ar%^C081%^d%^C075%^s %^C069%^of %^C081%^i%^C087%^c%^C087%^e %^RESET%^%^C039%^at you!%^CRST%^");
            tell_object(caster, "%^RESET%^%^CRST%^%^C039%^You send a burst of %^C051%^frigid air %^C039%^filled with %^C075%^s%^C081%^h%^C087%^ar%^C081%^d%^C075%^s %^C069%^of %^C081%^i%^C087%^c%^C087%^e %^RESET%^%^C039%^at "+targetname+"%^RESET%^%^CRST%^%^C039%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C039%^"+castername+"%^RESET%^%^CRST%^%^C039%^ sends a burst of %^C051%^frigid air %^C039%^filled with %^C075%^s%^C081%^h%^C087%^ar%^C081%^d%^C075%^s %^C069%^of %^C081%^i%^C087%^c%^C087%^e %^RESET%^%^C039%^at "+targetname+"%^RESET%^%^CRST%^%^C039%^!%^CRST%^", ({ caster, target}) );
            break;
        case "electricity":
            tell_object(target, "%^RESET%^%^CRST%^%^C100%^Threads of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^C130%^erupt %^RESET%^%^C100%^from "+castername+"%^RESET%^%^CRST%^%^C100%^'s fingertips towards you!%^CRST%^");
            tell_object(caster, "%^RESET%^%^CRST%^%^C100%^Threads of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^C130%^erupt %^RESET%^%^C100%^from your fingertips towards "+targetname+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C100%^Threads of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^C130%^erupt %^RESET%^%^C100%^from "+castername+"%^RESET%^%^CRST%^%^C100%^'s fingertips towards "+targetname+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^", ({ caster, target}) );
            break;
        case "sonic":
            tell_object(target, "%^RESET%^%^CRST%^%^C090%^A %^C092%^hazy %^C090%^burst of %^C218%^r%^C212%^e%^C206%^sona%^C212%^n%^C218%^t e%^C212%^n%^C206%^er%^C212%^g%^C218%^y %^RESET%^%^C090%^surges from "+castername+"%^RESET%^%^CRST%^%^C090%^'s hands towards you!%^CRST%^");
            tell_object(caster, "%^RESET%^%^CRST%^%^C090%^A %^C092%^hazy %^C090%^burst of %^C218%^r%^C212%^e%^C206%^sona%^C212%^n%^C218%^t e%^C212%^n%^C206%^er%^C212%^g%^C218%^y %^RESET%^%^C090%^surges from your hands towards "+targetname+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C090%^A %^C092%^hazy %^C090%^burst of %^C218%^r%^C212%^e%^C206%^sona%^C212%^n%^C218%^t e%^C212%^n%^C206%^er%^C212%^g%^C218%^y %^RESET%^%^C090%^surges from "+castername+"%^RESET%^%^CRST%^%^C090%^'s hands towards "+targetname+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^", ({ caster, target}) );
            break;
        default:
            element = "fire";
            tell_object(target, "%^RESET%^%^CRST%^%^C124%^"+castername+"%^RESET%^%^CRST%^%^C124%^ sends a %^C196%^sheet %^C124%^of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e %^RESET%^%^C124%^straight at you!%^CRST%^");
            tell_object(caster, "%^RESET%^%^CRST%^%^C124%^You send a %^C196%^sheet %^C124%^of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e %^RESET%^%^C124%^straight at "+targetname+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+castername+"%^RESET%^%^CRST%^%^C124%^ sends a %^C196%^sheet %^C124%^of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e %^RESET%^%^C124%^at "+targetname+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^", ({ caster, target}) );
            break;
    }
    damage(target, bonus);
    counter += (int)target->query_size();
    for(x = 0;x < sizeof(targets) && counter < 4;x++){
        if(!objectp(targets[x])) { continue; }
        if(!random(3)){
            damage(targets[x], bonus-random(5));//5 for the 5 feet spread
            counter+=(int)targets[x]->query_size();
        }
    }
    dest_effect();
}

void damage(object mytarg, int bonus){
    string before, after, targname, *immunities;
    int i;
    targname = mytarg->query_cap_name();

    if(do_save(mytarg,0)){
        switch(element){
            case "acid":
                tell_room(place, "%^RESET%^%^CRST%^%^C064%^"+targname+"%^RESET%^%^CRST%^%^C064%^ jumps out of the way just as the acid is about to hit!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C064%^You are only splashed by a few drops of the acid.%^CRST%^");
                    break;
            case "cold":
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^"+targname+"%^RESET%^%^CRST%^%^C039%^ jumps out of the way just as the freezing air is about to hit!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C039%^You are only slightly chilled by the ice.%^CRST%^");
                break;
            case "electricity":
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+targname+"%^RESET%^%^CRST%^%^C100%^ jumps out of the way just as the lightning is about to hit!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C100%^You are only slightly jolted by the lightning.%^CRST%^");
                break;
            case "sonic":
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+targname+"%^RESET%^%^CRST%^%^C090%^ jumps out of the way just as the sonic waves are about to hit!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C090%^You are only slightly shaken by the waves of sonic.%^CRST%^");
                break;
            default:
                tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+targname+"%^RESET%^%^CRST%^%^C124%^ jumps out of the way just as the flames are about to hit!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C124%^You are only slightly singed by the flames.%^CRST%^");
                break;
        }
        damage_targ(mytarg, "torso", to_int(sdamage / 2), element);
    }
    else{
        switch(element){
            case "acid":
                tell_room(place, "%^RESET%^%^CRST%^%^C064%^"+targname+"%^RESET%^%^CRST%^%^C064%^ is %^C046%^burned %^C064%^by the spray of %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C064%^!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C064%^The %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C046%^ burns %^C064%^you badly!%^CRST%^");
                break;
            case "cold":
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^"+targname+"%^RESET%^%^CRST%^%^C039%^ is %^C051%^sliced %^C039%^by the %^C075%^s%^C081%^h%^C087%^ar%^C081%^d%^C075%^s %^C069%^of %^C081%^i%^C087%^c%^C087%^e%^RESET%^%^C039%^!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C039%^The %^C075%^s%^C081%^h%^C087%^ar%^C081%^d%^C075%^s %^C069%^of %^C081%^i%^C087%^c%^C087%^e %^RESET%^%^C051%^slice %^C039%^your skin!%^CRST%^");
                break;
            case "electricity":
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+targname+"%^RESET%^%^CRST%^%^C100%^ is %^C130%^shocked %^C100%^by the threads of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C100%^!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C100%^The %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^C130%^shocks %^RESET%^%^C100%^you badly!%^CRST%^");
                break;
            case "sonic":
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+targname+"%^RESET%^%^CRST%^%^C090%^ is badly %^C092%^shaken %^C090%^by the wave of %^C218%^s%^C212%^o%^C206%^n%^C212%^i%^C218%^c e%^C212%^n%^C206%^er%^C212%^g%^C218%^y%^RESET%^%^C090%^!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C090%^The %^C218%^s%^C212%^o%^C206%^n%^C212%^i%^C218%^c w%^C212%^a%^C206%^v%^C212%^e%^C218%^s %^RESET%^%^C092%^shake %^C090%^you!%^CRST%^");
                break;
            default:
                tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+targname+"%^RESET%^%^CRST%^%^C124%^ is %^C196%^scorched %^C124%^by the sheet of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^RESET%^%^C124%^!%^CRST%^", mytarg);
                tell_object(mytarg, "%^RESET%^%^CRST%^%^C124%^The %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s %^RESET%^%^C196%^scorch %^RESET%^%^C124%^you badly!%^CRST%^");
                break;
        }
        damage_targ(mytarg, "torso", sdamage, element);
    }
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

