// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "河西");
  set ("long", @LONG

一条大河水面很宽，一眼望去，远远可以见到隐约的对岸。西
边是岸上的树林，东面是河面，已结了厚厚的冰层，冷风呼呼
地吹着，冰上偶然可见有人或车行走。

LONG);

  set("exits", ([
        "north"   : __DIR__"hexi5",
      ]));
  set("outdoors", __DIR__);

  setup();
}



