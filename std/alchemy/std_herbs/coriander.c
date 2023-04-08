inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "coriander");
    set_long("This is a small paper packet containing some coriander. The seeds of the coriander can be used as an infusion to help calm intestinal ailments when taken internally or to soothe muscle and joint pain when applied externally.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 6;
    current_state <<= 5;
    return current_state;
}
