inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("greater shadow conjuration");
    set_spell_level(([ "mage" : 7, "innate":7]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS greater shadow conjuration on SPELL_NAME [on SPELL_ARGS]");
    set_description("You create an illusory version of a conjuration spell of 6th level or lower. The source of the illusion can differ based on the caster.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage greater shadow conjuration on conjure elemental fire>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "conjuration_summoning";
}
