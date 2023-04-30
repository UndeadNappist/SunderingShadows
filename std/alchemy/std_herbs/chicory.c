inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "chicory");
    set_long("This is a small paper packet containing some chicory. The fresh leaves of the chicory can be used as an infusion or tincture to cleanse and balance the urinary and digestive systems.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 3333;
    current_state |= 2020;
    return current_state;
}
