//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("紧罗那", ({"jinluo na", "luona", "na"}));
       	set("gender", "男性");
       	set("age", 20);
        set("class", "xian");
       	set("attitude", "friendly");
	set("title", "歌神");
       	set("rank_info/respect", "歌神");
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
       	set("combat_exp", 600000);
        set("daoxing", 600000);

       	set_skill("dodge", 200);
       	set_skill("parry", 160);
        set_skill("wuxing-quan", 160);
        set_skill("spells", 160);
        set_skill("dao", 160);
        set_skill("moondance", 200);
	set_skill("unarmed", 160);
        map_skill("spells", "dao");
        map_skill("dodge", "moondance");
        map_skill("unarmed", "wuxing-quan");

	setup();
	carry_object("/d/qujing/tianzhu/obj/huapao")->wear();
}

