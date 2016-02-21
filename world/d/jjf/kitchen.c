// Room: /d/jjf/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG
厨房里打扫的很干净。几口大锅里冒出阵阵香气，令人垂涎欲
滴。几个丫鬟正在收拾蔬菜。一个小厮来来回回地跑，大概在打下
手。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kitchen_road2",
  "southwest" : __DIR__"ne_garden",
]));

  setup();
}
