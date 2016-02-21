//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("摩利之", ({"moli zhi", "zhi"}));
       	set("gender", "女性");
       	set("age", 20);
        set("class", "xian");
	set("title", "火焰之神");
       	set("attitude", "friendly");
       	set("rank_info/respect", "天女");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 600);
       	set("max_gin", 600);
       	set("max_sen", 600);
       	set("force", 2500);
       	set("max_force", 2500);
       	set("force_factor", 100);
       	set("max_mana", 2500);
       	set("mana", 2500);
       	set("mana_factor", 100);
       	set("combat_exp", 1600000);
        set("daoxing", 1000000);

       	set_skill("dodge", 180);
       	set_skill("parry", 180);
        set_skill("baihua-zhang", 180);
        set_skill("spells", 180);
        set_skill("moonshentong", 180);
        set_skill("moondance", 180);
	set_skill("unarmed", 180);
	set_skill("blade", 180);
	set_skill("huaxue-blade", 180);
	map_skill("blade", "huaxue-blade");
        map_skill("spells", "moonshentong");
        map_skill("dodge", "moondance");
        map_skill("unarmed", "baihua-zhang");
	map_skill("parry", "huaxue-blade");

	setup();
	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/start/obj/huoyandao")->wield();
}

