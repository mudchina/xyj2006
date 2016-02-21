// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "酒店");
  set ("long", @LONG

店里酒气熏天，靠窗一是几张方桌，里面是酒柜，上面放着大小不
一的酒坛子。墙上写着“不醉不归，醉亦不归”，墙下有些躺椅，
一些醉得不醒人事的酒客正躺在上面休息。

LONG);

  set("exits", ([ 
    "south" : __DIR__"xi2",
  ]));
  set("objects", ([
    __DIR__"npc/zui" : 1,
    "/d/obj/misc/woodtable" : 1,
    "/d/obj/misc/woodseat" : 2,
  ]));
  setup();
}
