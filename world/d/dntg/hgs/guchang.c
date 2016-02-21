// Room: /d/4world/guchang.c
inherit ROOM;

void create ()
{
  set ("short", "谷场");
  set ("long", @LONG

这是靠近城边的一个打谷场，场上很平并压的很硬。边上高高低低
有几个草堆，几棵大柳树下有几条野狗在打瞌睡。场中有几只老母
鸡在啄谷粒吃。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muji" : 2,
]));
  set("outdoors", "/d/4world");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"east2",
]));

  setup();
}
