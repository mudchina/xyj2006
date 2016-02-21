// Room: /u/hkgroup/yard3
inherit ROOM;

void create ()
{
  set ("short", "怡红院");
  set ("long", @LONG

　　　　深庭长日静，两两出婵娟。绿蜡春犹卷，红□夜未眠。
　　　　凭栏垂绛袖，倚石护青烟。对立东风□，主人应解怜。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge",
  "backyard" : __DIR__"bull",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
