inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "ginger");
    set_long("This is a small paper packet containing some ginger. The roots of the ginger can be used fresh or as an infusion or tincture to aid with morning sickness and other digestive symptoms as well as to help with arthritis and improve circulation.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 8;
    current_state <<= 7;
    return current_state;
}
