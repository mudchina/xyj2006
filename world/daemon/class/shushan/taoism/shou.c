// /daemon/class/shushan/taoism/shou.c 飞龙探云手
// writted bye jie 2001-1-5
// 《仙剑奇侠传》的飞龙探云手

#include <ansi.h>

inherit SSERVER;
int cast(object me, object target)
{
	
	string msg;

	object thing,*inv;
	if( !target ) target = offensive_target(me);
        if(me->query("family/family_name") != "蜀山派" )
        return notify_fail("你不是蜀山剑派，不会用「飞龙探云手」?\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
	return notify_fail("「飞龙探云手」只能对战斗中的对手使用。\n");

		
	if( (int)me->query_skill("spells",1)<60)
	return notify_fail("你的仙风云体术修为太浅，不会使用「飞龙探云手」。\n");
	if( (int)me->query_skill("taoism",1)<60)
	return notify_fail("你的基本法术修为太浅，不会使用「飞龙探云手」。\n");
	if( (int)me->query_skill("sevensteps",1)<60)
	return notify_fail("你的轻功不够敏捷，不能使用「飞龙探云手」。\n");
	if( (int)me->query("mana",1)<50)
	return notify_fail("你现在法力太弱，不能使用「飞龙探云手」。\n");
			
	msg = HIM "$N突然身形一展，使出「飞龙探云手」向$n怀中伸去！\n"NOR;

	if(random(me->query_skill("spells"))>target->query_skill("dodge")/2)
	{
	me->start_busy(3);
		target->start_busy(random(3));
		
	me->add("mana",-random(20));
	inv=all_inventory(target);
	if(!sizeof(inv))	{
		msg +=HIW"$n身上空空如也，$N什么也没「探」到！\n"NOR;
	}
	else	{
		thing=inv[random(sizeof(inv))];
		thing->move(me);
	msg +=HIM"$N妙手空空，从$n身上得到"+thing->query("unit")+thing->query("name")+"！\n"NOR;
	}
	} else 
	{
		me->start_busy(1);
	msg += HIW"可是$n看破了$N的企图，身形一晃闪了开去。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
