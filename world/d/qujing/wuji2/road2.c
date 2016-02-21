// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

只见此山八面巍峨，四围险峻，古怪乔松盘翠盖，枯摧老树挂藤箩。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road1",
  "westup" : __DIR__"road3",
]));

  setup();
}







