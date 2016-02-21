// Room: /4world/houshan2
inherit ROOM;

void create ()
{
  set ("short", "后山树丛");
  set ("long", @LONG

你顶着满头满脸的野果汁穿行在树丛中，把一群猴子乐得
吱吱乱叫。它们显然不太同情你的处境，还在不停地拿各
种各样的野果砸你。南面是一条下山的小路，北面透过树
丛可以看到一小块平地。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/monkey2" : 1,
  __DIR__"npc/monkey1" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houshan3",
  "southdown" : __DIR__"houshan1",
]));

  setup();
}
