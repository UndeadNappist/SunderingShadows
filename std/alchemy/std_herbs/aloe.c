inherit "/std/alchemy/std_herb/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some aloe. The cut leaves of the aloe can be used directly on burns or scrapes to soothe pain and prevent infection.");
    set("alchemical_id", "aloe");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 1;
    current_state |= 127;
    return current_state;
}
