//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "小溪");
set("long", @LONG
    
一条清澈见底的小溪，水流潺潺，在这玩够了就游(swim)
回去吧。
LONG );


set("exits", ([
]));


set("objects", ([
  __DIR__"npc/shuishe"   : 1,
  __DIR__"npc/fish"   : 2,
]));



setup();
}


void init()
{
add_action("do_swim", "swim");
}

int do_swim()
{
object me = this_player();
if ( me->is_busy() )
               return 1 ;

message_vision("$N游到岸边。\n", me);
me->move(__DIR__"xiaoxiqian");
message_vision("$N分开水面，爬上岸来。\n", me);
return 1;
}

