//Cracked by Roath
// Room: /moon/neartop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "玉女峰");
  set ("long", @LONG

这里靠近玉女峰顶。虽说是冰雪遍地，你并不觉得太冷。四周冰缝中长着
一些洁白的雪莲。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/xuelian" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"ontop2.c",
  "eastdown" : __DIR__"yunu5",
]));

  setup();
}






