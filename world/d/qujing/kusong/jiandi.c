//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "涧底");
  set ("long", @LONG

这里是涧下一块小的平地。头上有飞泉涉过，恰好将这里遮掩
起来，从涧上是看不到的。周围长着密密麻麻的青草，中间隐
隐现出一条小路。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"jiandi2", 
]));



  setup();
}

