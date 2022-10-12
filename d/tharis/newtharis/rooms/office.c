#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("carriage house");
    set_short("%^RESET%^%^C015%^The %^RESET%^%^C231%^C%^C225%^a%^C189%^r%^C231%^r%^C230%^i%^C194%^a%^C231%^g%^C159%^e %^RESET%^%^C231%^H%^C195%^o%^C153%^u%^C231%^s%^C189%^e%^CRST%^");
    set_long("%^RESET%^%^C015%^Citizens of the city and tourists both pour in and out of this fine carriage house like so many %^RESET%^%^C241%^ants%^RESET%^%^C015%^. The floors and walls are composed of a glossy %^RESET%^%^C231%^white marble %^RESET%^shot through with %^RESET%^%^C231%^p%^C225%^e%^C189%^a%^C231%^r%^C230%^l%^C194%^e%^C231%^s%^C159%^c%^C195%^e%^C153%^n%^C231%^t v%^C189%^e%^C117%^i%^C159%^n%^C231%^s %^RESET%^%^C015%^and several thick %^RESET%^%^C231%^c%^C231%^o%^C225%^l%^C231%^u%^C153%^m%^C189%^n%^C231%^s %^RESET%^%^C015%^support a high, domed ceiling ornamented with a %^RESET%^%^C178%^g%^C220%^o%^C226%^l%^C227%^d%^C220%^e%^C178%^n b%^RESET%^%^C226%^a%^C178%^s-r%^RESET%^%^C220%^e%^C226%^l%^C227%^i%^C220%^e%^RESET%^%^C178%^f%^RESET%^%^C015%^. Sconces contain tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s %^RESET%^%^C015%^that cast the spacious room in a %^RESET%^%^C135%^d%^C141%^u%^C147%^s%^C153%^k%^C147%^y %^C141%^l%^C135%^u%^C141%^m%^C147%^i%^C153%^n%^C147%^e%^C141%^s%^C147%^c%^C153%^e %^RESET%^%^C015%^and large %^RESET%^%^C231%^porcelain pots %^RESET%^%^C231%^hold %^RESET%^%^C240%^b%^C241%^r%^C028%^o%^C241%^a%^C240%^d-l%^RESET%^%^C241%^e%^C028%^a%^C034%^f%^C241%^e%^RESET%^%^C240%^d p%^RESET%^%^C241%^l%^C022%^a%^C028%^n%^C241%^t%^RESET%^%^C240%^s %^RESET%^%^C015%^nestled in many corners of the carriage house. The north side of the room houses %^RESET%^%^C098%^ticketing booths %^RESET%^%^C015%^while on the east side, a colonnade leads to %^RESET%^%^C178%^p%^C220%^l%^C226%^a%^C227%^t%^C228%^f%^C227%^o%^C226%^r%^C220%^m%^C178%^s %^RESET%^%^C015%^where travelers board and exit the fine %^RESET%^%^C241%^horseless carriages %^RESET%^%^C015%^that traverse the city. %^RESET%^%^C189%^S%^C225%^t%^C117%^a%^C153%^i%^C123%^n%^C159%^e%^C153%^d%^RESET%^%^C015%^-%^RESET%^%^C087%^g%^C123%^l%^C159%^a%^C123%^s%^C087%^s w%^RESET%^%^C123%^i%^C159%^n%^C195%^do%^C159%^w%^RESET%^%^C123%^s %^RESET%^%^C015%^decorate the western wall and to the south is an %^RESET%^%^C231%^archway %^RESET%^%^C015%^that leads into what appears to be a mail room, a %^RESET%^%^C178%^p%^C220%^l%^C226%^a%^C227%^q%^C220%^u%^C178%^e %^RESET%^%^C015%^above the entryway.\n%^CRST%^");
    //set_long("%^RESET%^%^ORANGE%^This small office is cramped and lit by only one lone torch, casting %^BOLD%^%^BLACK%^shadows%^RESET%^%^ORANGE%^ into its corners. The walls are filled with wanted posters, aged and curling, with some torn away almost "
     // "completely. A small desk is cluttered with equally aged and damaged paperwork, "
     // "including a single ominously large leather-bound book. Here is where the elves of "
     // "Tharis were once required to %^RESET%^%^BOLD%^'register'%^RESET%^%^ORANGE%^, but it "
     // "seems it has been long since abandoned to fall into disrepair, or perhaps left as a "
     // "reminder - after all, someone must have lit that torch. The floor is stained %^RESET%^%^RED%^dark crimson%^ORANGE%^, leaving you to wonder what might once have happened here...\n%^RESET%^");
    set_smell("default","%^RESET%^%^C147%^A light floral scent lingers here.%^CRST%^");
    set_listen("default","%^RESET%^%^C153%^You hear the bustle of citizens and visitors going about their business.%^CRST%^");

    set_items (([
     // ({ "book", "leather book", "leather-bound book" }) : "%^RESET%^This book seems to be in "+
     // "better shape than any of the other paperwork or posters here. It contains the names of "+
     // "the elves who have registered to be in the city.%^RESET%^",
    ]));

    set_exits(([
      "north" : ROOMS"elf1",
      "south" : ROOMS"reg2",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}