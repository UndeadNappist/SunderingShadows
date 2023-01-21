/*
  _gale_of_life.c
  
  AOE Breath of Life for Radiant Servant
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>

#define DELAY 600

inherit SPELL;

create()
{
    ::create();
    set_spell_name("gale of life");
    set_spell_level(([ "innate" : 7 ]));
    set_affixed_spell_level(5);
    set_spell_sphere("healing");
    set_syntax("cast CLASS gale of life");
    set_damage_desc("revive or heal all party members");
    set_description("The radiant servant releases a wave of positive energy, casting breath of life on all of their party members. This spell has a cooldown.");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
	set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^C032%^You gather your %^C214%^r%^C220%^a%^C226%^d%^C220%^i%^C214%^ant p%^C220%^o%^C226%^w%^C220%^e%^C214%^r%^C032%^ into a blast of %^C226%^divine energy%^C032%^.%^CRST%^";
}

int preSpell()
{
    object party, spell_ob;
    
    party = ob_party(caster);
    //party += caster->query_followers();
    
    if(!sizeof(party))
    {
        tell_object(caster, "You're not in a party.");
        return;
    }
    
    foreach(object ob in party)
    {
        if(!userp(ob))
            continue;
        
        if(catch(spell_ob = new("/cmds/spells/b/_breath_of_life.c")))
            continue;
        
        spell_ob->set_silent_casting(1);
        spell_ob->use_spell(caster, ob, clevel, 100, "cleric");
    }      
      
    spell_successful();
    dest_effect();
    return 1;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}