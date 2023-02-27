// Steppes - Outside

#include <std.h>
#include "../outpost.h"

inherit CROOM;

void create(){
   ::create();
    set_property("indoors",0);
    set_name("windswept steppes");
    set_short("%^C029%^windswept steppes%^CRST%^");
    set_long("%^C029%^All around you the %^C036%^windswept%^C029%^ ground "+
        "disappears to almost the horizon without end. To the north and west "+
        "rise %^C066%^massive mountains%^C029%^ and to the east the land extends. "+
        "The steppes are devoid of %^C100%^large trees%^C029%^ but you can see "+
        "there is an abundance of life here. %^C144%^taller tan grasses%^C029%^ "+
        "can be seen in the distance and around you here are clumps of %^C022%^darker "+
        "grass%^C029%^ grows in clumps around the %^C244%^rocks%^C029%^. High above "+
        "you %^C231%^seabirds%^C029%^ circle meaning you must be close to the %^C081%^water%^C029%^. "+
        "The air here is %^C081%^cold%^C029%^, as if the threat of %^C249%^Colddays%^C029%^ "+
        "is always just over the horizon.%^CRST%^\n");

    set_items(([
        ({"mountains"}) : "%^C247%^Far to the west and north extend the largest peaks of "+
        "the %^C058%^Dagger Mountains%^C247%^. The tops of them extend far above "+
        "the %^C250%^cloud line%^C247%^ and they are topped by a constant "+
        "topping of %^C255%^snow%^C247%^.%^CRST%^",
        ({"birds"}) : "%^C044%^Far far above you %^C066%^adult seabirds%^C044%^ circle. "+
        "With their wide wingspan they lazily spin and you wonder how long they can "+
        "stay up there.%^CRST%^",
        ({"rocks"}) : "%^C060%^Rocks jut out of the ground randomly here, "+
        "mostly %^C247%^granite%^C060%^ and %^C240%^slate%^C060%^. The effect of the "+
        "dark rock against the %^C081%^wide sky%^C060%^ is striking%^CRST%^",
        ({"grasses"}) : "%^C040%^The %^C028%^grass%^C040%^ around you is thick and hardy, "+
        "resistant to %^C081%^cold%^C040%^ and needing little %^C081%^water%^C040%^. In the "+
        "distance you can make out taller %^C143%^amber grasses%^C040%^ meaning there must "+
        "be some rivers or lake to the northeast.%^CRST%^",
    ]));  

set_smell("default","%^C059%^You smell %^C058%^earth%^C059%^ and %^C022%^grass%^CRST%^");
set_listen("default","%^C074%^You hear the cry of %^C145%^seabirds%^CRST%^");

}
