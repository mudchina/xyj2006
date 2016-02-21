// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "客店");
  set ("long", @LONG

客店里有两张大桌子，八把木椅，墙边还有两条长长的条凳，
供行人歇脚。店后面有一柜台，上面摆着一些小吃之类的食
品。店北临街，不时有客进出。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie5",
      ]));
  set("objects", ([
        __DIR__"npc/dianzhu"   : 1,
      ]));
  set("valid_startroom",1);

  setup();
}


