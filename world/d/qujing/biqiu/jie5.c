// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

这里为三岔路口，整个路面由青石铺就的街坊，中间是五六尺
长两尺宽的三条石，路边是拳头大的平卵石。街道不甚直且顺
着地势而筑，略有高低上下。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"jie3",
        "east"    : __DIR__"jie6",
        "south"    : __DIR__"jie8",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

