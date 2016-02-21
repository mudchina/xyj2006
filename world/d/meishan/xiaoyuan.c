
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "小院");
  set ("long", @LONG

院子四周有篱笆围绕，篱笆都是青竹编就，看起来古朴之极。院
中摆着些常用渔具，挂了几张渔网，靠墙还有个小木筏子。
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/girl" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"denglong2",
  "north" : __DIR__"maowu",
]));

  setup();
}

