//sgzl

#include <room.h>
//inherit ROOM;
inherit "/d/dntg/lijing/starting_place.c";

void create()
{
set("short", "花果山教军场");
set("long", @LONG
    
一片开阔的草地，被猴子们当作他们的教军
场，只见其中一个严肃的通背猿指挥着一列
列，一排派走过来的猴子兵。
LONG );


set("exits", ([
"east"   : __DIR__"shanya",
]));


set("objects", ([
__DIR__"npc/beng" : 1,
]));



set("outdoors", 1);
setup();
}
