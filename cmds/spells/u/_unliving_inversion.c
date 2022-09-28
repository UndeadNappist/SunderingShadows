#include <magic.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("unliving inversion");
    set_spell_level(([ "mage" : 4, "cleric" : 4]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS unliving inversion");
    set_description("With this spell living being can obtain properties of unliving creature, swapping currents of negative and positive energy within themselves.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell()
{
    if (caster->query_property("negative energy affinity")) {
        tell_object(caster, "%^BOLD%^You already have have affinity to negative energy.%^CRST%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^BLUE%^Waveringly " + caster->QCN + " spells out few undertones.%^RESET%^";
}

void spell_effect()
{
    tell_object(caster, "%^RESET%^%^C075%^Currents of %^RESET%^%^C250%^d%^C251%^e%^C252%^a%^C251%^t%^C250%^h %^RESET%^%^C075%^and %^RESET%^%^C051%^l%^C050%^i%^C086%^f%^C051%^e %^RESET%^%^C075%^invert within you.%^CRST%^");
    tell_room(place, "%^RESET%^%^C075%^" + caster->QCN + "%^RESET%^%^C075%^'s skin briefly turns %^RESET%^%^C015%^w%^C255%^h%^C231%^i%^C255%^t%^C015%^e%^RESET%^%^C075%^.%^CRST%^", caster);
    caster->set_property("negative energy affinity", 1);
    addSpellToCaster();
    spell_successful();
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property("negative energy affinity", 1);
        tell_object(caster, "%^BLUE%^Currents of death and life change back to normal.");
    }
    ::dest_effect();
}
