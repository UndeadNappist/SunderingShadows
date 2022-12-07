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
   set_name("sonic shield");
   set_short("%^RESET%^%^CRST%^%^C091%^A blurred %^C135%^sonic %^C091%^shield%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C091%^You can see a blurred field of %^C135%^sonic energy%^C091%^, causing the air around it to vibrate violently.%^CRST%^");
   set_id( ({"shield","sonic shield","sonic field","field of sonic"}) );
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
      tell_object(caster,"%^RESET%^%^CRST%^%^C091%^The new wall simply melts into the wall that is already surrounding you!%^CRST%^\n");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C091%^The wall surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C091%^ glows brighter for a second.%^CRST%^\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"sonic") != -1)
         continue;
      tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C091%^"+foes[k]->query_cap_name()+"%^RESET%^%^CRST%^%^C091%^ leaps back as the %^C135%^sonic field%^C091%^ rises up and catches "+foes[k]->query_objective()+" on its edge!%^CRST%^",foes[k]);
      tell_object(foes[k],"%^RESET%^%^CRST%^%^C091%^You jump away as a piercing note strikes your ears from the %^C135%^sonic field%^C091%^ that springs up around "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C091%^.%^CRST%^");
      dmg = spellob->query_base_damage();
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"sonic" );
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
         strsrch(foes[k]->query_property("strength"),"sonic") != -1)
         continue;
      tell_room(environment(foes[k]),"%^RESET%^%^CRST%^%^C091%^"+foes[k]->query_cap_name()+"%^RESET%^%^CRST%^%^C091%^ is buffeted by the %^C135%^sonic field%^C091%^!%^CRST%^",foes[k]);
      tell_object(foes[k],"%^RESET%^%^CRST%^%^C091%^The scream of the %^C135%^sonic shield%^C091%^ echoes violently in your ears!%^CRST%^");
      dmg = spellob->query_base_damage();
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"sonic" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
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
   set_short("%^RESET%^%^CRST%^%^C091%^A %^C135%^sonic shield%^C091%^ blocking the %^CRST%^"+exitname);
   set_long("%^RESET%^%^CRST%^%^C091%^You can see a blurred field of %^C135%^sonic energy%^RESET%^%^C091%^, causing the air around it to vibrate violently. It fully blocks the "+exitname+".%^CRST%^");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^RESET%^%^CRST%^%^C091%^The new wall blurs into the wall that is already blocking the "+exitname+".%^CRST%^\n");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C091%^The wall blocking the "+exitname+" glows brighter for a second.%^CRST%^\n");
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
            tell_object(caster,"%^RESET%^%^CRST%^%^C091%^The %^C135%^sonic shield%^C091%^"+exitdesc+" fades away.%^CRST%^");
         else {
            tell_object(caster,"%^RESET%^%^CRST%^%^C091%^The %^C135%^sonic shield%^C091%^ protecting you fades away.%^CRST%^");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^RESET%^%^CRST%^%^C091%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C091%^'s %^C135%^sonic shield%^C091%^"+exitdesc+" fades away.%^CRST%^", notsee);
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
   if(TP->query_property("strength") && strsrch(TP->query_property("strength"),"sonic") != -1 ) {
      tell_object(TP,"%^RESET%^%^CRST%^%^C091%^You step calmly through the field of %^C135%^sonic vibrations%^C091%^, totally unharmed.%^CRST%^");
      tell_room(ETP,"%^RESET%^%^CRST%^%^C091%^"+TPQCN+"%^RESET%^%^CRST%^%^C091%^ steps calmly through the field of %^C135%^sonic vibrations%^C091%^ blocking the "+exitname+", totally unharmed.%^CRST%^",TP);
      return 0;
   }
   tell_object(TP,"%^RESET%^%^CRST%^%^C091%^You rush quickly through the %^C135%^sonic field%^C091%^ as the vibrations scream in your ears!%^CRST%^");
   tell_room(ETP,"%^RESET%^%^CRST%^%^C091%^"+TPQCN+"%^RESET%^%^CRST%^%^C091%^ rushes quickly through the %^C135%^sonic field%^C091%^ blocking the "+exitname+"!%^CRST%^",TP);
   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"sonic" );
   if(TP) TP->continue_attack();
   return 0;
}

int end_walls(string str) {
   if(!caster || (TP != caster))
      return 0;
   if(str != "shield")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}

int query_blocking(){
   return blocking;
}
