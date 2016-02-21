// Room: /changan/southseashore.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "海滨");
  set ("long", @LONG

这里没有明显的大道通往内地。而另一面是一片汪洋大海。你
只好沿着海边行走，希望能找出一条大路来。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"southseashore",
  "east" : __DIR__"seashore2",
]));
  set("outdoors", 2);

  setup();
}
