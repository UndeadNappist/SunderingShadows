/*
  mythic.c
  
  Handles the Awakening Soul (Mythic paths) system.
  
  -- Tlaloc --
*/

#define DAILY_LIMIT 1000

mapping mythic = ([ 
                    "planar power" : 0,
                    "daily planar power" : 0,
                    "daily count" : 0,
                    "path"  : 0,
                    "level" : 0,
                 ]);
                 

void heart_beat()
{
    if(mythic["daily planar power"])
        if(!hour(time()) && !minutes(time()))
            mythic["daily planar power"] = 0;
}
        

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

int add_planar_power(int x)
{
    if(is_awakened())
        return 0;
    
    if(mythic["daily planar power"] >= DAILY_LIMIT)
        return 0;
    
    if(mythic["daily planar power"] + x >= DAILY_LIMIT)
        x = DAILY_LIMIT - mythic["daily planar power"];
    
    return mythic["planar power"] += x;
}

 
    