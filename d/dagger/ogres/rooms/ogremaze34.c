
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "northeast" : ROOMS"ogremaze33",
       "east" : ROOMS"ogremaze39",
       "west" : ROOMS"ogremaze35",
   ]));

}