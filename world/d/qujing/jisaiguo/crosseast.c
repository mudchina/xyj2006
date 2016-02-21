#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "路口");
  set ("long", @LONG

祭赛国中非常的繁华，路周的楼台高耸，云雾缤纷。只见那三街
六市，货殖通财，来往人等衣冠隆重，足显民富豪华。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/laoban" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"eastmarket",
  "east" : __DIR__"eastgate",
  "south" : __DIR__"east1",
]));

  setup();
}

