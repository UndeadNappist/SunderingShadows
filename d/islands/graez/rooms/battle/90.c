#include "../../graez.h"

#include <std.h>
#include "../../graez.h"
inherit STORAGE"desert.c";
inherit CORE;

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"80",
"southwest" : ROOMS"89",


]));


}



void reset(){
   ::reset();
   if(!present("commander")){
      new(MOBS"undead_commander.c")->move(TO);
   }
      if(!present("monolith")){
      new(OBJ"monolith.c")->move(TO);
   }
}
