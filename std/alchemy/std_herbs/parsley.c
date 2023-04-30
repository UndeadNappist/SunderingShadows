inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "parsley");
    set_long("This is a small paper packet containing some parsley. The leaves of the parsley can be used fresh, powered, as an infusion, or as a tincture to help lower fever and cool the blood.  When chewed, it can also act as a breath freshener and fight allergies.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state = 1;
    current_state = 127;
    return current_state;
}
