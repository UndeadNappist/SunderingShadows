
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"north" : HAVEN"18",
"east" : HAVEN"1",
"southwest" : HAVEN"3",

]));

}
void reset(){
   ::reset();
   if(!present("statue")){
      new(OBJ"statue1.c")->move(TO);
   }
}

