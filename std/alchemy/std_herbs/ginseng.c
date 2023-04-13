inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "ginseng");
    set_long("This is a small paper packet containing some ginseng. The mature roots of the ginseng can be used as a powder to improve the body's resistances and boost the immune system.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
