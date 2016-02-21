
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "草屋");
  set ("long", @LONG

屋中光线不是很好，隐约看到正中一张八仙桌，几张竹椅。桌
上放着一个茶壶，几个茶碗。屋里并无豪华摆设，看来主人并
不是很富有。
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhangsun" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xiaoyuan",
]));

  setup();
}

