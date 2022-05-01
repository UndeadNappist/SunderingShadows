// Chernobog & Titania (2/25/22)
// The Wailing Isle - Fence Inventory

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit "/std/obj/fence_store_epic";

void create(){
    ::create();
    set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set("short","thief storage");
    set("long","If you're here you shouldn't be.");
}

void reset(){
    object ob, storage;
    
    ::reset();
    
    storage = this_object();
    if(!present("smokebomb")) {
        ob = new("/d/tharis/obj/smokebomb");
        ob->move(storage);
        ob->set_origin("wailing");
    }
    while(!present("garrote 3")) new(OBJ"garrote")->move(storage);
}

