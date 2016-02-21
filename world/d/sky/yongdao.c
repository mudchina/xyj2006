#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "甬道");
  set ("long", @LONG

甬道上是青石碎瓦铺地，道旁有四时不谢之仙花异草，遍地芬芳。
翠竹林中风带鸟语，色润飘香。周围见迭迭朱阁画楼，逐逐彩雾
烟波。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zhanyaotai",
    "west" : __DIR__"yunlougate",
    "south": __DIR__"taizifu",
    "north": __DIR__"yunlou",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/tong-nan" : 1,
]));


  set("outdoors", 1);
  setup();
}


