#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

#define POISONS ({ "wyvern_poison", "shadow_essence", "purple_worm_poison", "large_scorpion_venom", "giant_wasp_poison", "deathblade" })
#define PDIR "/d/common/obj/poisons/base/"

object wpn;

void create()
{
    ::create();
    set_spell_name("poison");
    set_spell_level(([ "cleric" : 4, "druid" : 3, "paladin" : 4, "assassin" : 1, "inquisitor" : 3, "ranger":3]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS poison on TARGET|WEAPON");
    set_description("With this spell you create a natural poison and either envenom your target with it, or apply it to a weapon in your possession.\n\n%^BOLD%^%^RED%^See also:%^RESET%^ poison *player commands");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf;
    object targ;

    if (!objectp(place)) {
        return;
    }

    poisonf = PDIR+POISONS[random(sizeof(POISONS))];

    targ = present(arg,place);

    if(objectp(targ) &&
       !living(targ))
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^That is not a living being!%^CRST%^");
        TO->remove();
        return;
    }

    if(objectp(targ))
    {
        tell_object(caster,"%^RESET%^%^CRST%^%^C100%^You extend your hand and an %^C094%^o%^C095%^i%^C096%^l%^C095%^y %^C094%^t%^C095%^h%^C096%^o%^C095%^r%^C094%^n %^RESET%^%^C100%^flies out of it straight into "+targ->QCN+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^");
        tell_room(place,"%^RESET%^%^CRST%^%^C100%^"+caster->QCN+"%^RESET%^%^CRST%^%^C100%^ extends "+caster->QP+" hand and an %^C094%^o%^C095%^i%^C096%^l%^C095%^y %^C094%^t%^C095%^h%^C096%^o%^C095%^r%^C094%^n %^RESET%^%^C100%^flies out of it straight into %^BOLD%^"+targ->QCN+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^",({caster}));
        POISON_D->ApplyPoison(targ,poisonf,caster,"injury");
        spell_kill(targ,caster);
        dest_effect();
        return;
    }
    targ = present(arg,caster);
    if(!objectp(targ))
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Cant find "+arg+" in your inventory!%^CRST%^");
        TO->remove();
        return;
    }
    if(!targ->is_weapon())
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^That is not a weapon!%^CRST%^");
        TO->remove();
        return;
    }
    if(objectp(targ))
    {
        string pname;
        object poisono;

        poisono=new(poisonf);
        if(!objectp(poisono))
        {
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^The poisoning didn't seem to take effect!%^CRST%^");
            TO->remove();
            return;
        }
        wpn = targ;

        pname = poisono->query_poison_name();
        wpn->set("PoisonDoses", clevel/5);
        wpn->set("PoisonType", pname);
        wpn->set("whoImmune", caster->query_name());
        if(wpn->query_property("temp_oiled")){
            wpn->remove_property("temp_oiled");
        }
        wpn->set_property("temp_oiled","damage bonus acid 5");
        tell_object(caster, "%^RESET%^%^CRST%^%^C100%^A layer of %^C094%^p%^C095%^o%^C096%^i%^C095%^s%^C094%^o%^C095%^n%^C096%^o%^C095%^u%^C094%^s %^C095%^v%^C096%^e%^C095%^n%^C094%^o%^C095%^m %^RESET%^%^C100%^appears on "+wpn->query_name()+" %^RESET%^%^CRST%^%^C100%^as you move your hand along it.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C100%^A layer of %^C094%^p%^C095%^o%^C096%^i%^C095%^s%^C094%^o%^C095%^n%^C096%^o%^C095%^u%^C094%^s %^C095%^v%^C096%^e%^C095%^n%^C094%^o%^C095%^m %^RESET%^%^C100%^appears on "+wpn->query_name()+" %^RESET%^%^CRST%^%^C100%^as "+caster->QCN+"%^RESET%^%^CRST%^%^C100%^ moves "+caster->QP+" hand along it.%^CRST%^",({caster}));
        dest_effect();
        return;
    }
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
