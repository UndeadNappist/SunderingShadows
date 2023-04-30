rnherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "tarragon");
    set_long("This is a small paper packet containing some tarragon. The leaves of the tarragon can be used fresh to function as a mild anesthetic to prevent infections.  It can also help relieve toothaches when chewed.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
