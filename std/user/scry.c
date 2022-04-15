/*
  New scrying system handler.
  
  -- Tlaloc --
*/

//This is a spot scry check
int scry_check(object scryer, int power)
{
    object room, block_spell;
    int block_power, room_block, detect_power, false_vision, result;
    
    if(!objectp(this_object()) || !objectp(scryer) || !power)
        return 0;
    
    room = environment(this_object());
    
    if(!objectp(room))
        return 0;
    
    if(room->query_property("no scry"))
        return 0;
    
    if(this_object()->query_property("block scrying"))
        return 0;
    
    detect_power = this_object()->query_property("scry detect power");
    false_vision = this_object()->query_property("false vision");
    room_block = room->query_property("scry proof");    
    block_power = this_object()->query_property("scry block power");    
    block_power = max( ({ room_block, block_power }) );
    
    
    result = (false_vision + 10) - (power + roll_dice(1, 20));
    if(result >= 0)
    {
        tell_object(scryer,"%^BOLD%^%^MAGENTA%^Suddenly, horrific images of your worst fears appear before your eyes, and you can't help but to stagger away in fright, losing your concentration!");
        scryer->cause_typed_damage(scryer, "head", roll_dice(false_vision / 2, 6), "mental");
        if(result >= 5)
            scryer->cause_typed_damage(scryer, "head", roll_dice(false_vision, 6), "mental");
        return 0;
    }
   
    //Reverse check for detection
    result = (detect_power + roll_dice(1, 20)) - (power + 10);
    if(result >= 0)
    {
        tell_object(this_object(),"%^BOLD%^MAGENTA%^You detect someone scrying you!%^RESET%^");
        if(result >= 5)
        {
            tell_object(this_object(),"%^BOLD%^YELLOW%^You get an image of where they are!%^RESET%^");
            scryer->reverse_look_room(this_object());
        }   
    }
        
    if(block_power + 10 > power + roll_dice(1, 20))
        return 0;
    
    return 1;
}

void long_look_room(object detector, int power)
{
    string file, desc;
    object *inv, dest;
    int i,j;
    
    if(!objectp(this_object()))
        return;
    
    dest = environment(this_object());
    
    if(!dest || !objectp(dest))
        return;
    
    if(!detector || !objectp(detector))
        return;
    
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_short()+"\n", detector);
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_long()+"\n", detector);
    inv = all_inventory(dest);

    foreach(object ob in inv)
    {
        if(!objectp(ob))
            continue;
        if(ob->query_invis())
            continue;
        if(ob->is_detectable())
            continue;
        if(ob != this_object())
            if(!ob->scry_check(detector, power))
                continue;
        tell_object(detector, "%^WHITE%^BOLD%^[S] %^RED%^"+inv[i]->query_short());
    }
    return;
}

//This is here to avoid infinite loop
void reverse_look_room(object detector)
{
    string file, desc;
    object *inv, dest;
    int i,j;
    
    if(!objectp(this_object()))
        return;
    
    dest = environment(this_object());
    
    if(!dest || !objectp(dest))
        return;
    
    if(!detector || !objectp(detector))
        return;
    
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_short()+"\n", detector);
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_long()+"\n", detector);
    inv = all_inventory(dest);

    foreach(object ob in inv)
    {
        if(!objectp(ob))
            continue;
        if(ob->query_invis())
            continue;
        if(ob->is_detectable())
            continue;
        tell_object(detector, "%^WHITE%^BOLD%^[S] %^RED%^"+inv[i]->query_short());
    }
    return;
}