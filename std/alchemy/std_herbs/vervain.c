inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "vervain");
    set_long("This is a small paper packet containing some vervain. The plant of the vervain can be used as an infusion or tincture to act as a pain killer for aches, pains, and headaches.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 4280;
    current_state |= 5764;
    return current_state;
}
