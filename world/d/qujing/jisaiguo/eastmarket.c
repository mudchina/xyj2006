#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "东市");
  set ("long", @LONG

祭赛国中非常的繁华，路周的楼台高耸，云雾缤纷。只见那三街
六市，货殖通财，来往人等衣冠隆重，足显民富豪华。路南有一
家小小的竹器铺，各种各样的手工艺品都摆到了街上。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"centermarket",
  "east" : __DIR__"crosseast",
  "south" : __DIR__"bamboo",
]));

  setup();
}

