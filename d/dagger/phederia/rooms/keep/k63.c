#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Short"
  );
  set_long(
  "Long"
  "\n"
  );
  set_smell("default",
  "Smell"
  );
  set_listen("default",
  "Listen"
  );
  set_items(([
  ]));
  set_exits(([
  "west":KEEP"k62.c",
  "east":KEEP"k64.c",
  ]));
}
