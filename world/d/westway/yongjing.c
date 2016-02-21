// create by snowcat.c 4/8/1997
// room: /d/westway/yongjing.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","永靖");
  set ("long", @LONG

永靖到了。这里是西北的一个不小的镇子，人口比较密集一些。
许多去西方取经或去西域长途贩货的车队马队在这里歇脚，东
面是一条大道，西南面是绕进山区的平阳道。

LONG);

  set("exits", ([
        "east"      : __DIR__"dadao",
        "southwest" : __DIR__"pingyang",
      ]));
  set("outdoors", __DIR__);

  setup();
}





