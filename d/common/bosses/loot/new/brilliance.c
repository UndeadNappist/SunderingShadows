/*
  brilliance.c
  
  Staff weapon dropped by the Nightwalker Boss.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

//Hit interval instead of proc chance. Procs every 3 hits.
#define HIT_INTERVAL 5

inherit "/d/common/obj/weapon/mstaff.c";

string owner;
int hit_count;
object holder;

string color(string str)
{
    return CRAYON_D->color_string(str, "lightning yellow");
}

void create()
{
    ::create();
    
    set_name("brilliance");
    set_id( ({ "brilliance", "staff", "flame staff", "fire staff" }) );
    set_short("brilliance, the flames of inspiration");
    set_obvious_short(color("a brilliant staff"));
    set_long("");
    set_lore("");
    set_value(100000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("caster level bonus", 5);
    set_item_bonus("fire resistance percent", 25);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
}

void init()
{   
    ::init();
    
    holder = environment(this_object());
    
    if(!holder || !userp(holder))
        return;
    
    hit_count = 0;
}

int hit_func(object target)
{
    int dam;
    object holder;
    string ename, pname;
    
    if(!owner || !target)
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    pname = owner->query_cap_name();
    ename = target->query_cap_name();

}

int wield_func()
{
    string stat_to_buff;
    
    if(!holder)
        holder = this_player();
    
    if(!strlen(owner))
        owner = holder->query_true_name();
    
    if(holder->query_true_name() != owner)
    {
        tell_object(holder, "STAFF REJECTS YOU!");
        return 0;
    }
    
    stat_to_buff = "intelligence";
    if(holder->query_stats(stat_to_buff) < holder->query_stats("charisma"))
        stat_to_buff = "charisma";
    if(holder->query_stats(stat_to_buff) < holder->query_stats("wisdom"))
        stat_to_buff = "wisdom";
    
    set_item_bonus(stat_to_buff, 6);
    
    tell_object(holder, "STAFF ACCEPTS YOU!");
    tell_room(environment(holder), color("STAFF ACCEPTS ROOM MESS"), holder);
    return 1;
}

int unwield_func()
{
    owner && tell_object(owner, "STAFF UNWIELD");
    return 1;
}

int scorch_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/s/_scorcher")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(2))
        return notify_fail(sprintf("The staff only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), 0, this_player()->query_level(), 100, "mage");
    
    return 1;
}

int fireball_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/f/_fireball")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(3))
        return notify_fail(sprintf("The staff only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), 0, this_player()->query_level(), 100, "mage");
    
    return 1;
}

int wall_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/w/_wall_of_fire")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(4))
        return notify_fail(sprintf("The ring only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), 0, this_player()->query_level(), 100, "mage");
    
    return 1;
}

int storm_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/f/_fire_storm")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(7))
        return notify_fail(sprintf("The staff only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), 0, this_player()->query_level(), 100, "cleric");
    
    return 1;
}