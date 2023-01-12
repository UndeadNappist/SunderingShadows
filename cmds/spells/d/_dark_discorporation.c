#include <spell.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("dark discorporation");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS dark discorporation");
    set_description("By using this invocation, the warlock dissipates into a hazy mist, only vaguely retaining his or her prior form. By this means he or she can avoid taking as much damage from physical attacks, and becomes immune to most standard poisons. This invocation does not function in conjunction with the 'stoneskin' or 'iron body' spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_stoneSkinned() || caster->query_property("iron body")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You already have protection of this nature!%^CRST%^");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster, "%^RESET%^%^CRST%^%^C243%^You raise both arms, attuning yourself with the %^C051%^p%^C045%^la%^C039%^n%^C051%^a%^C045%^r e%^C039%^n%^C051%^e%^C045%^rg%^C039%^i%^C051%^e%^C045%^s %^RESET%^%^C243%^of the area.%^CRST%^");
    tell_room(place, "%^RESET%^%^%^CRST%^%^C243%^"+caster->QCN+"%^RESET%^%^%^CRST%^%^C243%^ raises both arms and murmurs an invocation.%^CRST%^", caster);
    return "display";
}

void spell_effect(int prof) {
    ::spell_effect();
    tell_object(caster, "%^RESET%^%^CRST%^%^C023%^Your body grows %^C039%^l%^C045%^i%^C051%^g%^C045%^h%^C039%^t %^RESET%^%^C023%^as it dissipates into a %^C243%^h%^C246%^a%^C247%^z%^C243%^y %^C245%^m%^C247%^i%^C243%^s%^C245%^t%^RESET%^%^C023%^.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C023%^As you watch, "+caster->QCN+"%^RESET%^%^CRST%^%^C023%^'s body dissipates into a %^C243%^h%^C246%^a%^C247%^z%^C243%^y %^C245%^m%^C247%^i%^C243%^s%^C245%^t%^RESET%^%^C023%^.%^CRST%^", caster);
    caster->set_property("spelled",({TO}));
    caster->set_property("iron body",1);
    caster->set_property("damage resistance",15);
    caster->set_property("poison immunity",1);
    caster->set_property("added short",({"%^RESET%^%^CRST%^%^C035%^ (%^C023%^%^is a %^C243%^h%^C245%^a%^C247%^z%^C243%^y %^C023%^silhouette%^RESET%^%^C035%^)%^CRST%^"}));
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 1800;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (!objectp(caster)) {
        if(objectp(TO)) TO->remove();
        return;
    }
    tell_object(caster, "%^RESET%^%^CRST%^%^C023%^Your body %^C035%^re-solidifies %^C023%^and grows heavy once more.%^CRST%^");
    tell_room(environment(caster), "%^RESET%^%^CRST%^%^C023%^"+caster->QCN+"%^RESET%^%^CRST%^%^C023%^'s body %^C035%^re-solidifies %^C023%^before your eyes.%^CRST%^",caster);
    caster->set_property("damage resistance",-15);
    caster->set_property("poison immunity",-1);
    caster->set_property("iron body",-1);
    caster->remove_property_value("spelled", ({TO}) );
    caster->remove_property_value("added short",({"%^RESET%^%^CRST%^%^C035%^ (%^C023%^%^is a %^C243%^h%^C245%^a%^C247%^z%^C243%^y %^C023%^silhouette%^RESET%^%^C035%^)%^CRST%^"}));
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

