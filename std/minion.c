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
int    is_minion()          { return 1;                  }

void create()
{
    ::create();
    
    set_name("minion");
    set_id( ({ "minion" }) );
    set_short("A generic minion");
    set_hd(1, 1);
    set_hp(10);
    set_exp(1);
    set_size(2);
    set_damage(1, 1);
    set_gender("neuter");
}

void heart_beat()
{
    object room;
    
    ::heart_beat();
    
    if(!objectp(owner))
        return;
    
    room = environment(this_object());
    
    if(!objectp(room))
        return;
    
    if(follow && room != environment(owner))
    {
        this_object()->move(environment(owner));
        owner->add_follower(this_object());
    }
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


        
    

