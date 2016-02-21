#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIY"剑阵外"NOR);
set ("long", @LONG

地上有什么东西闪闪发光，原来是一尊金佛。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/jinfo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
