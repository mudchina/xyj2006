//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "覆海大圣宫");
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
  "out": __DIR__"yishan",
  "enter": __DIR__"tongfeng",
]));


set("objects", ([
  "/d/dntg/sky/stars/xuexing" : 1,
]));



  set("outdoors", 1);

setup();
}
