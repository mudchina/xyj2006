//ximenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "西门厅");
        set("long", @LONG
现在整修中。
LONG
        );
 
        set("exits", ([
                "west" : __DIR__"xitian",
        ]));
 
        create_door("west", "西天门", "east", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
