inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "yarrow");
    set_long("This is a small paper packet containing some yarrow. The leaves and flowers of the yarrow can be used as an infusion or tincture to prevent infection in cuts and scrapes.  If taken internally, it can act as a mild sedative and relaxer.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state <<= 9;
    current_state |= 21;
    return current_state;
}
