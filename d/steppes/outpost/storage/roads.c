// Dwarven Outpost - Roads

#include <std.h>
#include "../outpost.h"

inherit CROOM;

void create(){
   ::create();
    set_property("indoors",0);
    set_name("ruined road");
    set_short("%^C059%^quiet %^C102%^road%^CRST%^");
    set_long("%^C102%^Centuries ago there must have been a %^C066%^small settlement%^C102%^ here. The road here is formed of interlocking stones that must have been placed centuries ago. There is some damage here and there but someone has been careful to clear away any debris.%^CRST%^\n");
      
    set_items(([
        ({"rocks"}) : "%^C101%^The %^C242%^rocks%^C101%^ here are obviously ther ruins of the %^C060%^settlement%^C101%^ that was here. They are %^C246%^pockmarked%^C101%^ from some century's old %^C088%^violence%^C101%^.\n%^CRST%^",
        ({"ground"}) : "%^C100%^The %^C059%^ground%^C100%^ here is formed of small interlocking stones that while ancient in their placement are still mostly perfect. Some damage had been done to parts but overall this is a serviceable %^C059%^road%^C100%^.\n%^CRST%^",
    ]));

set_smell("default","%^C059%^You smell %^C058%^earth%^C059%^ and %^C022%^grass%^CRST%^");
set_listen("default","%^C074%^You hear the cry of %^C145%^seabirds%^CRST%^");


}
