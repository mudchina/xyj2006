// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

街坊整个路面由青石铺就的街坊，中间是五六尺长两尺宽的三
条石，路边是拳头大的平卵石。街道不甚直且顺着地势而筑，
路边有一牛肉馆的招牌。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"jie8",
        "southeast"    : __DIR__"jie11",
        "east"    : __DIR__"niurou",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

