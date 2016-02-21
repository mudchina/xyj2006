
#include <room.h>
#include <ansi.h>
inherit ROOM;



void create ()
{
  set ("short", "假山");
  set ("long", @LONG

天宫后院的假山，四季都盛开着鲜花，这里一草一木都
显露出帝王风范。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"      : __DIR__"beitian",

]));

  create_door("north", "北天门", "south", DOOR_CLOSED);

  set("objects", ([
]));


  setup();
}


