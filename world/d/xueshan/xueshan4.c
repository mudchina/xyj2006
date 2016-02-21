//standroom.c used by weiqi...others may hate this format:D
//xueshan4.c

inherit ROOM;

void create ()
{
	set ("short", "茫茫雪峰");
	set ("long", @LONG

北风呼啸，飞雪茫茫，四面望去均是绵延不尽的雪峰。天地之间
似已毫无生迹，除了雪还是雪。
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"snowmaze9",
		"north" : __DIR__"xueshan5",
		//"west" : __DIR__"wroad1",
		//"east" : __DIR__"eroad1",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}



