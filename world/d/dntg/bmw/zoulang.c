//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "走廊");
        set("long", @LONG

一条宽敞的走廊，足可供五匹马并排行走。
LONG
        );
 
        set("exits", ([
                "east" : __DIR__"gate",
                "west" : __DIR__"zhengting",
        ]));
 
        set("objects", ([
                __DIR__"npc/jianfu" : 1,
        ]));
 
        create_door("east", "小红门", "west", DOOR_CLOSED);
        set("no_clean_up", 0);


        setup();
}
