 
inherit NPC;
 
void create()
{
	set_name("¼à¸±", ({"jian fu","fu"})); 
        set("gender", "ÄÐÐÔ" );
	set("long", "ÓùÂí¼à¼à¸±¡£\n");
        set("age",40);
	set("title", "ÓùÂí¼à");
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 20500);
  set("daoxing", 20500);

	set("max_kee", 1000);
	set("max_sen", 1000);
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 

ÿ