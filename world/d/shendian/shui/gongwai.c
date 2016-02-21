#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIB"水晶宫外"NOR);
set ("long", @LONG

水中，有一物体发出淡淡的光芒。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/bingfo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
