//Cracked by Roath
// shizhe.c ¾»Æ¿Ê¹Õßº
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("¾»Æ¿Ê¹Õß", ({ "shizhe" }));
	set("title", "ÄÏº£¹ÛÒôÊÌ´Ó");   
	set("long", @LONG
ÄÏº£¹ÛÒô×ùÇ°¾»Æ¿Ê¹Õß¡£
LONG);
	set("gender", "ÄÐÐÔ");
	set("age", 20);
	set("attitude", "friendly");
	set("max_kee", 300);
	set("max_gin", 300);
	set("max_sen", 350);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 10);
	set("max_mana", 350);
	set("mana", 350);
	set("mana_factor", 20);
	set("combat_exp", 100000);
	set("daoxing", 200000);


        set("eff_dx", 40000);
        set("nkgain", 200);

	set_skill("literate", 80);
	set_skill("spells", 70);
	set_skill("buddhism", 70);
	set_skill("unarmed", 60);
	set_skill("jienan-zhi", 55);
	set_skill("dodge", 70);
	set_skill("lotusmove", 70);
	set_skill("parry", 80);
	set_skill("force", 70);
	set_skill("lotusforce", 60);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

	setup();
//	carry_object("/obj/money/thousand-cash");
	carry_object("/obj/money/gold");
	carry_object("/d/nanhai/obj/jingping");
	carry_object("/obj/cloth")->wear();
}

ÿ
