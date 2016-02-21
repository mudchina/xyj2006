#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIR"熔岩洞外"NOR);
set ("long", @LONG

这里有一个很小的祭坛，上面摆着一尊火佛。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/huofo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
