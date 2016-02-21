//Cracked by Roath
//houyuan.c
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "后院");
	set ("long", @LONG

来到后院，不觉心情为之一松。好一派鸟语花香。院子虽不大，
看得出有一番精心布置。北面一道小门以梨树枝结成，而雪白的
梨花居然依旧盛开。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"juyuan",
		"south" : __DIR__"houdian",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	create_door("north", "梨花门", "south", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
