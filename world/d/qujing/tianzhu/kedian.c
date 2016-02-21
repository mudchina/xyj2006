// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "客店");
  set ("long", @LONG

一间十分宽敞的客店，四周的石墙被粉刷得雪白干净，临街的
窗台上放着茶具，一张四方大木桌摆在堂中，四边放着长条凳
供客人门休息。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao21",
      ]));
  set("objects", ([
        __DIR__"npc/xin"   : 1,
      ]));
  set("valid_startroom",1);

  setup();
}


