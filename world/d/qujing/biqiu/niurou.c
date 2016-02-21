// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "牛肉馆");
  set ("long", @LONG

牛肉馆里热气腾腾，一阵牛汤香味扑鼻而来。地上铺着蒲团和
几张矮脚桌，每个桌子上放着一大瓮牛肉清汤，让食客们随意
享受。

LONG);

  set("exits", ([
        "west"    : __DIR__"jie10",
      ]));
  set("objects", ([
        __DIR__"npc/kusikusi"    : 1,
      ]));
  setup();
}

