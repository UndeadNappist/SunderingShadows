///////////////////////////////////////////////////
//
// misc_funcs.c
//
// Mainly functions taken from daemons and made
// into simul_efuns.
//
// -- Tlaloc --
//
///////////////////////////////////////////////////

int query_stat_bonus(object who, string stat)
{
    if(!objectp(who) || !stringp(stat))
        return 0;
    
    return ((who->query_stats(stat) - 10) / 2);
}