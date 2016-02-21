// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "仓库");
  set ("long", @LONG

石头的洞穴自然形成了一个仓库，里面有上下两层石壁分开，
堆放着不同的东西，主要有兽皮肉干之类的陈货。在东边的墙
角下似乎有一个缝隙。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"can",
      ]));

  setup();
}



