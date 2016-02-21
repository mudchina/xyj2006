// heaven_soldier.c

#include <ansi.h>

inherit NPC;

#include <soldier_skill.h>
void create()
{
    	object ob1, ob2;
	
	string *order = ({"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"});

	set_name("天" + (order[random(10)]) + "神兵", ({ "heaven soldier", "soldier" }) );
	set("long", "这是一位来自天界的守护神，专门担任护法之责。\n");
	set("attitude", "friendly");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 5);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 100000);
	set("daoxing", 100000);
/*
	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "喝道：孽障！竟敢对？\n"
	}) );
*/
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	setup();

	ob1=carry_object("/d/obj/armor/tianjia");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
	ob2=carry_object(__DIR__"obj/golden_sword");
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
		HIY + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
		+ name() + "化成一道金光，冲上天际消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIY "一道金光由天而降，金光中走出一个身穿金色战袍的将官。\n\n"
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
  give_skill(who,"moonshentong","sword");
}
