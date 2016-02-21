// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

屋子里有一小灶，上有铁锅一口。边上有一菜筐里面堆有一些
青菜萝卜之类的蔬菜，地上有一小垛干柴干草。

LONG);

  set("exits", ([
        "southwest"    : __DIR__"cha",
      ]));
  setup();
}

