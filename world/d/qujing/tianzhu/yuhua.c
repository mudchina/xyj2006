// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "御花园");
  set ("long", @LONG

御花园四周是琉璃墙，园中有大小云纹花坛无数，里面种着罕
见的奇花异草，散发着浓郁的清香味。花园的南边是金銮店，
东西为龙凤亭阁，北面是一排宫殿。

LONG);

  set("exits", ([
        "east"   : __DIR__"feng",
        "west"   : __DIR__"long",
        "south"   : __DIR__"jinluan",
        "north"   : __DIR__"hou3",
      ]));
  set("objects", ([
        __DIR__"npc/girl"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}


