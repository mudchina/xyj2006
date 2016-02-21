// create by snowcat.c 4/20/1997
// room: /d/eastway/jinshi.c

inherit ROOM;

void create ()
{
  set ("short", "进士场");
  set ("long", @LONG

进士场是一个不大不小的广场，据说新科进士在受赐之后都要在进士
场题名刻碑。另外这里也是文人墨客汇集的地方，在这里交流心得体
会。北边是碑林，西边可看到一座高塔。
LONG);

  set("exits", ([
      "north" : __DIR__"beilin1",
      "east"  : __DIR__"wangnan2",
      "south" : __DIR__"wangnan4",
      "west" : __DIR__"xyt",
    ]));
  set("objects", ([
      __DIR__"npc/xiucai"     : 2,
    ]));
  set("outdoors", __DIR__);

  setup();
}






