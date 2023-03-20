#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("cackle fever");
    set_incubation("1 day");
    set_damage_desc("1d6 wis");
    set_infection("inhaled");
    set_description("\n\nSymptoms include high fever, disorientation, and frequent bouts of hideous laughter. Also known as the shieks.");

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
    int dmg = -roll_dice(stage, 6);

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

    tell_object(ETO,"\n%^BOLD%^%^BLUE%^Your burst out in sudden laughter.%^RESET%^");
    tell_room(EETO, "%^ORANGE%^" + ETO->QCN + " bursts out in sudden laughter!%^RESET%^", ETO);

    stage++;

}

void heart_beat()
{
    if (!objectp(this_object()))
        return;

    if(!objectp(environment(this_object())))
        return;

    if (!next_step)
        return;

    if (!environment(this_object())->is_living())
        this_object()->remove();

    if (environment(this_object())->query_age() > next_step)
        advance_disease();

    if (stage > 1)
    {
        if (!random(120))
        {
            tell_object(environment(this_object()), "\n%^BOLD%^%^BLUE%^Your burst out in sudden laughter.%^RESET%^");

            if (objectp(environment(environment(this_object()))))
                tell_room(environment(environment(this_object())), "%^ORANGE%^" + environment(this_object())->query_cap_name() + " bursts out in sudden laughter!%^RESET%^", environment(this_object()));
        }
    }

    return;
}
