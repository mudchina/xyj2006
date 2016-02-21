//Cracked by Roath
// xiaomaolu.c

inherit NPC;

void create()
{
	set_name("小毛驴", ({"xiao maolu", "maolu", "lu"}));
	set("race", "野兽");
	set("age", 10);
	set("combat_exp", 10000);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite"}));

	set("ride/msg", "倒骑");
	set("ride/dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 20);

	setup();
}


