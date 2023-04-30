inherit "/std/alchemy/std_herb/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some anise. The seeds of the anise can be used as an anfusion or tincture to treat a cough or provide relief from cramping.");
    set("alchemical_id", "anise");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 654;
    current_state ^= 1509;
    return current_state;
}
