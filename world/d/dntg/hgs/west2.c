// Room: /d/4world/西芫街
inherit ROOM;

void create ()
{
  set ("short", "西芫街");
  set ("long", @LONG

西芫街宽广的街道上铺着石板，偶尔马匹驰过，马蹄在石板上
发出清脆地嗒嗒声。东边就通到城中心，远远可见宽阔地广场
和广场中的大旗及石台。北边是个小土地庙，南边是家民宅，
门口挂着些红布。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shiwu.c",
  "north" : __DIR__"tudi.c",
  "east" : __DIR__"west1",
]));
  set("outdoors", "/d/4world");

  setup();
}
