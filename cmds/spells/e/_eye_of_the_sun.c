#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("eye of the sun");
    set_spell_level(([ "innate" : 9 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS eye of the sun on TARGET");
    set_damage_desc("radiant damage on ranged touch attack");
    set_description("You call on the pure radiance of the sun itself, drawing its eye to your target. A beam of pure radiant energy blasts the target. On a successful ranged touch attack, the target takes radiant damage. The target must then make a reflex save to turn away from the light, or takes a small amount of fire damage and is rendered blind for a short time as their eyes are burned with solar fire.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string()
{
    tell_object(caster, "%^C032%^You raise your hands to the sky, calling on the %^C193%^power%^C032%^ of the %^C193%^sun%^C032%^!%^CRST%^");
    return "%^C032%^" + caster->query_cap_name() + " raises " + caster->query_possessive() + " hands to the sky, calling on the %^C193%^power%^C032%^ of the %^C193%^sun%^C032%^!%^CRST%^";
}

void spell_effect(int prof)
{
    int num;
    string my_name, your_name;
    string target_limb;

    spell_successful();

    if (environment(caster) != environment(target))
    {
        tell_object(caster,"Your target is not here.");
        dest_effect();
        return;
    }
    
    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();

    target_limb = target->return_target_limb();

    tell_room(place,"%^C220%^The sun ascends the sky and dilates, casting its brilliant eye upon " + your_name + "!%^CRST%^", ({ target }));
    tell_object(target,"%^C220%^The sun ascends the sky and dilates, casting its brilliant eye upon you!%^CRST%^");

    if(BONUS_D->process_hit(caster, target, 1, 0, 0, 1) > 0)
    {
        tell_room(place,"%^C191%^" + your_name + " is struck by a broad beam of radiant energy from the sky!%^CRST%^", ({ target }));
        tell_object(target,"%^C191%^You are struck by a broad beam of radiant energy from the sky!%^CRST%^");
        target->cause_typed_damage(target, target_limb, sdamage, "radiant");
        
        if(target && objectp(target) && !do_save(target))
        {
            target->set_temporary_blinded(1);
            target->cause_typed_damage(target, target_limb, sdamage / 10, "fire");
        }
    }
    else
    {
        tell_room(place,"%^BOLD%^" + your_name + " manages to avoid the beam of radiant energy!%^RESET%^", ({ target }));
        tell_object(target,"%^BOLD%^You manage to avoid the beam of radiant energy!%^RESET%^");
    }
    
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}
