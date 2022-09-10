#include <std.h>
#include <daemons.h>

#define SHAPE_DIR "/std/races/shapeshifted_races/"
#define DELAY 180

inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("PactBond");
    feat_name("final_covenant");
    feat_prereq("Warlock L31");
    feat_syntax("final_covenant");
    feat_desc("");
    set_target_required(0);
    allow_blind(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("warlock") < 31)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_final_covenant(string str)
{
    object feat;
    if(!objectp(this_player())) { return 0; }
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(),str);
    return 1;
}

void execute_feat()
{   
    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You can't use final covenant while you're casting a spell.");
        dest_effect();
        return;
    }
    
    if(caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    if(caster->cooldown("final covenant"))
    {
        tell_object(caster, "You aren't ready to use final covenant yet.");
        dest_effect();
        return;
    }
    
    ::execute_feat();

    tell_object(caster,"You open yourself to possession by your patron.");
    //tell_room(place,"Shifting into message room",caster);
    caster->set_property("using instant feat",1);
}


void execute_attack()
{
    object shape;
    string pact, file;

    if(!objectp(caster)) { return; }

    caster->remove_property("using instant feat");
    ::execute_attack();

    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You can't shapeshift while you're casting a spell.");
        dest_effect();
        return;
    }

    pact = caster->query("warlock heritage");
    
    switch(pact)
    {
        case "abyssal":
        case "demonic":
        file = "warlock_abyssal.c";
        break;
        case "infernal":
        file = "warlock_infernal.c";
        break;
        case "gloom":
        file = "warlock_gloom.c";
        break;
        case "astral":
        file = "warlock_astral.c";
        break;
        case "fey":
        file = "warlock_fey.c";
        break;
    }
    
    strlen(file) && catch(shape = new(SHAPE_DIR + file));
    objectp(shape) && shape->init_shape(caster);
    caster->add_cooldown("final covenant", DELAY);
    
    return;
}

void dest_effect()
{
    object shape;
    
    if(shape = caster->query_property("shapeshifted"))
        shape->reverse_shape(caster);
    else if(shape = caster->query_property("altered"))
        shape->reverse_shape(caster);
    
    ::dest_effect();
    remove_feat(this_object());
    return;
}
