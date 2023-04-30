#include <spell.h>
#include <magic.h>
#include <rooms.h>

#define TYPES ({ "animals", "insects", "elementals", "modrons" })

inherit SPELL;

object* monsters = ({});
int duration;

create(){
    ::create();
    set_spell_name("monster summoning i");
    set_spell_level(([ "mage" : 1, "bard" : 1, "cleric" : 1, "paladin" : 1 ]));
    set_syntax("cast CLASS monster summoning i [on TYPE]");
    set_spell_sphere("conjuration_summoning");
    set_description("This spell will summon creatures from other planes to protect the caster, becoming aggressive to anyone attempting to harm the caster. They will return to their home plane when either exhausted or the spell duration is completed. Approaches to the use of this spell vary, as some users put out a call for aid while others coerce these creatures into servitude.\n\nThe spell will default to animals, but you can specify between these types: animals, elementals, insects, or modrons. Sorcerers of the abyssal bloodline can also specify demons, and will summon them by default.");
    summon_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_arg_needed(1);
}


int preSpell(){
    if(present(caster->query_name() + "_monster", place)){
        message("info", "%^YELLOW%^You have already summoned monsters.%^RESET%^", caster);
        return 0;
    }

    return 1;
}

int spell_effect(int prof){
    object monster;
    int num, i;

    if(!objectp(caster)){
        dest_effect();
        return;
    }

    num = query_spell_level(spell_type);

    for(i = 0; i < num; i++){
        monster = new("/d/magic/mon/summoned_monster.c");
        if(!objectp(monster)) continue;

        monsters += ({ monster });

        monster->add_id("outsider");
        monster->set("aggressive", 1);
        monster->remove_property("swarm");
        monster->set_mlevel("fighter", clevel);
        monster->set_guild_level("fighter", clevel);
        monster->set_hd(clevel, num);
        monster->set_attacks_num(1);
        monster->set_property("spelled", ({ this_object() }));
        monster->set_property("spell_creature", this_object());
        monster->set_property("spell", this_object());
        monster->add_id(caster->query_true_name() + "_monster");
        monster->set_new_exp(1, "low");
        monster->set_property("minion", caster);
        if(monster->query_max_hp() > caster->query_max_hp()){
            monster->set_max_hp(caster->query_max_hp());
            monster->set_hp(monster->query_max_hp());
        }
        monster->move(environment(caster));
        skin_fun(monster);
        caster->add_follower(monster);
        caster->add_protector(monster);
    }

    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 300;
    duration = time() + spell_duration;
    set_end_time();
    call_out("dest_effect",spell_duration);

    addSpellToCaster();
    spell_successful();

    check();
}

void skin_fun(object monster){
    string mon_name;
    
    if(caster->is_class("sorcerer") && (caster->query_bloodline() == "abyssal") && (!arg || arg == "demons")){
        monster->set_short("%^C243%^d%^C090%^a%^C059%^r%^C243%^k w%^C059%^i%^C090%^n%^C096%^g%^C059%^e%^C243%^d %^C090%^d%^C059%^e%^C096%^m%^C090%^o%^C243%^n%^CRST%^");
        monster->set_long("%^C059%^Flapping in the air, this horrifying demon is a %^C033%^c%^C039%^h%^C045%^illi%^C039%^n%^C033%^g %^C059%^sight to behold. Its eyes are glowing %^C089%^v%^C090%^i%^C091%^ol%^C090%^e%^C089%^t %^C090%^o%^C091%^r%^C090%^b%^C089%^s %^C059%^and its lupine snout is wrinkled in a perpetual snarl, revealing rows of %^C124%^j%^C125%^a%^C124%^g%^C125%^g%^C124%^e%^C125%^d %^C255%^teeth%^C059%^. Pitch black skin shot through with %^C096%^v%^C091%^e%^C096%^i%^C091%^n%^C096%^s %^C059%^of %^C089%^v%^C090%^i%^C091%^ol%^C090%^e%^C089%^t %^C059%^is stretched over a lean muscular body. Large %^C245%^m%^C243%^e%^C245%^mbr%^C243%^a%^C245%^no%^C243%^u%^C245%^s w%^C243%^i%^C245%^ng%^C243%^s %^C059%^hold it aloft while wicked claws tip its fingers and toes which it rends at the air with, its hunger for %^C160%^v%^C124%^i%^C160%^ol%^C124%^e%^C160%^nc%^C124%^e %^C059%^palpable.%^CRST%^");
        message("info", "%^C059%^Reality rips and an abyssal creature claws its way through to protect "+caster->query_cap_name()+"%^C059%^!%^CRST%^", place, caster);
        message("info", "%^BLACK%^BOLD%^Reality rips and an abyssal creature claws its way through to protect you!%^RESET%^", caster);
        monster->set_name("demon");
        monster->set_race("demon");
        monster->add_id("demon");
        monster->set_property("damage resistance", 1 + clevel / 10);
        monster->set_property("spell damage resistance", 1 + clevel / 10);
        return;
    }
    if(caster->is_class("cleric") && member_array("creation", caster->query_divine_domain()) >= 0) monster->set_property("spell damage resistance", 10);
    
    if(!arg) arg = "animals";
    if(member_array(arg, TYPES) < 0) arg = "animals";
    switch(arg){
        case "animals" : // bobcat, badger, warthog, hawk, wolf, viper
            switch(random(6)){
                case 0 :
                    monster->set_short("%^C222%^ta%^C228%^wn%^C222%^y %^C101%^b%^C144%^o%^C101%^bc%^C144%^a%^C101%^t%^CRST%^");
                    monster->set_race("bobcat");
                    monster->set_body_type("quadruped");
                    break;
                case 1 :
                    monster->set_short("%^C058%^co%^C059%^u%^C255%^r%^C059%^s%^C058%^e-fu%^C100%^r%^C058%^r%^C100%^ed %^C059%^b%^C255%^a%^C059%^d%^C058%^g%^C100%^e%^C058%^r%^CRST%^");
                    monster->set_race("badger");
                    monster->set_body_type("quadruped");
                    break;
                case 2 :
                    monster->set_short("%^C101%^st%^C102%^ock%^C101%^y w%^C102%^a%^C101%^rt%^C102%^ho%^C101%^g%^CRST%^");
                    monster->set_race("warthog");
                    monster->set_body_type("quadruped");
                    break;
                case 3 :
                    monster->set_short("%^C220%^g%^C226%^o%^C220%^l%^C101%^d%^C058%^en %^C220%^h%^C101%^a%^C058%^wk%^CRST%^");
                    monster->set_race("hawk");
                    monster->set_body_type("fowl");
                    break;
                case 4 :
                    monster->set_short("%^C130%^ru%^C202%^d%^C130%^d%^C202%^y %^C130%^wo%^C202%^l%^C130%^f%^CRST%^");
                    monster->set_race("wolf");
                    monster->set_body_type("quadruped");
                    break;
                default :
                    monster->set_short("%^C040%^e%^C046%^m%^C040%^e%^C046%^r%^C226%^a%^C046%^l%^C040%^d %^C046%^v%^C226%^i%^C046%^pe%^C040%^r%^CRST%^");
                    monster->set_race("viper");
                    monster->set_body_type("snake");
            }
            monster->set_name("animal");
            monster->add_id("animal");
            break;
        case "elementals" : // mephits - dust, ice, magma, mud, smoke, steam
            switch(random(6)){
                case 0 :
                    monster->set_short("%^C101%^d%^C144%^u%^C255%^s%^C252%^t %^C101%^m%^C252%^e%^C144%^p%^C255%^h%^C144%^i%^C101%^t%^CRST%^");
                    break;
                case 1 :
                    monster->set_short("%^C252%^i%^C255%^c%^C045%^e %^C252%^m%^C051%^e%^C255%^p%^C252%^h%^C255%^i%^C045%^t%^CRST%^");
                    break;
                case 2 :
                    monster->set_short("%^C202%^m%^C196%^a%^C202%^g%^C208%^m%^C202%^a m%^C196%^e%^C202%^p%^C208%^h%^C202%^i%^C196%^t%^CRST%^");
                    break;
                case 3 :
                    monster->set_short("%^C100%^m%^C058%^u%^C100%^d m%^C101%^e%^C100%^ph%^C058%^i%^C100%^t%^CRST%^");
                    break;
                case 4 :
                    monster->set_short("%^C243%^s%^C245%^m%^C247%^o%^C245%^k%^C243%^e %^C245%^m%^C247%^e%^C245%^p%^C243%^h%^C245%^i%^C247%^t%^CRST%^");
                    break;
                default :
                    monster->set_short("%^C249%^s%^C251%^t%^C253%^e%^C255%^a%^C253%^m %^C251%^m%^C253%^e%^C255%^p%^C253%^h%^C251%^i%^C249%^t%^CRST%^");
                    
            }
            monster->set_race("elemental");
            monster->set_body_type("humanoid");
            monster->set_name("mephit");
            monster->add_id("elemental");
            break;
        case "insects" : // giant versions - ant, wasp, centipede, spider, scorpion, mosquito
            switch(random(6)){
                case 0 :
                    monster->set_short("%^C100%^g%^C101%^i%^C102%^a%^C101%^n%^C100%^t %^C088%^a%^C124%^n%^C088%^t%^CRST%^");
                    monster->set_race("ant");
                    monster->set_body_type("insectoid");
                    break;
                case 1 :
                    monster->set_short("%^C100%^g%^C101%^i%^C102%^a%^C101%^n%^C100%^t %^C226%^h%^C220%^o%^C226%^r%^C220%^n%^C226%^e%^C220%^t%^CRST%^");
                    monster->set_race("hornet");
                    monster->set_body_type("insectoid-winged");
                    break;
                case 2 :
                    monster->set_short("%^C100%^g%^C101%^i%^C102%^a%^C101%^n%^C100%^t %^C101%^c%^C144%^en%^C101%^ti%^C144%^p%^C101%^e%^C144%^d%^C101%^e%^CRST%^");
                    monster->set_race("centipede");
                    monster->set_body_type("insectoid");
                    break;
                case 3 :
                    monster->set_short("%^C100%^g%^C101%^i%^C102%^a%^C101%^n%^C100%^t %^C058%^s%^C100%^p%^C058%^id%^C100%^e%^C058%^r%^CRST%^");
                    monster->set_race("spider");
                    monster->set_body_type("arachnid");
                    break;
                case 4 :
                    monster->set_short("%^C100%^g%^C101%^i%^C102%^a%^C101%^n%^C100%^t %^C059%^s%^C243%^c%^C244%^o%^C245%^rp%^C244%^i%^C243%^o%^C059%^n%^CRST%^");
                    monster->set_race("scorpion");
                    monster->set_body_type("arachnid");
                    break;
                default :
                    monster->set_short("%^C100%^g%^C101%^i%^C102%^a%^C101%^n%^C100%^t %^C243%^m%^C059%^o%^C245%^s%^C255%^q%^C252%^u%^C255%^i%^C252%^t%^C255%^o%^CRST%^");
                    monster->set_race("mosquito");
                    monster->set_body_type("insectoid-winged");
            }
            monster->set_name("insect");
            monster->add_id("insect");
            break;
        case "modrons" : // modrons - monodrone, duodrone, tridrone
            switch(random(6)){
                case 0..2 :
                    monster->set_short("%^C142%^s%^C143%^p%^C144%^h%^C145%^e%^C146%^r%^C145%^i%^C144%^c%^C143%^a%^C142%^l %^C184%^m%^C178%^o%^C184%^n%^C178%^o%^C172%^d%^C184%^r%^C178%^o%^C172%^ne%^CRST%^");
                    monster->set_name("monodrone");
                    monster->add_id("monodrone");
                    break;
                case 3..4 :
                    monster->set_short("%^C136%^b%^C130%^o%^C136%^x%^C130%^y %^C184%^d%^C178%^u%^C178%^o%^C172%^d%^C184%^r%^C178%^o%^C172%^ne%^CRST%^");
                    monster->set_name("duodrone");
                    monster->add_id("duodrone");
                    break;
                default :
                    monster->set_short("%^C226%^p%^C220%^y%^C214%^r%^C226%^a%^C220%^m%^C214%^i%^C226%^d%^C220%^a%^C214%^l %^C184%^t%^C178%^r%^C178%^i%^C172%^d%^C184%^r%^C178%^o%^C172%^ne%^CRST%^");
                    monster->set_name("tridrone");
                    monster->add_id("tridrone");
            }
            monster->set_race("modron");
            monster->set_body_type("humanoid");
            break;
        default :
            message("info", "Something broke! Please inform Chernobog.", place);
    }
    mon_name = monster->query_short();
    monster->set_long("%^C030%^This is a "+mon_name+"%^C030%^ and fairly typical of its breed. However, it seems to be surrounded in a faintly %^C027%^s%^C033%^him%^C039%^m%^C027%^e%^C033%^rin%^C039%^g %^C027%^a%^C033%^u%^C039%^r%^C033%^a%^C030%^.%^CRST%^");
    
    message("info", "%^C030%^Reality rips and a "+mon_name+"%^C030%^ appears, moving to protect " + caster->query_cap_name() + "%^C030%^!%^CRST%^", place, caster);
    message("info", "%^C030%^Reality rips and a "+mon_name+"%^C030%^ appears, moving to protect you!%^CRST%^", caster);
    return;
}

void check(){
    object monster, * attackers, att;
    int i, j;

    monsters -= ({ 0 });

    if((!objectp(caster)) || (time() > duration) || (!sizeof(monsters)) || (!objectp(place = environment(caster)))){
        dest_effect();
        return;
    }

    for(i = 0; i < sizeof(monsters); i++){
        if(!objectp(monster = monsters[i])) continue;
        if(!present(monster, place)){
            message("info", "%^C030%^A "+monster->query_short()+"%^C030%^ fades away, vanishing from sight.%^CRST%^", environment(monster));
            monster->move("/d/shadowgate/void");
            monster->remove();
            continue;
        }

        caster->add_protector(monster);
        caster->add_follower(monster);

        if(!sizeof(attackers = (object*)caster->query_attackers())) continue;
        for(j = 0; j < sizeof(attackers); j++){
            if(!objectp(att = attackers[j])) continue;
            if (member_array(att, (object*)monster->query_attackers()) != -1) continue;
            monster->kill_ob(att, 0);
        }
    }
    call_out("check", 5);
}

void dest_effect(){
    object this_spell = this_object();
    int i;

    if(objectp(caster)){
        removeSpellFromCaster();
        message("info", "%^C226%^The summoned creatures vanish!%^CRST%^", caster);
    }

    if(sizeof(monsters)){
        for(i = 0; i < sizeof(monsters); i++){
            if(!objectp(monsters[i])) continue;
            monsters[i]->move("/d/shadowgate/void");
            monsters[i]->remove();
        }
    }
    ::dest_effect();
    if(objectp(this_spell)) this_spell->remove();
}

