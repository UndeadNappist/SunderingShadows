
// nethess.c

#include <std.h>
inherit NPC;
string *menu_items;

mapping menu;


void set_menu(string *item_names, string *types, int *strengths);
void set_my_mess(string *msg);
void set_your_mess(string *msg);
void set_empty_container(string *empty);
void set_menu_short(string *str);
void set_menu_long(string *str);
string *query_menu();

void create(){
    object obj;
    ::create();
    set_name("nethess");
    set_id( ({ "nethess", "bartender", "marilith", "waiter", "server" }) );
    set_short("%^RESET%^%^CRST%^%^C046%^N%^C047%^e%^C048%^t%^C049%^h%^C048%^e%^C047%^s%^C046%^s%^RESET%^%^C072%^, the %^RESET%^%^C028%^marilith%^CRST%^");
    set_level(30);
    set_long("%^CRST%^%^RESET%^%^C072%^Looming behind the %^RESET%^%^C241%^bar %^C072%^is this terrifyingly beautiful %^C028%^marilith%^RESET%^%^C072%^, her %^C094%^bronzed torso %^RESET%^%^C072%^that of an %^RESET%^%^C052%^a%^C088%^l%^C124%^l%^C160%^u%^C196%^r%^C124%^i%^C088%^n%^C052%^g %^RESET%^%^C072%^humanoid woman, while her lower half is that of a giant snake with %^RESET%^%^C046%^g%^C047%^l%^C048%^o%^C049%^s%^C048%^s%^RESET%^%^C046%^y e%^RESET%^%^C047%^m%^C048%^e%^C049%^r%^C048%^a%^C047%^l%^RESET%^%^C046%^d s%^C047%^c%^C048%^a%^C049%^l%^C048%^e%^C046%^s%^RESET%^%^C072%^. She has finely %^C022%^arched brows %^RESET%^%^C072%^that accentuate eyes like %^RESET%^%^C241%^b%^C052%^u%^C088%^r%^C124%^n%^C088%^i%^C052%^n%^RESET%^%^C241%^g c%^RESET%^%^C088%^o%^C124%^a%^C160%^l%^C241%^s%^RESET%^%^C072%^, the sclera %^C241%^black %^C072%^and her slitted %^RESET%^%^C241%^pupils %^C072%^a %^C088%^f%^C124%^i%^C160%^e%^C196%^r%^C160%^y %^RESET%^%^C124%^c%^C088%^r%^C124%^i%^C160%^m%^C196%^s%^C160%^o%^C088%^n%^RESET%^%^C072%^. Curved, ram-like %^RESET%^%^C241%^horns %^RESET%^%^C072%^crown her head and she has long, %^C022%^d%^C028%^a%^C034%^r%^RESET%^%^C022%^k g%^C028%^r%^C034%^e%^C028%^e%^RESET%^%^C022%^n h%^C028%^a%^C034%^i%^C022%^r %^RESET%^%^C072%^that has been left to fall in %^RESET%^%^C022%^w%^C028%^a%^C034%^v%^C028%^e%^RESET%^%^C022%^s %^RESET%^%^C072%^that barely conceal her %^C094%^full breasts%^C072%^, which she has not bothered to cover with any form of clothing. The muscles of her %^C094%^abdomen %^RESET%^%^C072%^are well-defined and she has six powerfully built arms, which normally make her kind %^C088%^d%^C124%^e%^C160%^a%^C196%^d%^C124%^l%^RESET%^%^C088%^y %^C072%^in battle, but are instead busy efficiently crafting %^C046%^e%^C048%^x%^C050%^o%^C051%^t%^C048%^i%^C046%^c%^RESET%^%^C072%^-looking %^C156%^cocktails %^RESET%^%^C072%^and pouring %^C136%^beers %^RESET%^%^C072%^as well as fine %^C052%^wines%^C072%^. The %^C057%^b%^C056%^e%^C055%^j%^C054%^e%^C053%^w%^C054%^e%^C055%^l%^C056%^e%^RESET%^%^C057%^d %^C094%^b%^C136%^a%^C220%^n%^C226%^g%^C220%^l%^C136%^e%^RESET%^%^C094%^s %^RESET%^%^C072%^she wears on her wrists %^C245%^j%^C250%^i%^C255%^ng%^C245%^l%^RESET%^%^C250%^e %^RESET%^%^C072%^as she works, and despite her %^C241%^intimidating stature%^RESET%^%^C072%^, the patrons fawn over her as she prepares their drinks.%^CRST%^ ");
    set_gender("female");
    set_exp(20);
    set_alignment(8);
    set_race("demon");
    set_hd(10,0);
    set_hp(356);
    set_max_hp(query_hp());
    add_money("gold", random(1000));
    set_body_type("demon");
    set_menu(
        ({ "food for thought", "bounty of the deep", "finger lichen good", "wrong or rothe", "rolling in the deep", "spiderkisser surprise", "bloody good pudding", "crunchy cave delight", "eye of the beholder", "simple and clean","bazi tea", "black wine", "mother's milk", "deep abyssal ale", "drow azure wine", "spiderblood" }),
        ({ "food", "food", "food", "food", "food", "food", "food", "food", "food", "water", "soft drink", "soft drink", "soft drink", "alcoholic", "alcoholic", "alcoholic" }),
        ({15,15,15,30,45,45,30,30,45,15,15,15,15,15,15,15})
        );
    set_my_mess(({
       "%^RESET%^%^CRST%^%^C144%^You dip a piece of %^C130%^fried tentacle %^RESET%^%^C144%^in the %^C197%^s%^C198%^w%^C199%^e%^C200%^e%^C201%^t s%^C200%^a%^C199%^u%^C198%^c%^C197%^e %^RESET%^%^C144%^and pop it in your mouth. The batter is %^C088%^s%^C124%^p%^C160%^i%^C124%^c%^C160%^e%^C088%^d %^RESET%^%^C144%^with Sse giving it delightful %^C160%^heat %^RESET%^%^C144%^and the tentacles are cooked to perfection, %^C214%^m%^C220%^e%^C221%^l%^C226%^t%^C227%^i%^C228%^n%^C229%^g %^RESET%^%^C144%^in your mouth.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^You pile a piece of %^C130%^bread %^RESET%^%^C144%^with sliced rothe %^C214%^c%^C220%^h%^C226%^ee%^C220%^s%^C214%^e %^RESET%^%^C144%^and %^C249%^m%^C250%^u%^C251%^s%^C252%^h%^C253%^r%^C252%^o%^C251%^o%^C250%^m%^C249%^s %^RESET%^%^C144%^then mop up the %^RESET%^%^C094%^Oob'%^RESET%^%^C144%^. The combination tantalizes your taste buds!%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^You dig into the %^RESET%^%^C022%^salad%^RESET%^%^C144%^. The tender %^C249%^m%^C250%^u%^C251%^s%^C252%^h%^C253%^r%^C252%^o%^C251%^o%^C250%^m%^C249%^s %^RESET%^%^C144%^and %^C047%^s%^C048%^p%^C049%^r%^C050%^i%^C051%^n%^C050%^g%^C049%^y %^C048%^l%^C047%^i%^C046%^c%^C047%^h%^C048%^e%^C049%^n %^RESET%^%^C144%^create a delightful blend of textures and flavors.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^The %^RESET%^%^C088%^m%^C124%^e%^C160%^a%^C088%^t %^RESET%^%^C144%^falls off the %^RESET%^%^C244%^bone %^C144%^and melts in your mouth. The %^C196%^t%^C202%^a%^C208%^n%^C202%^g%^C196%^y s%^C202%^a%^C208%^u%^C202%^c%^C196%^e %^RESET%^%^C144%^leaves your fingers sticky.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^You pick up the %^C241%^wooden sticks %^RESET%^%^C144%^meant to serve as utensils, balance one of the %^RESET%^%^C202%^c%^C203%^o%^C204%^l%^C167%^o%^C168%^r%^C167%^f%^C204%^u%^C203%^l %^C202%^r%^C203%^o%^C204%^l%^C167%^l%^C168%^s %^RESET%^%^C144%^between them, and pop it in your mouth. Scrumptious!%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^You dig in, careful not to break the %^C250%^eggs %^RESET%^%^C144%^with the spoon. Surprisingly, the %^C167%^s%^C168%^p%^C174%^i%^C175%^d%^C174%^e%^C168%^r %^C167%^p%^C168%^a%^C174%^t%^C175%^e %^RESET%^%^C144%^tastes a bit %^C205%^s%^C206%^w%^C207%^e%^C206%^e%^C205%^t%^RESET%^%^C144%^, and the eggs that burst in your mouth lend a slightly %^RESET%^%^C094%^earthen%^C144%^, %^C249%^m%^C250%^e%^C251%^t%^C252%^a%^C251%^l%^C250%^l%^C249%^i%^C250%^c %^RESET%^%^C144%^note.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^You try a piece of the %^C052%^cake%^RESET%^%^C144%^. It has a %^C088%^t%^C124%^a%^C160%^n%^C124%^g%^C088%^y%^RESET%^%^C144%^, %^C249%^m%^C250%^e%^C251%^t%^C252%^a%^C251%^l%^C250%^l%^C249%^i%^C250%^c %^RESET%^%^C144%^taste.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^You enjoy a spoonful of the %^RESET%^%^C230%^ice cream %^RESET%^%^C144%^and %^RESET%^%^C130%^caramelized crunchy topping%^RESET%^%^C144%^. Just the right combination of %^C207%^s%^C213%^w%^C219%^e%^C213%^e%^C207%^t %^RESET%^%^C144%^and %^C015%^salty%^RESET%^%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^You squeeze one of the tart %^RESET%^%^C129%^B%^C135%^e%^C141%^h%^C147%^ol%^C141%^d%^C135%^e%^C129%^r e%^C135%^y%^C141%^e%^C129%^s %^RESET%^%^C144%^between your teeth until it %^C129%^pops %^RESET%^%^C144%^and releases its %^C230%^jelly%^RESET%^%^C144%^. Here's looking at you.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^You sip at the glass of %^RESET%^%^C051%^c%^C087%^o%^C123%^o%^C159%^l %^C195%^w%^C159%^a%^C123%^t%^C087%^e%^C051%^r%^RESET%^%^C101%^. Refreshing!%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^You carefully sip at the %^C250%^s%^C251%^t%^C252%^e%^C253%^am%^C252%^i%^C251%^n%^C250%^g %^RESET%^%^C094%^tea %^RESET%^%^C101%^and are surprised by how %^C207%^s%^C213%^w%^C219%^e%^C219%^e%^C213%^t %^RESET%^%^C101%^it is!%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^You pour some %^RESET%^%^C230%^rothe milk %^C101%^and %^RESET%^%^C015%^sugar %^C101%^into the %^RESET%^%^C094%^dark coffee %^C101%^and stir before taking a sip. Still a bit bitter but you can already feel its effects as your %^C240%^pupils %^RESET%^%^C101%^dilate and your %^RESET%^%^C088%^p%^C124%^u%^C160%^l%^C196%^s%^C160%^e %^C124%^r%^C088%^a%^C124%^c%^C160%^e%^C196%^s%^RESET%^%^C101%^!%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^You enjoy the rich warm %^RESET%^%^C230%^milk%^C101%^, immediately feeling more %^C039%^r%^C045%^e%^C051%^l%^C087%^a%^C051%^x%^C045%^e%^C039%^d%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^You take a swig of the %^RESET%^%^C240%^ale%^C101%^, your vision temporarily %^RESET%^%^C244%^darkening%^C101%^. You can taste notes of %^C052%^dried fig%^RESET%^%^C101%^, %^C241%^molasses%^RESET%^%^C101%^, and %^C053%^blackberry%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^You sip the tart %^C051%^a%^C087%^z%^C123%^u%^C159%^r%^C195%^e %^C159%^w%^C123%^i%^C087%^n%^C051%^e %^RESET%^%^C101%^and the room %^C252%^s%^C253%^p%^C254%^i%^C253%^n%^C252%^s %^RESET%^%^C101%^and colors %^C220%^b%^C221%^r%^C226%^i%^C227%^g%^C228%^h%^C227%^t%^C226%^e%^C220%^n%^RESET%^%^C101%^. You quickly down the rest of the %^RESET%^%^C051%^d%^C087%^r%^C123%^i%^C087%^n%^C051%^k %^RESET%^%^C101%^and immediately feel like having another!%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^You have heard this %^C247%^w%^C248%^i%^C249%^n%^C250%^e %^RESET%^%^C101%^is laced with %^C240%^spider venom%^RESET%^%^C101%^. Certainly just a rumor, but all the same, you sip it tentatively. The flavor is delightful.%^CRST%^\n",
        }));
    set_your_mess(({
       "%^RESET%^%^CRST%^%^C144%^dips a piece of %^RESET%^%^C130%^fried illithid tentacle %^RESET%^%^C144%^in %^RESET%^%^C201%^s%^C200%^a%^C199%^u%^C198%^c%^C197%^e %^RESET%^%^C144%^before eating it.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^piles a piece of %^RESET%^%^C130%^bread %^RESET%^%^C144%^with rothe %^C214%^c%^C220%^h%^C226%^ee%^C220%^s%^C214%^e %^RESET%^%^C144%^and %^RESET%^%^C249%^f%^C250%^u%^C251%^ng%^C249%^i %^RESET%^%^C144%^and wolfs it down.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^digs into the %^RESET%^%^C022%^salad%^C144%^, popping a forkful of %^C249%^m%^C250%^u%^C251%^s%^C252%^h%^C253%^r%^C252%^o%^C251%^o%^C250%^m %^RESET%^%^C144%^and %^RESET%^%^C048%^g%^C047%^l%^C046%^o%^C047%^w%^C048%^i%^C049%^n%^C048%^g %^RESET%^%^C048%^l%^C047%^i%^C046%^c%^C047%^h%^C048%^e%^C049%^n %^RESET%^%^C144%^into their mouth.%^RESET%^\n",
       "%^RESET%^%^CRST%^%^C144%^ravages a rack of succulent %^C088%^r%^C124%^i%^C160%^b%^RESET%^%^C088%^s%^RESET%^%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^expertly maneuvers a slender pair of %^RESET%^%^C241%^sticks %^RESET%^%^C144%^to pick up one of the %^C202%^r%^C203%^o%^C204%^l%^C167%^l%^C168%^s %^RESET%^%^C144%^of %^C202%^r%^C203%^a%^C204%^w %^RESET%^%^C167%^f%^C168%^i%^C204%^s%^C205%^h %^RESET%^%^C144%^and pop it into their mouth.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^dips their spoon into the %^C167%^s%^C168%^p%^C174%^i%^C175%^d%^C174%^e%^C168%^r %^C167%^p%^C168%^a%^C174%^t%^C175%^e%^RESET%^%^C144%^, a pile of tiny, pale %^RESET%^%^C253%^eggs %^RESET%^%^C144%^on top.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^enjoys a small %^RESET%^%^C094%^brown cake %^RESET%^%^C144%^with %^C052%^d%^C088%^a%^C124%^r%^C088%^k %^C052%^r%^C088%^e%^C124%^d %^C088%^l%^C052%^u%^C088%^m%^C124%^p%^C088%^s %^RESET%^%^C144%^baked within.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^enjoys a sweet and %^RESET%^%^C015%^salty treat %^RESET%^%^C144%^- %^RESET%^%^C230%^ice cream %^RESET%^%^C144%^topped with %^RESET%^%^C130%^caramelized %^RESET%^%^C241%^cave crickets %^RESET%^%^C144%^and %^RESET%^%^C136%^peanuts%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^bravely consumes one of the %^RESET%^%^C129%^B%^C135%^e%^C141%^h%^C147%^ol%^C141%^d%^C135%^e%^C129%^r e%^C135%^y%^C141%^e%^C129%^s%^RESET%^%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^sips at a glass of %^RESET%^%^C051%^c%^C087%^o%^C123%^o%^C159%^l %^C195%^w%^C159%^a%^C123%^t%^C087%^e%^C051%^r%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^sips a mug of piping %^C088%^h%^C124%^o%^C088%^t %^RESET%^%^C094%^tea%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^stirs some %^RESET%^%^C230%^milk %^C101%^and %^RESET%^%^C015%^sugar %^RESET%^%^C101%^into their %^RESET%^%^C241%^coffee %^C101%^but still makes a sour face after the first drink.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^enjoys a glass of thick, %^RESET%^%^C230%^warm milk%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^takes a swig from a tankard of %^RESET%^%^C241%^dark ale %^C101%^that seems to %^RESET%^%^C244%^dampen %^RESET%^%^C101%^the very %^C229%^l%^C230%^i%^C231%^g%^C230%^h%^C229%^t %^RESET%^%^C101%^around it.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^guzzles a glass of %^RESET%^%^C051%^g%^C087%^l%^C123%^o%^C159%^w%^C123%^i%^C087%^n%^C051%^g %^RESET%^%^C051%^a%^C087%^z%^C123%^u%^C159%^r%^C195%^e %^C159%^w%^C123%^i%^C087%^n%^C051%^e%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^swirls a glass of %^C247%^d%^C248%^u%^C249%^l%^C250%^l %^C249%^g%^C248%^r%^C247%^a%^C248%^y %^C249%^w%^C250%^i%^C249%^n%^C248%^e %^RESET%^%^C101%^and sniffs it suspiciously before taking a tentative sip.%^CRST%^\n",
        }));
    set_menu_short(({
        "%^RESET%^%^C240%^Food for %^RESET%^%^C039%^T%^C045%^h%^C051%^o%^C087%^u%^C051%^g%^C045%^h%^C039%^t%^CRST%^",
        "%^RESET%^%^C240%^Bounty of the %^RESET%^%^C024%^D%^C031%^e%^C038%^e%^C024%^p%^CRST%^",
        "%^RESET%^%^C240%^Finger %^RESET%^%^C048%^L%^C047%^i%^C046%^c%^C047%^h%^C048%^e%^C049%^n %^RESET%^%^C240%^Good%^CRST%^",
        "%^RESET%^%^C240%^Wrong or %^RESET%^C088%^R%^C124%^o%^C160%^t%^C124%^h%^C088%^e%^CRST%^",
        "%^RESET%^%^C240%^Rolling in the %^BLUE%^D%^CYAN%^e%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^p%^RESET%^",
        "%^RESET%^%^C021%^S%^C027%^p%^C033%^i%^C039%^d%^C045%^e%^C051%^r%^C045%^k%^C039%^i%^C033%^s%^C027%^s%^C021%^e%^C027%^r %^RESET%^%^C240%^Surprise%^CRST%^",
        "%^RESET%^%^C052%^B%^C088%^l%^C124%^oo%^C088%^d%^C052%^y %^RESET%^%^C240%^Good Pudding%^CRST%^",
        "%^RESET%^%^C094%^Cr%^C136%^unc%^C094%^hy %^RESET%^%^C240%^Cave Delight%^CRST%^",
        "%^RESET%^%^C240%^Eye of the %^RESET%^%^C129%^B%^C135%^e%^C141%^h%^C147%^ol%^C141%^d%^C135%^e%^C129%^r%^CRST%^",
        "%^RESET%^%^C240%^Simple and %^C051%^C%^C087%^l%^C123%^e%^C087%^a%^C051%^n%^CRST%^",
        "%^RESET%^%^C240%^Bazi %^RESET%^%^C094%^Tea%^CRST%^",
        "%^RESET%^%^C240%^Black W%^RESET%^%^C230%^i%^C240%^ne%^CRST%^",
        "%^RESET%^%^C240%^Mother's %^RESET%^%^C230%^M%^C231%^i%^C015%^l%^RESET%^%^C230%^k%^CRST%^",
        "%^RESET%^%^C240%^Deep %^C242%^A%^C243%^b%^C244%^y%^C245%^s%^C244%^s%^C243%^a%^C242%^l %^RESET%^%^C240%^Ale%^CRST%^",
        "%^RESET%^%^C240%^Drow %^RESET%^%^C051%^A%^C087%^z%^C123%^u%^C159%^r%^C195%^e %^RESET%^%^C240%^Wine%^CRST%^",
        "%^RESET%^%^C240%^Spider%^C088%^b%^C124%^l%^C160%^oo%^C124%^%^C088%^d%^CRST%^",
        }));
    set_menu_long(({
       "%^RESET%^%^CRST%^%^C144%^An %^RESET%^%^C241%^onyx platter %^RESET%^%^C144%^piled with %^RESET%^%^C094%^fried illithid tentacles %^RESET%^%^C144%^and served with a %^RESET%^%^C197%^s%^C198%^w%^C199%^e%^C200%^e%^C201%^t s%^C200%^a%^C199%^u%^C198%^c%^C197%^e%^RESET%^%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^A rectangular %^RESET%^%^C015%^porcelain plate %^RESET%^%^C144%^piled with sliced rothe %^RESET%^%^C214%^c%^C220%^h%^C226%^ee%^C220%^s%^C214%^e%^RESET%^%^C144%^, %^RESET%^%^C250%^f%^C249%^u%^C248%^n%^C249%^g%^C250%^i%^RESET%^%^C144%^, and %^RESET%^%^C094%^fresh bread, drizzled with %^RESET%^%^C094%^Oob'%^RESET%^%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^An %^RESET%^%^C241%^onyx bowl %^RESET%^%^C144%^filled with fresh %^RESET%^%^C250%^f%^C249%^u%^C248%^n%^C249%^g%^C250%^i %^RESET%^%^C144%^and crumbled rothe %^RESET%^%^C214%^c%^C220%^h%^C226%^ee%^C220%^s%^C214%^e%^RESET%^%^C144%^ on a bed of %^RESET%^%^C048%^g%^C047%^l%^C046%^o%^C047%^w%^C048%^i%^C049%^n%^C048%^g %^RESET%^%^C048%^l%^C047%^i%^C046%^c%^C047%^h%^C048%^e%^C049%^n%^RESET%^%^C144%^, drizzled with an %^RESET%^%^C094%^Oob' vinaigrette%^RESET%^%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^A round %^RESET%^%^C241%^onyx plate %^RESET%^%^C144%^holding half a rack of %^RESET%^%^C241%^smoked %^RESET%^%^C052%^r%^C088%^o%^C124%^t%^C088%^h%^C052%^e %^C088%^r%^C124%^i%^C088%^b%^C052%^s %^RESET%^%^C144%^resting on a bed of roasted %^RESET%^%^C022%^v%^C028%^e%^C040%^g%^C046%^e%^C082%^t%^C076%^a%^C070%^b%^C064%^l%^C058%^e%^C094%^s%^CRST%^.\n",
       "%^RESET%^%^CRST%^%^C144%^A long rectangular %^RESET%^%^C241%^onyx plate %^RESET%^%^C144%^adorned with rolls of exotic %^RESET%^%^C202%^r%^C203%^a%^C204%^w %^RESET%^%^C167%^f%^C168%^i%^C204%^s%^C205%^h %^RESET%^%^C144%^and %^RESET%^%^C040%^p%^C041%^i%^C042%^c%^C049%^k%^C042%^l%^C041%^e%^C040%^d %^RESET%^%^C048%^l%^C047%^i%^C046%^c%^C047%^h%^C048%^e%^C049%^n\n",
       "%^RESET%^%^CRST%^%^C144%^A %^RESET%^%^C015%^porcelain plate %^RESET%^%^C144%^with a large, %^RESET%^%^C021%^e%^C027%^l%^C033%^e%^C039%^c%^C045%^t%^C051%^r%^C045%^i%^C039%^c %^RESET%^%^C033%^b%^C027%^l%^C021%^u%^C027%^e %^RESET%^%^C033%^t%^C039%^a%^C045%^r%^C051%^a%^C045%^n%^C039%^t%^C033%^u%^C027%^l%^C021%^a %^RESET%^%^C144%^resting upon it. Its abdomen has been hollowed out and filled with a %^C167%^p%^C168%^a%^C174%^l%^C175%^e %^RESET%^%^C167%^p%^C168%^a%^C174%^t%^C175%^e%^RESET%^%^C144%^. On top of that is a mound of tiny, perfect spheres, %^C247%^m%^C248%^o%^C249%^t%^C250%^t%^C249%^l%^C248%^e%^C247%^d %^RESET%^%^C144%^in color.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^A small %^RESET%^%^C094%^brown cake %^RESET%^%^C144%^with lumps of %^RESET%^%^C052%^c%^C088%^l%^C124%^o%^C088%^t%^C052%^t%^C088%^e%^C124%^d %^RESET%^%^C088%^b%^C052%^l%^C088%^o%^C124%^o%^C088%^d %^RESET%^%^C144%^baked within.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^An %^RESET%^%^C241%^onyx bowl %^RESET%^%^C144%^holding two scoops of %^RESET%^%^C230%^vanilla ice cream %^RESET%^%^C144%^topped with %^RESET%^%^C130%^caramelized %^RESET%^%^C241%^cave crickets %^RESET%^%^C144%^and %^RESET%^%^C136%^peanuts%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C144%^A %^RESET%^%^C015%^porcelain bowl %^RESET%^%^C144%^filled with %^RESET%^%^C040%^p%^C041%^i%^C042%^c%^C049%^k%^C042%^l%^C041%^e%^C040%^d %^RESET%^%^C129%^B%^C135%^e%^C141%^h%^C147%^ol%^C141%^d%^C135%^e%^C129%^r e%^C135%^y%^C141%^e%^C129%^s%^RESET%^%^C144%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^A tall glass of %^RESET%^%^C051%^c%^C087%^o%^C123%^o%^C159%^l %^C195%^w%^C159%^a%^C123%^t%^C087%^e%^C051%^r%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^A mug of piping %^RESET%^%^C088%^h%^C124%^o%^C088%^t %^RESET%^%^C094%^tea%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^A mug of %^RESET%^%^C240%^inky black liquid %^RESET%^%^C101%^served with rothe %^RESET%^%^C230%^milk %^C101%^and %^RESET%^%^C015%^sugar%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^A tall glass of warm %^RESET%^%^C230%^rothe milk%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^A tankard of %^C241%^black ale %^RESET%^%^C101%^that seems to %^C244%^dampen %^RESET%^%^C101%^the very %^C229%^l%^C230%^i%^C231%^g%^C230%^h%^C229%^t %^RESET%^%^C101%^around it%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^A fluted %^RESET%^%^C195%^crystal glass %^C101%^of %^RESET%^%^C051%^g%^C087%^l%^C123%^o%^C159%^w%^C123%^i%^C087%^n%^C051%^g %^RESET%^%^C051%^a%^C087%^z%^C123%^u%^C159%^r%^C195%^e %^C159%^w%^C123%^i%^C087%^n%^C051%^e%^RESET%^%^C101%^.%^CRST%^\n",
       "%^RESET%^%^CRST%^%^C101%^A glass of %^C247%^d%^C248%^u%^C249%^l%^C250%^l %^C249%^g%^C248%^r%^C247%^a%^C248%^y %^C249%^w%^C250%^i%^C249%^n%^C248%^e %^RESET%^%^C101%^laced with veins of %^RESET%^%^C088%^c%^C124%^r%^C160%^i%^C196%^m%^C160%^s%^C124%^o%^C088%^n%^C101%^.%^CRST%^\n",
        }));
    set_emotes(2,({
        "%^RESET%^%^C036%^A %^RESET%^%^C094%^sl%^C136%^o%^C178%^p%^C136%^p%^C094%^y d%^C136%^r%^C178%^u%^C136%^n%^C094%^k %^RESET%^%^C036%^reaches over the %^RESET%^%^C241%^bar%^C036%^, trying to snatch a %^C159%^b%^C195%^o%^C123%^t%^C159%^t%^C195%^l%^C123%^e %^RESET%^%^C036%^of %^C214%^l%^C220%^i%^C221%^q%^C226%^u%^C221%^o%^C214%^r %^RESET%^%^C036%^from one of the %^C241%^shelves%^RESET%^%^C036%^. Quick as %^C226%^l%^C227%^i%^C228%^g%^C229%^h%^C230%^t%^C229%^n%^C228%^i%^C227%^n%^C226%^g%^RESET%^%^C036%^, the bartender whips him with her %^C046%^t%^C048%^a%^C050%^i%^C046%^l%^C036%^, sending him skidding across the %^RESET%^%^C241%^floor%^RESET%^%^C036%^, his face a %^C088%^b%^C124%^l%^C160%^o%^C196%^o%^C124%^d%^C088%^y m%^C124%^e%^C160%^s%^C088%^s%^RESET%^%^C036%^.%^CRST%^",
        "%^RESET%^%^C042%^Nethess gets a %^RESET%^%^C094%^bottle %^C042%^of %^C136%^beer %^RESET%^%^C042%^from beneath the %^RESET%^%^C241%^bar %^C042%^and presses the cap to the edge of one of her %^C241%^h%^C243%^o%^C245%^r%^C243%^n%^C241%^s%^RESET%^%^C042%^. With a swift jerk of her head, she sends the cap %^C045%^f%^C051%^l%^C087%^y%^C123%^i%^C051%^n%^C045%^g%^RESET%^%^C042%^. One of the men sitting at the end of the bar catches it, his companions %^RESET%^%^C161%^c%^C162%^h%^C163%^e%^C164%^e%^C165%^r%^C201%^i%^C200%^n%^C199%^g %^C198%^e%^C197%^n%^C161%^t%^C162%^h%^C163%^u%^C164%^s%^C165%^i%^C201%^a%^C200%^s%^C199%^t%^C198%^i%^C197%^c%^C161%^a%^C162%^l%^C163%^l%^C164%^y%^RESET%^%^C042%^.%^CRST%^",
        "%^CRST%^%^RESET%^%^C045%^\"%^C051%^You know my sister, Ssiress?%^C045%^\" %^C034%^Nethess asks one of the patrons. %^C045%^\"%^C051%^That bitch getsss to hand out popssiclesss at the carnival while I am ssstuck with you lot,%^C045%^\"%^RESET%^%^C034%^ she %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^C087%^e%^C051%^s %^RESET%^%^C034%^with a %^C022%^wry grin %^RESET%^%^C034%^that reveals her %^C231%^sharp fangs%^RESET%^%^C082%^.%^CRST%^",
        "%^RESET%^%^CRST%^%^C040%^The bartender's six arms are a %^C047%^b%^C048%^l%^C049%^u%^C050%^r %^RESET%^%^C040%^as she simultaneously mixes a %^C219%^c%^C225%^o%^C231%^ckta%^C225%^i%^C219%^l%^RESET%^%^C040%^, pours a %^RESET%^%^C136%^beer%^C040%^, and wipes down the %^RESET%^%^C241%^bar%^C040%^.%^RESET%^%^CRST%^",
        "%^RESET%^%^CRST%^%^C147%^The %^C255%^band %^RESET%^%^C147%^begins to play a %^C220%^l%^C226%^i%^C227%^ve%^C226%^l%^C220%^y t%^C226%^u%^C227%^n%^C220%^e %^RESET%^%^C147%^and several patrons make their way to the %^C241%^dance floor%^RESET%^%^C147%^.%^CRST%^",
        "%^CRST%^%^RESET%^%^C052%^W%^C088%^a%^C124%^n%^C160%^t%^C124%^o%^C088%^n %^C052%^m%^C088%^o%^C124%^a%^C160%^n%^C124%^s of %^C052%^p%^C088%^l%^C124%^e%^C160%^a%^C124%^s%^C088%^u%^C052%^r%^C088%^e %^RESET%^%^C124%^emanate from the %^RESET%^%^C241%^pit%^RESET%^%^C124%^.%^CRST%^",}), 0);
}

void init() {
    ::init();
    add_action("buy", "buy");
   add_action("buy","order");
}
void set_menu(string *item_names, string *types, int *strengths) {
    int i;

    menu_items = item_names;
    if(!menu) menu = ([]);
    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]] = ([ "type": types[i], "strength": strengths[i] ]);
    }
}
void set_my_mess(string *msg) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["my message"] = msg[i];
    }
}
void set_your_mess(string *msg) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {

        menu[menu_items[i]]["your message"] = msg[i];
    }
}
void set_empty_container(string *container) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["empty container"] = container[i];
    }
}

void set_menu_short(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["short"] = str[i];
    }
}
void set_menu_long(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["long"] = str[i];
    }
}

void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}
int buy(string str) {
    int i, cost;
    object ob;
    if(!str) {
        notify_fail(query_cap_name()+" says: What is it you would like?\n");
        return 0;
    }
    if(!should_interact(TP)){
       force_me("emote taps on the bar and shakes "+query_possessive()+" head in refusal.");
       force_me("say I will not serve you here");
       return 1;
    }
    str = lower_case(str);
    if(member_array(str, menu_items) == -1) {
        notify_fail(query_cap_name()+" says: I don't serve that.\n");
        return 0;
    }


   force_me("emote takes an order from "+TP->query_cap_name()+" and soon delivers it.");
    if(menu[str]["type"] == "food") {
        ob = new("std/food");
        ob->set_name(str);
        ob->set_id( ({str, "food" }) );
    ob->set_value(0);
    }
    else {
        ob = new("std/drink");
        ob->set_name(str);
        ob->set_type(menu[str]["type"]);
        ob->set_id( ({ str, "drink" }) );
    }
    ob->set_strength(menu[str]["strength"]);
    ob->set_weight(1);
    i = menu[str]["strength"];
   ob->set_value(0);
    ob->set_destroy();
    if(menu[str]["short"]) ob->set_short(menu[str]["short"]);
    else ob->set_short(capitalize(str));
    if(menu[str]["long"]) ob->set_long(menu[str]["long"]);
    else ob->set_long(capitalize(str) + " from
"+(string)environment(this_object())->query_short()+".\n");
    if(menu[str]["empty container"]) ob->set_empty_name(menu[str]["empty container"]);
    if(menu[str]["my message"]) ob->set_my_mess(menu[str]["my message"]);
    if(menu[str]["your message"]) ob->set_your_mess(menu[str]["your message"]);
    if(ob->move(this_player())) {
        write("You cannot carry it!\nYou drop a "+str+".\n");
        say(this_player()->query_cap_name()+" drops a "+str+".\n", this_player());
        ob->move(environment(this_player()));
    }
    return 1;
}
string *query_menu() { return menu_items; }
