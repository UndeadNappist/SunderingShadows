inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "sage");
    set_long("This is a small paper packet containing some sage. The leaves of the sage can be used fresh, or as an infusion, tincture, or powder to fight infection, help preserve foods and drinks, and aid with sore throats.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 4095;
    current_state <<= 8;
    return current_state;
}
