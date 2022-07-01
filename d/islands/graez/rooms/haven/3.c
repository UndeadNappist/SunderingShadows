
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"northeast" : HAVEN"2",
"west" : HAVEN"4",

]));

}
void reset(){
   ::reset();
   if(!present("statue")){
      new(OBJ"statue1.c")->move(TO);
   }
}

