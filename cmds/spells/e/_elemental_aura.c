#include <std.h>
#include <priest.h>
inherit SPELL;

int timer, flag, stage, toggle, counter;
string element;
mapping shortmap, colormap, myverb, yourverb;
shortmap = ([
    "fire" : " %^RESET%^%^CRST%^%^C059%^(%^C124%^bathed in %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s%^C059%^)%^CRST%^",
    "cold" : " %^RESET%^%^CRST%^%^C059%^(%^C033%^in an %^C045%^i%^C051%^c%^C045%^y h%^C051%^az%^C045%^e%^C059%^)%^CRST%^",
    "electricity" : " %^RESET%^%^CRST%^%^C059%^(%^C100%^engulfed in %^C228%^st%^C231%^o%^C226%^r%^C228%^mbo%^C231%^l%^C228%^t%^C226%^s%^C059%^)%^CRST%^",
    "acid" : " %^RESET%^%^CRST%^%^C059%^(%^C065%^in an %^C077%^a%^C071%^c%^C070%^i%^C076%^d %^C070%^f%^C071%^o%^C077%^g%^C059%^)%^CRST%^",
    ]);
colormap = ([
    "fire" : "%^C124%^",
    "cold" : "%^C033%^",
    "electricity" : "%^C100%^",
    "acid" : "%^C065%^",
    ]);
myverb = ([
    "fire" : "scorches",
    "cold" : "freezes",
    "electricity" : "shocks",
    "acid" : "burns",
    ]);
yourverb = ([
    "fire" : "scorched",
    "cold" : "frozen^",
    "electricity" : "shocked",
    "acid" : "burned",
    ]);


string* valid_forms(){
    return ({ "fire", "cold", "electricity", "acid" });
}

void create(){
    ::create();
    set_spell_name("elemental aura");
    set_spell_level(([ "mage" : 3, "magus" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS elemental aura on [acid|cold|electricity|fire]");
    set_damage_desc("based on argument");
    set_description("This spell surrounds the caster with elemental energy that will harm everything that attacks them. Quick enough enemies might evade some of the damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_helpful_spell(1);
    set_arg_needed(1);
    traveling_aoe_spell(1);
}

string query_cast_string(){
    tell_object(caster, "%^RESET%^%^CRST%^%^C255%^Circling your hands before you, you begin to evoke the element of "+colormap[element]+element+"%^RESET%^%^C255%^.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C255%^Circling "+caster->query_possessive()+" hands before "+caster->query_objective()+", "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^ begins to evoke the element of "+colormap[element]+element+"%^RESET%^%^C255%^.%^CRST%^", caster);
}

int preSpell(){
    if(caster->query_property("elemental aura")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already protected by an elemental aura.%^CRST%^");
        return 0;
    }
    
    if(member_array(arg, valid_forms()) == -1) element = "fire";
    else element = arg;

    return 1;
}

void spell_effect(int prof){
    tell_room(place, "%^RESET%^%^CRST%^"+colormap[element]+caster->query_cap_name()+"%^RESET%^%^CRST%^"+colormap[element]+" completes "+caster->query_possessive()+" evocation and is surrounded by "+element+"!%^CRST%^", caster);
    tell_object(caster, "%^RESET%^%^CRST%^"+colormap[element]+"You complete your evocation and are surrounded by "+element+"!%^CRST%^");
    caster->set_property("elemental aura", 1);
    caster->set_property("spelled", ({ this_object() }));
    caster->set_property("added short", ({ shortmap[element] }));
    addSpellToCaster();
    spell_successful();
    counter = 7 * clevel;
    execute_attack();
    call_out("room_check", ROUND_LENGTH);
}

void room_check(){
    if(!objectp(caster) || !objectp(environment(caster))){
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(environment(caster));

    call_out("room_check", ROUND_LENGTH * 2);
    return;
}

void execute_attack()
{
    object* foes = ({}), targ;
    int i, dam;

    if (!objectp(caster))
        return;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(place = environment(caster)))
    {
        dest_effect();
        return;
    }

    if(counter < 0)
    {
        dest_effect();
        return;
    }

    foes = caster->query_attackers();

    if(sizeof(foes))
    {
        define_base_damage(0);//reroll each turn
        tell_room(place, "%^RESET%^%^CRST%^"+colormap[element]+"The "+element+" around "+caster->query_cap_name()+"%^RESET%^%^CRST%^ "+colormap[element]+myverb[element]+" "+caster->query_possessive()+" enemies!%^CRST%^", ({ caster, target }));
        tell_object(caster, "%^RESET%^%^CRST%^"+colormap[element]+"The elemental aura "+myverb[element]+" your enemies!%^CRST%^");

        define_base_damage(0);

        for(i = 0; i < sizeof(foes); ++i)
        {
            dam = sdamage;

            if (!objectp(foes[i]))
                continue;

            if (do_save(foes[i], 0))
                dam /= 2;

            tell_object(foes[i], "%^RESET%^%^CRST%^"+colormap[element]+"You are "+yourverb[element]+" by a shield of "+element+" as you strike "+caster->query_cap_name()+"%^RESET%^%^CRST%^"+colormap[element]+"!%^CRST%^");
            damage_targ(foes[i], foes[i]->return_target_limb(), dam, element);
        }
    }

    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    object me;

    remove_call_out("room_check");

    if (objectp(caster))
    {
        if (objectp(environment(caster)))
            tell_room(environment(caster), "%^RESET%^%^CRST%^"+colormap[element]+"The elemental aura around "+caster->query_cap_name()+"%^RESET%^%^CRST%^"+colormap[element]+" fades away.", caster);
        tell_object(caster, "%^RESET%^%^CRST%^"+colormap[element]+"The elemental aura around you fades away.%^CRST%^", caster);
        caster->remove_property("elemental aura");
        caster->remove_property_value("added short", ({ shortmap[element] }));
    }

    ::dest_effect();

    if (objectp(me = this_object()))
        me->remove();
}

