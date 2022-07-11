/*
  minimap.c
  
  simple_map() efun that creates a visual map of the environment.
  
  -- Tlaloc --
*/

#include <std.h>

string query_blocked(object what, string direction)
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
    string *exits, *lines, *extra_desc;
    string this_exit;
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
    
    lines = allocate(7);
    lines[0] = "---------\n";
    lines[6] = "---------\n";
    lines[1] = "|       |\n";
    lines[3][4..4] = "*";
    
    foreach(string dir in exits)
    {
        this_exit = query_blocked(room, dir);
        
        switch(dir)
        {
            case "north":
            lines[1][4..4] = this_exit;
            lines[2][4..4] = "|";
            break;
            case "south":
            lines[5][4..4] = this_exit;
            lines[4][4..4] = "|";
            break;
            case "east":
            lines[3][7..7] = this_exit;
            lines[3][5..5] = "-";
            lines[3][6..6] = "-";
            break;
            case "west":
            lines[3][1..1] = this_exit;
            lines[3][2..2] = "-";
            lines[3][3..3] = "-";
            break;
            case "northeast":
            lines[1][7..7] = this_exit;
            lines[2][6..6] = "/";
            break;
            case "northwest":
            lines[1][1..1] = this_exit;
            lines[2][2..2] = "\\";
            break;
            case "southest":
            lines[5][7..7] = this_exit;
            lines[4][6..6] == "\\";
            break;
            case "southwest":
            lines[5][1..1] = this_exit;
            lines[4][2..2] = "/";
            break;
            default:
            extra_desc = dir;
            break;
        }
    }
        
    if(sizeof(extra_desc))
        lines[3] = replace_string(lines[3], "\n", "Also Available: " + implode(extra_desc, ", ") + "\n");
    
    return implode(lines, "\n");           
}
        
        
    
    