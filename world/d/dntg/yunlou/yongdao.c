//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "甬道");
set("long", @LONG
    
甬道上是青石碎瓦铺地，道旁有四时不谢之仙花异草，遍地芬芳。
翠竹林中风带鸟语，色润飘香。周围见迭迭朱阁画楼，逐逐彩雾
烟波。
LONG );


set("exits", ([
  "west"   : __DIR__"gate",
  "north"   : __DIR__"yunlou",
  "south"   : __DIR__"taizifu",
]));


set("objects", ([
    __DIR__"npc/tong-nan" : 1,
]));

  create_door("west", "云楼宫门", "east", DOOR_CLOSED);


setup();
}
