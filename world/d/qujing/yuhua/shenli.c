// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "审理厅");
  set ("long", @LONG

厅里灯火通明，两张香木长案面对面排开。靠门处有几张软缎
靠背椅，厅后有一素花屏风。看样子屏风后面可能有通道引向
内室。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie6",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));

  setup();
}



