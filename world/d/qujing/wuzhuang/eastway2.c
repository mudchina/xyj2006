//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "东小廊");
	set ("long", @LONG

这是大殿东厢的一条长廊，向北连到后院。小廊上是木板铺地，
打扫的极为干净，走在上面发出吱吱的响声。走廊两面的木格内
雕着一些山水人物。西边一道木门通到东偏殿。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"eastway1",
		"north" : __DIR__"eastway3",
		"west" : __DIR__"epiandian",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

create_door("west", "雕花木门", "east", DOOR_CLOSED);
//	set("outdoors", "wuzhuang");

	setup();
}
