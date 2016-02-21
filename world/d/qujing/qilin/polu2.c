// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "坡路");
  set ("long", @LONG

坡路渐陡渐窄，山色茫茫云雾渺渺，东南方向的巅峰冲天占地，挡
住雾角，岭头松郁郁。路旁岩崖石磷磷高耸，往东可以遥遥望见朱
紫国城池。

LONG);

  set("exits", ([ 
    "eastup" : __DIR__"polu3",
    "westdown" : __DIR__"polu1",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
