#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "羊肠小路");
  set ("long", @LONG

小路很窄，只能容一人侧身而行。路边荆棘从生，一不小心就会
在身上挂出伤口。荆棘中生有红色野果，但很难摘到。远望东北
一座城池，南边上去是座石头山。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yangchang2",
  "northeast" : "/d/qujing/jisaiguo/pingxi",
]));

  setup();
}

