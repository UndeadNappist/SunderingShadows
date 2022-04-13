/*
  New scrying system handler.
  
  -- Tlaloc --
*/

#include <std.h>
#include <security.h>

//This is a spot scry check
int scry_check(object target, int power)
{
    object room;
    int block_power, room_block;
    
    if(!objectp(target) || !power)
        return 0;
    
    room = environment(target);
    
    if(!objectp(room))
        return 0;
    
    if(room->query_property("no scry"))
        return 0;
    
    if(target->query_property("block scrying"))
        return 0;
    
    room_block = room->query_property("scry proof");    
    block_power = target->query_property("scry block power");
    
    block_power = max( ({ room_block, block_power }) );   
   
    if(block_power > power)
        return 0;
    
    return 1;
}