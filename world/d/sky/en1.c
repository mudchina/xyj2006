//en1.c
//created 4-8-97 pickle

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "天宫墙外");
  set ("long", @LONG

    漫步过来，你感到空气异常的新鲜，心情也随之变的很好。西边
是天宫的高墙。玉帝和他的臣子们神通广大，所以天宫不必象下界般
造起五丈城墙，充满剑拔弩张的气氛。琉璃造就的墙里，隐隐约约的
是宫殿的飞檐。南面遥遥可以看到东天门。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ne",
  "south" : __DIR__"dongtian",
]));
  set("outdoors", 1);

  setup();
}
