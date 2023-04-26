rnherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "tea");
    set_long("This is a small paper packet containing some tea. The leaves of the tea can be used as an infusion to help with congestion, asthma, tooth decay, and to treat colds and other mild discomforts of illness.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state <<= 6;
    current_state |= 423;
    return current_state;
}
