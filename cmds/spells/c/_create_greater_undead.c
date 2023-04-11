#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/c/_create_undead";

void create()
{
    ::create();
    set_spell_name("create greater undead");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create greater undead");
    set_description("Animating dead is a pathetic craft for the weak. A true necromancer's art is to change what was into something more potent and powerful that can serve his fell desires and schemes. This spell uses a fallen corpse to make an undead creature from rotting flesh. Such a creature is more potent than lesser skeletons and zombies, and will serve the necromancer until discorporated. This spell, without a doubt, is evil."+extra_help());
    evil_spell(1);
    set_helpful_spell(1);
    set_arg_needed();
    set_property("undead spell", 1);
}

string extra_help(){
    return "\n\nEach lesser undead minion uses four pool slots out of a maximum pool size of twenty, and this resource is shared between all undead creation spells.\n%^ORANGE%^<dismiss undead>%^RESET%^ destroys your current undead retinue%^RESET%^\n%^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^ will command undead to perform an action%^RESET%^\n%^ORANGE%^<command undead to follow>%^RESET%^ forces lost undead to follow you%^RESET%^\n%^ORANGE%^<command undead to halt>%^RESET%^ forces the undead to stay in place\n%^ORANGE%^<poolsize>%^RESET%^ lists how many undead minions you have under your control%^RESET%^";
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^CYAN%^You cut your %^BOLD%^%^CYAN%^wrists and %^CYAN%^s%^BLACK%^i%^CYAN%^n%^CYAN%^g%^CYAN%^ low in %^CYAN%^f%^BLACK%^ell%^CYAN%^ tongues.%^RESET%^");
    return "%^BOLD%^%^CYAN%^" + caster->QCN + " cuts " + caster->QP + "%^BOLD%^%^CYAN%^wrists and %^CYAN%^s%^BLACK%^i%^CYAN%^n%^CYAN%^g%^BLACK%^s%^CYAN%^ low in %^CYAN%^f%^BLACK%^ell%^CYAN%^ tongues.%^RESET%^";
}

string undead_to_raise()
{
    return "skelemage";
}

void setup_undead_scaling(object undead)
{
    undead->set_level(clevel);
    undead->set_guild_level("mage", clevel);
    undead->set_mlevel("mage", clevel);
    undead->set_skill("spellcraft", clevel);
    undead->set_skill("perception", clevel - clevel / 10);
    undead->set_property("spell penetration", clevel / 10);
    undead->set_property("raised", 4);
    undead->set_hd(clevel, 8);
    undead->set_max_hp(clevel * 14 + 100);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(10 - clevel);
}
