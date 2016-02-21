// Room: /u/mimi/zhuziguo/prince_shufang.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "书房");
  set ("long", @LONG

房间三面都是书架，上面摆满了书，大多都是军事与哲学方面的书。
房中央有一张红木的书桌，桌后的太师椅上挂着一张白虎皮，一丝
杂毛也没有。这张虎皮是太子去年打猎而得，太子为此甚为自豪。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"garden",
    "southwest" : __DIR__"house.c",
  ]));

  setup();
}
