/*
  _black_tentacles.c
  
  Functional rewrite of previous spell.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

object *grappled, *targets, stagger;
int flag;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("black tentacles");
    set_spell_sphere("conjuration_summoning");
    set_spell_level( ([ "mage" : 4, "cleric" : 4, "magus" : 4, "warlock" : 3, "druid" : 4 ]) );
    set_domains("nightmare");
    set_syntax("cast CLASS black tentacles");
    set_damage_desc("staggered or tripped and force damage");
    set_description("This spell summons up a mass of writhing black tentacles from the earth at your feet. These will ensnare anything nearby to slow their escape, and attempt to knock them from their feet. Enemies in the room must defend against a combat maneuver roll (caster CMB + 4) or become staggered as the tentacles grapple them. Grappled targets must attempt a new maneuver check each round until they succeed and then will no longer have to make such checks. Those that are not grappled must pass a reflex save each round or become tripped.");
    set_save("reflex");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

int preSpell()
{
    if (!objectp(caster))
        return 0;

    if (caster->query_property("black tentacles"))
    {
        tell_object(caster, "%^RESET%^%^C241%^You are already maintaining such a spell!%^CRST%^");
        return 0;
    }

    return 1;
}

string query_cast_string()
{
    if (!objectp(caster))
        return "";

    if (!objectp(place))
        return "";

    tell_object(caster, "%^RESET%^%^C241%^You kneel down, %^RESET%^%^C039%^w%^C045%^h%^C051%^i%^C087%^s%^C123%^p%^C159%^e%^C087%^r%^C051%^i%^C045%^n%^C039%^g %^RESET%^%^C241%^your summons through the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h%^RESET%^%^C241%^.%^CRST%^");
    tell_room(place, "%^RESET%^%^C241%^Kneeling, " + caster->query_cap_name() + " %^RESET%^%^C051%^w%^C087%^h%^C123%^i%^C159%^s%^C195%^p%^C123%^e%^C087%^r%^C051%^s %^RESET%^%^C241%^a summoning through the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h%^RESET%^%^C241%^.%^RESET%^", caster);
    return "display";
}

void spell_effect()
{
    object stagger;
    
    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }
    if(place != environment(caster))
    {
        tell_object(caster, "Your movement has interrupted the spell!");
        dest_effect();
        return;
    }
    
    targets = target_selector();
    grappled = ({  });
    
    if (!sizeof(targets))
    {
        tell_object(caster, "%^RESET%^%^C241%^From just beneath the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h %^RESET%^%^C241%^at your feet, you feel the %^RESET%^%^C051%^s%^C087%^h%^C123%^i%^C159%^v%^C087%^e%^C051%^r %^RESET%^%^C241%^of the %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^C240%^s %^RESET%^%^C241%^as they find no target to ensnare, and simply %^RESET%^%^C240%^f%^C244%^a%^C248%^d%^C252%^e %^RESET%^%^C241%^away.%^CRST%^");
        dest_effect();
        return;
    }
    
    spell_successful();
    caster->set_property("black tentacles", 1);
    
    tell_room(place, "%^RESET%^%^C240%^R%^C241%^u%^C242%^b%^C241%^b%^C240%^e%^C241%^r%^C242%^y %^RESET%^%^C241%^b%^C240%^l%^C241%^a%^C242%^c%^C241%^k %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^C240%^s %^RESET%^%^C241%^writhe up out of the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h%^RESET%^%^C241%^, coiling and grasping at anything within reach!%^CRST%^");
    
    stagger = load_object("/std/effect/status/staggered");
    
    foreach(object ob in targets)
    {
        if(objectp(stagger) && BONUS_D->combat_maneuver(ob, caster, 4))
        {
            tell_object(ob, "%^RESET%^%^C241%^One manages to wrap about your leg and %^RESET%^%^C240%^e%^C241%^n%^C242%^s%^C243%^n%^C242%^a%^C241%^r%^C240%^e %^RESET%^%^C241%^you!%^CRST%^");
            tell_room(place, "%^RESET%^%^C241%^One manages to wrap about " + ob->query_cap_name()+ "%^RESET%^%^C241%^'s leg and %^RESET%^%^C240%^e%^C241%^n%^C242%^s%^C243%^n%^C242%^a%^C241%^r%^C240%^e%^RESET%^%^C241%^ " + ob->query_objective() + "%^RESET%^%^C241%^!%^CRST%^", ob);
            ob->set_property("added short", ({ "%^RESET%^%^C240%^ (%^RESET%^%^C241%^e%^C242%^n%^C243%^t%^C242%^a%^C241%^n%^C242%^g%^C243%^l%^C242%^e%^C241%^d%^RESET%^%^C240%^)%^CRST%^" }));
            stagger->apply_effect(ob, ROUND_LENGTH, caster);
            damage_targ(ob, "torso", sdamage, "force");
            grappled += ({ ob });
            continue;
        }
        if(!do_save(ob, 0))
        {
            tell_object(ob, "%^RESET%^%^C241%^You %^RESET%^%^C063%^s%^C075%^t%^C081%^u%^C087%^m%^C075%^b%^C069%^l%^C063%^e %^RESET%^%^C241%^as one of the %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^C240%^s %^RESET%^%^C241%^almost knocks you from your feet!%^CRST%^");
            tell_room(place, "%^RESET%^%^C241%^" + ob->query_cap_name() + " %^RESET%^%^C063%^s%^C069%^t%^C075%^u%^C081%^m%^C087%^b%^C075%^l%^C069%^e%^C063%^s %^RESET%^%^C241%^as a %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e %^RESET%^%^C240%^knocks " + ob->query_objective() + " %^RESET%^%^C241%^from " + ob->query_possessive() + " %^RESET%^%^C241%^feet!%^CRST%^", ob);
            damage_targ(ob, "torso", sdamage / 2, "bludgeoning");
            ob->set_tripped(1, "%^RESET%^%^C241%^You're regaining your %^RESET%^%^C049%^b%^C050%^a%^C051%^l%^C123%^a%^C051%^n%^C050%^c%^C049%^e%^RESET%^%^C241%^!%^CRST%^", 1);
            continue;
        }
        
    }
    addSpellToCaster();
    duration = (clevel / 10 + 3) * ROUND_LENGTH;
    spell_duration = duration;
    set_end_time();
    execute_attack();
    call_out("dest_effect", duration);
}

void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(environment(caster) != place)
    {
        dest_effect();
        return;
    }
    if(caster->query_unconscious())
    {
        dest_effect();
        return;
    }
    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }
    
    grappled = filter_array(grappled, (: objectp($1) :));
    
    if(!sizeof(grappled))
    {
        dest_effect();
        return;
    }
    
    define_base_damage(0);
    
    foreach(object ob in grappled)
    {

        if(objectp(stagger) && BONUS_D->combat_maneuver(ob, caster, 0))
        {
            tell_object(ob, "%^RESET%^%^C241%^The %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C240%^e %^RESET%^%^C241%^s%^C242%^q%^C243%^u%^C242%^e%^C241%^e%^C242%^z%^C243%^e%^C242%^s %^RESET%^%^C241%^the %^RESET%^%^C036%^l%^C037%^i%^C038%^f%^C039%^e %^RESET%^%^C241%^from you!%^CRST%^");
            tell_room(place, "%^RESET%^%^C241%^The %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C240%^e squeezes around " + ob->query_cap_name() + "!", ob);
            damage_targ(ob, "torso", sdamage / 5, "force");
        }
        else
        {
            tell_object(ob, "%^RESET%^%^C241%^You %^RESET%^%^C088%^r%^C124%^i%^C088%^p %^RESET%^%^C241%^free of the %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C240%^e%^RESET%^%^C241%^!%^CRST%^");
            tell_room(place, "%^RESET%^%^C241%^" + ob->query_cap_name() + " %^RESET%^%^C088%^r%^C124%^i%^C160%^p%^RESET%^%^C088%^s %^RESET%^%^C241%^free of the %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C240%^e%^RESET%^%^C241%^!%^CRST%^", ob);
            ob->remove_property_value("added short", ({ "%^RESET%^%^C240%^ (%^RESET%^%^C241%^e%^C242%^n%^C243%^t%^C242%^a%^C241%^n%^C242%^g%^C243%^l%^C242%^e%^C241%^d%^RESET%^%^C240%^)%^CRST%^" }));
            grappled -= ({ ob });
        }
    }
    
    targets = target_selector() - grappled;
    targets = filter_array(targets, (: (!$1->query_tripped() && objectp($1)) :));
    
    foreach(object ob in targets)
    {
        if (!do_save(ob, 0))
        {
            tell_object(ob, "%^RESET%^%^C241%^You %^RESET%^%^C063%^s%^C069%^t%^C075%^u%^C081%^m%^C075%^b%^C069%^l%^C063%^e%^RESET%^%^C241%^ as one of the " + "%^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^RESET%^%^C240%^s %^RESET%^%^C241%^almost knocks you from your feet!%^CRST%^");
            tell_room(place, "%^RESET%^%^C241%^" + ob->query_cap_name() + " %^RESET%^%^C063%^s%^C069%^t%^C075%^u%^C081%^m%^C087%^b%^C075%^l%^C069%^e%^C063%^s %^RESET%^%^C241%^as a %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C240%^e %^RESET%^%^C241%^knocks " + ob->query_objective() + " %^RESET%^%^C241%^ " + ob->query_subjective() + " %^RESET%^%^C241%^feet!%^CRST%^", ob);
            ob->set_tripped(1, "%^RESET%^%^C241%^You're regaining your " + "%^RESET%^%^C049%^b%^C050%^a%^C051%^l%^C123%^a%^C051%^n%^C050%^c%^C049%^e%^RESET%^%^C241%^!%^CRST%^", 1);
        }
    }
    
    if(place != environment(caster) || caster->query_unconscious())
    {
        dest_effect();
        return;
    }
    else
    {
        place->addObjectToCombatCycle(this_object(), 1);
        return;
    }
}

void dest_effect()
{
    tell_room(place, "%^RESET%^%^C241%^The %^RESET%^%^C240%^w%^C241%^r%^C242%^i%^C241%^t%^C240%^h%^C241%^i%^C242%^n%^RESET%^%^C240%^g %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^RESET%^%^C240%^s %^RESET%^%^C051%^s%^C087%^h%^C123%^i%^C159%^v%^C087%^e%^C051%^r " + "%^RESET%^%^C241%^and crumble into %^RESET%^%^C250%^dust%^RESET%^%^C241%^, %^RESET%^%^C240%^f%^C244%^a%^C248%^d%^C250%^i%^C252%^n%^C254%^g %^RESET%^%^C241%^before your eyes.%^RESET%^");
    
    if(sizeof(grappled))
    {
        foreach(object ob in grappled)
        {
            if(!objectp(ob))
                continue;
            
            ob->remove_property_value("added short", ({ "%^RESET%^%^C240%^ (%^RESET%^%^C241%^e%^C242%^n%^C243%^t%^C242%^a%^C241%^n%^C242%^g%^C243%^l%^C242%^e%^C241%^d%^RESET%^%^C240%^)%^CRST%^" }));
        }
    }
    
    objectp(caster) && caster->remove_property("black tentacles");
    
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
    
    