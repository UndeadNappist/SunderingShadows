// Chernobog (12/12/22)
// Shrine to Mephasm
// Written by Vuzan

#include <std.h>
#include <player_housing.h>
inherit "/std/temple";

void create(){
    ::create();
    set_terrain(BEACH);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_temple("mephasm");
    set_name("mephasm's shrine");
    set_short("%^RESET%^%^CRST%^%^C113%^Inside a %^C088%^Crimson %^C226%^Tent%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C113%^The insides of the tent are dimly lit and has multiple places to sit, on cushions provided. The seating is meticulously arranged around a %^C053%^summoning circle %^C113%^in the center of the room. Stacked and organized along the edge of the room are various treasures and offerings, including chests of gold, gems and other valuable items, evidently for tribute to the creatures treated with here.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C124%^You smell the unmistakable scent of brimstone.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C155%^The room here is silent save for brief noises from outside.%^CRST%^");
    set_items(([
        ({ "summoning circle", "circle" }) : "%^RESET%^%^CRST%^%^C088%^The summoning circle sits prominently in the center of the room with a dull glow of magic radiating from the lines of powdered silver etched on the ground.%^CRST%^",
        "treasure" : "%^RESET%^%^CRST%^%^C053%^The treasures here are likely used for propitiation by the priests, such is the cost of willingly given souls.%^CRST%^",
        ]));
    set_exits(([
        "out" : "/d/magic/temples/mephasm/outside",
        ]));
    
    set_property("scry proof", SCRYWARD_EPIC);
}

