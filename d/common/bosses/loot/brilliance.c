/*
  brilliance.c
  
  Staff of Fire adapted to the mud.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

//Hit interval instead of proc chance. Procs every 5 hits.
#define HIT_INTERVAL 5
#define MAX_CHARGES 10
#define TICKER_INTERVAL 600

inherit "/d/common/obj/weapon/mstaff.c";

string owner;
int hit_count;
int charges = MAX_CHARGES;
int ticker;
object holder;

string color(string str)
{
    return CRAYON_D->color_string(str, "lightning yellow");
}

void create()
{
    ::create();
    
    set_name("brilliance");
    set_id( ({ "brilliance", "staff", "flame staff", "fire staff" }) );
    set_short("%^C209%^B%^C215%^r%^C221%^i%^C227%^l%^C221%^l%^C215%^i%^C209%^ance, the F%^C215%^l%^C221%^a%^C227%^m%^C221%^e%^C209%^s of I%^C215%^n%^C221%^s%^C227%^p%^C221%^i%^C215%^r%^C209%^ation%^CRST%^");
    set_obvious_short("%^C209%^a %^C215%^brilliant%^C209%^ %^C221%^flaming%^C209%^ staff%^CRST%^");
    set_long("%^C209%^This is a tall and ornate staff, crafted from polished oak wood and adorned with intricate carvings of roaring flames and glittering gemstones. At its head is a %^C221%^blazing crystal orb%^C209%^, which glows with a %^C231%^brilliant white light%^C209%^ that seems to radiate %^C215%^warmth%^C209%^ and %^C215%^vitality%^C209%^.%^CRST%^");
    set_lore("%^C227%^The legend of Brilliance, the Flames of Inspiration, tells of a powerful wizard who once sought to harness the power of flames in order to channel them into his creative works. He spent years studying the nature of fire, delving into the deepest secrets of its elemental nature, until he finally crafted a staff of blackened ironwood that was able to channel the raw, primal energy of flame. With this staff in hand, the wizard was able to bring forth works of art and innovation that were unparalleled in their power and beauty. But as time went on, the wizard became consumed by his own passion, and his works grew increasingly dangerous and destructive, fueled by the uncontrollable power of the staff. In the end, the wizard vanished into the flames of his own creation, leaving behind only the staff that had driven him to such heights of madness. It is said that the staff still holds within it the raw, untamed power of flame, and that only the most daring and creative of wielders can hope to master it without being consumed by their own ambition. It is said that one can %^C203%^<scorcher>%^C227%^, %^C203%^<fireball>%^C227%^ or %^C203%^<firestorm>%^C227%^, or even %^C203%^<firewall>%^C227%^ in times of need. Each of these spells within the staff will consume charges equal to its spell level. The wielder of this staff can check its %^C203%^<charges>%^C227%^ at will.%^CRST%^");
    set_value(10000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("caster level bonus", 5);
    set_item_bonus("fire resistance percent", 25);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
}

void init()
{
    ::init();
    
    holder = environment(this_object());
    
    if(!userp(holder))
        return;
    
    add_action("fireball_func", "fireball");
    add_action("storm_func", "firestorm");
    add_action("wall_func", "firewall");
    add_action("scorch_func", "scorcher");
    add_action("show_charges", "charges");
    
    hit_count = 0;
}

int consume_charges(int x)
{
    if(x > charges)
        return 0;
    
    charges -= x;
    
    return 1;
}

int refresh_charges(int x)
{
    charges = min( ({ charges + x, MAX_CHARGES }) );
    charges = max( ({ charges, 0 }) );
    
    return charges;
}

void heart_beat()
{   
    ticker++;
    
    if(!environment())
        return;
    
    if(!query_worn())
        return;
    
    if(ticker < TICKER_INTERVAL)
        return;
    
    ticker = 0;
    refresh_charges(1);
}

int hit_func(object target)
{
    int dam;
    object holder;
    string ename, pname;
    
    if(!owner || !target)
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
    {
        target->cause_typed_damage(target, "torso", roll_dice(1, 10), "fire");
        return 0;
    }
    
    pname = owner->query_cap_name();
    ename = target->query_cap_name();

}

int wield_func()
{
    string stat_to_buff;
    
    if(!holder)
        holder = this_player();
    
    if(!strlen(owner) && userp(holder) && !archp(holder))
        owner = holder->query_true_name();
    
    if(holder->query_true_name() != owner)
    {
        tell_object(holder, "%^C203%^Unworthy hands grasp at the Flames of Inspiration, but they burn with a fury that you cannot contain. Beware the consequences of your audacity!%^CRST%^");
        holder->cause_typed_damage(holder, "torso", 200, "fire");
        return 0;
    }
    
    stat_to_buff = "intelligence";
    if(holder->query_stats(stat_to_buff) < holder->query_stats("charisma"))
        stat_to_buff = "charisma";
    if(holder->query_stats(stat_to_buff) < holder->query_stats("wisdom"))
        stat_to_buff = "wisdom";
    
    if(holder->query_stats(stat_to_buff) < 24)
    {
        tell_object(holder, "%^C203%^The Flames of Inspiration will not suffer a weak or unworthy hand. You are not yet ready to harness its true power!%^CRST%^");
        holder->cause_typed_damage(holder, "torso", 200, "fire");
        return 0;
    }
    
    set_item_bonus(stat_to_buff, 6);
    
    tell_object(holder, "%^C221%^Your mind sparks with inspiration as you wield Brilliance, the Flames of Inspiration, and you feel a fiery energy coursing through your body, empowering you to create and innovate with unparalleled vision and clarity.%^CRST%^");
    return 1;
}

int unwield_func()
{
    owner && tell_object(owner, "%^C203%^As you release your grip on Brilliance, the Flames of Inspiration, you feel the fiery energy that had suffused your body recede, leaving you feeling drained and uninspired, but with a lingering sense of potential and possibility.%^CRST%^");
    return 1;
}

int scorch_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/s/_scorcher")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(2))
        return notify_fail(sprintf("The staff only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), str, this_player()->query_level(), 100, "mage");
    
    return 1;
}

int fireball_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/f/_fireball")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(3))
        return notify_fail(sprintf("The staff only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), str, this_player()->query_level(), 100, "mage");
    
    return 1;
}

int wall_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/w/_wall_of_fire")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(4))
        return notify_fail(sprintf("The staff only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), str, this_player()->query_level(), 100, "mage");
    
    return 1;
}

int storm_func(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/f/_fire_storm")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(7))
        return notify_fail(sprintf("The staff only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), str, this_player()->query_level(), 100, "cleric");
    
    return 1;
}

int show_charges()
{
    printf("You can tell the staff currently has %d out of %d charges available.\n", charges, MAX_CHARGES);
    return 1;
}