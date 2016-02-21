//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "林间小路");
set("long", @LONG
    
花果山中的一条林间小路。这里葛藤纠结，古木参天，绝少
人行，只有一些猴子在树间荡来荡去。花果山山势雄伟而不
险峻，在山间行走并不吃力。再往上很快就到山腰了。
LONG );


set("exits", ([
  "northup"   : __DIR__"entrance",
  "westdown"   : __DIR__"up1",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
