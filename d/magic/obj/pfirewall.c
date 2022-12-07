#include <std.h>
inherit OBJECT;

int blocking = 0;
string exitname;
object caster;
object spellob;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("wall of fire");
   set_short("%^RESET%^%^CRST%^%^C124%^A wall of %^C024%^co%^C023%^ba%^C030%^lt %^C024%^fl%^C023%^am%^C030%^es%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C160%^You see a massive opaque sheet of fire raging wildly upward in shades of %^C024%^co%^C023%^ba%^C030%^lt %^C024%^bl%^C023%^ue%^C124%^.%^CRST%^");
   set_id( ({"wall","wall of cobalt flames","cobalt flames","flames"}) );
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
}

void init() {
   ::init();
   add_action("end_walls","remove");
   if(blocking)
      add_action("damager",exitname);
}

void surround(object ob, object spell) {
   int k,j,dmg;
   object *foes;
   string whose,wallname;

   caster = ob;
   add_action("end_walls","remove");
   foes = caster->query_attackers();
   whose = caster->query_name();
   level = spell->query_clevel();
   spellob = spell;
   wallname = whose+"surroundingfirewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^RESET%^%^CRST%^%^C124%^The new %^C024%^wa%^C023%^ll %^C030%^of %^C024%^fl%^C023%^am%^C030%^e %^RESET%^%^C124%^simply melts into the wall that is already surrounding you!%^CRST%^\n");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C124%^The %^C024%^wa%^C023%^ll %^C030%^of %^C024%^fl%^C023%^am%^C030%^e %^RESET%^%^C124%^surrounding "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^ glows brighter for a second.%^CRST%^\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"fire") != -1)
         continue;
      tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C160%^"+foes[k]->QCN+" is singed by the %^C024%^fl%^C023%^am%^030%^es %^C160%^and leaps back as they rise up!%^CRST%^",foes[k]);
      tell_object(foes[k],"%^RESET%^%^CRST%^%^C124%^You get singed by the %^C024%^fl%^C023%^am%^030%^es %^C160%^and jump away from "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^ as they spring up around "+caster->QO+".%^CRST%^");
      dmg = spellob->query_base_damage();
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"fire" );
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"untyped" );
      if(objectp(foes[k])) foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void monitor() {
   int k,j,dmg;
   object *foes;

   if((!objectp(caster) || !present(caster->query_name(),ETO)) && !blocking) {
      if(objectp(query_property("spell"))) {
         query_property("spell")->dest_effect();
         return;
      }
      remove_call_out("monitor");
      TO->remove();
   }
   if(objectp(caster)) {
     foes = caster->query_attackers();
     j = sizeof(foes);
     for(k=0;k<j;k++) {
       if(!objectp(foes[k])) continue;
       if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"fire") != -1)
         continue;
       tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C160%^"+foes[k]->query_cap_name()+"%^RESET%^%^CRST%^%^C160%^ is burned by the %^C024%^fl%^C023%^am%^030%^es %^C160%^!",foes[k]);
       tell_object(foes[k],"%^RESET%^%^CRST%^%^C160%^You get burned by the %^C024%^fl%^C023%^am%^030%^es %^C160%^!");
       dmg = spellob->query_base_damage();
       foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"fire" );
       foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg/2,"untyped" );
       if(objectp(foes[k])) foes[k]->continue_attack();
     }
   }
   call_out("monitor",7);
}

void block(object ob, string exitn, object spell) {
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = spell->query_clevel();
   spellob = spell;
   exitname = exitn;
   set_short("%^RESET%^%^CRST%^%^C124%^A wall of %^C024%^co%^C023%^ba%^C030%^lt %^C024%^fl%^C023%^am%^C030%^es %^RESET%^%^C124%^blocking the %^CRST%^"+exitname);
   set_long("%^RESET%^%^CRST%^%^C160%^You see a massive opaque sheet of fire raging wildly upward in shades of %^C024%^co%^C023%^ba%^C030%^lt %^C024%^bl%^C023%^ue%^C124%^. It fully blocks the %^CRST%^"+exitname+".");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^RESET%^%^CRST%^%^C124%^The new %^C024%^wa%^C023%^ll %^C030%^of %^C024%^fl%^C023%^am%^C030%^e %^RESET%^%^C124%^simply melts into the wall that is already blocking the "+exitname+".%^CRST%^\n");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C124%^The %^C024%^wa%^C023%^ll %^C030%^of %^C024%^fl%^C023%^am%^C030%^e %^RESET%^%^C124%^blocking the "+exitname+" glows brighter for a second.%^CRST%^\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
}

void remove_wall() {
   object *notsee = ({});
   string exitdesc = "";

   if(blocking)
      exitdesc = ", blocking the "+exitname+",";
   if(objectp(caster) && objectp(ETO)) {
      if(present(caster,ETO)) {
         notsee = ({caster});
         if(blocking)
            tell_object(caster,"%^RESET%^%^CRST%^%^C124%^Your %^C024%^wa%^C023%^ll %^C030%^of %^C024%^fl%^C023%^am%^C030%^e%^RESET%^%^C124%^"+exitdesc+" dissipates away.%^CRST%^");
         else {
            tell_object(caster,"%^RESET%^%^CRST%^%^C124%^The %^C024%^wa%^C023%^ll %^C030%^of %^C024%^fl%^C023%^am%^C030%^e %^RESET%^%^C124%^that surrounds you dissipates away.%^CRST%^");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^RESET%^%^CRST%^%^C124%^"+caster->QCN+"%^RESET%^%^CRST%^%^C124%^'s %^C024%^wa%^C023%^ll %^C030%^of %^C024%^fl%^C023%^am%^C030%^e%^RESET%^%^C124%^"+exitdesc+" dissipates away.%^CRST%^", notsee);
   }
   destruct(TO);
   return;
}

int damager(string str) {
   int dmg;
   if(TP->query_paralyzed() || TP->query_bound() || TP->query_tripped() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(caster)
      if((string)caster->query_name()==(string)TPQN )
         return 0;
   if(TP->query_property("strength") && strsrch(TP->query_property("strength"),"fire") != -1 ) {
      tell_object(TP,"%^RESET%^%^CRST%^%^C160%^You step into the %^C024%^co%^C023%^ba%^C030%^lt %^C024%^in%^C023%^fe%^C030%^rn%^C024%^o%^RESET%^%^C160%^, walking calmly through the flames, unharmed.%^CRST%^");
      tell_room(ETP,"%^RESET%^%^CRST%^%^C160%^"+TPQCN+"%^RESET%^%^CRST%^%^C160%^ walks calmly into the %^C024%^co%^C023%^ba%^C030%^lt %^C024%^in%^C023%^fe%^C030%^rn%^C024%^o%^RESET%^%^C160%^ blocking the "+exitname+", unaffected by the flames.%^CSRT%^",TP);
      return 0;
   }
   tell_object(TP,"%^RESET%^%^CRST%^%^C160%^You step into the %^C024%^co%^C023%^ba%^C030%^lt %^C024%^in%^C023%^fe%^C030%^rn%^C024%^o%^RESET%^%^C160%^, rushing through before the flames engulf you.%^CRST%^");
   tell_room(ETP,"%^RESET%^%^CRST%^%^C160%^"+TPQCN+"%^RESET%^%^CRST%^%^C160%^ rushes into the %^C024%^co%^C023%^ba%^C030%^lt %^C024%^in%^C023%^fe%^C030%^rn%^C024%^o%^RESET%^%^C160%^ blocking the "+exitname+", as the flames attack "+TP->query_objective()+"!%^CRST%^",TP);

   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg/2,"fire" );
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg/2,"untyped" );
   if(TP) TP->continue_attack();
   return 0;
}

int end_walls(string str) {
   if(!caster || (TP != caster))
      return 0;
   if(str != "wall")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}

int query_blocking(){
   return blocking;
}
