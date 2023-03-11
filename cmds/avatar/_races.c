#include <std.h>
#define RACE_D "/adm/daemon/race_d.c"

#define MON_DIR "/std/races/monster_races"
#define USER_DIR "/std/races/"

int cmd_races(string str){
    string *race_list, *limb_list;
    object tmp;
    int i;
 
    race_list = get_dir(MON_DIR) + get_dir(USER_DIR);
    race_list = filter_array(race_list, (: !(catch(load_object(USER_DIR + $1)) && catch(load_object(MON_DIR + $1))) :) );
    race_list = filter_array(race_list, (: file_size(USER_DIR + $1) != -2 :));
    race_list = map(race_list, (: replace_string($1, ".c", "") :));
    
    if(!str)
    {
        printf("%s\n", implode(race_list, ", "));
        printf("\n\n   Use <races [racename]> to see valid limbs.\n");
        return 1;
    }
    
    if(member_array(str, race_list) < 0)
    {
        write("That is not a valid race.\n");
        return 1;
    }
    
    tmp = load_object(USER_DIR + str) || tmp = load_object(MON_DIR + str);
    limb_list = tmp->limbs();
    
    printf("%s\n", sizeof(limb_list) ? implode(limb_list, ", ") : "No limbs listed for that race");    
    
/*  
    tmp = "";
    if(str){
      if(!RACE_D->is_race(str)) return notify_fail("Not a valid race.\n");
      race_list = RACE_D->query_limbs(str);
    } else {
      //race_list = RACE_D->query_races();
    }
    for(i=0;i<sizeof(race_list);i++){
      tmp += race_list[i] + ",  ";
    }
    tmp += "\n\n   Use <races [racename]> to see valid limbs.\n";
    tmp += "Wizzes also see <mraces> for other valid body types for mobs.";
    TP->more(explode(tmp, "\n"));
*/
    return 1;
}

int help(){
    write(
      "Syntax: <races>  or <races [racename]>\n\n"
      "<races> alone will give you a list of all races on the mud you can use "
	"(plus some you can't at this time.) <races [racename]> where racename "
	"is a name from 'races' will give you all the limbs of that race, for "
	"use in armors and weapons.\n"
	"Wizzes - see also <mraces> for other body types available for mobs."
    );
    return 1;
}
