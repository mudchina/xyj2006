// Room: /u/mimi/zhuziguo/huilang2.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "白玉回廊");
  set ("long", @LONG

廊两侧皆由白云石雕成，花鸟虫鱼，莫不维妙维肖。回廊之外花
开似锦，春意盎然。往北是废弃的御花园。三年前国王与祈雨的道
人在御花园玩赏时，道人化风而去，国王思慕那道人，再无心玩赏，
遂命人将花园关闭。往西是王后的寝宫。

LONG);

  set("outdoors", __DIR__"");                   
  set("exits", ([ /* sizeof() == 3 */
    "enter" : __DIR__"yuhua",
    "south" : __DIR__"huilang",
    "west" : __DIR__"ziyun.c",
  ]));
  set("objects", ([
     __DIR__"npc/girl" : 1,
  ]));

  setup();
}
