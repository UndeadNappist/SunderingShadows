/*
  minimap.c
  
  simple_map() efun that creates a visual map of the environment.
  
  -- Tlaloc --
*/

#include <std.h>

#define LINE0 "---------\n"
#define LINE1 "|       |\n"

string query_door(object what, string direction)
{
    string dest;
    object room;
    
    if(!objectp(what) || !strlen(direction))
        return "#";
    
    if(what->query_blocked(direction))
        return "O";
    
    dest = what->query_exit(direction);
    
    if(!dest)
        return "#";
    else
    {
        room = load_object(dest);
        if(!objectp(room))
            return "#";
    }
    
    return " ";
}

varargs string simple_map(mixed arg)
{
    string *exits;
    object room;
    
    if(userp(arg))
        room = environment(arg);
    else if(strlen(arg))
        room = load_object(arg);
    else if(objectp(arg))
        room = arg;
    else
        room = environment(this_player());
    
    if(!objectp(room))
        return "";
    
    exits = room->query_exits();
    
    if(!exits || !sizeof(exits))
        return "";
    
        
    
    
}
        
        
    
    