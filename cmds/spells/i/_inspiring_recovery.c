#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

create(){
    ::create();
    set_spell_name("inspiring recovery");
    set_spell_level(([ "psion" : 5 ]));
    set_spell_sphere("psychometabolism");
    set_discipline("egoist");
    set_syntax("cast CLASS inspiring recovery on TARGET");
    set_damage_desc("healing or revive recently deceased");
    set_description("You channel psychic energy into the target, helping their body repair their wounds or resuscitate them if they're deceased. Does not work on undead creatures or constructs.\n\nThis spell accepts the recognized player's name or their corpse as the TARGET if they are deceased.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_non_living_ok(1);
	set_helpful_spell(1);
}

spell_effect(int prof){
    string what, theirname, dam_type;
    object corpse, targ;

    ::spell_effect();

    if(!objectp(target)){
        theirname = caster->realName(lower_case(arg));
        target = find_player(theirname);
    }

    if(!objectp(target)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You need a target.%^CRST%^");
        dest_effect();
    }

    if(target->is_corpse()||target->query_ghost()){
        if(target->is_corpse()) corpse = target;
        else corpse = present("corpse of $&$"+target->query_true_name()+"$&$",place);

        if(!interactive(target)){
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You can only revive interactive players.%^CRST%^");
            dest_effect();
            return;
        }
        if(interactive(caster)){
            set_cast_string("%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ focuses intently...%^CRST%^\n");
            tell_object(caster, "%^RESET%^%^CRST%^%^C101%^You attempt to resuscitate "+capitalize(arg)+"%^RESET%^%^CRST%^%^C101%^!%^CRST%^");
            tell_room(environment(CASTER), "%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ tries to resuscitate "+capitalize(arg)+"%^RESET%^%^CRST%^%^C101%^!%^CRST%^", ({ caster, target}));
        }
        else{
            set_cast_string("%^RESET%^%^CRST%^%^C101%^" + caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ channels %^C206%^p%^C200%^s%^C218%^y%^C212%^c%^C206%^h%^C200%^i%^C218%^c %^C212%^e%^C206%^n%^C200%^e%^C218%^r%^C212%^g%^C206%^y %^C144%^into "+capitalize(arg)+"%^RESET%^%^CRST%^%^C101%^, attempting to resuscitate them!%^CRST%^\n");
        }
        if(!target->query_ghost()){
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^" + capitalize(arg) + "%^RESET%^%^CRST%^%^C059%^ does not need to be revived.%^CRST%^");
            dest_effect();
            return;
        }
        if(!objectp(corpse)){
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^" + capitalize(arg) + "%^RESET%^%^CRST%^%^C059%^'s corpse is not here.%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C059%^You think you feel a faint pull on your soul, but it is gone as soon as it begins.%^CRST%^");
            dest_effect();
            return;
        }
        tell_object(caster, "%^RESET%^%^CRST%^%^C144%^You can feel %^C206%^p%^C200%^s%^C218%^y%^C212%^c%^C206%^h%^C200%^i%^C218%^c %^C212%^e%^C206%^n%^C200%^e%^C218%^r%^C212%^g%^C206%^y %^C144%^flow out to "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^'s body, and know that "+target->query_possessive()+" life is in "+target->query_possessive()+" own hands now.%^CRST%^");
        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C144%^The power of "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^'s %^C206%^p%^C200%^s%^C218%^y%^C212%^c%^C206%^h%^C200%^i%^C218%^c %^C212%^e%^C206%^n%^C200%^e%^C218%^r%^C212%^g%^C206%^y %^C144%^flows through the area as "+caster->query_subjective()+" tries to bring "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ back to life!%^CRST%^", caster);
        target->set("RaisingPriestGod",caster->query_property("hidden deity")||caster->query_diety());
        target->set("RaisingPriestAlignment",caster->query_alignment());
        target->set("RaisingRoom",base_name(environment(caster)));
        target->set("RaisingExpLoss",(-10+(random(2)+random(3)+1)));
        target->set("RaisingType","raise dead");
        tell_object(target, "%^RESET%^%^CRST%^%^C144%^You can feel a pull on your soul. You sense a powerful %^C206%^p%^C200%^s%^C218%^y%^C212%^c%^C206%^h%^C200%^i%^C218%^c %^C212%^e%^C206%^n%^C200%^e%^C218%^r%^C212%^g%^C206%^y %^C144%^is trying to return you to consciousness!\n%^RESET%^%^CRST%^%^C059%^Type %^C255%^<accept>%^C059%^ to return to life, or %^C255%^<cancel>%^C059%^ to die.%^CRST%^");
        corpse->remove();
    }
    else{
        if(target->is_undead() || USER_D->is_valid_enemy(target->query_race(), "constructs")){
            tell_room(place, "%^RESET%^%^CRST%^%^C144%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ places "+caster->query_possessive()+" hand on "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ and channels %^C206%^p%^C200%^s%^C218%^y%^C212%^c%^C206%^h%^C200%^i%^C218%^c %^C212%^e%^C206%^n%^C200%^e%^C218%^r%^C212%^g%^C206%^y %^C144%^into them, but %^C059%^nothing happens%^C144%^!%^CRST%^", caster);
        }
        else{
            tell_room(place,"%^RESET%^%^CRST%^%^C144%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ places "+caster->query_possessive()+" hand on "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ and wills their body to %^C255%^heal%^C144%^!%^CRST%^");
            damage_targ(target, "torso", -sdamage, "untyped");
        }
    }
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}
