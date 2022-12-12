#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(RUTTED_TRACK);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("Black Rose Construction");
    set_short("%^RESET%^%^CRST%^%^C053%^Black %^C052%^Ro%^C124%^s%^C226%^e %^C154%^Construction %^C094%^Site%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C094%^The long pathway ends here in well-maintained tent complex surrounded by %^C053%^black roses%^C094%^. One main tent stands here with a few  %^C088%^crimson robed %^C094%^men and woman moving about on various tasks. Behind the %^C208%^tent%^C094%^, %^C122%^construction materials %^C094%^are stacked, bringing on the realization that this is likely just the beginning of a larger more permanent structure.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C124%^You smell the unmistakable scent of brimstone.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C155%^You hear the banter of priests in the area and the occasional sounds of construction.%^CRST%^");
    set_items(([
        "tent" : "%^RESET%^%^CRST%^%^C088%^This large tent has been entirely made up of crimson fabrics with gold lining. Its entrance is closed off by long golden corded ropes which visually block the entrance but can easily be moved through.",
        ({ "black roses", "roses" }) : "%^RESET%^%^CRST%^%^C053%^These beautiful black roses are clearly the center-piece for the area. Immaculately groomed and maintained, they line the complex and the path going into it.",
        ]));
    set_exits(([
        "tent" : "/d/magic/temples/mephasm/mephasm",
        "west" : "/d/shadow/room/forest/owagon9",
        ]));
}

