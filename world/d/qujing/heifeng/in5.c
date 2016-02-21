//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

这里面是黑熊怪的厨房，他最爱吃的就是蜂蜜，所以这里面
的妖精只会偷些蜂蜜来讨好黑熊怪。
LONG);

  set("exits", ([
        "east"  : __DIR__"in2",
      ]));
  set("objects",([
        __DIR__"npc/yaojing":2,
        __DIR__"obj/fengmi":1,
        ]));
  setup();
}
