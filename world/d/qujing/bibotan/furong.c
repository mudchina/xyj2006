#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "芙蓉亭");
  set ("long", @LONG

芙蓉亭上有八角，上雕飞龙彩凤，麒麟辟邪，分指向八个方位。
亭中一张园形青石桌，上刻有极大的一个太极图案。周围八个石
凳，按八卦方位摆置。任何的风吹草动似乎都会引发一些风雨雷
电，天动地摇的前兆。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/table" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hua_qian",
  "east" : __DIR__"hua_li",
  "north" : __DIR__"hua_kun",
  "west" : __DIR__"hua_kan",
]));
//      
        set("water", 1);
//  
  setup();
}

