//sgzl

#include <room.h>
inherit ROOM;

int grass_number;

void create()
{
set("short", "山路");
set("long", @LONG
    
一条不甚宽广的山路，四处芳草鲜美，落英缤纷。周围的树丛
中偶尔撺出几只猴子，在这里跳来跳去，路边的小草(grass)
随风飘舞。
LONG );

set("item_desc",(["grass":"
一些绿油油的小草，拔(ba)出来看看？\n"
]));

set("exits", ([
"northup"   : __DIR__"shanlu2",
"southdown"   : __DIR__"up1",
]));


set("objects", ([
]));



set("outdoors", 1);
setup();
}



void init()
{
   grass_number=5;

   add_action("do_ba", "ba");
}


int do_ba(string arg)
{
   object me = this_player();
   object cao;

   if ( !arg || ( arg != "grass" ) ) 
     return notify_fail("你要拔什么？\n");
   else if(grass_number==0)  
     return notify_fail("草已经被拔光了，别费劲了。\n");
   else if(me->query("kee")<10) 
     {
     me->unconcious();
     return 1;
     }
   else 
     {
     me->add("kee",-10);
     cao = new (__DIR__"obj/grass");
     cao->move(me);
     message_vision("$N拔了一颗小草。\n", me);
     grass_number--;
     }
     return 1;
}

