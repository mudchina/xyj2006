//sgzl

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
set("short", "天宫大道");
set("long", @LONG
    
一条大道，笔直的伸展出去，直通南天门。道上不时走过几名
巡查的天兵，持刀悬剑，威风凛凛。
LONG );


set("exits", ([
      "north"   : __DIR__"dadao2",
]));


set("objects", ([
]));




setup();
}


void init()
{
add_action("do_swim", "swim");
}

int do_swim()
{
object who = this_player();
object horse = who->query_temp("ridee");


if(who->is_busy()||who->query_temp("pending/exercising")
||who->is_fighting()
||who->query_temp("pending/meditating"))
return notify_fail("你正忙着,不怕淹死?\n");
if (! horse) 
  {
  message_vision(HIY "$N纵身一跃，跳入天河。\n" NOR, who);
  who->move(__DIR__"tianhe");
  }
else 
  {
  message_vision(HIY "$N"+horse->query("ride/msg")+"着"+horse->name()+"跃入天河。\n" NOR, who,horse);
  who->move(__DIR__"tianhe");
  horse->move(__DIR__"tianhe");
  }
message_vision(HIY "$N顺着宽广的河水飘了过来。\n" NOR, who);
return 1;
}

