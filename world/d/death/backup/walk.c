// Room: /d/death/walk.c
inherit ROOM;

void create ()
{
  set ("short", "荒郊草野");
  set ("long", @LONG

周围什么也没有，看不到一个人影，听到的只是呜呜的风声，
就象有无数的野鬼在你耳边狂啸．
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"inn2.c",
  "west" : __DIR__"inn1",
  "north" : __DIR__"gate",
]));
  set("hell", 1);

  setup();
}
