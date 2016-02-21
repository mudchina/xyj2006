#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"石林外"NOR);
set ("long", @LONG

这里有个石台，上面似乎有什么东西。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
   "/d/shendian/obj/shifo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
