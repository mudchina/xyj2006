// Room: some place in 西牛贺洲
// cave2.c

inherit ROOM;

void create ()
{
  set ("short", "山洞");
  set ("long", @LONG

忍着领人窒息的腥气，你钻进一个洞中．洞口虽不大，里面
却还宽敞．但满地狼籍，到处是动物骨头，还有一些被撕成
碎片的尸体．
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youngwolf.c" : 2,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"cave1",
]));

  setup();
}
