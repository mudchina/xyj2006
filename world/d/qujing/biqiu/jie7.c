// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

西临城门，这里是青石铺就的街坊，中间是五六尺长两尺宽的
三条石，路边是拳头大的平卵石。街道不甚直，顺地势而筑略
有高低上下。两边可见店铺宅院。

LONG);

  set("exits", ([
        "west"    : __DIR__"ximen",
        "east"    : __DIR__"zhai2",
        "north"    : __DIR__"jie4",
        "south"    : __DIR__"jie9",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

