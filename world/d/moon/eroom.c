//Cracked by Roath
// Room: /moon/eroom.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "练功房");
  set ("long", @LONG

这是月宫弟子平时修炼的地方。靠南墙摆着一个书架。书架上书并不多，
无非是一些修生养性的法门。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/d/obj/book/san" : 1,
  "/d/obj/book/girlbook" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaoyuan",
]));

  setup();
}






