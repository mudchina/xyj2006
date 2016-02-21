//Cracked by Roath
// duo.c 空手入白刃
//pudding 99.12 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( (int)me->query_temp("duo") )
                return notify_fail("你已经在夺敌人的兵刃了。\n");
        skill = me->query_skill("yinfeng-zhua",1);

        if( !(me->is_fighting() ))
                return notify_fail("空手入白刃只能对战斗中的对手使用。\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须空手。\n");
         if(me->query("family/family_name")!="陷空山无底洞")
             return notify_fail("你不是老鼠家族的，不能用空手入白刃\n");
        if (!objectp(weapon2 = target->query_temp("weapon")))
           return notify_fail("对方没有兵刃，你不用担心。\n");

//        if( skill < 50)
        if( skill < 750)
//                return notify_fail("你的阴风爪等级不够, 不能空手入白刃！\n");
                return notify_fail("空手入白刃暂时封闭,等待调整！\n");

        if( me->query("force") < 200 )
                return notify_fail("你的内力不够，无法空手入白刃！\n");
 
        msg = CYN "$N凝神闭息，打算施展空手入白刃的绝技. \n";
        message_vision(msg, me);
 
        dp = target->query_skill("parry") / 3;
        if( dp < 1 )
                dp = 1;
        if( random(skill) > dp )
        {
                if(userp(me))
                        me->add("force",-80);
                msg = "$N突然手臂暴涨, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
                target->start_busy(2);
                weapon2->move(me);
                me->start_busy(random(2));
        }
        else
        {
                msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
                me->start_busy(random(2));
        }
        message_vision(msg, me, target);

        return 1;
}
