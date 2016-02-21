//Cracked by Roath
// zhangchan.c ÕÆìøÉ®
// By Dream Dec. 20, 1996

inherit NPC;

string ask_staff(object who);
string ask_spear(object who);

void create()
{
	set_name("ÕÆìøÉ®", ({ "zhangchan seng", "seng" }));
	set("gender", "ÄĞĞÔ");
	set("age", 35);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 250);
	set("max_gin", 250);
	set("max_sen", 250);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 20);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 20);
	set("combat_exp", 10000);
	set("daoxing", 60000);

	set_skill("literate", 30);
	set_skill("spells", 10);
	set_skill("unarmed", 30);
	set_skill("jienan-zhi", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);
	set_skill("force", 30);
	set_skill("staff", 30);
	map_skill("unarmed", "jienan-zhi");

	set("inquiry", ([
		"±øÆ÷": "ÄãÏëÒªÊ²Ã´±øÆ÷£¿",
		"ÌúÕÈ": (: ask_staff :),
		"ÌúÇ¹": (: ask_spear :)
	]) );

	set("apply/staffno", 10);
	set("apply/spearno", 10);
        create_family("ÄÏº£ÆÕÍÓÉ½", 4, "µÜ×Ó");
	
	setup();
	carry_object("/obj/money/gold");
	carry_object("/d/nanhai/obj/sengpao")->wear();
}


string ask_staff(object me)
{
	object ob, who = this_player();
	int number;


	if (who->query("family/family_name") != "ÄÏº£ÆÕÍÓÉ½") 
		return RANK_D->query_respect(who) +"Óë±¾ÃÅºÁÎŞÔ¨Ô´£¬ÎªÊ²Ã´ÎÊÆğÕâ¸ö£¿\n";

	if (present("tie zhang", who)) return "ÄãÉíÉÏ²»ÊÇÒÑ¾­ÓĞÌúÕÈÁËÂğ£¬ÔõÃ´ÓÖÀ´Òª£¿\n";

	if (!(number = me->query("apply/staffno"))) return "¶Ô²»Æğ£¬±øÆ÷ÒÑ¾­È«²¿·¢·Å³öÈ¥ÁË¡£\n";
	set("apply/staffno", --number);

	ob = new("/d/nanhai/obj/tiezhang");
	ob -> move(me);
	command("give " + who->query("id") + " staff");
	return "Ç§Íò¼Ç×¡£¬±øÆ÷Ö»¿ÉÓÃÀ´·ÀÉí£¬²»¿ÉÀÄÉ±ÎŞ¹¼¡£";
}

string ask_spear(object me)
{
        object ob, who = this_player();
        int number;

        if (who->query("family/family_name") != "ÄÏº£ÆÕÍÓÉ½")
		return RANK_D->query_respect(who) +"Óë±¾ÃÅºÁÎŞÔ¨Ô´£¬ÎªÊ²Ã´ÎÊÆğÕâ¸ö£¿\n";

	if (present("iron spear", who)) return "ÄãÉíÉÏ²»ÊÇÒÑ¾­ÓĞÌúÇ¹ÁËÂğ£¬ÔõÃ´ÓÖÀ´Òª£¿\n";

	if (!(number = me->query("apply/spearno"))) return "¶Ô²»Æğ£¬±øÆ÷ÒÑ¾­È«²¿·¢·Å³öÈ¥ÁË¡£\n";
	set("apply/spearno", --number);

	ob = new("/d/nanhai/obj/tieqiang");
	ob -> move(me);
	command("give " + who->query("id") + " spear");
	return "Ç§Íò¼Ç×¡£¬±øÆ÷Ö»¿ÉÓÃÀ´·ÀÉí£¬²»¿ÉÀÄÉ±ÎŞ¹¼¡£";
}

ÿ
