// Room: /d/jjf/kitchen_road2.c

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
一条弯弯曲曲的小路。路边绿草间稀稀疏疏地种了几株月季，
三两只小鸡小鸭正在漫步啄食。南边是后院小花园，不时传来阵阵
鸟语花香。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kitchen",
  "northwest" : __DIR__"kitchen_road1",
]));
  set("outdoors", 1);

  setup();
}
