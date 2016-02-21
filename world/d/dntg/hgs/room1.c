// Room: /d/4world/room1.c
inherit ROOM;

void create ()
{
  set ("short", "民宅");
  set ("long", @LONG

这户人家在城里也算比较富裕的了。男主人常年经商在外，妻子在
家主持家务。如同大多数人家一样，屋里供着南海观音和关王爷的
神像。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"east2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman" : 1,
  __DIR__"npc/kid" : 1,
]));

  setup();
}
