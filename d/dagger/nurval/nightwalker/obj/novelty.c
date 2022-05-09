/*
  novelty.c
  
  Hammer weapon dropped by the Nightwalker Boss.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

//Hit interval instead of proc chance. Procs every 5 hits.
#define HIT_INTERVAL 5

inherit "/d/common/obj/weapon/warhammer.c";

object owner;
int hit_count;

string color(string str)
{
    return CRAYON_D->color_string(str, "lightning yellow");
}

void create()
{
    ::create();
    
    set_name("novelty");
    set_id( ({ "hammer", "healing hammer", "glowing hammer" }) );
    set_short("%^C160%^N%^C196%^o%^C208%^v%^C220%^e%^C226%^l%^C228%^t%^C231%^y%^CRST%^ - %^C220%^a%^CRST%^ %^C214%^b%^C220%^ri%^C226%^l%^C220%^li%^C214%^a%^C208%^n%^C202%^t%^CRST%^ %^C160%^f%^C196%^l%^C202%^a%^C208%^m%^C214%^i%^C220%^n%^C226%^g%^CRST%^ %^C220%^w%^C226%^a%^C220%^rh%^C214%^a%^C220%^mm%^C226%^e%^C220%^r%^CRST%^");
    set_obvious_short("A %^C220%^l%^C231%^o%^C226%^n%^C220%^g%^CRST%^ %^C220%^ha%^C226%^m%^C228%^m%^C231%^e%^C226%^r bin%^C231%^d%^C228%^i%^C226%^n%^C220%^g%^CRST%^ a %^C196%^b%^C202%^r%^C208%^i%^C214%^l%^C220%^l%^C226%^iant%^CRST%^ %^C220%^f%^C214%^l%^C208%^a%^C202%^m%^C196%^e%^CRST%^");
    set_long(" %^C220%^This %^C214%^h%^C226%^a%^C228%^mm%^C226%^e%^C214%^r%^C220%^ has been constructed wholly from pure %^C231%^g%^C228%^o%^C226%^l%^C220%^d, with the h%^C226%^a%^C228%^n%^C231%^d%^C229%^l%^C231%^e%^C220%^ and %^C231%^s%^C228%^t%^C226%^a%^C228%^f%^C231%^f%^C220%^ of the hammer appearing to be made from a single, large piece of gold. The head of the hammer blunts out and %^C231%^pr%^C228%^ot%^C226%^ru%^C220%^de%^C214%^s%^C220%^ on one side while the other spikes out in a sharp and long %^C231%^l%^C228%^e%^C226%^a%^C220%^f%^C214%^-bl%^C220%^a%^C226%^d%^C228%^e%^C231%^d%^C220%^ shape. Where both sides meet, small little %^C196%^f%^C202%^l%^C208%^am%^C202%^e%^C196%^s%^C220%^ %^C160%^g%^C196%^lo%^C160%^w%^C220%^ in a dimly %^C160%^c%^C196%^r%^C160%^ims%^C196%^o%^C160%^n%^C220%^ colour among smaller engravings of %^C058%^r%^C094%^oot%^C136%^s%^C220%^ that %^C130%^g%^C094%^r%^C058%^o%^C022%^w%^C220%^ along the centre of the bladed side while towards the hammer, small %^C196%^f%^C160%^l%^C197%^or%^C160%^a%^C196%^l%^C220%^ shapes bloom out. The pole of the hammer shows leather wrappings for a sturdier hold and little engravings of roots glide along it until growing out into a %^C160%^re%^C196%^d%^C220%^, %^C196%^p%^C202%^h%^C208%^o%^C214%^e%^C220%^n%^C226%^ix-like fe%^C220%^a%^C214%^t%^C208%^h%^C202%^e%^C196%^r%^C220%^ at the bottom of the %^C226%^po%^C220%^l%^C226%^e.%^CRST%^");
    set_lore("");
    set_value(10000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("positive energy resistance percent", -25);
    set_item_bonus("caster level", 3);
    set_item_bonus("fast healing", 3);
    
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
        if((holder->query_true_align() != 1 &&
           holder->query_true_align() != 4 &&
           holder->query_true_align() != 7) ||
           holder->query_character_level() < 40)
        {
            tell_object(holder, "The wooden handle rejects your hand and you drop it!");
            this_object()->move(environment(holder));
            return;
        }      
               
        owner = holder;
        tell_object(holder, color("As you lift the hammer, you feel it entwine itself with your life force."));
    }
}

int hit_func(object target)
{
    int dam;
    string ename, pname;
    
    if(!owner || !target)
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    pname = owner->query_cap_name();
    ename = target->query_cap_name();
}

int wield_func()
{
    if(environment(this_object()) != owner)
    {
        tell_object(environment(this_object()), "The hammer rejects your touch!");
        return 0;
    }
    
    tell_object(owner, color("As you wield it, the staff alights with radiant flames!"));
    tell_room(environment(owner), color(owner->query_cap_name() + "'s hammer alights with radiant flames."), owner);
    return 1;
}

int unwield_func()
{
    owner && tell_object(owner, "%^CYAN%^You feel the warmth of the hammer disappate as you release it.");
    return 1;
} 