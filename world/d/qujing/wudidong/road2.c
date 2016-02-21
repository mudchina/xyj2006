// Room: /d/qujing/wudidong/road2.c

inherit ROOM;

void create ()
{
  set ("short", "村中小路");
  set ("long", @LONG

这里就是张家村的“繁华地界”了，北面传来叮叮当当的打铁声音，
南边随风飘来阵阵饭菜香气。抬头一看，茅屋边大树上挑着个酒幌，
屋檐下的匾上写着「张家老店」，门面倒也齐整。
LONG);

  set("outdoors", "1");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road1",
  "north" : __DIR__"smithy",
  "south" : __DIR__"shop",
  "west" : __DIR__"road3",
]));

  setup();
}
