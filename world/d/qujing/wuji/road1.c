// Room: /moon/road.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山顶嵯峨摩斗柄，树梢仿佛接云霄。青烟堆里，时闻得谷口啼猿；乱翠荫
中，每听得松间鹤唳。
LONG);

  set("outdoors", __DIR__"");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road2",
]));

  setup();
}






