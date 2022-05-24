// Chernobog (5/20/22)
// Player Housing Item Storage

#include <std.h>
inherit BAG;

string filename;

void create(){
    ::create();
    set_name("storage");
    set_id(({"storage"}));
    set_short("storage");
    set_open_long("This is a large box meant to contain a miscellaneous collection of items.");
    set_closed_long(this_object()->query_open_long_desc()+"\nIt is currently closed.");
    set_max_internal_encumbrance(500);
    set_weight(1000000);
    set_value(0);
    set_property("no animate",1);
    set_possible_to_close(1);
    set_closed(1);
}

void setup_wardrobe(string location){
    filename = "/d/save/storage/"+location;
    "/daemon/yuck_d"->load_inventory(this_object(), filename);
}

int remove(){
    save_wardrobe();
    all_inventory(this_object())->remove();
    ::remove();
}

void save_wardrobe(){
    object storage = this_object();
    
    if(!objectp(storage)) return;
    if(!objectp(environment(storage))) return;

    mkdir("/d/save/storage");
    mkdir(filename);
    "/daemon/yuck_d"->save_inventory(storage, filename);
}

