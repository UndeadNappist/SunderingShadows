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
   set_name("cloud of frost");
   set_short("%^RESET%^%^CRST%^%^C036%^A cloud of %^C051%^frost%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C036%^You see a massive cloud of %^C051%^frosty air %^C036%^drifting here, chilling everything it touches.%^CRST%^");
   set_id( ({"wall","cloud of frost","frost cloud","frost"}) );
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
      tell_object(caster,"%^RESET%^%^CRST%^%^C036%^The new wall simply melts into the wall that is already surrounding you!\n%^CRST%^");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C036%^The wall surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C036%^ glows brighter for a second.\n%^CRST%^");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"cold") != -1)
         continue;
      tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C036%^"+foes[k]->QCN+" is chilled by the %^C051%^icy cloud %^C036%^and leaps back as it forms!%^CRST%^",foes[k]);
      tell_object(foes[k],"%^RESET%^%^CRST%^%^C036%^You get chilled by the %^C051%^icy cloud %^C036%^and jump away from "+caster->QCN+"%^RESET%^%^CRST%^%^C036%^ as it forms up around "+caster->QO+".%^CRST%^");
      dmg = spellob->query_base_damage();
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"cold" );
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
   if(objectp(caster)) {
   foes = caster->query_attackers();
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!objectp(foes[k])) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"cold") != -1)
         continue;
      tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C036%^"+foes[k]->QCN+"%^RESET%^%^CRST%^%^C036%^ is chilled by the cloud of %^C051%^frost%^C036%^!%^CRST%^",foes[k]);
      tell_object(foes[k],"%^RESET%^%^CRST%^%^C036%^You get chilled by the cloud of %^C051%^frost%^C036%^!%^CRST%^");
      dmg = spellob->query_base_damage();
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"cold" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   } }
   call_out("monitor",7);
}

void block(object ob, string exitn, object spell) {
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = spell->query_clevel();
   spellob = spell;
   exitname = exitn;
   set_short("%^RESET%^%^CRST%^%^C036%^A cloud of %^C051%^frost blocking the %^CRST%^"+exitname);
   set_long("%^RESET%^%^CRST%^%^C036%^You see a massive cloud of %^C051%^frosty air %^C036%^drifting here, chilling everything it touches. It fully blocks the "+exitname+".%^CRST%^");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^RESET%^%^CRST%^%^C036%^The new wall simply melts into the wall that is already blocking the "+exitname+"\n%^CRST%^");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C036%^The wall blocking the "+exitname+" glows brighter for a second.\n%^CRST%^");
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
            tell_object(caster,"%^RESET%^%^CRST%^%^C036%^Your cloud of %^C051%^frost%^C036%^"+exitdesc+" dissipates away.%^CRST%^");
         else {
            tell_object(caster,"%^RESET%^%^CRST%^%^C036%^The cloud of %^C051%^frost %^C036%^that surrounds you dissipates away.%^CRST%^");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^RESET%^%^CRST%^%^C036%^"+caster->QCN+"%^RESET%^%^CRST%^%^C036%^'s cloud of %^C051%^frost%^C036%^"+exitdesc+" dissipates away.%^CRST%^", notsee);
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
   if(TP->query_property("strength") && strsrch(TP->query_property("strength"),"cold") != -1 ) {
      tell_object(TP,"%^RESET%^%^CRST%^%^C036%^You step into the cloud of %^C051%^frost%^C036%^, walking calmly through the chilled air, unharmed.%^CRST%^");
      tell_room(ETP,"%^RESET%^%^CRST%^%^C036%^"+TPQCN+"%^RESET%^%^CRST%^%^C036%^ walks calmly into the cloud of %^C051%^frost %^C036%^blocking the "+exitname+", unaffected by the chill.%^CRST%^",TP);
      return 0;
   }
   tell_object(TP,"%^RESET%^%^CRST%^%^C036%^You step into the cloud of %^C051%^frost%^C036%^, rushing through before the air chills you badly.%^CRST%^");
   tell_room(ETP,"%^RESET%^%^CRST%^%^C036%^"+TPQCN+"%^RESET%^%^CRST%^%^C036%^ rushes into the cloud of %^C051%^frost %^C036%^blocking the "+exitname+", as the air chills "+TP->QO+"!%^CRST%^",TP);
   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"cold" );
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
