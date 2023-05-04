#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string YOU, HIM, element;


void create(){
    ::create();
    set_spell_name("cone of cold");
    set_spell_level(([ "mage" : 5, "monk" : 15, "magus" : 5 ]));
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS cone of cold on TARGET");
    set_damage_desc("delayed cold");
    set_description("By casting this spell, you form a massive white cone of icy cold towards your target. Not only does this spell increase damage-wise as the caster increases in level, but also, the chance of hitting an unintended target in addition to the intentional one increases too. The mage will try to aim the spell at only hostile targets, but this is not always possible.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    versatile();
    set_components(([ "mage" : ([ "crystal" : 1, ]), ]));
    set_save("reflex");
    set_immunities(({"cold"}));
}


string query_cast_string(){
    if(spell_type == "monk"){
        tell_object(caster, "%^RESET%^%^CRST%^%^C101%^You take in a deep breath, focusing your %^C100%^ki%^RESET%^%^C101%^.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ inhales %^C100%^deeply%^C101%^...%^CRST%^", caster);
    }
    tell_object(caster, "%^RESET%^%^CRST%^%^C101%^You mutter some words while raising a crystal, cupping it gently in your hands.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ mutters some words while raising a %^C250%^c%^C255%^rys%^C250%^t%^C255%^a%^C250%^l%^RESET%^%^C101%^, cupping it gently in "+caster->query_possessive()+" hands.%^CRST%^", caster);
    return "display";
}


void spell_effect(int prof){
    if(!objectp(caster)){
        dest_effect();
        return;
    }

    YOU = caster->query_cap_name();
    HIM = target->query_cap_name();
    
    element = (string)caster->query("elementalist");
    if(element){
        set_immunities(({ element }));
        define_clevel();
        define_base_damage(0);
    }
    
    switch(element){
        case "acid":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C065%^Raising a finger to your lips, you exhale a cloud of %^C118%^s%^C112%^ic%^C106%^k%^C118%^l%^C112%^y %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C065%^.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C065%^Raising a finger to "+caster->possessive()+" lips,"+YOU+"%^RESET%^%^CRST%^%^C065%^ exhales a cloud of %^C118%^s%^C112%^ic%^C106%^k%^C118%^l%^C112%^y %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C065%^.%^CRST%^", caster);
            }
            else{
                tell_object(caster, "%^RESET%^%^CRST%^%^C065%^The crystal pulses with a short-lived, %^C118%^s%^C112%^ic%^C106%^k%^C118%^l%^C112%^y g%^C106%^r%^C118%^e%^C112%^en %^C106%^l%^C118%^i%^C112%^gh%^C106%^t%^RESET%^%^C065%^ that slightly burns your hands.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C065%^"+YOU+"%^RESET%^%^CRST%^%^C065%^'s hands tremble violently as "+caster->query_subjective()+" grasps the %^C118%^c%^C112%^ry%^C106%^s%^C118%^t%^C112%^al%^RESET%^%^C065%^.%^CRST%^", ({caster}) );
            }
            break;
        case "electricity":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C100%^Raising a finger to your lips, you exhale a dark, %^C059%^s%^C243%^to%^C059%^r%^C243%^m%^C059%^y c%^C243%^lou%^C059%^d%^RESET%^%^C100%^.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^Raising a finger to "+caster->possessive()+" lips,"+YOU+"%^RESET%^%^CRST%^%^C100%^ exhales a dark, %^C059%^s%^C243%^to%^C059%^r%^C243%^m%^C059%^y c%^C243%^lou%^C059%^d%^RESET%^%^C100%^.%^CRST%^", ({caster}));
            }
            else{
                tell_object(caster, "%^RESET%^%^CRST%^%^C100%^The %^C228%^cr%^C231%^y%^C228%^st%^C226%^a%^C228%^l%^RESET%^%^C100%^ develops a static charge, making your hands tremble.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+YOU+"%^RESET%^%^CRST%^%^C100%^'s hands tremble violently as "+caster->query_subjective()+" grasps the %^C228%^cr%^C231%^y%^C228%^st%^C226%^a%^C228%^l%^RESET%^%^C100%^.%^CRST%^", ({caster}) );
            }
            break;
        case "fire":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C124%^Raising a finger to your lips, you exhale a cloud of %^C208%^r%^C214%^o%^C208%^i%^C202%^l%^C208%^i%^C214%^n%^C208%^g %^C202%^f%^C208%^l%^C214%^a%^C208%^m%^C202%^e%^C208%^s%^RESET%^%^C124%^.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C124%^Raising a finger to "+caster->possessive()+" lips,"+YOU+"%^RESET%^%^CRST%^%^C124%^ exhales a cloud of %^C208%^r%^C214%^o%^C208%^i%^C202%^l%^C208%^i%^C214%^n%^C208%^g %^C202%^f%^C208%^l%^C214%^a%^C208%^m%^C202%^e%^C208%^s%^RESET%^%^C124%^.%^CRST%^", ({caster}));
            }
            else{
                tell_object(caster, "%^RESET%^%^CRST%^%^C124%^The %^C208%^c%^C214%^r%^C208%^y%^C202%^s%^C208%^t%^C214%^a%^C208%^l%^RESET%^%^C124%^ takes on a sudden heat, making your hands tremble.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+YOU+"%^RESET%^%^CRST%^%^C124%^'s hands tremble violently as "+caster->query_subjective()+" grasps the %^C208%^c%^C214%^r%^C208%^y%^C202%^s%^C208%^t%^C214%^a%^C208%^l%^RESET%^%^C124%^.%^CRST%^", ({caster}) );
            }
            break;
        case "sonic":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C090%^Raising a finger to your lips, you begin to intone a %^C243%^d%^C059%^ee%^C243%^p b%^C059%^as%^C243%^s %^C218%^s%^C212%^o%^C206%^u%^C212%^n%^C218%^d%^RESET%^%^C090%^.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^Raising a finger to "+caster->possessive()+" lips,"+YOU+"%^RESET%^%^CRST%^%^C090%^ begin to intone a %^C243%^d%^C059%^ee%^C243%^p b%^C059%^as%^C243%^s %^C218%^s%^C212%^o%^C206%^u%^C212%^n%^C218%^d%^RESET%^%^C090%^.%^CRST%^", ({caster}));
            }
            else{
                tell_object(caster, "%^RESET%^%^CRST%^%^C090%^A powerful, low-pitched droning emanates from the %^C218%^c%^C212%^r%^C206%^yst%^C212%^a%^C218%^l%^RESET%^%^C090%^, making your hands tremble.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+YOU+"%^RESET%^%^CRST%^%^C090%^'s hands tremble violently as "+caster->query_subjective()+" grasps the %^C218%^c%^C212%^r%^C206%^yst%^C212%^a%^C218%^l%^RESET%^%^C090%^.%^CRST%^", ({caster}) );
            }
            break;
        default:
            element = "cold";
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C039%^Raising a finger to your lips, you exhale a cloud of %^C250%^a%^C255%^rct%^C250%^i%^C255%^c fro%^C250%^s%^C255%^t%^RESET%^%^C039%^.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^Raising a finger to "+caster->possessive()+" lips,"+YOU+"%^RESET%^%^CRST%^%^C039%^ exhales a cloud of %^C250%^a%^C255%^rct%^C250%^i%^C255%^c fro%^C250%^s%^C255%^t%^RESET%^%^C039%^.%^CRST%^", ({caster}));
            }
            else{
                tell_object(caster, "%^RESET%^%^CRST%^%^C039%^Slowly your %^C250%^c%^C255%^rys%^C250%^t%^C255%^a%^C250%^l%^RESET%^%^C039%^ chills to an icy cold, making your hands tremble.%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^"+YOU+"%^RESET%^%^CRST%^%^C039%^'s hands tremble violently as "+caster->query_subjective()+" grasps the %^C250%^c%^C255%^rys%^C250%^t%^C255%^a%^C250%^l%^RESET%^%^C039%^.%^CRST%^", ({caster}) );
            }
            break;
    }
    
    if(interactive(caster)) call_out("zapper", 4);
    else zapper();
}


void zapper(){
    string before, after, size;
    object *inven, *hits = ({});
    int i;

    if(!objectp(caster)){
        dest_effect();
        return;
    }

    if(!objectp(target) || !objectp(place) || !present(target, place)){
        if(spell_type == "monk"){
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^The cloud of air turns into a harmless breath.%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C059%^"+YOU+"%^RESET%^%^CRST%^%^C059%^'s cloud of air turns into a harmless breath.%^CRST%^", caster);
            dest_effect();
            return;
        }
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Your crystal sublimes into harmless steam.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C059%^"+YOU+"%^RESET%^%^CRST%^%^C059%^'s crystal sublimes into harmless steam.%^CRST%^", caster);
        dest_effect();
        return;
    }

    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }

    spell_successful();

    size = "avalanche";
    if (clevel < 15) size = "gush";
    if (clevel < 20) size = "flood";

    switch(element){
        case "acid":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C065%^You unleash a massive "+size+" of %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C065%^ toward "+HIM+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C065%^"+YOU+"%^RESET%^%^CRST%^%^C065%^ unleashes a massive "+size+" of %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C065%^ toward "+HIM+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^", ({target, caster}));
                tell_object(target, "%^RESET%^%^CRST%^%^C065%^"+YOU+"%^RESET%^%^CRST%^%^C065%^ unleashes a massive "+size+" of %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C065%^ toward you!%^CRST%^");
            }
            else{
                tell_room(place, "%^RESET%^%^CRST%^%^C065%^A cyclone of deadly %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C065%^ bursts forth from the %^C118%^c%^C112%^ry%^C106%^s%^C118%^t%^C112%^al%^RESET%^%^C065%^, directly toward "+HIM+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^", target);
                tell_object(target, "%^RESET%^%^CRST%^%^C065%^A cyclone of deadly %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^RESET%^%^C065%^ bursts forth from "+YOU+"%^RESET%^%^CRST%^%^C065%^'s %^C118%^c%^C112%^ry%^C106%^s%^C118%^t%^C112%^al%^RESET%^%^C065%^, directly toward you!%^CRST%^");
            }
            break;
        case "electricity":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C100%^You unleash a massive "+size+" of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C100%^ toward "+HIM+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+YOU+"%^RESET%^%^CRST%^%^C100%^ unleashes a massive "+size+" of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C100%^ toward "+HIM+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^", ({target, caster}));
                tell_object(target, "%^RESET%^%^CRST%^%^C100%^"+YOU+"%^RESET%^%^CRST%^%^C100%^ unleashes a massive "+size+" of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C100%^ toward you!%^CRST%^");
            }
            else{
                tell_room(place, "%^RESET%^%^CRST%^%^C100%^A wave of brilliant %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C100%^ surges forth from the %^C228%^cr%^C231%^y%^C228%^st%^C226%^a%^C228%^l%^RESET%^%^C100%^ toward "+HIM+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^", target);
                tell_object(target, "%^RESET%^%^CRST%^%^C100%^A wave of brilliant %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g%^RESET%^%^C100%^ surges forth from "+YOU+"%^RESET%^%^CRST%^%^C100%^'s %^C228%^cr%^C231%^y%^C228%^st%^C226%^a%^C228%^l%^RESET%^%^C100%^ toward you!%^CRST%^");
            }
            break;
        case "fire":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C124%^You unleash a massive "+size+" of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^RESET%^%^C124%^ toward "+HIM+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+YOU+"%^RESET%^%^CRST%^%^C124%^ unleashes a massive "+size+" of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^RESET%^%^C124%^ toward "+HIM+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^", ({target, caster}));
                tell_object(target, "%^RESET%^%^CRST%^%^C124%^"+YOU+"%^RESET%^%^CRST%^%^C124%^ unleashes a massive "+size+" of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^RESET%^%^C124%^ toward you!%^CRST%^");
            }
            else{
                tell_room(place, "%^RESET%^%^CRST%^%^C124%^A blazing maelstrom of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^RESET%^%^C124%^ bursts forth from the crystal toward "+HIM+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^", target);
                tell_object(target, "%^RESET%^%^CRST%^%^C124%^A blazing maelstrom of %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^RESET%^%^C124%^ bursts forth from "+YOU+"%^RESET%^%^CRST%^%^C124%^'s crystal toward you!%^CRST%^");
            }
            break;
        case "sonic":
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C090%^You unleash a massive "+size+" of %^C218%^c%^C212%^a%^C206%^cophon%^C212%^i%^C218%^c s%^C212%^o%^C206%^u%^C212%^n%^C218%^d%^RESET%^%^C090%^ toward "+HIM+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+YOU+"%^RESET%^%^CRST%^%^C090%^ unleashes a massive "+size+" of %^C218%^c%^C212%^a%^C206%^cophon%^C212%^i%^C218%^c s%^C212%^o%^C206%^u%^C212%^n%^C218%^d%^RESET%^%^C090%^ toward "+HIM+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^", ({target, caster}));
                tell_object(target, "%^RESET%^%^CRST%^%^C090%^"+YOU+"%^RESET%^%^CRST%^%^C090%^ unleashes a massive "+size+" of %^C218%^c%^C212%^a%^C206%^cophon%^C212%^i%^C218%^c s%^C212%^o%^C206%^u%^C212%^n%^C218%^d%^RESET%^%^C090%^ toward you!%^CRST%^");
            }
            else{
                tell_room(place, "%^RESET%^%^CRST%^%^C090%^The %^C218%^c%^C212%^r%^C206%^yst%^C212%^a%^C218%^l%^RESET%^%^C090%^ shatters, and a massive %^C218%^s%^C212%^h%^C206%^ockwa%^C212%^v%^C218%^e%^RESET%^%^C090%^ assaults "+HIM+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^", target);
                tell_object(target, "%^RESET%^%^CRST%^%^C090%^The %^C218%^c%^C212%^r%^C206%^yst%^C212%^a%^C218%^l%^RESET%^%^C090%^ shatters, and a massive %^C218%^s%^C212%^h%^C206%^ockwa%^C212%^v%^C218%^e%^RESET%^%^C090%^ assaults you!%^CRST%^");
            }
            break;
        default:
            if(spell_type == "monk"){
                tell_object(caster, "%^RESET%^%^CRST%^%^C039%^You unleash a massive "+size+" of %^C250%^f%^C255%^ro%^C250%^s%^C255%^t%^RESET%^%^C039%^ toward "+HIM+"%^RESET%^%^CRST%^%^C039%^!%^CRST%^");
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^"+YOU+"%^RESET%^%^CRST%^%^C039%^ unleashes a massive "+size+" of %^C250%^f%^C255%^ro%^C250%^s%^C255%^t%^RESET%^%^C039%^ toward "+HIM+"%^RESET%^%^CRST%^%^C039%^!%^CRST%^", ({target, caster}));
                tell_object(target, "%^RESET%^%^CRST%^%^C039%^"+YOU+"%^RESET%^%^CRST%^%^C039%^ unleashes a massive "+size+" of %^C250%^f%^C255%^ro%^C250%^s%^C255%^t%^RESET%^%^C039%^ toward you!%^CRST%^");
            }
            else{
                tell_room(place, "%^RESET%^%^CRST%^%^C039%^A massive "+size+" of %^C250%^f%^C255%^ro%^C250%^s%^C255%^t%^RESET%^%^C039%^ thrusts forth from the %^C250%^c%^C255%^rys%^C250%^t%^C255%^a%^C250%^l%^RESET%^%^C039%^ toward "+HIM+"%^RESET%^%^CRST%^%^C039%^!%^CRST%^", target);
                tell_object(target, "%^RESET%^%^CRST%^%^C039%^A massive "+size+" of %^C250%^f%^C255%^ro%^C250%^s%^C255%^t%^RESET%^%^C039%^ thrusts forth from "+YOU+"%^RESET%^%^CRST%^%^C039%^'s %^C250%^c%^C255%^rys%^C250%^t%^C255%^a%^C250%^l%^RESET%^%^C039%^ toward you!%^CRST%^");
            }
            break;
    }

    inven = target_selector(1);


    if(sizeof(inven)){
        for(i=0;i<sizeof(inven);i++){
            if(!objectp(inven[i])) { continue; }
            if(inven[i] == caster) { continue; }
            if(inven[i] == target) { continue; }
            if(random(100) < clevel){
                hits += ({ inven[i] });
                continue;
            }
            if(random(500) < clevel){
                hits += ({ inven[i] });
                continue;
            }
        }
    }

    if(sizeof(hits)){
        for (i = 0;i < sizeof(hits);i++){
            if(!objectp(hits[i])) { continue; }

            switch(element){
                case "acid":
                    tell_object(hits[i], "%^RESET%^%^CRST%^%^C077%^The corrosive vapor washes over you!%^CRST%^");
                    tell_room(place, "%^RESET%^%^CRST%^%^C065%^The corrosive vapor washes over "+hits[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^", hits[i]);
                    break;
                case "electricity":
                    tell_object(hits[i], "%^RESET%^%^CRST%^%^C226%^You are jolted by a stray bolt of lightning!%^CRST%^");
                    tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+hits[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ is jolted by a stray bolt of lightning!%^CRST%^", hits[i]);
                    break;
                case "fire":
                    tell_object(hits[i], "%^RESET%^%^CRST%^%^C196%^You are singed by the fiery maelstrom!%^CRST%^");
                    tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+hits[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^ is singed by the fiery maelstrom!%^CRST%^", hits[i]);
                    break;
                case "sonic":
                    tell_object(hits[i], "%^RESET%^%^CRST%^%^C092%^You are caught within the shockwave!%^CRST%^");
                    tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+hits[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^ is caught within the shockwave!%^CRST%^", hits[i]);
                    break;
                default:
                    tell_object(hits[i], "%^RESET%^%^CRST%^%^C051%^You are caught by a wisp of frosty vapor!%^CRST%^");
                    tell_room(place, "%^RESET%^%^CRST%^%^C039%^"+hits[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C039%^ is caught by a wisp of frosty vapor!%^CRST%^", hits[i]);
                    break;
            }
            
            if(do_save(hits[i])){
                damage_targ(hits[i],"torso",sdamage/2,element);
            }
            else{
                damage_targ(hits[i],"torso",sdamage,element);
            }
        }
    }

    switch(element){
        case "acid":
            tell_object(target, "%^RESET%^%^CRST%^%^C077%^You are surrounded by the burning toxic vapor!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C065%^"+HIM+"%^RESET%^%^CRST%^%^C065%^ is surrounded by the burning toxic vapor!%^CRST%^", target);
            break;
        case "electricity":
            tell_object(target, "%^RESET%^%^CRST%^%^C226%^You are blasted by the wave of crackling lightning!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+HIM+"%^RESET%^%^CRST%^%^C100%^ is blasted painfully by the wave of lightning!%^CRST%^", target);
            break;
        case "fire":
            tell_object(target, "%^RESET%^%^CRST%^%^C196%^You are blasted by the full force of the fiery maelstrom!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+HIM+"%^RESET%^%^CRST%^%^C124%^ is blasted with the full force of the fiery maelstrom!%^CRST%^", target);
            break;
        case "sonic":
            tell_object(target, "%^RESET%^%^CRST%^%^C092%^You are blasted squarely by the brunt of the shockwave!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+HIM+"%^RESET%^%^CRST%^%^C090%^ is blasted squarely by the brunt of the shockwave!%^CRST%^", target);
            break;
        default:
            tell_object(target, "%^RESET%^%^CRST%^%^C051%^The frosty vapor slams into you, draining heat, strength, and life!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C039%^The frosty vapor slams into "+HIM+"%^RESET%^%^CRST%^%^C039%^, draining heat, strength, and life!%^CRST%^", target);
        break;
    }
    
    if(do_save(target)){
        if(!evade_splash(target)){
            damage_targ(target, "torso", sdamage / 2, element);
        }
    }
    else damage_targ(target, "torso", sdamage, element);
    dest_effect();
}


void dest_effect(){
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

