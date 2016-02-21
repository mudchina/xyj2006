// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

街坊整个路面由青石铺就的街坊，中间是五六尺长两尺宽的三
条石，路边是拳头大的平卵石。街道不甚直且顺着地势而筑，
略有高低上下。

LONG);

  set("exits", ([
        "north"    : __DIR__"jie5",
        "southwest"    : __DIR__"jie10",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

