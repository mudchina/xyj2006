// Room: /d/4world/west1.c
inherit ROOM;

void create ()
{
  set ("short", "西芫街");
  set ("long", @LONG

西芫街宽广的街道上铺着石板，偶尔马匹驰过，马蹄在石板上
发出清脆地嗒嗒声。东边就通到城中心，远远可见宽阔地广场
和广场中的大旗及石台。南边是家斋院，是给穷人舍饭的地方。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"huofang.c",
  "south" : __DIR__"zhaiyuan.c",
  "west" : __DIR__"west2.c",
  "east" : __DIR__"center",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kid" : 1,
  "/d/city/npc/dog":1,
]));

  set("outdoors", "/d/4world");

  setup();
}
