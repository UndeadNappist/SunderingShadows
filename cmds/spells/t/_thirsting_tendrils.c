#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("thirsting tendrils");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS thirsting tendrils");
    set_damage_desc("piercing, paralyzed, life leach");
    set_description("");
    set_description("");
    set_save("reflex");
    set_verbal_comp();
    set_somatic_comp();
    aoe_spell(1);
    set_aoe_message("persistent AOE message here ie: (tendrils)");
}

void spell_effect(int prof)
{
    tell_object(caster, "Spell cast message to caster");
    tell_room(place, "Spell cast message to room", caster);
    counter = clevel * 3;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object *foes=({});
    int i;
    string limb;
    int dam, gripped;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(caster) || !objectp(place) || !present(caster, place) || counter < 0 || place != environment(caster))
    {
        dest_effect();
        return;
    }

    message("info", "Roomwide message about what tendrils are doing", nearbyRoom(place,2));

    foes = target_selector();
    foes -= ({ caster });
    
    dam = sdamage;
    gripped = 0;

    foreach(object ob in foes)
    {
        if (!objectp(ob))
            continue;

        limb = ob->return_target_limb();
        
        set_save("reflex");
        
        if(do_save(ob, 0))
        {
            gripped = 0;
            tell_object(ob, "Avoiding the tendrils message");
        }
        else
        {
            tell_object(ob, "tendrils gripping target message");
            tell_room(place, "tendrils gripping room message", ({ ob }));
            ob->set_paralyzed(6, "%^BOLD%^The tendrils are gripping you tightly!%^RESET%^", 4);
            gripped = 1;
            damage_targ(ob, limb, dam, "piercing");
        }
        //Now a fort save to see if they can avoid the life drain.
        
        set_save("fort");
        
        if(objectp(ob) && gripped && !do_save(ob, 0) && !ob->is_undead())
        {
            tell_object(ob, "tendrils drinking their life target message");
            tell_room(place, "tendrils drinking their life room message");
            damage_targ(ob, limb, dam / 8, "negative energy");
            ob->add_hp(dam / 8);
        }
        
        set_save("reflex");
    }

    counter--;
    place->addObjectToCombatCycle(this_object(),1);
}

void dest_effect()
{
    if (objectp(place))
    {
        tell_object(place, "message for tendrils disappearing.");
    }
    ::dest_effect();
    if (objectp(this_object()))
        TO->remove();
}
