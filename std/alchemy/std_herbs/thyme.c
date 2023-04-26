inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "thyme");
    set_long("This is a small paper packet containing some thyme. The leaves of the thyme can be used fresh or as an infusion to help fight and prevent bacteria and disease as well as aid digestion and prevent cramping.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state |= 10101;
    current_state <<= 3;
    return current_state;
}
