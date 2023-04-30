#include <std.h>
#include <daemons.h>
#include <enhancements.h>

inherit DAEMON;

int cmd_enhance(string str)
{
    object player, enhanceob, oldob, * wielded;
    mapping enhances, enhance;
    string enhancement_name, *arguments, *domains, *temp = ({}), *display = ({}), * normal_enhances = ({});
    int power, duration, feat_ap, feat_wb, feat_ab, feat_wr, feat_cl, has_resource, my_levels, i;

    string element, property_name;
    int is_burst, has_element, is_alignement, cost;
    mapping this_enhance;

    if(!objectp(player = this_player())){
        return 0;
    }

    feat_ap = FEATS_D->usable_feat(player, "arcane pool");
    feat_wb = FEATS_D->usable_feat(player, "weapon bond");
    feat_ab = FEATS_D->usable_feat(player, "armor bond");
    feat_wr = FEATS_D->usable_feat(player, "warding");

    if(player->is_class("cleric")){
        domains = player->query_divine_domain();
        if(member_array("good", domains) >= 0  ||
           member_array("evil", domains) >= 0  ||
           member_array("chaos", domains) >= 0 ||
           member_array("law", domains) >= 0)
            feat_wb = 1;
    }

    if(!feat_ap && !feat_wb && !feat_ab) return 0;
    if(!stringp(str) || str == "" || str == " ") str = "list";

    arguments = explode(str, " ");

    if(!sizeof(arguments))
    {
        printf("You currently have %d maximum enhancement points.\n", calc_enh_points(player));
        return 1;
    }

    switch (arguments[0]){
    case "weapon":
        if(!feat_ap && !feat_wb) return 0;
        
        wielded = (object*)player->query_wielded();
        if (!sizeof(wielded)){
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^You must be wielding a weapon.%^CRST%^");
            return 1;
        }
        has_resource = 0;
        if (feat_ap && (int)USER_D->spend_pool(player, 1, "arcana")){
            has_resource = 1;
        }
        else if(feat_wb && (int)USER_D->spend_pool(player, 1, "grace")){
            has_resource = 1;
        }
        else{
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^You can't enhance your weapon!%^CRST%^");
            return 1;
        }

        enhances = get_enhances(player);
        power = player->query_property("weapon enhancement timer");
        if(power) off_enhances(player, "weapon");
        
        temp = keys(enhances);
        power = 0;
        power = calc_enh_points(player);
        if(sizeof(temp)){
            this_enhance = VALID_WEAPON_ENHANCEMENTS;
            for(i = 0;i < sizeof(temp);i++){
                enhancement_name = temp[i];
                enhance = enhances[enhancement_name];
                if(!this_enhance[enhancement_name]) continue;
                property_name = this_enhance[enhancement_name]["property"];
                cost = (int)this_enhance[enhancement_name]["cost"];
                has_element = 0;
                //element = replace_string(property_name, " en_dam", "");
                if(is_burst = strsrch(property_name, "burst") + 1){
                    element = replace_string(property_name, " burst", "");
                    if(has_element = player->query_property(element)) cost -= 1;
                }
                if(power - cost >= 0){
                    if(!player->query_property(property_name)){
                        if(strsrch(property_name, "alignment ") + 1){
                            is_alignement = strsrch(property_name, (string)player->query_true_align() + "") + 1;
                            if(!is_alignement){
                                tell_object(player, "%^RESET%^%^CRST%^%^C059%^Your alignment doesn't match to "+enhancement_name+".%^CRST%^");
                                continue;
                            }
                        }
                        player->set_property(property_name, 1);
                        if(is_burst && !has_element){
                            player->set_property(element, 1);
                        }
                        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Applying %^C046%^%^"+enhancement_name+"%^C101%^%^ to your weapon.%^CRST%^");
                        power -= cost;
                        player->set_property("weapon enhancements", 1);
                    }
                }
                else tell_object(player, "%^RESET%^%^CRST%^%^C059%^Cannot apply %^C196%^"+enhancement_name+"%^C059%^ to your weapon, it requires %^C196%^"+cost+" %^C059%^enhancement points.%^CRST%^");
            }
        }
        
        if(power){
            player->set_property("weapon enhancement bonus", power);
            player->add_attack_bonus(power);
            player->add_damage_bonus(power);
            tell_object(player, "\n%^RESET%^%^CRST%^%^C144%^Unspent resources have bolstered your combat prowess.%^CRST%^");
        }
        if(FEATS_D->usable_feat(player, "greater enduring arcana")){
            duration = (int)player->query_prestige_level("magus") * 600;
        }
        else if(FEATS_D->usable_feat(player, "enduring arcana")){
            duration = (int)player->query_prestige_level("magus") * 60;
        }
        else{
            duration = 180;
            duration *= (1 + (player->query_prestige_level("paladin") / 5) + (player->query_prestige_level("cleric") / 5));
        }
        player->set_property("weapon enhancement timer", duration);
        return 1;

    case "armor":
        if(!feat_wr && !feat_ab) return 0;
        wielded = filter_array(distinct_array(player->query_armour("torso")), "armor_filter", player);
        if(!sizeof(wielded)){
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^You must be wearing body armor.%^CRST%^");
            return 1;
        }
        has_resource = 0;
        if(feat_wr && (int)USER_D->spend_pool(player, 1, "arcana")){
            has_resource = 1;
        }
        else if(feat_ab && (int)USER_D->spend_pool(player, 1, "grace")){
            has_resource = 1;
        }
        else{
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^You can't enhance your armor!%^CRST%^");
            return 1;
        }

        enhances = get_enhances(player);
        power = player->query_property("armor enhancement timer");
        if(power) off_enhances(player, "armor");
        
        temp = keys(enhances);
        power = 0;
        power = calc_enh_points(player);
        if(sizeof(temp)){
            this_enhance = VALID_ARMOR_ENHANCEMENTS;
            for(i = 0;i < sizeof(temp);i++){
                enhancement_name = temp[i];
                enhance = enhances[enhancement_name];
                if(!this_enhance[enhancement_name]) continue;
                property_name = this_enhance[enhancement_name]["property"];
                cost = (int)this_enhance[enhancement_name]["cost"];
                has_element = 0;
                element = replace_string(property_name, " en_res", "");
                if(strsrch(property_name, " en_res") + 1 && feat_ab){ cost -= 1; }
                if(is_burst = strsrch(property_name, "improved") + 1){
                    element = replace_string(property_name, " en_res improved", "");
                    if(has_element = player->query_property(element + " en_res")){
                        cost -= 3;
                    }
                }
                if(power - cost >= 0){
                    if(!player->query_property(property_name)){
                        if(strsrch(property_name, "en_res") + 1) player->set_resistance(element, 10);
                        player->set_property(property_name, 1);
                        if(is_burst && !has_element){
                            player->set_property(element + " en_res", 1);
                            player->set_resistance(element, 10);
                        }
                        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Applying %^C046%^"+enhancement_name+"%^C101%^ to your armor.%^CRST%^");
                        power -= cost;
                        player->set_property("armor enhancements", 1);
                    }
                }
                else {
                    tell_object(player, "%^RESET%^%^CRST%^%^C059%^Cannot apply %^C196%^"+enhancement_name+"%^C059%^ to your armor, requires %^C196%^"+cost+" %^C059%^enhancement points.%^CRST%^");
                }
            }
        }
        if(power){
            player->set_property("armor enhancement bonus", power);
            player->add_ac_bonus(power);
            tell_object(player, "\n%^RESET%^%^CRST%^%^C144%^Unspent resources have bolstered your armor.%^CRST%^");
        }
        if(FEATS_D->usable_feat(player, "greater enduring warding")){
            duration = (int)player->query_prestige_level("magus") * 600;
        }
        else if(FEATS_D->usable_feat(player, "enduring warding")){
            duration = (int)player->query_prestige_level("magus") * 60;
        }
        else{
            duration = 180;
            duration *= (1 + (player->query_prestige_level("paladin") / 5));
        }
        player->set_property("armor enhancement timer", duration);
        return 1;

    case "add":

        if(sizeof(arguments) < 2){
            tell_object(player, "Syntax: <enhance add PROPERTY NAME>");
            return 1;
        }
        for(i = 1; i < sizeof(arguments); i++){
            temp += ({ arguments[i] });
        }

        enhancement_name = implode(temp, " ");

        if(!does_enhance_exist(player, enhancement_name)){
            write("%^RESET%^%^CRST%^%^C059%^The enhancement "+enhancement_name+" doesn't seem to exist.%^CRST%^\n");
            return 1;
        }
        if(!enhancement_name){
            return 1;
        }
        enhances = get_enhances(player);
        delete_enhance(player, enhancement_name);
        enhances[enhancement_name] = ({ });
        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Adding to enhancement list: %^RESET%^%^CRST%^%^C046%^"+enhancement_name+"%^CRST%^");
        save_enhances(player, enhances);
        return 1;

    case "clear":

        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Clearing all of your enhancements from the list...%^CRST%^");
        delete_enhances(player);
        return 1;

    case "remove":

        if(sizeof(arguments) < 2){
            tell_object(player, "%^RESET%^%^CRST%^%^C196%^Syntax: %^RESET%^%^CRST%^%^C255%^<enhance remove ENHANCEMENT NAME>%^CRST%^");
            return 1;
        }
        for(i = 1; i < sizeof(arguments); i++){
            temp += ({ arguments[i] });
        }

        enhancement_name = implode(temp, " ");
        tell_object(player, "%^RESET%^%^CRST%^%^C101%^Removing from enhancement list: %^RESET%^%^CRST%^%^C196%^"+enhancement_name+"%^CRST%^");
        delete_enhance(player, enhancement_name);
        return 1;

    case "list":

        enhances = get_enhances(player);
        temp = keys(enhances);
        
        if (!sizeof(temp)){
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't seem to have any enhancements added to your list yet.%^CRST%^");
            return 1;
        }

        display += ({ "%^RESET%^%^CRST%^%^C100%^--%^C101%^==%^C144%^=====< %^C255%^Enhancements List%^RESET%^%^C144%^>=====%^C101%^==%^C100%^--%^CRST%^\n" });

        for (i = 0;i < sizeof(temp);i++){
            enhancement_name = temp[i];
            enhance = enhances[enhancement_name];
            normal_enhances += ({ enhancement_name });
            if (enhance)
            {
                display += ({ "   %^RESET%^%^CRST%^%^C046%^"+enhancement_name+"%^RESET%^%^CRST%^" });
            }
        }
        display += ({" "});
        if(feat_ap || feat_wb)display += ({ "%^RESET%^%^CRST%^%^C130%^   Total weapon enhancement pool: %^C226%^"+calc_enh_points(player)+"%^RESET%^%^CRST%^"});
        if(feat_ab || feat_wr)display += ({ "%^RESET%^%^CRST%^%^C130%^   Total armor enhancement pool: %^C226%^"+calc_enh_points(player)+"%^RESET%^%^CRST%^"});
        display += ({ "\n%^RESET%^%^CRST%^%^C100%^--%^C101%^==%^C144%^==============================%^C101%^==%^C100%^--%^RESET%^%^CRST%^\n" });

        player->more(display);

        return 1;
    }
    return 0;
}

// checks if it's an actual enhancement
int does_enhance_exist(object obj, string str){
    int property_num;
    string * enhancements;
    enhancements = ({ });
    if(FEATS_D->usable_feat(obj, "weapon bond")) enhancements += PALADIN_WEAPON_ENHANCEMENTS;
    if(FEATS_D->usable_feat(obj, "armor bond")) enhancements += PALADIN_ARMOR_ENHANCEMENTS;
    if(FEATS_D->usable_feat(obj, "arcane pool")) enhancements += MAGUS_WEAPON_ENHANCEMENTS;
    if(FEATS_D->usable_feat(obj, "warding")) enhancements += MAGUS_ARMOR_ENHANCEMENTS;
    if(FEATS_D->usable_feat(obj, "thundering arcana")) enhancements += THUNDERING_ENHANCEMENTS;
    if(FEATS_D->usable_feat(obj, "corrosive arcana")) enhancements += CORROSIVE_ENHANCEMENTS;
    if(FEATS_D->usable_feat(obj, "devoted arcana")) enhancements += ALIGNMENT_ENHANCEMENTS;
    if(obj->is_class("cleric")) enhancements += CLERIC_WEAPON_ENHANCEMENTS;
    enhancements = distinct_array(enhancements);
    if(member_array(str, enhancements) != -1) return 1;
    return 0;
}


int add_enhance(object obj, string enhancement_name, mapping enhance){
    mapping enhances;
    if(!objectp(obj)) return 0;
    if(!mapp(enhance) || !sizeof(keys(enhance))) return 0;
    enhances = get_enhances(obj);
    delete_enhance(obj, enhancement_name);
    enhances[enhancement_name] = enhance;
    save_enhances(obj, enhances);
    return 1;
}


int delete_enhance(object obj, string enhancement_name){
    mapping enhances;
    if(!objectp(obj)) return 0;
    enhances = get_enhances(obj);
    enhances = map_delete(enhances, enhancement_name);
    save_enhances(obj, enhances);
    return 1;
}


mapping get_enhances(object obj){
    mapping temp;
    temp = (mapping)obj->query("enhance_list");
    if(!mapp(temp) || !sizeof(keys(temp))) return ([]);
    return temp;
}


void delete_enhances(object obj){
    if(!objectp(obj)) return;
    obj->delete("enhance_list");
    return;
}


void save_enhances(object obj, mapping enhances){
    if(!objectp(obj)) return;
    if(!mapp(enhances) || !sizeof(enhances)) return;
    obj->set("enhance_list", enhances);
    return;
}


void run_enhances_timer(object obj, string enh_type){
    int enh_timer;
    enh_timer = obj->query_property(enh_type + " enhancement timer");
    if(enh_timer > 0){
        enh_timer -= 2;
        if(enh_timer < 1) off_enhances(obj, enh_type);
        else obj->set_property(enh_type + " enhancement timer", -2);
    }
    return;
}


void off_enhances(object obj, string enh_type){
    int i, enh_bonus;
    string element, property_name, * temp = ({});
    mapping enhances;
    if(!objectp(obj)) return;
    
    tell_object(obj, "%^RESET%^%^CRST%^%^C100%^Your "+enh_type+" enhancements fade.%^CRST%^\n");
    obj->remove_property(enh_type + " enhancement timer");
    enh_bonus = obj->query_property(enh_type + " enhancement bonus");
    if(enh_bonus){
        obj->remove_property(enh_type + " enhancement bonus");
        if(enh_type == "armor"){
            obj->add_ac_bonus(-enh_bonus);
        }
        else{
            obj->add_attack_bonus(-enh_bonus);
            obj->add_damage_bonus(-enh_bonus);
        }
    }
    if(enh_type == "armor"){
        enhances = VALID_ARMOR_ENHANCEMENTS;
    }
    else enhances = VALID_WEAPON_ENHANCEMENTS;
    temp = keys(enhances);
    if (!sizeof(temp)) tell_object(obj, "Error.");
    for (i = 0;i < sizeof(temp);i++){
        property_name = enhances[temp[i]]["property"];
        if (obj->query_property(property_name)){
            if (strsrch(property_name, "en_res") + 1){
                element = replace_string(property_name, " en_res", "");
                element = replace_string(element, " improved", "");
                TP->set_resistance(element, -10);
            }
            obj->remove_property(property_name);

        }
    }
    return;
}

int calc_enh_points(object player){
    int power, my_levels;

    power = 0;

    my_levels = (int)player->query_prestige_level("magus");
    power += ((int)player->query_prestige_level("magus") + 7) / 8;
    if (FEATS_D->usable_feat(player, "legendary blade")) power += 2;
    power += ((int)player->query_level() - my_levels) / 16;

    if(player->is_class("cleric")){
        if(player->is_class("paladin")){
            my_levels = max( ({ (int)player->query_prestige_level("paladin"), (int)player->query_prestige_level("cleric") }) );
            power += max( ({ ((int)player->query_prestige_level("paladin") + 1) / 6, ((int)player->query_prestige_level("cleric") + 1) / 6 }) );
        }
        else{
            my_levels = (int)player->query_prestige_level("cleric");
            power += ((int)player->query_prestige_level("cleric") + 1) / 6;
        }
    }
    else if(player->is_class("paladin")){
        my_levels = (int)player->query_prestige_level("paladin");
        power += ((int)player->query_prestige_level("paladin") + 1) / 6;
    }
    
    power += ((int)player->query_level() - my_levels) / 16;
    
    return power;
}

void help(){

    write(
"
%^CYAN%^NAME%^RESET%^

enhance - apply stored list of enhancements

%^CYAN%^SYNOPSIS%^RESET%^

enhance
enhance list
enhance add %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^
enhance remove %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^
enhance clear
enhance weapon
enhance armor

%^CYAN%^DESCRIPTION%^RESET%^

The command will allow player to store a list of enhancements they can apply to their weapon instead of adding an enhancement bonus. The enhancements will cycle one at a time. If the player doesn't have enough enhancement bonus, enhancements process will be interrupted.

%^ORANGE%^<enhance list>%^RESET%^
  Will list all added enhancements.

%^ORANGE%^<enhance add %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^%^ORANGE%^>%^RESET%^
  Will add %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^ to the enhancement list.

%^ORANGE%^<enhance remove %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^%^ORANGE%^>%^RESET%^
  Will remove %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^ from the enhancement list.

%^ORANGE%^<enhance clear>%^RESET%^
  Will clear your enhancement list.

%^ORANGE%^<enhance weapon>%^RESET%^
  Will enhance your main weapon with the listed valid options.

%^ORANGE%^<enhance armor>%^RESET%^
  Will enhance your body armor with the listed valid options.

%^CYAN%^SEE ALSO%^RESET%^

enhancements, magus, arcane pool, warding, paladin, armor bond, weapon bond
"
        );
}
