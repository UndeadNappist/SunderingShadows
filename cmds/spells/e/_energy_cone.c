#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void dest_effect();

#define MYTYPES ({ "fire", "electricity", "cold", "acid", "sonic", "random" })

void create() {
    ::create();
    set_spell_name("energy cone");
    set_spell_level(([ "psion" : 3 ]));
    set_discipline("kineticist");
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS energy cone on TARGET [as TYPE]");
    set_description("Similar to energy bolt, this cone is a specialized version manifested by kineticists. Unlike energy bolt, this cone strikes nearby targets as well, giving the kineticist additional power in battles against multiple enemies. When manifesting the power, please choose one of the following types: fire, electricity, cold, acid, sonic, or random. If you do not specify, it will be random.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_save("reflex");
    splash_spell(2);
    set_target_required(1);
}

string query_cast_string(){
    return "%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^'s eyes burn like points of %^C249%^s%^C252%^i%^C255%^lv%^C252%^e%^C249%^r %^C252%^f%^C255%^i%^C252%^r%^C249%^e %^RESET%^%^C101%^as "+caster->query_subjective()+" places "+caster->query_possessive()+" wrists together and splays "+caster->query_possessive()+" fingers.%^CRST%^";
}

void spell_effect(int prof){
    int damage,num,stop, mylevel,mynum;
    object *foes, *ownparty;
    string energy, color, dam_type, thetarg, args, realname;

    damage = 0;
    if(!arg) {
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You need to specify a target and a type for this power!%^CRST%^");
        dest_effect();
        return;
    }
    if(sscanf(arg,"%s as %s",thetarg,args) != 2){
        thetarg = arg;
        args = "random";
    }
    if(member_array(args,MYTYPES) == -1){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^That is not a valid type!%^CRST%^");
        dest_effect();
        return;
    }
    if(thetarg == "attacker"){
        target = caster->query_current_attacker();
        if(!objectp(target)){
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You don't see an attacker here!%^CRST%^");
            dest_effect();
            return;
        }
    }
    else{
        target = present(thetarg,environment(caster));
        if(!objectp(target)){
            if(userp(caster)) realname = caster->realName(thetarg);
            else realname = thetarg;
            if(avatarp(caster) && !objectp(target)) realname = thetarg; // it was screwing out on imms.
            target = present(realname,place);
            if(!objectp(target)){
                tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You don't see "+thetarg+" here!%^CRST%^");
                dest_effect();
                return;
            }
          dest_effect();
          return;
       }
    }
    foes = ({});
    ownparty = ({});
    mylevel = clevel;
    if(environment(caster) != environment(target)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Your target has left your range.%^CRST%^\n");
        dest_effect();
        return;
    }
    //damage = roll_dice(mylevel,6);

    if(args == "random"){
        mynum = random(5);
        args = MYTYPES[mynum];
    }
    spell_successful();
    switch(args){
        case "fire": color = "%^C214%^";
            energy = "%^C208%^f%^C214%^i%^C208%^r%^C202%^e";
            dam_type = "fire";
            break;
        case "electricity": color = "%^C100%^";
            energy = "%^C228%^l%^C231%^i%^C228%^ght%^C226%^n%^C231%^i%^C228%^n%^C226%^g";
            dam_type = "electricity";
            break;
        case "cold": color = "%^C039%^";
            energy = "%^C081%^i%^C087%^c%^C081%^e";
            dam_type = "cold";
            break;
        case "acid": color = "%^C065%^";
            energy = "%^C077%^a%^C071%^c%^C070%^i%^C076%^d";
            dam_type = "acid";
            break;
        default: color = "%^C090%^";
            energy = "%^C218%^s%^C212%^o%^C206%^u%^C212%^n%^C218%^d";
            dam_type = "sonic";
            break;
    }
    foes += target_selector();

    if(!sizeof(foes)){
        dest_effect();
        return;
    }

    if (caster->query_party()){
        ownparty=PARTY_D->query_party_members(caster->query_party());
        foes -= ownparty;
    }
    else{
        ownparty = ({ caster });
    }

    foes -= ({caster});

    foes = distinct_array(foes);
    foes -= ({target});
    if(caster->query_followers()) foes -= caster->query_followers();
    
    tell_object(caster, "%^RESET%^%^CRST%^"+color+"You summon a latent energy inside your mind and send forth a wave of "+energy+"%^RESET%^%^CRST%^"+color+" into "+target->query_cap_name()+"%^RESET%^%^CRST%^"+color+"!%^CRST%^");
    tell_object(target, "%^RESET%^%^CRST%^"+color+caster->query_cap_name()+"%^RESET%^%^CRST%^"+color+" inhales sharply before focusing "+caster->query_possessive()+" entire being on you!\n%^RESET%^%^CRST%^"+color+"Suddenly, a wave of "+energy+"%^RESET%^%^CRST%^"+color+" shoots forth from "+caster->query_possessive()+" palms and envelopes you!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^"+color+caster->query_cap_name()+"%^RESET%^%^CRST%^"+color+" focuses on "+target->query_cap_name()+"%^RESET%^%^CRST%^"+color+" and sends forth a wave of "+energy+"%^RESET%^%^CRST%^"+color+" from "+caster->query_possessive()+" palms, enveloping "+target->query_objective()+"%^RESET%^%^CRST%^"+color+"!%^CRST%^", ({caster, target}));
    
    if(!do_save(target,0)){
    //if (!do_saving_throw(target, "spell", 0)) {
        damage_targ(target, target->return_target_limb(), sdamage,dam_type);
    }
    else{
        damage_targ(target, target->return_target_limb(), to_int(sdamage/2),dam_type);
    }
    stop = random(mylevel);
    if(sizeof(foes)){
        for(num=0;num<sizeof(foes);num++){
            if(!objectp(foes[num])) continue;
            if(!living(foes[num])) continue;
            tell_object(foes[num], "%^RESET%^%^CRST%^"+color+"You are hit by the wave of "+energy+"%^RESET%^%^CRST%^"+color+"!%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^"+color+foes[num]->query_cap_name()+"%^RESET%^%^CRST%^"+color+" is hit by the wave of "+energy+"%^RESET%^%^CRST%^"+color+"!%^CRST%^", foes[num]);
            if(!do_save(foes[num],0)) {
            //if (!do_saving_throw(foes[num], "spell", 0)) {
                damage_targ(foes[num], foes[num]->return_target_limb(), sdamage,dam_type);
            }
            else{
                damage_targ(foes[num], foes[num]->return_target_limb(), to_int(sdamage/2),dam_type);
            }
            if(!stop) break;
        }
    }
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

