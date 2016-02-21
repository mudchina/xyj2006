//jiz.

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「无尽风波」只有在战斗中才能使用。\n");
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙宫弟子不能用「风波」！\n");
	if( (int)me->query_skill("fengbo-cha", 1) < 50 ) 
		return notify_fail("你的修为不够深，还使不出这一招！\n");
        if(me->is_busy())
                return notify_fail("你太忙了！\n");;
	if( target->is_busy() )
		return notify_fail(target->name()+"已经够忙了，你使的再漂亮也不会注意到。\n");
        if(me->query_temp("dhwl")) 
                return notify_fail("你正在蓄力之中，哪还有余出「无尽风波」。\n");
	message_vision(HIC"$N挥展开来，左一叉，右一叉，幻出无数大小光环向$n绕去。
虽看起来柔弱无力，却宛若秋波般连绵不绝，实是暗藏杀机！\n\n"NOR,me, target);

	mypot=(int)me->query_skill("fork");
	mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));

	tapot=(int)target->query_skill("parry");
	tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));

time=(int)me->query_skill("fengbo-cha", 1) /50;
      if ( time > 10 ) time = 10;
        if ( time < 4  ) time = 4;

        if ( random( mypot + tapot ) > tapot/2 ) {
		message_vision(HIR"$N果然被这光环套住，当时目瞪口呆，不知所措！\n"NOR,target);
//                target->start_busy(1+random(time));
target->start_busy(time/2+random(time/4));
me->start_busy(1);
                
	}else {
	message_vision(HIR"不料确被$N看破，攻其不备，$n反被打了个措手不及！\n"NOR,target,
me);
me->start_busy(1+random(time/2));
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}
