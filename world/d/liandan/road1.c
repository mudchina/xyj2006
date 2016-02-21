//by Canoe on 01-06-21.
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小  路");
	set("long",@LONG
这里是一条幽静的小路，路旁全部是些奇花异草，但是前面
隐隐约约有片草地。你不由的想去看看！清烟和云雾缭绕着，美丽
极了。在这里,要回去的话只能跳(tiao)回去.
LONG
);
	
set("exits", ([ /* sizeof() == 2 */
  "north":__DIR__"road2",
        
]));
 set("objects", ([
    "/d/liandan/obj/baicaoxian1" : random(2) ,
    "/d/liandan/obj/xianguan" : random(3) ,
         ]));
 
	setup();
}
void init()
{
add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me=this_player();
	
if( !arg || (arg!="cliff" && arg!="悬崖") )
		return notify_fail("你要跳过哪里？\n");
	if(me->is_fighting()||me->is_busy()||me->query_temp("pending"))
		return notify_fail("你很忙，跳什么呀！\n");
        if((int)me->query("learned_points")<200000)
                return notify_fail("看你的所学,似乎还有点不够,对面可是很危险的哦！\n");
         
message_vision("$N往后退了几步，一个冲刺,运用轻功腾空而起。\n", me);
	me->move("/d/penglai/yaxia");
message_vision("$N稳稳当当地从悬崖跳了下来。\n", me);
return 1;

}
