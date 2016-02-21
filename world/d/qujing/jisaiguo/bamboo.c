#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "南湾竹屋");
  set ("long", @LONG

竹屋中摆满了各种竹制品，堆的到处都是，让人无法下脚。几个
小伙计正在一旁编着竹筐，因老板出去逛街，就有些偷懒。竹器
在这里还是个新鲜物，来的人还挺多。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/huoji" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"eastmarket",
]));

  setup();
}

