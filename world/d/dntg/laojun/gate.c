//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "兜率宫大门");
set("long", @LONG
    
这里就是太上老君的住所－－兜率宫了。
这兜率宫是三十三天之上，经常有各路神
仙来这里与太上老君讲经谈道。
LONG );


set("exits", ([
  "west"   : "/d/dntg/yaochi/wmj4",
  "enter" : __DIR__"hall",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
