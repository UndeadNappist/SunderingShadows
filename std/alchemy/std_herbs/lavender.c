inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "lavender");
    set_long("This is a small paper packet containing some lavender. The flowers of the lavender can be used fresh usually in bath water to reduce stress and provide calm when inhaled.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state |= 263;
    current_state << 2;
    return current_state;
}
