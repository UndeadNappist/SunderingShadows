#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("mindfire");
    set_incubation("1 day");
    set_damage_desc("1d4 int");
    set_infection("inhaled");
    set_description("\n\nFeels like your brain is burning. Causes stupor.");

    set_property("inanimate bonus", 1);
    set_heart_beat(32);
}

int init_disease(int dc)
{
    ::init_disease(dc);
    next_step = ETO->query_age() + DAY;
}

advance_disease()
{
    int dmg = -roll_dice(stage, 4);

    next_step += DAY;

    if (do_save())
    {
        saved++;
        if (saved > 2) {
            TO->remove();
            return;
        }
        return;
    }
    saved = 0;

    set_item_bonus("intelligence",dmg);

    tell_object(ETO,"\n%^BOLD%^%^BLUE%^Your brain is burning with pain.%^RESET%^");

    stage++;

}

void heart_beat()
{
    object me, my_environment;

    if (!objectp(me = this_object()))
        return;

    if (!objectp(my_environment = environment(me)))
        return;

    if (!next_step)
        return;

    if (!my_environment->is_living())
        me->remove();

    if (my_environment->query_age() > next_step)
        advance_disease();

    return;
}
