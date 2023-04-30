inherit "/std/alchemy/std_herbs/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some catnip. The leaves and flowers of the catnip can be used as an infusion to relieve chest congestion and lessen phlegm.");
    set("alchemical_id", "catnip");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state |= 500;
    current_state &= 37;
    return current_state;
}
