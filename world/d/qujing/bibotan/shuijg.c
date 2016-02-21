#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "碧波潭水晶宫");
  set ("long", @LONG

这里便是碧波潭龙王的居所水晶宫。大堂之上高悬数颗明珠，将
大厅照的如同白昼。厅内的摆设也是尽其豪华，入目之处无不是
人间少有，世上难寻的奇珍异宝。一群彩衣宫嫔正随歌而舞，几
个龙子龙孙前后招呼，好不热闹。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/longwang" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"yujie",
  "north" : __DIR__"longtai2",
  "east" : __DIR__"hanyu",
  "west" : __DIR__"lengxiang",
]));
//      
        set("water", 1);
//  
  setup();
}

