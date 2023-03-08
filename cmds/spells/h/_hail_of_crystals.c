#include <std.h>
#include <daemons.h>
inherit SPELL;

int time,flag;

void create()
{
    ::create();
    set_spell_name("hail of crystals");
    set_spell_level(([ "psion" : 6 ]));
    set_discipline("shaper");
    set_spell_sphere("metacreatvity");
    set_syntax("cast CLASS hail of crystals");
    set_description("This power will cause the shaper to fill the air with razor-sharp crystals, which churn and damage "
        "most things in the area.  Due to the shaper's natural control over crytals, this power will not damage the shaper, his "
        "party members, or any beings following him.  The power becomes longer lasting as the shaper grows stronger.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(shredded by shards of %^MAGENTA%^c%^RED%^r%^YELLOW%^y%^GREEN%^s%^CYAN%^t%^BLUE%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^)%^RESET%^");
}

void spell_effect(int prof)
{
    tell_object(caster,"%^BOLD%^%^WHITE%^With a flick of your wrist, "+
        "you send three crystals hurling through the air!");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" sends three "+
        "crystals into the air with a flick of "+caster->QP+" wrist!",({caster}));
    time = 0;

    addSpellToCaster();
    spell_successful();
    execute_attack();
}


void execute_attack()
{
    object *foes, *rooms_nearby, me;
    string target_limb;
    int i, damage;

    if (!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (objectp(me = this_object()))
        return;

    if (!objectp(place))
        return;

    if (!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    foes = target_selector();
    foes -= ({caster});
    if (caster->query_followers())
        foes -= caster->query_followers();

    if(time > clevel * 3)
    {
        dest_effect();
        return;
    }

    if (arrayp(rooms_nearby = nearbyRoom(place, 2)))
        message("info", "%^BOLD%^%^BLACK%^Shards of %^MAGENTA%^c%^RED%^r%^YELLOW%^y%^GREEN%^s%^CYAN%^t%^BLUE%^a%^RESET%^%^MAGENTA%^l %^BOLD%^%^BLACK%^slice through the sky, shearing everything within the storm!", rooms_nearby);

    define_base_damage(0); //lazy re-roll
    damage = sdamage;

    for (i=0; sizeof(foes), i < sizeof(foes); ++i)
    {
        if (!objectp(foes[i]))
            continue;

        if (!objectp(caster))
        {
            dest_effect();
            return;
        }

        if (!present(caster, place) && caster != target)
        {
            dest_effect();
            return;
        }

        if (!present(foes[i], place))
            continue;

        target_limb = foes[i]->return_target_limb();

        if (do_save(foes[i], 0))
            damage_targ(foes[i], target_limb, damage/2,"slashing");
        else
            damage_targ(foes[i], target_limb, damage,"slashing");

        if (objectp(foes[i]))
            spell_kill(foes[i], caster);
    }

    ++time;

    if (present(caster, place))
        environment(caster)->addObjectToCombatCycle(me, 1);
    else
    {
        dest_effect();
        return;
    }
}


void dest_effect()
{
    object me;

    if (objectp(place))
        tell_room(place, "%^BOLD%^%^WHITE%^The crystals churning in the air grind to dust and are blown away by the wind.");

    ::dest_effect();

    if(objectp(me = this_object()))
        me->remove();
}


string query_cast_string()
{
    return ""+caster->QCN+" withdraws three tourmaline gems from a pouch.";
}
