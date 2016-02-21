// Room: /u/mimi/zhuziguo/eastroom.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "东厢房");
  set ("long", @LONG

这是宝林寺的禅房，以供游方僧人借宿一宿，房内陈设简陋，靠墙
设有几张木床。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"backyard",
    "west" : __DIR__"zheng",
  ]));
  set("sleep_room",1);
  set("if_bed",1);

  setup();
}
