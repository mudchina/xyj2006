//standroom.c used by weiqi...others may hate this format:D
//eroad2.c

inherit ROOM;

void create ()
{
	set ("short", "小木屋外");
	set ("long", @LONG

很难想象这些木头是从哪里来的。但是这里的确是一间小木屋。
周围是一道冰制的围墙，也不过半人来高。围墙入口出站着一
位身披白袍，腰跨弯刀的男子。
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"xiaomuwu",
		//"north" : __DIR__"icegate",
		"west" : __DIR__"eroad1",
		"east" : __DIR__"eroad3",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/shier" : 2,
	]));


	set("outdoors", "xuesan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

int valid_leave(object me, string dir)
{
	object shier;
	if (dir == "south" ) {
		if(objectp(shier=present("shier", environment(me))) && living(shier) )
		{
			if ( me->query("family/family_name") == "大雪山" && (int)me->query("family/generation") <= 3 )
				write("侍儿点头哈腰地把你让了进去。\n");
			else 
				return notify_fail("侍儿把你一拦道：公主有令，任何人不得入内打搅！\n");
		}
	}

	return ::valid_leave(me, dir);
}

