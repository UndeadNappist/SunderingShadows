
//archway scene

#include <std.h>

inherit ROOM;
void movie(object targ, int num);

void create(){
  ::create();
  set_name("moving through stone!");
  set_long("You are stuck in the stone!");
  set_property("light",-100);
  set_property("indoors",1);
  set_property("no teleport",1);
  set_smell("default","The smell nothing");
  set_listen("default","You hear absolutely nothing");
}
void init(){
  ::init();
  call_out("movie",10,TP,0);
}
void movie(object targ, int num)
{
  string *classes;
  object ob;
  string race,template,subrace;
  int i,is_stonelord,is_pale_lord;

	if(!objectp(TP)) { return; }
	if(!objectp(targ)) { return; }
   

	race = targ->query_race();
	subrace = targ->query_subrace();	
	template = targ->query_acquired_template();
    if(targ->is_class("stonelord")){is_stonelord = 1;}   
   
    targ->set_paralyzed(5000,"You are unable to do that!");

  switch(num){
  case(0):
  tell_object(targ,
  "\n\n\n"
  "%^C101%^As you touch the %^C059%^archway%^C101%^ you feel a massive force push you from behind, as if a %^C100%^whole mountain%^C101%^ suddenly rushed up behind you. You are plunged into %^C239%^darkness%^C101%^.%^CRST%^");
  break;
  case(1):
  tell_object(targ,
  "\n\n\n"
  "%^C242%^You are encased in %^C239%^stone%^C242%^, but it flows around you like it was liquid, or are you liquid, its hard to tell. It is %^C239%^pitch black%^C242%^ in the middle of the %^C094%^earth%^CRST%^."
  );
  break;
  case(2):
  tell_object(targ,
  "\n\n\n"
  "%^C101%^Suddenly you are moving at unimaginable speeds, pushed along a current that is impossible deep in the %^C240%^mountain%^C101%^. You feel your body pushed to a limit as you rush through thousands of miles a minute through the %^C239%^stone%^C101%^.%^CRST%^"
  );
  break;
  case(3):
  tell_object(targ,
  "\n\n\n"
  "%^C242%^Your body tingles as it passed through %^C185%^metals%^C242%^ and %^C081%^crystals%^C242%^. You pass through a %^C195%^vein of diamond%^C242%^, your eyes passing right through them and %^C141%^dazzling%^C242%^ you!%^CRST%^"
  );
  break;
  
  case(4):
	  
	  if(is_stonelord == 1){
		tell_object(targ,
		"\n\n\n"
		"%^C101%^You feel your body start to slow down and the %^C241%^stone%^C101%^ wrap more closely around you. You can hear the thrum of the %^C094%^earth%^C101%^ and its voice deep in your body. Your %^C124%^heartbeat%^C101%^ slows to almost nothing as you pass through the stone.%^CRST%^");	  break;
	  
	  }	  
	  
	  if(template == "undead"){
		tell_object(targ,
		"\n\n\n"
		"%^C101%^You feel your body start to slow down, and the force of the whole of %^C241%^stone%^C101%^ around you suddenly seems more real. If your %^C088%^heart%^C101%^ could beat, you wonder if it would be racing.%^CRST%^");
	  break;
	  }
	  
	  if(template == "vampire"){
		tell_object(targ,
		"\n\n\n"
		"%^C101%^You feel your body start to slow down, and the force of the whole of %^C242%^stone%^C101%^ around you suddenly seems more real. If your %^C088%^heart%^C101%^ could beat, you wonder if it would be racing.%^CRST%^");	  break;
	  }	 
	  
	  if(is_pale_lord == 1){
		tell_object(targ,
		"\n\n\n"
		"%^C101%^You feel your body start to slow down, and the force of the whole of %^C239%^stone%^C101%^ around you suddenly seems more real. If you still had a %^C088%^heart%^C101%^, you wonder if it would be racing.%^CRST%^");
	  break;
	  }

	  if(subrace == "feytouched"){
		tell_object(targ,
		"\n\n\n"
		"%^C101%^As your body slows, you see something suddenly %^C134%^flash%^C101%^ in your periphery. The %^C240%^earth%^C101%^ around you %^C219%^shimmers%^C101%^ and you realize that you are inches from the %^C140%^feywild%^C101%^. Emotions %^C074%^alien%^C101%^ and %^C069%^wonderous%^C101%^ flow past you and your %^C196%^heart%^C101%^ races a moment. You feel a %^C147%^hand%^C101%^ pull at you, but your body continues through the %^C240%^mountain%^C101%^.%^CRST%^");
	  break;
	  }

	tell_object(targ,
	"\n\n\n"
		"%^C101%^You feel your body start to slow down and the %^C238%^stone%^C101%^ wrap more closely around you. You can hear the thrum of the %^C094%^earth%^C101%^ and its voice deep in your body. Your %^C160%^heartbeat%^C101%^ starts to race as you still cannot see a way out.%^CRST%^");

	  break;
	  
  case(5):	  
	  
	  if(is_stonelord == 1){
		tell_object(targ,
		"\n\n\n"
		"%^C100%^Your covenant with the %^C239%^stone%^C100%^ is complete, and you are at peace.%^CRST%^"
		);
	  break;
	  }	 	  
	 
	  if(template == "undead"){
		tell_object(targ,
		"\n\n\n"
		"%^C100%^So this is what the %^C239%^grave%^C100%^ feels like, this is the %^C248%^silence%^C100%^ and solemnity of the %^C094%^earth%^C100%^. You are entombed here now.%^CRST%^");
		break;
	  }
	  
	  if(subrace == "feytouched"){
		tell_object(targ,
		"\n\n\n"
		"%^C100%^You pass away from the %^C075%^feywild's%^C100%^ influence and your %^C088%^heart rate%^C100%^ falls again. You feel like you recognized the %^C225%^touch%^C100%^ though, there was a familiarity to it%^CRST%^.");
	  break;
	  
	  }

	  tell_object(targ,
		"\n\n\n"
		"%^C100%^The %^C238%^stone%^C100%^ suddenly feels more %^C055%^oppressive%^C100%^ around you. Wait, when was the last time you could breathe? You can't even open your mouth. %^C160%^Panic%^C100%^ starts to grow in you.%^CRST%^"); 
	  break;
	  
  case(6):
  
	  if(is_stonelord == 1){
		tell_object(targ,
		"\n\n\n"
		"%^C059%^Yo%^C058%^u feel the %^C242%^mountain%^C058%^ ending soon and breathe in deeply, enjoying the last of this miraculous journey. The %^C241%^rock%^C058%^ gently deposits you back and you emerge.%^CRST%^");
	  break;
	  
	  }
	  
	  if(template == "undead"){
		tell_object(targ,
		"\n\n\n"
		"%^C058%^You are slowly expelled from the %^C240%^rock%^C058%^. You instinctively %^C088%^claw%^C058%^ your way through the last of the way, as if crawling from your %^C241%^grave%^C058%^.%^CRST%^");
	  break;
	  
	  }
	  
	  if(template == "vampire"){
		tell_object(targ,
		"\n\n\n"
		"%^C058%^You are slowly expelled from the %^C240%^rock%^C058%^. You instinctively %^C088%^claw%^C058%^ your way through the last of the way, as if crawling from your %^C241%^grave%^C058%^.%^CRST%^");
	  break;
	  
	  }	
	  
	  if(is_pale_lord == 1){
		tell_object(targ,
		"\n\n\n"
		"%^C058%^You feel %^C244%^consciousness%^C058%^ slowly leave you, and your head swims. Suddenly and without warning though you are expelled violently from the %^C241%^rock%^C058%^.%^CRST%^");
		break;
	  
	  }  	  

	tell_object(targ,
	"\n\n\n"
		"%^C058%^You feel %^C244%^consciousness%^C058%^ slowly leave you, and your head swims. Suddenly and without warning though you are expelled violently from the %^C241%^rock%^C058%^.%^CRST%^");
    break;
 
 case(7):
 
	tell_object(targ,
	"\n\n\n"
	"%^C144%^You have arrived at the steppes%^CRST%^." );

  targ->set_paralyzed(0);
  targ->move("/d/steppes/outpost/rooms/1");

return;
  }
    num++;
	call_out("movie",10,targ,num);
 return;
}