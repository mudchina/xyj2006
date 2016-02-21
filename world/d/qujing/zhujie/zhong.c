// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "中宫");
  set ("long", @LONG

一个大厅在黑暗中被四周洞壁上的火炬照亮，大厅为三角形，
可容纳数十人。大厅的西边有一石头通道通往偏宫，东南边也
一石头通道通往外宫。

LONG);

  set("exits", ([
        "west"   : __DIR__"pian",
        "southeast"   : __DIR__"wai",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



