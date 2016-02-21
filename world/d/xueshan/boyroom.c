//standroom.c used by weiqi...others may hate this format:D
//girlroom.c

inherit ROOM;

void create ()
{
	set ("short", "男弟子卧房");
	set ("long", @LONG

雪山派的男弟子卧房。陈设相当简陋，连张床都没有。
LONG);

	//set("item_desc", (["bed" : "一张精致的床铺(gosleep, gobed, bed)。\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"restroom",
		//"north" : __DIR__"restroom",
		//"west" : __DIR__"restroom",
		//"east" : __DIR__"chufang",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 2,
		//__DIR__"npc/yingwu-guai" : 1,
	]));

	set("sleep_room",1);

	//set("outdoors", "xueshan");

	setup();
}


