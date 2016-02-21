
//note: this is created from player data.
//acer.c with foxer.c
inherit NPC;

void create()
{
	set_name("小小", ({"acer"}));
	set("long", "阿绣的丫环。\n");
	set("gender", "女性");
	set("age", 19);
	set("attitude", "friendly");
	set("per", 20);
	set("max_kee", 502);
	set("max_gin", 200);
	set("max_sen", 623);
	set("max_force", 770);
	set("force_factor", 20);
	set("max_mana", 870);
	set("mana_factor", 42);
	set("combat_exp", 113000);

	set_skill("dodge", 9);
	set_skill("ghost-steps", 9);
	set_skill("force", 40);
	set_skill("hellfire-whip", 73);
	set_skill("tonsillit", 59);
	set_skill("unarmed", 51);
	set_skill("whip", 9);

	map_skill("force", "tonsillit");
	map_skill("dodge", "ghost-steps");
	map_skill("whip", "hellfire-whip");

	setup();

	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/weapon/whip/tielian")->wield();
}

