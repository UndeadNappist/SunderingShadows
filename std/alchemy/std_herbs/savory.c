inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "savory");
    set_long("This is a small paper packet containing some savory. The leaves of the savory can be used as an infusion to soothe and calm children when taken internally.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 6;
    current_state <<= 6;
    return current_state;
}
