
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "east" : FOR"25",

]));

}

void reset(){
   ::reset();
   if(!present("corpses")){
         new(OBJ"pile_of_corpses.c")->move(TO);
   }
}

