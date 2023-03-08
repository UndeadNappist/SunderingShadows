

#include <std.h>
#include "../outpost.h"

inherit STORAGE"gates.c";


void create() {
   ::create();
   set_long(::query_long()+"\n%^C101%^To the south you can almost see the %^C075%^shore%^C101%^, there is a lot of %^C241%^rubble%^C101%^ blocking the way though and you cant tell if there is a %^C094%^dock%^C101%^ there at all%^CRST%^\n");

set_exits(([
"north" : ROOMS"21",
"west" : ROOMS"22",
"east" : ROOMS"19",



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

