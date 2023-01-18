#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int duration, basemax, newmax, deltahp, feattracker, cooldown, myFlag, BonusFlag;

void rage_me();
void check();

void create() {
   ::create();
   feat_type("instant");
   feat_category("KiOffense");
   feat_name("flurry of blows");
   feat_desc("This feat allows the monk to focus her mind. She is able to uncannily spot the weaknesses in the defenses of her enemies. By doing so, this allows her to attack at least once more, possibly twice, at the expense of 1 Ki per combat round. This feat functions only  when unarmored and either unarmed or wielding small weapons while the monk has Ki available.");
   feat_prereq("Monk L2");
   feat_syntax("flurry_of_blows on|off");
   set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }
   if((int)ob->query_class_level("monk") < 2 || (int)ob->query_alignment() > 3)
   {
      dest_effect();
      return 0;
   }
    return ::prerequisites(ob);
}

int cmd_flurry_of_blows(string str)
{
   object feat;
   if(!objectp(TP)) { return 0; }
   if(str) str = lower_case(str);
   if((int)TP->query_alignment() > 3) return 0;
   if(!TP->is_class("monk")) return 0;
   if(str != "on" && str != "off")
   {
      tell_object(TP, "Use flurry_of_blows on or flurry_of_blows off.");
      return 1;
   }
   if(!(int)USER_D->can_spend_ki(TP, 1) && str == "on")
   {
       tell_object(TP, "%^RESET%^%^CRST%^%^C030%^You lack the needed ki to enable flurry of blows.%^CRST%^");
       dest_effect();
       return 1;
   }
   feat = new(base_name(TO));
   feat->setup_feat(TP,str);
   return 1;
}

void execute_feat()
{
    object myFB;
    int i;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",caster);
        dest_effect();
        return;
    }
    ::execute_feat();
    switch(arg)
    {
        case "off":
            if(!objectp(myFB = caster->query_property("flurry of blows")))
            {
                tell_object(caster, "%^RESET%^%^CRST%^%^C030%^You currently are not focusing your mind on spotting the weaknesses in the defense of your enemies.%^CRST%^");
                dest_effect();
                break;
            }
            if(objectp(myFB)) myFB->dest_effect();
            dest_effect();
            break;
        case "on":
            if(objectp(myFB = caster->query_property("flurry of blows")))
            {
                tell_object(caster, "%^RESET%^%^CRST%^%^C030%^You are already focusing your mind on spotting the weaknesses in the defenses of your enemies.%^CRST%^");
                dest_effect();
                break;
            }
            if((int)caster->query_property("using instant feat"))
            {
                tell_object(caster, "%^RESET%^%^CRST%^%^C030%^You are already in the middle of using a feat.%^CRST%^");
                dest_effect();
                break;
            }
            if(caster->query_casting())
            {
                tell_object(caster, "%^RESET%^%^CRST%^%^C030%^You are already in the middle of casting a spell.%^CRST%^");
                dest_effect();
                break;
            }
            if(!(int)USER_D->can_spend_ki(caster, 1))
            {
                tell_object(caster, "%^RESET%^%^CRST%^%^C030%^You lack the needed ki to focus your mind so completely.%^CRST%^");
                dest_effect();
                return;
            }
            tell_object(caster, "%^RESET%^%^CRST%^%^C051%^You focus your mind enabling yourself to see the weak spots in your enemies defenses.%^CRST%^");
            tell_room(place, "%^RESET%^%^CRST%^%^C051%^"+caster->QCN+"%^RESET%^%^CRST%^%^C051%^ begins focusing intently.%^CRST%^",caster);
            call_out("check",ROUND_LENGTH);
            caster->set_property("flurry of blows", TO);
            return;
            break;
    }
    return;
}

int calculate_my_dam(object victim, int crit)
{
    object myFB;
    int dam, mycrit_range=20;
    if(!objectp(caster))
    {
        return 0;
    }
    if(!objectp(myFB = caster->query_property("flurry of blows")))
    {
        return 0;
    }
    if((int)caster->query_alignment() > 3)
    {
        return 0;
    }
    dam = (int)caster->query_unarmed_damage();
    if(FEATS_D->usable_feat(caster, "weapon finesse")) dam += BONUS_D->query_stat_bonus(caster, "dexterity");
    else dam += BONUS_D->query_stat_bonus(caster, "strength");
    dam += (int)caster->query_damage_bonus();
    if(caster->is_class("monk")) dam += "/std/class/monk.c"->effective_enchantment(caster);
	if(FEATS_D->usable_feat(caster, "lethal strikes")){
		mycrit_range=19;
	}
	if(crit >= mycrit_range) dam = "/daemon/combat_d.c"->crit_damage(caster, victim, 0, (int)victim->query_size(), dam, 0);
    return dam;
}

void flurry_hit()
{
    string myWay, dam_type,*ways = ({ "way of the fist","way of the shadow","way of the elements" });
    object myVic, myFB;
    int dam, crit, mybonus, DC;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(myFB = caster->query_property("flurry of blows")))
    {
        dest_effect();
        return;
    }
    if((int)caster->query_alignment() > 3)
    {
        myFB->dest_effect();
        dest_effect();
        return;
    }

    myWay = (string)caster->query("monk way");
    if(FEATS_D->usable_feat(caster,"grandmaster of the way")) // maybe give the grandmaster its own hit func at some point
    {
        myWay = ways[random(sizeof(ways))];
    }

    myVic = caster->query_current_attacker();
    if(!objectp(myVic)) return;
    if(caster->query_paralyzed()) return;
    DC = (int)caster->query_class_level("monk");
    DC += (int)"/daemon/bonus_d.c"->query_stat_bonus(caster, "wisdom");
    DC += 5;
    if((crit = (int)BONUS_D->process_hit(caster, myVic, 1, 0, 0, 1)))
    {
        dam = calculate_my_dam(myVic, crit);
        dam_type = "force";
        tell_object(caster, "%^RESET%^%^CRST%^%^C244%^You strike "+myVic->QCN+"%^RESET%^%^CRST%^%^C244%^ with a sudden ferocity!%^CRST%^");
        tell_object(myVic, "%^RESET%^%^CRST%^%^C244%^"+caster->QCN+"%^RESET%^%^CRST%^%^C244%^ strikes you with a sudden ferocity!%^CRST%^");
        if(objectp(environment(caster)))
        {
            tell_room(environment(caster), "%^RESET%^%^CRST%^%^C244%^"+caster->QCN+"%^RESET%^%^CRST%^%^C244%^ strikes "+myVic->QCN+"%^RESET%^%^CRST%^%^C244%^ with a sudden ferocity!%^CRST%^", ({caster, myVic}));
        }
        if(myWay == "way of the fist" && !random(5))
        {
            if(do_save(myVic,DC) || myVic->query_property("no paralyze"))
            {
                tell_object(myVic, "%^RESET%^%^CRST%^%^C118%^Your body shudders violently for a brief instant but you manage to shake off most of the strike.%^CRST%^");
                if(objectp(environment(caster)))
                {
                    tell_room(environment(caster), "%^RESET%^%^CRST%^%^C118%^"+myVic->QCN+"%^RESET%^%^CRST%^%^C118%^ shudders violently for a brief instant but "+myVic->QS+" manages to shake off most of the strike.%^CRST%^", ({myVic}));
                }
            }
            else
            {
                tell_object(myVic, "%^RESET%^%^CRST%^%^C160%^Your body shudders violently for a brief instant before you collapse!%^CRST%^");
                myVic->set_tripped(1, "%^RESET%^%^CRST%^%^C160%^You are struggling to get back to your feet!%^CRST%^");
                if(objectp(environment(caster)))
                {
                    tell_room(environment(caster), "%^RESET%^%^CRST%^%^C160%^"+myVic->QCN+"%^RESET%^%^CRST%^%^C160%^'s body shudders violently for a brief instant before "+myVic->QS+" collapses!%^CRST%^", ({myVic}));
                }
            }
        }
        else if(myWay == "way of the shadow" && (int)caster->query_class_level("monk") > 16)
        {
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^T%^C243%^e%^C244%^n%^C245%^d%^C244%^r%^C243%^i%^C059%^l%^C243%^s %^RESET%^%^C059%^of %^C243%^s%^C244%^h%^C245%^a%^C244%^d%^C243%^o%^C059%^w lash out at "+myVic->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^!%^CRST%^");

            mybonus = ((int)caster->query_class_level("monk")/10)+1;
            dam += roll_dice(mybonus,4);

            tell_object(myVic, "%^RESET%^%^CRST%^%^C059%^T%^C243%^e%^C244%^n%^C245%^d%^C244%^r%^C243%^i%^C059%^l%^C243%^s %^RESET%^%^C059%^of %^C243%^s%^C244%^h%^C245%^a%^C244%^d%^C243%^o%^C059%^w lash out at you from "+caster->QCN+"%^RESET%^%^CRST%^%^C059%^!%^CRST%^");

            if(objectp(environment(caster)))
            {
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C059%^T%^C243%^e%^C244%^n%^C245%^d%^C244%^r%^C243%^i%^C059%^l%^C243%^s %^RESET%^%^C059%^of %^C243%^s%^C244%^h%^C245%^a%^C244%^d%^C243%^o%^C059%^w lash out at "+myVic->QCN+"%^RESET%^%^CRST%^%^C059%^ from "+caster->QCN+"%^RESET%^%^CRST%^%^C059%^!%^CRST%^", ({caster, myVic}));
            }
            dam_type = "void";
        }
        else if(myWay == "way of the elements")
        {
            dam_type = caster->query("monk_ele_focus");
            if(!stringp(dam_type)) dam_type = "fire";
            switch(dam_type)
            {
                case "cold":
                    tell_object(caster, "%^RESET%^%^CRST%^%^C255%^The air around you coalesces into %^C069%^s%^C075%^h%^C081%^a%^C087%^r%^C123%^d%^C087%^s %^C081%^o%^C075%^f %^C069%^i%^C075%^c%^C081%^e%^RESET%^%^C255%^, driving into "+myVic->QCN+"%^RESET%^%^CRST%^%^C255%^!%^CRST%^");

                    tell_object(myVic, "%^RESET%^%^CRST%^%^C255%^The air around "+caster->QCN+"%^RESET%^%^CRST%^%^C255%^ coalesces into %^C069%^s%^C075%^h%^C081%^a%^C087%^r%^C123%^d%^C087%^s %^C081%^o%^C075%^f %^C069%^i%^C075%^c%^C081%^e%^RESET%^%^C255%^, driving into you!%^CRST%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C255%^The air around "+caster->QCN+"%^RESET%^%^CRST%^%^C255%^ coalesces into %^C069%^s%^C075%^h%^C081%^a%^C087%^r%^C123%^d%^C087%^s %^C081%^o%^C075%^f %^C069%^i%^C075%^c%^C081%^e%^RESET%^%^C255%^, driving into "+myVic->QCN+"%^RESET%^%^CRST%^%^C255%^!%^CRST%^", ({caster, myVic}));
                    }
                    break;
                case "electricity":
                    tell_object(caster, "%^RESET%^%^CRST%^%^C228%^Ar%^C226%^c%^C228%^s %^C231%^o%^C228%^f %^C228%^e%^C231%^l%^C228%^ect%^C226%^r%^C231%^i%^C228%^ci%^C231%^t%^C228%^y%^RESET%^%^C100%^ snap and spark along your hands towards "+myVic->QCN+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^");

                    tell_object(myVic, "%^RESET%^%^CRST%^%^C228%^Ar%^C226%^c%^C228%^s %^C231%^o%^C228%^f %^C228%^e%^C231%^l%^C228%^ect%^C226%^r%^C231%^i%^C228%^ci%^C231%^t%^C228%^y%^RESET%^%^C100%^ from "+caster->QCN+"%^RESET%^%^CRST%^%^C100%^'s hands snap and spark towards you!%^CRST%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C228%^Ar%^C226%^c%^C228%^s %^C231%^o%^C228%^f %^C228%^e%^C231%^l%^C228%^ect%^C226%^r%^C231%^i%^C228%^ci%^C231%^t%^C228%^y%^RESET%^%^C100%^ from "+caster->QCN+"%^RESET%^%^CRST%^%^C100%^'s hands snap and spark towards "+myVic->QCN+"%^RESET%^%^CRST%^%^C100%^!%^CRST%^", ({caster, myVic}));
                    }
                    break;
                case "acid":
                    tell_object(caster, "%^RESET%^%^CRST%^%^C077%^B%^C071%^l%^C070%^o%^C076%^b%^C070%^s %^C071%^o%^C077%^f %^C071%^v%^C070%^i%^C076%^s%^C070%^c%^C071%^o%^C077%^u%^C071%^s %^C070%^a%^C076%^c%^C070%^i%^C071%^d %^RESET%^%^C065%^flow along your arms and splash against "+myVic->QCN+"%^RESET%^%^CRST%^C065%^!%^CRST%^");

                    tell_object(myVic, "%^RESET%^%^CRST%^%^C077%^B%^C071%^l%^C070%^o%^C076%^b%^C070%^s %^C071%^o%^C077%^f %^C071%^v%^C070%^i%^C076%^s%^C070%^c%^C071%^o%^C077%^u%^C071%^s %^C070%^a%^C076%^c%^C070%^i%^C071%^d %^RESET%^%^C065%^flow along "+caster->QCN+"%^RESET%^%^CRST%^%^C065%^'s arms and splash against you!%^CRST%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C077%^B%^C071%^l%^C070%^o%^C076%^b%^C070%^s %^C071%^o%^C077%^f %^C071%^v%^C070%^i%^C076%^s%^C070%^c%^C071%^o%^C077%^u%^C071%^s %^C070%^a%^C076%^c%^C070%^i%^C071%^d %^RESET%^%^C065%^flow along "+caster->QCN+"%^RESET%^%^CRST%^%^C065%^'s arms and splash against "+myVic->QCN+"%^RESET%^%^CRST%^%^C065%^!%^CRST%^", ({caster, myVic}));
                    }
                    break;
                default:
                    tell_object(caster, "%^C208%^F%^C214%^l%^C208%^i%^C202%^c%^C208%^k%^C214%^e%^C208%^r%^C202%^i%^C214%^n%^C208%^g %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s %^RESET%^%^C202%^roll about your fists, darting out to sear "+myVic->query_cap_name()+"%^RESET%^%^CRST%^%^C202%^!%^CRST%^");

                    //mybonus = ((int)caster->query_class_level("monk")/10)+1;
                    //dam += roll_dice(mybonus,2);

                    tell_object(myVic, "%^C208%^F%^C214%^l%^C208%^i%^C202%^c%^C208%^k%^C214%^e%^C208%^r%^C202%^i%^C214%^n%^C208%^g %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s %^RESET%^%^C202%^roll about "+caster->QCN+"%^RESET%^%^CRST%^%^C202%^'s fists, darting out to sear you!%^CRST%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^C208%^F%^C214%^l%^C208%^i%^C202%^c%^C208%^k%^C214%^e%^C208%^r%^C202%^i%^C214%^n%^C208%^g %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s %^RESET%^%^C202%^roll about "+caster->QCN+"%^RESET%^%^CRST%^%^C202%^'s fists, darting out to sear "+myVic->QCN+"%^RESET%^%^CRST%^%^C202%^!%^CRST%^", ({caster, myVic}));
                    }
                    break;
            }
        }
        myVic->cause_typed_damage(myVic, (string)myVic->return_target_limb(), dam, dam_type);
        return;
    }
    else
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C255%^You strike out at "+myVic->QCN+"^RESET%^%^CRST%^%^C255%^ but miss your mark!%^CRST%^");
        tell_object(myVic, "^RESET%^%^CRST%^%^C255%^"+caster->QCN+"^RESET%^%^CRST%^%^C255%^ strikes out at you, but you manage to avoid the blow!%^CRST%^");
        if(objectp(environment(caster)))
        {
            tell_room(environment(caster), "^RESET%^%^CRST%^%^C255%^"+caster->QCN+"^RESET%^%^CRST%^%^C255%^ strikes out at "+myVic->QCN+"^RESET%^%^CRST%^%^C255%^ but misses "+caster->QP+" mark!%^CRST%^", ({caster, myVic}));
        }
    }
    return;
}

void check()
{
    object myFB, *weapons, myWeapon;
    int x, myDam;
    string myWay;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(myFB = caster->query_property("flurry of blows")))
    {
        dest_effect();
        return;
    }
    if((int)caster->query_alignment() > 3)
    {
        myFB->dest_effect();
        dest_effect();
        return;
    }
    if(!(int)USER_D->can_spend_ki(caster, 1))
    {
        call_out("check",ROUND_LENGTH);
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        call_out("check",ROUND_LENGTH);
        return;
    }
    if(caster->is_in_combat())
    {
        //only very rare chance of getting extra attacks when doing either - Saide
        myWay = (string)caster->query("monk way");
        if((int)caster->query_property("using instant feat") || caster->query_casting())
        {
            //higher chance of procs for way of the elements monks when casting or using another
            //feat
            if(myWay == "way of the elements" && random(3))
            {
                call_out("check", ROUND_LENGTH);
                return;
            }
            else if(random(10))
            {
                call_out("check",ROUND_LENGTH);
                return;
            }
        }
        weapons = (object *)caster->query_wielded();
        for(x = 0;x < sizeof(weapons);x++)
        {
            if(!objectp(weapons[x])) continue;
            //allow small weapons only - Saide
            if((int)weapons[x]->query_size() > 1)
            {
                call_out("check",ROUND_LENGTH);
                return;
            }
            continue;
        }
        if(!caster->is_ok_armour("barb"))
        {
            call_out("check",ROUND_LENGTH);
            return;
        }
        if(!(int)USER_D->can_spend_ki(caster, 1))
        {
            if(objectp(myFB)) myFB->dest_effect();
            dest_effect();
            return;
        }
        tell_object(caster, "%^RESET%^%^CRST%^%^C051%^You spot a weakness in your enemy's defense and launch an attack!%^CRST%^");
        /*if(objectp(environment(caster)))
        {
            tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^ launches an attack!%^RESET%^", caster);
        }*/
        for(int y = 0; y < (1 + caster->query_class_level("monk") / 15); y++)
        {
            flurry_hit();
            caster->spend_ki(1);
        }
        
        //redesigning so that extra hits are successful if
        //making a touch attack - do not use weapon at all - bare hands/tendrils
        //higher chance of second hit for way of the shadow monks with shadow opportunist feat
        if(FEATS_D->usable_feat(caster, "shadow opportunist"))
        {
            if(!random(2))
            {
                tell_object(caster, "%^RESET%^%^CRST%^%^C051%^You spot a weakness in your enemy's defense and launch an attack!%^CRST%^");
                flurry_hit();
            }
        }
        else if(!random(6) && (int)caster->query_class_level("monk") >= 15)
        {
            tell_object(caster, "%^RESET%^%^CRST%^%^C051%^You spot a weakness in your enemy's defense and launch an attack!%^CRST%^");
            /*if(objectp(environment(caster)))
            {
                tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^ launches an attack!%^RESET%^", caster);
            }*/
            flurry_hit();
        }
        //making it simply not function when out of ki - Saide
        /* if(!(int)"/daemon/user_d.c"->can_spend_ki(caster, 1))
        {
            if(objectp(myFB)) myFB->dest_effect();
            dest_effect();
            return;
        }*/
    }
    call_out("check",ROUND_LENGTH);
    return;
}

void dest_effect()
{
    object myFB;
    if(!objectp(caster))
    {
        ::dest_effect();
        remove_feat(TO);
        return;
    }
    if(objectp(myFB = caster->query_property("flurry of blows")))
    {
        if(myFB == TO)
        {
            tell_object(caster, "%^RESET%^%^CRST%^%^C051%^Your focus suddenly wavers and returns to normal, your uncanny ability to spot the weakness in the defenses of your enemies gone for now.%^CRST%^");
            if(objectp(environment(caster)))
            {
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C051%^"+caster->QCN+"%^RESET%^%^CRST%^%^C051%^'s focus suddenly returns to normal.%^CRST%^", caster);
            }
            caster->remove_property("flurry of blows");
        }
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
