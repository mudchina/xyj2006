#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "中院");
  set ("long", @LONG

院中地势开阔，墙边的古树参天，枝繁叶密、正中一条青砖铺成
的小路直通向后面的大雄宝殿，两旁一式的青砖小舍，依稀可以
看出往日的兴旺，只是多了几分凄凉。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/heshang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inner3",
  "south" : __DIR__"inner1",
  "east": __DIR__"jing",
  "west": __DIR__"xiang",
]));

  setup();
}

