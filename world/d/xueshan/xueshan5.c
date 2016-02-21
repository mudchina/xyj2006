//standroom.c used by weiqi...others may hate this format:D
//xueshan5.c

inherit ROOM;

void create ()
{
	set ("short", "茫茫雪峰");
	set ("long", @LONG

绵延的山势在此似乎变得平坦起来，四周仍是白雪茫茫，只是北
风已不是那么肆虐。环绕的群山在西面打开了一道缺口，而一股
细微的暖意正断断续续地飘来。
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"xueshan4",
		"north" : __DIR__"xueshan6",
		"west" : __DIR__"xihai",
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



