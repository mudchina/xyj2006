//Cracked by Roath
//standroom.c used by weiqi...others may hate this format:D
//tingjing.c

inherit ROOM;

void create ()
{
	set ("short", "听经石");
	set ("long", @LONG

这块石头(stone)状似两只并卧的海龟，静静地趴在海滩上。据说
东海龙王敖广曾派二海龟去偷听观音念经，并要它们记下经文，
好用来给水族讲解。不料，二龟光顾听经，全神贯注下竟错过了
返回大海的时间，遂变为石头。
LONG);

	set("item_desc", (["stone" : "石头上刻着一首诗： \n
		见说盘陀著地灵，
		普门曾此坐谈经。
		二龟何事翻成石，
		想是当年不解听。\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"***",
		//"north" : __DIR__"wuchang-s",
		"south" : __DIR__"island",
		"north" : __DIR__"shanglu2",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "/d/nanhai");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

