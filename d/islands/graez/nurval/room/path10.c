inherit ROOM;

void create(){
    ::create();
    set_name("Before the cave");
    set_short("%^RESET%^%^C059%^Before the cave%^CRST%^");
    set_long("%^CRST%^You stand before the shadow-shrouded entrance of a cave. The air here is noticeably cold and the air practically hums with an unsettling energy. Likely the wisest decision would be to make one's down the stairs and as far away from this place as possible.%^CRST%^");
    set_items(([
        "sky" : "%^RESET%^%^CRST%^The sky above is %^RESET%^%^C242%^c%^C246%^l%^C248%^o%^C241%^t%^C243%^t%^C245%^e%^C242%^d %^CRST%^with preternatural %^RESET%^%^C240%^darkness%^CRST%^.%^CRST%^",
        "walls": "%^RESET%^%^C244%^Even from this vantage point, the %^RESET%^%^C240%^coal-black walls %^RESET%^%^C244%^enclosing the %^RESET%^%^C246%^z%^C248%^i%^C246%^g%^C244%^g%^RESET%^%^C246%^u%^RESET%^%^C248%^r%^RESET%^%^C250%^a%^RESET%^%^C246%^t%^RESET%^%^C244%^ are towering.%^CRST%^",
        "ziggurat" : "%^RESET%^%^C244%^This massive, tiered structure scrapes the %^RESET%^%^C240%^d%^C241%^a%^C242%^r%^C243%^k%^C242%^e%^C241%^n%^C240%^e%^C241%^d %^RESET%^%^C240%^s%^C241%^k%^C242%^y%^C244%^, made of %^RESET%^%^C240%^coal-black stones %^C244%^similar to the walls.%^CRST%^\n",
   ]));
   
    set_smell("default","%^RESET%^%^C241%^The chill air here is slightly tinged with a metallic scent.%^CRST%^");
    set_listen("default","%^RESET%^%^C244%^The air practically hums with the vibration of magical energy.%^CRST%^");

    set_exits(([
                "cave": "/d/islands/graez/nurval/room/cave",
                "stairs": "/d/islands/graez/nurval/room/path9",
                
                   ]));
  
}
