#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("soul flaying");
    set_spell_level(([ "warlock" : 3 ]));
    set_heritage("infernal");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS soul flaying on TARGET");
    set_description("You intrusively reach into your opponent's soul, poring through it's worthless history and experiences, using their worst fears against them. As you shred their soul, they are met with unbearable terror and despair, and experience unimaginable agony. The target takes negative energy damage and must make a will save or suffer penalties to their attack, damage, caster level and saving throws for a short time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    mental_spell(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^C166%^" + caster->query_cap_name() + "%^C244%^ utters a dark and forbidding invocation.%^CRST%^";
}

void spell_effect(int prof)
{
    string my_name, your_name;
    int duration;
    
    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();
    
    if(target == caster)
    {
        tell_object(caster, "%^CYAN%^You cannot target yourself.%^RESET%^");
        tell_room(place,"%^CYAN%^The aura around "+caster->QCN+"'s hands weakens and then fades away.%^RESET%^",caster);
        TO->remove();
        return;
    }
    if(target->query_property("soul flaying"))
    {
        tell_object(caster,"%^CYAN%^You cannot flay their soul any further!%^RESET%^");
        TO->remove();
        return;
    }
    if (do_save(target, 0) || mind_immunity_damage(target))
    {
        tell_object(target, "With incredible agony, you manage to fight off the flaying of your soul!");
        tell_room(place, "Seems to resist the flaying of " + target->query_possessive() + " soul!", target);
        TO->remove();
        return;
    }
    bonus = clevel/8;
    duration = (ROUND_LENGTH) * (clevel / 12 + 1);

    tell_object(target,"");
    tell_room(place,"",target);
    target->add_damage_bonus((-1) * bonus);
    target->add_attack_bonus((-1) * bonus);
    target->set_property("empowered", (-1) * bonus);

    caster->add_saving_bonus("all", (-1) * bonus);
    target->set_property("soul flaying", 1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"");
        tell_room(environment(target),"",target);
        target->add_damage_bonus(bonus);
        target->add_attack_bonus(bonus);
        target->set_property("empowered",bonus);
        caster->add_saving_bonus("all",bonus);
        target->remove_property("soul flaying");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
