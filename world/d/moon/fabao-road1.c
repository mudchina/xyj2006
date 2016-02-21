//Cracked by Roath
//fabao-road1.c
inherit ROOM;

void create ()
{
	set ("short", "碎石路");
	set ("long", @LONG

斜斜的一道山脊往西延伸过去。一路上积雪越来越薄，而奇形怪
状的残岩碎石却越来越多。其中还有一些竟是色彩斑斓，不知是
从何而来。
LONG);

	set("exits", 
	([ //sizeof() == 4
		//"out" : __DIR__"guangchang",
		"east" : __DIR__"ontop2",
		"west" : __DIR__"fabao-road2",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	//set("valid_startroom", 1);
	set("outdoors", "moon");

	setup();
}

