inherit "/std/alchemy/std_herb/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some allspice. The seeds of the allspice can be used as an oil or infusion as digestive aid or pain reliever.");
    set("alchemical_id", "allspice");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state <<= 4;
    current_state &= 49;
    return current_state;
}
