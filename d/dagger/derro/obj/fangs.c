#include <std.h>
inherit WEAPON;


void create(){
    ::create();
	set_id(({"venum","fangs"}));
	set_name("fangs");
   	set_short("fangs");
   set_long("These are some mean looking fangs.");
     set_property("monsterweapon",1);
   set_weight(0);
   set_size(1);
   set("value", 0);
   set_wc(1,6);
   set_large_wc(1,4);
   set_type("piercing");
 add_poisoning(4);

}
