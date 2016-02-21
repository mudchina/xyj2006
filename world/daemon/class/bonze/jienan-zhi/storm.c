// 暴风骤雨
// dream 7/17/97
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("你并非出家和尚,不能使用这项技能！\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「暴风骤雨」？\n");

        if((int)me->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

	if((int)me->query_skill("jienan-zhi", 1) <100)
		return notify_fail("你的劫难指级别还不够！\n");


        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);

        if( random(me->query("max_force")) < 50 ) {
                write("糟糕，没成功！\n");
                return 1;
        }


        COMBAT_D->attacking_perform(
                me, 
                        //attacker 
                target, 
                        //target
                (int)me->query_skill("jienan-zhi", 1), 
                        //level of skill used
                150, 
                        //success adjustment
                100, 
                        //damage adjustment
                "both", 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "\n$N口中大喝了一声，施展出「暴风骤雨」，双手十指上下翻飞，身形前后左右移动，\n
$n只觉得到处是$N的影子，根本不知如何招架，更不用说躲闪了！\n\n" NOR,
                        //initial message
                HIC "结果十指结结实实全部击中了$n，差点没把$n戳了个透心凉！\n" NOR, 
                        //success message
                HIC "但是$n轻轻一跳就躲了开来。\n" NOR, 
                        //fail message
                HIC "但是被$n以内力一逼，指力尽数反挫！\n" NOR, 
                        //backfire initial message
                HIC "结果只听喀嚓！几声，$n十指几乎全部折断！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

me->start_busy(3);
return 5;
}

