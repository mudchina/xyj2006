// Room: /u/mimi/zhuziguo/huilang.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "白玉回廊");
  set ("long", @LONG

回廊两侧皆由白云石雕成，花鸟虫鱼，莫不维妙维肖。回廊之外花
开似锦，春意盎然。往西通往锦香亭，往北则是祈雨坛。

LONG);

  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"jxt.c",
    "south" : __DIR__"palace",
    "north" : __DIR__"huilang2.c",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}

