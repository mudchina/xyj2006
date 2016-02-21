#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "经堂");
  set ("long", @LONG

屋中黑漆漆的，顶上的香油灯不知已灭了多少年了。依稀看到周
围都是书架，上面也挂满了灰尘，屋中摆着上落满灰尘的木桌，
几张木椅零乱的倒在一边。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"inner2",
]));

  setup();
}

