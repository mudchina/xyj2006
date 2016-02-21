// Room: /d/nanhai/chucangshi

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "储藏室");
  set ("long", @LONG

这是一间用来放一些杂物的小屋子，另外还有一些储存起来的作
为冬天燃料的树干啊什么的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
"north" : __DIR__"zoulang2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/shugan" : 2,
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

create_door("north", "小门", "south", DOOR_CLOSED);
  setup();
}
