#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{

    ::create();
    set_spell_name("antimagic field");
    set_spell_level(([ "cleric" : 8, "mage" : 8 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS antimagic field");
    set_damage_desc("causes spells to fizzle in room");
    set_description("The caster creates an antimagic zone in the area, causing any spells cast in that area to have a high chance of failing. This also affects the caster's spells.");

}

int preSpell()
{

    if (place->query_property("antimagic field")) {
        tell_object(caster, "You feel your attempt to cast the spell repelled.");
        return 0;
    }

    if (objectp(caster->query_property("antimagic field"))) {
        tell_object(caster, "You are already enforcing an antimagic field.");
        return 0;
    }

    return 1;

}

void spell_effect()
{

    tell_room(place, "%^RESET%^%^CYAN%^You feel an emptiness on your soul, as if something is missing from the world.%^RESET%^");

    if (place->query_property("antimagic field") < (clevel - 1)) {
        place->remove_property("antimagic field");
    }

    place->set_property("antimagic field", clevel - 1);

    spell_successful();
    caster->set_property("spelled", ({ TO }));
    caster->set_property("antimagic field", place);
    addSpellToCaster();

    spell_duration = (clevel / 5 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);

    call_out("notify_effect", ROUND_LENGTH * 2);
}

void dest_effect()
{

    if (objectp(place)) {
        tell_room(place, "%^BOLD%^%^CYAN%^The magic returns to the area.");
        place->remove_property("antimagic field");
    }

    if (objectp(caster)) {
        caster->remove_property("antimagic field");
    }

    ::dest_effect();
    return;
}
