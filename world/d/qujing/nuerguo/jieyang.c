// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/jieyang.c

inherit ROOM;

void create ()
{
  set ("short", "解阳山");
  set ("long", @LONG

解阳山其实只是一座小土丘。不过这里幽花摆锦，野草铺蓝，
景致确是不错。山上有一道观，称为“聚仙庵”。山的西面
有一条小路。

LONG);

  set("exits", ([
    "north"   : __DIR__"sanchalu",
    "west"    : __DIR__"xiaolu1",
    "southup" : __DIR__"juxianan",
  ]));
  set("outdoors", __DIR__"");

  setup();
}






