/*
  _aura_of_dread.c

  Mortuum-specific spell similar to oppression, but undermines fear immunity.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

object *saved = ({  });
int counter, flag;
string my_name, my_poss, my_pron;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("aura of dread");
    set_spell_sphere("necromancy");
    set_spell_level( ([ "innate" : 9 ]) );
    set_syntax("cast CLASS aura of dread");
    set_damage_desc("electricity and shaken on attackers on failed save");
    set_description("The Mortuum calls upon dark and macabre powers and the unfortunate souls of the afterlife to create a storm of malevolent spirit energy around them. The trapped, suffering souls cause damage to attackers and instill them with fear. Any attackers will be struck with electicity damage and must make a will save or be rendered shaken. Unlike similar spells, like oppression, this spell ignores fear immunity.");
    traveling_spell(1);
    set_save("will");
    evil_spell(1);
}

string query_cast_string()
{
    my_name = caster->query_cap_name();
    my_poss = caster->query_possessive();
    my_pron = caster->query_subjective();

    tell_object(caster, "%^C238%^Clenching your %^C043%^f%^C037%^i%^C031%^s%^C025%^t%^C031%^s%^C238%^, you begin to %^C220%^g%^C221%^r%^C222%^o%^C228%^w%^C229%^l %^C238%^the words of a %^C230%^p%^C229%^r%^C228%^a%^C222%^y%^C221%^e%^C220%^r %^C238%^in a %^C239%^f%^C240%^e%^C241%^a%^C242%^r%^C243%^s%^C242%^o%^C241%^m%^C240%^e %^C238%^tone.%^RESET%^");
    tell_room(place, "%^C025%^" + my_name + " %^C238%^clenches " + my_poss + " %^C043%^f%^C037%^i%^C031%^s%^C025%^t%^C031%^s%^C238%^, growing the words of a %^C230%^p%^C229%^r%^C228%^a%^C222%^y%^C221%^e%^C220%^r %^C238%^in a %^C239%^f%^C240%^e%^C241%^a%^C242%^r%^C243%^s%^C242%^o%^C241%^m%^C240%^e %^C238%^tone.%^RESET%^", caster);
    return "display";
}

int preSpell()
{
    if(caster->query_property("oppression"))
    {
        tell_object(caster, "You already have an aura of oppression up.");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    int duration;

    ::spell_effect();

    my_name = caster->query_cap_name();
    my_poss = caster->query_possessive();
    my_pron = caster->query_subjective();

    tell_object(caster, "%^C238%^Finishing the %^C230%^p%^C229%^r%^C228%^a%^C222%^y%^C221%^e%^C220%^r%^C238%^, your %^C043%^f%^C037%^i%^C031%^s%^C025%^t%^C031%^s %^C238%^open and an %^C240%^a%^C242%^u%^C244%^r%^C246%^a %^C238%^bursts forth, creating a sense of %^C025%^f%^C031%^e%^C037%^a%^C043%^r %^C238%^and %^C043%^d%^C037%^e%^C031%^s%^C025%^p%^C031%^a%^C037%^i%^C043%^r%^C238%^, causing even the bravest of %^C220%^s%^C221%^o%^C222%^u%^C223%^l%^C229%^s %^C238%^to %^C240%^f%^C242%^a%^C244%^l%^C246%^t%^C248%^e%^C250%^r %^C238%^and %^C250%^t%^C248%^r%^C246%^e%^C244%^m%^C242%^b%^C240%^l%^C238%^e.%^RESET%^");
    tell_room(place, "%^C025%^As" + my_name + "%^C238%^finishes" + my_poss + "%^C230%^p%^C229%^r%^C228%^a%^C222%^y%^C221%^e%^C220%^r%^C238%^ a wave of %^C025%^f%^C031%^e%^C037%^a%^C043%^r %^C238%^and %^C043%^d%^C037%^e%^C031%^s%^C025%^p%^C031%^a%^C037%^i%^C043%^r %^C238%^bursts forth the moment" + my_pron + "%^C238%^opens" + my_poss + "%^C043%^f%^C037%^i%^C031%^s%^C025%^t%^C031%^s%^C238%^.%^RESET%^", caster);

    caster->set_property("spelled", ({ this_object() }));
    caster->set_property("added short",({" SHORT DESC AURA MESS"}));
    caster->set_property("oppression", 1);
    addSpellToCaster();
    counter = 8 * clevel;
    spell_duration = counter * ROUND_LENGTH;
    set_end_time();
    execute_attack();
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(environment(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(environment(caster));

    call_out("room_check",ROUND_LENGTH * 2);
    return;
}

void execute_attack()
{
    object *foes, targ;
    int i, dam, enchant;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(environment(caster)))
    {
        dest_effect();
        return;
    }

    place = environment(caster);

    if(!objectp(place) || counter < 0)
    {
        dest_effect();
        return;
    }

    foes = caster->query_attackers();

    if(!sizeof(foes))
        saved = ({  });

    foes -= saved;

    if(sizeof(foes))
    {
        tell_room("LIGHNING MESSAGE");
            
        foreach(object ob in foes)
        {
            if(!objectp(ob))
                continue;
          
            ob->cause_typed_damage(ob, "torso", sdamage / 2, "electricity");
            
            if(!objectp(ob))
                continue;

            if(!do_save(ob, 0)) //unlike oppression, overcomes fear immunity
            {
                tell_object(ob, "%^C238%^You can't %^C240%^r%^C242%^e%^C244%^s%^C246%^i%^C248%^s%^C250%^t %^C238%^the the %^C025%^c%^C031%^o%^C037%^l%^C043%^d %^C238%^grip on your heart, %^C025%^f%^C031%^e%^C037%^a%^C043%^r %^C238%^and %^C043%^d%^C037%^e%^C031%^s%^C025%^p%^C031%^a%^C037%^i%^C043%^r %^C238%^quickly replace %^C220%^b%^C221%^r%^C222%^a%^C223%^v%^C224%^e%^C230%^r%^C229%^y %^C238%^and %^C229%^h%^C230%^a%^C224%^p%^C223%^p%^C222%^i%^C221%^n%^C220%^e%^C221%^s%^C221%^s%^C238%^.%^RESET%^");
                tell_room(place, "%^C238%^You watch as the %^C240%^d%^C242%^a%^C244%^r%^C246%^k a%^C244%^u%^C242%^r%^C240%^a fills %^C025%^f%^C031%^e%^C037%^a%^C043%^r %^C238%^into%^C025%^" + my_name + "'s %^C238%^heart.%^RESET%^", ob);
                "/std/effect/status/shaken"->apply_effect(ob, 1, caster);
            }
            else
            {
                tell_object(ob, "%^C238%^You manage to %^C220%^s%^C221%^h%^C222%^r%^C223%^u%^C229%^g %^C238%^off the %^C025%^o%^C031%^p%^C037%^p%^C043%^r%^C037%^e%^C031%^s%^C025%^s%^C031%^i%^C037%^v%^C043%^e %^C238%^aura.%^RESET%^");
                tell_room(place, "%^C025%^" + ob->query_cap_name() + " %^C238%^manages to %^C220%^s%^C221%^h%^C222%^r%^C223%^u%^C229%^g %^C238%^off the %^C025%^o%^C031%^p%^C037%^p%^C043%^r%^C037%^e%^C031%^s%^C025%^s%^C031%^i%^C037%^v%^C043%^e %^C238%^aura.%^RESET%^", ob);
                saved += ({ ob });
            }
        }
    }

    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster))
    {
        tell_room(environment(caster), "%^C024%^" + caster->query_cap_name() + "'s oppressive aura dissipates.%^CRST%^", caster);
        tell_object(caster, "%^C081%^Your oppressive aura dissipates.%^CRST%^");
        caster->remove_property_value("added short",({" SHORT DESC AURA"}));
        caster->remove_property("oppression");
    }
    ::dest_effect();

    if (objectp(this_object()))
        this_object()->remove();
}
