/*
  wrecking_devil.c
  
  Magical gnome hooked hammer.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/gnome_hooked_hammer.c";

#define MIN_LEVEL     20
#define HIT_INTERVAL   4

int sundered, hit_count, amount
object holder;

void remove_sunder(object ob)
{
    sundered = 0;
    objectp(ob) && ob->add_ac_bonus(10);
} 

void create()
{
    ::create();
    set_name("hammer");
    set_id( ({ "hammer", "gnome hammer", "gnome hooked hammer", "wrecking devil", "wrecking hammer" }) );
    set_short("%^C184%^W%^C178%^r%^C172%^e%^C173%^c%^C167%^k%^C131%^i%^C095%^n%^C131%^g %^C167%^D%^C173%^e%^C172%^v%^C178%^i%^C184%^l%^RESET%^");
    set_obvious_short("%^C184%^wicked looking gnome hooked hammer%^CRST%^");
    set_long("This is a fearsome gnome hooked hammer that features a hammer head on one end and a wicked hook on the other, both inspired by the commander of the Nine Hells, Mephasm. The hammer's handle is crafted from blackened steel and adorned with intricate engravings that seem to writhe and twist like serpents. The head of the hammer is made from a deep red metal, with jagged spikes and hooks that can be used to tear through armor and flesh alike. When wielded by a skilled warrior, Wrecking Devil becomes a devastating weapon capable of crushing foes and rending them apart with its deadly hooks.");
    set_lore("%^C184%^W%^C178%^r%^C172%^e%^C173%^c%^C167%^k%^C131%^i%^C095%^n%^C131%^g %^C167%^D%^C173%^e%^C172%^v%^C178%^i%^C184%^l %^C124%^is said to have been forged deep within the %^C238%^N%^C160%^i%^C240%^n%^C241%^e %^C242%^H%^C160%^e%^C244%^l%^C245%^l%^C246%^s%^C124%^, by the hands of the archdevil %^C190%^M%^C184%^e%^C178%^p%^C172%^h%^C178%^a%^C184%^s%^C190%^m%^C124%^ himself. It is said that Mephasm imbued the hammer with a portion of his own %^C052%^m%^C088%^a%^C124%^l%^C160%^e%^C196%^v%^C203%^o%^C210%^l%^C217%^e%^C224%^n%^C217%^t %^C210%^e%^C203%^s%^C196%^s%^C160%^e%^C124%^n%^C088%^c%^C052%^e%^C124%^, granting it the power to %^C238%^c%^C104%^o%^C240%^r%^C241%^r%^C242%^u%^C104%^p%^C244%^t %^C124%^and %^C244%^d%^C124%^e%^C242%^s%^C241%^t%^C240%^r%^C124%^o%^C238%^y %^C124%^all it touches. Over the centuries, the hammer has been wielded by many powerful %^C245%^g%^C244%^n%^C243%^o%^C242%^m%^C241%^e%^C240%^s%^C124%^, each leaving their own bloody mark on history. Some say that the hammer is %^C060%^c%^C061%^u%^C062%^r%^C063%^s%^C069%^e%^C075%^d%^C124%^, driving its wielder to %^C136%^m%^C137%^a%^C138%^d%^C139%^n%^C140%^e%^C141%^s%^C147%^s %^C124%^and %^C009%^b%^C196%^l%^C160%^o%^C124%^o%^C088%^d%^C124%^l%^C160%^u%^C196%^s%^C009%^t %^C124%^with each swing. Others claim that it is a powerful tool of %^C220%^j%^C221%^u%^C215%^s%^C209%^t%^C215%^i%^C221%^c%^C220%^e%^C124%^, capable of %^C226%^s%^C227%^m%^C228%^i%^C229%^t%^C228%^i%^C227%^n%^C226%^g %^C124%^the wicked and corrupt wherever they may be found. Regardless of its true nature, there is no denying the awesome %^C066%^p%^C067%^o%^C068%^w%^C069%^e%^C075%^r %^C124%^of Wrecking Devil in the hands of a skilled warrior.%^RESET%^");
    set_value(2000);
    set_weight(6);
    
    set_property("enchantment", 4);
    
    set_hit( (: this_object(), "hit_func" :) );
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object() ,"unwield_func":) );
}

int hit_func(object target)
{
    int damage, room, my_dex_bonus;
    
    if(!objectp(holder = environment(this_object())) || !objectp(target))
        return 0;
    
    if(!objectp(room = environment(holder)))
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    hit_count = 0;
    my_dex_bonus = holder->query_stat_bonus(holder, "dexterity");
    
    switch(random(3))
    {
        case 0: //Trip
        tell_object(holder, "As the wicked hook of Wrecking Devil catches the legs of your foe, they stumble and fall, their fate sealed by the malevolent power of Mephasm.");
        tell_room(room, "The wicked hook of the hammer catches " + target->query_cap_name() + "'s legs and " + target->query_objective() + " stumbles and falls!", holder);
        if(BONUS_D->combat_maneuver(target, holder, my_dex_bonus))
            target->set_tripped(roll_dice(1, 4));
        break;
        default: //Sunder or damage
        if(!sundered && BONUS_D->combat_maneuver(target, holder, my_dex_bonus))
        {
            target->add_ac_bonus(-10);
            tell_object(holder, "The spiked head of Wrecking Devil tears through your foe's armor with ease, leaving them vulnerable to your deadly strikes.");
            tell_room(room, "The spiked head of the hammer tears through " + target->query_cap_name() + "'s armor with ease!", holder);
            sundered = 1;
            call_out("remove_sunder", 30, target);
        }
        else
        {
            tell_object(holder, "The twisted energy of Wrecking Devil crackles through your foe's body as the hammer connects.");
            tell_room(room, "Twisted energy crackles from the hammer as it connects!", holder);
            target->cause_typed_damage(target, "torso", roll_dice(1, 6) + 5, "bludgeoning");
        }
        break;
    }
    
    return roll_dice(1, 4);
}   

int wield_func()
{
    if(!objectp(holder = environment(this_object())))
        return 0;
    
    if(holder->query_base_character_level() < MIN_LEVEL)
    {
        tell_object(holder, "You aren't experience enough to handle this weapon!");
        return 0;
    }
    
    if(holder->query_true_align() != 1 && holder->query_true_align() != 2 && holder->query_true_align() != 3)
    {
        tell_object(holder, "Only those who uphold law and order may wield this weapon!");
        return 0;
    }
    
    tell_object(holder, "As you take hold of Wrecking Devil, you can feel the malevolent power of Mephasm coursing through the hammer, eager to be unleashed upon your enemies.");
    
    return 1;
}

int unwield_func()
{
    if(!objectp(holder = environment(this_object())))
        return 0;
    
    tell_object(holder, "As you release your grip on Wrecking Devil, the malevolent energy of Mephasm fades away, leaving you feeling empty and bereft of its power.");
    
    return 1;
}
    