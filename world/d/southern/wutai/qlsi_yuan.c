//Cracked by Roath
// ajax

#include <room.h>
inherit ROOM;

void create()
{
set("short", "院内");
set("long", @LONG
    
     那清凉寺在清凉山之巅，和沿途所见寺庙相比，也不
见得如何宏伟，山门破旧，显已年久失修。
LONG );


set("exits", ([
  "out"   : __DIR__"qlsi_gate",
  "enter"   : __DIR__"qlsi_tang",
 
]));


set("objects", ([
]));


create_door("out", "寺门", "enter", DOOR_CLOSED);
set("no_clean_up", 0);


setup();
}
