//changed by ~Circe~ 6/6/11 to be in room only after conversations with Tsera, Garrett, and Nienne
//updated by ~Circe~ 7/30/13 to accommodate the Drow subrace Ssri tel quessir, who have had the curse removed

#include <priest.h>
inherit SPELL;

object who, cast_ob, targ_ob;
string whoname, whocname, cname, Ccname;
int Started;
int DELAY = 259200;

void create() {
    ::create();     
    set_spell_name("commune");
    set_spell_level(([ "innate" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS commune on TARGET");
    set_description("Communion is a bond between elves to express utter trust, acceptance, and devotion. It does not work with half-elves, and will not work if there is even the slightest apprehension or reservation, often failing with even the barest flicker of doubt. It requires total serenity, with a focus entirely on the bond between elves (and thus is not a reliable way to relay messages of any urgency). Removing prejudice or judgment is not easily undertaken in preparation, and it is not unheard of to take weeks to prepare mind, body, and soul. Once ready, the elves will touch palm to palm and finger to finger, and begin to share emotions and experiences, opening their very being to each other in the most sacred of intimacies. Due to the intense nature of this process, it requires a long period of recovery before it can be attempted again.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
}

int preSpell(){
    object CO;
    if(objectp(CO = CASTER->query_property("commune_ob"))){
        CO->failed();
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster, "%^RESET%^%^CRST%^%^C128%^You close your eyes, reaching out with your hands.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C128%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C128%^ closes "+caster->query_possessive()+" eyes, reaching out with "+caster->query_possessive()+" hands.%^CRST%^", caster);
    return "display";
}

void spell_effect(int prof){
    string arg;
    string *ignored, *casterallowed, *targallowed;

    arg = lower_case(ARG);
    if(!(who = find_player(caster->realName(arg)))){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^"+capitalize(arg)+" cannot be found to commune with.%^CRST%^\n");
        if(objectp(TO)) TO->remove();
        return;
    }
//below added by ~Circe~ 6/6/11
    if(!(objectp(present(who,environment(CASTER))))){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^"+capitalize(arg)+" cannot be found to commune with.%^CRST%^\n");
        if(objectp(TO)) TO->remove();
        return;
    }

    cname = CASTER->query_name();
    whoname = who->query_name();
    whocname = who->QCN;
    Ccname = CASTER->QCN;
        
    if(avatarp(who) && !who->query_disguised()){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^"+capitalize(arg)+" cannot be found to commune with.%^CRST%^\n");
        if(objectp(TO)) TO->remove();
        return;
    }
   	if(avatarp(who) && arg == (string)who->query_true_name()){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^"+capitalize(arg)+" cannot be found to commune with.%^CRST%^\n");
        if(objectp(TO)) TO->remove();
        return;
   	}
    if(arg == cname) {
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot commune with yourself.%^CRST%^\n");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(this_player()->cooldown("elven communion")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You have not recovered from your last attempt at communion.%^CRST%^");
        if(objectp(this_object())) this_object()->remove();
        return;
	}
    
    this_player()->add_cooldown("elven communion", DELAY);
    
    if(!random(2)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    
    if(who->query_invis() && (int)who->query_level() > (int)CASTER->query_level()){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(who->is_player() && !interactive(who)){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }

    if((string)who->query_race() != "elf"){
        if((string)who->query("subrace") && (string)who->query("subrace") != "ssri tel quessir"){
            tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
            if(objectp(TO)) TO->remove();
            return;
        }
    }

    if(sizeof(who->query_attackers())){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }

    if(who->query_ghost()){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(who->query_blocked("tell")){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    ignored = who->query_ignored();
    if(!ignored){
        who->reset_ignored();
        ignored = who->query_ignored();
    }
    if((member_array(cname, ignored) != -1)){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
      	return;
    }
    casterallowed = CASTER->query_property("allowed tell");
   	targallowed = who->query_property("allowed tell");   	
    if(!casterallowed) casterallowed = ({});
    if(!targallowed) targallowed = ({});
    if(member_array(cname, targallowed) != -1 && member_array(whoname, casterallowed) != -1){
     	tell_object(CASTER, "You already have a mental link with "+who->query_cap_name()+".\n");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(objectp(who->query_property("commune_ob"))){
        tell_object(CASTER, "%^RESET%^%^CRST%^%^C059%^You cannot establish a proper communion.%^CRST%^");
        if(objectp(TO)) TO->remove();
        return;
    }


    tell_object(CASTER, "%^RESET%^%^C255%^You attempt to %^C051%^commune%^C255%^ with "+who->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^, you must wait and see if "+who->query_subjective()+" accepts your attempt.%^CRST%^");

    tell_object(who, "%^RESET%^%^CRST%^%^C255%^"+CASTER->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^ is attempting to commune with you, do you wish to open your mind and accept the attempt?\ntype <%^C051%^accept%^C255%^> or <%^C051%^deny%^C255%^>%^CRST%^");

    cast_ob = new("/d/magic/obj/commune_ob");
    targ_ob = new("/d/magic/obj/commune_ob");
    caster->set_property("commune_ob", cast_ob);
    who->set_property("commune_ob", targ_ob);
    cast_ob->set_caster(CASTER);
    cast_ob->set_target(who);
    cast_ob->set_cast_ob(targ_ob);
    cast_ob->set_spell_ob(TO);

    targ_ob->set_caster(CASTER);
    targ_ob->set_target(who);
    targ_ob->set_cast_ob(cast_ob);
    targ_ob->set_spell_ob(TO);
    targ_ob->SetMyType(1);

    targ_ob->move(who);
    //targ_ob->set_heart_beat(1);

    cast_ob->move(CASTER);
    //cast_ob->set_heart_beat(1);
    addSpellToCaster();
    CASTER->set_property("spelled", ({TO}) );	   
}

void start_delay(){
    if(!Started){
        call_out("dest_effect",clevel*10);
        Started = 1;
    }
}

void dest_effect() {
    if(objectp(CASTER)){
        CASTER->remove_property_value("spelled", ({TO}) );
    }
    if(objectp(cast_ob)){
        cast_ob->completed();
    }
    if(objectp(targ_ob)){
        targ_ob->completed();
    }	
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}