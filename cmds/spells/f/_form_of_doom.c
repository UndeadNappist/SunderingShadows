/*
  _form_of_doom.c

  Complete rewrite from old version.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

object *saved = ({  });
int counter, flag, statbonus;
string my_name, my_poss, my_pron, your_name;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("form of doom");
    set_spell_sphere("psychometabolism");
    set_bonus_type( ({ "body", "competence", "natural armor", "enhancement" }) );
    set_spell_level( ([ "psywarrior" : 6 ]) );
    set_syntax("cast CLASS form of doom");
    set_damage_desc("+4 strength, +5 DR, +5 AC, +4 athletics, tentacles and shaken");
    set_description("You wrench from your subconscious a terrifying visage of deadly hunger and become one with it. You are transformed into a nightmarish version of yourself, complete with an ooze-sleek skin coating, lashing tentacles, and a fright-inducing countenance. Your tentacles lash out at enemies, causing void damage to each on an attack roll. Your form is horrifying and all enemies must make a will save or be shaken.");
    set_save("will");
    traveling_spell(1);
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

    tell_object(caster, "%^C066%^You manifest a horrfying visage, deep from your subconscious, transforming into a nightmarish version of yourself.%^CRST%^");
    tell_room(place, "%^C066%^" + my_name + " transforms into a nightmarish entity, covered in ooze and lashing tentacles!%^CRST%^", caster);

    statbonus = min( ({ 4, (30 - caster->query_stats("strength")) }) );
    caster->add_stat_bonus("strength", statbonus);
    caster->add_ac_bonus(5);
    caster->add_skill_bonus("athletics", 5);
    caster->set_property("damage resistance", 5);

    caster->set_property("spelled", ({ this_object() }));

    caster->set_property("added short",({" %^C060%^(%^C066%^h%^C072%^o%^C078%^r%^C072%^r%^C066%^ifying%^C060%^)%^CRST%^"}));
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

    if(sizeof(foes))
    {
        tell_object(caster, "%^C066%^Your %^C078%^tentacles%^C066%^ lash out, casting %^C078%^woe%^C066%^ unto your enemies!%^CRST%^");
        tell_room(place, "%^C066%^The tentacles %^C078%^lash out%^C066%^ with horrifying %^C078%^fury%^C066%^!%^CRST%^", caster);
    }

    foreach(object ob in foes)
    {
        if(!objectp(ob))
            continue;

        if(environment(ob) != place)
            continue;

        if(BONUS_D->process_hit(caster, target, 1, 0, 0, 0))
            damage_targ(ob, "chest", roll_dice(caster->query_prestige_level("psywarrior") / 10, 8) + BONUS_D->query_stat_bonus(caster, "intelligence"), "void");
    }

    foes -= saved;

    if(sizeof(foes))
    {
        foreach(object ob in foes)
        {
            if(!objectp(ob) || ob->query_ghost())
                continue;

            your_name = ob->query_cap_name();

            if(place != environment(ob))
                continue;

            if(!do_save(ob, 0) && !PLAYER_D->immunity_check("fear"))
            {
                tell_object(ob, "%^C066%^You %^C078%^recoil%^C066%^ with %^C078%^fear%^C066%^ from %^C078%^" + my_name + "'s%^C066%^ horrible visage!%^CRST%^");
                tell_room(place, "%^C078%^" + your_name + "%^C066%^ recoils with fear from the horrible visage!%^CRST%^", ob);
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
        tell_room(environment(caster), "", caster);
        tell_object(caster, "");
        caster->remove_property_value("added short",({" %^C060%^(%^C066%^h%^C072%^o%^C078%^r%^C072%^r%^C066%^ifying%^C060%^)%^CRST%^"}));
        caster->remove_property("oppression");

        caster->add_stat_bonus("strength", -statbonus);
        caster->add_ac_bonus(-5);
        caster->add_skill_bonus("athletics", -5);
        caster->set_property("damage resistance", -5);
    }
    ::dest_effect();

    if (objectp(this_object()))
        this_object()->remove();
}
