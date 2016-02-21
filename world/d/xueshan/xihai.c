//standroom.c used by weiqi...others may hate this format:D
//xihai.c

inherit ROOM;

void create ()
{
	set ("short", "西海之畔");
	set ("long", @LONG

见惯了一望无际的雪原，巍峨雄伟的冰山，突然间碧波万顷，浩
瀚壮阔的水面展现在面前，你顿时觉得一股柔情蜜意涌上心头。
山，湖，草，鸟，仿佛是到了另一个世界。
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xueshan4",
		//"north" : __DIR__"xueshan6",
		"east" : __DIR__"xueshan5",
		//"west" : __DIR__"eroad1",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
  set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/hama" : 1,
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



