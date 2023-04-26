inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "clove");
    set_long("This is a small paper packet containing some clove. The seeds of the clove can be used as an oil or infusion to relieve toothaches or to help reduce fungal infections of the feet.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 7;
    current_state <<= 1;
    return current_state;
}
