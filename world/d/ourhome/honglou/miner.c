// Room: /d/ourhome/honglou/miner
inherit ROOM;

void create ()
{
  set ("short", "蓝桥");
  set ("long", @LONG

    　　遮不住的青山隐隐，流不断的绿水悠悠。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yard2",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}
