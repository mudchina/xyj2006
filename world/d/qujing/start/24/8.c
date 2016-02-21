//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("日宫天子", ({"rigong tianzi", "tianzi", "zi"}));
       	set("gender", "男性");
       	set("age", 20);
        set("class", "xian");
       	set("attitude", "friendly");
       	set("rank_info/respect", "日神");
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
        set_skill("jienan-zhi", 160);
        set_skill("spells", 160);
        set_skill("buddhism", 160);
        set_skill("lotusmove", 160);
	set_skill("unarmed", 160);
        map_skill("spells", "buddhism");
        map_skill("dodge", "lotusmove");
        map_skill("unarmed", "jienan-zhi");

	setup();
	carry_object("/d/sea/obj/longpao")->wear();
	carry_object("/d/qujing/tianzhu/obj/longguan")->wear();
}

