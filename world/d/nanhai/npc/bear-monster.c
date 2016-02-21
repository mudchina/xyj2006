//Cracked by Roath
// bear-monster.c ºÚĞÜ¹Ö¡õ
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ºÚĞÜ¹Ö", ({ "bear monster", "bear", "monster" }));
	set("title", "ÄÏº£¹ÛÒôÖ®Í½");   
	set("long", @LONG
ºÚĞÜ¹Ö±¾ÊÇÉ½¼äÒ°ÊŞ£¬²»Öª´ÓÄÄÀïÑ§µ½Ò»ÉíºÃ±¾Áì¡£
ºóÓö¼ûÄÏº£¹ÛÒô£¬±»ÄÏº£¹ÛÒôÊÕÎªÍ½µÜ¡£
LONG);
	set("gender", "ÄĞĞÔ");
	set("age", 30);
	set("attitude", "heroism");
	set("per", 9);
	set("rank_info/self", "ºÚĞÜ");
	set("rank_info/rude", "ĞÜ¹Ö");
	set("max_kee", 850);
	set("max_gin", 800);
	set("max_sen", 850);
	set("force", 400);
	set("max_force", 500);
	set("force_factor", 50);
	set("max_mana", 250);
	set("mana", 300);
	set("mana_factor", 20);
	set("combat_exp", 30000);
	set("daoxing", 50000);

	set_skill("literate", 60);
	set_skill("spells", 60);
	set_skill("buddhism", 60);
	set_skill("unarmed", 80);
	set_skill("jienan-zhi", 80);
	set_skill("dodge", 80);
	set_skill("lotusmove", 80);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("lotusforce", 60);
	set_skill("staff", 80);
	set_skill("lunhui-zhang", 80);
//	set_skill("spear", 60);
//	set_skill("huoyun-qiang", 50);

	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	map_skill("spear", "huoyun-qiang");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :),
	}) );
        create_family("ÄÏº£ÆÕÍÓÉ½", 2, "µÜ×Ó");

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/d/nanhai/obj/jingu3");
//	carry_object("/d/nanhai/obj/jingu3");
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="ÄÏº£ÆÕÍÓÉ½") {
		command("smile");
		command("say ºÜºÃ£¬ÎÒ¾ÍÊÕÏÂÄã£¬Ï£ÍûÄã¶à¼ÓÅ¬Á¦£¬Ôç³ÉÕı¹û¡£\n");

		command("recruit " + ob->query("id") );
		return;
	}

	command("shake");
	command("say " + "ÆĞÈø²»ÈÃÎÒËæ±ãÊÕÍâÈËÎªÍ½¡£\n");
	return;
}

ÿ
