// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "街坊");
  set ("long", @LONG

街道自道场东面绕过，路面由青石铺就的街坊，中间是五六
尺长两尺宽的三条石，路边上是的平卵石。街道顺着地势而
筑，西边的道场里不时传来人声。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"jie11",
        "south"    : __DIR__"nanmen",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

