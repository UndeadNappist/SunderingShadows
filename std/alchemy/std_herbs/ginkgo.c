inherit "/std/alchemy/std_herbs/herb_inherit.c";

void create()
{
    set("alchemical_id", "ginkgo");
    set_long("This is a small paper packet containing some ginkgo. The leaves of the ginkgo can be used fresh or as an infusion to help improve memory and aid ailments such as blindness or deafness.");
    set("base_value", 35);

    ::create();
}

int mutate_alchemical_state(int current_state)
{
    current_state &= 1337;
    current_state |= 82;
    return current_state;
}
