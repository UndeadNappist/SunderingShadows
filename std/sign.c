//      /std/sign.c
//      from the Nightmare mudlib
//      an inheritable sign object
//      created by Hanse@Nightmare

#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
    set_property("no_clean", 1);
}

int get() { 
    if(query("get message")) write(query("get message"));
    return 0;
}

//void clean_up() { return; }
