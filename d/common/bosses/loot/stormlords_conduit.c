/*
  stormlords_conduit.c
  
  Khyron-inspired lightning warhammer.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define HIT_INTERVAL 5

inherit "/d/common/obj/weapon/warhammer.c";

string owner;
int hit_count;

void create()
{
    ::create();
    
    set_name("hammer");
    set_id( ({ "hammer", "warhammer", "lord's hammer", "stormlord's hammer", "conduit", "stormlords conduit", "lords hammer", "stormlords hammer" }) );
    set_short("%^C231%^S%^C195%^t%^C153%^o%^C081%^r%^C074%^m%^C067%^l%^C060%^o%^C059%^r%^C239%^d'%^C059%^s %^C060%^C%^C067%^o%^C074%^n%^C081%^d%^C153%^u%^C195%^i%^C231%^t%^RESET%^");
    set_obvious_short("%^C238%^A%^C239%^n %^C240%^o%^C059%^b%^C060%^s%^C061%^i%^C060%^d%^C059%^i%^C240%^a%^C239%^n %^C238%^w%^C239%^a%^C240%^r%^C241%^h%^C059%^a%^C060%^m%^C061%^m%^C060%^e%^C059%^r %^C240%^a%^C239%^d%^C238%^o%^C239%^r%^C240%^n%^C241%^e%^C059%^d %^C060%^w%^C061%^i%^C060%^t%^C059%^h %^C075%^l%^C111%^i%^C153%^g%^C195%^h%^C253%^t%^C250%^n%^C247%^in%^C250%^g %^C253%^g%^C195%^l%^C153%^a%^C111%^s%^C075%^s%^RESET%^");
    set_long("%^C240%^This is a %^C052%^f%^C088%^e%^C124%^a%^C160%^r%^C196%^s%^C160%^o%^C124%^m%^C088%^e %^C240%^one-handed %^C245%^w%^C246%^a%^C247%^r%^C248%^h%^C249%^a%^C248%^m%^C247%^m%^C246%^e%^C245%^r%^C240%^, crafted from %^C059%^o%^C060%^b%^C061%^s%^C060%^id%^C061%^i%^C060%^a%^C059%^n %^C240%^and %^C251%^p%^C252%^u%^C253%^m%^C254%^i%^C255%^c%^C230%^e %^C240%^and adorned with shards of %^C075%^l%^C111%^i%^C153%^g%^C195%^h%^C253%^t%^C250%^n%^C247%^in%^C250%^g %^C253%^g%^C195%^l%^C153%^a%^C111%^s%^C075%^s%^C240%^. The handle is wrapped in %^C095%^d%^C137%^rif%^C095%^tw%^C137%^o%^C095%^od %^C240%^and bound with %^C015%^s%^C231%^i%^C230%^n%^C224%^e%^C223%^w%^C240%^, giving the wielder a secure grip even in the midst of a %^C102%^t%^C103%^e%^C104%^m%^C105%^p%^C104%^e%^C103%^s%^C102%^t%^C240%^. The head of the hammer is etched with symbols of %^C088%^K%^C124%^h%^C160%^yr%^C124%^o%^C088%^n%^C240%^, and crackles with %^C032%^e%^C033%^n%^C075%^e%^C074%^r%^C073%^g%^C072%^y %^C240%^when held by a follower of the god. When wielded in battle, the hammer unleashes the full fury of the %^C253%^s%^C254%^t%^C255%^o%^C254%^r%^C253%^m%^C240%^, sending %^C229%^l%^C241%^i%^C242%^g%^C243%^h%^C229%^t%^C245%^n%^C246%^i%^C229%^n%^C246%^g %^C245%^b%^C229%^o%^C243%^l%^C242%^t%^C229%^s %^C240%^crashing into enemies and summoning howling %^C250%^w%^C251%^i%^C252%^n%^C253%^d%^C254%^s %^C240%^to batter them. It is a weapon of %^C196%^cha%^C160%^o%^C124%^s %^C240%^and %^C196%^dest%^C160%^ru%^C124%^ct%^C088%^io%^C124%^n%^C240%^, imbued with the raw power of Khyron himself.%^RESET%^");
    set_lore("%^C220%^L%^C226%^e%^C227%^g%^C228%^e%^C229%^n%^C230%^d %^C240%^has it that the %^C231%^S%^C195%^t%^C153%^o%^C081%^r%^C074%^m%^C067%^l%^C060%^o%^C059%^r%^C239%^d'%^C059%^s %^C060%^C%^C067%^o%^C074%^n%^C081%^d%^C153%^u%^C195%^i%^C231%^t %^C240%^was forged during a massive %^C250%^s%^C251%^t%^C252%^o%^C253%^r%^C254%^m %^C240%^that ravaged the coast, where a band of devout followers of %^C088%^K%^C124%^h%^C160%^y%^C196%^r%^C160%^o%^C124%^n %^C240%^sought to harness the raw power of the %^C255%^t%^C254%^e%^C253%^m%^C252%^p%^C251%^e%^C250%^s%^C249%^t %^C240%^to create a weapon worthy of their god. They sacrificed many offerings to Khyron, including %^C075%^l%^C111%^i%^C153%^g%^C195%^h%^C253%^t%^C250%^n%^C247%^in%^C250%^g %^C253%^g%^C195%^l%^C153%^a%^C111%^s%^C075%^s%^C240%^, %^C095%^d%^C137%^rif%^C095%^tw%^C137%^o%^C095%^od%^C240%^, %^C059%^o%^C060%^b%^C061%^s%^C060%^id%^C061%^i%^C060%^a%^C059%^n%^C240%^, %^C251%^p%^C252%^u%^C253%^m%^C254%^i%^C255%^c%^C230%^e%^C240%^, and the scales of a %^C023%^l%^C029%^e%^C035%^v%^C042%^i%^C049%^a%^C042%^t%^C035%^h%^C029%^a%^C023%^n%^C240%^, and imbued the %^C245%^w%^C246%^a%^C247%^r%^C248%^h%^C249%^a%^C248%^m%^C247%^m%^C246%^e%^C245%^r%^C240%^ with the %^C033%^e%^C039%^l%^C045%^e%^C051%^m%^C087%^e%^C123%^n%^C159%^t%^C195%^al %^C123%^e%^C087%^n%^C051%^e%^C045%^r%^C039%^g%^C033%^y %^C240%^of the storm. The smith who forged it is said to have been struck by %^C238%^l%^C239%^i%^C229%^g%^C241%^h%^C242%^t%^C243%^n%^C229%^i%^C245%^n%^C229%^g %^C240%^during the process, but instead of killing him, the bolt seemed to infuse him with a %^C214%^d%^C220%^i%^C221%^v%^C227%^i%^C228%^n%^C229%^e e%^C228%^n%^C227%^e%^C221%^r%^C220%^g%^C214%^y %^C240%^that allowed him to complete the weapon.%^RESET%^");
    set_value(100000);
    set_weight(6);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("caster level bonus", 5);
    set_item_bonus("attack bonus", 7);
    set_item_bonus("electricity resistance percent", 25);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
}

void init()
{
    object holder;
    
    ::init();
    
    holder = environment(this_object());
    
    if(!holder || !userp(holder))
        return;
    
    hit_count = 0;
    
    if(!owner)
    {          
        owner = holder->query_true_name();
        tell_object(holder, "You feel your soul bind to the hammer, charging you with incredible energy!");
    }
}

int hit_func(object target)
{
    int dam;
    string ename, pname;
    object holder;
    
    holder = environment(this_object());
    
    if(!objectp(holder) || !objectp(target))
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
    {
        target->cause_typed_damage(target, "torso", roll_dice(1, 10), "electricity");
        return 0;
    }
    
    hit_count = 0;
    
    pname = holder->query_cap_name();
    ename = target->query_cap_name();
    
    tell_room(environment(holder), "%^C240%^When the warhammer strikes its target, it unleashes a %^C220%^t%^C226%^h%^C220%^underous s%^C226%^h%^C220%^ockwave%^C240%^ that tears through the air, leaving behind a trail of %^C253%^c%^C195%^r%^C153%^a%^C111%^c%^C075%^k%^C253%^ling e%^C195%^n%^C153%^e%^C253%^rgy%^C240%^ that scorches the earth and leaves %^C159%^" + target->query_cap_name() + "%^C240%^ reeling in agony!%^CRST%^");
    target->cause_typed_damage(target, "torso", roll_dice(6, 10) + 10, "electricity");

    objectp(target) && new("/cmds/spells/l/_lightning_arc")->use_spell(holder, target, 50, 100, "mage");
    
    return 0;
}

int wield_func()
{
    object holder;
    
    holder = environment(this_object());
    
    if(holder->query_true_align() == 1 || holder->query_true_align() == 4 || holder->query_true_align() == 7 || holder->query_true_name() != owner)
    {
        tell_object(holder, "%^C226%^You feel an intense shock as the hammer denies your unworthy touch!%^CRST%^");
        holder->cause_typed_damage(holder, "torso", roll_dice(6, 10) + 10, "electricity");
        return 0;
    }
    
    tell_object(holder, "%^C231%^You feel a surge of electrical power course through your veins as you lift the mighty warhammer!%^CRST%^");
    return 1;
}

int unwield_func()
{
    object holder;
    
    holder = environment(this_object());
    holder && tell_object(holder, "%^C231%^You feel the electrical power leave your body as you unwield the mighty warhammer.%^CRST%^");
    return 1;
} 