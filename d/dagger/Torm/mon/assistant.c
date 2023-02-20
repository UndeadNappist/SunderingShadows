// Chernobog (1/17/23)
// Shalea
// Written by Gwenhwyfar

#include <std.h>  

inherit WEAPONLESS; 

void create(){ 
    object obj; 
    ::create(); 
    set_name("Shalea"); 
    set_id(({"shalea", "assistant", "Shalea"})); 
    set_short("%^RESET%^%^CRST%^%^C028%^Shalea, assistant%^CRST%^"); 
    set_long("%^RESET%^%^CRST%^%^C028%^Shalea is a young female human of average height and weight.  She has golden blonde hair pulled into a long pony tail. Her eyes are sparkling emerald green, and her skin is smooth and porcelain. She is often smiling warmly. Finally, she wears a pale blue country dress and sandals.%^CRST%^\n"); 
    set_race("human"); 
    set_body_type("human"); 
    set_alignment(5); 
    set_class("fighter"); 
    set_mlevel("fighter", 10); 
    set_gender("female"); 
    set_size(2); 
    set_hd(10,25); 
    set_hp(query_max_hp()); 
    set("aggressive", 2);
}

