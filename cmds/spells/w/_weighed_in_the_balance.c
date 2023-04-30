/*
  _weighed_in_the_balance.c
  
  Balance Domain spell based on SRD.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("weighed in the balance");
    set_spell_level( ([ "cleric" : 9 ]) );
    set_affixed_spell_level(5);
    set_spell_sphere("necromancy");
    set_domains( ({ "balance" }) );
    set_syntax("cast CLASS weighed in the balance");
    set_damage_desc("negative energy damage to enemies. positive energy to allies");
    set_description("You speak the words of power, enforcing balance with nature on all present. Enemies take negative energy damage and allies are healed by positive energy equivalent to a cure serious wounds or cause serious wounds spell. The damage done is greater against enemies who have no semblance of neutrality in them (LG, CG, LE, CG). The healing done is greater on allies who have neutrality in their alignment (LN, TN, CN, NE, NG). The polarity is reversed for undead targets.");
    splash_spell(3);
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^CYAN%^You cast judgement on all present, demanding balance with the natural order of the world!");
    tell_room(place,"%^BOLD%^%^CYAN%^" + caster->query_cap_name() + " casts judgement on all present, demanding balance with the natural order of the world!",caster);
    return "display";
}

void spell_effect()
{
    object *foes, *friends;
    string energy;
    
    tell_room(place, "%^C033%^The scales of balance exact their %^C045%^judgment%^C033%^ on all present with waves of %^C255%^positive%^C033%^ and %^C244%^negative%^C033%^ energy!%^CRST%^");
    
    foes = target_selector();
    
    foreach(object ob in foes)
    {
        if(ob->is_undead())
            energy = "positive energy";
        else
            energy = "negative energy";
        
        switch(ob->query_true_align())
        {
            case 0:
            case 1:
            case 3:
            case 7:
            case 9:
            set_affixed_spell_level(5);
            break;
            default:
            set_affixed_spell_level(3);
            break;
        }
        
        //This is required to recalc damage based on affixed level above
        define_base_damage();
        damage_targ(ob, "torso", sdamage, energy);
    }
    
    friends = ob_party(caster);
    if(!pointerp(friends))
        friends = ({  });
    friends += caster->query_followers();
    
    foreach(object ob in friends)
    {
        if(ob->is_undead())
            energy = "negative energy";
        else
            energy = "positive energy";
        
        switch(ob->query_true_align())
        {
            case 2:
            case 4:
            case 5:
            case 6:
            case 7:
            set_affixed_spell_level(5);
            break;
            default:
            set_affixed_spell_level(3);
            break;
        }
        
        //This is required to recalc damage based on affixed level above
        define_base_damage();
        damage_targ(ob, "torso", sdamage, energy);
    }
    
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(this_object()))
        this_object()->remove();
}
        


