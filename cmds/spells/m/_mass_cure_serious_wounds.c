#include <std.h>

inherit "/cmds/spells/m/_mass_heal";

void create() {
    ::create();
    set_author("ares");
    set_spell_name("mass cure serious wounds");
    set_spell_level(([ "cleric" : 7,"druid" : 8 ]));
    set_domains(({}));
    set_mystery(({}));
    set_affixed_spell_level(4);
    set_spell_sphere("healing");
    set_syntax("cast CLASS mass cure serious wounds on TARGET");
    set_description("This is a stronger version of the cleric spell, cure serious wounds.  When cast on the caster or any party member, are present in the area.  When cast on a hostile attacker, it will hit all hostiles in the immediate area, healing those that are living, and hurting those that are undead.  When cast on a neutral creature that is neither in the caster's party or hostile to the caster, it will hit all creatures in the area, healing those that are living and hurting those that are undead.");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    set_target_required(1);
	set_helpful_spell(1);
}
