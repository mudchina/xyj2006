// niushi.c
#include <ansi.h>
inherit NPC;
void create()
{
	object ob1, ob2;
string *order = ({"长", "短", "金", "卷"});
	set_name((order[random(4)]) + "毛虱", ({ "niushi"}) );
	set("long", "没见过虱子吗？去牛和猴子身上仔细找找。\n");
	set("attitude", "friendly");
	set("max_gin", 400);
	set("max_kee", 400);
set("max_sen", 400);
	set("max_mana", 500);
	set("mana", 500);
	set("str", 40);
	set("cor", 30);
	set("cps", 25);
	set("combat_exp", 100000);
	set_skill("stick", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();
	ob1=carry_object("/d/obj/armor/shoupi");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
	ob2=carry_object("/d/obj/weapon/stick/xiangmo");
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
		RED + name() + "说道：搞定，会家吸血去咯！\n\n"
+ name() + "蹭的跳回了老大的身上。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void invocation(object who)
{
	int i;
	object *enemy;
	message("vision",
		RED "只听啪！的一声，一团红光爆开，一个面目狰狞的牛虱掉到了地上。\n\n"
+ name() + "说道：我们是害虫，我们是害虫！\n" NOR,
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

