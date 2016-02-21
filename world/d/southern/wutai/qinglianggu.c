//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "清凉谷");
set("long", @LONG
    

　　走到谷口，一股清风吹来，令人心情为之一畅。这里就
是四季如春的清凉谷了。

LONG );


set("exits", ([
  "northup"   : __DIR__"qlsi_shanlu3",
  "southdown"   : __DIR__"shanjiao",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
