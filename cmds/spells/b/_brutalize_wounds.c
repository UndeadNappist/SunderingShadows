/*
  _brutalize_wounds.c

  From PF SRD. Makes target vulnerable to physical attacks.

  -- Tlaloc --
*/

#include <std.h>
#include <magic.h>

inherit SPELL;

int amount;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("brutalize wounds");
    set_spell_level( ([ "psywarrior" : 6 ]) );
    set_spell_sphere("telepathy");
    mental_spell();
    set_syntax("cast CLASS brutalize wounds on TARGET");
    set_damage_desc("Target takes additional physical damage.");
    set_description("You invade the target's mind and temporarily reduces its ability to handle physical wounds. If the target fails a will save, their damage resistance is reduced by 5 + clevel / 10. Otherwise, their damage resistance is reduced by 1.");
    set_save("will");
    //set_arg_needed(1);
    set_target_required(1);
}

void spell_effect()
{
    string ename, pname, eposs;

    if(!place || !caster || !target)
        return;

    if(!target || !present(target, place))
    {
        tell_object(caster, "Your target is no longer here.");
        return;
    }

    if(target->query_property("brutalized"))
    {
        tell_object(caster, "That target is already affected by brutalize wounds.");
        return;
    }

    pname = caster->query_cap_name();
    ename = target->query_cap_name();
    eposs = target->query_possessive();

    tell_object(caster, "%^CYAN%^BOLD%^" + sprintf("You invade %s's mind, carefully dismantling %s defenses.", ename, eposs) + "%^RESET%^");
    tell_object(target, "%^BOLD%^" + pname + " invades your mind, carefully dismantling your defenses.%^RESET%^");
    tell_room(place, "%^BOLD%^CYAN%^" + sprintf("%s invades %s's mind, carefully dismantling %s defenses.", pname, ename, eposs) + "%^RESET%^", ({ target, caster }));

    if(do_save(target, 0))
    {
        tell_object(target, "%^BOLD%^You manage to shrug off some of the effects of the brutality.%^RESET%^");
        tell_object(caster, "%^BOLD%^" + ename + " manages to shrug off some of the effects of the brutality.%^RESET%^");
        amount = 1;
    }
    else
    {
        tell_object(target, "%^RED%^BOLD%^You scream as you feel the pain of every wound amplified!%^RESET%^");
        tell_object(caster, "%^RED%^BOLD%^" + ename + " screams in pain as they feel amplified pain!%^RESET%^");
        amount = 5 + (clevel / 10);
        //target->set_property("brutalized", 2 + caster->query_guild_level("psywarrior") / 20);
    }

    target->set_property("brutalized", 1);
    target->set_property("damage resistance", -amount);

    spell_successful();
    spell_duration = (clevel / 10 + 1) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->remove_property("brutalized");
        target->set_property("damage resistance", amount);
        tell_object(target, "You feel the psychic enhancement of your wounds fade.");
    }
    
    objectp(caster) && tell_object(caster, "Your target's wounds are no longer brutalized.");
        
    ::dest_effect();
    if(this_object())
        this_object()->remove();
}
