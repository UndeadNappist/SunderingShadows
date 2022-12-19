//removed mention of non-specialized mages ~Circe~ 8/2/19
#include <std.h>
#include <priest.h>
inherit SPELL;

int timer,flag,stage,toggle,counter;
string shield_type;
string element = "fire";

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("fire shield");
    set_spell_level(([ "mage" : 4, "magus" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS fire shield [on chill|warm]");
    set_damage_desc("fire or cold");
    set_description("This spell will surround the caster's body in a roaring shield of flames. Any opponent striking the caster will take damage from the blistering heat. You can manipulate base element of the spell, casting it either on chill or warm.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_helpful_spell(1);
    traveling_aoe_spell(1);
    set_arg_needed();
}

string query_cast_string(){
    if(arg == "chill"){
        tell_object(caster, "%^RESET%^%^CRST%^%^C124%^Circling your hands before you, you begin to evoke the power of %^C208%^f%^C214%^i%^C208%^r%^C202%^e%^C124%^.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C124%^Circling "+caster->QP+" hands before "+caster->QO+", "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^ begins to evoke the power of %^C208%^f%^C214%^i%^C208%^r%^C202%^e%^C124%^.%^CRST%^", caster);
    }
    else{
        tell_object(caster, "%^RESET%^%^CRST%^%^C030%^Circling your hands before you, you begin to evoke the power of %^C045%^i%^C051%^c%^C045%^e%^C030%^.%^CRST%^");
        tell_room(place,"%^RESET%^%^CRST%^%^C030%^Circling "+caster->QP+" hands before "+caster->QO+", "+caster->QCN+"%^RESET%^%^CRST%^%^C030%^ begins to evoke the power of %^C045%^i%^C051%^c%^C045%^e%^C030%^.%^CRST%^",caster);
    }
    return "display";
}

int preSpell(){
    if(caster->query_property("fire shield")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already under such protections.%^CRST%^");
        return 0;
    }
    if(arg == "chill") element = "cold";
    
    return 1;
}

void spell_effect(int prof){
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    if(element == "cold"){
        tell_room(place, "%^RESET%^%^CRST%^%^C051%^"+caster->QCN+"%^RESET%^%^CRST%^%^C051%^ completes "+caster->QP+" evocation and is surrounded by a %^C255%^gust %^C051%^of %^C255%^sn%^C250%^o%^C255%^wfl%^C250%^a%^C255%^k%^C250%^e%^C255%^s%^C051%^!%^CRST%^", caster);
        tell_object(caster, "%^RESET%^%^CRST%^%^C051%^You complete your evocation and are surrounded by a %^C255%^gust %^C051%^of %^C255%^sn%^C250%^o%^C255%^wfl%^C250%^a%^C255%^k%^C250%^e%^C255%^s%^C051%^!%^CRST%^");
        shield_type = " %^RESET%^%^CRST%^%^C051%^(%^C030%^wreathed in %^C255%^sn%^C250%^o%^C255%^wfl%^C250%^a%^C255%^k%^C250%^e%^C255%^s%^C051%^)%^CRST%^";
    }
    else{
        tell_room(place, "%^RESET%^%^CRST%^%^C196%^"+caster->QCN+"%^RESET%^%^CRST%^%^C196%^ completes "+caster->QP+" evocation and is surrounded by %^C208%^r%^C214%^o%^C208%^a%^C202%^r%^C208%^i%^C214%^n%^C208%^g %^C202%^f%^C208%^l%^C214%^a%^C208%^m%^C202%^e%^C208%^s%^RESET%^%^C196%^!%^CRST%^", caster);
        tell_object(caster, "%^RESET%^%^CRST%^%^C196%^You complete your evocation and are surrounded by %^C208%^r%^C214%^o%^C208%^a%^C202%^r%^C208%^i%^C214%^n%^C208%^g %^C202%^f%^C208%^l%^C214%^a%^C208%^m%^C202%^e%^C208%^s%^RESET%^%^C196%^!%^CRST%^");
        shield_type = " %^RESET%^%^CRST%^%^C196%^(%^C124%^wreathed in %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s%^C196%^)%^CRST%^";
    }
    
    caster->set_property("fire shield", 1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({ shield_type }));
    addSpellToCaster();
    spell_successful();
    counter = 6 * clevel;
    execute_attack();
    call_out("room_check", ROUND_LENGTH);
}

void room_check(){
    if(!objectp(caster) || !objectp(ENV(caster))){
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check", ROUND_LENGTH * 2);
    return;
}

void execute_attack(){
    object *foes=({}),targ;
    int i;

    if(!flag){
        flag = 1;
        ::execute_attack();
        return;
    }

    place = ENV(caster);

    if(!objectp(caster) || !objectp(place) || counter<0){
        dest_effect();
        return;
    }

    foes = caster->query_attackers();
    if (foes == ({ })) return;

    if(sizeof(foes)){
        define_base_damage(0);//reroll each turn
        if(element == "cold"){
            tell_room(place, "%^RESET%^%^CRST%^%^C030%^The %^C051%^chill %^C030%^around "+caster->QCN+"%^RESET%^%^CRST%^ %^C255%^fr%^C250%^e%^C255%^ez%^C250%^e%^C255%^s %^RESET%^%^C030%^"+caster->QP+" enemies!%^CRST%^", ({caster, target}));
            tell_object(caster, "%^RESET%^%^CRST%^%^C030%^The %^C051%^chill %^C030%^of your shield %^C255%^fr%^C250%^e%^C255%^ez%^C250%^e%^C255%^s %^RESET%^%^C030%^your enemies!%^CRST%^");
        }
        else{
            tell_room(place, "%^RESET%^%^CRST%^%^C124%^The %^C196%^flames %^C124%^around "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^ %^C208%^b%^C214%^u%^C208%^r%^C202%^n %^C124%^"+caster->QP+" enemies!%^CRST%^", ({caster, target}));
            tell_object(caster, "%^RESET%^%^CRST%^%^C124%^The %^C196%^flames %^C124%^of your shield %^C208%^b%^C214%^u%^C208%^r%^C202%^n %^C124%^your enemies!%^CRST%^");
        }

        define_base_damage(0);
        for(i=0;i<sizeof(foes);i++){
            if(!objectp(foes[i])) continue;
            
            if(element == "cold"){
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C030%^You are %^C255%^fr%^C250%^o%^C255%^z%^C250%^e%^C255%^n %^C030%^by the %^C051%^cold %^C030%^as you strike "+caster->QCN+"%^RESET%^%^CRST%^%^C030%^!%^CRST%^");
            }
            else{
                tell_object(foes[i], "%^RESET%^%^CRST%^%^C124%^You are %^C208%^b%^C214%^u%^C208%^r%^C202%^n%^C208%^e%^C214%^d %^C124%^by the %^C196%^flames %^C124%^as you strike "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^");
            }
            
            if(foes[i] && do_save(foes[i], 0)) damage_targ(foes[i], foes[i]->return_target_limb(), sdamage / 2,element);
            else damage_targ(foes[i], foes[i]->return_target_limb(), sdamage, element);
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
        if(element == "cold"){
            tell_object(caster, "%^RESET%^%^CRST%^%^C030%^The shield of ice and snow flickers and fades away, leaving you vulnerable once again.%^CRST%^");
            tell_room(environment(caster), "%^RESET%^%^CRST%^%^C030%^The shield of ice and snow flickers and fades away, leaving "+caster->QCN+"%^RESET%^%^CRST%^%^C030%^ vulnerable once again.%^CRST%^", caster);
        }
        else{
            tell_object(caster, "%^RESET%^%^CRST%^%^C124%^The shield of roaring flames flickers and fades away, leaving you vulnerable once again.%^CRST%^");
            tell_room(environment(caster), "%^RESET%^%^CRST%^%^C124%^The shield of roaring flames flickers and fades away, leaving "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^ vulnerable once again.%^CRST%^", caster);
        }
        caster->remove_property("fire shield");
        caster->remove_property_value("added short", ({ shield_type }));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

