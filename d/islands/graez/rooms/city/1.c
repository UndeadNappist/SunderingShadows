#include <std.h>
#include "../../graez.h"

inherit STORAGE"street.c";



void create(){
   ::create();
   set_long(::query_long()+"%^C058%^\nTo the south is a sprawling deep harbor dock.%^CRST%^\n");


set_exits(([
"east" : TOWN"2",
"south" : TOWN"dock",
"north" : TOWN"4",
"west" : TOWN"3",

]));

}

void reset(){
   ::reset();
   if(!present("ambiance device")){
      new(MOBS"harbor_ambiance.c")->move(TO);
   }
}

