// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "后园");
  set ("long", @LONG

一个深深的大园子，有一个用树干搭就的棚子，边上是一些高
高低低的枯树，地上是一些乱糟糟的干树叶、树皮、绳索之类
的杂物。

LONG);

  set("exits", ([
        "south"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"npc/qiaozi" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}
