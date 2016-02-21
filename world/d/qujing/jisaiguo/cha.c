#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "茶室");
  set ("long", @LONG

房中的摆设虽已破旧，但还干净，好象有人常来常往的样子。屋
里墙上还挂着几幅字画，看起来还蛮有情趣。屋后几株绿竹随风
摇摆，叶子发出哗哗的声音。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"obj/qingzhutong" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east": __DIR__"inner3",
]));

  setup();
}

