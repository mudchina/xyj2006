#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "霜雨轩");
  set ("long", @LONG

轩内装饰典雅，家俱全是玉竹编成，看起来相当地雅致。四周摆
着不少古玩玉器，尤其是墙上的一幅字画风骨颇为不俗，上书“
霜雨轩”三个大字，字体隽秀，象是出自女子之手。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/gongzhu" : 1,
  __DIR__"npc/fuma" : 1,
]));
//  set("outdoors", 1);
  

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"yuetai2",
]));
//      
        set("water", 1);
//  
  setup();
}

