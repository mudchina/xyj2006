// Room: /d/4world/schoolin.c
inherit ROOM;

void create ()
{
  set ("short", "天井");
  set ("long", @LONG

这里是武馆内院的天井，头顶仅看到一丈见方的天空。西边是武
馆的大厅，时常在那里招待客人。北边是几间家人住的房子，南
边是招待客人的厢房，天井中种了许多奇花异草。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"schoolbook",
  "south" : __DIR__"schoolrest",
  "west" : __DIR__"schoolhall",
]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gardener" : 1,
]));

  setup();
}
