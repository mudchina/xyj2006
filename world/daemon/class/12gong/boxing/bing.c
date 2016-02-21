// bing.c 

// 取自fy3之麻婆寒练
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{

        int attackp, defendp;
	if( target == me ) target = offensive_target(me);
	if( !target || !target->is_character() )
		return notify_fail("你要对谁使用“冰心诀”？\n");
	if( !me->is_fighting(target) )
		return notify_fail("“冰心诀”只可以在战斗中使用！\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用“冰心诀”！\n");
//	if( (int)me->query_skill("beiming-zhenqi", 1) < 110 )
//		return notify_fail("你的北冥真气功力不够，不能使用“冰心诀”。\n");
	if( (int)me->query("force",1) < 270 )
		return notify_fail("你的内力不够，不能使用“冰心诀”。\n");
	if(target->query("disable_type") == HIW "<冻僵中>" NOR)
		return notify_fail("你现在并不需要使用“冰心诀”。\n");
	attackp = me->query_skill("boxing", 1);
	defendp = target->query_skill("force") + target->query_skill("dodge");
	message_vision( HIW"$N逆运北冥真气，掌中凝出无数晶莹闪烁的冰晶，在寒光闪耀中，向$n袭来！\n\n"NOR, me, target );
	if( attackp > defendp / 5 + random(defendp) / 5 ) {
		message_vision( HIW"无数闪耀的冰晶围绕着$n的全身，渐渐凝聚成冰块，将$n冻在其中！\n"NOR, me, target );
//		seteuid(ROOT_UID);
		target->disable_player(HIW"<冻僵中>"NOR);
		target->set_temp("block_msg/all", 1);
                call_out("remove_frozen", 7 + random((int)me->query_skill("boxing", 1) / 10), target);
	}
	else {
		message_vision("但是被$n躲开了。\n", me, target);
	}
	target->kill_ob(me);
	me->add("force", -270);
	me->start_busy(2);
	return 1;
}
void remove_frozen(object me)
{
	me->enable_player();
	me->set_temp("block_msg/all", 0);
	me->set("disable_type", 0);
	if ( !me->is_ghost() )
	message_vision(HIR "$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n" NOR, me);

}

