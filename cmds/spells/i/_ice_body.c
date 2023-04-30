#include <std.h>
#include <magic.h>
inherit SPELL;

string ashort;

void effect(int direction)
{
    caster->set_property("poison immunity", direction);
    caster->set_property("disease immunity", direction);
    caster->set_property("no blind", direction);
    caster->set_resistance_percent("cold", 80 * direction);
    caster->set_resistance_percent("electricity", 50 * direction);
    caster->set_resistance_percent("fire", -50 * direction);

    return;
}

void create()
{
    ::create();
    set_spell_name("ice body");
    set_spell_level(([ "druid" : 8 ]));
    set_circle("winter");
    set_bonus_type("body");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS ice body");
    set_damage_desc("blind, disease, poison immune. 80% cold resistance");
    set_description("This spell transforms your body into living ice. You gain immunity to disease, poison and blindness. In addition, You gain 80% cold resistance, 50% electricity resistance and -50% fire resistance.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string(){
    tell_object(caster, "%^BOLD%^%^BLUE%^You wrap icy frost around you as you chant the spell.%^RESET%^");
    tell_room(place, "%^BOLD%^%^BLUE%^"+caster->QCN+"%^RESET%^%^CRST%^%^BOLD%^%^BLUE%^ wraps icy frost around " + caster->query_objective() + " as "+caster->QS+" chants the spell.%^RESET%^", caster);
    return "display";
}

void spell_effect()
{
    ashort = "%^C045%^(%^C027%^i%^C033%^c%^C027%^y s%^C033%^i%^C039%^l%^C045%^h%^C039%^o%^C033%^u%^C027%^ette%^C045%^)%^CRST%^";

    tell_object(caster, "%^C033%^As you finish the chant, your %^C045%^body%^C033%^ hardens with a t%^C039%^h%^C045%^i%^C033%^ck c%^C039%^a%^C045%^ra%^C039%^p%^C033%^ace of %^C051%^ice%^C033%^!%^CRST%^");
    tell_room(place, "%^C033%^As %^C045%^" + caster->query_cap_name() + "%^C033%^ finishes the chant, " + caster->query_possessive() + " %^C045%^body %^C033%^hardens with a thick %^C051%^carapice of ice%^C033%^!%^CRST%^", caster);

    effect(1);
    caster->set_property("added short", ({ ashort }));
    caster->set_property("spelled", ({ TO }));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect", spell_duration);
    addSpellToCaster();
    spell_successful();
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property_value("added short", ({ ashort }));
        tell_object(caster, "%^BOLD%^%^BLUE%^Your silhouette loses " + caster->query_possessive() + " icy appearance.%^RESET%^");
        tell_room(environment(caster), "%^BOLD%^%^BLUE%^" + caster->QCN + "%^RESET%^%^CRST%^%^BOLD%^%^BLUE%^'s silhouette loses its icy appearance.%^RESET%^", caster);
        effect(-1);
    }
    ::dest_effect();
    if (objectp(this_object())) {
        this_object()->remove();
    }
}
