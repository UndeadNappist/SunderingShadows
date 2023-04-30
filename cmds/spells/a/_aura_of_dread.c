/*
  _aura_of_dread.c

  Mortuum-specific spell similar to oppression, but undermines fear immunity.

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
    set_spell_name("aura of dread");
    set_spell_sphere("necromancy");
    set_spell_level( ([ "innate" : 9 ]) );
    set_syntax("cast CLASS aura of dread");
    set_damage_desc("electricity and shaken on attackers on failed save. bypasses fear immunity.");
    set_description("");
    traveling_spell(1);
    set_save("will");
    evil_spell(1);
}

string query_cast_string()
{
    my_name = caster->query_cap_name();
    my_poss = caster->query_possessive();
    my_pron = caster->query_subjective();

    tell_object(caster, "%^BOLD%^%^BLACK%^Clenching your fists, you begin to growl the words of a prayer in a fearsome tone.");
    tell_room(place, "%^BOLD%^%^BLACK%^" + my_name + " clenches " + my_poss + " fist, growing the words of a prayer in a fearsome tone.", caster);
    return "display";
}

int preSpell()
{
    if(caster->query_property("oppression"))
    {
        tell_object(caster, "You already have an aura of oppression up.");
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

    tell_object(caster, "INITIAL CAST CASTER");
    tell_room(place, "INITIAL CAST ROOM", caster);

    caster->set_property("spelled", ({ this_object() }));
    caster->set_property("added short",({" SHORT DESC AURA MESS"}));
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
        tell_room("LIGHNING MESSAGE");
            
        foreach(object ob in foes)
        {
            if(!objectp(ob))
                continue;
          
            ob->cause_typed_damage(ob, "torso", sdamage / 2, "electricity");
            
            if(!objectp(ob))
                continue;

            if(!do_save(ob, 0)) //unlike oppression, overcomes fear immunity
            {
                tell_object(ob, "");
                tell_room(place, "", ob);
                "/std/effect/status/shaken"->apply_effect(ob, 1, caster);
            }
            else
            {
                tell_object(ob, "%^C063%^You manage to shrug off the oppressive aura.%^CRST%^");
                tell_room(place, "%^C063%^" + ob->query_cap_name() + " %^C063%^manages to shrug off the oppressive aura.%^CRST%^", ob);
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
        tell_room(environment(caster), "%^C081%^" + caster->query_cap_name() + "'s oppressive aura dissipates.%^CRST%^", caster);
        tell_object(caster, "%^C081%^Your oppressive aura dissipates.%^CRST%^");
        caster->remove_property_value("added short",({" SHORT DESC AURA"}));
        caster->remove_property("oppression");
    }
    ::dest_effect();

    if (objectp(this_object()))
        this_object()->remove();
}
