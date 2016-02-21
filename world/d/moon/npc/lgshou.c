// lgshou.c 锣鼓手

#include <ansi.h>
inherit NPC;

int do_kill(string);

void create()
{
	set_name("锣鼓手", ({ "luogu shou", "shou" }));
	set("long", "他就是婚礼上奏礼乐的吹鼓手。\n"
		"他胸前挂着一个大鼓，双手各拿一个鼓槌，起劲地敲打着。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 10);
	set("max_kee", 500);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
}

int do_kill(string arg)
{
	if ((arg=="shou" || arg=="luogu shou")
		&& environment()!=find_object("/d/moon/yltw")) {
		message_vision(HIR 
"你突然听到天上一个巨大的声音吼道：“$N企图破坏婚礼，乱人好事，天理难容！去死吧！”\n"
"话音未落，耳边“轰隆隆”一声雷鸣，一道闪电直劈下来正中$N的头顶，$N登时化成了灰烬！\n" NOR, this_player());
		this_player()->die();
		return 1; }
	return 0;
}
