// monkey1.c

inherit NPC;

void create()
{
	set_name("´óÂíºï", ({ "mahou","monkey","hou" }) );
	set("race", "Ò°ÊŞ");
	set("age", 26);
	set("long", "Ò»Ö»´óÂíºï¡£\n");
	
	set("str", 35);
	set("cor", 26);	
	set("combat_exp", 5000);
  set("daoxing", 2000);

  

            set_skill("dodge",40);
            set_skill("unarmed",30);
	set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "ºó½Å", "Î²°Í" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: call_other, this_object(), "random_move" :),
		"´óÂíºï¶ÔÄã×öÁË¸ö¹íÁ³¡£\n",
		"Å¾µØÒ»Éù£¡´óÂíºïÈÓÀ´Ò»¿ÅÒ°¹û£¬ÕıºÃÔÒÖĞÄãµÄ±Ç×Ó¡£\n",
		"´óÂíºï¶ÔÄãÖ¨Ö¨Ö¨µØ½ĞÁË¼¸Éù¡£\n",
		"´óÂíºï×¥¶úÄÓÈùµØ£¬Î§×ÅÄãÌøÀ´ÌøÈ¥¡£\n" }) );
		
//	set_temp("apply/attack", 20);
//	set_temp("apply/defense", 50);
//	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("mihou tao")||ob->id("huasheng")||ob->id("jiudai")) {
		set_leader(who);
		message("vision", name() + "¸ßĞËµÃ×¥¶úÄÓÈù£¬Ö±·­¸úÍ·¡£\n", environment());
		return 1;
	}
}
ÿÿ