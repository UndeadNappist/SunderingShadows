/*
  _archons_aura.c

  Non-evil version of oppression.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

object *saved = ({  });
int counter, flag;
string my_name, my_poss, my_pron;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("archons aura");
    set_spell_sphere("enchantment_charm");
    set_spell_level( ([ "cleric" : 4, "paladin" : 3, "inquisitor" : 4 ]) );
    set_domains("glory");
    set_syntax("cast CLASS archons aura");
    set_damage_desc("Shaken on attackers on failed save.");
    set_description("This spell surrounds the caster in a majestic aura of justice, causing enemies caught in the aura to be shaken unless they make a will saving throw. This aura will attempt to apply the shaken effect every round until the will save is made, then will no longer affect that target for the duration of combat.");
    traveling_spell(1);
    set_save("will");
}

string query_cast_string()
{
    my_name = caster->query_cap_name();
    my_poss = caster->query_possessive();
    my_pron = caster->query_subjective();

    tell_object(caster, "%^BOLD%^%^YELLOW%^Clenching your fists, you begin to growl the words of a prayer in a commanding tone.");
    tell_room(place, "%^BOLD%^%^YELLOW%^" + my_name + " clenches " + my_poss + " fist, growling the words of a prayer in a commanding tone.", caster);
    return "display";
}

int preSpell()
{
    if(caster->query_property("oppression"))
    {
        tell_object(caster, "You already have an aura of fear up.");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    int duration;

    ::spell_effect();

    my_name = caster->query_cap_name();
    my_poss = caster->query_possessive();
    my_pron = caster->query_subjective();

    tell_object(caster, "%^C033%^You begin to %^C051%^glow%^C033%^ with %^C051%^relentless resolve%^C033%^ as you complete your chant.%^CRST%^");
    tell_room(place, "%^C051%^" + my_name + "%^C033%^ begins to %^C051%^glow%^C033%^ with %^C051%^relentless resolve%^C033%^ as " + my_pron + " completes " + my_poss + " chant.%^CRST%^", caster);

    caster->set_property("spelled", ({ this_object() }));
    caster->set_property("added short",({" %^C033%^(%^C039%^m%^C045%^a%^C051%^j%^C045%^e%^C039%^s%^C045%^t%^C051%^i%^C039%^c a%^C045%^u%^C051%^r%^C039%^a%^C033%^)%^CRST%^"}));
    caster->set_property("oppression", 1);
    addSpellToCaster();
    counter = 8 * clevel;
    spell_duration = counter * ROUND_LENGTH;
    set_end_time();
    execute_attack();
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(environment(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(environment(caster));

    call_out("room_check",ROUND_LENGTH * 2);
    return;
}

void execute_attack()
{
    object *foes, targ;
    int i, dam, enchant;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(environment(caster)))
    {
        dest_effect();
        return;
    }

    place = environment(caster);

    if(!objectp(place) || counter < 0)
    {
        dest_effect();
        return;
    }

    foes = caster->query_attackers();

    if(!sizeof(foes))
        saved = ({  });

    foes -= saved;

    if(sizeof(foes))
    {
        foreach(object ob in foes)
        {
            if(!objectp(ob))
                continue;

            if(!do_save(ob, 0) && !PLAYER_D->immunity_check("fear"))
            {
                tell_object(ob, "%^C033%^You cower in %^C208%^fear%^C033%^ from " + caster->query_cap_name() + "'s %^C172%^majestic aura%^C033%^!%^CRST%^");
                tell_room(place, "%^C033%^" + ob->query_cap_name() + " cowers in %^C172%^fear %^C033%^from " + caster->query_cap_name() + "'s %^C172%^majestic aura%^C033%^!%^CRST%^", ob);
                "/std/effect/status/shaken"->apply_effect(ob, 1, caster);
            }
            else
            {
                tell_object(ob, "%^C172%^You manage to shrug off the majestic aura.%^CRST%^");
                tell_room(place, "%^C172%^" + ob->query_cap_name() + " manages to shrug off the majestic aura.%^CRST%^", ob);
                saved += ({ ob });
            }
        }

    }

    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster))
    {
        tell_room(environment(caster), "%^C178%^" + caster->query_cap_name() + "'s%^C039%^ majestic aura dissipates.%^CRST%^", caster);
        tell_object(caster, "%^C039%^Your majestic aura dissipates.%^CRST%^");
        caster->remove_property_value("added short",({" %^C033%^(%^C039%^m%^C045%^a%^C051%^j%^C045%^e%^C039%^s%^C045%^t%^C051%^i%^C039%^c a%^C045%^u%^C051%^r%^C039%^a%^C033%^)%^CRST%^"}));
        caster->remove_property("oppression");
    }
    ::dest_effect();

    if (objectp(this_object()))
        this_object()->remove();
}
