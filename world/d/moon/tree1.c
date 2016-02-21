//Cracked by Roath
// Room: /moon/yunu1.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "桂树叶间");
  set ("long", @LONG
四周花香弥漫，枝叶繁茂，却已看不见地。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tree2",
  "down" : __DIR__"ontop2.c",
]));

 set("objects", ([
	"/d/obj/flower/guihua.c":2,]));

  setup();
}






