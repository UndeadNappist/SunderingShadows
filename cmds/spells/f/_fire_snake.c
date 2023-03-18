#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
   ::create();
    set_spell_name("fire snake");
    set_spell_level(([ "druid" : 6 ]));
    set_circle("wildfire");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS fire snake");
    set_damage_desc("fire damage on attackers, half on reflex save");
    set_description("With this spell, the caster creates a sinous line of fire, hitting foes in front of them. Those who make a reflex save will take half damage.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_save("reflex");
    set_immunities( ({ "fire" }) );
}


void spell_effect(int prof)
{
    object *foes;

    foes = target_selector();

    tell_room(place,"A sinuous ribbon of fire shoots out from " + caster->query_cap_name() + "'s hands!",caster);
    tell_object(caster,"A sinuous ribbon of fire erupts from your hands.");

    foreach(object ob in foes)
    {
        if(!objectp(ob))
            continue;

        tell_object(caster,"%^C208%^The flames of your fire snake burn %^C220%^" + ob->query_cap_name() + "%^C208%^!%^CRST%^");
        tell_object(ob, "%^C208%^The flames of the fire snake burn you!%^CRST%^");
        tell_room(place,"%^C202%^The blazing energy from %^C220%^" + caster->query_cap_name() + "'s%^C202%^ fire snake burns brightly as it engulfs %^C220%^" + ob->query_cap_name() + "%^C202%^.%^CRST%^",({ ob, caster }));
        if(!do_save(ob,0))
            damage_targ(ob, "torso", sdamage / 2, "fire");
        else
            damage_targ(ob, "torso", sdamage, "fire");
    }
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}
