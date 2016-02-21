//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "宝阁");
  set ("long", @LONG

宝阁里霞光瑞气，笼罩千重，彩雾祥云，迷漫万道。正中有一
巨大的金钉藏经柜，旁边有一长长的紫木案桌，上有花玉宝匣。
都贴着各种红签。

LONG);

  set("exits", ([
        "down"   : __DIR__"baoge1",
      ]));
  set("objects", ([
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

