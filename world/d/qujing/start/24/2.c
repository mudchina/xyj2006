//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("黄飞虎", ({"huang feihu", "feihu", "huang"}));
       	set("gender", "男性");
       	set("age", 40);
	set("title", "东岳大帝");
        set("class", "fighter");
       	set("attitude", "friendly");
       	set("rank_info/respect", "大将军");
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
        set("daoxing", 1200000);

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
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "dingshen" :)
        }) );

	setup();
        carry_object("/d/obj/weapon/spear/jinqiang")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

