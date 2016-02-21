inherit NPC;

void create()
{
        set_name("·¶ÇàÆÁ", ({"fan qingping", "fan"}));
        set("age", 72);
        set("gender", "ÄĞĞÔ");
        set("long",
"·¶ÀÏÈ­Ê¦×³ÄêÊ±Ò²ÊÇÏìµ±µ±µÄÓ¢ĞÛ£¬ÏÖÔÚËäÀÏÁË£¬ÊÖ½ÅÀûÂäÈ´²»Êäµ±Äê£®\n");
	set("title", "È­¸ÇÈıÊ¡");
        set("attitude", "friendly");
	set("max_kee", 800);
	set("max_sen", 700);
        set("combat_exp", 100000);
  set("daoxing", 50000);

        set("shen_type", 1);
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 15);
        set_skill("unarmed", 100);
	set_skill("changquan", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
	map_skill("unarmed", "changquan");
	set("chat_chance",1);
        set("chat_msg", ({
        "·¶ÇàÆÁÌ¾µÀ£ºÍÈ½Å²»ÀûÂäÁË£¬Ò²Ã»ÈËÈ¥¸øÎÒÌáÁıĞ¡¶şµÄ°ü×ÓÀ´¡£\n",
}));
	setup();
        carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/obj/book/quanjing");
}

int accept_object(object who,object ob)
{
        if (ob->query("id")=="zhurou bao"){
	command("say ºÙºÙ£¬ÀÏ¶şÕâ°ü×ÓÊÇÔ½×öÔ½Ğ¡ÁË¡£\n");
	command("say ²»¹ı»¹ÊÇÒªĞ»Ğ»ÄãÑ½£¡\n");
	command("give jing to " + who->query("id"));
	return 1;
	}
	return 0;
}


ÿ