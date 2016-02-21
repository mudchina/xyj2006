// Room: /d/33tian/doushuai-gate
inherit ROOM;

void create ()
{
  set ("short", "殿门");
  set ("long", @LONG

走近看来，原来这座宫殿并不十分宏伟。殿门上横挂一块匾(bian)，
两边有一付对联 (duilian)。里面静悄悄的，也不知有没有人。正殿
后面隐隐约约可以看到一片松林，想必是个清修的好地方。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"west1",
  "north" : __DIR__"dadian",
]));
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "「兜率宫」
",
]));

  setup();
}
