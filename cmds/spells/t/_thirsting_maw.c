#include <spell.h>
#include <magic.h>
inherit SPELL;

int num;

void create()
{
    ::create();
    set_spell_name("thirsting maw");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS thirsting maw on TARGET");
    set_heritage("abyssal");
    set_damage_desc("piercing damage over time plus healing to caster");
    set_description("With a flick of the wrist, you create a phantasmal, eel-like creature from your palm and hurl it at your foe. It latches itself to this unfortunate wretch and and begins to drink his blood, granting you newfound vitality. A fortitude save will reduce the duration by half.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    return "%^C059%^You utter a %^C065%^foul invocation%^C059%^, calling upon your %^C072%^abyssal%^C059%^ patron.%^CRST%^";
}

spell_effect(int prof)
{
    int heal_amount;
    
    spell_successful();

    tell_room(place,"Placeholder",target);
    tell_object(target,"Placeholder",target);
    heal_amount = target->cause_typed_damage(target, target->return_target_limb(), sdamage, "piercing");
    caster->add_hp(heal_amount);
    num = clevel / 8 + 1;
    if(do_save(target,0))
        num/=2;
    call_out("bite_again",ROUND_LENGTH);
}

void bite_again()
{
    int heal_amount;
    
    if(!objectp(target))
    {
        dest_effect();
        return;
    }

    if(target->query_hp()<0)
    {
        dest_effect();
        return;
    }

    define_base_damage(0);
    tell_room(ENV(target),"Periodic placeholder",target);
    tell_object(target,"Periodic placeholder");
    heal_amount = target->cause_typed_damage(target, target->return_target_limb(), sdamage / 6, "piercing");
    target->add_hp(heal_amount);

    if(num-- < 0)
    {
        dest_effect();
        return;
    }
    else
    {
        call_out("bite_again",ROUND_LENGTH);
    }
}

dest_effect()
{
    if(find_call_out("bite_again") != -1)
        remove_call_out("bite_again");

    if(objectp(target))
    {
        tell_room(environment(target),"End placeholder",target);
        tell_object(target,"End placeholder");
    }

    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
