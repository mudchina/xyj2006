// Room: /u/mimi/zhuziguo/garden.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "后院");
  set ("long", @LONG

后院中心有一个小池塘，养了几只鹤。四围房前种了不少松柏，郁  
郁葱葱。

LONG);

  set("exits", ([ /* sizeof() == 4 */
    "west" : __DIR__"house.c",
    "south" : __DIR__"bedroom.c",
    "east" : __DIR__"stable.c",
    "north" : __DIR__"shufang.c",
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}

