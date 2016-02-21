// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
	string *order = ({"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"});

	set_name( (order[random(12)]) + "阴鬼卒", ({ "hell guard", "guard" }) );
	set("long", "这是一位来自阴界的守护神，专门担任护法之责。\n");
	set("attitude", "heroism");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);

	set("max_force", 100);
	set("force", 100);
	set("max_mana", 100);
	set("mana", 100);

	set("str", 40);
	set("per", 10);

	set("combat_exp", 100000);
	set("daoxing", 100000);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "喝道：孽障！随我赴阴司受审吧。\n"
	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);

	setup();

	ob1=carry_object(__DIR__"obj/steel_armor");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
	ob2=carry_object(__DIR__"obj/steel_fork");
	ob2->wield();
	ob2->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIB + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n"
		+ name() + "的身形发出幽暗的蓝光，沈入地下不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIB "一道蓝光从地底升起，蓝光中出现一个手执钢叉、面目狰狞的鬼卒。\n"
		+ name() + "说道：末将奉法主召唤，特来护法！\n" NOR,
		environment(), this_object() );
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
}
