inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "mint");
    set_long("This is a small paper packet containing some mint. The leaves of the mint can be used as an infusion, tincture, or powder to help combat infection and sterilize a wound or to ease sinus and chest congestion when inhaled.  When chewed, it can also help fight morning sickness.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state ^= 3028;
    current_state &= 937;
    return current_state;
}
