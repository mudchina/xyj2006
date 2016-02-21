// girl3.c

inherit ROOM;

void create ()
{
  set ("short", "绣房");
  set ("long", @LONG

公主龙女就住在这里。房内布置的极其典雅。左一道屏，右一挂
帘使屋里显得朦朦胧胧。公主和几个小宫女不知在笑着什么。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"girl2",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long5" : 1,
  __DIR__"npc/gongnu" : 1,
  __DIR__"npc/longnu" : 1,
]));
//      
        set("water", 1);
//  
  setup();
}
