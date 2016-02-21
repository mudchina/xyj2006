//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "官道");
set("long", @LONG
    

　　一条宽阔的大道，贯穿南北，直同边关。

LONG );


set("exits", ([
  "north"   : __DIR__"guandao1",
  "south"   : __DIR__"guandao3",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
