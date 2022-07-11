/*
  minimap.c
  
  simple_map() efun that creates a visual map of the environment.
  
  -- Tlaloc --
*/

#include <std.h>

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
        
        
    
    