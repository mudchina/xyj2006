// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "竹器店");
  set ("long", @LONG

店门口放着一些编好的竹器，门檐上挂着一个招牌迎风轻晃着，
里面铺面不小，到处堆满着竹制品。西墙有一柜台，上面也堆
着正在出售的竹制品。

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao16",
      ]));
  set("objects", ([
        __DIR__"npc/shi"   : 1,
      ]));

  setup();
}


