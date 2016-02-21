//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ÁéÏö±¦µî");
set("long", @LONG
    
LONG );


set("exits", ([
  "south"   : __DIR__"qianyuangong",
//  "north"   : __DIR__"houhuayuan",
//  "west"   : __DIR__"hougong",
//  "east"   : __DIR__"hougong",
]));


set("objects", ([
  __DIR__"npc/yuhuang"   : 1,
//"/d/qujing/wuzhuang/npc/laojun"   : 1,
  __DIR__"npc/wuquxingjun"   : 1,
]));



setup();
}
