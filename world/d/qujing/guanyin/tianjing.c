inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "天井");
  set ("long", @LONG

只见这儿松篁交翠，桃李争研，丛丛花发，簇簇兰香。
却也是个洞天之处。小妖在四处走动。
LONG);
 
  set("exits", ([
 "north" : __DIR__"dongmen",
        "south"  : __DIR__"ermen",
      ]));
create_door("north", "石门", "south", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}

