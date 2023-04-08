inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "dandelion");
    set_long("This is a small paper packet containing some dandelion. The fresh leaves of the dandelion can be used as an infusion or tincture to help with weight loss and as a digestive aid.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state ^= 9210;
    current_state <<= 2;
    return current_state;
}
