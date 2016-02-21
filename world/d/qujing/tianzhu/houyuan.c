// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "后院");
  set ("long", @LONG

一条泥土道穿过月门从北边的寺院通到这里，东边有几片菜地
种着一些蔬菜，菜地旁搭了一个瓜架，上面结着绿油油的小翠
瓜。南边的屋子有个烟囱，冒着青烟。

LONG);

  set("exits", ([
        "north"   : __DIR__"siyuan",
        "south"   : __DIR__"zhaifang",
        "northwest"   : __DIR__"baodian",
"southeast"    : __DIR__"chanfang",
      ]));
  set("outdoors", __DIR__);

  setup();
}


