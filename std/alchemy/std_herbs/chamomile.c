inherit "/std/alchemy/std_herb/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some chamomile. The flowers of the chamomile can be used as an infusion to treat wounds and inflammations or as a sedative.");
    set("alchemical_id", "chamomile");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state =<< 7;
    current_state += 468;
    return current_state;
}
