// monkey1.c

inherit NPC;

void create()
{
	set_name("ºï×Ó", ({ "hou zi","monkey","hou" }) );
	set("race", "Ò°ÊŞ");
	set("age", 8);
	set("long", "Ò»Ö»ÍçÆ¤µÄĞ¡ºï×Ó¡£\n");
	
	set("str", 30);
	set("cor", 26);	
	set("combat_exp", 50);
  set("daoxing", 0);

            set_skill("dodge",20);
            set_skill("unarmed",10);
	set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "ºó½Å", "Î²°Í" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 3);
	set("chat_msg", ({
                (: call_other, this_object(), "random_move" :),
		"Ğ¡ºï×Ó¸ßĞËµÃÖ±·­½î¶·¡£\n",
		"ºï×ÓÃÇ´ó½ĞµÀ£º£¢ÒªÊÇÄÜÔÚÕâÀï°²¼Ò¾ÍºÃÁË¡££¢\n",
		"ºï×ÓÃÇ½»Í·½Ó¶úµÀ£º¡°¾ÍÅÂÆäËûÀÇ³æ»¢±ªÀ´´Ë×÷ÂÒ¡£¡±\n"}) );
		

	setup();
}

ÿ