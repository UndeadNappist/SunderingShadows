//Supposed to be AOE phantasmal killer. Noted for future changes.
#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create()
{
    ::create();
    set_spell_name("weird");
    set_spell_level(([ "mage" : 9, "cleric" : 9 ]));
    set_domains(({ "madness", "nightmare" }));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS weird");
    set_damage_desc("mental damage, phantasmal killer, and cowering on failed save");
    set_description("With this spell, the caster extends fears and horrors from their own mind into the material plane, causing pain and suffering to everything in sight. The phantasmal killer spell is cast on all enemies and their minds assaulted with visions of horror. Only a strong will can withstand this power, and even then will only avoid some of the suffering.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("will");
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->QCN + " speaks words of arcane horror.";
}

int preSpell()
{
    object nspell, *enemies;
    
    enemies = target_selector();
    
    if(!sizeof(enemies))
    {
        tell_object(caster, "You aren't fighting anyone.");
        return 0;
    }
    
    foreach(object ob in enemies)
    {
        nspell = new("/cmds/spells/p/_phantasmal_killer");
        nspell->set_silent_casting(1);
        nspell->set_spell_source(spell_type);
        nspell->use_spell(caster, ob, clevel, 100, "mage");
    }
    
    return 1;
}

void spell_effect(int prof)
{
    object* attackers;
    int i, admg;
    attackers = target_selector();

    tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " raises " + caster->QP + " hands and releases waves of horrific images!%^RESET%^");
    if (!sizeof(attackers)) {
        tell_object(caster, "%^BOLD%^%^BLUE%^The place is filled with images of horrors, but nothing happens.%^RESET%^");
        dest_effect();
        return;
    }

    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        admg = sdamage;
        if (do_save(attackers[i])) {
            admg = admg / 2;
        }else {
            "/std/effect/status/cowering"->apply_effect(attackers[i], clevel / 18 + 1);
        }
        tell_object(attackers[i], "%^CYAN%^%^BOLD%^Your mind is filled with images of suffering!%^RESET%^");
        damage_targ(attackers[i], attackers[i]->return_target_limb(), admg, "mental");
    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
