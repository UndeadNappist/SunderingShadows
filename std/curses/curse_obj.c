/*
  curse_obj.c
  
  Standardized curse object in line with poisons and disease.
  
  -- Tlaloc --
*/

#include <std.h>
#include <stdprops.h>
#include <daemons.h>

inherit OBJECT;

string description, damage_desc;
int power, duration;
object victim;

void create()
{
    ::create();
    set_name("curse_obj");
    set_property(NO_DROP);
    set_property(NO_PUT);
}

string set_description(string str) { description = str; return description; } //Help file description
string set_damage_desc(string str) { damage_desc = str; return damage_desc; } //Help file effect description
int set_power(int x)               { power = x; return power;               } //Power should be clevel + stat bonus
int set_duration(int x)            { duration = x; return power;            } //Some curses have limited duration on save
object set_victim(object ob)       { victim = ob; return victim;            } //Who we're afflicting
int is_curse()                     { return 1;                              } //It IS a curse

//Default break curse check. Pass curing spell clevel + stat bonus
int break_curse(int x)
{
    if(power + 10 > x + roll_dice(1, 20))
        return 0;
    
    if(objectp(this_object()))
        this_object()->remove();
    
    return 1;
}

object apply_curse(object who, int level)
{
    object *curses, curse;
    
    if(!living(who) || !level)
        return 0;
    
    if(PLAYER_D->immunity_check(who, "curses"))
        return 0;
    
    curses = filter_array(all_inventory(who), (: $1->is_curse() :));
    
    foreach(object ob in curses)
    {
        if(ob->query_name() == this_object()->query_name())
        {
            destruct(this_object());
            return 0;
        }
    }
    
    curse = new(file_name(this_object()));
    curse->move(who);
    curse->set_power(level);
    curse->set_victim(who);
    curse->start_curse();
    
    return curse;
}

void help()
{
    write("%^PURPLE%^%^BOLD%^Name: %^RESET%^" + query_name());

    if (damage_desc) {
        write("%^PURPLE%^%^BOLD%^Effect: %^RESET%^" + damage_desc);
    }
    write("%^PURPLE%^%^BOLD%^Description: %^RESET%^" + description);
}