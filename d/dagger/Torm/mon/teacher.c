// Chernobog (1/17/23)
// Mrs. Radcliff
// Written by Gwenhwyfar

#include <std.h>  

inherit WEAPONLESS; 

void create(){ 
    object obj; 
    ::create(); 
    set_name("Mrs. Radcliff"); 
    set_id(({"radcliff", "teacher", "mrs radcliff", "Mrs Radcliff", "Mrs. Radcliff"})); 
    set_short("%^RESET%^%^CRST%^%^C028%^Mrs. Radcliff, teacher%^CRST%^"); 
    set_long("%^RESET%^%^CRST%^%^C028%^Mrs. Radcliffe is a petite middle-aged human female. She has greying brown hair pulled into a tight bun. She has wire rimmed eye glasses and pale blue eyes. Her skin is pale and beginning to show signs of age with fine lines and slightly sagging jowls. Her posture is ramrod straight. Her demeanor paradoxically imposing while her eyes convey warmth and kindness. She wears a white fluffy blouse, a full dark purple skirt, and brown flats. She is typically at the head of the classroom and a stick of chalk or book is often found in her hand.%^CRST%^\n"); 
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

