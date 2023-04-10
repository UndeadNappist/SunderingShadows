// Chernobog (4/6/23)
// Animate Dead Rework

#include <std.h>

inherit SPELL;

#define LESSER_UNDEAD "/d/magic/mon/create_undead/lesser_undead"

void create()
{
    ::create();
    set_spell_name("animate dead");
    set_spell_level(([ "mage" : 4, "cleric" : 3, "paladin" : 3, "oracle" : 3 ]));
    set_mystery("bones");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS animate dead [on TYPE]");
    set_damage_desc("raises up to clevel/5 lesser minions");
    set_description("%^RESET%^With this spell, the caster releases traces of necrotic energy into the area to cobble decayed matter and bones into serviceable, though weak, minions. Many faiths and cultures condemn this spell and similar powers as it serves the caster's selfish, often evil, motives. Frequent users of the spell are believed to be inherently evil. This spell can be directed to create skeletons or zombies, but will produce a mix of both by default."+extra_help());
    set_property("undead spell", 1);
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    set_helpful_spell(1);
    evil_spell(1);
    set_arg_needed(1);
    set_property("undead spell", 1);
}

string extra_help(){

    return "\n\nEach lesser undead minion uses "+query_poolsize()+" pool slot out of a maximum pool size of twenty, and this resource is shared between all undead creation spells.\n%^ORANGE%^<dismiss undead>%^RESET%^ destroys your current undead retinue%^RESET%^\n%^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^ will command undead to perform an action%^RESET%^\n%^ORANGE%^<command undead to follow>%^RESET%^ forces lost undead to follow you%^RESET%^\n%^ORANGE%^<poolsize>%^RESET%^ lists how many undead minions you have under your control%^RESET%^";
}

string query_poolsize(){
    return "one";
}

string query_cast_string(){
    tell_object(caster, "%^C059%^Raising your hands outward, %^C030%^n%^C036%^e%^C041%^c%^C036%^r%^C030%^o%^C036%^t%^C041%^i%^C036%^c %^C030%^e%^C036%^n%^C041%^e%^C036%^r%^C030%^g%^C036%^y %^C059%^drips from them and seeps into the ground.%^CRST%^");
    tell_room(place, "%^C059%^Raising "+caster->query_cap_name()+"%^C059%^'s hands outwards, %^C030%^n%^C036%^e%^C041%^c%^C036%^r%^C030%^o%^C036%^t%^C041%^i%^C036%^c %^C030%^e%^C036%^n%^C041%^e%^C036%^r%^C030%^g%^C036%^y %^C059%^drips from them and seeps into the ground.%^CRST%^", caster);
    return "display";
}

void spell_effect(int prof){
    int num_minions, max, i;
    object controller, undead;
    string caster_name;
    
    num_minions = caster->query_property("raised");
    if(!intp(num_minions)) num_minions = 0;
    
    if(num_minions >= MAX_RAISE){
        fail();
        tell_room(place, "%^C059%^"+caster->query_cap_name()+"%^C059%^ seems to strain fruitlessly with exertion.%^CRST%^", caster);
        this_object()->remove();
        return;
    }
    
    if(present("undead_controller", caster)) controller = present("undead_controller", caster);
    else{
        controller = new("/d/magic/obj/undead_controller");
        controller->set_caster(caster);
        controller->move(caster);
    }
    
    max = MAX_RAISE - num_minions;
    max = min(({ max, clevel / 5 }));
    caster->remove_property("raised");
    caster_name = caster->query_cap_name();
    
    for(i = 0; i < max; i++){
        if(caster->query_property("raised") >= MAX_RAISE) continue;
        undead = new(LESSER_UNDEAD);
        undead->set_property("raised", 1);
        undead->set_weap_enchant(clevel / 12);
        undead->set_skill("athletics", clevel);
        undead->set_skill("perception", clevel);
        undead->set_property("spell", TO);
        undead->set_property("spell_creature", TO);
        undead->set_property("minion", caster);
        undead->set_owner(caster);
        undead->setup_minion(clevel, spell_level, "lesser");
        skin_fun(undead);
        caster->set_property("raised", 1);
        undead->move(place);
        undead->control(caster);
        controller->add_monster(undead);
        tell_object(caster, "%^C244%^A "+undead->query_short()+" %^C244%^manifests at your side.%^CRST%^");
        tell_room(place, "%^C244%^An "+undead->query_short()+" %^C244%^manifests at "+caster_name+"%^C244%^'s side.%^CRST%^", caster);
    }
    
    succeed();
    dest_effect();
    spell_successful();
    return;
}

void fail(){
    tell_object(caster, "%^C160%^Your desire to control more undead does not meet your skill.%^CRST%^");
    return;
}

void succeed(){
    tell_object(caster, "\n%^C059%^You let your arms drop limply to your sides after completing the spell.%^CRST%^");
    tell_room(place, "\n%^C059%^"+caster->query_cap_name()+"%^C059%^ lets "+caster->query_possessive()+" arms drop limply to "+caster->query_possessive()+" sides.%^CRST%^", caster);
    return;
}

void skin_fun(object undead){
    string choice;
    
    if(!arg || (arg != "skeletons" && arg != "zombies")) choice = random(2) ? "zombies" : "skeletons";
    else choice = arg;
    
    switch(choice){
        case "skeletons":
            switch(random(3)){
                case 0:
                    undead->set_short("%^C059%^m%^C243%^a%^C245%^l%^C243%^f%^C059%^o%^C243%^r%^C245%^m%^C243%^e%^C059%^d %^C250%^s%^C255%^ke%^C250%^l%^C255%^eto%^C250%^n%^C059%^");
                    undead->set_long("%^C059%^This animated skeleton seems to be missing quite a few pieces, but that doesn't appear to stop it from obeying commands from its master.%^CRST%^");
                    break;
                case 1:
                    undead->set_short("%^C059%^m%^C243%^i%^C059%^s%^C245%^m%^C247%^a%^C245%^t%^C059%^c%^C243%^h%^C245%^e%^C247%^d %^C250%^s%^C255%^ke%^C250%^l%^C255%^eto%^C250%^n%^C059%^");
                    undead->set_long("%^C059%^While it appears mostly humanoid, several of the bones seem to be from completely different sources. Several ribs are actually talons, and a clavicle has been replaced by part of a jawbone.%^CRST%^");
                    break;
                case 2:
                    undead->set_short("%^C247%^c%^C250%^h%^C253%^a%^C247%^t%^C250%^t%^C253%^e%^C247%^r%^C250%^i%^C253%^n%^C247%^g %^C250%^s%^C255%^ke%^C250%^l%^C255%^eto%^C250%^n%^C059%^");
                    undead->set_long("%^C059%^Something doesn't appear quite right with this skeleton, as its limbs twitch and spasm as it moves. Even its jaw continuously chatters with every step.%^CRST%^");
                    break;
            }
            undead->add_id("skeleton");
            break;
        case "zombies":
            switch(random(3)){
                case 0:
                    undead->set_short("%^C124%^f%^C160%^l%^C130%^e%^C124%^n%^C160%^s%^C130%^e%^C124%^d %^C070%^z%^C064%^om%^C070%^b%^C064%^i%^C070%^e%^C059%^");
                    undead->set_long("%^C064%^This zombie's skin has been shorn away, leaving exposed muscle and sinew. It appears that several scavengers have already started feasting before its animation.%^CRST%^");
                    break;
                case 1:
                    undead->set_short("%^C031%^d%^C037%^r%^C042%^i%^C031%^p%^C037%^p%^C042%^i%^C031%^n%^C037%^g %^C070%^z%^C064%^om%^C070%^b%^C064%^i%^C070%^e%^C059%^");
                    undead->set_long("%^C064%^Foul ichors and fluids drip from the waterlogged and decayed flesh on this zombie. It is a fierce competition for which is more foul, the form or the smell.%^CRST%^");
                    break;
                case 2:
                    undead->set_short("%^C124%^c%^C125%^ra%^C126%^w%^C124%^l%^C125%^in%^C126%^g %^C070%^z%^C064%^om%^C070%^b%^C064%^i%^C070%^e%^C059%^");
                    undead->set_long("%^C064%^Only half of this zombie remains, and it pulls itself along inexorably by bloody fingers and protruding bones. A wet trail of viscera and blood winds behind it.%^CRST%^");
                    break;
            }
            undead->add_id("zombie");
            break;
    }
    return;
}

void dest_effect(){
    if(objectp(this_object())) this_object()->remove();
}

