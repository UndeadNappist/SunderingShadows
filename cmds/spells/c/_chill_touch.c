//      Chill Touch
//fixed switch so versatile arcanist actually manipulates element.
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string target_limb, element;


create(){
    ::create();
    set_spell_name("chill touch");
    set_spell_level(([ "mage" : 1, "magus" : 1, "druid" : 1 ]));
    set_spell_sphere("necromancy");
    set_circle("winter");
    set_syntax("cast CLASS chill touch on TARGET");
    set_description("By casting this spell, your hand will flare up with a blue aura. You can touch your enemy with that hand and, if the target doesn't make his save and avoid your touch, you will inflict a small amount of damage. Furthermore, the target will be slightly weakened until a certain length of time runs out.");
    set_verbal_comp();
    set_somatic_comp();
    versatile();
    set_target_required(1);
    set_immunities(({"cold"}));
}

string query_cast_string(){
    element = (string)caster->query("elementalist");
    if(element){
        set_immunities(({ element }));
        define_clevel();
        define_base_damage(0);
    }
    return "%^RESET%^%^CRST%^%^C059%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ utters a morose chant.%^CRST%^";
}

spell_effect(int prof){
    string mycolor, myhue, myhue2, myfeeling, damtype;
    int bonus, roll;

    if(!objectp(caster) || !objectp(target)){
        target = 0;
        dest_effect();
        return;
    }

    target_limb = target->return_target_limb();
    bonus = 0;

    if (!present(target,environment(caster))){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Your target is not in this area.%^CRST%^\n");
        target = 0;
        dest_effect();
        return;
    }

    switch(element){
        case "acid":
            mycolor = "%^C065%^";
            myhue = "%^C077%^s%^C071%^i%^C070%^c%^C076%^k%^C070%^l%^C071%^y %^C077%^g%^C071%^r%^C070%^e%^C076%^e%^C070%^n%^C065%^";
            myhue2 = "%^C077%^s%^C071%^i%^C070%^c%^C076%^k%^C070%^l%^C071%^y %^C077%^g%^C071%^r%^C070%^e%^C076%^e%^C070%^n %^C071%^g%^C077%^l%^C071%^o%^C070%^w%^C065%^";
            myfeeling = "%^C046%^burning pain%^C065%^";
            damtype = "acid";
            break;
        case "electricity":
            mycolor = "%^C100%^";
            myhue = "%^C228%^s%^C231%^t%^C228%^at%^C226%^i%^C228%^c-c%^C231%^h%^C228%^arg%^C231%^e%^C226%^d%^C100%^";
            myhue2 = "%^C228%^s%^C231%^t%^C228%^at%^C226%^i%^C228%^c c%^C231%^h%^C228%^arg%^C231%^e%^C100%^";
            myfeeling = "%^C228%^sudden jolt%^C100%^";
            damtype = "electricity";
            break;
        case "fire":
            mycolor = "%^C124%^";
            myhue = "%^C208%^r%^C214%^a%^C208%^d%^C202%^i%^C208%^a%^C214%^n%^C208%^t%^C202%^l%^C208%^y %^C214%^g%^C208%^l%^C202%^o%^C208%^w%^C214%^i%^C208%^n%^C202%^g%^C124%^";
            myhue2 = "%^C208%^r%^C214%^a%^C208%^d%^C202%^i%^C208%^a%^C214%^n%^C208%^t%^C202%^l%^C208%^y %^C214%^g%^C208%^l%^C202%^o%^C208%^w%^C124%^";
            myfeeling = "%^C196%^blazing pain%^C124%^";
            damtype = "fire";
            break;
        case "sonic":
            mycolor = "%^C090%^";
            myhue = "%^C218%^p%^C212%^u%^C206%^lsi%^C212%^n%^C218%^g%^C090%^";
            myhue2 = "%^C218%^p%^C212%^u%^C206%^lsi%^C212%^n%^C218%^g %^C212%^a%^C206%^u%^C212%^r%^C218%^a%^C090%^";
            myfeeling = "%^C165%^horrible throbbing%^C090%^";
            damtype = "sonic";
            break;
        default:
            element = "cold";
            mycolor = "%^C039%^";
            myhue = "%^C069%^b%^C075%^l%^C081%^u%^C087%^i%^C123%^s%^C087%^h %^C081%^g%^C075%^l%^C069%^o%^C075%^w%^C081%^i%^C087%^n%^C123%^g%^C039%^";
            myhue2 = "%^C069%^b%^C075%^l%^C081%^u%^C087%^i%^C123%^s%^C087%^h %^C081%^g%^C075%^l%^C069%^o%^C075%^w%^C039%^";
            myfeeling = "%^C051%^ghastly chill%^C039%^";
            damtype = "cold";
            break;
    }

    tell_object(caster, "%^RESET%^%^CRST%^"+mycolor+"Your hand starts to develop a "+myhue2+".%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^"+mycolor+caster->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+"'s hand starts to develop a "+myhue2+".%^CRST%^",caster );

    /*===================================================================================
                                      FUNCTION EXPLAINATIONS
       for any touch attack spell the following will likely work

       roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);
       roll will be a 0 for a miss, a -1 for a dice roll of 1 which is a miss
       a 20 for a dice roll of 20 or the actual dice roll

       if(roll == -1 || !roll) {
            ...set what happens when the touch attack fails
       }
       else {
           ... set what happens when it lands
       }
       ARGUMENT descriptions =
       caster = person casting spell
       target = target of the spell
       1 = the attack number they are using for the hit bonus - for players there is a -2 bonus when dual wielding, though this is
       negated if they have the feats - otherwise it is -2 x this number to a max of -10 (I know not how tabletop works) - technically
       could set this number at anything, though anything more than 5 will have the same impact as 5 or anything less than 1 will be counted as 1

       bonus = a bonus to hit or a weapon - if it's an integer it gets added as a bonus to hit - if it is an object it adds the enchantment to the hit bonus

       0 = the debug object if this is set to someone it will show the dice roll, attack bonus, and AC + Ac Bonuses

       1 = a flag that designates this as a touch attack - the real difference is that it does not include
       AC from equipment - only dodge bonuses/dex bonuses

       PLEASE NOTE: This spell now checks for deflection - see explaination below.

       Though beyond the scope of this spell - it is possible to allow a deflection attempt - so that they deflect
       with their shield or with something like concealing amorpha
       this would be as simple as "/daemon/combat_d.c"->extra_hit_calcs(caster, target, weapon, limb)
       at present weapon && limb have no impact and are not required - will likely remain optional
       as the code adapts
       the function call to extra_hit_calcs() will return 0 if the deflect is
       successful or 1 if it fails - in the event of a 0 it will
       also tell the caster and the target that the spell/attack was deflected
       so in this case if we wanted to allow for a deflection attempt also
       after the following check we do simply do
       if(!"/daemon/combat_d.c"->extra_hit_calcs(caster, target) {
       TO->remove();
          return;
       }

       both the caster, target, and room will be notified that it was a deflection or miss
       based on concealing amorpha - there is currently no seperating the two, it checks
       for both - this could also be easily modified to allow for a flag that specifics which to check for
                                    END SAIDE'S ATTEMPT AT EXPLAINING
     ==================================================================================*/

    roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);

    if(!roll || roll == -1 && ! caster->query_property("spectral_hand")){
        tell_object(caster, "%^RESET%^%^CRST%^"+mycolor+"You try and touch "+target->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+"'s "+target_limb+" with a "+myhue+" hand, but %^C059%^miss"+mycolor+"!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^"+mycolor+caster->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+"'s "+myhue+" hand gropes for your "+target_limb+" unsuccessfully.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^"+mycolor+caster->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+" reaches out for "+target->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+"'s "+target_limb+" with a "+myhue+" hand and %^C059%^misses"+mycolor+"!%^CRST%^", ({ caster, target}) );
        target = 0;
        dest_effect();
        return;
    }

    // I am adding in the chance to deflect - after reading touch
    // attacks allow for deflection attempts, size modifiers, and
    // dexterity bonuses not a perfect setup since in our world
    // shields deflect, in D&D they add to AC I believe - but close
    // enough IMHO and unique to us :D

    // Who is "I am"?.. That comment is not helfpful.  -- Il

    if(!"/daemon/combat_d.c"->extra_hit_calcs(caster, target)){
        target = 0;
        dest_effect();
        return;
    }

    tell_object(caster, "%^RESET%^%^CRST%^"+mycolor+"You reach out and touch "+target->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+"'s "+target_limb+" with your "+myhue+" hand!%^CRST%^");
    tell_object(target, "%^RESET%^%^CRST%^"+mycolor+caster->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+" touches your "+target_limb+" with a "+myhue+" hand.\n%^RESET%^%^CRST%^"+mycolor+"A "+myfeeling+" runs through you, sapping your strength!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^"+mycolor+caster->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+" reaches out and touches "+target->query_cap_name()+"%^RESET%^%^CRST%^"+mycolor+"'s "+target_limb+" with a "+myhue+" hand!\n%^RESET%^%^CRST%^"+mycolor+"All life and color seems drawn out of the limb!%^CRST%^",({ caster, target}) );
    spell_successful();

    damage_targ(target, target_limb, sdamage , damtype );
    if (objectp(target)){
        stat_change(target, "strength", -1);
        target->set_property("spelled", ({TO}) );
        spell_duration = (clevel + roll_dice(1, 20) + bonus) * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
    else{
        target = 0;
        dest_effect();
        return;
    }
}


void dest_effect(){
    if(find_call_out("dest_effect") != -1) remove_call_out("dest_effect");
    if(objectp(target)){
        stat_change(target, "strength", 1);
        target->remove_property_value("spelled", ({TO}) );
        tell_room(environment(target), "%^RESET%^%^CRST%^%^C101%^"+target->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ loses "+target->query_possessive()+" pale complexion.%^CRST%^", target);
        tell_object(target, "%^RESET%^%^CRST%^%^C101%^The skeletal white color in your "+target_limb+" fades away.%^CRST%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

