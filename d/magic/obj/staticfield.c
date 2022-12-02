#include <std.h>

inherit OBJECT;

int blocking = 0;
string exitname;
object caster;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("static field");
   set_short("%^RESET%^%^CRST%^%^C101%^A crackling field of %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C101%^You can see a crackling field of %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c e%^C230%^n%^C228%^erg%^C230%^y%^RESET%^%^C101%^, sending jolts of electricity into the air around it.%^CRST%^");
   set_id( ({"field","static field","electric field","static"}) );
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

void surround(object ob) {
   int k,j,dmg;
   object *foes;
   string whose,wallname;

   caster = ob;
   add_action("end_walls","remove");
   foes = caster->query_attackers();
   whose = caster->query_name();
   level = caster->query_guild_level("mage");
   wallname = whose+"surroundingfirewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^RESET%^%^CRST%^%^C101%^The new wall simply melds into the wall that is already surrounding you!%^CRST%^\n");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C101%^The wall surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ glows brighter for a second.%^CRST%^\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"electricity") != -1)
         continue;
      tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C101%^"+foes[k]->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ leaps back as a crackling field of %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c %^RESET%^%^C101%^comes into being near "+foes[k]->query_objective()+"!%^CRST%^",foes[k]);
      tell_object(foes[k],"%^RESET%^%^CRST%^%^C101%^You leap back as a crackling field of %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c %^RESET%^%^C101%^comes into being around "+caster->query_cap_name()+".%^CRST%^");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"electricity" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
//          foes[k]->set_attackers((object *)foes[k]->query_attackers() -({caster}) );
//          caster->set_attackers((object *)caster->query_attackers() -({foes[k]}) );
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
   foes = caster->query_attackers();
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!objectp(foes[k])) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"electricity") != -1)
         continue;
      tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C101%^"+foes[k]->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ is zapped by the field of %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c%^RESET%^%^C101%^!%^CRST%^",foes[k]);
      tell_object(foes[k],"%^RESET%^%^CRST%^%^C101%^The %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c %^RESET%^%^C101%^field crackles and zaps you!%^CRST%^");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"electricity" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void block(object ob, string exitn) {
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = caster->query_guild_level("mage");
   exitname = exitn;
   set_short("%^RESET%^%^CRST%^%^C101%^A crackling field of %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c %^RESET%^%^C101%^blocking the %^CRST%^"+exitname);
   set_long("%^RESET%^%^CRST%^%^C101%^You can see a crackling field of %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c e%^C230%^n%^C228%^erg%^C230%^y%^RESET%^%^C101%^, sending jolts of electricity into the air around it. It fully blocks the "+exitname+".%^CRST%^");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^RESET%^%^CRST%^%^C101%^The new wall blurs into the wall that is already blocking the "+exitname+".%^CRST%^\n");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C101%^The wall blocking the "+exitname+" glows brighter for a second.%^CRST%^\n");
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
            tell_object(caster,"%^RESET%^%^CRST%^%^C101%^The %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c fie%^C230%^l%^C228%^d%^RESET%^%^C101%^"+exitdesc+" fades away.%^CRST%^");
         else {
            tell_object(caster,"%^RESET%^%^CRST%^%^C101%^The %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c fie%^C230%^l%^C228%^d%^RESET%^%^C101%^ protecting you fades away.%^CRST%^");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^'s %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c fie%^C230%^l%^C228%^d%^RESET%^%^C101%^"+exitdesc+" fades away.%^CRST%^", notsee);
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
   if(TP->query_property("strength") &&
strsrch(TP->query_property("strength"),"electricity") != -1 ) {
      tell_object(TP,"%^RESET%^%^CRST%^%^C101%^You step calmly through the %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c fie%^C230%^l%^C228%^d%^RESET%^%^C101%^, totally unharmed.%^CRST%^");
      tell_room(ETP,"%^RESET%^%^CRST%^%^C101%^"+TPQCN+"%^RESET%^%^CRST%^%^C101%^ steps calmly through the %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c fie%^C230%^l%^C228%^d%^RESET%^%^C101%^ blocking the "+exitname+", totally unharmed.%^CRST%^",TP);
      return 0;
   }
   tell_object(TP,"%^RESET%^%^CRST%^%^C101%^You dash through the %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c fie%^C230%^l%^C228%^d%^RESET%^%^C101%^ and the air crackles over your skin!%^CRST%^");
   tell_room(ETP,"%^RESET%^%^CRST%^%^C101%^"+TPQCN+"%^RESET%^%^CRST%^%^C101%^ rushes quickly through the %^C228%^st%^C230%^a%^C228%^t%^C230%^i%^C228%^c fie%^C230%^l%^C228%^d%^RESET%^%^C101%^ blocking the "+exitname+", as the charged air crackles over "+TP->QP+" skin!%^CRST%^",TP);
   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"electricity" );
   if(TP) TP->continue_attack();
   return 0;
}

int end_walls(string str) {
   if(!caster || (TP != caster))
      return 0;
   if(str != "field")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}

int query_blocking(){
   return blocking;
}
