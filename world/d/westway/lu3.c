inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","大厅");
  set ("long", @LONG

大厅之上还是非常宽敞，周围墙上点着粗大的油灯，把大厅照
的通亮。厅中高台上放着三把太师椅，几个小妖来回走动。
LONG);

  set("exits", ([
        "south" : __DIR__"lu2",
      ]));
//  set("outdoors", __DIR__);
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/yin" : 1,
  __DIR__"npc/xiong" : 1,
  __DIR__"npc/niu" : 1,
]));

  setup();
}





