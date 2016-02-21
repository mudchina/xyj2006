// Room: /u/mimi/zhuziguo/road6  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

只见此山八面巍峨，四围险峻，古怪乔松盘翠盖，枯摧老树挂藤箩。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"road7",
  "eastup" : __DIR__"road5",
]));

  setup();
}
