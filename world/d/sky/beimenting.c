//beimenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "北门厅");
        set("long", @LONG
 
现在整修中。
LONG
        );
 
        set("exits", ([
                "north" : __DIR__"beitian",
        ]));
 
        create_door("north", "北天门", "south", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
