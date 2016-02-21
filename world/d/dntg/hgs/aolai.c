//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "傲来国");
set("long", @LONG
    
东胜神洲海边一小国。傲来国西临大海，东靠花果山，只是
在其间一块狭窄的平原地带上建有一座城池。一条大路直通
南方，路上行人也是匆匆而过。
LONG );


set("exits", ([
  "west"   : "/d/changan/aolaiws",
  "east"   : __DIR__"flowerfruit",
  "south"   : __DIR__"northgate",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
