// Room: /u/mimi/zhuziguo/square.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "乾坤广场");
  set ("long", @LONG

这里是城中心了，路两旁挤满了小贩向你兜售当地的土产。向北可以
到达乌鸡国的皇宫。向南则是一片民宅。东西两边的大路上有不少商
店，甚是繁华。近几年来乌鸡国风调雨顺，老百性安居乐业，一片欣
向荣的景象。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"estreet2",
    "north" : __DIR__"nstreet.c",
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}

