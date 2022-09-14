#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

int amount;

void create()
{
    ::create();
    
    set_spell_name("frigid darkness");
    set_spell_level( ([ "warlock" : 2 ]) );
    set_heritage("astral");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS frigid darkness on TARGET");
    set_damage_desc("cold/void damage on ranged touch attack and lowered AC");
    set_description("A sphere of darkness shoots out at the target, enveloping them in cold darkness. On a successful ranged touch attack, the target takes both cold and void damage and their defenses are weakened, lowering their armor class for a short time.");
    set_target_required(1);
    set_immunities( ({ "cold", "void" }) );
}

string query_cast_string()
{
    return "%^C069%^" + caster->query_cap_name() + "%^C244%^ utters a %^C057%^f%^C063%^o%^C069%^u%^C057%^l%^C244%^ %^C057%^i%^C063%^n%^C069%^v%^C075%^o%^C069%^c%^C063%^a%^C057%^tion%^C244%^ and gathers the %^C069%^f%^C075%^r%^C081%^o%^C069%^zen%^C244%^ d%^C246%^a%^C248%^r%^C250%^k%^C248%^n%^C246%^e%^C244%^ss around + " + caster->query_objective() + ".%^CRST%^";
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
    string my_name, your_name;
       
    if(!objectp(target))
    {
        tell_object(caster, "Your target is no longer here.");
        return;
    }
    
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();
    
    if(roll < 1)
    {
        tell_object(caster, "%^BLACK%^BOLD%^You point your finger and shoot a ball of pure, cold darkness at %^CYAN%^" + your_name + "%^BLACK%^ but miss!%^RESET%^");
        dest_effect();
        return;
    }
    
    tell_object(caster, "Your orb of darkness strikes " + your_name + ", enveloping " + target->query_objective() + " in frigid darkness!");
    tll_object(target, "" + my_name);
    tell_room(place, "hit message room", ({ caster })); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage / 2, "void");
    target->cause_typed_damage(target, target->return_target_limb(), sdamage / 2, "cold");
    spell_kill(target, caster);
    
    if(target->query_property("frigid darkness"))
    {
        dest_effect();
        return;
    }
    
    amount = 1 + clevel / 5;
    target->set_property("frigid darkness", 1);
    target->add_ac_bonus(-amount);
    
    call_out("dest_effect", 18);
}

void dest_effect()
{
    if(target && target->query_property("frigid darkness"))
    {
        tell_object(target, "%^CYAN%^You feel the cold darkness subside from your body.%^RESET%^");
        target->remove_property("frigid darkness");
        target->add_ac_bonus(amount);
    }
    
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
    

