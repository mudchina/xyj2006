//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "御马监大门");
        set("long", @LONG

天宫的御马监虽不甚大，却也小有气魄。正中间一块蓝
匾(bian)上书几个大字，门前两个监官来回巡游，偶尔
可以听到监内天马雄壮的嘶鸣声。
LONG);
set("item_desc",(["bian":"
       ***********************
       **      御马监       **
       ***********************\n"
]));

 
        set("exits", ([
                "east" : __DIR__"hgj6",
                "west" : __DIR__"zoulang",
        ]));
 
        set("objects", ([
		__DIR__"npc/jianguan": 2,
        ]));
 
        create_door("west", "小红门", "east", DOOR_CLOSED);
        set("no_clean_up", 0);

        set("outdoors", 1);

        setup();
}
