rnherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "valerian");
    set_long("This is a small paper packet containing some valerian. The roots of the valerian can be used as an infusion or tincture to act as a mild sedative or tranquilizer.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
