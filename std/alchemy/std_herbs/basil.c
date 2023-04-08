inherit "/std/alchemy/std_herb/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some basil. The leaves of the basil can be used as an infusion or tincture to treat intestinal illnesses and promote a healthy immune system.");
    set("alchemical_id", "basil");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state /= 3;
    current_state |= 2840;
    return current_state;
}
