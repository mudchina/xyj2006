// 窒气诀

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int delay,myunarmed;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[窒气诀]只能在战斗中使用\n");

	if(me->query("family/family_name") != "将军府")
                return notify_fail(HIR"「窒气诀」"+NOR"是将军府不传之密！\n");

	myunarmed=(int)me->query_skill("changquan",1);
	if(myunarmed<60) 
		return notify_fail("你的长拳修为不够深，无法使用[窒气诀]。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIY "$N收拳发力，招化长拳之秘奥义[窒气诀]向$n攻去！\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += HIB "$n被一阵拳风扫中，身形不由慢了下来。\n" NOR;
		delay = random(myunarmed/20);
		target->start_busy(delay);
		me->start_busy(random(3));
	} else {
		msg += HIG "可是$p连跳了几步，闪开了这阵拳风！\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);

	return 1;
}
