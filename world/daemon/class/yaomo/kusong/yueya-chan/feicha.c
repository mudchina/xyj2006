//Cracked by Roath
// 飞叉绝艺。     evil     2000.5.15

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("yueya-chan",1) ;
	if ( extra < 80) return notify_fail("你的月牙铲还不够纯熟！\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("飞叉绝艺只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
message_vision(HIC "$N双臂一震，一招飞叉绝艺，手中的"+ weapon->name()+  "飞出击向$n！" NOR,me,target);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	if( weapon->unequip()) weapon->move(environment(me));
	me->start_busy(2);
	return 1;
}
