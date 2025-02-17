#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("End of Sunset Way in Offestry");
   set_short("%^RESET%^%^GREEN%^End of Sunset Way in Offestry");
   set_long("%^RESET%^%^GREEN%^End of Sunset Way in Offestry%^RESET%^\n"
"You are standing on Sunset Way, which leads east back to the Offestry town square. The road ends here at an opening that allows passage beyond the town. The cobblestone %^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but "
"steady stream of %^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  The street is bordered on both "
"sides by a jumble of %^RED%^buildings%^RESET%^. To the north the closest of which is a tall %^BLUE%^stone tower%^RESET%^ with its doors open to welcome customers. "
"To the south the closest of which is the library with its doors open to welcome customers.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Sunset Way trails east, back towards the square which serves as the heart of this town.  It ends in an "
"opening in the palisade which surrounds the town to allow passage beyond its borders.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along both sides of the street.  Their age and vastly "
"varied styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearest is the "
"library and a tall stone tower.%^RESET%^",
   ]));
   set_exits(([
      "west":ROAD"froad8",
      "east":MAINTOWN"wstreet2",
      "north":MAINTOWN"mtower1",
      "south":MAINTOWN"library",
   ]));
   
   set_post_exit_functions( ({"west"}), ({"ready"}) );
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}

void ready(string str) 
{
    //if(!random(4))  return;
    if(!userp(TP)) return;
    if((int)TP->query_level() > 5) return;
    if( ((int)TP->query_hp()*100)/(int)TP->query_max_hp() < 90) 
    { 
        switch(TP->query_level()) 
        {
            case 0..2 :  
                tell_room(TP, "%^CYAN%^A concerned citizen points to your "
                "wounds and suggests that you should try to %^YELLOW%^<heal> "
                "%^RESET%^%^CYAN%^yourself.");
                break;
            case 3..5 :
                tell_room(TP, "%^YELLOW%^A concerned citizen points to "
                "your wounds and suggests you visit the healer for potions or training "
                "in healing.  %^CYAN%^(help skills)%^RESET%^.");
                break;
            default: 
                return;
                break;           
        }
        return;
    }
    if(sizeof(TP->query_wielded()) == 0) 
    {
        switch(TP->query_level()) 
        {
            case 0..3:  
                tell_room(TP, "%^YELLOW%^As you leave the protection of the city, "+
                "you realize it might be wise to wield your weapons and be prepared "+
                "for battle.%^RESET%^");
                break;
            default:
                return;
                break;
        }
        return;
    }
    return;
}