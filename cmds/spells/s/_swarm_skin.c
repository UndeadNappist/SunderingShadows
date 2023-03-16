/*
  _swarm_skin.c

  Innate spell for Druids with pestilence circle.

  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int flag;
string ashort;

void create()
{
    ::create();

    set_spell_name("swarm skin");
    set_spell_level( ([ "druid" : 9 ]) );
    set_circle("pestilence");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS swarm skin");
    set_damage_desc("Piercing damage and disease to attackers");
    set_description("You speak the language of swarm, calling to you a swarm of vicious, disgusting flies. They cover your skin in a protective layer, biting all who would attack you. Those bitten must make a fortitude save or be infected with filth fever.");
    set_save("fort");
    traveling_aoe_spell(1);
    set_immunities( ({ "piercing" }) );
}

string query_cast_string()
{
    return "%^C072%^" + caster->query_cap_name() + "%^C060%^ emits a low, buzzing chant.%^CRST%^";
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_object(caster,"%^C060%^Your skin is suddenly covered in a %^C072%^swarm%^C060%^ of %^C072%^buzzing flies%^C060%^!%^CRST%^");
    tell_room(place,"%^C072%^" + caster->query_cap_name() + "'s%^C060%^ skin is suddenly covered in a %^C072%^swarm%^C060%^ of buzzing flies!%^CRST%^",caster);
    
    ashort = "%^C060%^(%^C072%^ %^C078%^s%^C072%^w%^C066%^a%^C060%^r%^C066%^m%^C072%^i%^C078%^ng s%^C072%^k%^C066%^i%^C078%^n%^C072%^ %^C060%^)%^CRST%^";

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({ ashort }));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("room_check",ROUND_LENGTH);
}

void execute_attack()
{
    object *attackers;
    object disease, dfile;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    place = environment(caster);
    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }

    attackers = filter_array(caster->query_attackers(),(:objectp($1):));
    attackers = filter_array(attackers,(:$1->is_living():));
    dfile = load_object("/std/diseases/diseases/filth_fever");

    if(sizeof(attackers))
    {
        define_base_damage(0);
        tell_room(place,"", caster);
        tell_object(caster,"%^C072%^The filthy flies swarm and bite your foes!%^CRST%^");
        foreach(object ob in attackers)
        {
            tell_object(ob,"%^C072%^The filthy flies swarm and bite you!%^CRST%^");
            ob->cause_typed_damage(ob, ob->return_target_limb(), sdamage, "piercing");
            
            if(!objectp(ob))
                continue;
            
            if(objectp(dfile) && !do_save(ob, 0))
            {
                disease = dfile->infect(ob, clevel);
                objectp(disease) && disease->advance_disease();
            }
        }
    }
    prepend_to_combat_cycle(place);
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^C066%^The swarm of %^C078%^flies%^C066%^ drops %^C078%^twitching %^C066%^to the floor.%^CRST%^");
        caster->remove_property("nimbus");
        caster->remove_property_value("added short",({ ashort }));
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
