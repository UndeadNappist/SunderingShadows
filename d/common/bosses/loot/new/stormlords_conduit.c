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
    set_obvious_short("SHORT DESC");
    set_long("This is a fearsome one-handed warhammer, crafted from obsidian and pumice and adorned with shards of lightning glass. The handle is wrapped in driftwood and bound with sinew, giving the wielder a secure grip even in the midst of a tempest. The head of the hammer is etched with symbols of Khyron, and crackles with energy when held by a follower of the god. When wielded in battle, the hammer unleashes the full fury of the storm, sending lightning bolts crashing into enemies and summoning howling winds to batter them. It is a weapon of chaos and destruction, imbued with the raw power of Khyron himself.");
    set_lore("Legend has it that the Stormlord's Conduit was forged during a massive storm that ravaged the coast, where a band of devout followers of Khyron sought to harness the raw power of the tempest to create a weapon worthy of their god. They sacrificed many offerings to Khyron, including lightning glass, driftwood, obsidian, pumice, and the scales of a leviathan, and imbued the warhammer with the elemental energy of the storm. The smith who forged it is said to have been struck by lightning during the process, but instead of killing him, the bolt seemed to infuse him with a divine energy that allowed him to complete the weapon.");
    set_value(100000);
    set_weight(6);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("caster level bonus", 5);
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
        owner = holder->query_true_name();
        tell_object(holder, "OWNER ATTUNE MESSAGE");
    }
}

int hit_func(object target)
{
    int dam;
    string ename, pname;
    object holder;
    
    holder = environment(this_object());
    
    if(!objectp(holder) || !objectp(target))
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    hit_count = 0;
    
    pname = holder->query_cap_name();
    ename = target->query_cap_name();
    
    tell_room(environment(holder), "When the warhammer strikes its target, it unleashes a thunderous shockwave that tears through the air, leaving behind a trail of crackling energy that scorches the earth and leaves " + target->query_cap_name() + " reeling in agony!");  

    new("/cmds/spells/l/_lightning_arc")->use_spell(holder, target, 50, 100, "druid");
}

int wield_func()
{
    object holder;
    
    holder = environment(this_object());
    
    if(holder->query_true_name() != owner)
    {
        tell_object(holder, "REJECT YOU MESSAGE");
        return 0;
    }
    
    tell_object(holder, "OWNER WIELD MESSAGE");
    tell_room(environment(holder), "ROOM WIELD MESSAGE", holder);
    return 1;
}

int unwield_func()
{
    object holder;
    
    holder = environment(this_object());
    holder && tell_object(holder, "OWNER UNWIELD MESSAGE");
    return 1;
} 