// Room: /d/huanggong/yhy3b
inherit ROOM;

void create ()
{
  set ("short", "御花园");
  set ("long", @LONG

葱翠艳丽的御花园，四周种满五颜六色龙形凤姿的奇花异蕊
中间是数条回转的青玉石雕花小径互为交错。煦风吹过，真
是葩醇花香无比，令人恍然纷醉。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yhy2b.c",
  "southwest" : __DIR__"damen",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
