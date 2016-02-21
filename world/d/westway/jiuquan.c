// create by snowcat.c 4/8/1997
// room: /d/westway/jiuquan.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","酒泉郊外");
  set ("long", @LONG

酒泉郊外是长途车马队歇脚的另一个重要地点。这里比较热闹，
尤其以产酒而闻名，“葡萄美酒夜光杯”由此而来。东面是一
条马道，西面是一条石栈道，北部是座神秘的小山丘。

LONG);

  set("exits", ([
        "east"      : __DIR__"madao",
        "west"      : __DIR__"shizhan",
        "northup"   : __DIR__"yunti",
      ]));
  set("outdoors", __DIR__);

  setup();
}



