// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "林中路");
  set ("long", @LONG

你走在长长的林中路上，两边林深幽幽，狂风吹得叶飞枝舞，时不
时传来远处的虎啸猿啼。令人不由自主地加快步伐。

LONG);

  set("exits", ([ 
    "north" : __DIR__"lin2",
    "southwest" : __DIR__"dalu1",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
