//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("大梵天王", ({"dafan tianwang", "tianwang"}));
       	set("gender", "男性");
       	set("age", 60);
        set("class", "xian");
       	set("attitude", "friendly");
	set("title", "宇宙之主");
       	set("rank_info/respect", "大帝");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 1500);
       	set("max_gin", 1500);
       	set("max_sen", 1500);
       	set("force", 2000);
       	set("max_force", 2000);
       	set("force_factor", 80);
       	set("max_mana", 2000);
       	set("mana", 2000);
       	set("mana_factor", 80);
       	set("combat_exp", 1200000);
        set("daoxing", 2000000);

       	set_skill("dodge", 160);
       	set_skill("parry", 160);
        set_skill("spear", 160);
        set_skill("bawang-qiang", 160);
        set_skill("spells", 160);
        set_skill("dao", 160);
        set_skill("yanxing-steps", 160);
        map_skill("spells", "dao");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        map_skill("spear", "bawang-qiang");

	setup();
	carry_object("/d/obj/cloth/baipao")->wear();
}

