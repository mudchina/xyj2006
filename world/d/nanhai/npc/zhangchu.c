//Cracked by Roath
// zhangchu.c ÕÆ³øÉ®º
// By Dream Dec. 20, 1996

inherit NPC;

string *have_yao=({});
string *have_dan=({});

string ask_yao(object who);
string ask_dan(object who);

void create()
{
	set_name("ÕÆ³øÉ®", ({ "zhangchu seng", "seng" }));
	set("gender", "ÄĞĞÔ");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);
	set_skill("literate", 20);
	set_skill("unarmed", 25);
	set_skill("dodge", 20);
	set_skill("parry", 25);
	set_skill("force", 10);
	set_skill("spells", 10);
	set_skill("buddhism", 10);
	set_skill("unarmed", 30);
	map_skill("spells", "buddhism");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

	set("inquiry", ([
		"ÔÆÄÏ°×Ò©": (: ask_yao :),
		"Áéµ¤": (: ask_dan :),
	]) );
        set("apply/yaono", 10);
        set("apply/danno", 10);

        create_family("ÄÏº£ÆÕÍÓÉ½", 4, "µÜ×Ó");
	
	setup();
	add_money("silver", 20);
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

string ask_yao(object me)
{
	object ob, who = this_player();
	int number;

        if (who->query("family/family_name") != "ÄÏº£ÆÕÍÓÉ½") 
		return RANK_D->query_respect(who) +"Óë±¾ÃÅºÁÎŞÔ¨Ô´£¬ÎªÊ²Ã´ÎÊÆğÕâ¸ö£¿\n";

if (present("yunnan baiyao", who)) return "ÄãÉíÉÏ²»ÊÇÒÑ¾­ÓĞÔÆÄÏ°×Ò©ÁËÂğ£¬ÔõÃ´ÓÖÀ´Òª£¿\n";
	
	if (!(number = me->query("apply/yaono"))) return "¶Ô²»Æğ£¬ÔÆÄÏ°×Ò©ÒÑ¾­È«²¿·¢·Å³öÈ¥ÁË¡£\n";
	
	if(member_array(who->query("id"),have_yao)!=-1)
	    return "Äã²»ÊÇ¸Õ¸ÕÒª¹ıÂğ£¿\n";
	have_yao+=({who->query("id")});

	set("apply/yaono", --number);

	ob = new("/d/ourhome/obj/yunnandrug");
	ob -> move(me);
	command("give " + who->query("id") + " yunnan baiyao");
	return "ÔÆÄÏ°×Ò©µÃÖ®²»Ò×£¬Òª½ÚÔ¼×ÅÓÃ¡£\n";
}

string ask_dan(object me)
{
	object ob, who = this_player();
	int number;

	if (who->query("family/family_name") != "ÄÏº£ÆÕÍÓÉ½")
		return RANK_D->query_respect(who) +"Óë±¾ÃÅºÁÎŞÔ¨Ô´£¬ÎªÊ²Ã´ÎÊÆğÕâ¸ö£¿\n";

	if (present("lingdan", who)) return "ÄãÉíÉÏ²»ÊÇÒÑ¾­ÓĞÁéµ¤ÁËÂğ£¬ÔõÃ´ÓÖÀ´Òª£¿\n";

	if (!(number = me->query("apply/danno"))) return "¶Ô²»Æğ£¬Áéµ¤ÒÑ¾­È«²¿·¢·Å³öÈ¥ÁË¡£\n";

	if(member_array(who->query("id"),have_dan)!=-1)
	    return "Äã²»ÊÇ¸Õ¸ÕÒª¹ıÂğ£¿\n";
	have_dan+=({who->query("id")});

	set("apply/danno", --number);

	ob = new("/d/nanhai/obj/lingdan");
	ob -> move(me);
	command("give " + who->query("id") + " lingdan");
	return "Áéµ¤µÃÖ®²»Ò×£¬Òª½ÚÔ¼×ÅÓÃ¡£\n";
}

