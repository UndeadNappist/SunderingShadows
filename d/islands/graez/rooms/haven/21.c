
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();
   set_name("inside a small building");
   set_short("%^C058%^inside a small %^C244%^desolate%^C058%^ building%^CRST%^");
   
   
   set_property("indoors",1);
   set_long(::query_long()+"\nThis %^C059%^building%^CRST%^ looks like it was going to be a %^C151%^shop%^CRST%^, with %^C094%^empty shelves%^CRST%^ freshly made and ready for products.\n");


set_exits(([
"west" : HAVEN"5",
"south" : HAVEN"4",

]));

}
void reset(){
   ::reset();
   if(!present("statue")){
      new(OBJ"statue3.c")->move(TO);
   }
}

