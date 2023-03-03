

#include <std.h>
#include "../outpost.h"

inherit STORAGE"roads.c";


void create() {
   ::create();
   set_long(::query_long()+"\n%^C101%^This must have been the centre of the city. The %^C060%^roads%^C101%^ extend north, east, south and west of here and you can survey most of the area from this vantage point.%^CRST%^\n");


set_exits(([
"west" : ROOMS"26",
"east" : ROOMS"34",
"south" : ROOMS"32",
"north" : ROOMS"33",

]));

}

void reset() {
  object ob;
  ::reset();
  if (!objectp(present(getuid(TO)+"_board"))) {
     ob = new("std/bboard");
     ob->set_name(getuid(TO)+"board");
     ob->set_id( ({ "board", getuid(TO)+"_board", "my board" }) );
     ob->set_board_id("steppe board");
     ob->set("short", "%^C058%^A stout %^C094%^wooden %^C058%^board%^CRST%^");
     ob->set("long", "%^C094%^Installed in the centre of the settlement, stout %^C058%^oak boards%^C094%^ support a board with notices %^C240%^nailed %^C094%^to it.%^CRST%^\n");
     ob->set_max_posts(20);
     ob->set_location(base_name(TO));
     ob->move(TO);
     ob->set_property("no steal",1);

}

}

