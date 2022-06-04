#include <std.h>
#include <spell.h>

inherit SPELL;

create()
{
    ::create();
    set_spell_name("dictum");
    set_spell_level(([ "cleric" : 7, "inquisitor" : 6, ]));
    set_spell_sphere("invocation_evocation");
    set_domains("law");
    set_syntax("cast CLASS dictum on TARGET");
    set_damage_desc("Staggered, paralyzed and/or death, depending on level difference.");
    set_description("You proclaim a word of power, and stagger, paralyze or kill your target. Any target that is 10 levels or more less than the caster must make a combat death save or die immediately. If the target is 5 levels or more lower than the caster, they must also make a will save or are stunned for 1d4 rounds (or 1 round if save succeeds). All targets must make a will save or are staggered for 2d4 rounds (1d4 rounds on successful save). All effects listed are concurrent and cumulative.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^You can feel an orderly presence building inside.");
    tell_room(place, "%^BOLD%^" + caster->QCN + " chants in an orderly fashion.", caster);
    return "display";
}

int preSpell()
{
    string align;
    
    align = target->query_true_align();
    
    if(align == 1 || align == 2 || align == 3)
    {
        tell_object(caster, "Dictum only affects non-lawful targets!");
        return 0;
    }
    
    return 1;
}

void spell_effect()
{
    int ldiff;

    ldiff = (clevel - target->query_level());

    caster->force_me("yell %^WHITE%^%^BOLD%^DIE!");

    {
        tell_room(place, "%^BOLD%^" + target->QCN + " is blasted to the groud with the power of the voice.", target);
        tell_object(target, "%^BOLD%^%^You are blasted to the ground with the power of the voice.");
        //target->set_tripped(roll_dice(1, 4), "%^BOLD%^You are trying to regain your footing.");
        if (!do_save(target, 0))
            find_object("/std/effect/status/staggered")->apply_effect(target, roll_dice(2, 4));
        else
            find_object("/std/effect/status/staggered")->apply_effect(target, roll_dice(1, 4));            
    }
        

    if (ldiff > 4) {
        int duration;
        tell_room(place, "%^BOLD%^" + target->QCN + " stops for a moment with a thoughtful expression.", target);
        tell_object(target, "%^BOLD%^%^You are stunned by the command.");
        duration = roll_dice(1, 4) * 6;
        if (do_save(target, 0)) {
            duration = 6;
        }
        target->set_paralyzed(duration, "You are stunned by the command you just heard.");
    }

    if (ldiff > 9) {
        if (!combat_death_save(target, 0)) {
            tell_room(place, "%^BOLD%^Upon hearing the words, " + target->QCN + " simply dies!", target);
            tell_object(target, "%^BOLD%^YOU OBEY AND DIE.");
            //damage_targ(target, target->return_target_limb(), target->query_max_hp() * 2, "mental");
            target->cause_typed_damage(target, "torso", target->query_max_hp() * 2, "untyped");
        }   
    }

    dest_effect();
    return;
}
