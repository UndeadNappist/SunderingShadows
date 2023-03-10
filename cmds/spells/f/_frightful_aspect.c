#include <std.h>
#include <priest.h>
#include <party.h>
#include <daemons.h>

inherit SPELL;

int flag, mrbonus, mrflag, counter;
object *saved = ({  });

void emote_em();

void create()
{
    ::create();
    set_spell_name("frightful aspect");
    set_spell_level(([ "cleric" : 8, "druid" : 8, "mage" : 8]));
    set_syntax("cast CLASS frightful aspect");
    set_spell_sphere("alteration");
    set_bonus_type(({ "size", "body", "natural armor" }));
    set_description("You become a larger, awful version of yourself. You grow in size, and take on features that horrify your enemies. You gain the following abilities: a +6 size bonus to Strength, a +4 size bonus to Constitution, a +6 natural armor bonus, +5 damage resistance and spell damage resistance equal to 10 + half your caster level. You also emit an aura that emanates 30 feet from you. Enemy creatures within the aura must make a will save or are shaken.\n\n%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
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

int preSpell()
{

    if (caster->query_property("oppression")) {
        tell_object(caster, "You are already under the effects of this kind of power!");
        return 0;
    }

    /*
    if (caster->query_property("iron body")) {
        tell_object(caster, "You already have protection of this nature!");
        return 0;
    }
    */
    mrbonus = 10 + clevel / 2;
    mrflag = 0;
    return 1;
}

void spell_effect(int prof)
{
    tell_object(caster, "%^RED%^You grow twice in size and feel more powerful, ready to crush your enemies!");
    tell_room(environment(caster), "%^RED%^" + caster->QCN + " grows twice in size!", caster);
    caster->set_property("spelled", ({ this_object() }));
    caster->set_property("damage resistance", 5);
    caster->add_stat_bonus("strength", 6);
    caster->add_stat_bonus("constitution", 4);
    caster->set_property("added short", ({ "%^RED%^ (giant)%^RESET%^" }));
    caster->set_size_bonus(1);
    caster->add_ac_bonus(6);
    caster->set_property("spell damage resistance", mrbonus);
    caster->set_property("oppression", 1);
    spell_successful();
    addSpellToCaster();
    environment(caster)->addObjectToCombatCycle(TO, 1);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect", spell_duration);
    call_out("room_check", ROUND_LENGTH * 2);
}

void execute_attack()
{
    object* inven, room, ppl, *foes;
    if (!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    room = environment(caster);
/*
    inven = target_selector(); //doesn't look like this function can take an argument

    if (sizeof(inven)) {
        foreach(ppl in inven)
        {
            if (!ppl->query_property("effect_shaken")) {
                if (!mind_immunity_check(ppl) && !PLAYER_D->immunity_check(ppl, "fear")) {
                    "/std/effect/status/shaken"->apply_effect(ppl, clevel / 6 + 1);
                    tell_object(ppl, "%^RED%^You shake in fear in sight of " + caster->QCN);
                    tell_room(room, "%^RED%^" + ppl->QCN + " shakes in fear in sight of " + caster->QCN, ({ ppl }));
                }
            }
        }
    }
*/
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
                tell_object(ob, "%^C081%^You cower in %^C069%^fear%^C081%^ from %^C069%^" + caster->query_cap_name() + "'s%^C081%^ oppressive aura!%^CRST%^");
                tell_room(place, "%^C081%^" + ob->query_cap_name() + " cowers in %^C069%^fear%^C081%^ from %^C069%^" + caster->query_cap_name() + "'s%^C081%^ oppressive aura!%^CRST%^", ob);
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

    environment(caster)->addObjectToCombatCycle(TO, 1);
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        caster->set_size_bonus(0);
        caster->remove_property_value("added short", ({ "%^RED%^ (giant)%^RESET%^" }));
        caster->remove_property("iron body");
        caster->add_stat_bonus("strength", -6);
        caster->add_stat_bonus("constitution", -4);
        caster->set_property("damage resistance", -5);
        caster->add_ac_bonus(-6);
        //caster->add_saving_bonus("all", -2);
        caster->remove_property("oppression");
        //if (mrflag) {
        //    caster->set_property("magic resistance", -mrbonus);
        caster->set_property("spell damage resistance", -mrbonus);
        //    caster->set_property("raised resistance", 0);
        //    mrflag = 0;
        //}
        tell_object(target, "%^RED%^You shrink back to normal!");
        tell_room(environment(caster), "%^RED%^" + caster->QCN + " shrinks back to normal size.", target);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
