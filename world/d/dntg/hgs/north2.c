// Room: /d/4world/north2.c
inherit ROOM;

void create ()
{
  set ("short", "北菀街");
  set ("long", @LONG

这是傲来国中最大的一条街，宽有数丈。城中的富豪商家多聚于
此，银庄商号，饭馆客栈不断。往来人流拥挤，其中也不乏奇装
怪饰的外人。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"northgate",
  "south" : __DIR__"north1.c",
  "west" : __DIR__"bank.c",
  "east" : __DIR__"pownshop.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/monk" : 1,

]));

  set("outdoors", __DIR__"");

  setup();
}
