#include <std.h>
#include <magic.h>
inherit SPELL;

string ashort;
int cond_test=0;
int lastattack;

void effect(int direction)
{
    if(direction>0)
    {
        caster->set_property("flying",1);
        caster->set_property("angelic_aspect",1);
    }
    else
    {
        caster->set_property("flying", -1);
        caster->remove_property("angelic_aspect");

    }

    caster->add_ac_bonus(2*direction);
    caster->set_property("endurance",(clevel/10)*direction);
    caster->set_resistance("cold",10*direction);
    caster->set_resistance("acid",10*direction);

    return;
}

void create(){
    ::create();
    set_spell_name("angelic aspect");
    set_spell_level(([ "cleric" : 5, "paladin" : 3, "mage" : 5, "magus" : 5 ]));
    set_spell_sphere("alteration");
    set_bonus_type("deflection");
    set_syntax("cast CLASS angelic aspect");
    set_damage_desc("levitating, AC2, 10 DR to Acid and Cold");
    set_description("You take on an aspect of an angelic being, including some of its physical characteristics.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    /*
    if(caster->query_property("angelic_aspect"))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You're already infused with this aspect.%^RESET%^");
        return 0;
    }
    */
    return 1;
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" raises above the ground as "+caster->QS+" chants the spell.";
}

void spell_effect()
{
    string wing_color;
    int align = caster->query_true_align();

    ashort = " %^CRST%^%^RESET%^%^C153%^(%^C152%^trailed by %^C188%^f%^C189%^e%^C195%^athe%^C189%^r%^C188%^y %^C188%^w%^C189%^h%^C195%^ite %^C188%^w%^C189%^i%^C195%^ngs%^C153%^)%^CRST%^";
	wing_color = "%^C188%^f%^C189%^e%^C195%^athe%^C189%^r%^C188%^y %^C188%^w%^C189%^i%^C195%^ngs";

    if( align == 2 || align == 5 || align == 8){
        ashort = " %^RESET%^%^C117%^(%^C111%^trailed by %^C110%^e%^C116%^t%^C115%^h%^C109%^e%^C110%^r%^C116%^e%^C117%^a%^C111%^l %^C110%^w%^C116%^i%^C115%^n%^C109%^g%^C110%^s%^RESET%^%^C117%^)%^CRST%^";
        wing_color = "%^CRST%^%^C110%^e%^C116%^t%^C115%^h%^C109%^e%^C110%^r%^C116%^e%^C117%^a%^C111%^l %^C110%^w%^C116%^i%^C115%^n%^C109%^g%^C110%^s%^RESET%^";
    }
	
    else if(!(align%3)){
        ashort = " %^CRST%^%^RESET%^%^C243%^(%^C060%^trailed by %^C061%^f%^C060%^e%^C059%^athe%^C060%^r%^C061%^y %^C061%^w%^C060%^in%^C059%^gs%^RESET%^%^C243%^)%^CRST%^";
        wing_color = "%^C061%^f%^C060%^e%^C059%^athe%^C060%^r%^C061%^y %^C061%^w%^C060%^in%^C059%^gs";
    }

	tell_room(ENV(caster),"%^CRST%^%^C146%^As "+caster->QCN+"%^RESET%^%^CRST%^%^C146%^ finishes the chant, "+wing_color+" %^RESET%^%^C146%^unfurl from "+caster->QP+" shoulders!%^RESET%^", caster);
    tell_object(caster, "%^CRST%^%^C146%^As you finish the chant, "+wing_color+" %^RESET%^%^C146%^unfurl from your shoulders!%^RESET%^");

    effect(1);
    spell_successful();
    caster->set_property("added short",({ashort}));
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
    spell_duration = (1 + clevel / 5) * 60;
    set_end_time();
    call_out("dest_effect", spell_duration);
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property_value("added short",({ashort}));
        tell_object(caster,"%^RESET%^%^C146%^You feel your %^C247%^mortality%^C146%^ return as your %^C153%^an%^C147%^gel%^C135%^ic %^C153%^as%^C147%^pe%^C135%^ct%^RESET%^%^C146%^ fades.%^CRST%^");
        tell_room(ENV(caster),"%^RESET%^%^C146%^The wings trailing "+caster->QCN+" fade.%^RESET%^", caster);
        effect(-1);
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

