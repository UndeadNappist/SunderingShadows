#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(1);
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);

    set_exits( ([
      "south" : "/d/dagger/cave2/cave9",
      "east" : "/d/dagger/cave2/cave11",
    ]) );
}

void init() {
    ::init();
}

void reset(){
    ::reset();

}
