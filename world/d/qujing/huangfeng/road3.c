//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "乡间小路");
  set ("long", @LONG

在你的前方，一群鸟雀正在啄着地上的秕谷，根本都没有注意到
你的到来，等你走的很近时，它们才一哄而散。
LONG);

  set("exits", ([
        "west"  : __DIR__"road4",
        "east"  : __DIR__"road2",
      ]));
  set("outdoors","hfd");
  setup();
}
