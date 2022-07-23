/*
  cooldowns.c
  
  Shows your current cooldowns and time left.
  
  -- Tlaloc --
*/

#include <std.h>
#include <ansi.h>
#include <daemons.h>

//#define LINE sprintf("%s[ Cooldowns ]%s\n", "*=*=*=*=*=*", "*=*=*=*=*=*")
//#define LINE "%^BOLD%^============[ %^CYAN%^Cooldowns%^WHITE%^ ]============%^RESET%^\n"
#define LINE "%^BOLD%^BLUE%^-------------------=%^CYAN%^< %^WHITE%^Cooldowns %^CYAN%^>%^BLUE%^=--------------------%^RESET%^"
#define LINE2 "%^BOLD%^BLUE%^------------------------------------------------------%^RESET%^"

inherit DAEMON;

mixed cmd_cooldowns(string args)
{
    object who = this_player();
    mapping cooldowns;
    string *keys;
    int width, minutes, seconds;
    
    cooldowns = who->query_cooldowns();
    keys = keys(cooldowns);
    
    write("\n");
    write(LINE);
    
    if(sizeof(keys))
    {
        foreach(string str in keys)
        {
            seconds = cooldowns[str] - time();
            minutes = seconds / 60;
            seconds = seconds % 60;
            tell_object(who, sprintf("  %s%-19s%s - %s%5s%s", YEL, capitalize(str), NOR, HIN, minutes ? minutes + "m " + seconds + "s" : seconds + "s", NOR));
            //tell_object(who, sprintf("   %s%-13s%s : %s%6d%s sec\n",YEL,capitalize(str),NOR,HIN,(cooldowns[str] - time()),NOR));
        }
    }
    //else
    //    write("                %^BOLD%^None%^RESET%^\n");
    
    write(LINE2);
    write("%^BLACK%^BOLD%^Type 'dispell' to see what spells you maintain.%^RESET%^");
    write("%^BLACK%^BOLD%^Type 'bonuses' to see what bonuses you are receiving.%^RESET%^");
    return 1;
}
    
    
    