//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "移山大圣宫");
set("long", @LONG

      星光灿烂

   千          五
   秋          洲
   万          四
   载          海
   美          群
   名          英
   扬          会

LONG );


set("exits", ([
  "out": __DIR__"qushen",
  "enter": __DIR__"fuhai",
]));


set("objects", ([
  "/d/dntg/sky/stars/ggggg" : 1,
]));



  set("outdoors", 1);

setup();
}
