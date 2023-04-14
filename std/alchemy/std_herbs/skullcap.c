rnherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "skullcap");
    set_long("This is a small paper packet containing some skullcap. The leaves of the skullcap can be used as an infusion to act as a mild sedative and to aid with sleep.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
