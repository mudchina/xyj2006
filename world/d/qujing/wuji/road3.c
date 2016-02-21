// Room: /moon/road.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

高峰入云，清流见底，青林翠竹，四时俱备。猿鸟乱鸣，沉鳞竞跃，
实是欲界之仙都。
LONG);

  set("outdoors", __DIR__"");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"road4.c",
  "eastdown" : __DIR__"road2.c",
]));

  setup();
}






