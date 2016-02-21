// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

街坊上停着马车，街道的路面由青石铺就的街坊，中间是五六
尺长两尺宽的三条石，路边是拳头大的平卵石。街道不甚直且
顺着地势而筑，略有高低上下，南边有一招牌。

LONG);

  set("exits", ([
        "west"    : __DIR__"jie2",
        "east"    : __DIR__"jinting",
        "south"    : __DIR__"caipu",
        "southeast"    : __DIR__"jie5",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

