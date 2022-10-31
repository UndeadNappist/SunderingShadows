
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"northwest" : SWAM"17",
"east" : "/d/dagger/nurval/room/tomb1",


]));

}

void reset()
{
    ::reset();
    if (!present("guard"))
        new("/d/dagger/nurval/mon/necroknight")->move(TO);
    if (!present("guard 2"))
        new("/d/dagger/nurval/mon/necroknight")->move(TO);
    if (!present("guard 3"))
        new("/d/dagger/nurval/mon/necroknight")->move(TO);
    if (!present("banshee"))
        new("/d/dagger/nurval/mon/banshee")->move(TO);
    if (!present("banshee 2"))
        new("/d/dagger/nurval/mon/banshee")->move(TO);
    if (!present("bonewyvern"))
        new("/d/dagger/nurval/mon/bonewyvern")->move(TO);
}

