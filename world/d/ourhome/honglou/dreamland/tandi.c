
#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "潭底");
  set ("long", @LONG

这里是无名水潭潭底，左右水草密布，随着水波来回飘摆。
LONG);
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/jiaolong" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"shuitan",
]));
  setup();
}
