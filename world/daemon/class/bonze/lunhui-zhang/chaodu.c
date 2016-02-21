#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("超生渡化只能对战斗中的对手使用。\n");
	if (me->query_temp("lastchaodu")+15>time())
	  return notify_fail("你刚刚使过超渡绝招，还是歇会儿吧。\n");
if((int)me->query_skill("lunhui-zhang", 1) < 80)
 return notify_fail("你的轮回杖修为还不够，使用这一招会有困难！\n");
//      if (!(me->query("id")=="bell" || "xiaoxiao"))
//       return notify_fail("只有风铃才可以使超度绝招.\n");
	if (me->query("force")<100)
	 return notify_fail("你的内力不够。\n");
/*          extra = me->query_skill("lunhui-staff",1) * 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
*/
	me->add("force",-100);
  msg = HIR "$N缓缓说道:佛曰,以杀止杀!我今天就大开杀戒.代表佛来惩罚你们这些顽恶之徒!\n" NOR;
	message_vision(msg, me, target);
  msg =  HIY "天理循环，报应不爽！\n"NOR;
         message_vision(msg, me, target);
	me->set_temp("LUNHUI_perform",0);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
  msg =  HIC "天网恢恢，疏而不漏！\n"NOR;
          message_vision(msg, me, target);
	me->set_temp("LUNHUI_perform",3);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
  msg =  HIG "放下屠刀，立地成佛！\n"NOR;
         message_vision(msg, me, target);
	me->set_temp("LUNHUI_perform",5);
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
 msg =  HIW "$n好象已经到了极乐世界．．．．\n"NOR;
	message_vision(msg, me, target);
/*	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
*/
	me->set_temp("lastchaodu",time());
	me->start_busy(2);
	return 1;
}
