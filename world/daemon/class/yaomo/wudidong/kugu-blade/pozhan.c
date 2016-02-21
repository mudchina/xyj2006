//Cracked by Roath
// pozhan.c 		破绽百出

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int delay, myblade;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("不在战斗中，露什么破绽？\n");
	if(me->query("family/family_name")!="陷空山无底洞")
 return notify_fail("“破绽”只有无底洞门人才可以用！\n");

	myblade=(int)me->query_skill("kugu-blade",1);
	if(myblade>160) myblade=160; // mon 12/7/98
	if(myblade<50) 
		return notify_fail("你的修为不够深，露破绽给人太危险了。\n");

	delay=myblade/16;

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = CYN "$N的招式突然一变，变得全无章法，浑身上下破绽百出，\n";
	//change totoal random to half random half ur own value to make the sucessrate more stable
        if( ((random(me->query("combat_exp"))*3/4 + (me->query("combat_exp")/4) > (int)target->query("combat_exp")*3/8 ))) {
		msg += "$n想攻，却不知道哪个破绽是真，哪个是假。\n";
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
		target->start_busy(delay);
		me->start_busy(random(2));
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(2+random(2));
	}
	message_vision(msg, me, target);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

	return 1;
}
