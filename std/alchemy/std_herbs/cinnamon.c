inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "cinnamon");
    set_long("This is a small paper packet containing some cinnamon. The bark of the cinnamon can be used crushed or powdered to help prevent infection and as a pain reliever when applied directly to the injury.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state >>= 5;
    current_state |= 8470;
    return current_state;
}
