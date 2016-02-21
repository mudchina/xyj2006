 
inherit NPC;
 
void create()
{
	set_name("¼à¹Ù", ({"jian guan","guan"})); 
        set("gender", "ÄÐÐÔ" );
	set("long", "ÓùÂí¼à¼à¹Ù¡£\n");
        set("age",20);
	set("title", "ÓùÂí¼à");
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 4000);
  set("daoxing", 4000);

	set("max_kee", 300);
	set("max_sen", 300);
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 

ÿ