// Room: /d/4world/east1.c
inherit ROOM;

void create ()
{
  set ("short", "东苑街");
  set ("long", @LONG

东苑街上没有什么商家，往来行人也不多。北边是一家大的武馆，
里面不时传出练武发出的声音。一扇朱红的铜钉门大开，向里也
看到几重院落。南边是个书院，看起来十分地干净。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"school1.c",
  "west" : __DIR__"center",
  "south" : __DIR__"shuyuan.c",
  "east" : __DIR__"east2.c",
]));
  set("outdoors", __DIR__"");

  setup();
}
