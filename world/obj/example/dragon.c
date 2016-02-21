// dragon.c

inherit NPC;

void create()
{
	set_name("五爪金龙", ({ "dragon" }) );
	set("long",
		"这是一只生长在璃山的五爪金龙，它身上的鳞片闪闪发着耀眼的光芒。\n");

	set("race", "野兽");
	set("age", 600);
	set("attitude", "friendly");

	set("max_gin", 4000);
	set("max_kee", 6000);
	set("max_sen", 3000);

	set("str", 80);
	set("cor", 40);
	set("cps", 40);
	set("spi", 40);
	set("int", 20);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 20);
	set("max_mana", 1000);
	set("mana", 1000);
	set("mana_factor", 50);

	set_skill("dodge", 200);
	set_skill("parry", 200);

	set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/armor", 60);

	set("combat_exp", 800000);
	setup();
}
