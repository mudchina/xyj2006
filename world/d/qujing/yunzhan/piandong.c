//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "偏洞");
  set ("long", @LONG

这里堆满了白骨，你不禁打了个寒噤，你仔细一瞧，原来是些虎狼
的骨头，这真是强中更有强中手，百兽之王竟然抵不过这猪怪的一
耙。
LONG);

  set("exits", ([
        "east"  : __DIR__"in2",
      ]));
  set("objects",([
        __DIR__"obj/weed":1,
        ]));
  setup();
}
