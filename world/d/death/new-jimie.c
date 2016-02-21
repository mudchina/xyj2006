// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "寂灭司");
  set ("long", @LONG

寂灭司内寒气森森，堂周是青布围幔，上面用金银丝线绣着些奇怪
的图案。堂前两侧阴兵分列，气势汹汹。堂上一张拱木案，上面摆
放了些文书。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"new-walk3",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yinchangsheng" : 1,
]));

  setup();
}

