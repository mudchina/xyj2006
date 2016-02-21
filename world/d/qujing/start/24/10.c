//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("鬼子母神", ({"guizimu shen", "shen"}));
       	set("gender", "女性");
       	set("age", 20);
        set("class", "youling");
	set("title", "母夜叉");
       	set("attitude", "friendly");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 1300);
       	set("max_gin", 1300);
       	set("max_sen", 1300);
       	set("force", 2500);
       	set("max_force", 2500);
       	set("force_factor", 80);
       	set("max_mana", 2500);
       	set("mana", 2500);
       	set("mana_factor", 80);
       	set("combat_exp", 1200000);
        set("daoxing", 400000);

       	set_skill("dodge", 180);
       	set_skill("parry", 180);
        set_skill("jinghun-zhang", 180);
        set_skill("spells", 180);
        set_skill("gouhunshu", 180);
        set_skill("ghost-steps", 180);
	set_skill("unarmed", 180);

        map_skill("spells", "gouhunshu");
        map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");

	setup();
	carry_object("/d/obj/cloth/hei")->wear();
}

