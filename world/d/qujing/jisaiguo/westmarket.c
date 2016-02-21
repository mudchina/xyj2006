#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "西市");
  set ("long", @LONG

祭赛国中非常的繁华，路周的楼台高耸，云雾缤纷。只见那三街
六市，货殖通财，来往人等衣冠隆重，足显民富豪华。路南有一
家银器店，传出叮叮咚咚的响声。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"crosswest",
  "east" : __DIR__"centermarket",
  "south" : __DIR__"silver",
  "north" : __DIR__"yaopu",
]));

  setup();
}

