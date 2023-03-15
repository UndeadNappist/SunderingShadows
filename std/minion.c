/*
  minion.c
  
  Baseline minion inheritable with basic functionality.
  
  -- Tlaloc --
*/

#include "/d/magic/mon/summoned_monster.h"

inherit WEAPONLESS;

object owner;
int follow;

object set_owner(object ob) { owner = ob; return owner;  }
int    set_follow(int x)    { follow = x; return follow; }
int    is_minion()          { return 1;                 }

void create()
{
    ::create();
    
    set_name("minion");
    set_id( ({ "minion", "summoned monster" }) );
    set_short("A generic minion");
    set_hd(1, 1);
    set_hp(10);
    set_exp(1);
    set_size(2);
    set_damage(1, 1);
    set_gender("neuter");
    follow = 1;
    
    set_monster_feats( ({ "perfect caster" }) );
}

void heart_beat()
{
    object me = this_object(), my_environment, owners_environment;
    
    ::heart_beat();
    
    if (!objectp(owner))
        return;

    if (!objectp(owners_environment = environment(owner)))
        return;

    if (!objectp(me))
        return;

    if (!objectp(my_environment = environment(me)))
        return;

    if (follow && my_environment != owners_environment)
    {
        me->move(owners_environment);
        owner->add_follower(me);
        owner->add_protector(me);
    }
}       

int setup_minon(int clevel, spell_level, string type)
{
    if(!clevel || !spell_level)
        return 0;
    
    if(!strlen(type))
        return 0;
    
    set_new_exp(1, "low");
    set("aggressive", 1);
    remove_property("swarm");
    set_mlevel("fighter", clevel);
    set_guild_level("fighter", clevel);
    
    switch(type)
    {
        case "lesser":
        set_hd(clevel / 2 + 1, spell_level);
        set_max_hp(1);
        break;
        case "standard":
        set_hd(clevel, spell_level);
        break;
        case "greater":
        set_hd(clevel, spell_level);
        set_max_hp(clevel * 100);
        set_static_bab(clevel);
        set_property("effective enchantment", clevel / 7 + 1);
        set_attacks_num(clevel / 13 + 1);
        break;
    }
    
    set_hp(query_max_hp());
    
    if(objectp(owner))
    {
        owner->add_follower(this_object());
        owner->add_protector(this_object());
        set_property("minion", owner);
        set_follow(1);
    }
    
    return 1;
}
/*
The idea of this system is to, first of all, have a player command that handles minions

/cmds/mortal/_minions.c

Secondly all minions should inherit this object and additional functionality will be added
over time.

Thirdly, all minions should have more standardized stat and power levels based on three
categories : fodder, lesser, greater

- Fodder minions are very low HP and should only take like a hit or two from a similarly
  levelled opponent. (sticks into snakes, lesser undead, etc)

- Lesser minions should absorb more damage (but still be weaker than current versions).

- Greater minions should be very strong, summoned outside of combat and have high HP, armor,
  feats and reliability. Still only one of these at a time. Stronger than current iterations.
*/


        
    

