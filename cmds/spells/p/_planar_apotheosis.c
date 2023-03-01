#include <std.h>
#include <priest.h>

inherit SPELL;

int counter, myresist, resistflag, extra, flag, duration, mylevel;
string mytype;

void emote_em(string str);

void create(){
    ::create();
    set_spell_name("planar apotheosis");
    set_spell_level(([ "psywarrior" : 4 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS planar apotheosis on CELESTIAL|FIENDISH");
    set_description("When manifesting this power, the psionic character chooses to embrace the powers of either the celestial or the fiendish. The planar energy chosen grants special resistances and imbues the manifester with a protective force. Once each round, the energy automatically lashes out at one of his foes, striking him with fiendish or celestial energy. The duration of this power grows with the psionic character.");
    set_verbal_comp();
    set_bonus_type("resistance");
    set_arg_needed();
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

int preSpell(){
    if(!arg){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Please specify the type of energy you would like to embrace - celestial or fiendish.%^CRST%^");
        return 0;
    }
    if(caster->query_property("apotheosis")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already under the effects of this power!%^CRST%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    mytype = arg;
    mylevel = clevel;
    duration = (ROUND_LENGTH * 10) * mylevel;
    myresist = (mylevel/2) + 5; //lower than other resistance spells because it is lower level and grants specific resistances as well. Adjust if needed.
    if(mytype == "fiendish"){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You reach into the depths of the %^C056%^A%^C055%^b%^C054%^y%^C055%^s%^C056%^s%^C059%^ and bring forth %^C105%^o%^C111%^th%^C117%^e%^C105%^r%^C111%^wo%^C117%^r%^C105%^l%^C111%^dl%^C117%^y %^C105%^e%^C111%^ne%^C117%^r%^C105%^g%^C111%^ie%^C117%^s%^C059%^, feeling them settle into your very skin.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C056%^D%^C055%^a%^C054%^rkne%^C055%^s%^C056%^s %^C059%^suddenly surrounds "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ and "+caster->query_possessive()+" eyes %^C105%^g%^C111%^li%^C117%^m%^C105%^m%^C111%^er %^C059%^briefly.%^CRST%^", caster);
        caster->set_resistance("cold", 10);
        caster->set_resistance("fire", 10);
        caster->set_resistance("electricity", 10);
        caster->set_property("spell damage resistance", myresist);
    }    
    else if(mytype == "celestial"){
        tell_object(caster, "%^RESET%^%^CRST%^%^C255%^You reach into the shimmering %^C051%^A%^C045%^st%^C039%^ral %^C051%^P%^C045%^la%^C039%^ne%^C255%^ and bring forth %^C105%^o%^C111%^th%^C117%^e%^C105%^r%^C111%^wo%^C117%^r%^C105%^l%^C111%^dl%^C117%^y %^C105%^e%^C111%^ne%^C117%^r%^C105%^g%^C111%^ie%^C117%^s%^C255%^, feeling them settle into your very skin.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C255%^An %^C051%^e%^C045%^the%^C039%^real %^C051%^g%^C045%^l%^C039%^ow%^C255%^ suddenly surrounds "+caster->query_cap_name()+" %^RESET%^%^CRST%^%^C255%^and "+caster->query_possessive()+" eyes %^C105%^g%^C111%^li%^C117%^m%^C105%^m%^C111%^er %^C255%^briefly.%^CRST%^", caster);
        caster->set_resistance("cold", 10);
        caster->set_resistance("acid", 10);
        caster->set_resistance("electricity", 10);
        caster->set_property("spell damage resistance", myresist);
    }
    else{
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^That is not a valid type! Please choose celestial or fiendish.%^CRST%^");
        return;
    }
    caster->set_property("spelled", ({this_object()}) );
    caster->set_property("apotheosis", 1);
    addSpellToCaster();
    spell_successful();
    environment(caster)->addObjectToCombatCycle(this_object(), 1);
    call_out("emote_em", 15 * ROUND_LENGTH, mytype);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect", spell_duration);
}

void execute_attack(){
    object ppl;
    string baddie;
    if(!flag){
        ::execute_attack();
        flag = 1;
        return;
    }
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    
    ppl = caster->query_current_attacker();
    if(ppl && objectp(ppl)){
        baddie = ppl->query_cap_name();
        extra = ((mylevel*2)/3);
        if(!objectp(ppl)) return;
        if(mytype == "fiendish"){
            tell_room(environment(caster), "%^RESET%^%^CRST%^%^C059%^The %^C056%^s%^C055%^h%^C054%^ado%^C055%^w%^C056%^s%^C059%^ surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ suddenly surge forward, %^C105%^l%^C111%^as%^C117%^h%^C105%^i%^C111%^ng%^C059%^ out at "+baddie+"%^RESET%^%^CRST%^%^C059%^.%^CRST%^", ({caster, ppl}));
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^The %^C056%^s%^C055%^h%^C054%^ado%^C055%^w%^C056%^s%^C059%^ surrounding you coalesce, %^C105%^l%^C111%^as%^C117%^h%^C105%^i%^C111%^ng%^C059%^ out at "+baddie+"%^RESET%^%^CRST%^%^C059%^!%^CRST%^");
            tell_object(ppl, "%^RESET%^%^CRST%^%^C059%^The %^C056%^s%^C055%^h%^C054%^ado%^C055%^w%^C056%^s%^C059%^ surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ coalesce and %^C105%^l%^C111%^as%^C117%^h%^C059%^ out at you!%^CRST%^");
        }
        else{
            tell_room(environment(caster), "%^RESET%^%^CRST%^%^C255%^A flash of %^C051%^b%^C045%^lin%^C039%^ding %^C051%^l%^C045%^ig%^C039%^ht%^C255%^ beams from "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^'s eyes, striking "+baddie+"%^RESET%^%^CRST%^%^C255%^!%^CRST%^", ({caster, ppl}));
            tell_object(caster, "%^RESET%^%^CRST%^%^C255%^Heat builds within you before a beam of %^C051%^b%^C045%^lin%^C039%^ding %^C051%^l%^C045%^ig%^C039%^ht%^C255%^ lashes out, striking "+baddie+"%^RESET%^%^CRST%^%^C255%^!%^CRST%^");
            tell_object(ppl, "%^RESET%^%^CRST%^%^C255%^A flash of %^C051%^b%^C045%^lin%^C039%^ding %^C051%^l%^C045%^ig%^C039%^ht%^C255%^ beams from "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^'s eyes, striking you!%^CRST%^");
        }
        damage_targ(ppl,ppl->return_target_limb(), extra, "mental");
        counter++;
        if(counter > mylevel){
            dest_effect();
            return;
        }
    }
    environment(caster)->addObjectToCombatCycle(this_object(), 1);
}

void dest_effect(){
    if(objectp(caster)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C030%^You feel the %^C105%^p%^C111%^la%^C117%^n%^C105%^a%^C111%^r e%^C117%^n%^C105%^e%^C111%^rg%^C117%^y %^C030%^drain from you.%^CRST%^");
        tell_room(environment(caster), "%^CYAN%^The field of %^C105%^e%^C111%^ne%^C117%^r%^C105%^g%^C111%^y %^C030%^surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C030%^ fades away.%^CRST%^", caster);
        caster->set_resistance("cold",-10);
        caster->set_resistance("electricity",-10);
        if(mytype == "fiendish"){
            caster->set_resistance("fire",-10);
        }
        else{
            caster->set_resistance("acid",-10);
        }

        caster->set_property("spell damage resistance", -1 * myresist);
        caster->remove_property("apotheosis");
    }
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

void emote_em(string str){
    mytype = str;
    if(sizeof(caster->query_attackers()) > 0){
        call_out("emote_em", 5*ROUND_LENGTH, mytype);
        return;
    }
    if(mytype == "fiendish"){
        switch(random(5)){
            case 0:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C056%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C056%^'s exposed skin takes on a %^C062%^f%^C069%^ain%^C062%^t b%^C069%^lu%^C062%^e %^C056%^cast before it fades away.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C056%^You feel a surge of %^C062%^d%^C069%^ar%^C062%^k e%^C069%^nerg%^C062%^y %^C056%^test your mental resilience before it settles once more.%^CRST%^");
                break;
            case 1:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C059%^A pair of %^C056%^s%^C055%^h%^C054%^ado%^C055%^w%^C056%^y w%^C055%^i%^C054%^n%^C055%^g%^C056%^s%^C059%^ sprout from "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^'s back and then shrink away again.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Heat flushes your skin and you feel an %^C056%^i%^C055%^t%^C054%^c%^C055%^h%^C059%^ between your shoulder blades that soon fades away.%^CRST%^");
                break;
            case 2:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C059%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^'s eyes suddenly %^C160%^g%^C196%^l%^C160%^o%^C124%^w r%^C160%^e%^C124%^d%^C059%^ before returning to their normal hue.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You feel the %^C160%^f%^C196%^i%^C160%^r%^C124%^e%^C059%^ within blaze before dampening just as quickly.%^CRST%^");
                break;
            case 3:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C124%^The scent of %^C208%^b%^C214%^r%^C208%^i%^C202%^m%^C208%^s%^C214%^t%^C208%^o%^C202%^n%^C208%^e%^C124%^ fills the air around "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C124%^The scent of %^C208%^b%^C214%^r%^C208%^i%^C202%^m%^C208%^s%^C214%^t%^C208%^o%^C202%^n%^C208%^e%^C124%^ rises all around you.%^CRST%^");
                break;
            default:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C059%^The %^C056%^s%^C055%^h%^C054%^ado%^C055%^w%^C056%^s%^C059%^ around "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ shift, distorting "+caster->query_possessive()+" face into a %^C124%^te%^C125%^r%^C126%^r%^C124%^if%^C125%^y%^C126%^i%^C124%^ng %^C125%^m%^C126%^a%^C124%^sk%^C059%^. With a hint of a %^C243%^l%^C244%^i%^C245%^g%^C246%^h%^C247%^t %^C243%^b%^C244%^r%^C245%^e%^C246%^e%^C247%^z%^C248%^e%^C059%^, the illusion dissipates.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You fight back a smile as you feel a %^C124%^fi%^C125%^e%^C126%^n%^C124%^di%^C125%^s%^C126%^h %^C124%^wa%^C125%^r%^C126%^m%^C124%^th%^C059%^ deep within your soul.%^CRST%^");
                break;
        }
    }
    if(mytype == "celestial"){
        switch(random(5)){
            case 0:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C030%^As "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C030%^ turns "+caster->query_possessive()+" head, "+caster->query_subjective()+" sparkles with an %^C207%^o%^C051%^p%^C045%^a%^C039%^l%^C207%^e%^C201%^s%^C045%^c%^C051%^e%^C045%^n%^C039%^t %^C039%^g%^C045%^l%^C051%^e%^C207%^a%^C039%^m%^C030%^.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C030%^You feel a surge of %^C045%^j%^C051%^o%^C045%^y%^C030%^ as warmth spreads across your skin.%^CRST%^");
                break;
            case 1:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C100%^A stray %^C226%^b%^C220%^e%^C214%^am %^C208%^of %^C226%^l%^C220%^ig%^C214%^ht%^C100%^ appears, casting its glow on "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^'s hair and giving it an unearthly %^C245%^s%^C248%^i%^C251%^lv%^C248%^e%^C245%^r s%^C248%^h%^C251%^e%^C248%^e%^C245%^n%^C100%^.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C100%^You are briefly bathed in a warm, %^C226%^r%^C220%^adi%^C214%^ant %^C226%^g%^C220%^l%^C214%^ow%^C100%^.%^CRST%^");
                break;
            case 2:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C101%^As you look on, a cascade of %^C099%^i%^C105%^r%^C033%^i%^C027%^d%^C026%^e%^C032%^s%^C038%^c%^C037%^e%^C031%^n%^C099%^t %^C105%^f%^C033%^e%^C027%^a%^C026%^t%^C032%^h%^C038%^e%^C037%^r%^C031%^s%^C101%^ sprouts from "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^'s shoulders before fading away.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C101%^Something tickles your ear just before you see a single %^C099%^i%^C105%^r%^C033%^i%^C027%^d%^C026%^e%^C032%^s%^C038%^c%^C037%^e%^C031%^n%^C099%^t %^C105%^f%^C033%^e%^C027%^a%^C026%^t%^C032%^h%^C038%^e%^C037%^r%^C101%^ float before your eyes.%^CRST%^");
                break;
            case 3:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C144%^A smattering of %^C099%^i%^C105%^r%^C033%^i%^C027%^d%^C026%^e%^C032%^s%^C038%^c%^C037%^e%^C031%^n%^C099%^t %^C105%^s%^C033%^c%^C027%^a%^C026%^l%^C032%^e%^C038%^s%^C144%^ briefly covers "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^'s exposed skin.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C144%^You feel a brush against your skin like angelic fingertips.%^CRST%^");
                break;
            default:
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C100%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^'s skin takes on a %^C214%^g%^C220%^o%^C226%^ld%^C220%^e%^C214%^n %^C220%^g%^C226%^l%^C220%^o%^C214%^w%^C100%^ before returning to its usual hue.%^CRST%^", caster);
                tell_object(caster, "%^RESET%^%^CRST%^%^C100%^You feel %^C214%^w%^C220%^a%^C226%^rm%^C220%^t%^C214%^h%^C100%^ against your skin, like the gentle kiss of a warm fire in the hearth.%^CRST%^");
                break;
        }
    }
    call_out("emote_em", 15 * ROUND_LENGTH, mytype);
    return;
}

