
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();
   set_long(::query_long()+"\nA %^C060%^small building%^CRST%^ sits to the north..\n");


set_exits(([
"east" : HAVEN"3",
"northwest" : HAVEN"5",
"north" : HAVEN"21",

]));

}

