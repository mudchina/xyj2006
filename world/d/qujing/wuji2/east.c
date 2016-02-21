// Room: /u/mimi/zhuziguo/east  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "东厢房");
  set ("long", @LONG
这是宝林寺的禅房，房内摆有一张长桌，靠墙设有几张木床。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : "",
]));
  setup();
}

