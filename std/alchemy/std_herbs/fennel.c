inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "fennel");
    set_long("This is a small paper packet containing some fennel. The seeds of the fennel can be used as an infusion or tincture to soothe stomach cramps.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state ^= 2020;
    current_state |= 9163;
    return current_state;
}
