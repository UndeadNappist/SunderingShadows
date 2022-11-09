inherit ROOM;

void create(){
    ::create();
    set_name("Forboding cave");
    set_short("%^RESET%^%^C059%^Forboding cave%^CRST%^");
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_light(1);
    set_indoors(1);
    set_long("%^RESET%^%^RESET%^%^C059%^This massive cave is awash in deep, shifting %^RESET%^%^C240%^s%^C241%^h%^C242%^a%^C243%^d%^C242%^o%^C241%^w%^RESET%^%^C240%^s %^RESET%^%^C059%^that set the %^RESET%^%^C088%^n%^C124%^e%^C160%^r%^C196%^v%^C124%^e%^RESET%^%^C088%^s %^RESET%^%^C059%^on edge and let the imagination run wild with what manner of vile creatures might be hidden in their %^RESET%^%^C240%^depths%^RESET%^%^C059%^.%^CRST%^");
    set_items(([
        
   ]));
   
    set_smell("default","%^RESET%^%^C241%^The chill air here is slightly tinged with a metallic scent.%^CRST%^");
    set_listen("default","%^RESET%^%^C244%^The air practically hums with the vibration of magical energy.%^CRST%^");

    set_exits(([
                "out": "/d/islands/graez/nurval/room/path10",
                
                   ]));
  
}
