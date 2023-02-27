// Dwarven Outpost - Empty Lot

#include <std.h>
#include "../outpost.h"

inherit CROOM;

void create(){
   ::create();
    set_property("indoors",0);
    set_name("ruin of a building");
    set_short("%^C059%^ruin of a %^C102%^building%^CRST%^");
    set_long("%^C102%^Centuries ago there must have been a %^C066%^small settlement%^C102%^ here. Time and some unknown act of %^C124%^violence%^C102%^ seemed to have laid it to almost the %^C240%^foundations%^C102%^. The ground here is recessed, as if there was a building here that was destroyed. The %^C058%^ground%^C102%^ is hard packed and nothing could grow here. The %^C238%^rocks%^C102%^ themselves are marred with pockmarks where %^C088%^fire%^C102%^ or %^C125%^explosions%^RESET%^%^C102%^ hit them and even the march of time could not hide all of them.%^CRST%^\n");
      
    set_items(([
        ({"rocks"}) : "%^C101%^The %^C242%^rocks%^C101%^ here are obviously ther ruins of the %^C060%^settlement%^C101%^ that was here. They are %^C246%^pockmarked%^C101%^ from some century's old %^C088%^violence%^C101%^.\n%^CRST%^",
        ({"ground"}) : "%^C100%^The %^C059%^ground%^C100%^ here is hard packed earth and nothing grows on it. As you look closer you realize that under a small layer of %^C150%^cold soil%^C100%^ are %^C242%^interlocking stones%^C100%^ forming a %^C059%^road%^C100%^.\n%^CRST%^",
    ]));

set_smell("default","%^C059%^You smell %^C058%^earth%^C059%^ and %^C022%^grass%^CRST%^");
set_listen("default","%^C074%^You hear the cry of %^C145%^seabirds%^CRST%^");


}
