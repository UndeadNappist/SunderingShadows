inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "juniper");
    set_long("This is a small paper packet containing some juniper. The berries of the juniper can be used as an infusion to aid with arthritis and improve circulation.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 1;
    current_state |= 127;
    return current_state;
}
