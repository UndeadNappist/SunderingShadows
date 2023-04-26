inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "tobacco");
    set_long("This is a small paper packet containing some tobacco. The leaves of the tobacco can be used dried, and then smoked or chewed as a strong stimulant, although it is known to have addictive qualities.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 5380;
    current_state <<= 2;
    return current_state;
}
