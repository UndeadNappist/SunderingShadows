inherit "/std/alchemy/std_herb/std_herb_inherit.c"

void create()
{
    set_long("This is a small paper packet containing some alfalfa. The seeds of the alfalfa can be used to help keep the heart healthy and te blood flowing evenly.");
    set("alchemical_id", "alfalfa");
    set("base_value", 30);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state <<= 2;
    current_state ^= 18;
    return current_state;
}
