rnherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "witch hazel");
    set_long("This is a small paper packet containing some witch hazel. The plant of the witch hazel can be used as an infusion or tincture to act as an antiseptic and to help soothe cuts, bruises, and sore muscles while relieving some of the pain.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
