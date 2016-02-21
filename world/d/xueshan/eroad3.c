//standroom.c used by weiqi...others may hate this format:D
//eroad3.c

inherit ROOM;

void create ()
{
	set ("short", "冰崖底");
	set ("long", @LONG

冰崖底的拐角处。两段冰崖在此交会，望上看去崖势不是那么
险峻了。
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
//		"north" : __DIR__"chufang",
		"west" : __DIR__"eroad2",
		//"east" : __DIR__"eroad3",
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

	if( !arg || arg != "up" ){
		return notify_fail("你要爬到哪里去？\n");
	}
	message_vision("$N手足并用，攀住冰崖向上爬了过去。\n", me);
	me->move(__DIR__"bingya-up1");
	message_vision("$N气喘呼呼地从下面爬了过来。\n", me);   
	return 1;    
}


