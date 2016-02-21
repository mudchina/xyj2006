//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

路旁的山涧中一群白鹤正在饮水，路旁的空地上，几个猿猴在呲牙咧
嘴的向你做鬼脸，一条小溪通向远处的山涧。

LONG);

  set("exits", ([
        "southwest"  : __DIR__"road3",
        "north"      : __DIR__"road1",
      ]));
  set("outdoors","hf");
  setup();

}
