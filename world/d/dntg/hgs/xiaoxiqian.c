//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "小溪前");
set("long", @LONG
    
延着山路一转，一条清澈的小溪出现在你的面前。
灿烂的阳光照耀下，小溪中波光闪闪，不时还有
几条鱼儿跳出水面，使你真想到溪中游(swim)一
翻。
LONG );


set("exits", ([
  "east"   : __DIR__"shanlu2",
]));


set("objects", ([
  __DIR__"npc/cihu"   : 1,
  __DIR__"npc/huabao"   : 1,
]));



set("outdoors", 1);

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

message_vision("$N纵身跃入小溪。\n", me);
me->move(__DIR__"xiaoxi");
message_vision("只见小溪中水花四溅，几条小鱼跳了起来。\n", me);
return 1;
}

