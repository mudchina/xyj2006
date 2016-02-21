// Room: /d/wiz/courthouse.c

#include <ansi.h>
inherit ROOM;

//seems should block chat and rumor here:)
//and can't quit here...hehe:)...weiqi
int do_chat();
int do_rumor();
int do_quit();

void create()
{
	set("short", "法院");
	set("long", @LONG

这里是审问机器人的法院，你一定是被人检举或是行为太像机器人，才
会来到这里，如果你答不出审判官的三个问题，会被做上记号，超过三
次的人将会被处以极刑，好好回答吧。

LONG
	);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}

void init()
{
	add_action("do_chat", "chat");
	add_action("do_chat", "chat*");
	add_action("do_rumor", "rumor");
	add_action("do_rumor", "rumor*");
	add_action("do_quit","quit");
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("忽然一阵闪光罩住了$N。\n", me);
	me->move(this_object());
}

int do_chat()
{
	object me;
	me=this_player();
	write("还是老老实实回答问题吧。\n");
	return 1;
}

int do_rumor()
{
	object me;
	me=this_player();
	write("大胆！到了这里还想散布谣言。\n");
	return 1;
}

int do_quit()
{
	object me;
	me=this_player();
	write("嘿嘿，想跑？回答出问题来就放了你。\n");
	return 1;
}

