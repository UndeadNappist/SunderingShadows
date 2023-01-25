#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create(){
    ::create();
    set_spell_name("thunder wave");
    set_spell_level(([ "monk" : 5 ]));
    set_monk_way("way of the elements");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS thunder wave");
    set_description("This spell creates a wave of thunderous force, all creatures around the caster must make a fortitude save or be damaged and knocked to the ground. Furthermore, all inanimate objects not attached and on the ground may be knocked away.%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    //set_target_required(1);
    set_save("fort");
    set_components(([
    ]));
}

string query_cast_string(){
    return "%^RESET%^%^CRST%^%^C103%^"+caster->QCN+" raises "+caster->QP+" hands in the air and begins focusing intently!%^CRST%^%^RESET%^";
}

void spell_effect(int prof)
{
    int dam, i;
    object *foes, *obs;
    string *myExits, myExit, myPlace, myFrom, myWhere;

    if(!objectp(caster)){
        dest_effect();
        return;
    }
    foes = ({});
    tell_object(caster, "%^CRST%^%^RESET%^%^C231%^You focus your %^C159%^inner ki%^RESET%^%^C231%^, releasing it with a %^C195%^d%^C153%^e%^C189%^a%^C195%^fen%^C189%^i%^C153%^n%^C195%^g b%^C189%^o%^C153%^o%^C195%^m%^RESET%^%^C231%^!%^CRST%^");
    tell_object(caster, "%^CRST%^%^RESET%^%^C152%^A %^C151%^th%^C145%^und%^C146%^ero%^C152%^us w%^C151%^av%^C145%^e%^RESET%^%^C152%^ of %^C146%^force%^RESET%^%^C152%^ rolls out from you in all directions!%^CRST%^");
    tell_room(place, "%^CRST%^%^RESET%^%^C152%^With a %^C151%^th%^C145%^und%^C146%^ero%^C152%^us b%^C151%^oo%^C145%^m%^RESET%^%^C152%^, a wave of %^C146%^force%^RESET%^%^C152%^ rolls out from "+caster->QCN+" going in all directions!%^CRST%^", caster);

    foes += target_selector();
    if(!sizeof(foes)) if(objectp(environment(environment(caster)))) foes += all_living(environment(caster));
    if(member_array(caster,foes) != -1) foes -= ({caster});

    if(spell_type == "monk" && sizeof(foes)) { MAGIC_D->elemental_opportunist(caster, foes[0]); }
    for(i=0;i<sizeof(foes);i++){
        if(!objectp(foes[i])) continue;
        if(foes[i]->id(""+caster->query_name()+" summoned")) continue;
        if(foes[i]->id(""+(string)caster->query_name()+" retainer")) continue;
        if(evade_splash(foes[i])) continue; //evasion
        
        tell_object(foes[i], "%^RESET%^%^CRST%^%^C103%^The wave of force slams into you!%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C103%^The wave of force slams into "+foes[i]->QCN+"!%^CRST%^", foes[i]);
        
        define_base_damage(0);
        dam = sdamage;

        if(!do_save(foes[i])){
            tell_object(foes[i], "%^CRST%^%^RESET%^%^C067%^You are thrown %^C066%^violently%^RESET%^%^C067%^ to the ground!%^CRST%^");
            foes[i]->set_tripped(1, "%^CRST%^%^RESET%^%^C068%^You are struggling to get back to your feet!%^CRST%^");
            tell_room(place, "%^CRST%^%^RESET%^%^C067%^"+foes[i]->QCN+" is thrown %^C066%^violently%^RESET%^%^C067%^ to the ground!%^CRST%^", foes[i]);
        }
        else dam /= 2;
        damage_targ(foes[i],foes[i]->return_target_limb(),dam,"force");
        continue;
    }
    if(objectp(place)){
        myExits = place->query_exits();
        if(sizeof(myExits)){
            myFrom = base_name(place);
            if(living(caster)) obs = all_inventory(place);
            obs = filter_array(obs, "is_nonliving", FILTERS_D);
            for(i = 0;i < sizeof(obs);i++){
                if(!objectp(obs[i])) continue;
                if(obs[i]->query_property("no animate")) continue;
                if(obs[i]->query_property("no get")) continue;
                if((int)obs[i]->query_weight() > clevel) continue;
                if(!stringp(obs[i]->query_short())) continue;
                if(random(5)) continue;

                myExit = myExits[random(sizeof(myExits))];
                if(!place->query_open(myExit) && place->is_vault()){
                    myExits -= ({myExit});
                    if(!sizeof(myExits)) break;
                    myExit = myExits[random(sizeof(myExits))];
                    if(!place->query_open(myExit) && place->is_vault()){
                        myExits -= ({myExit});
                        continue;
                    }
                }
                
                tell_room(place, "%^CRST%^%^RESET%^%^C080%^"+obs[i]->query_short()+ " is thrown "+myExit+" by the powerful wave of force!%^CRST%^");
                
                myPlace = place->query_exit(myExit);
                obs[i]->move(myPlace);
                if(!objectp(environment(obs[i]))) continue;
                if(stringp(myWhere = environment(obs[i])->query_direction(myFrom))){
                    tell_room(environment(obs[i]), "%^CRST%^%^RESET%^%^C080%^"+obs[i]->query_short()+" is suddenly thrown into the area from the "+myWhere+"!%^CRST%^");
                }
                else{
                    tell_room(environment(obs[i]), "%^CRST%^%^RESET%^%^C080%^"+obs[i]->query_short()+" is suddenly thrown into the area!%^CRST%^");
                }
                continue;
            }
        }
    }
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

