//dibaohouse.c
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "地保家");
        set("long", @LONG

    张地保手里有几个祖宗传下来的闲钱，因此也不干活，成天坐在
家里发呆。少爷脾气倒是从小养起来了，屋子里乱得象猪窝，也不说
收拾收拾。吃了饭，桌上还是杯子朝天碗朝地。

LONG
        );

	set("exits", ([
                "south" : __DIR__"road1",
        ]));

	set("objects", ([
                __DIR__"npc/dibao" : 1,
        ]));

	setup();
}

