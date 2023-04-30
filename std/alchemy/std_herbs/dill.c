inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "dill");
    set_long("This is a small paper packet containing some dill. The seeds of the dill can be used as an infusion or ticture to fight infection and soothe stomach pains.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 48432;
    current_state >>= 2;
    return current_state;
}
