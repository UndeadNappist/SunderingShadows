inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "kelp");
    set_long("This is a small paper packet containing some kelp. The leaves of the kelp can be used as an infusion to fight infection when applied directly to a wound.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
