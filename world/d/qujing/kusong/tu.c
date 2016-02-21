//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "土戊洞");
  set ("long", @LONG

一个黑漆漆的小室，象是来储藏东西用的。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huoyun", 
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"obj/che" : 1,
]));



  setup();
}

