#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "柏林");
  set ("long", @LONG

柏林之中古柏森森，望去树木皆有百年之龄，挺直修长。树皮上
有风霜偶现，枝叶上淡挂绿萝。树木紧列如密密的屏障，林之深
处不可一见。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/bo" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"xinglin",
  "northwest": __DIR__"shiya",
  "southwest" : __DIR__"zhulin",
]));

  setup();
}


