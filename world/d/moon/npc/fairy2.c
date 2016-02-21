//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("ÜøÑÌ",({"ming yan","fairy", "girl"}));
       set("long",
"ÆäÖé´äÖ®»Ô»ÔÙâ£¬Âú¶î¶ì»Æ¡£³öÃ»»¨¼äÙâ£¬ÒËàÁÒËÏ²£»ÅÇ»²³ØÉÏÙâ£¬
Èô·ÉÈôÑï¡£¶êÃ¼ò­Ð¦Ùâ£¬½«ÑÔ¶øÎ´Óï£»Á«²½Õ§ÒÆÙâ£¬ÓûÖ¹¶øÓûÐÐ¡£\n");
       set("title", "ÔÂ¹¬ËÅÅ®");
       set("gender", "Å®ÐÔ");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "ÏÉ¹Ã");
       set("per", 30);
	set("int", 30);
       set("max_kee", 800);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 600);
       set("max_force", 600);
       set("force_factor", 40);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 100000);
  set("daoxing", 50000);

       set_skill("literate", 80);
       set_skill("unarmed", 80);
       set_skill("dodge", 100);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 80);

create_family("ÔÂ¹¬", 3, "µÜ×Ó");
setup();

        carry_object("/d/obj/cloth/luoyi")->wear();
}


ÿ