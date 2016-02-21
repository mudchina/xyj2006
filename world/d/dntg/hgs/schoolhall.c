// Room: /d/4world/schoolhall.c
inherit ROOM;

void create ()
{
  set ("short", "武馆大厅");
  set ("long", @LONG

这里就是东方武馆的大厅，左右各摆四张檀木太师椅，是为来客准
备的。正中是东方馆主的座位。东边走廊通向内室，里面住的是武
馆弟子和家人。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"school2",
  "east" : __DIR__"schoolin.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dongfang" : 1,
]));

  setup();
}
