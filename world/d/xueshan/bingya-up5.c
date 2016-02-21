//standroom.c used by weiqi...others may hate this format:D
//bingya-up5.c

inherit ROOM;

string direction_name(string);
string direction_rev(string);

void create ()
{
	set ("short", "冰崖上");
	set ("long", @LONG

你趴在冰崖上，当真是小心翼翼。
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
		//"north" : __DIR__"chufang",
		//"west" : __DIR__"eroad2",
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

	if( !arg || (arg != "up" && arg != "down" && arg != "left" && arg != "right") )
	{
		return notify_fail("你要爬到哪里去？\n");
	}

	if( arg == "right" ) 
	{
		message_vision("$N手足并用，小心翼翼地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move(__DIR__"bingya-up4");
	}
	else if( arg == "left" ) 
	{
		message_vision("$N手足并用，小心翼翼地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move(__DIR__"bingya-up6");
	} 
	else return notify_fail( "往"+direction_name(arg)+"已经没有着手之点了。\n" );

	message_vision("$N从"+direction_rev(arg)+"面爬了过来，长长地舒了口气。\n", me);   
	return 1;    
}

string direction_name(string arg)
{
	if ( arg == "up" ) return "上";
	else if ( arg == "down" ) return "下";
	else if ( arg == "left" ) return "左";
	else if ( arg == "right" ) return "右";
	else return "不知道哪儿";
}

string direction_rev(string arg)
{
	if ( arg == "up" ) return "下";
	else if ( arg == "down" ) return "上";
	else if ( arg == "left" ) return "右";
	else if ( arg == "right" ) return "左";
	else return "不知道哪儿";
}



