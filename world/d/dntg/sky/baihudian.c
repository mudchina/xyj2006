//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "白虎殿");
set("long", @LONG
    
天宫的一座偏殿，天神进宫面见玉帝之前常在此歇息，
只见这里四壁描龙绣凤，气势非凡。
LONG );


set("exits", ([
  "east"   : __DIR__"xuanyuantang",
  "west"   : __DIR__"biyuegong",
]));


set("objects", ([
]));



setup();
}
