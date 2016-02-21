#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "潭底小径");
  set ("long", @LONG

这里是碧波潭底细沙铺就的一条小径，左右水草密布，随着水波
来回飘摆。潭水成碧绿色，水下光线不是很好，道路难辩。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/dadu" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tandi2",
  "up" : __DIR__"gudu",
]));
//      
        set("water", 1);
//  
  setup();
}

