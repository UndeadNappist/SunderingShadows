// Invisibility - Coded by Vashkar@shadowgate

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <std.h>
inherit SPELL;

object invisob;

create()
{
    ::create();
    set_spell_name("invisibility");
    set_spell_level(([ "mage" : 2, "bard" : 2, "assassin" : 2, "inquisitor" : 2, "oracle" : 2, "magus" : 2, "cleric" : 2 ]));
    set_mystery("shadow");
    set_domains("illusion");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS invisibility [on TARGET]");
    set_description("Although called invisibility, this spell doesn't turn the target invisible. Instead, it alters the perception of everyone around them, making the target unnoticeable in the minds of others. This spell requires the target to move with some caution and will break itself if the target enters combat. Creatures that can see beyond this illusion will be able to attack the target.
If target so wishes it might %^ORANGE%^<appear>%^RESET%^.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "eyelash" : 1, "gum arabic" : 1, ]),
    ]));
	set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^"+caster->query_cap_name()+" chants rhythmically, "+caster->query_posessive()+" voice getting slowly lower and harder to hear.";
}

spell_effect(int prof)
{
    object me;

    if (!objectp(caster) || !objectp(place))
    {
        ::dest_effect();
        return;
    }

    if (!objectp(me = this_object()))
    {
        ::dest_effect();
        return;
    }

    if (!objectp(target))
        target = caster;

    if (!silent_casting)
    {
        if ((string)me->query_spell_type() == "potion")
            tell_object(caster, "%^CYAN%^As the potion warms your stomach, you look down and realise your body is fading!%^RESET%^");
        else
        {
            if (interactive(caster))
            {
                if (target == caster)
                {
                    tell_object(caster, "%^CYAN%^You continue to chant as your body starts to fade from sight.");
                    tell_room(place, "%^CYAN%^" + caster->query_cap_name() + " continues to chant as " + caster->query_subjective() + " starts to fade and you are able to see through " + caster->query_objective() + "!", caster);
                }
                else
                {
                    tell_object(caster, "%^CYAN%^You face " + target->query_cap_name() + ", the palms of your hands held towards " + target->query_objective() + ", and continue to chant the spell.");
                    tell_object(target, "%^CYAN%^" + caster->query_cap_name() + " faces you, the palms of " + caster->query_posessive() + " hands held towards you, as " + caster->query_subjective() + " continues to chant.");
                    tell_room(place, "%^CYAN%^" + caster->query_cap_name() + " faces " + target->query_cap_name() + ", the palms of " + caster->query_posessive() + " hands held towards " + target->query_objective() + ", as " + caster->query_subjective() + " continues to chant.", ({ caster, target }));
                }
            }
            else
                tell_room(place, "%^CYAN%^A whispering sound emits from " + caster->query_cap_name() + " as the area glows with a black aura.");
        }
    }
    call_out("targ_vanish", 2, prof);
}

void targ_vanish(int prof)
{
    object me = this_object();

    if (!objectp(me) || !objectp(caster) || !objectp(target) || !objectp(place))
        return;

    if (!objectp(target))
    {
        tell_object(caster, "You look around, confused as to where your target went, and shrug.");
        tell_room(place, caster->query_cap_name()+" looks around, and shrugs in confusion.", caster);
        me->remove();
        return;
    }

    if (!present(target, place))
    {
        tell_object(caster, "You look around, confused as to where your target went, and shrug.");
        tell_room(place, caster->query_cap_name()+" looks around, and shrugs in confusion.", caster);
        me->remove();
        return;
    }

    if (target->query_invis())
    {
        tell_object(caster, target->query_cap_name()+" is already invisible.");
        me->remove();
        return;
    }

    if(target->query_property("visible"))
    {
        tell_object(caster, "The spell fails utterly on "+target->query_cap_name()+".");
        me->remove();
        return;
    }

    spell_successful();
//    call_out("dest_effect",clevel*ROUND_LENGTH*10*prof/100);
    invisob = new("/d/magic/obj/invisob.c");
    invisob->set_property("spell", me);
    invisob->set_property("spelled", ({me}) );

    if((string)me->query_spell_type() == "potion")
        invisob->set_property("potion", 1); // to vary the messages!

    invisob->move_is_ok(1);
    invisob->move(target);
    invisob->set_prof(prof);
    invisob->move_is_ok(0);
//   if (caster != target) {
    addSpellToCaster();
//    }
    return;
}

void dest_effect()
{
    object me = this_object();

    if (objectp(invisob))
        invisob->show_up();

    if(objectp(target))   // added this check for objectp on target 11/3/02 *Styx*
        target->remove_property("visible");

    ::dest_effect();

    if(objectp(me))
        me->remove();
}


void reverse_spell()
{
    target->set_property("visible", 1);
    call_out_walltime("dest_effect", clevel * 8);
}
