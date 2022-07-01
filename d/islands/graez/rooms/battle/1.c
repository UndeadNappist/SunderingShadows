
#include <std.h>
#include "../../graez.h"

inherit STORAGE"warehouse.c";

void create() {
    ::create();



set_exits(([

"northeast" : ROOMS"2",
"southeast" : ROOMS"11",

]));


}



void reset(){
   ::reset();
   if(!present("Commander Ashton")){
new(MOBS"human_commander.c")->move(TO);

   }
}
