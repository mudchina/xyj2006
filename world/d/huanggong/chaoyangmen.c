inherit ROOM;

void create ()
{
  set ("short", "朝阳门");
  set ("long", @LONG

高墙巍峨，长梁雕龙，飞檐画凤，这里就是“朝阳门”。往
里就是皇宫大门了，一般的百姓到此截然止步，不敢擅自逾
越皇家禁地。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/weishi" : 2,
  ]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/city/xuanwu-n1",
  "north" : __DIR__"damen",
]));

  setup();
}


