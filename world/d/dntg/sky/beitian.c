
#include <room.h>
#include <ansi.h>
inherit ROOM;



void create ()
{
  set ("short", "北天门");
  set ("long", @LONG

这里是天宫的北门。由四大天王之一的魔礼寿负责保守。比起
南天门来，北边可就冷清多了。虽然如此，东天门造的可丝毫
不含糊。鲜红的大门上镶着闪闪发光的铜钉，显得威武非凡。
大力天丁和众天兵，一丝不苟的巡逻着。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"      : __DIR__"jiashan",
  "east"      : __DIR__"tgqn5",
  "west"      : __DIR__"tgqn4",

]));

  create_door("south", "北天门", "north", DOOR_CLOSED);

  set("objects", ([
  __DIR__"npc/moli-shou"   : 1,
  __DIR__"npc/tian-bing"   : 4,
"/d/eastway/npc/horsetrainer2":1,
]));


  setup();
}


