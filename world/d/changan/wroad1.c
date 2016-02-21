// Room: /changan/wroad1.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "青石路");
  set ("long", @LONG

这条路相当好走。往东不远即是贯穿大唐南北的大官道。往
西直达西部边陲。路上车马不少，更有一队队的官兵押着一
车车的辎重通过。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wroad2",
  "east" : __DIR__"broadway3",
]));
  set("outdoors", 1);

  setup();
}






