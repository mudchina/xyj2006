#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "月台小径");
  set ("long", @LONG

一条碎石铺成的小路通向潭的深处，小径上的碎石摆成了不同图
案，有园月，弯月。。。一路看去，竟是各种各样的月亮。小径
被清扫的很干净，向东通到公主和驸马的住所。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/changtui" : 1,
]));
//  set("outdoors", 1);
  

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yuetai2",
  "west" : __DIR__"yuemen",
]));
//      
        set("water", 1);
//  
  setup();
}

