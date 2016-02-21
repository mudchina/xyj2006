#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "松林");
  set ("long", @LONG

松林皆是古松，望去树木皆有百年之龄，树枝如虬龙般盘扭，树
皮上有风霜偶现，枝叶上淡挂绿萝。树木紧列如密密的屏障，林
之深处不可一见。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/song" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east": __DIR__"zhulin",
  "northwest": __DIR__"huilin",
  "northeast" : __DIR__"xinglin",
]));

  setup();
}


