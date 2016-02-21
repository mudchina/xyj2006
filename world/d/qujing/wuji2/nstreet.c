// Room: /u/mimi/zhuziguo/northstreet.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "乾元街");
  set ("long", @LONG

乾元街两边多为官宅民房。向北走可直达皇宫。路两旁时有卫兵巡
逻。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"square",
    "north" : __DIR__"nstreet2.c",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 3,
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}

