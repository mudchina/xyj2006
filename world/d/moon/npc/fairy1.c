inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("¾ÕÓ°",({"shade","juying", "fairy"}));
       set("long",
"ôæÈô¾ªºè£¬ÍñÈôÓÎÁú£¬ÈÙê×Çï¾Õ£¬»ªÃ¯´ºËÉ¡£·Â·ðÙâÈô
ÇáÔÆÖ®±ÎÔÂ£¬Æ®Ò¡ÙâÈôÁ÷·çÖ®»ØÑ©¡£Ô¶¶øÍûÖ®£¬ð¨ÈôÌ«Ñô
Éý³¯Ï¼¡£ÆÈ¶ø²ìÖ®£¬×ÆÈôÜ½Çþ³öÂÌ²¨¡£\n");
       set("title", "ÔÂ¹¬ÎèÏÉ");
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

       set_skill("unarmed", 50);
       set_skill("dodge", 100);
       set_skill("force", 50);
       set_skill("parry", 50);
       set_skill("sword", 50);
       set_skill("spells", 50);
        set_skill("moonshentong", 40);
        set_skill("baihua-zhang", 40);
        set_skill("moonforce", 40);
        set_skill("snowsword", 40);
        set_skill("moondance", 80);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("ÔÂ¹¬", 2, "µÜ×Ó");
setup();

        carry_object("/d/obj/cloth/luoyi")->wear();
	carry_object("/d/obj/weapon/sword/snow_sword")->wield();
}


ÿ