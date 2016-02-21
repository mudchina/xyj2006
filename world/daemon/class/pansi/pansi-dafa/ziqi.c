// drainerbolt.c
//2001,lestat
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 20 )
		return notify_fail("你的法术不够高！\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展氤氲紫气？\n");

	if((int)me->query("mana") < 100 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -25);
	me->receive_damage("sen", 20);

	if( random(me->query("max_mana")) < 20 ) {
		write("你失败了。\n");
		return 1;
	}

	msg = HIM "$N口中喃喃地念著咒文，左手一挥，手中聚起一团紫气射向$n！\n\n" NOR;

	ap = me->query_skill("spells");
	extradam = ap/2;
	ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 20) + random(extradam);
		damage -= (int)target->query("max_mana") / 30 + random((int)me->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  MAG "结果「嗤」地一声，紫气从$p身上透体而过，拖出一条长长的七彩光气，光气绕了\n"
					"回转过来又从$N顶门注入$P的体内！\n" NOR;
			me->receive_heal("sen", target->receive_damage("sen", damage, me));
			target->receive_wound("sen", damage/3, me);
			me->improve_skill("pansi-dafa", 1, 1);
		} else
			msg += HIB"结果「嗤」地一声，紫气从$p身上透体而过，无声无息地钻入地下！\n"NOR;
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(2);
	return 1;
}


