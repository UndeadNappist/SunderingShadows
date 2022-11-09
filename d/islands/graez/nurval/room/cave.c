inherit ROOM;

void create(){
    ::create();
    set_name("Forboding cave");
    set_short("%^RESET%^%^C059%^Forboding cave%^CRST%^");
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_light(1);
    set_indoors(1);
    set_long("%^RESET%^%^CRST%^");
    set_items(([
        
   ]));
   
    set_smell("default","%^RESET%^%^C241%^The chill air here is slightly tinged with a metallic scent.%^CRST%^");
    set_listen("default","%^RESET%^%^C244%^The air practically hums with the vibration of magical energy.%^CRST%^");

    set_exits(([
                "out": "/d/islands/graez/nurval/room/path10",
                
                   ]));
  
}
