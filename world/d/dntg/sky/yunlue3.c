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
  "west"   : __DIR__"yunlue2",
  "east"   : __DIR__"yunlue4",
  "north"   : "/d/dntg/yaochi/wmj4",
  "northeast" :"/d/dntg/laojun/laojunmaze0.c",
  "south"   : "/d/dntg/yaochi/wmj3",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}

int valid_leave(object who, string dir) {

  if(dir=="northeast")  who->set_temp("laojunmaze/steps",5+random(5));
return ::valid_leave(who,dir);
}
