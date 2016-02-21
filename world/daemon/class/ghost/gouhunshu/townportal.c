//Cracked by Roath
//
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 50 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");

	if((string)me->query("family/family_name")!="阎罗地府" )
		return notify_fail("你试着将自己化为气体，可血肉之躯却怎么也化不开！\n");

        message_vision("$N喃喃地念了几句咒语。\n", me);

	me->add("mana", -25);
	me->receive_damage("sen", 20);

	if(me->is_fighting() ) {
// if(random((int)me->query("max_mana"))>(int)target->query("max_mana")/2) {
 if( random(5) > 1) {
			message_vision(HIC"$N口中喷出一股黑风，整个人也随着黑风散去。。。\n"NOR, me);
			me->move("/d/death/gate");
			tell_room(environment(me),
HIC"一阵阴风过后，隐约现出"+me->query("name")+"的影子。\n\n"NOR, ({me, me}) );

		} else {
			message_vision(HIC"$N转身想跑，却被$n一个箭步拦住。\n"NOR, me, target);
			me->start_busy(2);
		}
	} else {
		message_vision(HIC"$N口中喷出一股黑风，整个人也随着黑风散去。。。\n"NOR, me);
		me->move("/d/death/gate");
                tell_room(environment(me),
HIC"一阵阴风过后，隐约现出"+me->query("name")+"的影子。\n\n"NOR, ({me, me}) );

	}

        return 5+random(5);
}

