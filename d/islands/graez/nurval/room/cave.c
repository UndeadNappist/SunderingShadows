inherit ROOM;

void create(){
    ::create();
    set_name("Forboding cave");
    set_short("%^RESET%^%^C059%^Forboding cave%^CRST%^");
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_light(1);
    set_indoors(1);
    set_long("%^RESET%^%^RESET%^%^C059%^This massive cave is awash in deep, shifting %^RESET%^%^C240%^s%^C241%^h%^C242%^a%^C243%^d%^C242%^o%^C241%^w%^RESET%^%^C240%^s %^RESET%^%^C059%^that set the %^RESET%^%^C088%^n%^C124%^e%^C160%^r%^C196%^v%^C124%^e%^RESET%^%^C088%^s %^RESET%^%^C059%^on edge and let the %^RESET%^%^C063%^i%^C069%^m%^C075%^a%^C081%^g%^C087%^i%^C051%^n%^C045%^a%^C039%^t%^C033%^i%^C027%^o%^C026%^n %^RESET%^%^C059%^run wild with what manner of vile creatures might be hidden in their %^RESET%^%^C240%^depths%^RESET%^%^C059%^. The %^RESET%^%^C051%^f%^C087%^r%^C159%^i%^C195%^g%^C087%^i%^RESET%^%^C051%^d a%^RESET%^%^C087%^i%^RESET%^%^C051%^r %^RESET%^%^C059%^within the cave is charged with %^RESET%^%^C240%^u%^C241%^n%^C022%^s%^C028%^e%^C034%^t%^C040%^t%^C028%^l%^C022%^i%^C241%^n%^RESET%^%^C240%^g e%^RESET%^%^C241%^n%^C022%^e%^C028%^r%^C241%^g%^C240%^y%^RESET%^%^C059%^. The cave is mostly empty, making its immensity all the more unnerving, even the slightest of sounds %^RESET%^%^C250%^e%^C252%^c%^C254%^h%^C248%^o%^C247%^i%^C252%^n%^C250%^g%^RESET%^%^C059%^ hauntingly. The far north wall is dominated by what appears to be a very active %^RESET%^%^C240%^portal%^RESET%^%^C059%^, %^RESET%^%^C240%^l%^C241%^i%^C242%^v%^C243%^i%^C244%^n%^C243%^g %^RESET%^%^C242%^d%^C241%^a%^C240%^r%^C241%^k%^C242%^n%^C243%^e%^C242%^s%^C241%^s %^RESET%^%^C059%^clinging to it, an unmistakable %^RESET%^%^C240%^m%^C022%^a%^RESET%^%^C240%^l%^RESET%^%^C040%^i%^C240%^g%^RESET%^%^C028%^n%^C034%^a%^C028%^n%^RESET%^%^C240%^t %^RESET%^%^C028%^a%^C022%^u%^C034%^r%^RESET%^%^C028%^a %^RESET%^%^C059%^radiating from it...%^CRST%^");
    set_items(([
        ({"portal", "runes"}) : "%^RESET%^%^C059%^This portal crawls with %^RESET%^%^C240%^l%^C241%^i%^C242%^v%^C243%^i%^C244%^n%^C243%^g %^RESET%^%^C242%^d%^C241%^a%^C240%^r%^C241%^k%^C242%^n%^C243%^e%^C242%^s%^C241%^s%^RESET%^%^C059%^, its surface undulating like %^RESET%^%^C240%^black serpents %^RESET%^%^C059%^slithering across the surface of a %^RESET%^%^C241%^m%^C246%^u%^C248%^r%^RESET%^%^C246%^k%^C241%^y p%^RESET%^%^C248%^o%^C246%^o%^RESET%^%^C241%^l%^RESET%^%^C059%^. The border of the portal is carved directly from the wall of the cave, runes %^RESET%^%^C046%^glowing %^RESET%^%^C059%^with a %^RESET%^%^C070%^s%^C076%^i%^C082%^c%^C046%^k%^RESET%^%^C076%^l%^C070%^y g%^RESET%^%^C076%^r%^C082%^e%^C046%^e%^RESET%^%^C070%^n l%^RESET%^%^C076%^i%^C082%^g%^RESET%^%^C076%^h%^C070%^t %^RESET%^%^C059%^carved into its surface. Despite your better judgment, you feel the urge to reach out and %^RESET%^%^C246%^trace %^RESET%^%^C059%^the runes.%^CRST%^",
   ]));
   
    set_smell("default","%^RESET%^%^C081%^The chill air here is slightly tinged with a metallic scent.%^CRST%^");
    set_listen("default","%^RESET%^%^C244%^The air practically hums with the vibration of magical energy.%^CRST%^");

    set_exits(([
                "out": "/d/islands/graez/nurval/room/path10",
                
                   ]));
  
}
