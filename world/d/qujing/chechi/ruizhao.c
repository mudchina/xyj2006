// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/ruizhao.c

inherit ROOM;

void create ()
{
  set ("short", "瑞兆场");
  set ("long", @LONG

一个以细砖铺就的小广场，场周围种了一圈苦椹树，由于缺水树
木已经有些干枯了。这里是车迟国的闹市区之一，行人来来往往
络绎不绝。

LONG);

  set("exits", ([
        "east"         : __DIR__"dongmen",
        "south"        : __DIR__"jieshi7",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

