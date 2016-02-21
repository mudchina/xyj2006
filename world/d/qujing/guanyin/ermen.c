inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "二门");
  set ("long", @LONG

洞门上写着一联对子：“静隐深山无俗虑，幽居仙洞
乐天真”。
LONG);
 
  set("exits", ([
        "north"  : __DIR__"tianjing",
        "south"  : __DIR__"sanmen",
      ]));
  create_door("south", "石门", "north", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}

