// under4.c

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG

前方隐约现出一座宫殿，发出一道道五颜六色的光芒。这里的鱼儿
也特别多，还有许多奇形怪状的海怪。一行行，一列列，宛如臣子
拜见皇帝一般。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/long4" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gate",
  "southwest" : __DIR__"under3",
]));
//      
        set("water", 1);
//  
  setup();
}
