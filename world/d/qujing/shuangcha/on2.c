//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/on2.c

inherit ROOM;

void create ()
{
  set ("short", "山岭");
  set ("long", @LONG

草呼呼的晃动着，在这种草窝里面经常会出来一些猛兽，这时
安静极了，只有一些小鸟喧杂的声音。
LONG);

  set("exits", ([
        "east" : __DIR__"on",
        "westdown" : __DIR__"shanlu4",
      ]));
  set("outdoors","sc");
  set("objects", ([
        __DIR__"npc/tiger": 1,
        ]));
  setup();
}
