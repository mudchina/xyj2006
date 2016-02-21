inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "清凉寺门");
  set ("long", @LONG
        
     那清凉寺在清凉山之巅，和沿途所见寺庙相比，也不
见得如何宏伟，山门破旧，显已年久失修。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"xiaoyuan",
  "south" : __DIR__"shanlu4",
   "east" :  "/d/shushan/shushan", 
]));

  create_door("enter", "寺门", "out", DOOR_CLOSED);
set("valid_startroom", 1);
setup();

}

