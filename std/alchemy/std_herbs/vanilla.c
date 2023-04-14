rnherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "vanilla");
    set_long("This is a small paper packet containing some vanilla. The seeds of the vanilla can be used as an infusion to aid with various stomach ailments. It is also highly prized for its flavor in cooking.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
