//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("月宫天子", ({"yuegong tianzi", "tianzi", "zi"}));
       	set("gender", "男性");
       	set("age", 20);
        set("class", "xian");
       	set("attitude", "friendly");
       	set("rank_info/respect", "月神");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 1500);
       	set("max_gin", 1500);
       	set("max_sen", 1500);
       	set("force", 1000);
       	set("max_force", 1000);
       	set("force_factor", 50);
       	set("max_mana", 1000);
       	set("mana", 1000);
       	set("mana_factor", 50);
       	set("combat_exp", 800000);
        set("daoxing", 1000000);

       	set_skill("dodge", 160);
       	set_skill("parry", 160);
        set_skill("baihua-zhang", 160);
        set_skill("spells", 160);
        set_skill("dao", 160);
        set_skill("moondance", 160);
	set_skill("unarmed", 160);
        map_skill("spells", "dao");
        map_skill("dodge", "moondance");
        map_skill("unarmed", "baihua-zhang");

	setup();
	carry_object("/d/sea/obj/longpao")->wear();
	carry_object("/d/qujing/tianzhu/obj/longguan")->wear();
}

