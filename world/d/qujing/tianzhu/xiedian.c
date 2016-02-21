// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "鞋店");
  set ("long", @LONG

一大店铺里放了一排柜台，台子上是各种各样的鞋靴，档次有
高有低，既卖皮靴也卖草鞋，生意十分兴隆。柜台前放了一些
矮凳以方便顾客试鞋。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao78",
      ]));
  set("objects", ([
        __DIR__"npc/ji"   : 1,
      ]));

  setup();
}


