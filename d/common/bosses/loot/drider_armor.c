#include <std.h>

inherit "/d/common/obj/armour/banded.c";

string owner;

void create()
{
    ::create();
    set_name("Arachnid's Embrace");
    set_id(({ "body armor", "armor", "banded", "drider armor", "arachnids embrace", "embrace" }));
    set_short("%^C233%^Arachnid's %^C124%^Embrace%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^Banded armor with protruding spider legs%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This suit of body armor is made of plates of a strange metal, banded together with thick leather.  All pieces of it fit perfectly together and allow completely free movement. Spiderweb designs cover the armor, almost seeming to extend outward slightly from the actual armor.  Eight legs are curled up in a mass on the back of the armor, seeming ready to unfurl. As you pay closer attention to the web design you realize it is real web, enchanted to sit on the armor permanently.%^RESET%^\n");
    set_value(150000);
    set_lore("%^C233%^This armor has been rumored to have been from a matriarch drow in the underdark. It helped her gain immense power within her house, however, when she disappeared on an envoy mission, supposedly she was assassinated - it was seemingly lost forever.%^RESET%^");
    set_property("no curse", 1);
    set_property("enchantment", 7);
    set_item_bonus("wisdom", 6);
    set_item_bonus("bonus_spell_slots",2);
	set_flag_required("boss avatar");
    set_wear((: TO, "wear_func" :));
    set_remove((: TO, "remove_func" :));
    set_flag_required("boss avatar");    
    set_heart_beat(1);
}

int wear_func()
{
	tell_room(EETO, "%^BOLD%^%^BLACK%^The spider legs on the armor lifts " + ETO->QCN + " off the grorund as they wear it and then retract into place eerily.%^RESET%^", ETO);
    tell_object(ETO,"%^C233%^You can feel the nature of the armor fill you as you slip on the armor.%^RESET%^");
    return 1;
}

int remove_func()
{

    tell_object(ETO,"%^C233%^Taking off the armor leaves you feeling vulnerable and in need of your companion.%^RESET%^");
    return 1;
}

int query_size()
{
    if (living(ETO)) {
        return ETO->query_size();
    }else {
        return 1;
    }
}

int strikeme(int damage, object what, object who){
    if(random(1000) < 50){
        tell_room(environment(query_worn()),"%^C231%^As a blow lands on "+ETOQCN+"%^C231%^'s armor you see it react and spew thick web at "+who->QCN+"%^C231%^!%^CRST%^",({ETO,who}));
        tell_object(ETO,"%^C231%^You see the arms rear up and spew thick webbing and "+who->QCN+"%^C059%^ is covered in web!%^CRST%^");
        tell_object(who,"%^C231%^You are covered in a thick web from "+ETOQCN+"%^C059%^'s armor!");
        who->set_paralyzed(1,"%^C231%^You are wrapped in sticky web!%^CRST%^");
    }
    return damage;
}
