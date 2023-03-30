inherit "/std/alchemy/herb_inherit.c"

void create()
{
    set_name("packet of herbs");
    set_id(({ "herb", "herbs", "allspice", "packet", "packet of alfalfa" }));
    set_short("A paper packet of alfalfa");
    set_long("This is a small paper packet containing some alfalfa. The seeds of the alfalfa can be used to help keep the heart healthy and te blood flowing evenly.");
    set("alchemical_id", "alfalfa");
    set("base_value", 30);
}

int mutate_alchemical_state(int current_state)
{
    current_state = current_state << 2;
    current_state ^= 18;
    return current_state;
}
