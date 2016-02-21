#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "后院");
  set ("long", @LONG

院中地势开阔，墙边的古树参天，枝繁叶密、正中一条青砖铺成
的小路直通向后面的大雄宝殿，两旁一式的青砖小舍，依稀可以
看出往日的兴旺，只是多了几分凄凉。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shaodi" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"baodian",
  "south" : __DIR__"inner2",
  "east": __DIR__"zai",
  "west": __DIR__"cha",
]));

  setup();
}

