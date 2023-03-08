

#include <std.h>
#include "../outpost.h"

inherit STORAGE"gates.c";


void create() {
   ::create();
   set_long(::query_long()+"\n%^C101%^To the north is the entrance to what looks like a %^C102%^shuttered mine%^C101%^. The way is blocked by %^C241%^rubble%^C101%^ too large for you to move now.%^CRST%^\n");


set_exits(([
"east" : ROOMS"11",
"west" : ROOMS"8",
"south" : ROOMS"10",


]));

}
void reset()
{
	::reset();
	if(!present("soldier"))
	{
           new(MOBS"dwarf_soldier")->move(TO);
	}
}

