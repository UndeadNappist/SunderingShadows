/*
  _psionic_blast.c

  AOE Stun

  -- Tlaloc -- 3.31.20
*/

#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();

    set_spell_name("psionic blast");
    set_spell_level( ([ "psion" : 3 ]) );
    set_spell_sphere("telepathy");
    mental_spell();
    set_syntax("cast CLASS psionic blast");
    set_description("The air ripples with the force of your mental attack, which blasts the minds of all creatures in range. Psionic blast stuns all affected creatures for 2d4 rounds.");
    set_save("will");
    splash_spell(3);
}

string query_cast_string()
{
    tell_object(caster, "%^C037%^You concentrate %^C025%^intently%^C037%^, focusing your %^C099%^p%^C105%^s%^C111%^ion%^C105%^i%^C099%^c p%^C105%^o%^C111%^we%^C105%^r%^C099%^s%^C037%^.%^CRST%^");
    tell_room(place, "%^C037%^"+caster->query_cap_name()+"%^C037%^ concentrates %^C025%^intently%^C037%^, focusing "+caster->query_possessive()+" %^C099%^p%^C105%^s%^C111%^ion%^C105%^i%^C099%^c p%^C105%^o%^C111%^we%^C105%^r%^C099%^s%^C037%^.%^CRST%^");
    return "display";
}

void spell_effect(int prof)
{
    object me = this_object(), *victims;
    string myname, yourname;

    myname = caster->QCN;

    tell_object(caster, "%^C043%^You place your fingers to the side of your head and bring forth a %^C099%^b%^C105%^l%^C111%^a%^C105%^s%^C099%^t %^C093%^of %^C099%^p%^C105%^s%^C111%^ych%^C105%^i%^C099%^c e%^C105%^n%^C111%^er%^C105%^g%^C099%^y%^C043%^!%^CRST%^");
    tell_room(place, "%^C043%^"+caster->query_cap_name()+"%^C043%^ places "+caster->query_possessive()+" fingers to the side of "+caster->query_possessive()+" head and brings forth a %^C099%^b%^C105%^l%^C111%^a%^C105%^s%^C099%^t %^C093%^of %^C099%^p%^C105%^s%^C111%^ych%^C105%^i%^C099%^c e%^C105%^n%^C111%^er%^C105%^g%^C099%^y%^C043%^!%^CRST%^", caster);

    victims = target_selector();

    if(!sizeof(victims))
    {
        tell_object(caster, "%^C059%^You release a wave of psionic energy, but nothing else happens...%^CRST%^");
        dest_effect();
        return;
    }

    tell_object(caster, "%^C049%^%^You release a blast of psychic energy into the area!%^CRST%^");
    tell_room(place, "%^C049%^"+caster->query_cap_name()+"%^C049%^ releases a blast of psychic energy into the area!%^CRST%^", caster);

    foreach(object ob in victims)
    {
        if(do_save(ob, 0))
            tell_object(ob, "%^C031%^You manage to shrug off the psionic blast.%^CRST%^");
        else
        {
            tell_object(ob, "%^C255%^The psionic energy slams into you, leaving you stunned!%^CRST%^");
            tell_object(caster, "%^C255%^The psionic energy slams into "+ob->query_cap_name()+"%^C255%^, leaving them stunned!%^CRST%^");
            ob->set_paralyzed(roll_dice(2, 4) * 8, "%^C255%^You are stunned by the psychic blast!%^CRST%^");
        }
        spell_kill(ob,caster);
    }

    spell_successful();
    dest_effect();
}

