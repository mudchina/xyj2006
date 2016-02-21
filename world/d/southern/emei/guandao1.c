//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "官道");
set("long", @LONG
    

　　一条崎岖的东西向小路，通入蜀中。

LONG );


set("exits", ([
  "west"   : __DIR__"shanjiao",
  "east"   : __DIR__"guandao2",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
