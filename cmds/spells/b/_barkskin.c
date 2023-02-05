#include <priest.h>
#include <daemons.h>
inherit SPELL;

int amount;

void create()
{
    ::create();
    set_spell_name("barkskin");
    set_spell_level(([ "ranger" : 2,"druid" : 2, "oracle":2]));
    set_mystery("nature");
    set_bonus_type("natural armor");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS barkskin");
    set_damage_desc("2 + clevel / 20 to AC");
    set_description("Barkskin hardens the caster's skin, making it hard as the bark of a mighty oak.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() { return "%^RED%^"+caster->QCN+" runs "+caster->QP+" hands over "+caster->QP+" arms."; }


void spell_effect(int prof)
{
    if (!objectp(caster))
    {
        dest_effect();
        return;
    }
    if (interactive(caster))
    {
        tell_object(caster, "%^ORANGE%^Your skin thickens and becomes rough, with a brittle texture like treebark!");
        tell_room(place,"%^ORANGE%^"+caster->QCN+"'s skin changes, becoming as rough and brittle as treebark!",caster);
    }

    amount = 2 + (clevel / 20);
    caster->add_ac_bonus(amount);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^CYAN%^Your skin loses its brittle texture.%^RESET%^");
        caster->add_ac_bonus(-amount);
        //if(feattracker == 1) caster->remove_temporary_feat("damage resistance");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
