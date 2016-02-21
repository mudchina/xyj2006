// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "后廊");
  set ("long", @LONG

虽只是一墙之隔，前堂的喧哗却一点也听不见了。左右都是竹
林，微风吹过，林中发出哗哗的响声。廊边的木柱显得相当陈
旧，却一尘不染，也许有人时常打扫。弯弯曲曲的木廊通向竹
林深处。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"houlang5",
  "southeast" : __DIR__"houlang3",
]));

  setup();
}
