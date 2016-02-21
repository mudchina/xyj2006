// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

此处街道略窄，路面由青石铺就的街坊，中间是五六尺长两尺
宽的三条石，路边是拳头大的平卵石。街道不甚直且顺着地势
而筑，略有高低上下。

LONG);

  set("exits", ([
        "west"    : __DIR__"jie1",
        "east"    : __DIR__"jie3",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

