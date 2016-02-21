
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "院内");
  set ("long", @LONG
        
     那清凉寺在清凉山之巅，和沿途所见寺庙相比，也不
见得如何宏伟，山门破旧，显已年久失修。
LONG);

  set("outdoors", "/u/dragon/kfadd/door");
  set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"neitang",
  "out" : __DIR__"door",
  ]));

create_door("out", "石门", "enter", DOOR_CLOSED);
  setup();
}
