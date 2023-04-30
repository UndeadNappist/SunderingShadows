inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "feverfew");
    set_long("This is a small paper packet containing some feverfew. The leaves of the feverfew can be used fresh or as a powder to help with headaches.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state <<= 3;
    current_state |= 149;
    return current_state;
}
