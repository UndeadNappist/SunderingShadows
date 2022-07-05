/*********************************
 * sphere_shadow.c 
 *
 * Tlaloc - 7.5.22
 *
 * This shadows several functions
 * on the player object to render
 * the prismatic sphere recipient
 * essentially unable to engage in
 * combat.
 *********************************/
 
object sphered;
 
int ok_to_kill(object targ)                           { return 0;      } //Can't attack anyone while sphere is up
int is_in_combat()                                    { return 0;      } //Never in combat
int clean_up_attackers()                              { return 0;      } //Never have attackers
object *query_attackers()                             { return ({  }); } //No attackers list while in sphere

object query_sphere_shadow()                          { return this_object(); } //Allows you to reference shadow by calling sphered player


//Mask cause_typed_damage while sphere is up
int cause_typed_damage(object targ, string limb, int damage, string type)
{
    object attacker;

    if(!objectp(attacker = targ->query_property("beingDamagedBy")))
        attacker = previous_object();
    
    if(!objectp(attacker) || !objectp(targ))
        return 0;
    
    if(attacker == targ) //if it's me doing something to myself, let it pass through (healing myself)
        return targ->cause_typed_damage(targ, limb, damage, type);
    
    if(!objectp(sphered) || targ != sphered)
        return targ->cause_typed_damage(targ, limb, damage, type);
    
    tell_room(environment(targ), "%^CYAN%^BOLD%^The sphere shimmers as it nullifies the damage.%^RESET%^");
    attacker->remove_attacker(targ);
    targ->remove_attacker(attacker);
    
    return 0;      
}

int start_shadow(object ob)
{
  sphered = ob;
  return shadow(sphered,1);
}

int end_shadow()
{
  unshadow();
  destruct(this_object());

}