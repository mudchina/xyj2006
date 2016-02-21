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
  "/d/sea/npc/soldier1" : 2,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"longtai1",
  "south" : __DIR__"tandi2",
]));
//      
        set("water", 1);
//  
  setup();
}

