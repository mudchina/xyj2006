// Room: /d/jjf/dining_room.c

inherit ROOM;

void create ()
{
  set ("short", "宴厅");
  set ("long", @LONG
屋子中间有一张大桌子，足足可以坐下三十来人。房子的一边
通向正厅，另一边可以去厨房。将军府客人多时，往往这里都坐不
下，干脆在前院空地上露天设宴。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kitchen_road1",
  "west" : __DIR__"keting",
]));

  setup();
}
