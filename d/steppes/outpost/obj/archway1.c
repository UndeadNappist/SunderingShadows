
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("A massive archway");
    set_id(({"gate","archway","massive archway","a massive archway"}));
    set_weight(1000000);
    set_short("%^C244%^massive stone archway%^CRST%^");
    set_long("%^C243%^This massive archway has been carved from some unknown %^C239%^dark rock%^C243%^. The rock itself is %^C248%^matte%^C243%^ and seems to refuse to reflect any %^C254%^light%^C243%^, instead sucking it itself. The whole of the archway is devoid of any markings. Instead of a door or gate, the archway seems to open to a solid wall of %^C239%^stone%^C243%^. You would have to%^C250%^ >push<%^C243%^ into the wall behind the archway to see what would happen.%^CRST%^\n");
    set_value(0);
    set_property("no animate",1);
}


void init() {
    ::init();
    add_action("push_fun","push");
}


int push_fun(string str,object who){
    object ob;
    
    if(!str) {
        tell_object(TP,"%^BLACK%^%^BOLD%^Push what, did you mean to >push against wall<?\n%^RESET%^");
        return 1;
    }
    
    if((str == "wall") || (str == "against wall") || (str == "against the wall")){
        tell_object(TP,"%^C095%^you reach out to push against the wall and get pushed into the solid rock!%^CRST%^");
        tell_room(ETP,""+TPQCN+" %^C095%^breathes in and pushes against the wall, disapearing into the rock!%^CRST%^",TP);
        TP->move("/d/steppes/outpost/storage/movie1");
        return 1;
    }

        tell_object(TP,"%^BLACK%^%^BOLD%^Push what, did you mean to >push against wall<?\n%^RESET%^");

    return 1;
}



