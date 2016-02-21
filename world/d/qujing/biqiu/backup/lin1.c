// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "林道");
  set ("long", @LONG

你行进在铺满树叶的道路上，风萧萧，阳光从稀稀松松的树枝
间散射下来。光景苍凉，山高水长道更长，只见是纷纷野花盈
径，杂树栖鸟鸟更啼。

LONG);

  set("exits", ([
        "southeast"    : __DIR__"lin2",
        "west"    : __DIR__"dongmen",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

