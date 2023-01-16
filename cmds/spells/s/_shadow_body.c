/*
  _shadow_body.c

  Egoists can turn their body into shadow. Similar to Fiery Body
  and Form of Doom.

  -- Tlaloc -- 4.3.20
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

string ashort;

void effect(int direction){
    if(direction > 0)
    {
        caster->set_property("flying",1);
        //caster->set_property("iron body", 1);
        caster->set_property("poison immunity", 1);
        caster->set_property("disease immunity", 1);
    }
    else
    {
        caster->set_property("flying", -1);
        //caster->remove_property("iron body");
        caster->remove_property("disease immunity");
        caster->remove_property("poison immunity");
    }

    caster->set_property("damage resistance",10 * direction);
    caster->set_resistance_percent("fire",50*direction);
    caster->set_resistance_percent("acid",50*direction);
    caster->set_resistance_percent("electricity",50*direction);
    caster->set_property("endurance", (clevel / 8) * direction);

    return;
}

void create(){
    ::create();

    set_author("tlaloc");
    set_spell_name("shadow body");
    set_spell_level( ([ "psion" : 9, "mage":7, "monk":17]) );
    set_spell_sphere("alteration");
    set_discipline("egoist");
    set_bonus_type("body");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS shadow body");
    set_description("Your body and all your equipment are subsumed by your shadow. As a living shadow, you blend perfectly into any other shadow and vanish in darkness. You appear as an unattached shadow in areas of full light. You shadow body gives you 10 damage reduction, flying, and 50% fire, acid and electricity resistance, and immunity to disease and poison.");
    set_helpful_spell(1);
}

int preSpell(){
    /*
   if(caster->query_stoneSkinned() || caster->query_property("iron body") || caster->query_property("form of doom") || caster->query_property("fiery body"))
   {
      tell_object(caster,"You already have protection of this nature!");
      return 0;
   }
   */

   return 1;
}


string query_cast_string(){
    tell_object(caster, "%^RESET%^%^CRST%^%^C060%^You concentrate on your %^C055%^s%^C054%^h%^C053%^ad%^C054%^o%^C055%^w%^RESET%^%^C060%^...%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C060%^"+caster->QCN+"%^RESET%^%^CRST%^%^C060%^ concentrates on "+caster->QP+" %^C055%^s%^C054%^h%^C053%^ad%^C054%^o%^C055%^w%^RESET%^%^C060%^...%^CRST%^", caster);
    return "display";
}

void spell_effect(int prof){
    string myname, yourname;
    int mylevel;

    myname = caster->QCN;
    ashort = " %^RESET%^%^CRST%^%^C099%^(%^C055%^s%^C054%^h%^C053%^ado%^C054%^w%^C055%^y si%^C054%^lh%^C053%^ou%^C054%^et%^C055%^te%^C099%^)%^CRST%^";

    tell_object(caster, "%^RESET%^%^CRST%^%^C060%^You focus on the %^C055%^s%^C054%^h%^C053%^ado%^C054%^w%^C055%^s%^RESET%^%^C060%^, drawing them to you and %^C055%^su%^C054%^bs%^C053%^u%^C054%^mi%^C055%^ng %^C060%^your body!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C060%^"+myname+"%^RESET%^%^CRST%^%^C060%^ pulls the %^C055%^s%^C054%^h%^C053%^ado%^C054%^w%^C055%^s%^RESET%^%^C060%^ towards "+caster->QO+", %^C055%^su%^C054%^bs%^C053%^u%^C054%^mi%^C055%^ng %^RESET%^%^C060%^"+caster->QP+" body!%^CRST%^", caster);

    effect(1);
    spell_successful();
    addSpellToCaster();

    caster->set_property("added short",({ashort}));

    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 7;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){
    remove_call_out("dest_effect");
    
    tell_object(caster, "%^RESET%^%^CRST%^%^C060%^The %^C055%^s%^C054%^h%^C053%^ado%^C054%^w%^C055%^s%^RESET%^%^C060%^ subsuming your body seem to %^C059%^dissipate%^C060%^.%^CRST%^");
    caster->remove_property_value("added short",({ashort}));
    effect(-1);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}

