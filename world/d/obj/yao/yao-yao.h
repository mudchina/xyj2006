//lestat 2001
        
void create()
{
//    int i;
	mapping name;	
	name=NAME_D->random_name("yaoguai");
	set_name(name["name"], name["id"]);
//    set_name(guainame[i=random(sizeof(guainame)/2)*2],({guainame[i+1]}));
    set("age",20+random(80));
    set("attitude","heroism");
	set("chat_chance", 5);
 set("chat_msg", ({
      (: random_move :)
 }) );

 
    setup();
}
