/*
  _augment_arrow.c
  
  Infused ranged attacks with different types of additional effects.
  For Peerless Archer PRC.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define VALID ({ "barbed", "crippling", "enervating", "blinding", "exploding" })

string type;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("PeerlessArcher");
    feat_name("augment_arrow");
    feat_prereq("Peerless Archer L7");
    feat_desc("");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("peerless_archer") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_augment_arrow(string str)
{
    object feat;
    if (!objectp(this_player()))
    {
        return 0;
    }
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat()
{
    object ob;
    
    ::execute_feat();
    
    if(ob = query_active_feat("augment arrow"))
    {
        tell_object(caster, "You put away your specialized arrows and begin utilizing normal arrows again.");
        ob->dest_effect();
        dest_effect();
        return;
    }
    
    if(!arg || !strlen(arg) || member_array(arg, VALID) < 0)
    {
        tell_object(caster, "%^CYAN%^You must select a valid augmentation type. Valid choices are : %^YELLOW%^" + implode(VALID, ", ") + ".%^RESET%^");
        dest_effect();
        return;
    }
    
    //These will become far more stylized descriptions
    switch(arg)
    {
        case "barbed":
        tell_object(caster, "You attach a barbed head to some of your arrows.");
        break;
        case "crippling":
        tell_object(caster, "You attach a crippling head to some of your arrows.");
        break;
        case "enervating":
        tell_object(caster, "You attach an enervating head to some of your arrows.");
        break;
        case "blinding":
        tell_object(caster, "You attach a blinding head to some of your arrows.");
        break;
        tell_object(caster, "You attach an exploding head to some of your arrows.");
        break;
    }
    
    type = arg;
    
    caster->set_property("active_feats", ({ this_object() }));
    
}