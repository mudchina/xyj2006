#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "乱石冈");
  set ("long", @LONG

乱石坡乱石遍地，大的小的到处都是。坡上极干燥，所生草木唯
有红柳，如在山上笼了一团红云。东边上去是山顶，山后就是碧
波潭，微风带来阵阵水声。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/stone" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shipo2",
  "eastup" : __DIR__"shishan",
]));

  setup();
}

