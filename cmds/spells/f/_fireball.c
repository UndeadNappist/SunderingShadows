#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string element;

void create()
{
    ::create();
    set_spell_name("fireball");
    set_spell_level(([ "mage" : 3, "monk" : 7, "oracle" : 3, "magus" : 3, "cleric" : 3, "druid" : 3 ]));
    set_domains("fire");
    set_circle("wildfire");
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS fireball [on TARGET]");
    set_damage_desc("fire, versatile arcanist");
    set_description("By casting this spell, a mage can aim and release a massive ball of fire at a target and those around him. The fireball spell will wreak havoc on the caster's target and those who oppose him. Damage done to those hit by the spell halved if they manage to evade the brunt of the spell.");
    set_verbal_comp();
    set_somatic_comp();
    versatile();
    set_target_required(1);
    splash_spell(1);
    set_components(([ "mage" : ([ "bat guano":1, "sulfur":1, ]), ]));
    set_save("reflex");
    set_immunities(({ "fire" }));
}


string query_cast_string(){
    element = (string)caster->query("elementalist");
    switch(element){
        case "acid":
            tell_object(caster, "%^RESET%^%^CRST%^%^C065%^You chant rapidly, creating an %^C077%^o%^C071%^r%^C070%^b %^C076%^o%^C070%^f %^C071%^a%^C077%^c%^C071%^i%^C070%^d %^RESET%^%^C065%^in your hand.%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C065%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^ chants rapidly, creating an %^C077%^o%^C071%^r%^C070%^b %^C076%^o%^C070%^f %^C071%^a%^C077%^c%^C071%^i%^C070%^d %^RESET%^%^C065%^in "+caster->query_possessive()+" hand.%^CRST%^",caster);
            break;
        case "cold":
            tell_object(caster, "%^RESET%^%^CRST%^%^C027%^You chant rapidly, creating an %^C045%^o%^C051%^r%^C045%^b %^C039%^of %^C045%^f%^C051%^ros%^C045%^t %^RESET%^%^C027%^in your hand.%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C027%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C027%^ chants rapidly, creating an %^C045%^o%^C051%^r%^C045%^b %^C039%^of %^C045%^f%^C051%^ros%^C045%^t %^RESET%^%^C027%^in "+caster->query_possessive()+" hand.%^CRST%^",caster);
            break;
        case "electricity":
            tell_object(caster, "%^RESET%^%^CRST%^%^C100%^You chant rapidly, creating an %^C228%^o%^C231%^r%^C228%^b %^C226%^of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^in your hand.%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C100%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ chants rapidly, creating an %^C228%^o%^C231%^r%^C228%^b %^C226%^of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^in "+caster->query_possessive()+" hand.%^CRST%^",caster);
            break;
        case "sonic":
            tell_object(caster, "%^RESET%^%^CRST%^%^C090%^You chant rapidly, creating an %^C212%^o%^C206%^r%^C212%^b %^C218%^of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^in your hand.%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C090%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^ chants rapidly, creating an %^C212%^o%^C206%^r%^C212%^b %^C218%^of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^in "+caster->query_possessive()+" hand.%^CRST%^",caster);
            break;
        default:
            tell_object(caster, "%^RESET%^%^CRST%^%^C124%^You chant rapidly, creating an %^C208%^o%^C214%^r%^C208%^b %^C202%^of %^C208%^f%^C214%^i%^C208%^r%^C202%^e %^RESET%^%^C124%^in your hand.%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C124%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^ chants rapidly, creating an %^C208%^o%^C214%^r%^C208%^b %^C202%^of %^C208%^f%^C214%^i%^C208%^r%^C202%^e %^RESET%^%^C124%^in "+caster->query_possessive()+" hand.%^CRST%^",caster);
            break;
    }
    return "display";
}


void spell_effect(int prof){
    object *foes = ({});
    string YOU, HIM, tmp = "";
    int i;

    if(!objectp(caster)){
        dest_effect();
        return;
    }

    if(!present(target, caster->is_room() ? caster : environment(caster) )){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Your target is not in this area.%^CRST%^\n");
        dest_effect();
        return;
    }
    
    element = (string)caster->query("elementalist");
    if(element){
        set_immunities(({ element }));
        define_clevel();
        define_base_damage(0);
    }

    YOU = caster->query_cap_name();
    HIM = target->query_cap_name();

    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }
    spell_successful();

    foes = target_selector(1);

    if(interactive(caster)) { tmp = "'s finger"; }

    switch(element){
        case "acid":
            tell_object(target, "%^RESET%^%^CRST%^%^C065%^An %^C077%^o%^C071%^r%^C070%^b %^C076%^o%^C070%^f %^C071%^a%^C077%^c%^C071%^i%^C070%^d %^RESET%^%^C065%^speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C065%^"+tmp+", heading straight for you!%^CRST%^");
            if(living(caster)) tell_object(caster, "%^RESET%^%^CRST%^%^C065%^An %^C077%^o%^C071%^r%^C070%^b %^C076%^o%^C070%^f %^C071%^a%^C077%^c%^C071%^i%^C070%^d %^RESET%^%^C065%^speeds through the air from your hand, heading straight for "+HIM+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C065%^An orb of acid speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C065%^"+tmp+", heading straight for "+HIM+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^",({ caster, target}) );
            break;
        case "cold":
            tell_object(target, "%^RESET%^%^CRST%^%^C027%^An %^C045%^o%^C051%^r%^C045%^b %^C039%^of %^C045%^f%^C051%^ros%^C045%^t %^RESET%^%^C027%^speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C027%^"+tmp+", heading straight for you!%^CRST%^");
            if(living(caster)) tell_object(caster, "%^RESET%^%^CRST%^%^C027%^An orb of frost and ice speeds through the air from your hand, heading straight for "+HIM+"%^RESET%^%^CRST%^%^C027%^!%^CRST%^");
            tell_room(place, "%^BOLD%^%^CYAN%^An %^C045%^o%^C051%^r%^C045%^b %^C039%^of %^C045%^f%^C051%^ros%^C045%^t %^RESET%^%^C027%^speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C027%^"+tmp+", heading straight for "+HIM+"%^RESET%^%^CRST%^%^C027%^!%^CRST%^",({ caster, target}) );
            break;
        case "electricity":
            tell_object(target, "%^RESET%^%^CRST%^%^C100%^An %^C228%^o%^C231%^r%^C228%^b %^C226%^of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C100%^"+tmp+", heading straight for you!%^CRST%^");
            if(living(caster)) tell_object(caster, "%^RESET%^%^CRST%^%^C100%^An %^C228%^o%^C231%^r%^C228%^b %^C226%^of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^speeds through the air from your hand, heading straight for "+HIM+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C100%^An %^C228%^o%^C231%^r%^C228%^b %^C226%^of %^C228%^l%^C231%^i%^C228%^gh%^C226%^t%^C231%^n%^C228%^in%^C226%^g %^RESET%^%^C100%^speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C100%^"+tmp+", heading straight for "+HIM+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^",({ caster, target}) );
            break;
        case "sonic":
            tell_object(target, "%^RESET%^%^CRST%^%^C090%^An %^C212%^o%^C206%^r%^C212%^b %^C218%^of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C090%^"+tmp+", heading straight for you!%^CRST%^");
            if(living(caster)) tell_object(caster, "%^RESET%^%^CRST%^%^C090%^An %^C212%^o%^C206%^r%^C212%^b %^C218%^of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^speeds through the air from your hand, heading straight for "+HIM+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C090%^An %^C212%^o%^C206%^r%^C212%^b %^C218%^of s%^C212%^o%^C206%^u%^C212%^n%^C218%^d %^RESET%^%^C090%^speeds through the air from "+YOU+"%^RESET%^%^CRST%^%^C090%^"+tmp+", heading straight for "+HIM+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^",({ caster, target}) );
            break;
        default:
            element = "fire";
            tell_object(target, "%^RESET%^%^CRST%^%^C124%^A massive ball of fire jets out from "+YOU+"%^RESET%^%^CRST%^%^C124%^"+tmp+", furiously growing as it speeds towards you!%^CRST%^");
            if(living(caster)) tell_object(caster, "%^RESET%^%^CRST%^%^C124%^A massive ball of fire jets out from your finger, furiously growing as it speeds towards "+HIM+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C124%^A massive ball of fire jets out from "+YOU+"%^RESET%^%^CRST%^%^C124%^"+tmp+" furiously growing as it speeds towards "+HIM+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^",({ caster, target}) );
            break;
    }

    switch(element)
    {
    case "acid":
        tell_object(target, "%^RESET%^%^CRST%^%^C046%^The acid orb explodes as it hits you!%^CRST%^",target);
        tell_room(environment(target),"%^RESET%^%^CRST%^%^C046%^The orb of acid explodes as it hits "+HIM+"%^RESET%^%^CRST%^%^C046%^!%^CRST%^",target);
        break;
    case "cold":
        tell_object(target, "%^RESET%^%^CRST%^%^C051%^The frost orb explodes as it hits you!%^CRST%^",target);
        tell_room(environment(target), "%^RESET%^%^CRST%^%^C051%^The orb of frost explodes as it hits "+HIM+"%^RESET%^%^CRST%^%^C051%^!%^CRST%^",target);
        break;
    case "electricity":
        tell_object(target, "%^RESET%^%^CRST%^%^C228%^The lightning orb explodes as it hits you!%^CRST%^",target);
        tell_room(environment(target), "%^RESET%^%^CRST%^%^C228%^The orb of lightning explodes as it hits "+HIM+"%^RESET%^%^CRST%^%^C228%^!%^CRST%^",target);
        break;
    case "sonic":
        tell_object(target, "%^RESET%^%^CRST%^%^C200%^The sonic orb explodes as it hits you!%^CRST%^",target);
        tell_room(environment(target), "%^RESET%^%^CRST%^%^C200%^The orb of sound explodes as it hits "+HIM+"%^RESET%^%^CRST%^%^C200%^!%^CRST%^",target);
        break;
    default:
        tell_object(target, "%^RESET%^%^CRST%^%^C196%^The ball of fire explodes into you!%^CRST%^",target);
        tell_room(environment(target), "%^RESET%^%^CRST%^%^C196%^The ball of fire explodes into "+HIM+"%^RESET%^%^CRST%^%^C196%^!%^CRST%^",target);
        break;
    }

    if(do_save(target)){
        if(!evade_splash(target)) damage_targ(target, "torso", to_int(sdamage / 2), element);
    }
    else{
        damage_targ(target, "torso", sdamage, element);
    }

    for(i=0;i<sizeof(foes);i++){
        if(!objectp(foes[i])) { continue; }
        if(!do_save(foes[i])){
            switch(element)
            {
            case "acid":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C065%^Acid sears into "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^'s flesh!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C046%^Your flesh is burnt by the acid!%^CRST%^");
                break;
            case "cold":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C027%^Shards of ice and frost tear into "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C027%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C051%^Shards of ice and frost tear into your skin!%^CRST%^");
                break;
            case "electricity":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C100%^Bolts of lightning from the orb shock "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C228%^You are shocked by bolts of lighting from the orb!%^CRST%^");
                break;
            case "sonic":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C090%^Sonic waves slam into "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^200%^Sonic waves slam into you!%^CRST%^");
                break;
            default:
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C124%^The blast of the explosion smashes into "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^196%^The blast of the explosion smashes into you!%^CRST%^");
                break;
            }
            damage_targ(foes[i], "torso", sdamage, element);
        }
        else
        {
            switch(element)
            {
            case "acid":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C065%^Acid splashes onto "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C065%^Acid splashes onto you!%^CRST%^");
                break;
            case "cold":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C027%^Shards of ice and frost graze "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C027%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C027%^Shards of ice and frost graze you from the orb!%^CRST%^");
                break;
            case "electricity":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C100%^A stray bolt of lightning from the orb jolts "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C100%^A stray bolt of lightning from the orb jolts you!%^CRST%^");
                break;
            case "sonic":
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C090%^Sonic waves graze past "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C090%^Sonic waves graze you!%^CRST%^");
                break;
            default:
                tell_room(environment(foes[i]), "%^RESET%^%^CRST%^%^C124%^The blast singes "+foes[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^",foes[i]);
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C124%^The blast of the explosion singes you!%^CRST%^");
                break;
            }
            damage_targ(foes[i], "torso", sdamage / 2, element);
        }
    }

    dest_effect();
    return;
}


void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

