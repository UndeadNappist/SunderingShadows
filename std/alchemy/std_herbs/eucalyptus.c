inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "eucalyptus");
    set_long("This is a small paper packet containing some eucalyptus. The type of the eucalyptus can be used as an oil or tincture to loosen phlegm and ease chest pain while opening sinuses.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 101;
    current_state <<= 7;
    return current_state;
}
