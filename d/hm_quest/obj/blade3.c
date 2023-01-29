#include <std.h>
inherit OBJECT;

string owner;
int JOIN;

void create() {
    ::create();
    set_name("blade");
    set_id(({"blade3","hm_quest_bronze","bronze blade"}));
    set_short("%^RESET%^%^ORANGE%^Bronze blade%^RESET%^");
    set_long("%^RESET%^This long, straight blade is from a sword that has seen much use, %^RESET%^%^BLUE%^notched %^RESET%^and %^RESET%^%^ORANGE%^scarred %^RESET%^along its length. Despite "
"its impressive appearance, you suspect its days of use in combat are long since over, though its %^ORANGE%^bronze %^RESET%^surface still glows with a faintly magical aura. It has been detached "
"at the base, and you marvel at the being capable of %^RESET%^%^RED%^sundering %^RESET%^such a weapon. The narrowed heel of the blade would suggest you could still join it to a suitable hilt, "
"if you could find one.%^RESET%^");
    set_weight(5);
    set_value(0);
}

void init()
{
    ::init();
    
    if(!userp(this_player()))
        return;
    
    if(archp(this_player()))
        return;
    
    if(!strlen(owner))
        owner = this_player()->query_true_name();
    else
    {
        if(this_player()->query_true_name() != owner)
        {
            write("The blade vanishes!\n");
            this_object()->remove();
            return;
        }
    }
    add_action("join_fun", "join");
}

int join_fun(string str) {
    object hilt;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Join what to what?\n");
	return 0;
    }
    if(str != "hilt to blade" && str != "blade to hilt") {
      notify_fail("You can't join those.\n");
      return 0;
    }
    if(JOIN) {
	notify_fail("A suitable hilt is already attached to this blade!\n");
	return 0;
    }
    if(!hilt = present("hm_quest_brass",TP)) {
	notify_fail("You don't have a hilt suitable to attach to that blade!\n");
	return 0;
    }
    if(base_name(hilt) != "/d/hm_quest/obj/hilt3") {
	notify_fail("That hilt refuses to be attached to that blade!\n");
	return 0;
    }
    if(!(int)hilt->is_attached()) {
	notify_fail("You should try to put the hilt together properly first!\n");
	return 0;
    }
    tell_object(TP,"%^CYAN%^The magical energy around both the hilt and the blade flares brightly as they are brought together, and they settle perfectly into place, one joined to the other.%^RESET%^");
    JOIN = 1;
    hilt->remove();
    set_short("%^RESET%^%^ORANGE%^Bronze blade (hilt joined)%^RESET%^");
    set_long("%^RESET%^This long, straight blade is from a sword that has seen much use, %^RESET%^%^BLUE%^notched %^RESET%^and %^RESET%^%^ORANGE%^scarred %^RESET%^along its length. Despite "
"its impressive appearance, you suspect its days of use in combat are long since over, though its %^ORANGE%^bronze %^RESET%^surface still glows with a faintly magical aura. It has been attached "
"to a hilt of %^ORANGE%^brass%^RESET%^, set with a bone-shaped pommel. Certainly it could be sheathed to keep it protected from the elements, if one could be found to fit it.%^RESET%^");
    set_weight(9);
    return 1;
}

int is_joined() { return JOIN; }