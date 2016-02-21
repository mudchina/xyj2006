// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "民居");
  set ("long", @LONG

这家陈姓人家屋子里面空空的，一张木长条凳上放着一个空陶
盆，长条凳边有几只小木凳。墙角放着一堆柴禾，边上是一个
空的水缸。

LONG);

  set("exits", ([
        "out"   : __DIR__"chen1",
      ]));
  set("objects", ([
        __DIR__"npc/kid"  : 1,
      ]));

  setup();
}



