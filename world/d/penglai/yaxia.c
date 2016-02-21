//Cracked by Roath
// Edit by Canoe
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "青石崖下");
  set ("long", @LONG

蓬莱岛上风光秀丽，当真是好去处！前方一座高崖，崖上有祥
云绕绕，隐有红光。崖壁上多是青苔锈葛，看上去异常的滑手。
崖上有鹤鸣阵阵，空山回音不绝。对面有个小岛,岛上郁郁葱
葱地长着很多花草,可惜似乎除了跳(tiao)过去外,没别的途
径能过去了.
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road1",
]));
	set("outdoors", 1);
  setup();
}


void init()
{
	add_action("do_climb", "climb");
	add_action("do_jump", "tiao");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="高崖" && arg!="悬崖" && arg!="cliff") )
		return notify_fail("你要爬什么？\n");
	if(me->is_busy())
		return notify_fail("你很忙，爬什么呀！\n");

	message_vision("$N搓了搓手，扒着石头的缝隙向崖上爬去。。。\n", me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=150 ){
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision("$N越爬越高，渐渐隐入了云中。。。\n", me);
	me->move("/d/penglai/yazhong");
	me->receive_damage("kee", 400);
	me->receive_damage("sen", 400);
	message_vision("$N慢慢的爬了上来。\n", me);
	return 1;
}
int faila(object me)
{

        tell_object(me, "你手上一个不稳，从崖上掉了下来。。。\n");
        tell_room(environment(me), me->name()+"晃悠悠的从崖上掉了下来。\n", ({me, me}));
	
me->unconcious();
	return 1;
}
int do_jump(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="cliff" && arg!="悬崖") )
		return notify_fail("你要跳过哪里？\n");
	if(me->is_fighting()||me->is_busy()||me->query_temp("pending"))
                 return notify_fail("你很忙，跳什么呀！\n");
       // if (!present("yao chu",me))
        //        return notify_fail("你跳过去干什么，没事不要过去！\n");
        if((int)me->query("learned_points")<200000)
                return notify_fail("看你的所学,似乎还有点不够,对面可是很危险的哦！\n");
         
message_vision("$N往后退了几步，一个冲刺,运用轻功腾空而起。\n", me);
	me->move("/d/liandan/road1");
 message_vision("$N稳稳当当地从悬崖跳了下来。\n", me);
	return 1;

}
