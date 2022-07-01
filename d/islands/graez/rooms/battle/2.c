
#include <std.h>
#include "../../graez.h"


inherit STORAGE"outerstreet.c";

void create() {
    ::create();



set_exits(([

"northeast" : ROOMS"3",
"north" : TOWN"21",
"south" : BATTLE"11",
"southeast" : ROOMS"12",
"southwest" : ROOMS"1",

]));


}
void reset(){
   ::reset();
   if(!present("ambiance device")){
      new(MOBS"poor_ambiance.c")->move(TO);
   }
}

