#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "中市");
  set ("long", @LONG

祭赛国中非常的繁华，路周的楼台高耸，云雾缤纷。只见那三街
六市，货殖通财，来往人等衣冠隆重，足显民富豪华。路南有一
家大酒楼，飘出烤肉的香味。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/xiaofan" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"westmarket",
  "east" : __DIR__"eastmarket",
  "north" : __DIR__"jitan",
  "south" : __DIR__"restaurant",
  "northup" : __DIR__"yunqi",
]));

  setup();
}

