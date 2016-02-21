// Room: /u/mimi/zhuziguo/road7  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山顶嵯峨摩斗柄，树梢仿佛接云霄。青烟堆里，时闻得谷口啼猿；乱
翠荫中，每听得松间鹤唳。远远的可以看见山下楼台叠叠，殿阁重重。
LONG);

  set("outdoors", __DIR__"");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"road6",
  "westdown" : __DIR__"street1",
]));

  setup();
}

