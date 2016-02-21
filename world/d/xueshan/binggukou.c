//standroom.c used by weiqi...others may hate this format:D
//binggukou.c

inherit ROOM;

void create ()
{
	set ("short", "冰谷口");
	set ("long", @LONG

这里突然出现了一道深谷。向下只能看到一段刀削斧劈似的冰
崖，在往下则是雪雾缭绕，什么也看不清了。不故谷底似乎有
一股炊烟的香味飘了上来，在冰天雪地中挣扎求生的你不禁有
点砰然心动。
LONG);

	set("item_desc", (["north" : "冰谷中雪雾缭绕，什么也看不清。\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"bingchuan",
		"north" : __DIR__"bingya-up7",
		"west" : __DIR__"bingchuan",
		"east" : __DIR__"bingchuan",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 1,
	]));


	set("outdoors", "xuesan");

	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();

	if( !arg || arg != "down" ){
		return notify_fail("你要爬到哪里去？\n");
	}
	message_vision("$N手足并用，攀住冰崖向下爬了过去。\n", me);
	me->move(__DIR__"bingya-up7");
	message_vision("$N气喘呼呼地从上面爬了过来。\n", me);   
	return 1;    
}

int valid_leave(object me, string dir)
{
	if (dir == "north" )
	{
		message_vision("$N不顾一切地往冰崖下一跳．．．\n", me);
		message("vision", "良久，一声杀猪般的惨号从冰崖下传了上来。\n", environment(me), ({ me }));

		call_out("do_unconcious", 0, me);
		return notify_fail("完了．．．\n");
	}

	return ::valid_leave(me, dir);
}

void do_unconcious(object me)
{
		me->move(__DIR__"binggu");
		message_vision("只听一声惨叫，$N死猪般地从冰崖上摔了下来！\n", me);
	me->unconcious();
}
