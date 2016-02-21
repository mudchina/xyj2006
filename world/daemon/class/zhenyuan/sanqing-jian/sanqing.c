// sanqing.c 一剑化三清

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
 	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「一剑化三清」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「一剑化三清」开始时必须拿着一把剑！\n");

        if (me->query_temp("jianmang"))
           return notify_fail("你正在施用剑芒，没有余力出「一剑化三清」！\n");
        
        if( (int)me->query("force") < 300 )
                return notify_fail("你的内力不够！\n");

        if( (int)me->query_skill("sanqing-jian",1) < 60 )
                return notify_fail("你的三清剑法还不到家，无法使用「一剑化三清」！\n");

        msg = YEL "$N使出三清剑法的绝技「一剑化三清」，一招连环三剑，手中的"+ weapon->name()+  "闪电般攻出第一剑！" NOR;
        message_vision(msg, me);
        me->add_temp("apply/attack", (int)me->query_skill("sanqin-jiang",1)/2);
        msg = HIY "只见$N右手一抖，"+ weapon->name()+ HIY"划向$n的左肩！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        message_vision(msg, me,target);
        msg =  HIW "$N凌空使出第二剑,"+ weapon->name()+ HIB"削向$n的右肩！" NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        message_vision(msg, me,target);
        msg = HIC "$N清啸一声，聚气于剑，朝$n的胸前攻出第三剑！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        message_vision(msg, me,target);
        me->add("force", - 100);
           me->add_temp("apply/attack",-(int)me->query_skill("sanqin-jiang",1)/2);
        me->start_busy(1+random(2));

        return 1;
}

