#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "桧林");
  set ("long", @LONG

桧林之中皆是古桧，，望去树木皆有百年之龄，挺直修长。树皮
上有风霜偶现，枝叶上淡挂绿萝。树木紧列如密密的屏障，林之
深处不可一见。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/hui" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast": __DIR__"songlin",
  "east": __DIR__"xinglin",
  "northeast" : __DIR__"shiya",
]));

  setup();
}


