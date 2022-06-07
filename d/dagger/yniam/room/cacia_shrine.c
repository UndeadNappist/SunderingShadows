// Branwen (6/4/22)
// Yniam Waystation - Shrine

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(BEACH);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("cacia's shrine");
    set_short("%^RESET%^%^CRST%^%^C060%^Cacia's Shrine%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C101%^A %^C243%^stone path%^C101%^ leads to a circle of pavement that gives way to a raised %^C243%^m%^C245%^a%^C243%^r%^C245%^b%^C243%^l%^C245%^e %^C243%^pl%^C245%^at%^C243%^fo%^C245%^rm%^RESET%^%^C101%^ dominated by a %^C060%^beguiling sculpture%^RESET%^%^C101%^. Offerings are lain out at its feet or placed reverently in its upturned palms. An %^C102%^inscription%^RESET%^%^C101%^ wraps around the periphery of the dais.\n\n%^RESET%^%^C059%^Little else flourishes here, and even the wind seems hesitant to expel its breath, the world stilled as if waiting for a ravenous predator to pass.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C156%^The scents of the plains are carried on the breeze.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C247%^The %^C244%^silence%^C247%^ is palpable.%^CRST%^");
    set_items(([
        "offerings" : "%^RESET%^%^CRST%^%^C109%^Placed with intention are traces of %^C245%^worldly vices%^C109%^: Bottles of spirits, cigarettes, pouches of pungent herbs. Splashes of blood, wine, and other curious substances are all %^C114%^reverently%^C109%^ left here by those seeking her favor.%^CRST%^",
        ({ "statue", "platform", "dais", "sculpture" }) : "^RESET%^%^CRST%^%^C060%^A sinuous sculpture lurks before you, its %^C054%^alluring%^C060%^ feminine form encapsulated in solid %^C061%^darksteel%^RESET%^%^C060%^, the edge of each detail picked out in a sinister %^C053%^viol%^C052%^e%^C053%^t tarni%^C052%^s%^C053%^h%^RESET%^%^C060%^. A smile tugs at the corner of her %^C059%^swollen lips%^RESET%^%^C060%^, her comely gaze cast downward to take in your measure. Six supple arms grace her slender body, the two at her shoulders reaching high and low along her curves to seek out the %^C059%^tantalizing%^C060%^ swell of a breast and the %^C059%^shaded secrets%^C060%^ between clenched thighs. The other four slink outwards from the serpentine curve of her back, her delicate hands palm upwards, awaiting the %^C066%^offerings%^C060%^ of her supplicants.%^CRST%^",
        "inscription" : "It reads, %^C059%^\"She Who Drinks of the World.\"%^CRST%^",
        ]));
}

