/*
  stormlords_conduit.c
  
  Khyron-inspired lightning warhammer.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define HIT_INTERVAL 7

inherit "/d/common/obj/weapon/warhammer.c";

string owner;
int hit_count;

void create()
{
    ::create();
    
    set_name("hammer");
    set_id( ({ "hammer", "warhammer", "lord's hammer", "stormlord's hammer", "conduit", "stormlords conduit", "lords hammer", "stormlords hammer" }) );
    set_short("");
    set_obvious_short("");
    set_long("");
    set_value(100000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("caster level bonus", 3);
    set_item_bonus("attack bonus", 7);
    set_item_bonus("electricity resistance percent", 25);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
}

void init()
{
    object holder;
    
    ::init();
    
    holder = environment(this_object());
    
    if(!holder || !userp(holder))
        return;
    
    hit_count = 0;
    
    if(!owner)
    {          
        owner = holder->query)_true_name();
        tell_object(holder, "OWNER ATTUNE MESSAGE");
    }
}

int hit_func(object target)
{
    int dam;
    string ename, pname;
    
    if(!owner || !target)
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    hit_count = 0;
    
    pname = owner->query_cap_name();
    ename = target->query_cap_name();
    
    tell_room(environment(owner), "ROOM HIT FUNC MESSAGE");  

    new("/cmds/spells/l/_lightning_arc")->use_spell(owner, target, 50, 100, "druid");
}

int wield_func()
{
    if(environment(this_object()) != owner)
    {
        tell_object(environment(this_object()), "");
        return 0;
    }
    
    tell_object(owner, "OWNER WIELD MESSAGE");
    tell_room(environment(owner), "ROOM WIELD MESSAGE"), owner);
    return 1;
}

int unwield_func()
{
    owner && tell_object(owner, "OWNER UNWIELD MESSAGE");
    return 1;
} 