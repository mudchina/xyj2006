// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小王子府");
  set ("long", @LONG

小王子府里挑着金黄色的灯笼，东边的墙边放着一金边香炉，
炉里香气缭绕。府上有一紫香木长案，案上有一些经书，还有
一个玉石砚台。

LONG);

  set("exits", ([
        "west"   : __DIR__"er",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince3"  : 1,
      ]));

  setup();
}



