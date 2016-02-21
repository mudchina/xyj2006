//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("菩提树神", ({"putishu shen", "shen"}));
       	set("gender", "女性");
       	set("age", 20);
        set("class", "xian");
       	set("attitude", "friendly");
        set("per", 30);
        set("int", 30);
	set("str", 30);

	set_temp("apply/armor", 200);

       	set("max_kee", 8000);
       	set("max_gin", 2000);
       	set("max_sen", 2000);

       	set("force", 2500);
       	set("max_force", 2500);
       	set("force_factor", 20);
       	set("max_mana", 1000);
       	set("mana", 1000);
       	set("mana_factor", 50);
       	set("combat_exp", 2000000);
        set("daoxing", 1000000);

       	set_skill("dodge", 300);
       	set_skill("parry", 300);
        set_skill("puti-zhi", 200);
        set_skill("spells", 100);
        set_skill("dao", 100);
	set_skill("unarmed", 200);
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");

	setup();
	carry_object("/d/moon/obj/luoyi")->wear();
}

