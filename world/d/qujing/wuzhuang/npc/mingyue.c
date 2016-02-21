//Cracked by Roath
//mingyue.c

inherit NPC;

int max_tea = 20;
void create()
{
	set_name("Ã÷ÔÂ", ({"ming yue", "mingyue"}));
	set("gender", "ÄÐÐÔ" );
	set("age", 16);
	set("long", "Ò»¸öÌÖÈËÏ²»¶µÄÐ¡ÏÉÍ¯¡£\n");
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

	if ( ((int)ob->query("env/invisibility")  == 0) && ((string)environment(me)->query("short")=="¶«Æ«µî") )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( max_tea <= 0 || ob->query_temp("tea_given") == 1 ) return;

	if ( (int)ob->query("combat_exp")>500000 )
	{
		carry_object("/d/obj/food/xiangcha");
		command("give teapot to " + ob->query("id"));
		max_tea=max_tea-1;
		ob->set_temp("tea_given", 1);
	}
	else if ( (int)ob->query("combat_exp")>100000 )
	{
		carry_object("/d/obj/food/xiangcha");
		command("give teapot to " + ob->query("id"));
		max_tea=max_tea-1;
		ob->set_temp("tea_given", 1);
	}
	else if ( (int)ob->query("combat_exp")>10000 )
	{
		carry_object("/d/obj/food/chahu");
		command("give teapot to " + ob->query("id"));
		max_tea=max_tea-1;
		ob->set_temp("tea_given", 1);
	}
	else
		return;
}
ÿ