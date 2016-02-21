// create by snowcat.c 12/8/1997
#include <room.h>

inherit HOCKSHOP;

void create ()
{
  set ("short", "当铺");
  set ("long", @LONG

沿街的铺面挑着当字招牌，当铺里有一个大半人高的柜台，柜
台里放着各种各样典当的东西，柜前坐着当铺的老板，满面堆
笑地接待着客人。

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao96",
      ]));
  set("objects", ([
        __DIR__"npc/le"   : 1,
      ]));

  setup();
}


