inherit ROOM;

void create ()
{
  set ("short", "背阴小道");
  set ("long", @LONG

这里是一条陡峭的小路，向上是背阴山，南边一座小桥，就是
令人胆颤的奈何桥。能听到桥下滚滚水声，也能听到鬼狼凄叫。
几个桥梁使者手握皮鞭，正驱敢着一些鬼怪。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"naiheqiao",
  "west" : __DIR__"new-wayout",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/shizhe" : 2,
]));

  setup();
}
