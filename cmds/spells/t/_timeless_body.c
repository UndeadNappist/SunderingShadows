/*
  _timeless_body.c
  
  Functional rewrite.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

#define RANGE 60

inherit SPELL;

int current_conceal, spell_conceal, flag;

void create()
{
    ::create();
    set_spell_name("timeless body");
    set_spell_level( ([ "psion" : 9 ]) );
    set_spell_sphere("psychoportation");
    set_bonus_type("concealment");
    set_syntax("cast CLASS timeless body");
    set_damage_desc("random missChance and spell resistance each round");
    set_description("You take on a ghostly state, transporting part of your self into the Astral Plane. This power fluctuates, intermittently moving you between the two planes, offering a random Miss Chance and Spell Resistance each round. As this is not an illusion power, it is not fully negated by True Seeing.

%^BOLD%^%^RED%^See also:%^RESET%^ timeless body *feats");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int conceal_effect()
{
    int power;
    
    power = random(RANGE);
    power = max( ({ 25, power }) );
    power = min( ({ 100 - caster->query_missChance(), power }) );
    
    if(power <= 0)
        return 0;
    
    return power;
}

int spell_conceal(int x)
{
    int power, current;
    
    if(!x) return 0;
    
    power = x / 10;
    
    if(!power) return 0;
    
    power = min( ({ power, 10 }) );
    current = caster->query_property("magic resistance");
    power = min( ({ power, 20 - current }) );
    
    if(power <= 0)
        return 0;
    
    return power;
}

void spell_effect()
{
    tell_room(place,"%^C117%^" + caster->query_cap_name() + "'s%^C105%^ body begins to fade, partially entering the astral plane!%^CRST%^", caster);
    tell_object(caster,"%^C105%^Your body begins to fade, partially entering the %^C117%^astral plane%^C105%^!%^CRST%^");
    
    current_conceal = conceal_effect();
    spell_conceal = spell_conceal(current_conceal);
    caster->set_missChance(caster->query_missChance() + current_conceal);
    caster->set_property("blink misschance", 25);
    caster->set_property("magic resistance", spell_conceal);
    
    spell_successful();
    addSpellToCaster();
    spell_duration = (5 + clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    place->addObjectToCombatCycle(this_object(), 1);
    call_out("dest_effect", spell_duration);
}

void execute_attack()
{
    int new_conceal;
    
    if (!flag)
    {
        ::execute_attack();
        flag = 1;
        return;
    }
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    place = environment(caster);
    new_conceal = conceal_effect();
    
    if(caster->query_current_attacker())
    {
        if(new_conceal > current_conceal)
        {
            tell_object(caster, "%^C111%^Your body fades a bit, becoming more a part of the astral plane!%^CRST%^");
            tell_room(place, "%^C117%^" + caster->query_cap_name() + "'s%^C111%^ body fades a bit, becoming more a part of the astral plane!%^CRST%^", caster);
        }
        else if(new_conceal < current_conceal)
        {
            tell_object(caster, "%^C105%^Your body becomes more solid as it enters more fully into the prime!%^CRST%^");
            tell_room(place, "%^C105%^" + caster->query_cap_name() + "'s body becomes more solid as it enters more fully into the prime!%^CRST%^", caster);
        }
    
        caster->set_missChance(caster->query_missChance() - current_conceal);
        caster->set_missChance(caster->query_missChance() + new_conceal);
        current_conceal = new_conceal;
        caster->set_property("magic resistance", -spell_conceal);
        spell_conceal = spell_conceal(current_conceal);
        caster->set_property("magic resistance", spell_conceal);
    }
    
    place->addObjectToCombatCycle(this_object(), 1);
}

void dest_effect()
{
    if(objectp(caster))
    {
        place = environment(caster);
        tell_object(caster, "%^BOLD%^Your body regains its corporeal form as the spell fades.%^RESET%^");
        //objectp(place) && tell_room(place, "EFFECT FADES ROOM", caster);
        caster->set_missChance(caster->query_missChance() - current_conceal);
        caster->remove_property("blink misschance");
        caster->set_property("magic resistance", -spell_conceal);
        caster->remove_property_value("spelled", ({ this_object() }));
    }
    ::dest_effect();
    objectp(this_object()) && this_object()->remove();
}