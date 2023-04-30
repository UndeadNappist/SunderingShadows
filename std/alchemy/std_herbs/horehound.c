inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "horehound");
    set_long("This is a small paper packet containing some horehound. The flowers of the horehound can be used as an infusion or tincture to act as a cough remedy and soothe chest pains.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
