//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "青龙殿");
set("long", @LONG
    
天宫的一座偏殿，天神进宫面见玉帝之前常在此歇息，
只见这里四壁描龙绣凤，气势非凡。
LONG );


set("exits", ([
  "west"   : __DIR__"xuanyuantang",
  "east"   : __DIR__"xinyuegong",
]));


set("objects", ([
]));



setup();
}
