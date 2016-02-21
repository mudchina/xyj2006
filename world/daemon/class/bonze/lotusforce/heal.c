// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");
        if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("你并非出家和尚,内功心法用的不对吧！\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
	message("vision",
		HIW + me->name() + "坐下来运功疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n" NOR,
		environment(me), me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("force_factor", 0);

	return 1;
}
