//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "西偏殿");
	set ("long", @LONG

西偏殿主要用来堆放一些布道上香的常用物品。殿北楠木桌上有
一对青铜的烛台，上有红烛轻燃。隔着西边的雕花木门是西廊，
隐约可听到竹林中的风声。东边就回到宝殿。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"jiangjing",
		"east" : __DIR__"zhengdian",
		"west" : __DIR__"westway2",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
	]));

create_door("west", "雕花木门", "east", DOOR_CLOSED);

	//set("outdoors", "wuzhuang");

	setup();
}

