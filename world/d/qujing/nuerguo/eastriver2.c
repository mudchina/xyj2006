// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/eastriver2.c

inherit ROOM;

void create ()
{
  set ("short", "子母河东岸");
  set ("long", @LONG

子母河在这里显得比较宁静一点。河面较宽，水流平缓。河
对岸的西梁女国远远地可以看见一点人烟了。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eastriver3",
  "north" : __DIR__"eastriver1",
]));
  set("outdoors", __DIR__"");

  setup();
}
