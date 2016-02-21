//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "青石台");
  set ("long", @LONG

蓬莱岛上风光秀丽，当真是好去处！高崖上视野开阔，周围景色
看的清清楚楚。石崖不知还有多高，隐在云中不见端倪，下面云
雾绕绕，也不知有多高了。
LONG);
  set("exits", ([ /* sizeof() == 3 */
//  "south" : __DIR__"road1",
]));
	set("outdoors", 1);
  setup();
}


void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="高崖" && arg!="悬崖" && arg!="cliff") )
		return notify_fail("你要爬什么？\n");
	if( me->is_busy())
		return notify_fail("你现在很忙，爬什么呀！\n");
	
	message_vision("$N搓了搓手，扒着石头的缝隙向崖上爬去。。。\n", me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=200 ){
		call_out("faila", 3, me);
		return 1;
	}

	if( random((int)me->query_kar()) <= 5){
		call_out("faila", 3, me);
		return 1;
	}
 
	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision("$N越爬越高，渐渐隐入了云中。。。\n", me);
	me->move("/d/penglai/yashang");
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
