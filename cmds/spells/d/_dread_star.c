#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

int amount;

void create()
{
    ::create();
    
    set_spell_name("dread star");
    set_spell_level( ([ "warlock" : 2 ]) );
    set_heritage("astral");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS dread star on TARGET");
    set_damage_desc("radiance damage on ranged touch attack, stunned on a failed save");
    set_description("Conjuring a fist-sized orb of light, the warlock sends the brilliant star at their target. The star dazzles and sears with radiance that can even stun the warlock's victim, overwhelming them with raw power.");
    set_target_required(1);
    set_save("will");
    set_immunities( ({ "radiant" }) );
}

string query_cast_string()
{
    return "%^RESET%^%^CRST%^%^C243%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C243%^ conjures a %^C226%^b%^C228%^li%^C230%^nd%^C228%^in%^C226%^g s%^C228%^p%^C230%^he%^C228%^r%^C226%^e %^RESET%^%^C243%^of %^C228%^r%^C255%^ad%^C228%^i%^C255%^an%^C228%^c%^C255%^e %^RESET%^%^C243%^between their hands.%^CRST%^";
}

int preSpell()
{
    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int roll;
    string my_name, your_name, my_poss;
       
    if(!objectp(target))
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Your target is no longer here.%^CRST%^");
        return;
    }
    
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    my_name = caster->query_cap_name();
    my_poss = caster->query_possessive();
    your_name = target->query_cap_name();
    
    if(roll < 1)
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C243%^The %^C226%^r%^C228%^a%^C230%^dia%^C228%^n%^C226%^t %^C228%^s%^C230%^t%^C228%^a%^C226%^r %^RESET%^%^C243%^flies past "+your_name+"%^RESET%^%^CRST%^%^C243%^ in a %^C202%^near miss%^C243%^!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C243%^The %^C226%^r%^C228%^a%^C230%^dia%^C228%^n%^C226%^t %^C228%^s%^C230%^t%^C228%^a%^C226%^r %^RESET%^%^C243%^flies past you in a %^C202%^near miss%^C243%^!%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C243%^The %^C226%^r%^C228%^a%^C230%^dia%^C228%^n%^C226%^t %^C228%^s%^C230%^t%^C228%^a%^C226%^r %^RESET%^%^C243%^flies past "+your_name+"%^RESET%^%^CRST%^%^C243%^ in a %^C202%^near miss%^C243%^!%^CRST%^", ({ caster, target }));
        dest_effect();
        return;
    }
    
    tell_object(caster, "%^RESET%^%^CRST%^%^C243%^You propel the %^C226%^d%^C228%^r%^C230%^e%^C228%^a%^C226%^d %^C228%^s%^C230%^t%^C228%^a%^C226%^r %^RESET%^%^C243%^forth, and it envelops "+your_name+"%^RESET%^%^CRST%^%^C243%^ in %^C196%^searing %^C228%^r%^C255%^ad%^C228%^i%^C255%^an%^C228%^c%^C255%^e%^C243%^!%^CRST%^");
    tell_object(target, "%^RESET%^%^CRST%^%^C243%^"+my_name+"%^RESET%^%^CRST%^%^C243%^ propels the %^C226%^d%^C228%^r%^C230%^e%^C228%^a%^C226%^d %^C228%^s%^C230%^t%^C228%^a%^C226%^r %^RESET%^%^C243%^forth, and it envelops you in %^C196%^searing %^C228%^r%^C255%^ad%^C228%^i%^C255%^an%^C228%^c%^C255%^e%^C243%^!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C243%^"+my_name+"%^RESET%^%^CRST%^%^C243%^ propels the %^C226%^d%^C228%^r%^C230%^e%^C228%^a%^C226%^d %^C228%^s%^C230%^t%^C228%^a%^C226%^r %^RESET%^%^C243%^forth, and it envelops "+your_name+"%^RESET%^%^CRST%^%^C243%^ in %^C196%^searing %^C228%^r%^C255%^ad%^C228%^i%^C255%^an%^C228%^c%^C255%^e%^C243%^!%^CRST%^", ({ caster, target }));
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "radiant");
    spell_kill(target, caster);
    
    if(do_save(target, 0))
        return;
    
    tell_room(place, "%^RESET%^%^CRST%^%^C243%^"+your_name+"%^RESET%^%^CRST%^%^C243%^ stumbles about in a %^C220%^d%^C226%^a%^C220%^z%^C214%^e %^RESET%^%^C243%^as the %^C255%^li%^C254%^g%^C252%^h%^C251%^t %^C250%^f%^C249%^a%^C248%^d%^C247%^e%^C246%^s a%^C245%^w%^C244%^a%^C243%^y.%^CRST%^", target);
    tell_object(target, "%^RESET%^%^CRST%^%^C243%^You stumble about in a %^C220%^d%^C226%^a%^C220%^z%^C214%^e %^RESET%^%^C243%^as the %^C255%^li%^C254%^g%^C252%^h%^C251%^t %^C250%^f%^C249%^a%^C248%^d%^C247%^e%^C246%^s a%^C245%^w%^C244%^a%^C243%^y.%^CRST%^");
    target->set_paralyzed(6);    
    
    dest_effect();
}

void dest_effect()
{
    
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
    

