// Room: /d/4world/school1.c
inherit ROOM;

void create ()
{
  set ("short", "东方武馆大门");
  set ("long", @LONG

你现在正站在一间大宅院的入口，两只巨大的石狮镇守在大门的两
侧，一阵阵吆喝与刀剑碰撞的声音从院子中传来，通过大门往东可
以望见许多身穿灰衣的汉子正在操练。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"school2.c",
  "south" : __DIR__"east1",
]));

  setup();
}
