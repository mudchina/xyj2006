
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "枫林");
  set ("long", @LONG

枫林中草木繁多，遍地绿草高可没膝。阵风吹过，草中发出
唏唏唆唆的响声，象是有人自草中穿行。顶上枫叶似火，密
密麻麻把天都遮住了。
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/cao" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/meishan/tiezhu",
  "northeast" : __DIR__"sengquan",
]));

  setup();
}

