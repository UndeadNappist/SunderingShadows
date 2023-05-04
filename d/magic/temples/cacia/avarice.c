// Chernobog (4/28/23)
// Temple of Cacia - Avarice
// Written by Branwen

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("fortune");
    set_short("%^C092%^The Temptation of Fortune, Cacia's Temple%^CRST%^");
    set_long("%^C092%^As you step into the small chamber, you are greeted by a dazzling display of %^C091%^extravagance%^C092%^. Illuminating the space, %^C220%^s%^C221%^p%^C227%^a%^C228%^r%^C229%^k%^C228%^l%^C227%^i%^C221%^n%^C220%^g c%^C221%^h%^C227%^a%^C228%^n%^C229%^del%^C228%^i%^C227%^e%^C221%^r%^C220%^s%^C092%^ cast light on %^C250%^gl%^C255%^it%^C250%^te%^C245%^ri%^C250%^ng %^C250%^m%^C255%^i%^C250%^r%^C245%^r%^C250%^o%^C255%^r%^C250%^s%^C092%^ that reflect and amplify its radiance. The walls are adorned with %^C074%^b%^C075%^r%^C111%^e%^C110%^a%^C074%^t%^C068%^h%^C069%^t%^C105%^a%^C104%^k%^C068%^i%^C062%^n%^C063%^g %^C099%^p%^C105%^a%^C069%^i%^C068%^n%^C074%^t%^C110%^i%^C111%^n%^C075%^g%^C074%^s%^C092%^ and %^C074%^s%^C075%^c%^C111%^u%^C110%^l%^C074%^p%^C068%^t%^C069%^u%^C105%^r%^C104%^e%^C067%^s%^C092%^, accompanied by %^C126%^r%^C127%^i%^C128%^c%^C129%^h %^C135%^t%^C134%^a%^C133%^p%^C132%^e%^C126%^s%^C127%^t%^C128%^r%^C129%^i%^C135%^e%^C134%^s%^C092%^ crafted from the %^C126%^f%^C127%^i%^C128%^n%^C129%^e%^C135%^s%^C134%^t %^C133%^s%^C132%^i%^C126%^l%^C127%^k%^C128%^s%^C092%^, and the floor is covered in a %^C220%^s%^C221%^h%^C227%^i%^C228%^m%^C229%^m%^C228%^e%^C227%^r%^C221%^i%^C220%^n%^C221%^g %^C227%^c%^C228%^a%^C229%^r%^C228%^p%^C227%^e%^C221%^t%^C092%^ of %^C221%^c%^C220%^o%^C221%^i%^C227%^n%^C228%^s%^C092%^ that rustle and shine beneath your feet, adding an additional layer of opulence. In the center of the room, a %^C220%^m%^C221%^a%^C227%^g%^C228%^n%^C229%^i%^C228%^f%^C227%^i%^C221%^c%^C220%^e%^C221%^n%^C227%^t %^C228%^t%^C229%^h%^C230%^r%^C229%^o%^C228%^n%^C227%^e%^C092%^ stands on a raised platform, commanding %^C091%^reverence%^C092%^ and %^C091%^awe%^C092%^. Lining the perimeter, %^C250%^o%^C255%^r%^C250%^n%^C245%^a%^C250%^t%^C255%^e %^C250%^m%^C245%^i%^C250%^r%^C255%^r%^C250%^o%^C245%^r%^C250%^s%^C092%^ display your %^C099%^reflection%^C092%^ from every angle. Is it possible your image appears to be more perfect than your memory recalls? The reflection calls to you, an image without flaw or peer...%^CRST%^\n");
    set_smell("default", "%^C110%^The air is thick with the %^C074%^heady scent%^C110%^ of %^C146%^exotic perfumes%^C110%^ and %^C146%^rich incense%^C110%^.%^CRST%^");
    set_listen("default", "%^C230%^A %^C229%^s%^C228%^u%^C227%^bt%^C228%^l%^C229%^e%^C230%^, %^C229%^so%^C228%^o%^C227%^t%^C228%^hi%^C229%^ng %^C228%^ch%^C227%^i%^C228%^me%^C230%^ resonates from the %^C228%^coins%^C230%^ that litter the floor beneath your feet.%^CRST%^");
    set_items(([
		({ "tapestries", "paintings", "sculptures" }) : "%^C127%^The %^C163%^grandiose paintings%^C127%^ and %^C126%^intricate sculptures%^C127%^ depict %^C126%^powerful figures%^C127%^ adorned in %^C126%^lavish clothing%^C127%^ and %^C126%^jewelry%^C127%^, while the %^C163%^luxurious tapestries%^C127%^ showcase scenes of %^C227%^opulence%^C127%^ and %^C227%^wealth%^C127%^. The art creates an overwhelming impression of the importance of material possessions and control over others. The message is clear: %^C140%^Those who control the wealth control the world%^C127%^.",
		"chandeliers" : "%^C220%^Each chandelier is an intricate work of art, crafted from the finest materials and adorned with hundreds of %^C227%^gl%^C228%^it%^C229%^te%^C230%^ri%^C231%^ng %^C227%^c%^C228%^r%^C229%^y%^C230%^s%^C231%^ta%^C230%^l%^C229%^s%^C220%^ that catch the light from every angle.%^CRST%^",
        "throne" : "%^C220%^The throne in the center of the room is a masterpiece of design and craftsmanship. It sits on a raised platform, made of the finest materials with %^C135%^ornate carvings%^C220%^ and %^C135%^gilded accents%^C220%^ that catch the light. The seat is adorned with %^C201%^sumptuous velvet cushions%^C220%^, while the back of the throne is tall and imposing, with intricate designs that evoke authority and power. The armrests are adorned with %^C135%^delicate carvings%^C220%^ and %^C135%^precious gems%^C220%^.%^CRST%^",
        ({ "coins", "gems", "riches", "carpet" }) : "%^C220%^The floor is a %^C227%^shimmering carpet%^C220%^ of %^C227%^coins%^C220%^, %^C197%^gems%^C220%^, and other %^C092%^precious items%^C220%^, each shining with a lustrous glow%^C220%^ that catches the light. The gems come in a variety of colors, from %^C019%^deep blues%^C220%^ and %^C037%^greens%^C220%^ to %^C196%^fiery reds%^C220%^ and %^C208%^oranges%^C220%^, and they glitter and shine like stars, begging you to gather them up. Among them are %^C227%^intricately crafted jewelry%^C220%^ and %^C127%^ornate trinkets%^C220%^, creating an atmosphere of excess and luxury.%^CRST%^",
		({ "mirror", "mirrors" }) : "%^C255%^Intricately framed mirrors line the perimeter of the room, each one displaying your reflection from every angle. The mirrors are of the highest quality, with ornate frames made of %^C220%^gilded gold%^C255%^ and %^C245%^intricate carvings%^C255%^ that catch the light and add to the room's grandeur. As you gaze into the mirrors, you can't help but notice how they seem to enhance your appearance, making you look more %^C147%^perfect%^C255%^ than you remember. The effect is almost magical, and it's easy to get lost in the endless reflections.%^CRST%^",
        ]));
    set_exits(([
        "out" : "/d/magic/temples/cacia/cacia",
        ]));
}

void init(){
    ::init();
    add_action("gather_fun", "gather");
}

int gather_fun(string str){
    object player = this_player();
    
    if(!str || (str != "coins" && str != "gems")){
        tell_object(player, "%^C220%^The %^C227%^coins %^C220%^and %^C197%^gems %^C220%^at your feet beckon to you.%^CRST%^");
        return 0;
    }
    
    switch(str){
        case "coins":
            str = "%^C227%^"+str;
            break;
        case "gems":
            str = "%^C197%^"+str;
            break;
    }
    tell_object(player, "%^C125%^As you try to gather and claim the "+str+"%^C125%^, they seem to slip free of your grasp at every motion, spilling back to the floor just as quickly.%^CRST%^");
    tell_room(environment(player), "%^C125%^Frustration seems to color "+player->query_cap_name()+"%^C125%^'s expression as they grasp for something on the floor.%^CRST%^", player);
    return 1;
}

