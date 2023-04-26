inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "saffron");
    set_long("This is a small paper packet containing some saffron. The stigma of the flower of the saffron can be used to help with circulation and soothe the nerves.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 10;
    current_state ^= 73;
    return current_state;
}
