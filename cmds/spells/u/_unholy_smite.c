#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("unholy smite");
    set_spell_level(([ "cleric" : 4, "inquisitor" : 4 ]));
    set_domains("evil");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS unholy smite");
    set_damage_desc("divine on neutral and good");
    set_description("You draw down holy power to smite your enemies, possibly blinding them. Only good and neutral creatures are harmed by the spell, evil creatures are unaffected..");
    evil_spell(1);
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("will");
}

string query_cast_string() {
    return "%^RESET%^%^C244%^"+caster->QCN+" %^RESET%^%^C244%^proclaims a %^RESET%^%^C240%^d%^C241%^i%^C242%^v%^C243%^i%^C241%^n%^C240%^e %^RESET%^%^C240%^p%^C241%^r%^C242%^a%^C243%^y%^C241%^e%^C240%^r %^RESET%^%^C244%^of %^RESET%^%^C088%^s%^C124%^m%^C160%^i%^C196%^t%^C160%^i%^C124%^n%^C088%^g%^RESET%^%^C244%^.%^CRST%^";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^RESET%^%^C244%^"+caster->QCN+" %^RESET%^%^C244%^raises hand and %^RESET%^%^C240%^d%^C241%^a%^C241%^r%^C240%^k %^RESET%^%^C240%^f%^C241%^l%^C242%^a%^C243%^m%^C241%^e%^C240%^s %^RESET%^%^C244%^burst out of "+caster->QO+" %^RESET%^%^C244%^in all directions!%^CRST%^");
    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^BLUE%^The area is blanketed with flames but nothing else happens.%^CRST%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        int align = attackers[i]->query_alignment();
        if(!objectp(attackers[i]))
            continue;
        if(!(align %3))
            continue;
        admg=sdamage;
        if(do_save(attackers[i]),-2)
        {
            admg/=2;
        }
        else
        {
            tell_object(attackers[i],"%^BOLD%^%^BLUE%^The darknes covers your eyes, blinding you!%^RESET%^");
            attackers[i]->set_temporary_blinded(3);
        }
        tell_object(attackers[i],"%^BOLD%^%^BLUE%^Your soul withers in the dark flames!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"divine");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
