#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "竹林");
  set ("long", @LONG

竹林中见各类翠竹环种，偶见有腊梅，丹桂飘香。又见有双瀑泻
于石涧中，跳珠溅玉，冷入人骨。上有竹桥一座，望之幽雅。冷
风从林中穿过，听之萧然。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhu" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"songlin",
  "northwest": __DIR__"xinglin",
  "northeast" : __DIR__"bolin",
]));

  setup();
}


