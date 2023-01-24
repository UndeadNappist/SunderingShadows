//New illusion domain spell.  Based on the psion power Concealing
//Amorpha ~Circe~ 4/27/08 Rebalancing priest domains
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int reversed;

void create() {
    ::create();
    set_spell_name("displacement");
    set_spell_level(([ "bard" : 3, "mage" : 3, "magus" : 3, "cleric" : 3 ]));
    set_spell_sphere("illusion");
    set_domains(({ "illusion", "trickery" }));
    set_syntax("cast CLASS displacement");
    set_damage_desc("30% miss chance");
    set_description("Using the power of illusion, the caster calls forth a distortion of her form, making her harder to target with melee attacks. Unlike blink and blurred movement, this spell will work in armor, but it has reduced potency.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string(){
    return "%^RESET%^%^CRST%^%^C090%^As "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^ begins to chant, "+caster->query_possessive()+" form grows %^C165%^d%^C171%^i%^C177%^s%^C165%^t%^C171%^o%^C177%^r%^C165%^t%^C171%^e%^C177%^d%^RESET%^%^C090%^.%^CRST%^";
}

int preSpell(){
    if(caster->query_property("amorpha") || caster->query_property("timeless body")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already protected by a spell of concealment.%^CRST%^");
        return 0;
    }
    if (caster->query_blinking()){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You can't maintain such a spell while blinking.%^CRST%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    if(caster->query_property("amorpha")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already protected by a spell similar to this one.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    if((string)TO->query_spell_type() == "potion"){
        if(prof == -100){
            reverse_spell();
            return;
        }
        tell_object(caster, "%^RESET%^%^CRST%^%^C092%^As the potion warms your stomach, a soft vibration runs through your body and it becomes %^C165%^b%^C171%^l%^C177%^u%^C165%^r%^C171%^r%^C177%^e%^C165%^d%^RESET%^%^C092%^.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C092%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C092%^'s form grows suddenly %^C165%^b%^C171%^l%^C177%^u%^C165%^r%^C171%^r%^C177%^e%^C165%^d%^RESET%^%^C092%^.%^CRST%^", caster);
    }
    else{
        if((string)TO->query_spell_type() == "bard"){
            tell_object(caster, "%^RESET%^%^CRST%^%^C092%^You hum softly, using the vibrations in the air to %^C165%^b%^C171%^l%^C177%^u%^C165%^r %^RESET%^%^C092%^your appearance, making you harder to target!%^CRST%^");
        }
        else{
            tell_object(caster, "%^RESET%^%^CRST%^%^C092%^You feel the spell take hold to %^C165%^b%^C171%^l%^C177%^u%^C165%^r %^RESET%^%^C092%^your appearance, making you harder to target!%^CRST%^");
        }
        tell_room(place, "%^RESET%^%^CRST%^%^C092%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C092%^'s form grows %^C165%^b%^C171%^l%^C177%^u%^C165%^r%^C171%^r%^C177%^e%^C165%^d %^RESET%^%^C092%^as "+caster->query_subjective()+" completes "+caster->query_possessive()+" spell.%^CRST%^", caster);
    }
    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    caster->set_missChance(caster->query_missChance()+ 30); // 30% evasion
    caster->set_property("added short", ({"%^RESET%^%^CRST%^%^C092%^ (%^C090%^slightly %^C165%^d%^C171%^i%^C177%^s%^C165%^t%^C171%^o%^C177%^r%^C165%^t%^C171%^e%^C177%^d%^RESET%^%^C092%^)%^CRST%^"}));
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){
    int chance;

    if(objectp(caster)){
        if(reversed){
            tell_object(caster, "%^RESET%^%^CRST%^%^C092%^You feel your body return to normal as the potion wears off.%^CRST%^");
            tell_room(environment(caster), "%^RESET%^%^CRST%^%^C092%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C092%^ suddenly seems normal again.%^CRST%^", caster);
            caster->add_ac_bonus(5);    // restore their lost AC!
        }
        else{
            if((string) this_object()->query_spell_type() == "potion") {
                tell_object(caster, "%^RESET%^%^CRST%^%^C092%^You feel your body become more substantial as the potion wears off.%^CRST%^");
            }
            else{
                if((string) this_object()->query_spell_type() == "bard"){
                    tell_object(caster, "%^RESET%^%^CRST%^%^C092%^You feel your body become more substantial as your song's protection fades.%^CRST%^");
                }
                else{
                    tell_object(caster, "%^RESET%^%^CRST%^%^C092%^You feel your body become more substantial as your spell's protection fades.%^CRST%^");
                }
            }
            tell_room(environment(caster), "%^RESET%^%^CRST%^%^C092%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C092%^ suddenly seems more substantial as "+caster->QP+" skin loses its distortion.%^CRST%^", caster);
            chance = (int) caster->query_missChance() - 30;
            caster->set_missChance(chance);
            caster->remove_property_value("added short", ({"%^RESET%^%^CRST%^%^C092%^ (%^C090%^slightly %^C165%^d%^C171%^i%^C177%^s%^C165%^t%^C171%^o%^C177%^r%^C165%^t%^C171%^e%^C177%^d%^RESET%^%^C092%^)%^CRST%^"}));
        }
        caster->remove_property("amorpha");
    }
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

void reverse_spell(){
    // adding in backfires for potions! Can't find where lib actually calls this anymore.
    tell_object(caster,"%^MAGENTA%^A queasy feeling runs through you, and your movements become slow and deliberate.%^RESET%^");
    reversed = 1;
    caster->add_ac_bonus(-5); // restore their lost AC!
    spell_successful();
    caster->set_property("spelled", ({this_object()}) );
    caster->set_property("amorpha",1);
    call_out("dest_effect",(clevel*20));
}

