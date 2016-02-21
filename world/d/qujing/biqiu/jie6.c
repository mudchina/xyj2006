// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

一条街连接着城门与城内，整个路面由青石铺就的街坊，中间
是五六尺长两尺宽的三条石，路边是拳头大的平卵石。街道不
甚直且顺着地势而筑，略有高低上下。

LONG);

  set("exits", ([
        "west"    : __DIR__"jie5",
        "east"    : __DIR__"dongmen",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

