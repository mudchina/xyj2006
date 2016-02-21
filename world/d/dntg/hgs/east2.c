// Room: /d/4world/east2.c
inherit ROOM;

void create ()
{
  set ("short", "东苑街");
  set ("long", @LONG

这里已没有什么行人了，周围散居着几十家平民。房屋俱是白墙
青瓦，看起来十分的爽亮。有些人家还在屋前开地种了些瓜果蔬
菜，圈养些小鸡小鸭。几个孩子正相逐游戏。偶尔微风卷起些落
叶，似蝴蝶般飘舞。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kid1" : 1,
  __DIR__"npc/kid" : 1,
]));
  set("outdoors", "/d/4world");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room2.c",
  "north" : __DIR__"room1.c",
  "west" : __DIR__"east1",
  "east" : __DIR__"guchang.c",
]));

  setup();
}
