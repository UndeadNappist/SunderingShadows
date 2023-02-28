

#include <std.h>
#include "../outpost.h"

inherit STORAGE"roads.c";


void create() {
   ::create();
   set_long(::query_long()+"\n%^C101%^This must have been the centre of the city. The %^C060%^roads%^C101%^ extend north, east, south and west of here and you can survey most of the area from this vantage point.%^CRST%^\n");


set_exits(([
"west" : ROOMS"26",
"east" : ROOMS"34",
"south" : ROOMS"32",
"north" : ROOMS"33",

]));

}

