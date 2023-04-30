//new elemental guardian passive creatures summoned with the elemental
//opportunist feat randomly - Saide, December 2016
#include <std.h>
inherit MINION;

#define VALID_ELE_TYPES ({"fire", "cold", "electricity", "acid"})

object myMaster;
string EleType;
int duration;

void create() {   
    ::create();   
    set_gender("neuter");    
    set_race("elemental");
    set_body_type("humanoid");
    set_size(1);
    set_base_damage_type("bludgeoning");
    set_exp(1);  
}

void heart_beat(){
    object guardian, room;
    ::heart_beat();
    if(!objectp(guardian = this_object())) return;
    if(!objectp(myMaster)){
        go_away();
        return;
    }
    if((room = environment(guardian)) != environment(myMaster)){
        go_away();
        return;
    }
    if(pointerp(guardian->query_attackers())){
        if(member_array(myMaster, (object *)guardian->query_attackers()) != -1){          
            guardian->remove_attacker(myMaster);
            if(objectp(myMaster)){
                tell_room(room, "%^RESET%^%^CRST%^"+guardian->query_short()+"%^RESET%^%^CRST%^%^C255%^ ceases attacking "+myMaster->QCN+"%^RESET%^%^CRST%^%^C255%^!%^CRST%^");
                myMaster->remove_attacker(guardian);
            }
        }
    }
    return;
}

void go_away(){
    object guardian, room;
    if(!objectp(guardian = this_object())) return;
    if(!objectp(room = environment(guardian))) return;
    switch(EleType){
        case "fire":
            tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ suddenly %^C124%^burns out %^C059%^in a shower of harmless %^C124%^e%^C160%^mb%^C124%^e%^C160%^r%^C124%^s%^RESET%^%^C059%^!%^CRST%^");
            break;
        case "cold":
            tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ suddenly %^C039%^melts%^C059%^, the liquid instantly evaporating into a harmless %^C247%^s%^C250%^te%^C247%^a%^C250%^m%^RESET%^%^C059%^!%^CRST%^");
            break;
        case "electricity":
            tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ suddenly %^C100%^fizzles out%^C059%^, dispersing in a harmless shower of %^C228%^sp%^C226%^a%^C231%^r%^C228%^k%^C226%^s%^RESET%^%^C059%^.%^CRST%^");
            break;
        case "acid":
            tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ suddenly %^C065%^evaporates%^C059%^, dispersing in a harmless %^C064%^g%^C070%^re%^C064%^e%^C070%^n m%^C064%^i%^C070%^st%^RESET%^%^C059%^!%^CRST%^");
            break;
    }
    if(objectp(guardian)) guardian->remove();
    return;
}

void setup_as(string myType)
{
    if(!stringp(myType)) myType = "fire";
    if(member_array(myType, VALID_ELE_TYPES) == -1) myType = "fire";
    EleType = myType;
    switch(myType){
        case "fire":
            set_name("a flaming creature");
            set_id(({"creature", "flaming creature", "guardian", "elemental guardian"}));
            set_short("%^RESET%^%^CRST%^%^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^i%^C214%^n%^C208%^g %^C202%^c%^C208%^r%^C214%^e%^C208%^a%^C202%^t%^C208%^u%^C214%^r%^C208%^e%^CRST%^");
            set_long("%^RESET%^%^CRST%^%^C202%^Jets of fire erupt from this small flaming creature continually. Its body seems malleable, as if it were composed of some molten material. There are extensions which allow it to walk and others which seem to serve as hands, you suppose that each could be considered an appendage. Somehow it lives but whatever is providing life to it is completely unknown.%^CRST%^");   
            set_resistance_percent("fire", 100);
            set("elementalist", "fire");
            break;
        case "cold":
            set_name("a frozen creature");
            set_id(({"creature", "freezing creature", "guardian", "elemental guardian", "frozen creature"}));
            set_short("%^RESET%^%^CRST%^%^C069%^f%^C075%^r%^C081%^o%^C087%^z%^C123%^e%^C087%^n %^C081%^c%^C075%^r%^C069%^e%^C075%^a%^C081%^t%^C087%^u%^C123%^r%^C087%^e%^CRST%^");
            set_long("%^RESET%^%^CRST%^%^C255%^A freezing cold is emanating from this small creature continually. Its body seems quite firm, as if it were composed from some sold material before being frozen. There are extensions which allow it to walk and others which seem to serve as hands. You suppose that each could be considered an appendage. Somehow it lives but whatever is providing life to it is completely unknown.%^CRST%^");    
            set_resistance_percent("cold", 100);
            set("elementalist", "cold");
            break;
        case "electricity":        
            set_name("a crackling creature");
            set_id(({"creature", "crackling creature", "guardian", "elemental guardian"}));
            set_short("%^RESET%^%^CRST%^%^C228%^c%^C231%^r%^C226%^a%^C228%^ckl%^C231%^i%^C228%^ng c%^C226%^r%^C228%^ea%^C231%^t%^C228%^u%^C231%^r%^C226%^e%^CRST%^");
            set_long("%^RESET%^%^CRST%^%^C100%^A cracking sound emanates from this dark creature continually. You quickly realize that there are bolts of electricity bouncing around inside of it and flashes of almost blinding light are given off from them. Its body seems to change as you look upon it, from a solid to an almost gaseous form. There are extensions which allow it to walk and others which seem to serve as hands. You suppose that each could be considered an appendage. Somehow it lives but whatever is providing life to it is completely unknown.%^CRST%^");       
            set_resistance_percent("electricity", 100);
            set("elementalist", "electricity");
            break;
        case "acid":
            set_name("a acidic creature");
            set_id(({"creature", "acidic creature", "guardian", "elemental guardian"}));
            set_short("%^RESET%^%^CRST%^%^C077%^a%^C071%^c%^C070%^i%^C076%^d%^C070%^i%^C071%^c %^C077%^c%^C071%^r%^C070%^e%^C076%^a%^C070%^t%^C071%^u%^C077%^r%^C071%^e%^CRST%^");
            set_long("%^RESET%^%^CRST%^%^C065%^Acid drips continually from this small and bizarre creature. Its body seems to be made of some amorphous mass that changes almost as frequently as the acid that drips from it. There are extensions which allow it to walk and others which seem to serve as hands. You suppose that each could be considered an appendage. Somehow it lives but whatever is providing life to it is completely unknown.%^CRST%^");   
            set_resistance_percent("acid", 100);
            set("elementalist", "acid");
            break;
    }
    set_spell_chance(20); 
    set_spells(({ "lightning bolt", "chill touch" }));
    call_out("go_away", duration);
}

void setup_guardian(object caster, string myType){
    int num;

    if(!objectp(caster)) return;
    if(!objectp(this_object())) return;
    num = (int)caster->query_guild_level("monk");
    if(!num) num = (int)caster->query_lowest_level();
    
    set_level(num);
    set_hd(num, 8);
    set_guild_level("mage", num);
    set_max_hp(roll_dice(num, 8) + (num * 2));
    set_hp(query_max_hp());
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",14 + (num / 5));
    set_stats("charisma",8);
    set_stats("dexterity",14 + (num / 5));
    set_stats("constitution",7);    
    set_attacks_num((num/10) + 1);
    set_overall_ac(10 - num);
    set_damage(1, (4 + (num / 8)));
    setup_as(myType);
    duration = (num * 4) + 20;
    myMaster = caster;
    set_property("minion", myMaster);
    set_monster_feats(({
        "spell focus",
        "spell penetration",
        }));
    return;
}

void go_to_master(){
    object myTarg, guardian, room;
    if(!objectp(guardian = this_object())) return;
    if(!objectp(myMaster)) return;
    if(!objectp(myTarg = environment(myMaster))) return;
    switch(EleType){
        case "fire":
            if(objectp(room = environment(guardian))) tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ vanishes in a puff of %^C247%^s%^C250%^mo%^C247%^k%^C250%^e%^RESET%^%^C059%^!%^CRST%^");
            guardian->move(myTarg);
            tell_room(environment(guardian), "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ appears in a sudden puff of %^C247%^s%^C250%^mo%^C247%^k%^C250%^e%^RESET%^%^C059%^!%^CRST%^");            
            break;
        case "cold":
            if(objectp(room = environment(guardian))) tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ vanishes in a brief %^C069%^i%^C075%^c%^C081%^y %^C087%^m%^C123%^i%^C087%^s%^C081%^t%^RESET%^%^C059%^!%^CRST%^");
            guardian->move(myTarg);
            tell_room(environment(guardian), "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^CRST%^%^C059%^ appears from a sudden %^C069%^i%^C075%^c%^C081%^y %^C087%^m%^C123%^i%^C087%^s%^C081%^t%^RESET%^%^C059%^!%^CRST%^");
            break;
        case "electricity":
            if(objectp(room = environment(guardian))) tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ vanishes in a shower of %^C228%^sp%^C226%^a%^C231%^r%^C228%^k%^C226%^s%^RESET%^%^C059%^!%^CRST%^");
            guardian->move(myTarg);
            tell_room(environment(guardian), "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ appears from a sudden shower of %^C228%^sp%^C226%^a%^C231%^r%^C228%^k%^C226%^s%^RESET%^%^C059%^!%^CRST%^");
            break;
        case "acid":
            if(objectp(room = environment(guardian))) tell_room(room, "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ vanishes in a %^C077%^h%^C071%^a%^C070%^z%^C076%^y %^C070%^f%^C071%^o%^C077%^g%^RESET%^%^C059%^!%^CRST%^");
            guardian->move(myTarg);
            tell_room(environment(guardian), "%^RESET%^%^CRST%^%^C059%^A "+guardian->query_short()+"%^RESET%^%^CRST%^%^C059%^ appears from a sudden %^C077%^h%^C071%^a%^C070%^z%^C076%^y %^C070%^f%^C071%^o%^C077%^g%^RESET%^%^C059%^!%^CRST%^");
            break;       
    }
    if(objectp(myMaster)){
        myMaster->add_protector(guardian);
        myMaster->add_follower(guardian);
    }
    return;
}

int die(){
    go_away();
    ::die();
    return 1;
}

