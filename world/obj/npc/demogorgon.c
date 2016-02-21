// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "孙悟空" NOR, ({ "sun wukong" }) );
	set("long",
		"一个身不足五尺，瘦瘦干干，满身黄毛的猢狲。\n");
//		"可怕杀气正压得你几乎喘不过气来，你的心里似乎有一个声音在告\n"
//		"诉你：「 快 逃 ！！」\n");

	set("age", 30);
	set("pursuer", 1);

	set("max_gin", 5000);
	set("max_kee", 5000);
	set("max_sen", 5000);

	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 100);
	set("per", 100);

	set("combat_exp", 5000000);
	set("daoxing", 5000000);

	set_skill("stick", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("dodge", 500);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();

	carry_object("/d/obj/weapon/stick/jingubang")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;

	message("system",
		HIR "\n你听到有人怪叫了几声……\n\n"
		HIW	"孙悟空" HIR "喝道：玉帝老儿，与我听了！\n\n"
			"\t\t将天与俺老孙装上半个时辰，助俺成功！\n\n"
//			"\t\t限你们十五分钟内把我的头颅交出来 ！\n\n"
			"\t\t若道半声不肯，即上灵霄殿，动起刀兵！\n\n" NOR,
		users() );
	call_out("countdown", 60, 10);
}

private void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIW "\n孙悟空" HIR "用震耳欲聋的声音喝道：\n\n"
				"\t\t你们还有" + chinese_number(min) + "分钟的时间！\n\n"
				"\t\t到时莫怪俺老孙翻脸无情，多生事端！\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "\n孙悟空" HIR "用震耳欲聋的声音喝道：\n\n"
				"\t\t可恨．．．真是可恨．．．\n\n"
				"\t\t苍天啊～ 大地啊～  海洋啊～  众生啊～\n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	}
}

private void do_shutdown()
{
    object *user, link_ob;
    int i;

	message("system",
		HIW "\n\n孙悟空" HIR "高声喝道：装天！！！\n\n"
			"\t\t所有的一切都在瞬间陷入黑暗．．．\n\n"
			"\t\t然后你的眼前是一片黑暗．．．无止尽的黑暗．．．\n\n" NOR,
		users() );
	
	user = users();
	for(i=0; i<sizeof(user); i++) {
	   if( !environment(user[i]) ) continue;
	   user[i]->save();
	   link_ob = user[i]->query_temp("link_ob");
	   if( objectp(link_ob) ) link_ob->save();
	}

	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n你听到一声带着愤恨、惊恐、与野兽般的咆哮声响彻整个天空。\n\n"
		HIW "孙悟空" HIR "嘶哑地吼着：可恶的" + ob->name(1) + "，我一定会报仇的～～～\n\n"
			"然后一道黑色火焰呼啸着冲上云端，大地又恢复了宁静。\n\n" NOR,
		users() );
	destruct(this_object());
}
