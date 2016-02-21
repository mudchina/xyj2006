// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "民居");
  set ("long", @LONG

这也是一户陈姓人家，房子里面布置得非常舒适。屋子东边有
一灶台，正烧着火，不知在做什么，散发出一股清香味。南边
的门通向屋外。

LONG);

  set("exits", ([
        "out"   : __DIR__"chen2",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(2),
        __DIR__"npc/kid"  : random(2),
        __DIR__"npc/ji"  : 1,
      ]));

  setup();
}



