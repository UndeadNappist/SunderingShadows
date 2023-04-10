inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "garlic");
    set_long("This is a small paper packet containing some garlic. The cloves of the garlic can be used fresh or as an infusion or ticture as a cure all or a preventative.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state |= 40292;
    current_state >>= 4;
    return current_state;
}
