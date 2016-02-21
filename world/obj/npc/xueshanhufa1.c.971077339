//xueshanhufa1.c
//created by vikee
//2000.10

#include <ansi.h>
inherit NPC;
#include <soldier_skill.h>
void create()
{
	set_name("老鹰",({ "lao ying", "hufa" }) );
	set("long", "一只得道多年的老鹰，传说是大鹏明王手下的得力干将。\n");
	set("attitude", "friendly");
	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("max_force", 500);
	set("force", 500);
	set("force_factor", 5);
	set("max_mana", 500);
	set("mana", 500);
	set("mana_factor", 5);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);
	set("combat_exp", 500000);
	set("daoxing", 500000);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	setup();
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;;
	}
	return ::heal_up() + 1;
}
void leave()
{
	message("vision",
		HIB + "老鹰一声长唳，展翅飞走了！\n\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void invocation(object who)
{
	int i;
	object *enemy;
	message("vision",
		HIC "只见天空中划出一道黑色闪电，一只兀鹰飞扑而来。\n\n" NOR,environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
  give_skill(who,"dengxian-dafa","sword");
}
