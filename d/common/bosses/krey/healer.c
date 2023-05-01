#include <std.h>

inherit MONSTER;

int buffed;

void create(){
   ::create();

   set_name("healer");
   set_short("Dragonkin Priest");
   set_id(({"krey_healer", "healer", "priest", "dragon priest", "noble", "dragonkin priest"}));
   set_long("SICK DRAGONKIN DESCRIPTION");
   set_property("magic",1);
   set_hd(60,8);
   set_level(60);
   set_class("cleric");
   set_mlevel("cleric", 60);
   set_hp(3000);
   set_base_damage_type("bludgeoning");
   set_gender("male");
   set_race("dragonkin");
   set("subrace", "earth");
   set_attacks_num(7);
   set_property("spell damage resistance", 20);
   set_property("divine resistance percent", 20);
   set_overall_ac(-70);
   set_monster_feats( ({ "perfect caster", "spell power", "spell penetration", "greater spell power", "apotheosis", "divine domain" }) );
   set_spells( ({ "repulsion", "stone body", "blade barrier" }) );
   set_spell_chance(75);
}

void init()
{
    object spell;
    
    ::init();
    
    if(!buffed)
    {
        if(objectp(spell = new("/cmds/spells/b/_blade_barrier")))
            spell->use_spell(this_object(), 0, 60, 100, "cleric");
        if(objectp(spell = new("/cmds/spells/r/_repulsion")))
            spell->use_spell(this_object(), 0, 60, 100, "cleric"); 
        if(objectp(spell = new("/cmds/spells/s/_stone_body")))
            spell->use_spell(this_object(), 0, 60, 100, "cleric");  
        
        set_spells( ({ "bolt of force", "implosion", "fire storm" }) );
        
        buffed = 1;
    }
}
        
void die()
{
    object *targets;
    tell_room(environment(this_object()), "DRAGONKIN ROARS AS HE DIES MESSAGE");
    
    ::die();
}