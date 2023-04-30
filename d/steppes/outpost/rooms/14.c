

#include <std.h>
#include "../outpost.h"

inherit STORAGE"gates.c";


void create() {
   ::create();
   set_long(::query_long()+"\n%^C101%^To the east are the %^C071%^steppes%^C101%^.%^CRST%^\n"); 

set_exits(([
"north" : ROOMS"13",
"south" : ROOMS"16",
"east" : ROOMS"15",
"west" : ROOMS"17",


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

