// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "兰亭府");
  set ("long", @LONG

兰亭府大门两边是朱红柱，上方挂有一排灯笼分别书有：“香”，“
玉”，“翠”几个大字。府内灯火通明，丝弦乐不断从里屋传出来。
西面是尧王大街，东边通向兰亭府内。

LONG);

  set("exits", ([
        "west" : __DIR__"yao4",
        "east" : __DIR__"xianglan",
      ]));
  set("objects", ([
        __DIR__"npc/yahuan" :  2,
      ]));

  setup();
}


