//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "林间小路");
set("long", @LONG
    
花果山中的一条林间小路。这里葛藤纠结，古木参天，绝少
人行，只有一些猴子在树间荡来荡去。花果山山势雄伟而不
险峻，在山间行走并不吃力。
LONG );


set("exits", ([
  "northup"   : __DIR__"shanlu1",
  "eastup"   : __DIR__"up2",
  "southdown"   : __DIR__"flowerfruit",
]));


set("objects", ([
  __DIR__"npc/monkey2"   : 1,
  __DIR__"npc/monkey1"   : 1,
]));



set("outdoors", 1);

setup();
}
