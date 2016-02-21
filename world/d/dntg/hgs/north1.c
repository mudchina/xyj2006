// Room: /d/4world/north1.c
inherit ROOM;

void create ()
{
  set ("short", "北菀街");
  set ("long", @LONG

这是傲来国中最大的一条街，宽有数长。城中的富豪商家多聚于
此，银庄商号，饭馆客栈不断。南边是城中心，偶见车马驰过。
东边则是城中最有名的翠香楼，飘出的香味不禁让人大流口水。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"north2",
  "south" : __DIR__"center.c",
  "east" : __DIR__"cuixiang.c",
]));
  set("outdoors", __DIR__"");

  setup();
}
