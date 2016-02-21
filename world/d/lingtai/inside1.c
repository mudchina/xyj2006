// Room: some place in 西牛贺洲
// inside1.c

inherit ROOM;

void create ()
{
  set ("short", "正院");
  set ("long", @LONG

院中极大，从此望去，层层深阁琼楼，一进进珠宫贝阙，说不尽
那静室幽居。院中种着各种仙花异草，也是精心分划，景色如幽。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"houyuan",
  "west" : __DIR__"inside5",
  "south" : __DIR__"gate1",
  "northup" : __DIR__"jingtang",
]));
  set("outdoors", 1);

  setup();
}
