//Cracked by Roath
//mudanting.c
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "牡丹亭");
	set ("long", @LONG

      ***********************
      &      牡丹亭         &
      ***********************         

果然是饮酒赏园的绝妙去处！北面桃林中甜香阵阵，大红蜜桃似
乎伸手可及。南面的菊园中蜂飞鸟唱，时有几片金黄的菊瓣随风
飘来。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"juyuan",
		"north" : __DIR__"southpool",
		"down" : __DIR__"anshi",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/misc/table" : 1,
		__DIR__"npc/hanzhongli" : 1,
	]));

	create_door("down","桌底暗门", "up", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
