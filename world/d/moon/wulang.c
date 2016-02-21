//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "广寒宫舞廊");
  set ("long", @LONG

珠帘绣幕，画栋雕檐，说不尽那光摇朱户金铺地，雪照琼窗玉作宫。更见
鲜花馥郁，异草芬芳，真是个好所在。各个仙子皆是荷袂蹁跹，羽衣飘舞
，娇若春花，媚如秋月。这里正是月宫会宴佳宾之处，平日也用做练舞场
所。
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/fairy.c" : 1,
  __DIR__"npc/zhangmen.c" : 1,
  __DIR__"npc/fairy1.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"backyard.c",
  "north" : __DIR__"junkroom.c",
  "west" : __DIR__"ghg_zhengdian.c",
]));

  setup();
}
