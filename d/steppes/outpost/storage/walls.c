// Dwarven Outpost - Walls

#include <std.h>
#include "../outpost.h"

inherit CROOM;

void create(){
   ::create();
    set_property("indoors",0);
    set_name("ruined walls");
    set_short("%^C059%^partially rebuilt %^C102%^walls%^CRST%^");
    set_long("%^C102%^Centuries ago there must have been a %^C066%^small settlement%^C102%^ here and it seems that someone has put significant work into starting to rebuild it. Instead of a proper constructed wall debris has been piled up and reinforced where it can be to form some protection. On the inside of the wall lanterns have been hung to illuminate and small openings have been made to allow some light to bathe out to the steppes. The ground is hard packed with the footsteps of soldiers.%^CRST%^\n");

      
    set_items(([
        ({"rocks"}) : "%^C101%^The %^C242%^rocks%^C101%^ here are obviously ther ruins of the %^C060%^settlement%^C101%^ that was here. They are %^C246%^pockmarked%^C101%^ from some century's old %^C088%^violence%^C101%^.\n%^CRST%^",
        ({"ground"}) : "%^C100%^The %^C059%^ground%^C100%^ here is hard packed earth and nothing grows on it. As you look closer you realize that under a small layer of %^C150%^cold soil%^C100%^ are %^C242%^interlocking stones%^C100%^ forming a %^C059%^road%^C100%^.\n%^CRST%^",
        ({"walls"}) : "%^C059%^Standing here you can see %^C094%^walls%^C059%^ protected the %^C060%^settlement%^C059%^. Most of the wall has been destroyed though some effort has been made to rebuild portions with rubble.\n%^CRST%^",
    ]));

set_smell("default","%^C059%^You smell %^C058%^earth%^C059%^ and %^C022%^grass%^CRST%^");
set_listen("default","%^C074%^You hear the cry of %^C145%^seabirds%^CRST%^");


}
