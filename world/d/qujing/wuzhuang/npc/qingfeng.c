//Cracked by Roath
//qingfeng.c

inherit NPC;
void create()
{
	set_name("Çå·ç", ({"qing feng", "qingfeng"}));
	set("gender", "ÄÐÐÔ" );
	set("age", 16);
	set("long", "Ò»¸ö»úÁéµÄÐ¡ÏÉÍ¯£¬ÔÚÎå×¯¹ÛÉÏÏÂºÜÊÇ³ÔµÃ¿ª¡£\n");
	set("class", "xian");
	set("combat_exp", 10000);
  set("daoxing", 20000);

	set("attitude", "peaceful");
	set("title", "Ð¡ÏÉÍ¯");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	set("per", 20);
	set("max_kee", 200);
	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
}

void init()
{       
	object ob=this_player();
	object me=this_object();

	::init();

	if ( ((int)ob->query("env/invisibility")  == 0) && ((string)environment(me)->query("short")=="Õýµî") )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if ( (int)ob->query("combat_exp")>500000 )
		command("say ÕâÎ»" + RANK_D->query_respect(ob) + "Ê§Ó­ÁË£¬¿ìÇëÉÏ×ø£¡Çëµ½¶«µîÓÃÏã²è£¡\n");
	else if ( (int)ob->query("combat_exp")>100000 )
		command("say ÕâÎ»" + RANK_D->query_respect(ob) + "Ê§Ó­ÁË£¬¿ìÇë×ø£¡Çëµ½¶«µîÓÃ²è£¡\n");
	else if ( (int)ob->query("combat_exp")>10000 )
		command("say ÕâÎ»" + RANK_D->query_respect(ob) + "£¬Çë×ø£¡ÓÃ²è£¡\n");
	else if ( (int)ob->query("combat_exp")>1000 )
		command("hi " + ob->query("id"));	
	else
		return;
}
ÿ