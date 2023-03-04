/*
  _color_spray.c
  
  Full rewrite of spell. 3.4.23
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("color spray");
    set_spell_level( ([ "mage" : 1, "magus" : 1, "oracle" : 1 ]) );
    set_spell_sphere("illusion");
    set_mystery("heavens");
    set_syntax("cast CLASS color spray");
    set_damage_desc("unconscious, paralyzed and/or blind");
    set_description("A vivid cone of clashing colors springs forth from your hand, causing creatures to become stunned, perhaps also blinded, and possibly knocking them unconscious. Targets must make a will save or be affected with various status effects. Targets with a level less than clevel - 10 will be rendered unconscious, paralyzed, and blind for 2d4 rounds. Targets with a level less than clevel - 5 will be rendered paralyzed and blind for 1d4 rounds. All other targets are rendered paralyzed for 1 round.");
    splash_spell(3);
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
}

void spell_effect()
{
    object *targets;
    int length;
    
    if(!objectp(place = environment(caster)))
    {
        dest_effect();
        return;
    }
    
    ::spell_effect();
    
    tell_object(caster,"You wave your hand and a fan-shaped spray of vivid colors flares from your hand!");
    tell_room(place,"You see a fan-shaped spray of vivid colors flare from "+caster->QCN+"'s hands!\n", ({ caster}) );
    
    targets = target_selector();
    
    foreach(object ob in targets)
    {
        if(!objectp(ob))
            continue;
        
        if(environment(ob) != place)
            continue;
        
        if(do_save(ob, 0))
        {
            tell_object(ob, "You manage to resist the effects of the bright light.");
            tell_room(place, ob->query_cap_name() + " manages to resist the effects of the bright light.", ob);
        }
        else
        {
            length = roll_dice(2, 4);
            
            if(ob->query_base_character_level() < clevel - 10)
            {
                ob->set_unconscious(length);
                ob->set_paralyzed(length);
                ob->set_temporary_blind(length);
            }
            else if(ob->query_base_character_level() < clevel - 5)
            {
                length = roll_dice(1, 4);
                ob->set_paralyzed(length);
                ob->set_temporary_blind(length);
            }
            else
            {
                set_paralyzed(1);
            }
        }
    }
    
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}  
    
    
                
    