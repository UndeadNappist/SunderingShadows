inherit "/std/alchemy/std_herb/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some bay. The fresh leaves of the bay can be used as an infusion or tincture to soothe sore joins and treat infections as well as aid in relaxation.");
    set("alchemical_id", "bay");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 7394;
    current_state ^= 863;
    return current_state;
}
