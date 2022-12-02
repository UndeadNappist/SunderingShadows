#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create(){
    ::create();
    set_spell_name("acid fog");
    set_spell_level(([ "mage":6,"magus" : 6 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS acid fog");
    set_damage_desc("acid");
    set_description("With this spell the mage opens a portal to the paraelemental plane of ooze, allowing raw matter of that plane to enter the world. For the duration of the spell's effect, the area will be filled with acidic fumes. The mage can then direct them to attack her enemies.");
    set_verbal_comp();
    set_somatic_comp();
    set_immunities( ({"acid"}) );
    set_components((["mage":(["citric acid":1,"nitric acid":1])]));
    aoe_spell(1);
    set_aoe_message("%^RESET%^%^CRST%^%^C064%^(%^C065%^engulfed in %^C190%^acidic %^C070%^f%^C076%^o%^C077%^g%^C064%^)%^CRST%^");
}

string query_cast_string(){
    tell_object(caster, "%^RESET%^%^CRST%^%^C065%^You draw an %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^C077%^-%^C071%^i%^C070%^n%^C076%^f%^C077%^u%^C071%^s%^C070%^e%^C076%^d %^C077%^s%^C071%^i%^C070%^g%^C076%^i%^C077%^l %^RESET%^%^C065%^in the air.%^CRST%^");
    tell_room(place,"%^RESET%^%^CRST%^%^C065%^"+caster->QCN+"%^RESET%^%^CRST%^%^C065%^ draws an %^C077%^a%^C071%^c%^C070%^i%^C076%^d%^C077%^-%^C071%^i%^C070%^n%^C076%^f%^C077%^u%^C071%^s%^C070%^e%^C076%^d %^C077%^s%^C071%^i%^C070%^g%^C076%^i%^C077%^l %^RESET%^%^C065%^in the air.%^CRST%^", caster);
    return "display";
}

void spell_effect(int prof){
    tell_object(caster,"%^RESET%^%^CRST%^%^C065%^You take quick retreat from the %^C077%^s%^C071%^i%^C070%^g%^C076%^i%^C077%^l %^RESET%^%^C065%^as it opens a %^C190%^portal %^RESET%^%^C065%^and %^C064%^fumes %^C065%^rush through it!%^CRST%^");
    tell_room(place,"%^RESET%^%^CRST%^%^C065%^"+caster->QCN+"%^RESET%^%^CRST%^%^C065%^ takes cover as the %^C190%^acidic %^C077%^s%^C071%^i%^C070%^g%^C076%^i%^C077%^l %^RESET%^%^C065%^explodes and %^C064%^fumes %^C065%^rush through the open portal!%^CRST%^",caster);
    counter = clevel * 3;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack(){
    object *foes=({}),targ;
    int i;

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

    foes = target_selector();
    foes -= ({ caster });

    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i]))
            continue;
        tell_object(targ,"%^RESET%^%^CRST%^%^C065%^You choke on %^C190%^acidic %^C064%^fumes%^C065%^!%^CRST%^");
        tell_room(place,"%^RESET%^%^CRST%^%^C065%^"+targ->QCN+"%^RESET%^%^CRST%^%^C065%^ chokes on %^C190%^acidic %^C064%^fumes%^C065%^!%^CRST%^",({targ}));
        damage_targ(targ,targ->return_target_limb(),sdamage,"acid");
    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place)) tell_object(place,"%^RESET%^%^CRST%^%^C065%^The %^C190%^acidic %^C070%^f%^C076%^o%^C077%^g %^RESET%^%^C065%^finally %^C059%^disperses%^C065%^!%^CRST%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

