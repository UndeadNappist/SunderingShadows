/*
  _arbitrament.c
  
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
    set_spell_name("arbitrament");
    set_spell_level( ([ "cleric" : 7 ]) );
    set_spell_sphere("invocation_evocation");
    set_domains( ({ "balance" }) );
    set_syntax("cast CLASS arbitrament");
    set_damage_desc("Status effects to LG, LE, CG, CE");
    set_description("You utter a demand for a return to balance. All creatures in the vicinity are subjected to immediate arbitrament. Any foe who is of the Lawful Good, Lawful Evil, Chaotic Good, or Chatic Evil alignments must make an immediate will save or become sickened. Additionally, any of those foes who are lower level than caster level must make another will save or become staggered. Finally, any of those foes who are 5 levels below caster level must make a combat death save or immediately perish. Those that pass the death save will take divine damage.");
    set_save("will");
    splash_spell(3);
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^CYAN%^PRE SPELL CAST CASTER");
    tell_room(place,"%^BOLD%^%^CYAN%^" + caster->query_cap_name() + " PRE SPELL CAST ROOM",caster);
    return "display";
}

void spell_effect()
{
    object *foes, status_ob;
    int foe_level;
    
    tell_room(place, "The scales of balance sound with a mighty boom, pronouncing arbitrament on all extreme beings in the area!");
    
    foes = target_selector();
    foes = filter_array(foes, (: ($1->query_true_align() == 1 || $1->query_true_align() == 3 || $1->query_true_align() == 7 || $1->query_true_align() == 9 || $1->query_true_align() == 0) :));
    
    if(!sizeof(foes))
    {
        tell_object(caster, "There are no targets here.");
        dest_effect();
        return;
    }
    
    foreach(object ob in foes)
    {
        foe_level = ob->query_base_character_level();
        
        //Everyone saves against sickened
        if(!do_save(ob, 0))
        {
            if(!catch(status_ob = load_object("/std/effect/status/sickened.c")))
                status_ob->apply_effect(ob, 1 + clevel / 6);
        }
        
        //Foes lower level than clevel also save against staggered
        if(foe_level < clevel)
        {
            if(!catch(status_ob = load_object("/std/effect/status/staggered.c")))
            {
                if(do_save(ob, 0))
                    status_ob->apply_effect(ob, roll_dice(2, 4));
                else
                    status_ob->apply_effect(ob, roll_dice(1, 4));
            }
        }
        
        
        //Foes up to caster level - 5 also save against death
        if(foe_level < clevel - 5)
        {
            if(!combat_death_save(ob))
                damage_targ(ob, "torso", ob->query_max_hp() + 100, "untyped");
            else
                damage_targ(ob, "torso", sdamage, "divine");
        }   
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
        


