// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "虎口");
  set ("long", @LONG

一个深奥莫测的山洞出现在眼前，洞口有凉嗖嗖的溪水滴嗒下
来。洞壁上是苔衣和蔓藤，洞口上写着六个大字：豹头山虎口
洞。

LONG);

  set("exits", ([
        "north"   : __DIR__"qiandong",
        "southeast"   : __DIR__"dongwai",
      ]));
  set("outdoors", __DIR__);
  set("objects", ([
        __DIR__"npc/yao"  : 3,
      ]));

  setup();
}



