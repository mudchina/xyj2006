// honghaier.c ºìº¢¶ù
// By Dream Dec. 20, 1996
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ºìº¢¶ù", ({ "honghaier" }));
	set("title", "ÄÏº£¹ÛÒôÖ®Í½");   
	set("long", @LONG
Ëû±¾ÊÇÅ£Ä§ÍõÖ®×Ó£¬ÉúĞÔºÃ¶·£»ºó±»ÄÏº£¹ÛÒôÊÕ·ş£¬Æ¢ÆøÈ´²»¼ûÓĞÊ²Ã´ºÃ×ª¡£
ËûÊ¹µÃÒ»ÊÖµÄºÃÇ¹·¨£¬»ğÔÆÇ¹¸üÊÇÏÊÓĞµĞÊÖ£¬Ñ°³£ÈËÊÇ²»¸ÒÅöËûµÄ¡£
LONG);
	set("gender", "ÄĞĞÔ");
	set("age", 15);
	set("attitude", "heroism");
	set("max_kee", 750);
	set("max_gin", 600);
	set("max_sen", 750);
	set("force", 450);
	set("max_force", 300);
	set("force_factor", 20);
	set("max_mana", 350);
	set("mana", 500);
	set("mana_factor", 50);
	set("combat_exp", 240000);
	set("daoxing", 400000);

	set_skill("literate", 80);
	set_skill("spells", 100);
	set_skill("buddhism", 100);
	set_skill("unarmed", 60);
	set_skill("jienan-zhi", 60);
	set_skill("dodge", 80);
	set_skill("lotusmove", 80);
	set_skill("parry", 80);
	set_skill("force", 80);
	set_skill("lotusforce", 70);
	set_skill("staff", 50);
	set_skill("lunhui-zhang", 40);
	set_skill("spear", 120);
	set_skill("huoyun-qiang", 150);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "huoyun-qiang");
	map_skill("staff", "lunhui-zhang");
	map_skill("spear", "huoyun-qiang");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :),
	}) );

	create_family("ÄÏº£ÆÕÍÓÉ½", 2, "µÜ×Ó");

	setup();
	carry_object("/obj/money/gold");
	carry_object("/obj/money/gold");
	carry_object("/obj/cloth")->wear();
	carry_object("/d/nanhai/obj/jingu2");
	carry_object("/d/nanhai/obj/huojianqiang")->wield();
}

void attempt_apprentice(object ob)
{
	if (((int)ob->query_skill("buddhism", 1) < 50 )) {
		command("say " + RANK_D->query_respect(ob) + "µÄ·ğ·¨ĞŞĞĞ»¹²»¾«£¬»¹Ğè¶à¼ÓÅ¬Á¦²ÅÊÇ£¡");
		return;
	}
	command("smile");
	command("say ºÜºÃ£¬ÎÒ¾ÍÊÕÏÂÄã£¬Ï£ÍûÄã¶à¼ÓÅ¬Á¦£¬Ôç³ÉÕı¹û¡£\n");

	command("recruit " + ob->query("id") );
	message("system", HIY"ÎÒ·ğÃÅÓÖ¶àÁËÒ»¸öµÜ×Ó  "+this_player()->name()+HIW"
                 ÄÏº£ÆÕÍÓÉ½µÄÊÆÁ¦¼ÓÇ¿ÁË¡£\n"NOR,users());
	return;
}

ÿ
