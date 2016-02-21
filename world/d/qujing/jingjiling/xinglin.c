#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "杏林");
  set ("long", @LONG

杏林中各色杏花怒放，香气扑鼻，几乎要将人醉倒了。望眼遍是
碗口大的花朵，且色彩多变，望之如女子之笑脸。树木皆成深色
如墨，而无一花瓣凋解。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/xing" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north": __DIR__"shiya",
  "east": __DIR__"bolin",
  "west": __DIR__"huilin",
  "southeast": __DIR__"zhulin",
  "southwest" : __DIR__"songlin",
]));

  setup();
}


