// monkey1.c

inherit NPC;

void create()
{
	set_name("Ğ¡ºï×Ó", ({ "xiao houzi","xiaohouzi","monkey","hou" }) );
	set("race", "Ò°ÊŞ");
	set("age", 6);
	set("long", "Ò»Ö»ÍçÆ¤µÄĞ¡ºï×Ó¡£\n");
	
	set("str", 30);
	set("cor", 26);	
	set("combat_exp", 50);
  set("daoxing", 0);

            set_skill("dodge",20);
            set_skill("unarmed",10);
	set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "ºó½Å", "Î²°Í" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: call_other, this_object(), "random_move" :),
		"Ğ¡ºï×Ó¶ÔÄã×öÁË¸ö¹íÁ³¡£\n",
		"Å¾µØÒ»Éù£¡Ğ¡ºï×ÓÈÓÀ´Ò»¿ÅÒ°¹û£¬ÕıºÃÔÒÖĞÄãµÄ±Ç×Ó¡£\n",
		"Ğ¡ºï×Ó¶ÔÄãÖ¨Ö¨Ö¨µØ½ĞÁË¼¸Éù¡£\n",
		"Ğ¡ºï×Ó×¥¶úÄÓÈùµØ£¬Î§×ÅÄãÌøÀ´ÌøÈ¥¡£\n" }) );
		
//	set_temp("apply/attack", 20);
//	set_temp("apply/defense", 50);
//	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("mihou tao")||ob->id("huasheng")||ob->id("jiudai")) {
		set_leader(who);
		who->set("pending/haha", 5);
		message("vision", name() + "¸ßĞËµÃ×¥¶úÄÓÈù£¬Ö±·­¸úÍ·¡£\n", environment());
		return 1;
	}
}
void init()
{
        add_action("do_let", "let");
}

int do_let(string arg)
{
        if( !this_player()->query("pending/haha") ) 
        return notify_fail("Ğ¡ºï×Ó¿ÚÖĞÎØÎØÁ½Éù£¬ºÃÏñ²»Ô¸ÀíÄã£¡\n");
	
	if(!arg )
	return notify_fail("Ğ¡ºï×ÓºÃÏó²»¶®ÄãËµÊ²Ã´£¡\n");

	message_vision("$N¶Ô$n×öÁË¸öÊÖÊÆ¡£\n", this_player(), this_object());
	command("bite");
	command("bite none");
	this_player()->add("pending/haha", -1);
	return 1;
}
ÿ