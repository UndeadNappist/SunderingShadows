inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "red pepper");
    set_long("This is a small paper packet containing some red pepper. The pepper of the red pepper can be used fresh or as an infusion to help soothe chronic pain when applied externally or to help with headaches and aid digestion when taken internally.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
