inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "myrrha");
    set_long("This is a small paper packet containing some myrrha. The leaves of the myrrha can be used as a powder, infusion, or tincture to help fight bacteria in the mouth or gums.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 6;
    current_state ^= 7873;
    return current_state;
}
