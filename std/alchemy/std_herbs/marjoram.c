inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "marjoram");
    set_long("This is a small paper packet containing some marjoram. The flowers of the marjoram can be used as a powder to aid with digestion by relieving the feeling of bloating.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state ^= 707;
    current_state |= 304;
    return current_state;
}
