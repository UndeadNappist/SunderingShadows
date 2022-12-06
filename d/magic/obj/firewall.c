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
   set_short("%^RESET%^%^CRST%^%^C124%^A wall of %^C091%^f%^C097%^i%^C091%^re%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C124%^You see a massive opaque sheet of fire raging wildly upward in shades of %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^RESET%^%^C124%^%^and %^C196%^red%^C124%^.%^CRST%^");
   set_id( ({"wall","wall of fire","firewall","fire","mirror"}) );
   set_weight(10000);
   set_value(10000);
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
      tell_object(caster,"%^RESET%^%^CRST%^%^C124%^The new wall simply melts into the wall that is already surrounding you!\n%^CRST%^");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C124%^The wall surrounding "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^ glows brighter for a second.\n%^CRST%^");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);

   if(j)
       tell_room(environment(caster),"%^RESET%^%^CRST%^%^C124%^"+caster->QCN+"%^RESET%^%^CRST%^%^C124%^'s enemies are singed by the %^C091%^fl%^C097%^a%^C091%^me%^C097%^s%^RESET%^%^C124%^ and leap back as they rise up!%^CRST%^",foes);
   for(k=0;k<j;k++)
   {
       if(!present(wallname,environment(caster))) continue;
       if(foes[k]->query_property("strength") &&
          strsrch(foes[k]->query_property("strength"),"fire") != -1)
           continue;
       dmg = spellob->query_base_damage();
       tell_object(foes[k],"%^RESET%^%^CRST%^%^C124%^You get burned by the %^C091%^fl%^C097%^a%^C091%^me%^C097%^s%^RESET%^%^C124%^!%^CRST%^");
       foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"fire" );

       if(objectp(foes[k]))
           foes[k]->continue_attack();
   }
   call_out("monitor",7);
}

void monitor() {
   int k,j,dmg;
   object *foes;

   if ((!objectp(caster) || !present(caster->query_name(), ETO)) && !blocking) {
       if (objectp(query_property("spell"))) {
           query_property("spell")->dest_effect();
           return;
       }
       remove_call_out("monitor");
       TO->remove();
       return;
   }
   if (!objectp(environment(TO))) {
       TO->remove();
       return;
   }
   if (objectp(caster)) {
       foes = caster->query_attackers();
       j = sizeof(foes);
       if (j) {
           tell_room(environment(TO), "%^RESET%^%^CRST%^%^C124%^"+caster->QCN+"%^RESET%^%^CRST%^%^C124%^'s enemies are singed by the %^C091%^fl%^C097%^a%^C091%^me%^C097%^s%^RESET%^%^C124%^!%^CRST%^", foes[k]);
           for (k = 0; k < j; k++) {
               if (!objectp(foes[k])) {
                   continue;
               }
               if (foes[k]->query_property("strength") &&
                   strsrch(foes[k]->query_property("strength"), "fire") != -1) {
                   continue;
               }
               tell_object(foes[k], "%^RESET%^%^CRST%^%^C124%^You get burned by the %^C091%^fl%^C097%^a%^C091%^me%^C097%^s%^RESET%^%^C124%^!%^CRST%^");
               dmg = spellob->query_base_damage();
               foes[k]->cause_typed_damage(foes[k], foes[k]->return_target_limb(), dmg, "fire");
               if (objectp(foes[k])) {
                   foes[k]->continue_attack();
               }
           }
       }
   }
   call_out("monitor",7);
}

void block(object ob, string exitn) {
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = caster->query_guild_level("mage");
   exitname = exitn;
   set_short("%^RESET%^%^CRST%^%^C124%^A wall of %^C091%^f%^C097%^i%^C091%^re %^RESET%^%^C124%^blocking the %^CRST%^"+exitname);
   set_long("%^RESET%^%^CRST%^%^C124%^You see a massive opaque sheet of fire raging wildly upward in shades of %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^RESET%^%^C124%^%^and %^C196%^red%^C124%^. It fully blocks the "+exitname+".%^CRST%^");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"%^RESET%^%^CRST%^%^C124%^The new wall simply melts into the wall that is already blocking the "+exitname+"\n%^CRST%^");
      tell_room(environment(caster),"%^RESET%^%^CRST%^%^C124%^The wall blocking the "+exitname+" glows brighter for a second.\n%^CRST%^");
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
            tell_object(caster,"%^RESET%^%^CRST%^%^C124%^Your wall of %^C091%^f%^C097%^l%^C091%^am%^C097%^e%^RESET%^%^C124%^"+exitdesc+" dissipates away.%^CRST%^");
         else {
            tell_object(caster,"%^RESET%^%^CRST%^%^C124%^The wall of %^C091%^f%^C097%^l%^C091%^am%^C097%^e%^RESET%^%^C124%^ that surrounds you dissipates away.%^CRST%^");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^RESET%^%^CRST%^%^C124%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^'s wall of %^C091%^f%^C097%^l%^C091%^am%^C097%^e%^RESET%^%^C124%^"+exitdesc+" dissipates away.%^CRST%^", notsee);
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
        tell_object(TP,"%^RESET%^%^CRST%^%^C124%^You step into the %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^in%^C097%^f%^C091%^ern%^C097%^o%^RESET%^%^C124%^, walking calmly through the flames, unharmed.%^CRST%^");
        tell_room(ETP,"%^RESET%^%^CRST%^%^C124%^"+TPQCN+"%^RESET%^%^CRST%^%^C124%^ walks calmly into the %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^in%^C097%^f%^C091%^ern%^C097%^o%^RESET%^%^C124%^ blocking the "+exitname+", unaffected by the flames.%^CRST%^",TP);
        return 0;
    }
    tell_object(TP,"%^RESET%^%^CRST%^%^C124%^You step into the %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^in%^C097%^f%^C091%^ern%^C097%^o%^RESET%^%^C124%^, rushing through before the flames engulf you.%^CRST%^");
    tell_room(ETP,"%^RESET%^%^CRST%^%^C124%^"+TPQCN+"%^RESET%^%^CRST%^%^C124%^ rushes into the %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^in%^C097%^f%^C091%^ern%^C097%^o%^RESET%^%^C124%^ blocking the "+exitname+", as the flames attack "+TP->query_objective()+"!%^CRST%^",TP);
    if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
    else dmg = roll_dice(2,6)+level+level/2;
    TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"fire" );
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

int is_scrying_mirror() {
	return 1;
}
