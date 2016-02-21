#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "香堂");
  set ("long", @LONG

屋中黑漆漆的，顶上的香油灯不知已灭了多少年了。屋中弥散着
股香烛味，却有了太多的土气。地下几个蒲团早已叫老鼠咬的破
烂不堪，两旁挂的香帘也如风中飘絮，破烂的不成样子。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east": __DIR__"inner2",
]));

  setup();
}

