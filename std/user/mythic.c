/*
  mythic.c
  
  Handles the Awakening Soul (Mythic paths) system.
  
  -- Tlaloc --
*/

mapping mythic = ([ 
                    "planar power" : 0,
                    "path"  : 0,
                    "level" : 0,
                 ]);
                 

void reset_mythic()
{
    mythic["planar power"] = 0;
    mythic["path"] = 0;
    mythic["level"] = 0;
}

int is_awakened()
{
    if(this_object()->query_level() < 50)
        return 0;
    
    if(!this_object()->query("awakened quest"))
        return 0;
    
    return 1;
}

mixed set_mythic(string str, mixed arg)
{
    string *map_keys;
    if(!stren(str) || !arg)
        return 0;
    
    map_keys = keys(mythic);
    
    if(member_array(str, map_keys) < 0)
        return 0;
    
    return mythic[str] = arg;
}   
    