

#include <std.h>
#include "../outpost.h"

inherit STORAGE"gates.c";


void create() {
   ::create();
   set_long(::query_long()+"\n%^C101%^To the west you can make out a large %^C239%^archway%^CRST%^\n");

set_exits(([
"west" : ROOMS"2",
"north" : ROOMS"4",
"south" : ROOMS"6",
"east" : ROOMS"5",

]));

}

