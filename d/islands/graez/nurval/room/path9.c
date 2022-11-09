inherit ROOM;

void create(){
    ::create();
    set_name("Path through the mountains");
    set_short("%^RESET%^%^C059%^Path through the mountains%^CRST%^");
    set_long("%^CRST%^The %^RESET%^%^C058%^path %^CRST%^here travels through the %^RESET%^%^C059%^mountains%^CRST%^, large boulders balanced precariously on either side of the trail. To the south the %^RESET%^%^C058%^path %^CRST%^continues along the inside of the towering %^RESET%^%^C240%^walls%^CRST%^ while to the north it veers away from them, continuing to climb toward the entrance of a %^RESET%^%^C241%^cave%^CRST%^.%^CRST%^");
    set_items(([
        "sky" : "%^RESET%^%^CRST%^The sky above is %^RESET%^%^C242%^c%^C246%^l%^C248%^o%^C241%^t%^C243%^t%^C245%^e%^C242%^d %^CRST%^with preternatural %^RESET%^%^C240%^darkness%^CRST%^.%^CRST%^",
        "walls": "%^RESET%^%^C244%^Even from this vantage point, the %^RESET%^%^C240%^cloak-black walls %^RESET%^%^C244%^enclosing the %^RESET%^%^C246%^z%^C248%^i%^C246%^g%^C244%^g%^RESET%^%^C246%^u%^RESET%^%^C248%^r%^RESET%^%^C250%^a%^RESET%^%^C246%^t%^RESET%^%^C244%^ are towering.%^CRST%^",
        "ziggurat" : "%^RESET%^%^C244%^This massive, tiered structure scrapes the %^RESET%^%^C240%^d%^C241%^a%^C242%^r%^C243%^k%^C242%^e%^C241%^n%^C240%^e%^C241%^d %^RESET%^%^C240%^s%^C241%^k%^C242%^y%^C244%^, made of %^RESET%^%^C240%^coal-black stones %^C244%^similar to the walls.%^CRST%^\n",
   ]));
   
    set_smell("default","%^RESET%^%^C241%^A slightly metallic scent tinges the air.%^CRST%^");
    set_listen("default","%^RESET%^%^C244%^There is an unsettling quiet here.%^CRST%^");

    set_exits(([
                "up": "/d/islands/graez/nurval/room/path10",
                "south": "/d/islands/graez/nurval/room/path8",
                   ]));
  
}
