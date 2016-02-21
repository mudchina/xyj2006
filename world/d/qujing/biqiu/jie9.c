// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

广场的北面是青石铺就的街坊，中间是五六尺长两尺宽的三条
石，路边是拳头大的平卵石。街道不甚直，顺地势而筑略有高
低上下，两边可见店铺，向西是一些宅院。

LONG);

  set("exits", ([
        "north"    : __DIR__"jie7",
        "southeast"    : __DIR__"jinqi",
        "southwest"    : __DIR__"xiaozi",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

