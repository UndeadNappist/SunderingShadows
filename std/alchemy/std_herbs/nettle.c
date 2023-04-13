inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "nettle");
    set_long("This is a small paper packet containing some nettle. The plant of the nettle can be used as an infusion or tincture to help prevent hay fever and allergies when taken regularly.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
