//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "石床");
set("long", @LONG
    
一张长长的石床。
LONG );


set("exits", ([
"out"   : __DIR__"shifang",
]));


set("objects", ([
]));



set("sleep_room", 1);
setup();
}
