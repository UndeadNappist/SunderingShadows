#include <std.h>
#include "../../serakii.h"

inherit STORAGE"trade_road.c";



void create(){
   ::create();
   set_long(::query_long()+"\n%^C060%^An impressive building that looks like a %^C094%^tavern%^C060%^ stands to the northeast.%^CRST%^\n");


set_exits(([

"northeast" : INN"1",
"north" : ROAD"2",
"southwest" : ROAD"3",
"southeast" : ROAD"4",
"tent" : "/realms/loki/events/serakii_benefit/rooms/tent",


]));

}
