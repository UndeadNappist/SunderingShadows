#include <std.h>
inherit OBJECT;

string owner;

void create() {
    ::create();
    set_name("emerald");
    set_id(({"gem2","hm_quest_emerald","emerald"}));
    set_short("%^RESET%^%^GREEN%^A brilliant emerald%^RESET%^");
    set_long("%^RESET%^This large %^GREEN%^emerald %^RESET%^gemstone certainly appears to be worth a bit of money. It has been cut to display its upper facets to best effect, and seems to "
"%^BOLD%^%^WHITE%^glow %^RESET%^with a faint magical light from within. Its underside is slightly %^BOLD%^%^BLACK%^scratched%^RESET%^, leaving you to think you could insert it into the right "
"setting.%^RESET%^");
    set_weight(2);
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
            write("The emerald vanishes!\n");
            this_object()->remove();
        }
    }
}