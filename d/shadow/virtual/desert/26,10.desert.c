#include <std.h>

inherit ROOM;

int is_virtual(){ return 1; }

void create(){
    ::create();
    set_terrain(DESERT);
    set_travel(FOOT_PATH);
    set_indoors(0);
    set_light(3);
    set_name("A vast desert");
    set_short("%^ORANGE%^You are in a vast desert.%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^You are in a vast desert.\n%^RESET%^In most directions, you see nothing but sand for miles.  Stone and timber have been piled here, the rudimentary beginnings of a wall beginning to take shape to the south.");
    set_exits(([
        "east":"/d/shadow/virtual/desert/26,11.desert",
        "west":"/d/shadow/virtual/desert/26,9.desert",
        "north":"/d/shadow/virtual/desert/25,10.desert",
        "south":"/d/shadow/virtual/desert/27,10.desert"
        ]));
    set_smell("default","The dry desert air fills your nostrils.");
    set_listen("default","You can hear the breeze blowing over the sand, it is so quiet here.");
    set_items(([
        ]));
}

query_weather(){ return "%^BOLD%^%^WHITE%^It is oppressively hot and dry.%^RESET%^"; }