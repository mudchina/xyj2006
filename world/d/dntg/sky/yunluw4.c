//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "云路");
set("long", @LONG
    
踏着这条宽敞的天宫云路，脚下飘过朵朵白云，俯视人间农舍
中飘起的袅袅炊烟，另人倍感心旷神怡。
LONG );


set("exits", ([
  "east"   : __DIR__"yunluw3",
  "west"   : __DIR__"xitian",
]));


set("objects", ([
]));



set("outdoors", 1);

  create_door("west", "西天门", "east", DOOR_CLOSED);

setup();
}
