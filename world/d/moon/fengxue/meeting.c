//meeting.c

inherit ROOM;

void create ()
{
  set ("short", "议会大厅");
  set ("long", @LONG

这是供枫雪天地会的成员开月会的地方。里面有张大圆桌和十几把椅子。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"living",
]));

  setup();
}


