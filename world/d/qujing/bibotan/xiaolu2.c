#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "潭边小路");
  set ("long", @LONG

小路因为年久无人走动的关系，已被枯黄的树叶覆盖了。路边的
荒草几有人高，阵风吹过，卷起一片片的枯叶。草从中也呼呼做
响，象是猛兽发出的吼声。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xiaolu1",
  "east" : __DIR__"luhua1",
]));

  setup();
}

