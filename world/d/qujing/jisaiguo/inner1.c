#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "大院");
  set ("long", @LONG

院中地势开阔，墙边的古树参天，枝繁叶密、正中一条青砖铺成
的小路直通向后面的大雄宝殿，依稀可以看出往日的兴旺。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/oldmonk" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inner2",
  "south" : __DIR__"gate",
]));
  create_door("south", "偏门", "north", DOOR_CLOSED);

  setup();
}
