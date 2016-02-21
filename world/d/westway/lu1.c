inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","山洞内");
  set ("long", @LONG

山洞里黑乎乎的。南边的洞门口堆着好些杂草，大概从外边是
看不来的。北边山洞弯弯地通向深处。
LONG);

  set("exits", ([
        "south" : __DIR__"shizhan",
        "north"      : __DIR__"lu2",
      ]));
//  set("outdoors", __DIR__);
        set("objects", 
        ([ //sizeof() == 1
                "/d/westway/obj/tielong" : 1,
        ]));

  setup();
}





