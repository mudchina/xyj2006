//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "饮宴厅");
        set("long", @LONG

一间小屋，众监官常在此安排酒席，饮酒叙话。
LONG );
 
        set("exits", ([
                "north" : __DIR__"zhengting",
        ]));
 
        set("objects", ([
        ]));
 


        setup();
}
