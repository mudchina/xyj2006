// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "茅屋");
  set ("long", @LONG

一座柴扉大开的茅屋，四周是木墙，上面挂着一些黄花金针木
耳地衣之类的干菜，茅屋的顶上是干茅草，门外是一圈矮矮的
篱笆墙。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"huangye8",
      ]));
  set("objects", ([
        __DIR__"npc/laofu" : 1,
      ]));
  setup();
}

