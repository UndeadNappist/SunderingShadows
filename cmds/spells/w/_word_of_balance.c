#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("word of balance");
    set_spell_level(([ "cleric" : 6, "inquisitor" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_domains("balance");
    set_syntax("cast CLASS word of balance on TARGET");
    set_damage_desc("Death, paralyzed and/or confused depending on level difference");
    set_description("You shout some gibberish. All non-neutral targets in the immediate area must make an immediate save or suffer from confusion for 2d4 rounds (1 round if save succeeds). Targets 5 levels below the caster will also be stunned for 1d4 rounds (1 round on successful save). Finally, any targets 10 levels below the caster must also make a combat death save or immediately die.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
    splash_spell(2);
}

int preSpell()
{
    string align;
    
    align = target->query_true_align();
    
    if(align != 1 && align != 3 && align != 6 && align != 9)
    {
        tell_object(caster, "Word of Balance only affects non-neutral targets!");
        return 0;
    }
    
    return 1;
}

void spell_effect()
{
    int ldiff;
    object *targs;
    
    targs = target_selector();
    targs += ({target});
    targs = distinct_array(targs);
    targs = filter_array(targs, (: ($1->query_true_align() != 1 && $1->query_true_align() != 3 && $1->query_true_align() != 6 && $1->query_true_align() != 9) :));
    
    tell_object(caster, "%^C243%^You utter the %^C075%^words%^C243%^ of %^C075%^balance%^C243%^, shunning all %^C196%^extremism%^C243%^!%^CRST%^");
    tell_room(place, "%^C243%^" + caster->query_cap_name() + " utters the words of balance, shunning all extremism!%^CRST%^", caster);
    
    foreach(object ob in targs)
    {

        ldiff = (clevel - ob->query_level());
        
        if (ldiff > 9 && !combat_death_save(ob, 0))
        {
            tell_room(place,"%^C075%^Upon hearing the words "+ob->query_cap_name()+" is utterly undone!%^CRST%^",ob);
            tell_object(ob,"%^C075%^You are completely undone by the words!%^CRST%^");
            damage_targ(ob,ob->return_target_limb(),ob->query_max_hp()*2,"mental");
        }

        if (ldiff > 4 && !PLAYER_D->immunity_check(ob, "paralysis"))
        {
            int duration;
            tell_room(place, "%^BOLD%^" + ob->QCN + " stops for a moment with a thoughtful expression.", ob);
            tell_object(ob, "%^BOLD%^%^You are stunned by the command.");
            duration = roll_dice(1, 4) * 6;
            if (do_save(ob, 0))
            {
                duration = 6;
            }
            ob->set_paralyzed(duration, "You are stunned by the command you just heard.");
            dest_effect();
            return;
        }

        if(!PLAYER_D->immunity_check(ob, "confusion"))
        {
            if (!do_save(ob, 0))
                "/std/effect/status/confused"->apply_effect(ob, roll_dice(2, 4));
            else
                "/std/effect/status/confused"->apply_effect(ob, 1);
        }
    }

    dest_effect();
    return;
}
