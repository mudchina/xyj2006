//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

这个地方全部都是一些松树，黑幽幽的颜色令人发冷。风一吹松树
向你涌来，仿佛妖怪在向你挑衅。

LONG);

  set("exits", ([
        "south"  : __DIR__"road4",
        "northeast"  : __DIR__"road2",
      ]));
  set("outdoors","hf");
  setup();

}
