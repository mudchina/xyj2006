//Cracked by Roath
// ajax

#include <room.h>
inherit ROOM;

void create()
{
set("short", "清凉寺门");
set("long", @LONG
    
     那清凉寺在清凉山之巅，和沿途所见寺庙相比，也不
见得如何宏伟，山门破旧，显已年久失修。
LONG );


set("exits", ([
  "enter"   : __DIR__"qlsi_yuan",
  "south"   : __DIR__"qlsi_shanlu1",
 
]));


set("objects", ([
]));


create_door("enter", "寺门", "out", DOOR_CLOSED);
set("no_clean_up", 0);


setup();
}
