//lestat 2001
void create()
{
//    int i;
	mapping name;
	if(random(2)==1){	
	name=NAME_D->random_name("female");}
	else {
			name=NAME_D->random_name("male");
			}
	set_name(name["name"], name["id"]);
//    set_name(xianname[i=random(sizeof(xianname)/2)*2],({xianname[i+1]}));
    set("age",20+random(80));
    set("attitude","heroism");
	set("chat_chance", 5);
 set("chat_msg", ({
      (: random_move :)
 }) );

    setup();
}
