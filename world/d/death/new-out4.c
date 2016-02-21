// Room: /d/death/walk.c
inherit ROOM;

void create ()
{
  set ("short", "荒郊草野");
  set ("long", @LONG

周围什么也没有，看不到一个人影，听到的只是呜呜的风声，就象
有无数的野鬼在你耳边狂啸。尺高的野草随风摇摆，草中发出呼呼
的声音，象是有人在里面穿行。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"gate",
  "north" : __DIR__"new-out5",
  "south": __DIR__"new-out3",
]));
  set("hell", 1);

  setup();
}
