// Based on Cone of Cold - Cythera 6/05
//Acid Breath
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("cythera");
    set_spell_name("acid breath"); // acid spit
    set_spell_level(([ "mage" : 3, "druid":3, "monk":15]));
    set_monk_way("way of the elements");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS acid breath");
    set_damage_desc("acid damage in splash");
    set_description("The caster exhales a cone of acid from their mouth, hitting their enemies with droplets of corrosive acid. A successful reflex save will reduce the damage by half.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(1);
    set_target_required(1);
    set_save("reflex");
}


string query_cast_string()
{
    tell_object(caster,"%^GREEN%^As you finish chanting a mystic phrase, you "+
        "drop the prepared snakes tongue into your mouth.");
    tell_room(place,"%^GREEN%^"+caster->QCN+" chants a mystic phrase and drops"+
        " a snakes tongue into "+caster->QP+" mouth.",caster);
    return "display";
}


void spell_effect(int prof)
{
    object *hits = ({}),*inven;
    string YOU, HIM, before, after;
    int i;
    
    if (interactive(caster))
    {
        tell_object(caster, "%^BOLD%^%^GREEN%^You feel the acid building in your mouth.%^RESET%^");
        tell_room(place, "%^BOLD%^%^GREEN%^"+caster->QCN+" stares intently for a moment, as green smoke rolls out of "+caster->QP+" mouth.", caster);
        call_out("zapper",4);
        return;
    }

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    YOU = caster->QCN;

    tell_object(caster, "%^GREEN%^%^BOLD%^You release a cone of acid droplets at your enemies!");
    tell_room(place,"%^GREEN%^%^BOLD%^A cone of acid droplets is spit forth from "+YOU+"'s mouth!",({caster}) );

    hits = target_selector();
    
    if(!sizeof(hits))
    {
        tell_object(caster, "%^GREEN%^The acid in your mouth fades away.");
        tell_room(place, "%^GREEN%^Clouds of green smoke roll out of "+caster->QCN+"'s mouth and vanishes into the air.", caster);
        dest_effect();
        return;
    }
    
    spell_successful();

    for(i=0;sizeof(hits),i<sizeof(hits);i++)
    {
        if(!objectp(hits[i])) { continue; }

        tell_object(caster,"%^GREEN%^The acid droplets fall onto "+ hits[i]->QCN+".");
        tell_object(hits[i],"%^GREEN%^The acid dropslets fall onto you, burning your skin!");
        tell_room(place,"%^GREEN%^The acid droplets fall onto "+hits[i]->QCN+".",({caster,hits[i]}));

        if(do_save(hits[i])) { damage_targ(hits[i],"torso",sdamage / 2,"acid"); }
        else { damage_targ(hits[i],"torso", sdamage, "acid"); }
    }

    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
