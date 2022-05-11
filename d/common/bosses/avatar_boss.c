#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit WEAPONLESS;

void create()
{
    ::create();
    set_property("no death", 1);
    set_property("no fear", 1);
    set_property("no bows", 1);
    set_property("no knockdown", 1);
    set_property("no trip", 1);
    set_property("no tripped", 1);
    set_property("no steal", 1);
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("confusion_immunity", 1);
    set_property("hidden inventory", 1);
    set_property("cast and attack", 1);
    set_property("function and attack", 1);
}

void init()
{
    ::init();
}

