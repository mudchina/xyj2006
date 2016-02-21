//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "护国街");
set("long", @LONG
    
在这里有天宫的重兵把守，这条街直通天宫兵营，
那里驻扎着几十万天兵。兵营旁边是饲养天马的
御马间。
LONG );


set("exits", ([
  "south"   : "/d/dntg/sky/yunluw3",
  "north"   : __DIR__"hgj5",
  "west"   : __DIR__"bingyinggate",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
