#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "羊肉店");
  set ("long", @LONG

烤肉点里飘着股浓浓的烤肉香味。店中无椅无桌，人人都是席地
而坐，面前的烤炉上放着不同种类，烤的香喷喷的肉食。店中的
客人都是大口喝酒，大口吃肉，自得其乐的样子。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/samui" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"centermarket",
]));

  setup();
}

