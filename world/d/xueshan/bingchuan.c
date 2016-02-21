//standroom.c used by weiqi...others may hate this format:D
//bingchuan.c

inherit ROOM;

void create ()
{
	set ("short", "冰川");
	set ("long", @LONG

等上了冰川，你才觉得世界在你脚下又拔高了一层。放眼望去，
一面是延绵不尽的雪峰，但此时都好像到了你的脚下。一面是浩
翰无垠的冰原，如大海中的波涛一样起伏在你的面前。而几条巨
大的冰缝也在冰原中穿行，深不可测地等待着失足的旅人。
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"xueshan6",
		"north" : __DIR__"binggukou",
		"west" : __DIR__"bingchuan",
		"east" : __DIR__"bingchuan",
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



