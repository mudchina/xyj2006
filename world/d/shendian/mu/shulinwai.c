#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIG"树林外"NOR);
set ("long", @LONG

隐约中，树林中间看到什么东西。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/mufo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
