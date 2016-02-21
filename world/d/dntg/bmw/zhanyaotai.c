//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "斩妖台");
set("long", @LONG
    
玉皇封托塔李天王为五界降魔大元帅，给了他先斩后奏的宏愿。
四方的斩妖台正中立一五尺多高雕符篆玉柱，四方神兵守护，端
地是杀气腾腾。
LONG );


set("exits", ([
  "south"   : __DIR__"hgj6",
]));


set("objects", ([
  __DIR__"npc/shenbing" : 2,
]));



set("outdoors", 1);

setup();
}
