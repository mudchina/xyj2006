//standroom.c used by weiqi...others may hate this format:D
//xueshan2.c

inherit ROOM;

void create ()
{
	set ("short", "茫茫雪峰");
	set ("long", @LONG

北风呼啸，飞雪茫茫，四面望去均是绵延不尽的雪峰。天地之间
似已毫无生迹，除了雪还是雪。
LONG);


	set("exits", 
	([ //sizeof() == 4
		"south" : "/d/moon/kunlun",
		"north" : __DIR__"xueshan2",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();
}


