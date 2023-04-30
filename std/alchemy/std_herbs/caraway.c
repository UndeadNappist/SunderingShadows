inherit "/std/alchemy/std_herbs/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some caraway. The seeds of the caraway can be used eaten fresh or as an infusion or tincture to soothe the digestive tract by expelling gas and to aid in treating cramping.");
    set("alchemical_id", "caraway");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 3;
    current_state ^= 8036;
    return current_state;
}
