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

int sundered, hit_count, amount;
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
    set_long("%^C124%^This is a %^C052%^f%^C088%^e%^C124%^a%^C160%^r%^C196%^s%^C160%^o%^C124%^m%^C088%^e %^C124%^gnome %^C255%^h%^C254%^o%^C253%^o%^C252%^k%^C251%^e%^C250%^d h%^C251%^a%^C252%^m%^C253%^m%^C254%^e%^C255%^r %^C124%^that features a %^C116%^h%^C117%^a%^C123%^m%^C159%^m%^C195%^e%^C231%^r %^C015%^h%^C255%^e%^C254%^a%^C253%^d %^C124%^on one end and a %^C238%^w%^C239%^i%^C240%^c%^C241%^k%^C242%^e%^C243%^d %^C244%^h%^C245%^o%^C246%^o%^C247%^k %^C124%^on the other, both inspired by the commander of the %^C238%^N%^C160%^i%^C240%^n%^C241%^e %^C242%^H%^C160%^e%^C244%^l%^C245%^l%^C246%^s%^C124%^, %^C190%^M%^C184%^e%^C178%^p%^C172%^h%^C178%^a%^C184%^s%^C190%^m%^C124%^. The hammer's handle is crafted from %^C238%^b%^C239%^l%^C240%^a%^C241%^c%^C242%^k%^C243%^e%^C244%^n%^C245%^e%^C246%^d %^C245%^s%^C244%^t%^C243%^e%^C242%^e%^C241%^l %^C124%^and adorned with intricate engravings that seem to %^C082%^w%^C076%^r%^C070%^i%^C064%^the %^C124%^and %^C064%^tw%^C070%^i%^C076%^s%^C082%^t %^C124%^like %^C227%^s%^C191%^e%^C155%^r%^C119%^pe%^C155%^n%^C191%^t%^C227%^s%^C124%^. The head of the hammer is made from a %^C052%^d%^C088%^e%^C124%^e%^C160%^p %^C196%^r%^C160%^e%^C124%^d %^C088%^m%^C052%^e%^C088%^t%^C124%^a%^C160%^l%^C124%^, with jagged %^C240%^s%^C241%^p%^C242%^ik%^C241%^e%^C240%^s %^C124%^and hooks that can be used to tear through %^C245%^a%^C246%^r%^C247%^m%^C248%^o%^C249%^r %^C124%^and %^C230%^f%^C224%^l%^C223%^e%^C222%^s%^C216%^h %^C124%^alike. When wielded by a skilled warrior, %^C184%^W%^C178%^r%^C172%^e%^C173%^c%^C167%^k%^C131%^i%^C095%^n%^C131%^g %^C167%^D%^C173%^e%^C172%^v%^C178%^i%^C184%^l %^C124%^becomes a devastating weapon capable of crushing foes and rending them apart with its deadly hooks.%^RESET%^");
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
        tell_object(holder, "%^C124%^As the %^C238%^w%^C239%^i%^C240%^c%^C241%^k%^C242%^e%^C243%^d %^C242%^h%^C241%^o%^C240%^o%^C239%^k %^C124%^of %^C184%^W%^C178%^r%^C172%^e%^C173%^c%^C167%^k%^C131%^i%^C095%^n%^C131%^g %^C167%^D%^C173%^e%^C172%^v%^C178%^i%^C184%^l %^C124%^catches the %^C221%^l%^C222%^e%^C223%^g%^C224%^s %^C124%^of your foe, they stumble and %^C255%^f%^C254%^a%^C253%^l%^C252%^l%^C124%^, their fate sealed by the %^C062%^m%^C061%^a%^C060%^l%^C059%^e%^C240%^vo%^C059%^l%^C060%^e%^C061%^n%^C062%^t %^C124%^power of %^C190%^M%^C184%^e%^C178%^p%^C172%^h%^C178%^a%^C184%^s%^C190%^m%^C124%^.%^RESET%^");
        tell_room(room, "%^C124%^The wicked hook of the hammer catches " + target->query_cap_name() + "'s legs and " + target->query_objective() + " stumbles and falls!%^CRST%^", holder);
        if(BONUS_D->combat_maneuver(target, holder, my_dex_bonus))
            target->set_tripped(roll_dice(1, 4));
        break;
        default: //Sunder or damage
        if(!sundered && BONUS_D->combat_maneuver(target, holder, my_dex_bonus))
        {
            target->add_ac_bonus(-10);
            tell_object(holder, "%^C124%^The spiked head of %^C184%^W%^C178%^r%^C172%^e%^C173%^c%^C167%^k%^C131%^i%^C095%^n%^C131%^g %^C167%^D%^C173%^e%^C172%^v%^C178%^i%^C184%^l %^C124%^tears through your foe's %^C245%^a%^C246%^r%^C247%^m%^C248%^o%^C249%^r %^C124%^with ease, leaving them vulnerable to your %^C088%^d%^C124%^e%^C160%^a%^C196%^d%^C009%^l%^C197%^y %^C198%^s%^C197%^t%^C009%^r%^C196%^i%^C160%^k%^C124%^e%^C088%^s%^C124%^!%^RESET%^");
            tell_room(room, "%^C124%^The spiked head of the hammer tears through " + target->query_cap_name() + "'s armor with ease!%^CRST%^", holder);
            sundered = 1;
            call_out("remove_sunder", 30, target);
        }
        else
        {
            tell_object(holder, "%^C124%^The %^C155%^t%^C149%^w%^C143%^i%^C137%^s%^C131%^t%^C125%^e%^C124%^d %^C125%^e%^C131%^n%^C137%^e%^C143%^r%^C149%^g%^C155%^y %^C124%^of %^C184%^W%^C178%^r%^C172%^e%^C173%^c%^C167%^k%^C131%^i%^C095%^n%^C131%^g %^C167%^D%^C173%^e%^C172%^v%^C178%^i%^C184%^l %^C124%^crackles through your %^C250%^f%^C249%^o%^C248%^e%^C247%^'%^C246%^s %^C124%^body as the %^C190%^h%^C184%^a%^C178%^m%^C172%^m%^C166%^e%^C167%^r %^C124%^connects.%^RESET%^", holder);
            tell_room(room, "%^C155%^T%^C149%^w%^C143%^i%^C137%^s%^C131%^t%^C125%^e%^C124%^d %^C125%^e%^C131%^n%^C137%^e%^C143%^r%^C149%^g%^C155%^y %^C124%^crackles from the %^C190%^h%^C184%^a%^C178%^m%^C172%^m%^C166%^e%^C167%^r %^C124%^as it %^C245%^c%^C246%^o%^C247%^n%^C248%^n%^C249%^e%^C250%^c%^C251%^t%^C252%^s%^C124%^!%^RESET%^", holder);
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
        tell_object(holder, "%^C124%^You %^C196%^a%^C160%^r%^C124%^en%^C196%^'%^C160%^t %^C027%^e%^C033%^x%^C039%^p%^C045%^e%^C051%^r%^C087%^i%^C051%^e%^C045%^n%^C039%^c%^C033%^e%^C027%^d %^C124%^enough to handle this %^C245%^w%^C246%^e%^C247%^a%^C248%^p%^C249%^o%^C250%^n%^C124%^!%^RESET%^");
        return 0;
    }
    
    if(holder->query_true_align() != 1 && holder->query_true_align() != 2 && holder->query_true_align() != 3)
    {
        tell_object(holder, "%^C124%^Only those who %^C209%^u%^C215%^p%^C221%^h%^C227%^ol%^C221%^d l%^C215%^a%^C209%^w %^C124%^and %^C083%^o%^C084%^r%^C085%^d%^C084%^e%^C085%^r %^C124%^may wield this %^C245%^w%^C246%^e%^C247%^a%^C248%^p%^C249%^o%^C250%^n%^C124%^!%^RESET%^");
        return 0;
    }
    
    tell_object(holder, "%^C124%^As you release your grip on %^C184%^W%^C178%^r%^C172%^e%^C173%^c%^C167%^k%^C131%^i%^C095%^n%^C131%^g %^C167%^D%^C173%^e%^C172%^v%^C178%^i%^C184%^l%^C124%^, the %^C062%^m%^C061%^a%^C060%^l%^C059%^e%^C240%^vo%^C059%^l%^C060%^e%^C061%^n%^C062%^t %^C124%^energy of %^C190%^M%^C184%^e%^C178%^p%^C172%^h%^C178%^a%^C184%^s%^C190%^m %^C124%^fades away, leaving you feeling %^C250%^e%^C251%^m%^C252%^p%^C253%^t%^C254%^y %^C124%^and bereft of its %^C155%^p%^C149%^o%^C143%^w%^C137%^e%^C131%^r%^C124%^.%^RESET%^");
    
    return 1;
}

int unwield_func()
{
    if(!objectp(holder = environment(this_object())))
        return 0;
    
    tell_object(holder, "%^C124%^As you release your grip on Wrecking Devil, the malevolent energy of Mephasm fades away, leaving you feeling empty and bereft of its power.%^CRST%^");
    
    return 1;
}
    