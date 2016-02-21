// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "马店");
  set ("long", @LONG

这里专供远道而来的马车准备的饭店，前面是客人休息洗刷吃
饭的场所，后面有一马棚，可以停放大小不同的马车，让马喝
水吃草休息。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao41",
      ]));
  set("objects", ([
        __DIR__"npc/ma"   : 1,
      ]));

  setup();
}


