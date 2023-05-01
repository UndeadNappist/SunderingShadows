//Avatar of Jarmila
#include <std.h>
#include <daemons.h>
#include "/d/antioch/jarmila/jarmila.h"

inherit "/d/common/bosses/avatar_boss.c";

int fate_counter;
int buffed, coreparty;

object bork_control;

void create()
{

    ::create();
    set_name("Avatar of Jarmila");
    set_id(({ "great golden pheonix", "pheonix", "avatar", "jarmila" }));
    set_short("%^C226%^Gre%^C196%^a%^C226%^t G%^C230%^"+
		"o%^C226%^lden Phoe%^C230%^n%^C226%^ix%^C226%^, "+
		"%^C160%^Av%^C124%^a%^C160%^tar of J%^C124%^"+
		"a%^C160%^rmila%^CRST%^");
    set_long("%^C197%^This immense beast is almost beyond "+
	    "all mortal %^C088%^comprehension%^C197%^ and %^C226%^power%^C197%^. "+
	    "Its entire body is formed from %^C124%^blazing divine fire%^C197%^ "+
        "and looks like a giant bird. Its %^C166%^two feet%^C197%^ are each "+
	    "the size of %^C058%^large wagons%^C197%^ and extend to "+
	    "%^C244%^wicked claws%^C197%^ each the size of a man. "+
	    "Its %^C124%^two wings%^C197%^ extend two hundred feet in "+
	    "either direction and when they beat the whole area is "+
	    "bathed in %^C220%^insufferable heat%^C197%^. Long tendrils "+
	    "of %^C124%^flame%^C197%^ extend to form a tail. The most "+
	    "%^C124%^ferocious fire%^C197%^ is reserved for its face, "+
	    "where two eyes as %^C228%^bright as the sun%^C197%^ regard "+
	    "the area with unknowable amounts of wisdom. Overall this "+
	    "avatar is a beast none but the most daring would dare to "+
	    "face.%^CRST%^\n");

    set_gender("female");
    set_race("phoenix");
    set_body_type("fowl");
    set_attack_limbs(({ "right claw", "left claw", "mouth", "tail", "beak", "left wing", "right wing"}));
   
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_class("radiant_servant");
    set_guild_level("fighter", 75);
    set_guild_level("mage", 75);
    set_guild_level("cleric", 75);
    set_mlevel("fighter", 75);
    set_mlevel("mage", 75);
    set_mlevel("cleric", 75);
    set_mlevel("radiant_servant", 10);
    set_alignment(4);
    set("aggressive",100);
    set_property("full attacks",1);
    set_true_seeing(1);

    set_hd(75, 10);
    set_max_hp(100000);
    set_hp(this_object()->query_max_hp());
    set_new_exp(75, "boss");
    set_overall_ac(-75);

    set_damage(10, 20);
    set_base_damage_type("slashing");
    set_property("weapon resistance", 7);
    set_mob_magic_resistance("high");
    set_property("no death", 1);
    set_property("no knockdown", 1);
    set_property("no trip", 1);
    set_property("no tripped", 1);
    set_property("no steal", 1);
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 0);
    set_property("no stun", 0);
    set_property("no bows", 1);
	set_property("no fear", 1);
    set_property("cast and attack", 1);
    set_property("function and attack", 1);

    set_monster_feats(({
	        "spell penetration", "greater spell penetration", "perfect caster"
    }));

   set_funcs(({
//      "flare",
      "comet",
//      "fire",
      "light",
      "reinforce",
      "holy",
//      "clear",

   }));
   
    set_spells(({ "holy aura", "daylight", "celestial brilliance", "sunburst", "meteor swarm", "repel the profane", "cleansing flames", "overwhelming presence", }));
    set_func_chance(50);
    set_spell_chance(50);

    set_skill("perception", 50);

    set_resistance_percent("radiant", 100);
    set_resistance_percent("fire", 100);
    set_mob_magic_resistance("high");
    set_property("cast and attack", 1);
    set_property("function and attack", 1);
    set_property("add quest", "%^BOLD%^%^RED%^Faced the Avatar of Jarmila!%^RESET%^");
    set_property("quest exp", 10000000);

    fate_counter = 0;

}

void init()
{
    int psize;
    object player, room;
    
    ::init();
    
    player = this_player();
    player && room = environment(this_object());
    
    if(!player || !room)
        return;
    
    if (wizardp(player) || player->query_true_invis()) {
        return;
    }
    
    if(!buffed)
    {
        object spell;
        
        if(!catch(spell = new("/cmds/spells/h/_holy_aura.c")))
            spell->use_spell(this_object(), 0, 70, 100, "cleric");
        if(!catch(spell = new("/cmds/spells/d/_daylight.c")))
            spell->use_spell(this_object(), 0, 70, 100, "cleric");
        
        command("radiant_aura");
        buffed = 1;
    }
}


int query_paralyzed()
{
    return 0;
}

int query_tripped()
{
    return 0;
}


void flare (object targ){
new("/cmds/spells/s/_sunburst.c")->use_spell(TO, targ, 80, 100, "cleric");
   fate_counter++;
         check_fate();
   return;
}

void comet (object targ){

int dam;
//dam = random(500)+100;
	dam = roll_dice(25, 20) + 200;

   if(!"/daemon/saving_throw_d.c"->dex_save(targ,80)){

   tell_room(ETO,"%^C178%^The phoenix spreads its massive wings wide "+
   "and calls down a single massive commet on "+targ->QCN+"%^C178%^ which "+
   "engulfs them!%^CRST%^",targ);
   tell_object(targ,"%^C178%^The phoenix spreads its wings and it calls a "+
   "massive comet that plummets towards you!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"fire");
   return;

   fate_counter++;
   check_fate();
   return;
      
}

   else{
   
   dam = dam/2;
   tell_room(ETO,"%^C178%^The phoenix spreads its massive wings wide and "+
   "calls down a single massive commet on "+targ->QCN+"%^C178%^!%^CRST%^",targ);
   tell_object(targ,"%^C178%^The phoenix spreads its wings and it calls a "+
   "massive comet that plummets towards you!%^CRST%^");
   tell_object(targ,"%^C178%^You jump out of the way just in time, "+
   "but still feel fire lick across you!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"fire");
   return;

   fate_counter++;
   check_fate();
   return;
}
}

void fire (object targ){
   tell_room(ETO,"%^C197%^With a scream the phoenix bursts forth with "+
   "several spells all at once!%^CRST%^");

   new("/cmds/spells/m/_meteor_swarm.c")->use_spell(TO,targ,40,100,"mage");
   new("/cmds/spells/f/_fireball.c")->use_spell(TO,targ,40,100,"mage");
   new("/cmds/spells/w/_wall_of_fire.c")->use_spell(TO,targ,40,100,"mage");
      fate_counter++;
      check_fate();
   return;
}


void light (object targ){

int dam;
//dam = random(300)+100;
	dam = roll_dice(15, 20) + 200;

   if(!"/daemon/saving_throw_d.c"->will_save(targ,80)){

   tell_room(ETO,"%^C127%^The phoenix grabs "+targ->QCN+"%^C127%^ "+
   "and lifts them up to their face. It's eyes blaze "+
   "and "+targ->QCN+"%^C127%^ is left dazed!%^CRST%^",targ);
   tell_object(targ,"%^C127%^You are lifed up suddenly "+
   "in the claws of the phoenix and crushed!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam, "piercing");
   tell_object(targ,"%^C127%^The phoenix lifts you "+
   "until you're in front of its eyes which flash. "+
   "You cant turn away in time and are stunned.%^CRST%^");
    targ->set_paralyzed(random(30)+30,"%^C127%^You are "+
	"stunned from the daze of the phoenix!%^CRST%^");
           return;

   fate_counter++;
   check_fate();
   return;
      
}

   else{
   
   tell_room(ETO,"%^C127%^The phoenix grabs "+targ->QCN+" "+
   "%^C127%^and lifts them up to their face. It's eyes "+
   "blaze and "+targ->QCN+" %^C127%^is left dazed!%^CRST%^",targ);
   tell_object(targ,"%^C127%^You are lifted up suddenly "+
   "in the claws of the phoenix and crushed!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam / 2,"piercing");
   tell_object(targ,"%^C127%^The phoenix lifts you until "+
   "you're in front of its eyes which flash. You turn "+
   "away just in time.%^CRST%^");
           return;

   fate_counter++;
   check_fate();
   return;
}
}

void reinforce(object ob){
   int i, num;
   
   if(sizeof(query_followers()))
       return;
   
   num=random(4)+3;
   if(!objectp(TO)) return;
   tell_room(ETO,"%^C222%^For a moment the glow intensifies and "+
   "creatures rush into the area to defend the phoenix!%^CRST%^");

                 for(i=0;i<num;i++){
                    ob=new(MOBS"foo");
                        ob->move(ETO);
                        TO->add_follower(ob);
                 }
   fate_counter++;
   check_fate();
   return;
}

void holy (object targ){

int dam;
//dam = random(500)+100;
dam = roll_dice(25, 20) + 200;

   if(!"/daemon/saving_throw_d.c"->fort_save(targ,40)){

   tell_room(ETO,"%^C225%^A blast of holy energy from the phoenix's "+
   "eyes blasts towards "+targ->QCN+"%^C225%^ which "+
   "engulfs them!%^CRST%^",targ);
   tell_object(targ,"%^C225%^You are flooded with holy energy "+
   "that blasts from the phoenix!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"divine");
   return;

   fate_counter++;
   check_fate();
   return;
      
}

   else{
   
   dam = dam/3;
   tell_room(ETO,"%^C225%^A blast of holy energy from the phoenix's "+
   "eyes blasts towards "+targ->QCN+"%^C225%^ which "+
   "engulfs them!%^CRST%^",targ);
   tell_object(targ,"%^C225%^You are flooded with holy energy that "+
   "blasts from the phoenix!%^CRST%^");
   tell_object(targ,"%^C225%^You grit your teeth and feel "+
   "the worst of the attack fade!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"divine");
   return;

   fate_counter++;
   check_fate();
   return;
}
}
void clear (object targ){
    
   if(random(4))
       return;
   
   tell_room(ETO,"%^C196%^The phoenix chants an ancient holy prayer!%^CRST%^");
   new("/cmds/spells/g/_greater_dispel_magic.c")->use_spell(TO,targ,80,100,"mage");
   return;
      fate_counter++;
      check_fate();
}


void check_fate(){
   if(fate_counter > 9) {unbork();}
   if(fate_counter == 5) {bork();}
}  

void bork (object targ)
{
    object room = environment(this_object());
    //bork_control =find_object_or_load(ROOMS"top.c");
    //bork_control->func_bork();
   
    if(room)
    {
       tell_room(room,"%^C153%^With a flash of the Phoenix's eyes a heavy mist fills the area!%^CRST%^");
       room->set_property("antimagic field");
    }
    return;
}
void unbork (object targ)
{
    object room;    
    //bork_control =find_object_or_load(ROOMS"top.c");
    //bork_control->func_unbork();
    fate_counter = 0;
    room = environment(this_object());
    
    if(room)
    {
        tell_room(room,"%^C153%^The massive phoenix flaps its wings and the mist clears from the area!%^CRST%^");
        room->remove_property("antimagic field");
    }
    
    return;
}

void boss_death_event()
{
    object *attackers;
    
    //environment(this_object())->return_exits();
    
    tell_room(environment(this_object()), "%%^C160%^The phoenix bursts into an explosion of epic proportions and disappears, though the force of its death has cracked open one of the larger sunstones.%^CRST%^");
    broadcast_area("/d/antioch/jarmila/rooms/", "%^C160%^A great plume of %^C124%^fire%^C160%^ erupts on the horizon and for a moment the land basks in a %^C226%^g%^C166%^o%^C226%^lden gl%^C166%^o%^C226%^w%^C160%^, then it fades.%^CRST%^%^RESET%^");
    //message("broadcast", "   %^C160%^A great plume of %^C124%^fire%^C160%^ erupts on the horizon and for a moment the entire realm is basked in a %^C226%^g%^C166%^o%^C226%^lden gl%^C166%^o%^C226%^w%^C160%^, then it fades.%^CRST%^%^RESET%^", users());
    message("broadcast", "%^WHITE%^BOLD%^The balance of power in the world shifts towards %^CYAN%^EVIL%^RESET%^", users());
    WORLD_EVENTS_D->kill_event("Phoenix has been defeated");
    WORLD_EVENTS_D->inject_event((["Phoenix has been defeated" : (["start message" : "%^RED%^%^BOLD%^Phoenix has been defeated!%^RESET%^", "event type" : "exp bonus", "length" : 720, "notification" : "5% Bonus Exp", "event name" : "Phoenix has been defeated", "modifier" : 5, "announce" : 1, "announce to" : "world", "alignments" : ({ 3, 6, 9 }) ]), ]));
}
