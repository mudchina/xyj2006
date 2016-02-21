//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "阳明道");
  set ("long", @LONG

山上祥光五色，瑞蔼千重，灵鹫顶上披彩虹，高峰两边落飞霞，
紫气袅袅气吞宇宙。阳明道缥缥缈渺如筑在云中，路边都是仙
石仙岩。

LONG);

  set("exits", ([
        "eastdown"   : __DIR__"yang2",
        "northwest"   : __DIR__"lingyun2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



