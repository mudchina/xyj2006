// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

  枯花满地鸟鸣绝，流水无声脚有声。静谧的山野，隐藏
着无限的杀机。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"baigushan",
  "westup"    : __DIR__"banshanpo", 
]));

  setup();
}






