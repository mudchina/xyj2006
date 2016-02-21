// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "金兜山");
  set ("long", @LONG

万山丛中，脚下的险峰在云海中露峥嵘，山峰之上雾气缭绕彩
虹飞舞。森林之中时时有猛兽的怒吼之声震撼山谷，使人不禁
迟疑地放慢脚步。

LONG);

  set("exits", ([
        "south"   : __DIR__"shanshi1",
        "southwest"   : __DIR__"shanlu2",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}



