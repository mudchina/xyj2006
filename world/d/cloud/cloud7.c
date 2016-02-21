// Room: /d/cloud/cloud7.c north of cloud0

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "云端");

	set("long", @LONG

    你站在云端，向四周望去，四面是一望无际的云海，头顶是碧蓝的天空。
向下望去，只见一片青翠的绿色，偶尔有一些细细的白线贯穿其中。北面就是
南天门了。

LONG
	);

	set("exits", ([
		"southeast"	: __DIR__"cloud1.c",
		"south" 	: __DIR__"cloud0.c",
		"west"		: __DIR__"cloud6.c",
		"north"		: "/d/dntg/sky/nantian",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        me->add("mana", -10);

	return ::valid_leave(me, dir);
}

