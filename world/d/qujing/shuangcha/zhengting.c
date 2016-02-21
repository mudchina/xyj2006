//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "客厅");
  set ("long", @LONG

正厅四壁上挂着些强弓硬弩，插着几壶利箭，在过梁上搭着
两块血腥的虎皮，墙跟头插着许多枪刀叉棒，正中间摆着两
张凳子。

LONG);

  set("exits", ([
        "east" : __DIR__"yard",
      ]));
  set("objects", ([
        __DIR__"npc/liumm": 1,
        ]));
  setup();

}
