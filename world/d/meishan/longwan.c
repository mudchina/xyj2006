
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "龙湾渡");
  set ("long", @LONG

灌江水静静东流，遥望水面一片渺茫。江心小岛上有数百只野
鸭，在水边盘旋沉浮。岸边有几十根大木桩子搭成的渡口，早
已废弃不用。
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/kang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"sengquan",
]));

  setup();
}

