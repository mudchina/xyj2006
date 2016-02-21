//Cracked by Roath
// Room: /d/nanhai/xiaoyuan
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "小院");
  set ("long", @LONG

这是一间小院，院中遍布奇花异草，参天大树将院子四周遮
得严严实实，好一个修身养性之所在。
LONG);

  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/tidu" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guangchang",
  "west" : __DIR__"zoulang",
  "south" : __DIR__"gate",
  "east" : __DIR__"zoulang2",
]));

create_door("south", "石门", "north", DOOR_CLOSED);
  setup();
}
