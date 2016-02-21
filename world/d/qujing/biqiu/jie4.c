// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

街道上晃着酒楼的招牌，街面由青石铺就的街坊，中间是五六
尺长两尺宽的三条石，路边是拳头大的平卵石。街道不甚直，
顺地势而筑，略有高低上下。

LONG);

  set("exits", ([
        "east"    : __DIR__"zhai1",
        "northeast"    : __DIR__"jie1",
        "northwest"    : __DIR__"jiulou",
        "south"    : __DIR__"jie7",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

