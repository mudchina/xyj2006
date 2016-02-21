// shiji3.c
// by shilling 97.2

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石级");
	set("long", @LONG
这是一段向南北方向伸展的石级，四周由于缺乏光亮，难免有点阴深深
的感觉，北面是个月形的铜门，南面是个石室。
LONG );
	set("exits", ([
		"south" : __DIR__"shishi2",
		"north" : __DIR__"tongmen",
	]));
	create_door("south", "石门", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
