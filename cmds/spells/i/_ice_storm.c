//Ice Storm coded by Bane//
//removed from druids for balance after discussion with Ts and players ~Circe~ 8/5/13
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i, j, time, profs, flag;
object env, *foes;
string target_limb, element;

void create() {
    ::create();
    set_spell_name("ice storm");
    set_spell_level(([ "mage" : 4, "druid" : 4, "magus" : 4, "cleric" : 4 ]));
    set_circle("winter");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS ice storm");
    set_domains(({"cold"}));
    set_description("When the ice storm spell is cast, the mage summons storm clouds above that rain hail and ice down upon anything in the area. The spell will not damage the caster and lasts for a number of rounds equal to the caster's level.");
    set_verbal_comp();
    set_somatic_comp();
    //set_components((["mage" : ([ "pinch of special dust" : 1, "water" : 3, ]),]));
    set_immunities( ({"cold"}) );
    aoe_spell(1);
    versatile();
    set_aoe_message("%^RESET%^%^CRST%^%^C255%^(%^C039%^scoured by %^C081%^s%^C087%^h%^C123%^ee%^C087%^t%^C081%^s %^C075%^of %^C087%^i%^C123%^c%^C087%^e%^RESET%^%^C255%^)%^CRST%^");
}

int preSpell() {
    element = (string)caster->query("elementalist");
    if(element){
        set_immunities(({ element }));
        define_clevel();
        define_base_damage(0);
    }
    switch(element){
        case "acid": 
            set_immunities(({"acid"})); 
            set_aoe_message("%^RESET%^%^CRST%^%^C190%^(%^C065%^scoured by a %^C077%^s%^C071%^t%^C070%^o%^C076%^r%^C070%^m %^C065%^of %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C190%^)%^CRST%^"); 
            break;
        case "electricity": 
            set_immunities(({"electricity"})); 
            set_aoe_message("%^RESET%^%^CRST%^%^C130%^(%^C100%^scoured by %^C228%^st%^C231%^r%^C228%^ea%^C226%^k%^C228%^s %^C100%^of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C130%^)%^CRST%^"); 
            break;
        case "fire": 
            set_immunities(({"fire"})); 
            set_aoe_message("%^RESET%^%^CRST%^%^C196%^(%^C124%^scoured by a %^C208%^r%^C214%^a%^C208%^i%^C202%^n %^C214%^of %^RESET%^%^C208%^f%^C214%^i%^C208%^re)%^CRST%^"); 
            break;
        case "sonic": 
            set_immunities(({"sonic"})); 
            set_aoe_message("%^RESET%^%^CRST%^%^C092%^(%^C090%^scoured by %^C218%^r%^C212%^e%^C206%^verb%^C212%^e%^C206%^rati%^C212%^n%^C218%^g e%^C212%^c%^C206%^ho%^C212%^e%^C218%^s%^C092%^)%^CRST%^"); 
            break;
        default: 
            element = "cold"; 
            break;
    }
    return 1;
}

void spell_effect(int prof){
    string colorings;

    profs = prof;

    switch(element){
        case "acid": colorings = "%^C064%^"; break;
        case "electricity": colorings = "%^C100%^"; break;
        case "fire": colorings = "%^C124%^"; break;
        case "sonic": colorings = "%^C090%^"; break;
        default: colorings = "%^C039%^"; break;
    }

    tell_object(caster, "%^RESET%^%^CRST%^"+colorings+"You wave your hands around summoning the fury of the skies above!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^"+colorings+""+caster->query_cap_name()+"%^RESET%^%^CRST%^"+colorings+" waves "+caster->query_possessive()+" hands around summoning the fury of the skies above!%^CRST%^",({caster}));
    time = 0;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack(){
    if(!flag){
        flag = 1;
        ::execute_attack();
        return;
    }
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    foes = target_selector();

    j = sizeof(foes);
    if(time > clevel * 3){
        dest_effect();
    }
    else{
        switch(element){
            case "acid":
                message("info", "%^RESET%^%^CRST%^%^C065%^Fist sized %^C077%^g%^C071%^l%^C070%^o%^C076%^b%^C070%^s %^C065%^of %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^RESET%^%^C065%^pour out of the sky %^C190%^burning %^RESET%^%^C065%^into everything in sight!%^CRST%^", nearbyRoom(place,2));
                break;
            case "electricity":
                message("info", "%^RESET%^%^CRST%^%^C100%^The furious %^C059%^s%^C243%^t%^C245%^o%^C243%^r%^C059%^m %^RESET%^%^C100%^above sends %^C228%^st%^C231%^r%^C228%^ea%^C226%^k%^C228%^s %^C100%^of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C100%^ all around!%^CRST%^", nearbyRoom(place,2));
                break;
            case "fire":
                message("info", "%^RESET%^%^CRST%^%^C124%^The clouds above %^C196%^burn %^RESET%^%^C124%^as %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^i%^C214%^n%^C208%^g %^C202%^b%^C208%^o%^C214%^l%^C208%^t%^C202%^s %^RESET%^%^C124%^rain down, %^C196%^immolating %^RESET%^%^C124%^the area!%^CRST%^", nearbyRoom(place,2));
                break;
            case "sonic":
                message("info", "%^RESET%^%^CRST%^%^C090%^The storm above unleashes a %^C218%^p%^C212%^a%^C206%^nde%^C212%^m%^C206%^oni%^C212%^u%^C218%^m %^C090%^of deadly %^C243%^n%^C247%^o%^C251%^i%^C243%^s%^C247%^e %^RESET%^%^C090%^and %^C243%^v%^C247%^i%^C251%^b%^C243%^r%^C247%^a%^C251%^t%^C243%^i%^C247%^o%^C251%^n%^C243%^s %^RESET%^%^C090%^that %^C092%^ravages %^C090%^everything in sight!", nearbyRoom(place,2));
                break;
            default:
                message("info", "%^RESET%^%^CRST%^%^C081%^S%^C087%^h%^C123%^ar%^C087%^d%^C081%^s %^C075%^of %^C087%^i%^C123%^c%^C087%^e %^RESET%^%^C039%^pour out of the sky, %^C051%^slamming %^C039%^into everything in sight!%^CRST%^", nearbyRoom(place,2));
                break;
        }

        for (i=0;i<j;i++){
            if(!objectp(foes[i])) continue;
            if(!objectp(caster)){
                dest_effect();
                return;
            }
            if(foes[i] == caster && caster != target) continue;
            if(interactive(foes[i]) && newbiep(foes[i])) continue;
            if(foes[i]->query_property("no detect")) continue;
//added by Circe to stop scry detectors, etc, from being hit.
            if(!present(caster,place) && caster != target){
                dest_effect();
                return;
            }
            if(!present(foes[i],place)) continue;

            target_limb = foes[i]->return_target_limb();
            damage_targ(foes[i], target_limb, sdamage,element);
      }
        time += 1;
        if(present(caster,place) && !caster->query_unconscious()){
            environment(CASTER)->addObjectToCombatCycle(TO,1);
        }
        else{
            dest_effect();
        }
    }
}

void dest_effect() {
    if(objectp(place)) tell_room(place, "%^RESET%^%^CRST%^%^C243%^The %^C247%^s%^C249%^t%^C251%^o%^C249%^r%^C247%^m %^RESET%^%^C243%^overhead breaks apart and the clouds %^C059%^dissipate%^C243%^.%^CRST%^");
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

