// Room: /changan/wroad2.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "青石路");
  set ("long", @LONG

这条路相当好走。这里已经靠近西部边陲了。路上车马不少，
更有一队队的官兵押着一车车的辎重通过。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wroad3",
  "east" : __DIR__"wroad1",
]));
  set("outdoors", 1);

  setup();
}






