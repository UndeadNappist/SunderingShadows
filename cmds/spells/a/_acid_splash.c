#include <spell.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("acid splash");
    set_spell_level(([ "cantrip" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS acid splash on TARGET");
    set_damage_desc("acid damage on ranged touch attack.");
    set_description("This spell opens a tiny portal into the paraelemental plane of ooze above your target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "acid"}) );
}

void spell_effect(int prof) {

    if(!target || !objectp(target))
        target = caster->query_current_attacker();
    
    if(!objectp(target))
    {
        tell_object(caster, "Your target is not here.");
        dest_effect();
        return;
    }
    
    spell_successful();
    
    if(!BONUS_D->process_hit(caster, target, 1, 0, 0, 1))
    {
        tell_object(caster, "You fire a dart of acid at " + target->QCN + " but miss!");
        return;
    }
    
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^GREEN%^You open a portal above "+target->QCN+" and some acid splashes through it!");
        tell_room(place,"%^BOLD%^%^GREEN%^A portal opens above "+target->QCN+" and some acid pours through it!", ({caster}) );
    }
    damage_targ(target, target->return_target_limb(), sdamage,"acid");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
