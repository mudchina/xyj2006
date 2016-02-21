// By canoe 2001-06-21
#include <room.h>
inherit ROOM;

void create()
{
set("short", "大  堂");
set("long", @LONG
    
这里是神农氏庄园的大堂,可惜没看到丹房在哪里。墙角
焚着一炉檀香，一丝若有若无的幽香满室缭绕。那香炉
的把手十分光滑,似乎经常被人接触.

LONG );
set("exits", ([
  "east": __DIR__"road2",
]));
set("item_desc", ([ /* sizeof() == 1 */
  "xianglu" : "
一个很重的香炉,看来可以移动(move)它.
"]));
  set("objects", ([ /* sizeof() == 4 */
       __DIR__"obj/xianguan" : 2,
]));
setup();
}
void init()
{
add_action("do_move", "move");
}

int do_move(string arg)
{
	object me=this_player();
	
if( !arg || (arg!="xianglu" && arg!="香炉") )
		return notify_fail("你要移动什么？\n");
	if(me->is_fighting()||me->is_busy()||me->query_temp("pending"))
		return notify_fail("你很忙，移什么呀！\n");
        if((int)me->query("learned_points")<200000)
                return notify_fail("看你的所学,似乎还有点不够,没必要去里面！\n");
        me->start_busy(1+random(2)); 
	message_vision("$N双手抱住香炉,吐气开声,香炉慢慢被$N移动了。\n", me);
	if(random(me->query("str"))>5)
	        {
	        message_vision("香炉下竟然有间地下室,$N赶快跳了进去。\n", me);
	        me->move("/d/liandan/danfang");
      tell_room( environment(me), "“扑通”一声，" + me->name() + "从上面轻松地跳了下来！\n",
               ({me}) );
	        }
        else    message_vision("香炉晃了晃,又轰的一声移回原处。\n", me);	        
return 1;

}
