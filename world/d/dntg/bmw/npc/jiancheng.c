 
inherit NPC;
void create()
{
	set_name("¼àØ©", ({"jian cheng"})); 
        set("gender", "ÄÐÐÔ" );
	set("long", "ÓùÂí¼à¼àØ©¡£\n");
        set("age",40);
        set("str", 30);
	set("title", "ÓùÂí¼à");
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 8500);
  set("daoxing", 8500);

	set("max_kee", 1000);
	set("max_sen", 1000);

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 
ÿ