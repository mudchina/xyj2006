// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xinshi.c

inherit ROOM;

void create ()
{
  set ("short", "新市口");
  set ("long", @LONG

新市口向北通往富贵人家的住宅区。街口宽敞，路面用石砖铺就，
这里相对比较安静干净。路上行人略少一点，有时可以见到一两
辆遮棚马车驶过。

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi5",
        "north"        : __DIR__"jieshi3",
        "south"        : __DIR__"jitan",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

