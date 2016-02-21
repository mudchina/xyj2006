// Room: /4world/houshan1
inherit ROOM;

void create ()
{
  set ("short", "后山小路");
  set ("long", @LONG

这是通往后山的一条小路。只能小心翼翼地在树丛中钻行，
一个不注意就会碰得头破血流。几只猴子围着你跳来跳去，
一边吱吱乱叫，一边冲你扔野果。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/monkey1" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"entrance",
  "northup" : __DIR__"houshan2",
]));

  setup();
}
