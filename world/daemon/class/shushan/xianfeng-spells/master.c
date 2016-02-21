#include <ansi.h>

inherit SSERVER;

int scribe(object me,object ob)
{
	object seal;

	if( (int)me->query("mana") < 100)
		return notify_fail("你的法力不足。\n");
	if( (int)me->query("sen") < 100)
		return notify_fail("你的精神无法集中。\n");
	
	
	message_vision("$N咬破手指，伸手在桃符纸上画了几下。\n", me);
	
	destruct(ob);

	seteuid(getuid());
seal=new("/d/shushan/obj/master_seal");
	seal->move(me);

	me->start_busy(2);
	return 1;
}
	
