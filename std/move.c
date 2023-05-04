//  /std/move.c
//  from the Nightmare mudlib
//  handles the moving and removing of objects
//  created by Descarte of Borg 18 february 1993

#include <move.h>
#include <std.h>
#include <rooms.h>

#define SMALL 7
#define MEDIUM 12
#define LARGE 17

#define VOID "/d/shadowgate/void"

private int encumbrance;
nosave private int no_clean;
private int size;
nosave private object last_location;

void strip_temp_values();

void set_size(int x) { size = x;}

int query_size() {
    if ( (size > 0) || (size == SIZE_UNIVERSAL) ) {
        return size;
    }
    if ((this_object()->is_weapon() || this_object()->is_armour())) {
       return SIZE_NORMAL; // If size is unset for weapons and armour, assume it's NORMAL sized.  Many armor and weapons don't have size set as part of course...
    } else {

        if (query_weight() < SMALL) {
            return 1;
        }
        if (query_weight() < MEDIUM) {
            return 2;
        }
        if (query_weight() < LARGE) {
            return 3;
        }
        return 4;
    }
}

int move(mixed dest)
{
    object me, environment, ob, prev;
    string str, msg;

    if (!objectp(me = this_object()))
        return MOVE_DESTRUCTED;

    environment = environment(me);

    if (stringp(dest))
    {
        // if(!objectp(ob = find_object(dest)))
        //    return MOVE_NOT_ALLOWED;
        ob = find_object_or_load(dest);

        if(!objectp(ob))
        {
            if(objectp(me))
            {
                msg = identify(me) + " attempted to move to invalid object.";
                if(objectp(environment)) { msg += " environment was "+identify(environment); }
            }
            else msg = "Invalid object attempted to move into invalid object.";
            return;
        }
    } else
        ob = dest;
    if (!ob)
        return MOVE_NOT_ALLOWED;
    if (!ob->receive_objects(me))
        return MOVE_NOT_ALLOWED;
    if (objectp(environment(me))) {
        if (!environment->loose_object(me)) return MOVE_NOT_ALLOWED;
    }
    if (living(me) && (living(ob) || ob->query("not living")) && !( (int)ob->move_ok() ))
        return MOVE_NOT_ALLOWED;
    if (!ob->add_encumbrance(query_weight()))
        return MOVE_NO_ROOM;
    if (environment(me))
    {
        if(me->is_player()) { environment(me)->add_encumbrance(-1*(int)me->query_player_weight()); }
        else { environment(me)->add_encumbrance(-1*query_weight()); }
    }
    set_last_location(environment(me));
    prev = environment;
    if(!objectp(me)) return MOVE_DESTRUCTED;
    if(!objectp(ob)) return MOVE_DESTRUCTED;
    move_object(ob);
    if(!objectp(me)) return MOVE_DESTRUCTED;
    ob->gain_item(me);

    if (ob->is_room() && me->is_player()) {
        ob->set_had_players();
    }

    if (objectp(prev)) {
        prev->loose_item(me);
    }

    if (objectp(me) && (interactive(me) || me->query_property("croom_track"))) {
        if (objectp(prev) && (!prev->query_property("croom_dirty"))) {
            prev->set_property("croom_dirty", 1);
        }

        if (!ob->query_property("croom_dirty")) {
            ob->set_property("croom_dirty", 1);
        }
    }
    return MOVE_OK;
}

int remove(){
    object env;
    object *inv;
    int i;

    if (!this_object() || !objectp(this_object())) return 0;
    
    env = environment(this_object());
    if (env) {
        env->add_encumbrance(-1*query_weight());
        i= sizeof(inv = all_inventory(this_object()));
        while (i--) inv[i]->move(env);
    }
	if(objectp(env))
	{
		if(living(env))
		{
			env->ApplyObjectBonuses(TO, env, "remove", "move");
		}
	}

    this_object()->set_property("combat_remove",1);
    this_object()->unequip();
    //!userp(this_object()) && this_object()->remove_property("added short");
    
    //This is to catch any lingering (temporary) added shorts
    strip_temp_values();
    
    if(catch(destruct(this_object())))
        return 0;
    
    return 1;
}

void strip_temp_values()
{
    object me;

    if (!objectp(me = this_object()))
        return;

    if(me->is_weapon())
    {
        me->remove_property("temp_hit_bonus");
        me->remove_property_value("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^vibrating%^BOLD%^}%^RESET%^" }));
        me->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ {empowered}%^RESET%^" }) );
        me->remove_property_value("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^ablaze%^BOLD%^}%^RESET%^" }));
        me->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ [bane]%^RESET%^" }) );
        me->remove_property_value("added short", ({ "%^BLACK%^BOLD%^ [%^GREEN%^eldritch%^BLACK%^]%^RESET%^" }) );
        me->remove_property_value("added short", ({ "%^MAGENTA%^ {vampiric}%^RESET%^" }) );
    }
}

int clean_up()
{
    object env, ob, trash, *inv;
    
    if(no_clean)
        return 0;
    
    if(!objectp(ob = this_object()))
        return 0;
    
    if(userp(ob))
        return 0;
    
    if(objectp(env = environment(ob)))
    {
        if(env->query_no_clean())
            return 1;
        if(env->query_property("storage room"))
            return 1;
        if(env->is_bag())
            return 1;
        if(living(env) || userp(env))
            return 1;
    }
    else
    {
        if(ob->query_no_clean())
            return 1;
        
        if(ob->query_property("storage room"))
            return 1;
        
        inv = deep_inventory(ob);
        
        if(sizeof(filter_array(inv, (: userp($1) :))))
            return 1;
        
        trash = load_object("/d/shadowgate/trash");
        
        if(objectp(trash))
        {
            ob->move(trash);
            destruct(trash);
        }
        else
        {
            catch(inv->remove());
            ob->move(ROOM_VOID);
            ob && ob->remove();
            ob && destruct(ob);
        }
        
        return 0;
    }
    
    return 1;
}

void set_last_location(object ob)
{
    last_location = ob;
}

object query_last_location()
{
    return last_location;
}

void set_weight(int x)
{
    encumbrance = x;
}

int query_weight()
{
    return encumbrance;
}

int query_no_clean()
{
    if(this_object()->query_property("no_clean"))
        return 1;
    
    return no_clean;
}

void set_no_clean(int x)
{
    no_clean = x;
}

object query_my_environment() { return environment(this_object()) ;}
